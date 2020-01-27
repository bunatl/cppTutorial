#include "Student.h"

#include <iostream>

using namespace std;

/*
    Initilizing in constructor with semicolumns when:
    -Calling base class constructors
    -Initialising member variables before the body of the constructor executes. (const variables)

    https://stackoverflow.com/questions/2785612/c-what-does-the-colon-after-a-constructor-mean
*/
Student::Student( const pair<string, string> &name, const char &gender, const int &age ) : Person ( name, gender, age ) {
    this->m_studentGPA = 0;
    this->m_studentObtainedCredits = 0;
    this->m_studentDegree = none ;
}

Student::Student ( const Student & x ) : Person( x.m_personName, x.m_personGender, x.m_personAge ){
    Person::copyClassVariables( x );
    Student::copyClassVariables( x );
}

Student& Student::operator= ( const Student & x ){
    Person::copyClassVariables( x );
    Student::copyClassVariables( x );

    return *this;
}

void Student::info() const {
    cout << "Person with ID " << Person::m_personID << " is student with name: " << Person::m_personName.first << " " << Person::m_personName.second;
    cout << " {" << Person::m_personAge << ", " << Person::m_personGender << "}" << endl;
    cout << "With GPA: " << this->m_studentGPA << " from totaling " << this->m_studentObtainedCredits << " credits." << endl;

    cout << "Student has taken following courses: ";
    for ( pair<Course *, int> it : this->m_studentCompletedCourses )
        cout << it.first->getCourseName() << ", "; 
    cout << endl << endl;
}

bool Student::addCompletedCourse( Course *x, const int &grade ){
    pair<Course *, int> tmp = make_pair( x, grade );
    /*
        Since I am having object as a key I need to:
        - have op< in key class
        - custom comapison function

        https://thispointer.com/stdmap-tutorial-part-3-using-user-defined-class-objects-as-key-in-stdmap/
        https://stackoverflow.com/questions/49460854/why-does-stdmap-need-an-operator-and-how-do-i-write-one
        https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator
    */

    /*
        1) By using insert() I make sure there is no element in map
        In compare to [] where I don't know if I am overwriting or creating new one
        this->m_studentCompletedCourses [ x ] = grade;

        2) Insert() has pair<iterator,bool> return value

        1) https://stackoverflow.com/questions/326062/in-stl-maps-is-it-better-to-use-mapinsert-than
        2) http://www.cplusplus.com/reference/map/map/insert/
    */

    /*
     * if condition also triggers the action in its body
     * following if is equal to:
     * auto insertion = this->m_studentCompletedCourses.insert( tmp );
     *  if ( insertion.second == false )
     */
    if ( this->m_studentCompletedCourses.insert( tmp ).second == false )
        return false;

    calculateGPA();
    calculateCredits();
    determinateStudentDegree();

    return true;
}

void Student::calculateGPA() {
    //each Course can be in the map only once
    int nrOfcourses = this->m_studentCompletedCourses.size();
    int gradeSum = 0;

    /*
        Iteration through maps as described in:
        https://stackoverflow.com/questions/26281979/c-loop-through-map 

        C++98 style implemented
    */
    map<Course *, int>::iterator it;
    for ( this->m_studentCompletedCourses.begin(); it != this->m_studentCompletedCourses.end(); it++ )
        gradeSum += it->second;

    this->m_studentGPA = gradeSum / nrOfcourses;
}

void Student::calculateCredits() {
    int totalCredits = 0;

    /*
        Iteration through maps as described in:
        https://stackoverflow.com/questions/26281979/c-loop-through-map 

        C++11 style implemented
    */
    for ( pair<Course *, int> course : this->m_studentCompletedCourses )
        totalCredits += course.first->getCourseLoad();
    
    this->m_studentObtainedCredits = totalCredits;
}

void Student::determinateStudentDegree() {
    if ( this->m_studentObtainedCredits >= 180 && this->m_studentObtainedCredits < 300 )
        this->m_studentDegree = bachelor;
    else if ( this->m_studentObtainedCredits >= 300 )
        this->m_studentDegree = master;
}

void Student::copyClassVariables( const Student &x ){
    this->m_studentGPA = x.m_studentGPA;
    this->m_studentCompletedCourses = x.m_studentCompletedCourses;
    this->m_studentDegree = x.m_studentDegree;
    this->m_studentObtainedCredits = x.m_studentObtainedCredits;
}


/*
 * =====================
 * =====================
 * =====================
 * =====================
 * ++++++ STUFF ++++++
 * =====================
 * =====================
 * =====================
 * =====================
 */

//operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
Stuff& Stuff::operator= ( const Stuff &x ){
    /*
     * When we want to call base class use Class:: prefix
     * https://stackoverflow.com/questions/7644154/calling-base-class-virtual-method-by-derived-class-virtual-method
     */
    Person::copyClassVariables( x );
    //no stuff variables to be copied
    return *this;
}

//virtual functions
void Stuff::info() const{
    cout << "Person with ID " << Person::m_personID << " is university stuff with name: " << Person::m_personName. first;
    cout << " " << Person::m_personName.second << " is a proffesor ";
    cout << "{" << Person::m_personAge << ", " << Person::m_personGender << "}" << endl;
    cout << endl;
} 
