#include <string>
#include <set>

class Message;

class Folder{

	friend void swap(Folder &, Folder &);
	friend class Message;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder& operator=(const Folder &);
    ~Folder();
	void reMsg( Message* msg ){ msgs.erase( msg ); }
	void addMeg( Message* msg ){ msgs.insert( msg ); }

private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder&);
    void remove_from_Message();
	

};
void swap(Folder &, Folder &);

class Message{
	friend class Folder;
	friend void swap( Message&, Message& );
public:
	explicit Message( const std::string &str = "" );
	Message ( const Message& );
	Message& operator=( const Message& );
	~Message();
	void save( Folder& );
	void remove( Folder& );
	
private:
	std::string  content;
	std::set< Folder* >folders;
	void add_to_Folder( const Message& );
	void remove_from_Folder();
	void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
	
};
void swap(Folder &, Folder &);



