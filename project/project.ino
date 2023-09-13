#include "control.h"
#include "robot.h"

Control control;
Robot lucas;

void setup() {
  Serial.begin(9600); 
}

void loop() {
    switch (control.what())
    {
      case Control::ACTION_FORWARD:
               Serial.println("Control::ACTION_FORWARD");
        lucas.forward();
        break;

      case Control::ACTION_BACKWARDS:
        Serial.println("Control::ACTION_BACKWARDS");
        lucas.backward();
      break;

      case Control::ACTION_LEFT:
        Serial.println("Control::ACTION_LEFT");
        lucas.left();
      break;

      case Control::ACTION_RIGHT:
        Serial.println("Control::ACTION_RIGHT");
        lucas.right();
      break;

      case Control::ACTION_STOP:
        Serial.println("Control::ACTION_STOP");
        lucas.stop();
        break;

      case Control::ACTION_NOTHING:
      default:
      break;
    }
}
