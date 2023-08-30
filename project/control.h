#pragma once

#include <IRremote.hpp>     // IRremote library statement


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
    IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);
  }

  Action what()
  {
		Action action = ACTION_NOTHING;
		
    if (IrReceiver.decode())
		{
      IrReceiver.resume(); // Receive the next value

      int val = IrReceiver.decodedIRData.command;

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
  static const int RECV_PIN = A0;
};