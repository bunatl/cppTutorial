#include <iostream>

using namespace std;

void hardSwap (int& first, int& second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 

void swap2 (int *first, int *second) 
{ 
    int temp = *first; 
    first = second; 
    *second = temp; 
} 

void swap (int first, int second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 

void pointerSwap (int *first, int *second) 
{ 
    int temp = *first; 
    *first = *second; 
    *second = temp; 
} 


int main(){

    /*
     * There are two types of references: (hard) reference & and pointer *
     * Pointers "pointing" to a location (physical address) in memory where variable is store
     * Reference is working directly with the variable on a specific address
     * When passing varibale (not a reference) to a function a local copy is created for teh function
     * To speed up your programs and work more efficiantly work with refrences and pointers
     */

    //declare local variable in main function
    int x = 1, y = 2;
    //create a general pointer
    int *px;
    //an address is assign a pointer
    cout << px << endl;
    //no value has been assigned yet
    cout << *px << endl;
    //assign a reference address to pointer
    px = &x;
    //the address has changed since the pointer is poiting to a different (new) variable
    cout << px << endl;
    //pointer is poiting to a value
    cout << *px << endl;
    //to access a value what pointer px is pointing to you have dereference a pointer
    //to dereference a pointer add a * infront of pointer
    *px = 3;
    //address doesnt change
    cout << px << endl;
    //only the value was chnaged - the address stayed same
    cout << *px << endl;

    int &ry = y;
    //to access value from a reference
    ry = 4;
    cout << ry << endl;


    int x1 = 5;
    int x2 = 10;

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    swap( x1, x2 );

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    hardSwap( x1, x2 );

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    pointerSwap( &x1, &x2 );

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    swap2 ( px, &x2 );

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;


    return 0;
}