#include "Course.h"

#include <iostream>

using namespace std;

/*
 * Outside class variable initialization
 * https://stackoverflow.com/questions/185844/how-to-initialize-private-static-members-in-c
 */
int Course::m_uniqueCourseID = 0;

Course::Course( const string &x, const int &n ){ 
    this->m_courseID = m_uniqueCourseID++;
    this->m_courseLoad = n;
    this->m_courseName = x;
}

Course& Course::operator= ( const Course &x ){
    copyClassVariables( x );
    return *this;
}

bool Course::operator== ( const Course *x ) const {    
    return ( this->m_courseID == x->m_courseID && this->m_courseLoad == x->m_courseLoad && this->m_courseName == x->m_courseName );
}

//operator< needs to be implemented because course is STL containers key
bool Course::operator< ( const Course *x ) const {
    return this->m_courseID > x->m_courseID;
}

void Course::info() const {
    cout << "Course " << this->m_courseName << " ( ID: " << this->m_courseID << " )";
    cout << " has workload " << this->m_courseLoad << " credits." << endl;
    cout << endl;
}

void Course::copyClassVariables( const Course &x ) {
    this->m_courseID = x.m_courseID;
    this->m_courseLoad = x.m_courseLoad;
    this->m_courseName = x.m_courseName;
}