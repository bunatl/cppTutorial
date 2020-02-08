/*
 * Friend can be function or classes
 * Mostly used to display some inf about classes (<<)
 */

#include <iostream>

using namespace std;

class rectangle{
  public:
    rectangle( int xa, int xb ) : a( xa ), b( xb ){}
    /*
     * Frined function is declared in public space
     * Using frined keyword at the begining
     * Friend function, although declared outside this class, 
     * can access private attributes just like function of this class
     * -> it is declared outside this class
     * ->it is not a member of this class, can only access its attributes
     */
    friend void calcArea( rectangle &x );
    int getArea() { return this->area; };

  private:
    int a;
    int b;
    int area;

};

void calcArea ( rectangle &x ){
  cout << x.a * x.b << endl;
  //passed object has to be reference
  //because next line writes to obj attribute
  x.area = x.a * x.b;
};

int main(){

  rectangle r1(10, 5);
  calcArea( r1 );

  cout << r1.getArea() << endl;

  return 0;
}