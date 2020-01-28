#include <iostream>
#include "ComplexNumber.h"

int main(){

  //static allocation
  std::cout << "Static allocation" << std::endl;
  ComplexNumber x(1);
  ComplexNumber y(5,5);

  (x + y).print();

  x.print();
  x += y;
  x.print();

  (x * 5).print();
  x.print();
  (*x).print();


  //dynamic allocation
  std::cout << "Dynamic allocation" << std::endl;
  ComplexNumber *z = new ComplexNumber();
  ComplexNumber *a = new ComplexNumber( 0, 0 );
  ComplexNumber *b = new ComplexNumber( 5, 5 );
  ComplexNumber *c = new ComplexNumber( 8, 15 ); 

  z->print();

  a->print();
  b->print();
  c->print();

  *a = *c + *b;

  a->print();

  *a += *b;

  a->print();

  *a = *a * 10;
  a->print();

  //unary operator and pointer dereference
  (**a).print();

  //after dynamic allocation memory chunks have o be destroyed and freed
  //4 * 8B memory is freed
  //valgrind can help with tracking memeory leaks
  delete z;
  delete a;
  delete b;
  delete c;

  return 0;
}