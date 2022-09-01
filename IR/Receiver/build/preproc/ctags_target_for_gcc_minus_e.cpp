# 1 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
/* rawR&cv.ino Example sketch for IRLib2

 *  Illustrate how to capture raw timing values for an unknow protocol.

 *  You will capture a signal using this sketch. It will output data the

 *  serial monitor that you can cut and paste into the "rawSend.ino"

 *  sketch.

 */
# 7 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
// Recommend only use IRLibRecvPCI or IRLibRecvLoop for best results
# 9 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 2

IRrecvPCI myReceiver(2); // pin number for the receiver

void setup()
{
    Serial.begin(9600);
    delay(2000);
    while (!Serial)
        ; // delay for Leonardo
    myReceiver.enableIRIn(); // Start the receiver
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 19 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 19 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  "Ready to receive IR signals"
# 19 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                  ); &__c[0];}))
# 19 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                  )));
}

void loop()
{
    // Continue looping until you get a complete signal received
    if (myReceiver.getResults())
    {
        Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 27 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 27 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                    "\n#define RAW_DATA_LEN "
# 27 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                    ); &__c[0];}))
# 27 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                    )));
        Serial.println(recvGlobal.recvLength, 10);
        for (bufIndex_t i = 1; i < recvGlobal.recvLength; i++)
        {
            Serial.print(recvGlobal.recvBuffer[i] > 900);
            Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 32 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                        (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 32 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                        ", "
# 32 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                        ); &__c[0];}))
# 32 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                        )));
        }
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 34 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 34 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                      "1000};"
# 34 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino" 3
                      ); &__c[0];}))
# 34 "c:\\Users\\822\\Documents\\GitHub\\Arduino\\IR\\Receiver\\Receiver.ino"
                      ))); // Add arbitrary trailing space
        myReceiver.enableIRIn(); // Restart receiver
    }
}
