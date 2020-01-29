 /* 
  * Exception ensuring smooth run of the program
  * Catching uncaught errors what occur during runtime and waerent caught during compilation
  * Exceptions using three key words: try, catch and throw
  * 
  * Exception prevent crash of the program and solve it during runtime
  * 
  * There can be different types of exceptions - c++ has a lib Exception
  * 
  * Potentionally "dangerous code" for program is in a try block
  * In try block checks happen and if inpropriete value occurs throw steps in
  * Throw throws a value(+data type) what is pecified after keyword throw
  * After try block follows catch block - more than one ctach block can be used
  * Each catch block can catch different data type
  * Order of the catch block matter - first written first tried
  * 
  */

#include <iostream>
#include <cctype> 
//to implement own exception a lib has to included
#include <exception>

using namespace std;

class Example{
  public:
    Example( int i, string str ) : exStr( str ), exInt( i ) {};

    int getExInt() { return this->exInt; };
    string getExStr() { return this->exStr; };

  private:
    string exStr;
    int exInt;
};


//custom exception, derivated from class exception
class myexceptionstandard: public exception {
  public:
  virtual const char* what() const throw() {
    return "My exception happened";
  }
  //shorten name
} myexstd;


//custom exception is motly used when dealing with more complex structures
class eachExceptionShouldHaveProblemInItsName: public exception {
  public:
    //in exception costructor pass class instance and store it privately in myexcepton class
    eachExceptionShouldHaveProblemInItsName( Example ee ) : e( ee ) {};

    //when working with exception, exceptions public method will be used
    //public method using public method of origin example class
    int getExIntInExampleClass() { return this->e.getExInt(); };
  private:
    //eachExceptionShouldHaveProblemInItsName();
    Example e;
};



int main(){
  Example exampleClass( 26, "textName" );

  try{
    int i = 0;
    cout << "Enter a number 1-5: " << endl;
    cin >> i;

    string str = "anyString";

    switch( i ){
      case 1:
        throw 5454;
        break;
      case 2:
        throw str;
        break;
      case 3:
        throw myexstd;
        break;
      case 4:
        throw eachExceptionShouldHaveProblemInItsName( exampleClass );
        break;
      default:
        throw 0.55;
    }
  }
  catch( int ex ){
    cout << "This exception is invoked when integer is thrown." << 
      "Whole block is executed." << endl;
    cout << "Also thrown 'argument' can displayed: " << ex << endl;
  }
  catch( string ex ){
    cout << "This exception is invoked when string is thrown." << endl;
  }
  //catch block from my own exception
  catch( myexceptionstandard& e ){
    cout << "Standard exception: " << e.what() << endl;
  }
  catch ( eachExceptionShouldHaveProblemInItsName& ex ){
    cout << "Int a thrown Example class is: " << ex.getExIntInExampleClass() << endl;
  }
  // ... is equal to any exception
catch( ... ){
  cout << "this catch block catches all not previously definied throws" << endl;
}
//other standart c++ lib exceptions are: bad_allow, bad_cast, runtime_error

cout << "Do you want another try? Y/N" << endl;
char ch = 'N';
cin >> ch;
if ( toupper(ch) == 'Y' )
  main();

return 0;
}