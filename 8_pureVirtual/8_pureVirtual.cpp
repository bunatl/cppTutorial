/*
 * Pure virtual functions allows to call methods in desired classes, 
 * based on class the pointer pointing at
 * 
 * Pure virtual function in abstract class doesnt have its body and picking 
 * method in corresponding class
 * 
 * Pure virtual function has no body
 * It cant have any code since always coresponding function in other classes are called
 */

#include "Vehicle.h"

int main(){

  Vehicle *v;
  //cout << v->getMaxSpeed() << endl;
  Vehicle *c = new Car( 10, 100 );
  v = c;
  v->getMaxSpeed();
  Vehicle *t = new Tuktuk( 10, 100 );
  //assign new class to the pointer
  v = t;
  v->getMaxSpeed();

  return 0;
}
