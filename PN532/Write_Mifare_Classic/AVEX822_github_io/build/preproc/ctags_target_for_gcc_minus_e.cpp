# 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino"
# 2 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino" 2
# 3 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino" 2
# 11 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino"
# 12 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino" 2
    PN532_HSU pn532hsu(Serial1);
    NfcAdapter nfc(pn532hsu);
# 30 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\AVEX822_github_io\\AVEX822_github_io.ino"
void setup() {
    Serial.begin(9600);
    Serial.println("NDEF Writer");
    nfc.begin();
}

void loop() {
    Serial.println("\nPlace a formatted Mifare Classic or Ultralight NFC tag on the reader.");
    if (nfc.tagPresent()) {
        NdefMessage message = NdefMessage();
        message.addUriRecord("https://AVEX822.github.io/");

        bool success = nfc.write(message);
        if (success) {
            Serial.println("Success. Try reading this tag with your phone.");
        } else {
            Serial.println("Write failed.");
        }
    }
    delay(5000);
}
