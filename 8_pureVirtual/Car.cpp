#include "Vehicle.h"

Car::Car( int wheels, int speed ) : Vehicle( wheels, speed ) {
  this->wheels = wheels;
  this->maxSpeed = speed;
}

Car::Car( const Car &x ) : Vehicle( x.wheels, x.maxSpeed ) {
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
}

Car& Car::operator= ( const Car &x ){
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
  return *this;
}
