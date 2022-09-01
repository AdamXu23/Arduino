# 1 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
/* rawR&cv.ino Example sketch for IRLib2

 *  Illustrate how to capture raw timing values for an unknow protocol.

 *  You will capture a signal using this sketch. It will output data the 

 *  serial monitor that you can cut and paste into the "rawSend.ino"

 *  sketch.

 */
# 7 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
// Recommend only use IRLibRecvPCI or IRLibRecvLoop for best results
# 9 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 2

IRrecvPCI myReceiver(2);//pin number for the receiver

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 16 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 16 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                "Ready to receive IR signals"
# 16 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                ); &__c[0];}))
# 16 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                )));
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 22 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 22 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  "Do a cut-and-paste of the following lines into the "
# 22 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  ); &__c[0];}))
# 22 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  )));
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 23 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 23 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  "designated location in rawSend.ino"
# 23 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  ); &__c[0];}))
# 23 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  )));
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 24 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 24 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                "\n#define RAW_DATA_LEN "
# 24 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                ); &__c[0];}))
# 24 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                )));
    Serial.println(recvGlobal.recvLength,10);
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 26 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 26 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                "uint16_t rawData[RAW_DATA_LEN]={\n\t"
# 26 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                ); &__c[0];}))
# 26 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                )));
    for(bufIndex_t i=1;i<recvGlobal.recvLength;i++) {
      Serial.print(recvGlobal.recvBuffer[i],10);
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 29 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 29 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  ", "
# 29 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  ); &__c[0];}))
# 29 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  )));
      if( (i % 8)==0) Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 30 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 30 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                                  "\n\t"
# 30 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                                  ); &__c[0];}))
# 30 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                                  )));
    }
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 32 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 32 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  "1000};"
# 32 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  ); &__c[0];}))
# 32 "f:\\Adam Data\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  )));//Add arbitrary trailing space
    myReceiver.enableIRIn(); //Restart receiver
  }
}
