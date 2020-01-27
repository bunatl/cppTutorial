#include <string>

using std::string;

/*
 * Implent my own class car
 * Only heads of classes are showns here
 * The only exception is one line function 
 * 
 */

class Car{
//public means it can be from outside its class
public:
    //constructor
    Car( int, int );
    //destructor, is not needed unless you alocate memory
    ~Car(){};

    int getDoor() { return this->doors; };
    //keyword this is used when reffereing to class varibale
    //this is a pointer thefore using ->
    //this-> is equal to (*this)
    void setDoors( int doors ){ this->doors = doors; };

    int getWeight() { return this->weight; };
    void setWeight( int weight ){ this->weight = weight; };

    string getBrand(){ return this->brand; };
    void setBrand( string brand ) { this->brand = brand; };

    void updatePrice();
    double getPrice() { return this->price; };

private:
    //this way implicit constructor is not allowed
    Car();
    int doors;
    int weight;
    string brand;
    double price;

    double computePrice( int, int );
};
