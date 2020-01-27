/*
 * INFO
 * **********************
 * @Author: Lukas Bunat
 * @ID: 34 968
 * @Course: B_OOP
 * @Purpose: Semestral Work
 * @Compiler: C++11
 * @Created: March 2019
 */ 

/*
 * PROGRAMMING NOTES:
 * Constant methods are not allowed to edit variables. 
 * 
 */

/*
    Issues:
    * courses copy const not increasing course ID!??
*/

#include <iostream>

#include "University.h"
#include "Person.h"
#include "Student.h"
#include "Course.h"

using namespace std;

/*
 * Program description ...
 */
int main( ) {

    /*
     * ===================
     * +++++ TESTER ++++++
     * ===================
     */
    cout << endl;
    cout << "**************************************" << endl;
    cout << "******** DYNAMIC ALLOCATION **********" << endl;
    cout << "**************************************" << endl;
    cout << endl;
    cout << "============== COURSE ================" << endl << endl;

    //=========== COURSE ==================
    //default and parametric const called here
    Course *c1 = new Course();
    c1->info();
    c1->setCourseName( "OOP" );
    c1->setCourseLoad( 6 );
    c1->info();
    cout << "Course " << c1->getCourseID();
    cout << " has credit load " << c1->getCourseLoad();
    cout << " and has name " << c1->getCourseName() << endl;

    Course *c2 = new Course( "PrSt", 5 );
    c2->info();

    cout << "assinging c2 into c1" << endl;
    //copy const should be used here
    //can I do this with pointers? copy const??!!!!
    Course *tmp = c1;
    //op= is called here
    c1 = c2;
    c1->info();
       
    cout << "are c1 and c2 equal " << (c1==c2) << endl;
    cout << "returning old value to c1" << endl;
    c1 = tmp;
    cout << "are c1 and c2 equal " << (c1==c2) << endl;

    Course *c3 = new Course();
    c3 = c2;
    Course *c4 = new Course ("Course 4", 8 );
    c3->info();
    c4->info();
    //=========== END COURSE ===============

    cout << endl << endl << "=============== UNIVERSITY ==============" << endl << endl;

    //========== UNIVERSITY ===============
    
    University *u1 = new University();
    u1->info();
    u1->setUniversityName( "VSFS" );
    cout << u1->getUniversityName() << endl;

    /*
     * add & delete Person
     * has to be dynamiclly allocated
     */ 

    cout << u1->getNumberOfPeople() << endl;
    
    University *u2 = new University();
    //u2 = u1;
    //u2 = u3; 
    u2->info();
    u2 = u1;
    u2->info();

    University *u3 = u2;
    u3->info();
    
    //==========END UNIVERSITY ============

    cout << endl << endl << "============ FACULTY =============" << endl << endl;

    //=========== FACULTY =================
    
    Faculty *f1 = new Faculty();
    f1->info();
    f1->setFacultyName("IT");
    f1->info();

    Faculty *f2 = new Faculty("KIT");
    f2->getFacultyName();
    f2->info();

    //why this works - what that does mean??!
    //how to write code for just pointer
    *f2 + c2;
    *f2 + c3;
    *f2 + c4;

    cout << "Print courses" << endl;
    f2->info();

    *f2 - c2;
    f2->info();
    
    //========= END FACULTY ===============

    cout << endl << endl << "============ PERSON - STUDENT - STUFF ==============" << endl << endl;

    //========== PERSON - STUDENT - STUFF =================

    cout << "------------- Student --------------------" << endl;
    
    Student *s1 = new Student();
    s1->info();

    Student *s2 = new Student( make_pair("lukas", "bunat") );
    s2->info();

    Student *s3 = new Student( make_pair("john", "smith"), 'M' );
    s3->info();

    Student *s4 = new Student( make_pair("jenna", "williams"), 'F', 26 );
    s4->info();

    s1 = s2;
    s1->info();

    Student *s5 = new Student();
    s5 = s3;
    s5->info();

    Student *s6 = new Student();
    s6 = s4;
    s6->info();

    cout << "------------- Stuff --------------------" << endl;
    
    Stuff *st1 = new Stuff();
    st1->info();

    Stuff *st2 = new Stuff( make_pair("worker", "1"), 'M' );
    st2->info();

    Stuff *st3 = new Stuff( make_pair("cleaner", "126"), 'F', 30 );
    st3->info();

    st1 = st2;
    st1->info();

    Stuff *st4 = new Stuff();
    st4 = st2;
    st4->info();

    Stuff *st5 = new Stuff();
    st5 = st3;
    st5->info();


    cout << "------------- person --------------------" << endl;

    Person *p = new Student( make_pair("abc", "mol"), 'F', 22 );
    Person *p2 = new Student( make_pair("swaper", "007"), 'M', 30 );

    p->info();
    p2->info();

    u1->info();
    
    u1->addPerson( p );
    u1->addPerson( p2 );

    u1->info();

    p->info();
    p2->info();

    //==========END PERSON - STUDENT - STUFF =================
    return 0;
}
