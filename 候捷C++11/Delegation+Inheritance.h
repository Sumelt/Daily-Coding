#include<vector>
using namespace std;
class Observe;
class Subject;

class Observe{
	public:
		virtual void update(Subject* sub, int value) = 0;
};

class Subject {
	int m_value;
	vector<Observe*> m_views;
	public:
		void attach(Observe* obs){
			m_views.push_back(obs);
		}
		void set_val(int value){
			m_value = value;
			notify();
		}
		void notify(){
			for(int i = 0; i<m_views.size(); i++)
				m_views[i]->update(this, m_value);
		}
};







