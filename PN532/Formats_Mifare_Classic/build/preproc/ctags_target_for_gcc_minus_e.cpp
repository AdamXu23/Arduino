# 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
// Formats a Mifare Classic tags as an NDEF tag
// This will fail if the tag is already formatted NDEF
// nfc.clean will turn a NDEF formatted Mifare Classic tag back to the Mifare Classic format
# 5 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino" 2
# 6 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino" 2
# 14 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
# 15 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino" 2
    PN532_HSU pn532hsu(Serial1);
    NfcAdapter nfc(pn532hsu);
# 33 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
void setup(void) {
    Serial.begin(9600);
    Serial.println("NDEF Formatter");
    nfc.begin();
}

void loop(void) {

    Serial.println("\nPlace an unformatted Mifare Classic tag on the reader.");
    if (nfc.tagPresent()) {

        bool success = nfc.format();
        if (success) {
            Serial.println("\nSuccess, tag formatted as NDEF.");
        } else {
            Serial.println("\nFormat failed.");
        }

    }
    delay(5000);
}
