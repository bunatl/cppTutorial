#include "University.h"

//commond liberaries
#include <iostream>

//univesity libs
#include <bits/stdc++.h>

//faculty libraries
#include <algorithm> //std::find

using namespace std;

University::University( const string &x ){
    this->m_universityName = x;
    this->m_universityNumberOfPeople = 0;
}

University& University::operator= ( const University & x ){
    copyClassVariables( x );    
    return *this;
}

bool University::addPerson( Person *x ){
    this->m_personList.insert( this->m_personList.begin(), x );
    this->m_universityNumberOfPeople = getNumberOfPeople();
    return true;
}

bool University::deletePerson( Person *x ){
    //Erase from set by key
    this->m_personList.erase( x );
 
    this->m_universityNumberOfPeople = getNumberOfPeople();
    return true;
}

void University::info() const{
    cout << "Name of university is: " << this->m_universityName << endl;
    cout << "List of total " << this->m_universityNumberOfPeople << " people: ";
    //range-based for loop C++11 approach
    
    for ( Person* person : this->m_personList ){
        cout << person->getPersonID() << endl;
        //here we will have to iterate through person courses
        //for ( string course : p)
        //    cout << course->getCourseName() << endl;
    }
    cout << endl << endl;
}

void University::copyClassVariables( const University &x ){
    //STL containers delete old array and copy new, if object are static
    this->m_personList = x.m_personList;
    this->m_universityName = x.m_universityName;
    this->m_universityNumberOfPeople = x.m_universityNumberOfPeople;
}


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


Faculty::Faculty( const string &x ){
    this->m_numberOfCourses = 0;
    this->m_facultyName = x;
}

Faculty::Faculty ( const Faculty & x ) : University(){
    Faculty::copyClassVariables( x );
    University::copyClassVariables( x );
}

Faculty& Faculty::operator= ( const Faculty & x ){
    Faculty::copyClassVariables( x );
    University::copyClassVariables( x );
    return *this;
}

Faculty Faculty::operator+ ( Course *x ){
    this->m_coursesList.insert( this->m_coursesList.end(), x );
    this->m_numberOfCourses++;
    return *this;
}

Faculty Faculty::operator- ( const Course *x ){
    /*
     * Correct way to erase from a vector is as descrobed here:
     * https://stackoverflow.com/questions/16219027/vector-erase-error
     * 
     * Erase() takes an iterator as parameter
     * std::vector<int>::iterator it = std::find(vector.begin(), vector.end(), value);
     * 
     * Line above is in c++11 equal to:
     * auto it = std::find(vector.begin(), vector.end(), value);
     * vector.erase(it);
     * vector<Course>::iterator can be substitized for auto
     * 
     * if we don't use find, we would have iterated through whole vector
    */
    vector<Course *>::iterator it = find( this->m_coursesList.begin(), this->m_coursesList.end(), x );
    this->m_coursesList.erase( it );

    this->m_numberOfCourses--;
    return *this;
}

//info() is a virtual function
void Faculty::info() const {
    cout << "Courses taught at " << this->m_facultyName <<  " faculty are: ";
    if ( this->m_coursesList.size() == 0 )
        cout << "None.";
    else 
        for ( Course *c : this->m_coursesList )
            cout << c->getCourseName() << ", ";
    cout << endl << endl;
}

void Faculty::copyClassVariables( const Faculty &x ){
    this->m_numberOfCourses = x.m_numberOfCourses;
    this->m_facultyName = x.m_facultyName;
}
