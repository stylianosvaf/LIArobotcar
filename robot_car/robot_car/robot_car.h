#ifndef ROBOT_CAR_H
#define ROBOT_CAR_H

#include <Arduino.h>

class RobotCar{
  
  private:
    int _pinA1;
    int _pinA2;
    int _pinB1;
    int _pinB2;
    int _standby;
  
  public:
    RobotCar(int _pinA1,int _pinA2,int _pinB1, int _pinB2, int _standby);

    void init();
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    

};

#endif
