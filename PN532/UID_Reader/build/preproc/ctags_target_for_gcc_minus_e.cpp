# 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\UID_Reader\\UID_Reader.ino"
# 2 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\UID_Reader\\UID_Reader.ino" 2
# 3 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\UID_Reader\\UID_Reader.ino" 2







# 11 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\UID_Reader\\UID_Reader.ino" 2
    PN532_HSU pn532hsu(Serial1);
    PN532 nfc(pn532hsu);
# 29 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\UID_Reader\\UID_Reader.ino"
void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");

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
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // Buffer to store the returned UID
  uint8_t uidLength; // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID((0x00), uid, &uidLength);

  if (success) {
    // Display some basic information about the card
    Serial.println("Found an ISO14443A card");
    Serial.print("  UID Length: ");Serial.print(uidLength, 10);Serial.println(" bytes");
    Serial.print("  UID Value: ");
    nfc.PrintHex(uid, uidLength);
    Serial.println("");
  }
}
