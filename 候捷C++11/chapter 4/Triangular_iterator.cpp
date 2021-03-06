/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
class Triangular_iterator
{
public:
    Triangular_iterator( int index ) : _index( index-1 ){} //***

    bool operator==( const Triangular_iterator& ) const;
    bool operator!=( const Triangular_iterator& ) const;
    int  operator*() const;
    Triangular_iterator& operator++();       // prefix version
    Triangular_iterator  operator++( int );  // postfix version

private:
    void check_integrity() const;  
    int _index;
};

inline Triangular_iterator& Triangular_iterator::
operator++()
{   // prefix instance
    ++_index;
    check_integrity();
    return *this; 
}

inline Triangular_iterator Triangular_iterator::
operator++( int )
{   // postfix instance
   
	Triangular_iterator tmp = *this;
	++_index; 
	check_integrity();   
    return tmp; 
}

inline void Triangular_iterator::
check_integrity() const
{
    // we�ll look at the throw expression in Chapter 7 ...
    if ( _index > Triangular::_max_elems )
         throw iterator_overflow();

    // grow vector if necessary ...
    if ( _index > Triangular::_elems.size() )
         Triangular::gen_elements( _index );
}




