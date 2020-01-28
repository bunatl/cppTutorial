/*
 * Inheritance occurs when one or more classes inherint certain attributes from its parent class
 * Derivated class can be assign to its parent class
 * In this example is vehicle parent class and car, formula and tuktuk are derivated classes
 * 
 * Polymorphism = late binding
 * As shown here: https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm, polymorhpism
 * allows to bind classes (after linking) to pointers
 * 
 * It is different from virtual functions. Virtual function allow overload function based on class what is calling.
 * Virtual function is in base parent class.
 * 
 */

#include "Vehicle.h"

#include <iostream>

using namespace std;


int main(){

  Vehicle *v = new Vehicle( 5, 150 );
  cout << v->getMaxSpeed() << endl;

  Vehicle *c = new Car( 10, 100 );
  cout << c->getMaxSpeed() << endl;

  Formula *f = new Formula( 4, 400 );
  
  Vehicle *v1;
  cout << v1->getMaxSpeed() << endl;
  Tuktuk *t = new Tuktuk ( 3, 50 );
  v1 = t;
  cout << v1->getMaxSpeed() << endl;


  return 0;
}

 