#ifndef __SETLINKLIST__H_
#define __SETLINKLIST__H_

#include "../List/linkList.h" 

template<typename T>
class SetLinkList : public List<T> {
private:
	List<T> *list;
public:
	SetLinkList();
	~SetLinkList();
	void add( T element );
	void remove( T element );
	bool contain( T element );
	int size();
	bool isEmpty();
};

template<typename T>
SetLinkList<T>::SetLinkList() {
	list = new List<T>();
}

template<typename T>
SetLinkList<T>::~SetLinkList() {
	list->~List();
	//delete list;
}

template<typename T>
bool SetLinkList<T>::isEmpty() {
	return list->IsEmpty();
}

template<typename T>
bool SetLinkList<T>::contain( T element ) {
	return list->Contain( element );
}

template<typename T>
int SetLinkList<T>::size() {
	return list->Size();
}

template<typename T>
void SetLinkList<T>::remove( T element ) {
	int index = list->Find( element );
	if( index != -1 )
		list->remove( index );
	else throw exception( "index error" );
}

template<typename T>
void SetLinkList<T>::add( T element ) {
	if( !list->Contain( element ) )
		list->InsertFront( element );
}

#endif