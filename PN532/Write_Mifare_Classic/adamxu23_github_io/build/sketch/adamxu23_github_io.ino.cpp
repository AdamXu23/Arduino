#include <Arduino.h>
#line 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\adamxu23_github_io\\adamxu23_github_io.ino"
#include <NfcAdapter.h>
#include <PN532/PN532/PN532.h>

#if 0 // use SPI
    #include <SPI.h>
    #include <PN532/PN532_SPI/PN532_SPI.h>
    PN532_SPI pn532spi(SPI, 9);
    NfcAdapter nfc = NfcAdapter(pn532spi);
#elif 1 // use hardware serial

    #include <PN532/PN532_HSU/PN532_HSU.h>
    PN532_HSU pn532hsu(Serial1);
    NfcAdapter nfc(pn532hsu);
#elif 0  // use software serial

    #include <PN532/PN532_SWHSU/PN532_SWHSU.h>
    #include "SoftwareSerial.h"
    SoftwareSerial SWSerial(2, 3);
    PN532_SWHSU pn532swhsu(SWSerial);
    NfcAdapter nfc(pn532swhsu);
#else //use I2C

    #include <Wire.h>
    #include <PN532/PN532_I2C/PN532_I2C.h>

    PN532_I2C pn532_i2c(Wire);
    NfcAdapter nfc = NfcAdapter(pn532_i2c);
#endif

#line 30 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\adamxu23_github_io\\adamxu23_github_io.ino"
void setup();
#line 36 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\adamxu23_github_io\\adamxu23_github_io.ino"
void loop();
#line 30 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Write_Mifare_Classic\\adamxu23_github_io\\adamxu23_github_io.ino"
void setup() {
    SERIAL.begin(9600);
    SERIAL.println("NDEF Writer");
    nfc.begin();
}

void loop() {
    SERIAL.println("\nPlace a formatted Mifare Classic or Ultralight NFC tag on the reader.");
    if (nfc.tagPresent()) {
        NdefMessage message = NdefMessage();
        message.addUriRecord("https://adamxu23.github.io/");

        bool success = nfc.write(message);
        if (success) {
            SERIAL.println("Success. Try reading this tag with your phone.");
        } else {
            SERIAL.println("Write failed.");
        }
    }
    delay(5000);
}
