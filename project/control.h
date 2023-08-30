#pragma once

#include <IRremote.hpp>     // IRremote library statement
int RECV_PIN = A0;        //define the pins of IR receiver as A0

class Control
{
public:
	enum Action
	{
		ACTION_NOTHING = 0,
		ACTION_FORWARD = 70,
		ACTION_BACKWARDS = 21,
		ACTION_LEFT = 68,
		ACTION_RIGHT = 67,
		ACTION_STOP = 66
	};

  Control()
  {
    //IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);
    IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);

  }

  Action what()
  {
		Action action = ACTION_NOTHING;
		
	    if (IrReceiver.decode())
		{
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.printIRSendUsage(&Serial);
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        // We have an unknown protocol here, print more info
        IrReceiver.printIRResultRawFormatted(&Serial, true);
      }
      Serial.println();

      IrReceiver.resume(); // Receive the next value

      int val = IrReceiver.decodedIRData.command;
      
      Serial.println(val);

			switch (val)
      {
      case ACTION_FORWARD:
        action = ACTION_FORWARD;
        break;

      case ACTION_BACKWARDS:
        action = ACTION_BACKWARDS;
        break;
        
      case ACTION_LEFT:
        action = ACTION_LEFT;
        break;

      case ACTION_RIGHT:
        action = ACTION_RIGHT;
        break;

      default:
        action = ACTION_NOTHING;
        break;
      }
	
			
		}
		
		return action;
	};

private:
 
};