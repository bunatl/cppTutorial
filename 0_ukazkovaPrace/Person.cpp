#include "Person.h"

#include <iostream>

using namespace std;

int Person::m_uniquePersonID = 0;

Person::Person(){
    pair<string, string> name = make_pair("", "");
    this->m_personName = name;
    this->m_personGender = '-';
    this->m_personAge = 0;
    this->m_personID = m_uniquePersonID++;
}

Person::Person( const pair<string, string> &name, const char &gender, const int &age ){
    this->m_personName = name;
    this->m_personGender = gender;
    this->m_personAge = age;
    this->m_personID = m_uniquePersonID++;
}

Person::Person ( const Person &x ){
    copyClassVariables( x );
}

Person& Person::operator= ( const Person &x ){
    copyClassVariables( x );

    return *this;
}

void Person::copyClassVariables( const Person &x ){
    this->m_personName = x.m_personName;
    this->m_personGender = x.m_personGender;
    this->m_personAge = x.m_personAge;
    this->m_personID = x.m_personID;
}