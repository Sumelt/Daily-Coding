#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class cimplex;
class ostream;
class A;

//template<typename T>
class complex {
	
	double re, im;
	
	public:
		complex(double r = 0, double i = 0)
			: re(r), im(i)
		{}
		double real () const { return re; }
		double imag () const { return im; }
		complex& operator += (const complex&);
		
	friend complex& __doapl (complex*, const complex&);
};


class A{
	
	public:
		static A& getInstance();
		setup() {}
		
	private:
		A(){}
		//A(const A& rhs);
};

inline double real(const complex& r);
inline double image(const complex& r);
inline complex conj(const complex& r);
ostream& operator << (ostream& os, const complex&);


//A::getInstance().setup();
#endif

//complex() :re(0), im(0) { }
//complex(double r = 0, double i = 0) : re(r), im(i) { }

