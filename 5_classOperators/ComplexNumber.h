
class ComplexNumber{
  public:
    //implicit parameters has to be only in file (one function header) - usually in header file
    ComplexNumber( int re = 0, int im = 0 );

    /*
    * Copy constructor
    * Is when during creation of a new instance
    * By default copy only default data types
    * Has to implement for non-default types, stucts and classes
    * Copy const is alwayes called when:
    * MyClass a
    * m(b)
    * x = a
    * because the instance hasnt been created yet
    */
    ComplexNumber( const ComplexNumber &x );

    /* 
    * Operator =
    * has to return reference, otherwise it would be calling itself in a loop
    * same functionality just like copy const + delete[]
    * return a class
    * return *this (goes for += etc)
    * in op= is also called copy const
    */
    ComplexNumber& operator= ( const ComplexNumber & );

    /*
    * Operator+
    * use overload op+ inside overload op+=
    * after a change in op+, op+= will also change
    */
    ComplexNumber operator+ ( const ComplexNumber & );

    //operator-
    ComplexNumber operator- ( const ComplexNumber & );

    //operator += and -=
    ComplexNumber& operator+= ( const ComplexNumber & );
    ComplexNumber& operator-= ( const ComplexNumber & );

    //operator*
    //operator can be to do really anything
    ComplexNumber& operator* ();
    ComplexNumber& operator* ( int );

    //custom print function
    void print();

  private:
    //two implicit parameters "kind of" simular to implicit constructor
    //ComplexNumber();
    int re;
    int im;
};