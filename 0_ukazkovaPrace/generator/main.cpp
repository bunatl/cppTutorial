/*
 * List of first names obtained from:
 * http://www.gutenberg.org/ebooks/3201
 * 
 * List of last names obtained from:
 * https://www.scrapmaker.com/view/names/surnames.txt
 * 
 * List of universities cloned from:
 * https://github.com/endSly/world-universities-csv
 * and then parsed via bash terminal
 * 
 * nacitani ze souboru n*n
 * vytvoreni - sort - nacteni - 1*n + log n + n
 * 
 * 
 */

#include <iostream>
#include <cctype> //std::toupper
#include <vector>
#include <stdlib.h> //std::rand
#include <algorithm> //std::sort
#include <set>
#include <random> //std::rand
#include <map>
#include <fstream>

#include "naming.h"
#include "timer.h"

using namespace std;

/*
 * Function asks user for input
 * Input is how many instances should be generated
 * Input has to be positive integer
 * Input is valited before exiting function
 * If it is not valid, user is aksed again
 */
int getNrOfValues() {
    int input = 0;
    do{
        cout << "How many values should be generated? ";
        cin >> input;
    } while ( input < 0 );

    return input;   
}

int main(){
    int numberOfValues = getNrOfValues();
    string charset = getCustomCharset();
    
    cout << "Staring creating instances..." << endl;
    Timer tmr;

    set<string> coursesList = createCourseInstances( charset, 10 * numberOfValues );
    map<string,set<string> > personList = createPersonInstances( charset, 2 * numberOfValues, coursesList );
    map<string, map<string,set<string> > > universityList = createUniversityInstances( charset, numberOfValues, personList );

    //map<string,set<string> > personList = createInstance( charset, 2 * numberOfValues, coursesList );
    //fileName = "universities.txt";
    //map<string, map<string,set<string> > > universityList = createInstance( charset, numberOfValues, personList );

    double timeDiff = tmr.elapsed();
    cout << "All instances have been created in " << timeDiff << " seconds." << endl;
    
    showCreatedInstances( coursesList, personList, universityList );

    /*
    Mozne rozsireni

    cout << "Starting creating methods..." << endl;
    methods based on previous instanes (created either random ore from file)
    course -> person, person -> university
    cout << "All methods have been created." << endl;
    */

    if ( writeToFile( coursesList, personList, universityList ) )
        cout << "All instances have been written into the file." << endl;
    else
        cout << "A problem has occured during writing into files.";
    
    return 0;
}