/*
keyestudio Mini Tank Robot V2
lesson 6
IRremote
http://www.keyestudio.com
*/ 
#include <IRremote.hpp>     // IRremote library statement
int RECV_PIN = A0;        //define the pins of IR receiver as A0
//IRrecv irrecv(RECV_PIN);   
//decode_results results;   // decode results exist in the“result”of “decode results”
void setup()  
{
  pinMode(10, OUTPUT);
    Serial.begin(9600);  
    IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);
    
}  

void loop() {  
  if (IrReceiver.decode())
  {  
    //IrReceiver.printIRResultShort(&Serial); 
    Serial.println(IrReceiver.decodedIRData.command);//Wrap word in 16 HEX to output and receive code 

    int val = IrReceiver.decodedIRData.command;

    if (val == 68)
    {
    digitalWrite(10,HIGH);
    }
    if (val == 67)
    {
      digitalWrite(10, LOW);
    }
    IrReceiver.resume(); // Receive the next value
  } 
  delay(100);
}
//*******************************************************