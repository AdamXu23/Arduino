# 1 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino"
# 2 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino" 2
# 3 "f:\\Adam Data\\GitHub\\Arduino\\NFG_Tag\\LED_Control\\LED_Control.ino" 2

NfcTag nfcTag;
int led = 13;
bool flag = false;
bool preFlag = false;
void setup() {
    Serial.begin(9600);
    pinMode(led, 0x1);
    nfcTag.init();
}

void loop() {
    flag = nfcTag.readByte(8192 - 1) == 0xff ? true : false;
    if (flag != preFlag) {
        Serial.println("get remote NFC control signal!");
        if (flag == true) {
            Serial.println("led will light up!");
            digitalWrite(led, 0x1);
        } else {
            Serial.println("led will turn dark!");
            digitalWrite(led, 0x0);
        }
        preFlag = flag;
    }
    delay(5 * 1000);
}
