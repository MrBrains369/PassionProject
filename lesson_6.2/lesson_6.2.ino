/*
keyestudio Mini Tank Robot V2
lesson 6
IRremote
http://www.keyestudio.com
*/

#define ML_Ctrl 13  //define the direction control pin of left motor
#define ML_PWM 11   //define the PWM control pin of left motor
#define MR_Ctrl 12  //define direction control pin of right motor

#define ML_Ctrl 13  //define the direction control pin of left motor
#define MR_PWM 11   //define the PWM control pin of left motor
#define MR_Ctrl 12  //define direction control pin of right motor
#include <IRremote.hpp>     // IRremote library statement
int RECV_PIN = A0;        //define the pins of IR receiver as A0
//IRrecv irrecv(RECV_PIN);   
//decode_results results;   // decode results exist in the“result”of “decode results”
void setup()  
{
  pinMode(10, OUTPUT);
    Serial.begin(9600);  
    IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);
  pinMode(ML_Ctrl, OUTPUT);//define direction control pin of left motor to output
  pinMode(ML_PWM, OUTPUT);//define PWM control pin of left motor as output
  pinMode(MR_Ctrl, OUTPUT);//define direction control pin of right motor as output.
  pinMode(MR_PWM, OUTPUT);//define the PWM control pin of right motor as output
}  

void loop() {  
 (IrReceiver.decode())
  ;digitalWrite(ML_Ctrl,LOW);//set the direction control pin of left motor to LOW
  analogWrite(ML_PWM,200);//set the PWM control speed of left motor to 200
  digitalWrite(MR_Ctrl,LOW);//set the direction control pin of right motor to LOW
  analogWrite(MR_PWM,200);//set the PWM control speed of right motor to 200

if  //front
  (delay(2000);//delay in 2s
    )
      digitalWrite(ML_Ctrl,HIGH);//set the direction control pin of left motor to HIGH
  analogWrite(ML_PWM,200);//set the PWM control speed of left motor to 200  
digitalWrite(MR_Ctrl,HIGH);//set the direction control pin of right motor to HIGH
  analogWrite(MR_PWM,200);//set the PWM control speed of right motor to 200
  else
   //back
  delay(2000);//delay in 2s 
  digitalWrite(ML_Ctrl,HIGH);//set the direction control pin of left motor to HIGH
  analogWrite(ML_PWM,200);//set the PWM control speed of left motor to 200
  digitalWrite(MR_Ctrl,LOW);//set the direction control pin of right motor to LOW
  analogWrite(MR_PWM,200);//set the PWM control speed of right motor to 200
if
    //left
   (digitalWrite(ML_Ctrl,LOW);//set the direction control pin of left motor to LOW
  analogWrite(ML_PWM,200);//set the PWM control speed of left motor to 200
  digitalWrite(MR_Ctrl,HIGH);//set the direction control pin of right motor to HIGH
  analogWrite(MR_PWM,200);//set the PWM control speed of right motor to 200
else
   //right
  delay(2000);//delay in 2s
  analogWrite(ML_PWM,0);//set the PWM control speed of left motor to 0
  analogWrite(MR_PWM,0);//set the PWM control speed of right motor to 0
 
    //IrReceiver.printIRResultShort(&Serial); 
    Serial.println(IrReceiver.decodedIRData.command);//Wrap word in 16 HEX to output and receive code 

    int val = IrReceiver.decodedIRData.command;

    if (val == 70)
{
    digitalWrite(10,HIGH);
}
    if (val == 21)
{
      digitalWrite(10, LOW);
}
    if (val == 68)
{
    digitalWrite(10,HIGH);
}
    if (val == 67)
{
      digitalWrite(10, LOW);
}
    IrReceiver.resume(); // Receive the next value
{ 
  delay(100);
}
//*******************************************************