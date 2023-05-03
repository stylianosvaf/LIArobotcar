#include "robot_car.h"

RobotCar::RobotCar(int pinA1,int pinA2,int pinB1, int pinB2, int standby) {
  
  _pinA1 = pinA1;
  _pinA2 = pinA2;
  _pinB1 = pinB1;
  _pinB2 = pinB2;
  _standby = standby;
}

void RobotCar::init(){
  pinMode(_pinA1, OUTPUT);
  pinMode(_pinA2, OUTPUT);
  pinMode(_pinB1, OUTPUT);
  pinMode(_pinB2, OUTPUT);
  pinMode(_standby,OUTPUT);
  digitalWrite(_standby,HIGH);
}

void RobotCar::forward() {
  digitalWrite(_pinA1, HIGH);
  digitalWrite(_pinA2, HIGH);
  analogWrite(_pinB1, 55);
  analogWrite(_pinB2, 55);
}

void RobotCar::backward() {
  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinA2, LOW);
  analogWrite(_pinB1, 55);
  analogWrite(_pinB2, 55);
}

void RobotCar::left() {
  digitalWrite(_pinA1, HIGH);
  digitalWrite(_pinA2, LOW);
  analogWrite(_pinB1, 55);
  analogWrite(_pinB2, 55);
}

void RobotCar::right() {
  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinA2, HIGH);
  analogWrite(_pinB1, 55);
  analogWrite(_pinB2, 55);
}

void RobotCar::stop() {
  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinA2, LOW);
  analogWrite(_pinB1, 0);
  analogWrite(_pinB2, 0);
}
