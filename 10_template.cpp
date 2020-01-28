/*
 * mostly used with STL
 * 
 */

//template class
template<typename T> class Guma
{
private:
  int size;
  T* array;
public:
  const int default_size = 10;
  Guma( int  _size = default_size)
    {  size = _size; array = new T[size]; };
  ~Guma() { delete array; }
  T& operator[] (int n);
};


//template function

//template struct



int main(){

  Guma<int> ip(5);
  ip[3] = 999;

  return 0;
}