/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Folder and Message.h"
using namespace std;

/****************Folder**************/
void swap(Folder &lhs, Folder &rhs) 
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.msgs, rhs.msgs);
    
    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder &f) 
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f) 
    : msgs(f.msgs) 
{ 
    add_to_Message(f); 
}



void Folder::remove_from_Message() 
{
    for (auto m : msgs)
        m->remFldr(this);
}

Folder::~Folder() 
{ 
    remove_from_Message(); 
}

Folder &Folder::operator=(const Folder &rhs) 
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}


/****************Message**************/
void swap( Message &lhs, Message &rhs )
{
	using std::swap;
	for( auto f : lhs.folders ) //lhs.remove_from_Folders();
		f->reMsg( &lhs );      
	for( auto f : rhs.folders ) //rhs.remove_from_Folders();
		f->reMsg( &rhs );
	swap( lhs.content, rhs.content );
	swap( lhs.folders, rhs.folders );
	for( auto f : lhs.folders ) //lhs.add_to_Folders(lhs); 
		f->addMeg( &lhs );
	for( auto f : rhs.folders ) //rhs.add_to_Folders(lhs); 
		f->addMeg( &rhs );
	
}

void Message::save( Folder &f )
{
	folders.insert( &f );
	f.addMeg( this );
}

void Message::remove( Folder &f )
{
	folders.erase( &f );
	f.reMsg( this );
}

void Message::add_to_Folder( const Message &m )
{
	for( auto f : m.folders )
		f->addMeg( this );
}

void Message::remove_from_Folder( void )
{
	for( auto f : folders )
		f->reMsg( this );
}

Message::Message( const Message& m )
	: content( m.content ), folders( m.folders )
{
	add_to_Folder( m );
}

Message::~Message()
{
	remove_from_Folder();
	//content free by string deconstruct fc
}

Message& Message::operator=( const Message &m )
{
	if( this == &m )
		return *this;
	remove_from_Folder();
	content = m.content;
	folders =  m.folders;
	add_to_Folder( m );
	return *this;
}

int main(int argc, char *argv[])
{

	return 0;
}




