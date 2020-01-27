#include "naming.h"

#include <fstream>

/*
 * ======================================
 * ======================================
 * 
 * ++++++++ BULDING CHARSETS ++++++++++
 * 
 * =======================================
 * =======================================
 */


//build a string which contains all desired charsets
string buildCharset( vector<int> input ){
    string lowerChars = "abcdefghijklmnopqrstuvwxyz";
    string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numberChars = "123456789";
    string specChars = "!#$%&()*+,-./:;<=>?@[]^_`{|}~";

    string completeCharset = "";

    for ( unsigned int i = 0; i < input.size(); i++ )
        if ( input[ i ] == 1 )
            completeCharset += lowerChars;
        else if ( input[ i ] == 2 )
            completeCharset += upperChars;
        else if ( input[ i ] == 3 )
            completeCharset += numberChars;
        else if ( input[ i ] == 4 )
            completeCharset += specChars;
    
    return completeCharset;
}

//determinated is user's input is valid or not
bool isUserCharsetInputValid ( vector<int> input ){
    for ( unsigned int i = 0; i < input.size(); i++ )
        if ( input[ i ] != 1 && input[ i ] != 2 && input[ i ] != 3 && input[ i ] != 4 )
            return false;

    return true;
}

//take user input and convert it into a sorted int array
vector<int> charsetInputToArray( string input ){
    vector<int> tmp;
    
    for ( unsigned int i = 0; i < input.length(); i++ )
        tmp.push_back( input[ i ] - 48 );

    sort( tmp.begin(), tmp.end() );    

    return tmp;
}

char getNamingMethod(){
    char input = ' ';
    
    do {
        cout << "Do you want to generate normal names (N) or random (R)? ";
        cin >> input;
        input = toupper( input );
    } while ( input != 'N' && input != 'R' );

    return input;
}

//build charsets if get naming type for normal names then return empty string
//this will be used later in building names
string getCustomCharset(){
    if ( getNamingMethod() == 'N' )
        return "";

    vector<int> input;

    while ( true ){
        cout << "What character set should be used?" << endl;
        cout << "1 : abcdefghijklmnopqrstuvwxyz" << endl;
        cout << "2 : ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
        cout << "3 : 123456789" << endl;
        cout << "4 : !#$%&()*+,-./:;<=>?@[]^_`{|}~" << endl;
        cout << "Enter 1-4 digits according which sets you want to use: ";
        string userInput = "";
        cin >> userInput;
        
        input = charsetInputToArray( userInput );
        if ( isUserCharsetInputValid( input ) )
            break;
    } 

    return buildCharset( input );
}

/*
 * =======================================
 * =======================================
 * 
 * ++++++ GENERATING RANDOM NUMBERS ++++++
 * 
 * =======================================
 * =======================================
 */


/*
 * generate random number
 * https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
 */
int getRandomNumber( int min, int max ){
    // obtain a random number from hardware
    random_device rd;
    // seed the generator
    mt19937 eng( rd() );
    // set range
    uniform_int_distribution<> distr(min, max);

    return distr( eng );
}

vector<int> getVectorOfUniqueNumbers( int min, int max, int num ){
    vector<int> vec;

    if ( max < num )
        num = max;

    //fill vector in {n * O(1)} with sequence numbers
    for( int i = min; i < max; i++ )
        vec.push_back( i );
    
    /*
     * shuffle vector multiple times
     * https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
     */
    for ( int i = 0; i < 20; i++ )
        random_shuffle( vec.begin(), vec.end() );

    //set desired legth of vector
    for ( int i = vec.size(); i > num; i-- )
        vec.pop_back();

    return vec;
}

/*
 * ======================================
 * ======================================
 * 
 * ++++++++ BUILDING NAMES ++++++++++
 * 
 * =======================================
 * =======================================
 */


string buildName( string charset, vector<int> &UqRndNumVec ) {
    if ( charset == "" )
        return buildRealWorldName( UqRndNumVec ); //what if I would put * here??? do througt all reference!!!
    else 
        return buildRandomName( charset );
}

//build random names char by char
string buildRandomName( string charset ) {
    string name = "";
    int nameLenght = getRandomNumber( MIN_LENGTH_OF_NAMES, MAX_LENGTH_OF_NAMES );

    for ( int i = 0; i < nameLenght; i++ ){
        //generates rnd number within charset range (char's position)
        int charPos = getRandomNumber( 0, charset.length() );
        //add that char into name
        name += charset[ charPos ];
    }

    return name;
}

string buildRealWorldName( vector<int> &UqRndNumVec ){
    /*
     * Cpp reference guide for file manipulation
     * http://www.cplusplus.com/doc/tutorial/files/
     * 
     */ 

    int counter = 0;
    /*
    if ( fileName == "course.txt" && UqRndNumVec.back() > COURSES_FILE_LENGTH  ) //const for couses lenght
        {
            UqRndNumVec.pop_back();
            UqRndNumVec.push_back( getRandomNumber( 0, COURSES_FILE_LENGTH ) );
        }
    else if ( fileName == "firstNames.txt" && UqRndNumVec.back() > PERSONS_FILE_LENGTH  ) //const for names lenght
        {
            UqRndNumVec.pop_back();
            UqRndNumVec.push_back( getRandomNumber( 0, PERSONS_FILE_LENGTH ) );
        }
    else if ( fileName == "universities.txt" && UqRndNumVec.back() > UNIS_FILE_LENGTH  ) //const for unis lenght
        {
            UqRndNumVec.pop_back();
            UqRndNumVec.push_back( getRandomNumber( 0, UNIS_FILE_LENGTH ) );
        }
    */   
    string line, name;
    string pathToFile = "./data/" + fileName;
    //cout << "path to file: " << pathToFile << endl;
    ifstream myfile ( pathToFile );

    //how to access this array
    //Firtly, check that the file was opened. In case of non existance or in use. 
    if ( myfile.is_open() ){
        while ( getline ( myfile, line ) ){
            if ( counter == UqRndNumVec.back() ){
                //cout << "counter" << counter << endl; 
                name = line;
                //cout << "line:" << line << ":" << endl;
                
                //fileName = "lastNames.txt";
                //vector<int> tmp = UqRndNumVec.back(); //+ getRandomNumber( 0, NUMBER_OF_LINES - UqRndNumVec.back() );
                //UqRndNumVec.push_back( UqRndNumVec.back() );
                //name += buildRealWorldName( UqRndNumVec );
                //fileName = "firstNames.txt";
                
                UqRndNumVec.pop_back(); // destroy ptr???!!!
                //just removes it from the array

                //since we found our name (line), we stop the search (while loop)
                break;

            }
            counter++;
        }

        myfile.close();
    } else 
        cout << "Unable to open file"; 

    return name;
}

/*
 * ======================================
 * ======================================
 * 
 * ++++++++ CREATING INSTANCES ++++++++++
 * 
 * =======================================
 * =======================================
 */

//return set of commands for creating course instances
set<string> createCourseInstances( string charset, int num ){
    set<string> res;

    if ( COURSES_FILE_LENGTH < num )
        num = COURSES_FILE_LENGTH; 
        
    vector<int> uniqueNumbers = getVectorOfUniqueNumbers( 0, num, num );

    for( int i = 0; i < num; i++ )
        res.insert( buildName( charset, uniqueNumbers ) );
        //cout <<  "in round " << i << "adding " << tmp << endl;}

    //in order for next time names will be created from person
    fileName = "firstNames.txt";

    return res;
}

//create person instances
map<string,set<string> > createPersonInstances( string charset, int num, set<string> &coursesList ){
    map<string,set<string> > res;
    vector<int> uniqueNumbers = getVectorOfUniqueNumbers( 0, PERSONS_FILE_LENGTH, num );
    
    for( int i = 0; i < num; i++ ){
        set<string> coursesSet;
        string key = buildName( charset, uniqueNumbers );
        /*
         * there are 5 times more courses instances than persons instances
         * so each person can have 0 to 5 instances
         */
        int numOfSets = getRandomNumber( 0, 5 );
        for ( int i = 0; i <= numOfSets; i++ ){
            set<string>::iterator it = next( coursesList.begin(), getRandomNumber( 0, coursesList.size() - 1 ) );
            //insert the element into tmp list
            coursesSet.insert( *it );
        }
        //http://www.cplusplus.com/reference/map/map/insert/
        //res.insert( make_pair( key, coursesSet ) );
        res[ key ] = coursesSet;
    }

    fileName = "universities.txt";
    
    return res;
}

//creates universities instances
map<string, map<string, set<string> > > createUniversityInstances( string charset, int num, map<string, set<string> > &personList){
    map<string, map<string, set<string> > > res;

    if ( UNIS_FILE_LENGTH < num )
        num = UNIS_FILE_LENGTH; 

    vector<int> uniqueNumbers = getVectorOfUniqueNumbers( 0, num, num );

    for( int i = 0; i < num; i++ ){
        map<string, set<string> > personsMap;
        string key = buildName( charset, uniqueNumbers );
        /*
         * there will be always twice as much person instaces
         * so each uni can have up to 2 persons
         */
        int numOfSets = getRandomNumber( 0, 2 );
        for ( int i = 0; i <= numOfSets; i++ ){
            map<string, set<string> >::iterator it = next( personList.begin(), getRandomNumber( 0, personList.size() - 1 ) );
            //insert the element into tmp list
            personsMap.insert( *it );
        }

        res.insert( make_pair( key, personsMap ) );
    }

    return res;
}

/*
template <typename T > map<string, T> createInstance( string charset, int num, T &list){
    map<string, T> res;
    vector<int> uniqueNumbers = getVectorOfUniqueNumbers( 0, list.size(), num );
    
    for( int i = 0; i < num; i++ ){
        T tmpMap;
        string key = "this " + buildName( charset, uniqueNumbers ) + " will be created";
 
        int numOfSets = getRandomNumber( 0, 2 );
        for ( int i = 0; i <= numOfSets; i++ ){
            //https://stackoverflow.com/questions/11275444/c-template-typename-iterator
            typename T::iterator it = next( list.begin(), getRandomNumber( 0, list.size() - 1 ) );
            //insert the element into tmp list
            tmpMap.insert( *it );
        }

        res.insert( make_pair( key, tmpMap ) );
    }

    return res;
}
*/

string setFileName(){
    string fileName = "";
    cout << "Enter name of your file (.txt extention will be added automaticly): ";
    cin >> fileName;
    return fileName + ".txt";
}

bool writeToFile( set<string> &coursesList, map<string,set<string> > &personsList, map<string, map<string,set<string> > > &unisList ){

    //reference guide
    //https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
    //!!!!!!!
    
    ofstream f( setFileName() );

    cout << "File has been created." << endl;
    cout << "Writing to file..." << endl;

    //here has to be to format which the main app will recognize
    for ( const string &courseName : coursesList )
        f << courseName << endl;

    for ( const pair<string, set<string> > &person : personsList ){
        f << person.first << endl;
        for ( const string &personCourse : person.second )
            f << personCourse << endl;
    }

    for ( const pair<string, map<string, set<string> > > &uni : unisList ){
        f << uni.first << endl;
        for ( const pair<string, set<string> > &uniPerson : uni.second ){
            f << uniPerson.first << endl;
            for ( const string &uniPersonCourse : uniPerson.second )
                f << uniPersonCourse << endl;
        }
    }

    f.close();    
    return true;
}

void showCreatedInstances( set<string> &coursesList, map<string,set<string> > &personsList, map<string, map<string,set<string> > > &unisList ){
    char input = ' ';
    
    do {
        cout << "Do you want to show generated name? Yes (Y) or No (N)? ";
        cin >> input;
        input = toupper( input );
    } while ( input != 'N' && input != 'Y' );
    
    if ( input == 'N' )
        return;

    string coursePrefix = "@Course: ";
    string personPrefix = "##Person: ";
    string uniPrefix = "===University: ";

    cout << endl << "====== COURSES ======" << endl;

    for ( const string &courseName : coursesList )
        cout << coursePrefix << courseName << endl;

    cout << endl << "========= PERSONS =========" << endl;

     for ( const pair<string, set<string> > &person : personsList ){
        cout << personPrefix << person.first << endl;
        for ( const string &personCourse : person.second )
            cout << coursePrefix << personCourse << endl;
     }

    cout << endl << "======= UNIVERSITIES ==========" << endl;

    for ( const pair<string, map<string, set<string> > > &uni : unisList ){
        cout << uniPrefix + uni.first << endl;
        for ( const pair<string, set<string> > &uniPerson : uni.second ){
            cout << personPrefix << uniPerson.first << endl;
            for ( const string &uniPersonCourse : uniPerson.second )
                cout << coursePrefix << uniPersonCourse << endl;
        }
    }        
}