#include "Register.h"


Register::Register( const Register &x ){
  this->centralRegister = x.centralRegister;
}

Register& Register::operator= ( const Register &x ){
  this->centralRegister = x.centralRegister;
}

bool Register::registerCar( int personID, Car* car ){
  //to iterate in a map an iterator has to be set
  map<int, set < Car* > >::iterator it;
  it = this->centralRegister.find( personID );

  //https://stackoverflow.com/questions/26281979/c-loop-through-map
  if ( it == this->centralRegister.end() ) {
    //a set has to created in order to be plased in a map
    set< Car* > tmp = { car };
    this->centralRegister.emplace( personID, tmp );
    return true;
  }

  //it->second points to a set
  it->second.insert( car );
  return true;
}

bool Register::removeFromRegister ( int personID ){
  //map erase: http://www.cplusplus.com/reference/map/map/erase/
  if ( this->centralRegister.erase( personID ) > 0 )
    return true;

  return false;
}

int Register::getTotalCarsInRegister(){
  int cars = 0;
  //iterate throught each el in a map and then through each element in a set
  //c++11 approach
  //auto is equal to map<int, Car* >::iterator
  for ( auto const& x : this->centralRegister ) {
    //for each key in the map count size of set (value of the key)
    cars += x.second.size();
  }

  return cars;
}

Car::Car( const string registerPlate, const int mileage ){
  this->registerPlate = registerPlate;
  this->mileage = mileage;
}

Car::Car( const Car &x ){
  this->registerPlate = x.registerPlate;
  this->mileage = x.mileage;
}

Car& Car::operator= ( const Car &x ){
  this->registerPlate = x.registerPlate;
  this->mileage = x.mileage;
}

bool Car::operator< ( const Car *x ){
  return this->registerPlate.compare( x->registerPlate );
}