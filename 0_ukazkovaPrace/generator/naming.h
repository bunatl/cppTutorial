#ifndef NAMING_H
#define NAMING_H
/*
 * #include guards.
 * Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.
 * When the code is included again, the first ifndef fails, resulting in a blank file. That prevents double declaration of any identifiers such as types, enums and static variables. 

 * https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
 */

/*
 * Has type and it is a constant
 * compared to #define which replace all occurences in program
 * http://www.informit.com/articles/article.aspx?p=1703469&seqNum=5
 */
#define MIN_LENGTH_OF_NAMES 5
#define MAX_LENGTH_OF_NAMES 20
#define COURSES_FILE_LENGTH 20000
#define PERSONS_FILE_LENGTH 20000
#define UNIS_FILE_LENGTH 20000

#include <iostream>
#include <cctype> //std::toupper
#include <vector>
#include <stdlib.h> //std::rand
#include <algorithm> //std::sort
#include <set>
#include <random> //std::rand
#include <map>

using namespace std;

static string fileName = "course.txt";

/*
 * Function asks user for input
 * Input is how names should be created
 * Input has to be char R, r or N, n
 * Input is valited before exiting function
 * If it is not valid, user is aksed again
 */
char getNamingMethod();

//take user input and convert it into a sorted int array
vector<int> charsetInputToArray( string input );

//determinated is user's input is valid or not
bool isUsetCharsetInputValid ( vector<int> input );

//build a string which contains all desired charsets
string buildCharset( vector<int> input );

/*
 * Gets input from getNamingMethod
 * Based on result create a charset used for creating names 
 */
string getCustomCharset();

/*
 * generate random number
 * https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
 */
int getRandomNumber( int min, int max );

string buildName( string charset, vector<int> & );

//build random names char by char
string buildRandomName( string charset );

string buildRealWorldName( vector<int> & );

//return set of commands for creating course instances
set<string> createCourseInstances( string charset, int num );

vector<int> getVectorOfUniqueNumbers( int min, int max, int num );

//create person instances
map<string,set<string> > createPersonInstances( string charset, int num, set<string> &coursesList );

//creates universities instances
map<string, map<string, set<string> > > createUniversityInstances( string charset, int num, map<string, set<string> > &personList);

//template <typename T> map<string, T> createInstance( string charset, int num, T &list);


/*
 *
 * 
 * 
 * 
 */

string setFileName();

bool writeToFile( set<string> &, map<string,set<string> > &, map<string, map<string,set<string> > > & );

void showCreatedInstances(  set<string> &, map<string,set<string> > &, map<string, map<string,set<string> > > & );

#endif