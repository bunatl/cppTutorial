
/*
 * due to pure virtual function this class became an abstract class
 * This means no instance of this class can be created
 * Abstract class is more like a template
 */

#include <iostream>

using namespace std;

class Vehicle {
  public:
    Vehicle( int, int x = 0 );
    Vehicle( const Vehicle & );
    Vehicle& operator= ( const Vehicle & );
    int getNumberOfWheels() { return this->wheels; };
    //pure virtual function
    virtual void getMaxSpeed() = 0;
  //I want to use them also in derivated classes
  protected:
    int wheels;
    int maxSpeed;
};

//class derivated : public baseClass
class Car : public Vehicle {
  public:
    Car( int a, int x = 0 );
    Car( const Car & );
    Car& operator= ( const Car & );
    int getNumberOfWheels() { return this->wheels; };
    void getMaxSpeed() { cout << "max speed of a car" << endl; };
};

class Tuktuk : public Vehicle {
  public: 
    Tuktuk( int, int x = 0 );
    Tuktuk( const Tuktuk & );
    Tuktuk& operator= ( const Tuktuk & );
    int getNumberOfWheels() { return this->wheels; };
    void getMaxSpeed() { cout << "max speed of a tuktuk" << endl; };
};