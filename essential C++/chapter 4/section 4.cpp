/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
/*------------- Object-----------------*/

/*-------------Triangular Object-----------------*/
class Triangular{
	public:
		Triangular();
		Triangular( const Triangular& );
		Triangular( int len = 1, int beg_pos = 1 );
		int length() const { return _length; }
		int beg_pos()  const { return _beg_pos; }
		int elem( int pos ) const { return _elems[ pos -1 ]; }
		
		bool next( int &val ) const;
		void next_reset() const { _next = _beg_pos - 1; }
		
		typedef Triangular_iterator iterator;
		
	private:
		int _length;
		int _beg_pos;
		mutable int _next;
		static vector<int> _elems;
};
vector<int>Triangular::_elems; // define

Triangular::Triangular(const Triangular& rhs)
	: _length(rhs._length),  _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1)
{
	//void
	
}

Triangular::Triangular( int len,  int bp )
{
	_length = len > 0 ? len : 1;
	_beg_pos = bp > 0 ? bp : 1;
	_next = _beg_pos - 1;
}

bool Triangular::next( int &val ) const
{
	if( _next < _beg_pos + _length - 1 ){
		val = _elems[ _next++ ];
		return true;
	}
	return false;
}

int sum( const Triangular &trian )
{
	if( !trian.length() )
		return 0;
		
	int val, sum = 0;
	trian.next_reset();
	while( trian.next( val ) )
		sum += val;
	return sum;
}
/*--------------Triangular_iterator-------------------------------*/ 
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

/*-------------Matrix Object-----------------*/
class Matrix{
	public:
		Matrix( int row, int col )
			:_row( row ), _col( col )
		{
			_pmat = new double [ row * col ]; //apply memeory
		}
		~Matrix()
		{
			delete [] _pmat; // delete necessarily
		}
		Matrix(){ _pmat = new double [ 1 ]; }
		Matrix& operator =( const Matrix& ); //return Matrix&
		int print(){
			cout<< _col;
		}
		
	private:
		int _row, _col;
		double* _pmat; //overload = 
};

Matrix& Matrix::operator =( const Matrix& rhs )
{
	Matrix tp;
	if( this == &rhs ) return *this;
	_row = rhs._row;
	_col = rhs._col;
	
	delete [] _pmat;
	_pmat = new double[ rhs._row * rhs._col ];
	for( int ix = 0; ix < _row * _col; ix++ )
		_pmat[ ix ] = rhs._pmat[ ix ];
	
	return *this; // Matrix Matrix::operator =( Matrix *this, const Matrix& rhs)
}



/*----------------------------- main------------------------------------------*/
int main(int argc, char *argv[])
{
	
}




