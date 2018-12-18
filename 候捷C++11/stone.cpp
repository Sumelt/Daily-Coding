/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: function template

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

class stone{
	public:
		stone(int w, int h, int we)
			: _w(w), _h(h), _we(we)
			{ }
		stone(){}
		bool operator < (const stone& rhs) const
		{return _we < rhs._we;}
		void print() const {
			cout << _w;
		} //test
	private:
		int _w, _h, _we;
};

template <class T>
inline const T& _min(const T& a, const T& b)
{
	return b < a ? b : a;
}

int main(int argc, char *argv[])
{
	stone r1(2, 3, 4), r2(4, 5, 6), r3;
	r3 = _min(r1, r2);
	r3.print();
	return 0;
}




