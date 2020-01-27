#ifndef STUDENT_H
#define STUDENT_H
/*
 * #include guards.
 * Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.
 * When the code is included again, the first ifndef fails, resulting in a blank file. That prevents double declaration of any identifiers such as types, enums and static variables. 

 * https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
 */

#include "Person.h"
#include "Course.h"

#include <string>
#include <map>
#include <utility> //std::pair

/*
 * using namespace std;
 * shoudln't be used because it would has to be included everywhere
 */
using std::string;


/*
Enumerations (C++)
each element is equivalent to int for its position
ex. none = 0, bachelor = 1
if I would like to have strings, I need to map in std::map
https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings

if constant would not be related i should you constants
static const string NONE;
static const string BC;
static const string MASTER;

constants must be initize before class initilization
so in construtor() : CONSTANT( value ) {};
https://stackoverflow.com/questions/14495536/how-to-initialize-const-member-variable-in-a-class
*/

enum degree { 
    none, 
    bachelor, 
    master
};

//derivated class from Person
class Student: public Person {
  public:
    /*
     * in student constructor are two argument provided implicitely - so name is enough
     * parametric constructor will be always called
     */ 
    Student() : Student( std::make_pair("", "") ) {};
    Student( const std::pair<string, string> &, const char & = '-', const int & = 0 );
    Student ( const Student & );
    ~Student() {};

    //operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
    Student& operator= ( const Student & );

    //virtual from Person
    virtual void info() const;
  
    double getGPA() const { return this->m_studentGPA; };
    int getCredits() const { return this->m_studentObtainedCredits; };
    std::map<Course *, int> getStudentCompledCourses() const { return this->m_studentCompletedCourses; };

    bool addCompletedCourse( Course *, const int & );
    
  //class members are private by default
  private:
    //calculate function are called from within class to "update values"
    void calculateGPA();
    void calculateCredits();
    void determinateStudentDegree();

    void copyClassVariables( const Student & );

    //each student can take only 
    std::map<Course *, int> m_studentCompletedCourses;

    double m_studentGPA;
    int m_studentObtainedCredits;
    degree m_studentDegree;

};


//derivated class from Person
class Stuff: public Person {
  public:
    /*
     * To inicialize variables in base from derivared constructor do
     * Write base class constructor incializing base class variables
     * Call from derivated constructor, base class constructor
     * That way it inicialized base class variables
     * 
     * https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor
     * 
     * Stuff has no class variables which we would inicialize 
     */ 
    Stuff() : Person( std::make_pair("", "") ) {};
    Stuff( const std::pair<string, string> &n, const char &g = '-', const int &a = 0 ) : Person( n, g, a ) {};
    Stuff ( const Person &x ) : Person( x ){ Person::copyClassVariables( x ); };
    ~Stuff() {};

    Stuff& operator= ( const Stuff & );
  
    //virtual functions
    void info() const; 
    int getPersonID() const;

    bool setGrade( Student student, Course *course, const int &grade ) {  return student.addCompletedCourse( course, grade ); };

  //class members are private by default
  private:

};


#endif