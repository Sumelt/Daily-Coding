/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

class LibMat
{
	public:
		LibMat(){
			cout<<"LibMat constructor !"<<endl;
			cout <<"--->void" <<endl;
		}
	virtual ~LibMat(){
			cout<<"LibMat destructor !"<<endl;
		}
	virtual print(){
			cout<<"LibMat::print() !"<<endl;
		}	
		
	//protected:
};

class Book : public LibMat
{
	public:
		Book( const string &title, const string &author )
		: _title( title ), _author( author ){
			cout<<"Book constructor !"<<endl;
			cout <<"--->" <<_title <<_author <<endl;
		}
	virtual	~Book(){
			cout<<"Book destructor !"<<endl;	
		}
	virtual print(){
			cout<<"Book::print() !"<<endl;
		}
	const string title() const { return _title; }
	const string author() const { return _author; }
	
	protected:
		string _title;
		string _author;	
};

class AudioBook : public Book
{
	public:
		AudioBook( const string &title, const string &author,
		 const string &narrator)
			: Book( title, author ), _narrator( narrator ){
				cout <<"AudioBook constructor !" <<endl;
				cout <<"--->" <<_title <<_author <<_narrator <<endl;
		}
	virtual ~AudioBook(){
		cout <<"AudioBook destructor !" <<endl;
	}
	virtual print(){
		cout <<"AudioBook::print() !" <<endl;
	}
	const string narrator() const { return _narrator; }
	
	protected:
		string _narrator;
		
};

class Magazine : public LibMat 
{		
	public:
		Magazine( const string &title, const string &author )
		: _title( title ), _author( author ){
			cout<<"Magazine constructor !"<<endl;
			cout <<"--->" <<_title <<_author <<endl;
		}
	virtual	~Magazine(){
			cout<<"Magazine destructor !"<<endl;	
		}
	virtual print(){
			cout<<"Magazine::print() !"<<endl;
		}
	const string title() const { return _title; }
	const string author() const { return _author; }
	
	protected:
		string _title;
		string _author;	
		
};

void PrintMessage(LibMat &mat)
{
	cout<<"void PrintMessage()-> mat::print() !"<<endl;
	mat.print();
}

int main(int argc, char *argv[])
{
	//LibMat tmp;
	Magazine tmp( "Essentail C++", " Hou Jie" );
	//AudioBook tmp( "Essentail C++", " Hou Jie", " Melt" );
	PrintMessage(tmp);
	
	return 0;
}




