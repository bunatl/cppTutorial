#include "Vehicle.h"

Tuktuk::Tuktuk( int wheels, int speed ) : Vehicle( wheels, speed ) {
  this->wheels = wheels;
  this->maxSpeed = speed;
}

Tuktuk::Tuktuk( const Tuktuk &x ) : Vehicle( x.wheels, x.maxSpeed ) {
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
}

Tuktuk& Tuktuk::operator= ( const Tuktuk &x ){
  this->wheels = x.wheels;
  this->maxSpeed = x.maxSpeed;
  return *this;
}
