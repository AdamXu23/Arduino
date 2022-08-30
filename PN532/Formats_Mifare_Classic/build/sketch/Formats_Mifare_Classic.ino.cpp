#include <Arduino.h>
#line 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
// Formats a Mifare Classic tags as an NDEF tag
// This will fail if the tag is already formatted NDEF
// nfc.clean will turn a NDEF formatted Mifare Classic tag back to the Mifare Classic format
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

#line 33 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
void setup(void);
#line 39 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
void loop(void);
#line 33 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\PN532\\Formats_Mifare_Classic\\Formats_Mifare_Classic.ino"
void setup(void) {
    SERIAL.begin(9600);
    SERIAL.println("NDEF Formatter");
    nfc.begin();
}

void loop(void) {

    SERIAL.println("\nPlace an unformatted Mifare Classic tag on the reader.");
    if (nfc.tagPresent()) {

        bool success = nfc.format();
        if (success) {
            SERIAL.println("\nSuccess, tag formatted as NDEF.");
        } else {
            SERIAL.println("\nFormat failed.");
        }

    }
    delay(5000);
}
