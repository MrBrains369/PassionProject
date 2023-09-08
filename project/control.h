#pragma once

//#define IR_SMALLD_NEC
#define IR_SMALLD_NECx
//#define IR_SMALLD_RC5
//#define IR_SMALLD_SIRC12
//#define IR_SMALLD_SIRC15
//#define IR_SMALLD_SIRC20
//#define IR_SMALLD_SIRC
//#define IR_SMALLD_SAMSUNG
//#define IR_SMALLD_SAMSUNG32

#include <IRsmallDecoder.h>

IRsmallDecoder irDecoder(2); //IR receiver connected to pin 2

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
		ACTION_STOP = 64
	};

  Control()
  {
  }

  Action what()
  {
		Action action = ACTION_NOTHING;
    irSmallD_t irData;    

    if(irDecoder.dataAvailable(irData))
		{
      Serial.println(irData.cmd, HEX);

			switch (irData.cmd)
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

      case ACTION_STOP:
        action = ACTION_STOP;
        break;

      default:
        action = ACTION_NOTHING;
        break;
      }
		}
		
		return action;
	};

private:
  static const int RECV_PIN = 2;
};