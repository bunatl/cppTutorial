#include "Register.h"

#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

void printRegister( Register* r ){
  auto carReg = r->getRegister();
  for ( auto const& x : carReg ) {
    cout << x.first << " : ";
    //iterating through set
    for ( auto const y : x.second ) {
      /*
       * y is pointer to a class Car 
       * thefore it is needed to access its private members
       */
      cout << y->getRegisterPlate() << ", ";
    }
    cout << endl;
  }
  cout << "=================" << endl;
}

int main(){

  Car *c1 = new Car( "ABC", 15000 );
  Car *c2 = new Car( "XYZ", 50000 );
  Car *c3 = new Car( "KLM", 150000 );
  Car *c4 = new Car( "AAA", 0 );
  Car *c5 = new Car( "XXX", 100000 );
  Car *c6 = new Car( "CPP", 500000 );
  Car *c7 = new Car( "TTT", 333333 );
  Car *c8 = new Car( "OOO", 999999 );

  Register *r = new Register();
  
  r->registerCar( 1, c1 );
  printRegister( r );

  r->registerCar( 2, c2 );
  printRegister( r );

  r->registerCar( 1, c3 );
  r->registerCar( 1, c4 );
  r->registerCar( 1, c5 );
  printRegister( r );

  r->registerCar( 3, c6 );
  printRegister( r );

  r->registerCar( 4, c7 );
  r->registerCar( 3, c8 );
  printRegister( r );

  return 0;
}