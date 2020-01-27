#include "Car.h"

//Class:: is equvilent to class*

Car::Car( int doors, int weight ){
  this->doors = doors;
  this->weight = weight;

  this->price = computePrice( doors, weight );
}

double Car::computePrice( int x, int y ){
  return ( x * y * 35 ) / 77;
}

void Car::updatePrice(){
  this->price = this->doors * this->weight * 35 / 77;
}