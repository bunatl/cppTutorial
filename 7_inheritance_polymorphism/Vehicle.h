/*
 * Class can have public, protected, private inheritance.
 * Private atrribute are never inherited.
 * In public inheritance are public and protected attr are as public and protected respectively.
 * In protected inheritance are public and protected attr inherited as protected
 * In private inheritance are both attr inherited as private.
 * 
 * getNumberOfWheels() method is using polymorphysm
 * getMaxSpeed() is a virtual fucntion
 */

/*
 * Import to note, that everytime a derivated instace is created
 * also parent/base instance has o be create
 * So, everytime derivated constructor or copy const is calles, 
 * parent/base constructor has to be called and iniciated! 
 */

//parent class
class Vehicle {
  public:
    Vehicle( int, int x = 0 );
    Vehicle( const Vehicle & );
    Vehicle& operator= ( const Vehicle & );
    int getNumberOfWheels() { return this->wheels; };
    virtual int getMaxSpeed() { return this->maxSpeed; };
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
    int getMaxSpeed() { return this->maxSpeed; };
  private:
    // int wheels;
    // int maxSpeed;
};

class Formula : public Vehicle {
  public:
    Formula( int, int x = 0 );
    Formula( const Formula & );
    Formula& operator= ( const Formula & );
    int getNumberOfWheels() { return this->wheels; };
    int getMaxSpeed() { return this->maxSpeed; };
  private:
    // int wheels;
    // int maxSpeed;
};

class Tuktuk : public Vehicle {
  public: 
    Tuktuk( int, int x = 0 );
    Tuktuk( const Tuktuk & );
    Tuktuk& operator= ( const Tuktuk & );
    int getNumberOfWheels() { return this->wheels; };
    int getMaxSpeed() { return this->maxSpeed; };
  private:
    // int wheels;
    // int maxSpeed;
};