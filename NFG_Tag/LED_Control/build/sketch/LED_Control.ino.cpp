#include <Arduino.h>
#line 1 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino"
#include "NfcTag.h"
#include <Wire.h>

NfcTag nfcTag;
int led = 13;
bool flag = false;
bool preFlag = false;
#line 8 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino"
void setup();
#line 14 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino"
void loop();
#line 8 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino"
void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    nfcTag.init();
}

void loop() {
    flag = nfcTag.readByte(EEPROM_I2C_LENGTH - 1) == 0xff ? true : false;
    if (flag != preFlag) {
        Serial.println("get remote NFC control signal!");
        if (flag == true) {
            Serial.println("led will light up!");
            digitalWrite(led, HIGH);
        } else {
            Serial.println("led will turn dark!");
            digitalWrite(led, LOW);
        }
        preFlag = flag;
    }
    delay(5 * 1000);
}
