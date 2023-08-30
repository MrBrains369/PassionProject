#include "robot.h"
#include "control.h"

Robot lucas;
Control control;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  Control::Action action = control.what();

  switch (action)
  {
    case Control::ACTION_FORWARD:
    Serial.println("Control::ACTION_FORWARD");
    //lucas.forward();
    break;

    case Control::ACTION_BACKWARDS:
    Serial.println("Control::ACTION_BACKWARDS");
    //lucas.backwards();
    break;

        case Control::ACTION_LEFT:
    Serial.println("Control::ACTION_LEFT");
    //lucas.left();
    break;

            case Control::ACTION_RIGHT:
    Serial.println("Control::ACTION_RIGHT");
    //lucas.right ();
    break;

  }
}
