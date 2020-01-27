#ifndef PERSON_H
#define PERSON_H
/*
 * #include guards.
 * Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.
 * When the code is included again, the first ifndef fails, resulting in a blank file. That prevents double declaration of any identifiers such as types, enums and static variables. 

 * https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
 */

#include <string>
#include <utility> //std::pair

/*
 * using namespace std;
 * shoudln't be used because it would has to be included everywhere
 */

using std::string;

/*
 * An abstract class is, conceptually, a class that cannot be instantiated and is usually implemented as a class that has one or more pure virtual (abstract) functions.
 * A pure virtual function is one which must be overridden by any concrete (i.e., non-abstract) derived class
 *  
 * abstract class because it has at least one pure virtual fucntion
 */
class Person{
  public:
    //superclass has to have a default constructor
    Person();
    //if age isn't set, by deafult will be 0, specified only in header file
    Person( const std::pair<string, string> &, const char & = '-', const int & = 0 );
    Person ( const Person & );
    ~Person() {};
    
    //operator= has to return reference, otherwise it would be calling itself in a loop (return *this)
    Person& operator= ( const Person & );
  
    //pure virtual function
    virtual void info() const = 0; 

    int getPersonID() const { return this->m_personID; };

    std::pair<string, string> getPersonName() const { return this->m_personName; };
    void setPersonFirstName( const string &firstName, const string &lastName ) { this->m_personName = std::make_pair( firstName, lastName ); };

    char getPersonGender() const { return this->m_personGender; };
    void setPersonGender( const char &x ) { this->m_personGender = x; };

    int getPersonAge() const { return this->m_personAge; };
    void setPersonAge( const int &x ) { this->m_personAge = x; };
    
  //class members are private by default
  private:
    
  //we want class variables to be accessable for derivated classes
  protected:  
    //cant be virtual because it will be called from derivated constructors
    void copyClassVariables( const Person & );
    
    /*
     * Person ID has to be unique
     * 
     * Unique ID can achieved with static variable 
     * https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s09.html
     */
    static int m_uniquePersonID;
    int m_personID;
    std::pair<string, string> m_personName;
    char m_personGender;
    int m_personAge;
};

#endif