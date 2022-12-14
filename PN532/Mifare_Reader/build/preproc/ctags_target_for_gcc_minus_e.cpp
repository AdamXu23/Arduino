# 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino"
/**************************************************************************/
/*! 

    This example will wait for any ISO14443A card or tag, and

    depending on the size of the UID will attempt to read from it.

   

    If the card has a 4-byte UID it is probably a Mifare

    Classic card, and the following steps are taken:

   

    - Authenticate block 4 (the first block of Sector 1) using

      the default KEYA of 0XFF 0XFF 0XFF 0XFF 0XFF 0XFF

    - If authentication succeeds, we can then read any of the

      4 blocks in that sector (though only block 4 is read here)

	 

    If the card has a 7-byte UID it is probably a Mifare

    Ultralight card, and the 4 byte pages can be read directly.

    Page 4 is read by default since this is the first 'general-

    purpose' page on the tags.



    To enable debug message, define DEBUG in PN532/PN532_debug.h

*/
# 21 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino"
/**************************************************************************/

# 24 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino" 2
# 25 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino" 2
# 33 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino"
# 34 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino" 2
    PN532_HSU pn532hsu(Serial1);
    PN532 nfc(pn532hsu);
# 52 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Mifare_Reader\\Mifare_Reader.ino"
void setup(void) {
  // has to be fast to dump the entire memory contents!
  Serial.begin(115200);
  Serial.println("Looking for PN532...");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, 16);
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, 10);
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, 10);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Waiting for an ISO14443A Card ...");
}


void loop(void) {
  uint8_t success; // Flag to check if there was an error with the PN532
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // Buffer to store the returned UID
  uint8_t uidLength; // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  uint8_t currentblock; // Counter to keep track of which block we're on
  bool authenticated = false; // Flag to indicate if the sector is authenticated
  uint8_t data[16]; // Array to store block data during reads

  // Keyb on NDEF and Mifare Classic should be the same
  uint8_t keyuniversal[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID((0x00), uid, &uidLength);

  if (success) {
    // Display some basic information about the card
    Serial.println("Found an ISO14443A card");
    Serial.print("  UID Length: ");Serial.print(uidLength, 10);Serial.println(" bytes");
    Serial.print("  UID Value: ");
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print(uid[i], 16);
      Serial.print(' ');
    }
    Serial.println("");

    if (uidLength == 4)
    {
      // We probably have a Mifare Classic card ...
      Serial.println("Seems to be a Mifare Classic card (4 byte UID)");

      // Now we try to go through all 16 sectors (each having 4 blocks)
      // authenticating each sector, and then dumping the blocks
      for (currentblock = 0; currentblock < 64; currentblock++)
      {
        // Check if this is a new block so that we can reauthenticate
        if (nfc.mifareclassic_IsFirstBlock(currentblock)) authenticated = false;

        // If the sector hasn't been authenticated, do so first
        if (!authenticated)
        {
          // Starting of a new sector ... try to to authenticate
          Serial.print("------------------------Sector ");Serial.print(currentblock/4, 10);Serial.println("-------------------------");
          if (currentblock == 0)
          {
              // This will be 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF for Mifare Classic (non-NDEF!)
              // or 0xA0 0xA1 0xA2 0xA3 0xA4 0xA5 for NDEF formatted cards using key a,
              // but keyb should be the same for both (0xFF 0xFF 0xFF 0xFF 0xFF 0xFF)
              success = nfc.mifareclassic_AuthenticateBlock (uid, uidLength, currentblock, 1, keyuniversal);
          }
          else
          {
              // This will be 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF for Mifare Classic (non-NDEF!)
              // or 0xD3 0xF7 0xD3 0xF7 0xD3 0xF7 for NDEF formatted cards using key a,
              // but keyb should be the same for both (0xFF 0xFF 0xFF 0xFF 0xFF 0xFF)
              success = nfc.mifareclassic_AuthenticateBlock (uid, uidLength, currentblock, 1, keyuniversal);
          }
          if (success)
          {
            authenticated = true;
          }
          else
          {
            Serial.println("Authentication error");
          }
        }
        // If we're still not authenticated just skip the block
        if (!authenticated)
        {
          Serial.print("Block ");Serial.print(currentblock, 10);Serial.println(" unable to authenticate");
        }
        else
        {
          // Authenticated ... we should be able to read the block now
          // Dump the data into the 'data' array
          success = nfc.mifareclassic_ReadDataBlock(currentblock, data);
          if (success)
          {
            // Read successful
            Serial.print("Block ");Serial.print(currentblock, 10);
            if (currentblock < 10)
            {
              Serial.print("  ");
            }
            else
            {
              Serial.print(" ");
            }
            // Dump the raw data
            nfc.PrintHexChar(data, 16);
          }
          else
          {
            // Oops ... something happened
            Serial.print("Block ");Serial.print(currentblock, 10);
            Serial.println(" unable to read this block");
          }
        }
      }
    }
    else
    {
      Serial.println("Ooops ... this doesn't seem to be a Mifare Classic card!");
    }
  }
  // Wait a bit before trying again
  Serial.println("\n\nSend a character to run the mem dumper again!");
  Serial.flush();
  while (!Serial.available());
  while (Serial.available()) {
  Serial.read();
  }
  Serial.flush();
}
