#include "robot_car.h"
#include <IRremote.h>

#define F 16736925  //FORWARD (PRESS)
#define B 16754775  //BACK (PRESS)
#define L 16720605  //LEFT (PRESS)
#define R 16761405  //RIGHT (PRESS)
#define S 16712445  //STOP (PRESS)
#define UNKNOWN_F 5316027     //FORWARD (HOLD)
#define UNKNOWN_B 2747854299  //BACK (HOLD)
#define UNKNOWN_L 1386468383  //LEFT (HOLD)
#define UNKNOWN_R 553536955   //RIGHT (HOLD)
#define UNKNOWN_S 3622325019  //STOP (HOLD)

IRrecv irrecv (9);
decode_results results;

RobotCar car(7, 8, 5, 6, 3); // Initialize the RobotCar object

unsigned long preMillis;

void setup() {
   car.init();
   irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    preMillis = millis();
    irrecv.resume(); // Receive the next value
    
    switch (results.value) {
      case F:
      case UNKNOWN_F: car.forward(); break;
      case B:
      case UNKNOWN_B: car.backward(); break;
      case L:
      case UNKNOWN_L: car.left(); break;
      case R:
      case UNKNOWN_R: car.right(); break;
      case S:
      case UNKNOWN_S: car.stop(); break;
      default: break;
    }
  }
  else{
    if(millis() - preMillis > 200){
      car.stop();
      preMillis = millis();
    }
  }
}
