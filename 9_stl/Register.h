/*
 * Register keep track of cars and their oweners
 * 
 * class car and register plate
 * clss set of previous oweners
 * 
 */
#include <map>
#include <set>
#include <string>

using namespace std;

class Car{
  public:
    Car( const string, const int );
    Car( const Car & );
    Car& operator= ( const Car & );
    //operator < has to be implemented since this class is used in map and set
    bool operator< ( const Car* );

    string getRegisterPlate() { return this-> registerPlate; };
    int getMilage() { return this->mileage; };
    void setYearOfManufactory( int x ) { this->yearOfManufactory = x; };
    int getYearOfManufactory() { return this->yearOfManufactory; };

  private:
    Car();
    string registerPlate;
    int mileage;
    int yearOfManufactory;
};

//class Register has to be declared after class Car
class Register{
  public:
    Register(){};
    Register( const Register & );
    Register& operator= ( const Register & );
    bool registerCar( int, Car* );
    bool removeFromRegister ( int );
    int getTotalCarsInRegister();
    int getTotalPeopleInRegister() { return this->centralRegister.size(); };
    map<int, set< Car* > > getRegister() { return this->centralRegister; } ;

  private:
    /*
     * Central register storing each owener with set all of his/hers cars
     * Used classes in STL cointener have to declared first
     * We want to store pointer instead of instances of class
     * - it is faster and takes less memory
     */ 
    map< int, set< Car* > > centralRegister;
};