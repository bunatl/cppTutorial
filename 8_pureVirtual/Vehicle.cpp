#include "Vehicle.h"

Vehicle::Vehicle( int wheels, int speed ){
  this->wheels = wheels;
  this->maxSpeed = speed;
}

Vehicle::Vehicle( const Vehicle &x ){
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
}

Vehicle& Vehicle::operator= ( const Vehicle &x ){
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
  return *this;
}
