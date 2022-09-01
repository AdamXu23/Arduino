# 1 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
/* rawSend.ino Example sketch for IRLib2

 *  Illustrates how to send a code Using raw timings which were captured

 *  from the "rawRecv.ino" sample sketch.  Load that sketch and

 *  capture the values. They will print in the serial monitor. Then you

 *  cut and paste that output into the appropriate section below.

 */
# 7 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
# 8 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino" 2
# 9 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino" 2

IRsendRaw mySender;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 15 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 15 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
                "Every time you press a key is a serial monitor we will send."
# 15 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino" 3
                ); &__c[0];}))
# 15 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
                )));
}
/* Cut and paste the output from "rawRecv.ino" below here. It will 

 * consist of a #define RAW_DATA_LEN statement and an array definition

 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes

 * with "…,1000};"

 */
# 24 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
uint16_t rawData[54]={3386,3438,602,2222,734,2254,702,1022,758,2314,654,2250,706,2226,742,1014,762,1050,730,1054,734,1050,738,1046,734,2310,658,1010,766,1042,738,2278,678,1018,770,1046,734,1050,738,2298,658,2246,710,2250,706,2250,706,2254,702,1022,766,1046,734,1000
};



/*

 * Cut-and-paste into the area above.

 */
# 33 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Send\\Send.ino"
char receivedChar;
void loop() {
    while(Serial.available()>0){
    receivedChar = Serial.read();
    if(receivedChar == '1')
    {
        uint16_t rawData[54]={3386,3438,602,2222,734,2254,702,1022,758,2314,654,2250,706,2226,742,1014,762,1050,730,1054,734,1050,738,1046,734,2310,658,1010,766,1042,738,2278,678,1018,770,1046,734,1050,738,2298,658,2246,710,2250,706,2250,706,2254,702,1022,766,1046,734,1000};
        mySender.send(rawData,54,36);
        mySender.send(rawData,54,36);

        Serial.println("Fan Power");
    }
    if(receivedChar == '2')
    {
        uint16_t rawData[54]={3554, 3278, 762, 2198, 758, 2202, 766, 1014, 762, 2194, 762, 2198, 758, 2198, 758, 2202, 754, 2202, 766, 2190, 766, 2194, 762, 2202, 762, 1018, 762, 1022, 766, 1018, 758, 2202, 754, 1026, 762, 1022, 758, 1022, 766, 1018, 758, 1026, 766, 1022, 766, 1018, 758, 1026, 762, 2198, 758, 1022, 766, 1000};
        mySender.send(rawData,54,36);
        mySender.send(rawData,54,36);
        Serial.println("Fan +");
    }
    if(receivedChar == '3')
    {
        uint16_t rawData[54]={3582, 3254, 762, 2198, 758, 2206, 762, 1018, 758, 2226, 730, 2226, 730, 2230, 738, 2218, 738, 2194, 762, 2222, 734, 1018, 762, 2226, 738, 1042, 738, 1018, 758, 1022, 758, 2230, 734, 1022, 758, 1030, 758, 1026, 762, 1022, 758, 1030, 758, 1022, 766, 2198, 758, 1018, 758, 2226, 742, 1014, 762, 1000};
        mySender.send(rawData,54,36);
        mySender.send(rawData,54,36);
        Serial.println("Fan -");
    }
  }
}
