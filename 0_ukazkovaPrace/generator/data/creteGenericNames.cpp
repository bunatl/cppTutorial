#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LIMIT 20000

int main (){

    string instance = "University"; 

    ofstream file( "generated" + instance + ".txt" );
    
    for ( int i = 0; i < LIMIT; i++ ){
        file << instance << i << endl;
        cout << instance << i << endl;
    }

    file.close();

    return 0;
}