#include "ComplexNumber.h"

#include <iostream>
using namespace std;

//only methods returning obejcts need to return a reference

ComplexNumber::ComplexNumber( int real, int img ){
  this->re = real;
  this->im = img;
}

ComplexNumber::ComplexNumber( const ComplexNumber &x ){
  this->re = x.re;
  this->im = x.im;
}

ComplexNumber& ComplexNumber::operator= ( const ComplexNumber &x ){
  this->re = x.re;
  this->im = x.im;
  return *this;
}

ComplexNumber ComplexNumber::operator+ ( const ComplexNumber &x ){
  return ComplexNumber( this->re + x.re, this->im + x.im );
}

ComplexNumber ComplexNumber::operator- ( const ComplexNumber &x ){
  return ComplexNumber( this->re - x.re, this->im - x.im );
}

ComplexNumber& ComplexNumber::operator+= ( const ComplexNumber &x ){
  //invoke overload op+
  *this = *this + x;
  return *this;
}

ComplexNumber& ComplexNumber::operator-= ( const ComplexNumber &x ){
  //invoke overload op-
  *this = *this - x;
  return *this;
}

ComplexNumber& ComplexNumber::operator* (){
  this->re = 0;
  this->im = 0;
  return *this;
}

ComplexNumber& ComplexNumber::operator* ( int x ){
  this->re *= x;
  this->im *= x;
  return *this;
}

void ComplexNumber::print(){
  cout << "Complex number is " <<
    this->re << " + " << this->im << "i" << endl;
}