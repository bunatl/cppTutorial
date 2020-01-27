#ifndef UNIVERSITY_H
#define UNIVERSITY_H
/*
 * #include guards.
 * Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.
 * When the code is included again, the first ifndef fails, resulting in a blank file. That prevents double declaration of any identifiers such as types, enums and static variables. 

 * https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
 */

#include "Course.h"
#include "Person.h"

//university libraries
#include <string>
#include <set>
#include <memory> //std::shared_prt

//faculty library
#include <vector>

/*
 * using namespace std;
 * shoudln't be used because it would has to be included everywhere
 */

using std::string;

/*
 * Class holds a name of university, number of people who are studing/working at university as well as their list.
 * List of people is represented as std::set, since we are expecting to often add or remove people.
 * Adding or removing people is done vie addPerson() and deletePerson(). 
 */
class University {
  public:
    /*
     * Since C++11 we can chain constructors
     * As mentioned here: https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
     * And pros listed here: https://stackoverflow.com/questions/26199431/why-did-c11-introduce-delegating-constructors
     * From non-parametric constructor is called parametric constructor 
     */
    University() : University ( "" ) {};
    University( const string &x );
    University ( const University &x ) { copyClassVariables( x ); };
    ~University(){};

    //operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
    University& operator= ( const University & );

    string getUniversityName() const { return this->m_universityName; };
    void setUniversityName( const string &x ) { this->m_universityName = x; };

    bool addPerson( Person * );
    bool deletePerson( Person * );
   
    std::set<Person *> getPersonList() const { return this->m_personList; };
    int getNumberOfPeople() const { return this->m_personList.size(); };
    
    virtual void info() const;

  //variables will be visiable for derivated classes
  protected:
    //using set because for inserting and removing values is log(n) compared to vector's n
    std::set<Person *> m_personList;
    /*
     * virtual function can be protected or private too
     * depending if you want to access them
     */
    void copyClassVariables( const University & );
    
  //class variables are private by default
  private:
    string m_universityName;
    int m_universityNumberOfPeople;
};


/*
 * =====================
 * =====================
 * =====================
 * =====================
 * ++++++ FACULTY ++++++
 * =====================
 * =====================
 * =====================
 * =====================
 */


/*
 * Class has own members on top of those from University class
 * Course keeps a list of all courses taught at this faculty ( m_courseList )
 * 
 * derivated class from University 
 */ 
class Faculty : public University {
  public:
    /*
     * Since C++11 we can chain constructors
     * As mentioned here: https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
     * And pros listed here: https://stackoverflow.com/questions/26199431/why-did-c11-introduce-delegating-constructors
     * From non-parametric constructor is called parametric constructor 
     */
    Faculty() : Faculty( "" ) {};
    Faculty( const string & );
    Faculty ( const Faculty & );
    ~Faculty(){};
    
    //operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
    Faculty& operator= ( const Faculty & );
    /*
     * Not allowed to return reference, otherwise once overwrite static variable from op+ (what I am returning) it would be pointing nowhere
     * operators +- adding or removing courses from courses list
     */ 
    Faculty operator+ ( Course * );
    Faculty operator- ( const Course * );
    
    //info() is a virtual function
    void info() const; 

    string getFacultyName() const { return this->m_facultyName; };
    void setFacultyName( const string &x ) { this->m_facultyName = x; };

    std::vector<Course *> getCourseList() const { return this->m_coursesList; };
    int getNumberOfCourses() const { return this->m_numberOfCourses; };

  //class members are private by default
  private:
    void copyClassVariables( const Faculty & );

    string m_facultyName;
    //using set would be better in this case, however for learning purposes I used vector
    std::vector<Course *> m_coursesList;
    int m_numberOfCourses;
    
};

#endif