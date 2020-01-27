#ifndef COURSE_H
#define COURSE_H
/*
 * #include guards.
 * Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.
 * When the code is included again, the first ifndef fails, resulting in a blank file. That prevents double declaration of any identifiers such as types, enums and static variables. 

 * https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
 */

#include <string>

/*
 * using namespace std;
 * shoudln't be used because it would has to be included everywhere
 */

using std::string;

/*
 * Class contains detail information about Course. 
 * Allows get and set course credit load and name.
 * If default constructor is called, it will pass object  will "default NULL" values;
 */
class Course {
  public:
    /*
     * Since C++11 we can chain constructors
     * As mentioned here: https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
     * And pros listed here: https://stackoverflow.com/questions/26199431/why-did-c11-introduce-delegating-constructors
     * From non-parametric constructor is called parametric constructor 
     */
    Course() : Course( "", 0 ) {};
    Course( const string &, const int & );
    Course ( const Course &x ) { copyClassVariables( x ); };
    ~Course() {};
    
    //operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
    Course& operator= ( const Course & );
    bool operator== ( const Course * ) const;
    bool operator< ( const Course * ) const ;
  
    void info() const;
    int getCourseID() const { return this->m_courseID; };

    int getCourseLoad() const { return this->m_courseLoad; };
    void setCourseLoad( const int &x ) { this->m_courseLoad = x; };
    
    string getCourseName() const { return this->m_courseName; };
    void setCourseName( const string &x ) { this->m_courseName = x; };

  //class members are private by default
  private:
    void copyClassVariables( const Course & );

    /*
     * Course ID has to be unique
     * 
     * Unique ID can achieved with static variable 
     * https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s09.html
     */
    static int m_uniqueCourseID;
    int m_courseID;
    string m_courseName;
    int m_courseLoad;
};

#endif
