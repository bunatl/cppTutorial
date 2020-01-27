//one line comment

/*
 *  Multi line comment
 */

/*
 * Tips:
 * 
 * Do comment every functionally (especially functions) what are not 100 % clear what they do
 * When you use any functionally from other sources (like stackoverflow) put the source into comment as reference
 * Write clean code
 * Always think about teh problem first, then start writting the code
 * For help use offcial reference: en.cppreference.com
 * Coding style: https://stackoverflow.com/questions/18170944/c-coding-style
 * 
 */ 

//a library input
//iostream library allows to manipuylate streams = allow to to print outputs and 
#include <iostream>

// see more on: https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm
/*
 * For now, most of the functions are store in std namespace
 * To access them you have first access this namespace
 * You access namespace by declarring is by std::
 * By declaring at the beggining use don't have to declare every single function
 */  
using namespace std;

/*
 * main() is a function where program execution begins
 * main has to return an int, therefore at the has be key word return followed by integer
 */ 
int main() {
    // prints Hello World
    cout << "Hello World"; 

    //endl prints a new line
    cout << endl;


    /*
     * data types in C++
     * most of the types has unsigned type too
     * numeric data types long type on top of that
     */ 

    //boolean
    bool flag;
    //character - 1B
    char ch;
    //integer - 4B
    int i;
    //floating point - 4B
    float f;
    //double floating point - 8B
    double d;
    //valueless is void - used mainly in fuctions


    cout << "Enter a number" << endl;
    //read standart input
    cin >> i;


    return 0;
}