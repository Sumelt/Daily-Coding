#include "complex.h"
#include <iostream>

//using namespace std;

int main(int argc, char *argv[])
{
	//complex a(1, 2);
	//complex b(3, 4);
	//a += b += a;
	//cout << conj(a);
	//<< conj(a);
	return 0;
}

inline complex& __doapl (complex* ths, const complex& r)
{
	ths->re +=r.re;
	ths->im +=r.im;
	return *ths;
}

inline complex& complex::operator +=(const complex& r)
{
	return __doapl(this, r);
}


A& A::getInstance()
{
	static A a;
	return a;
}

inline double image(const complex& r)
{
	return r.imag();
}

inline double real(const complex& r)
{
	return r.real();
}

inline complex conj(const complex& r)
{
	return complex(real(r), -image(r));
}
ostream& operator << (ostream& os, const complex& r)
{
	return os << '(' << real(r) << ',' << image(r) << ')';
}








