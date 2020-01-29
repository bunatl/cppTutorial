/*
 * Templates are used when it is wanted to use the exactly same code
 * just with different data type
 * 
 * Template is inicialized by adding template<typename T> infront of function, class...
 */

#include <set>

//template class
template<typename T> 
class AnySet {
  public:
    bool addElement( const T& x){
      //insert return a pair<iterator,bool>
      return this->mySet.insert( x ).second;
    }
    bool removeElement( const T& x ){
      if ( this->mySet.erase( x ) > 0 )
        return true;
      else
        return false;      
    }

  private:
    std::set<T> mySet;
};
 
//template function
template<typename T> 
T compareAnyType( T x, T y ){
  return x < y;
};

//template struct
template<typename T>
struct MyStruct
{
  T myVar;
};


int main(){

  AnySet<int> *i = new AnySet<int>();
  i->addElement( 5 );
  i->addElement( 10 );
  i->removeElement( 10 );
  delete i;

  AnySet<char> *ch = new AnySet<char>();
  ch->addElement( 'a' );
  ch->addElement( 'y' );
  ch->removeElement( 'a' );
  delete ch;

  MyStruct<int> s;
  s.myVar = 5;

  MyStruct<bool> s2;
  s.myVar = false;

  return 0;
}