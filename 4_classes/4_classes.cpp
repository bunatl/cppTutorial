//in this main class are other classes only created and theirs methods are used
//funtions stands alone whereas methods is a function inside a class 


/*
 * c++ program has 3 main parts: main.cpp, header file (.h) and class implementations in cpp
 * Header file is a "link" between main file and class files 
 * In header files are included class implementaions
 * Main includes header files - therefore in main are header files an also class implementations
 */

//include header file of my class car
#include "Car.h"

#include <iostream>

using namespace std;

int main(){

    Car *carA = new Car ( 5, 1400 );

    cout << "Weight of a car is " << carA->getWeight() << endl;

    cout << "This car costs " << carA->getPrice() << endl;
    carA->setWeight( 2500 );
    carA->updatePrice();
    cout << "Weight of a car is " << carA->getWeight() << endl;
    cout << "This car costs " << carA->getPrice() << endl;

    delete carA;

    Car carB( 5,66 );

    return 0;
}