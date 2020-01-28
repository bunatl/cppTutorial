#include "Vehicle.h"

Formula::Formula( int wheels, int speed ) : Vehicle( wheels, speed ) {
  this->wheels = wheels;
  this->maxSpeed = speed;
}

Formula::Formula( const Formula &x ) : Vehicle( x.wheels, x.maxSpeed ) {
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
}

Formula& Formula::operator= ( const Formula &x ){
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
  return *this;
}
