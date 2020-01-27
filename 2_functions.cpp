#include <iostream>
#include <string>

using namespace std;

int addNumbers( int a, int b = 50){
    return a + b;
}

void overloadFunction(){
    cout << "I am overload function with no argument" << endl;
}

void overloadFunction( int i ){
    cout << "I am overload function with integer argument " << i << endl;
}

void overloadFunction( string str ){
    cout << "I am overload function with string argument " << str << endl;
}

void overloadFunction( double d ){
    cout << "I am overload function with double floating argument " << d << endl;
}

bool isPrime( int num ){

    // Corner case 
    if (num <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < num; i++) 
        if (num % i == 0) 
            return false; 

    return true;
}


//always devided your code into section by functionality - create functions
int main (){

    int num = 0;
    cout << "Enter a number, you want to know if it is a prime number: ";
    cin >> num;

    cout << "The number " << num;
    string myString = ( isPrime( num ) ) ? " is a prime number" : " is not a prime number";
    cout << myString << endl;

    //functions can be overloaded
    //function with the same name but different arguments can do different task
    overloadFunction();
    overloadFunction( 5 );
    overloadFunction( "test" );
    overloadFunction( 5.55 );

    //implicit arguments are "preset values" in function argument
    //implicit arguments are used when no others are specified

    cout << addNumbers( 10, 8 ) << endl;
    //when second argument is ommited implicit is used
    cout << addNumbers( 10 ) << endl;

    return 0;
}