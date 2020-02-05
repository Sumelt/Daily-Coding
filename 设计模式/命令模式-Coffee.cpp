/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Ligth {
private:
	bool status = false;
public:
	void on() {
		status = true;
		cout << "ligth is on" << endl;
	}
	void off() {
		status = false;
		cout << "ligth is off" << endl;
	}
};
//抽象基类：命令接口 
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class NoCommand : public Command {
public:
	void execute(){}
	void undo(){}	
};
//实例化的命令接口：开 
class LightOnCommand : public Command {
private:
	Ligth m_ligth;
public:
	LightOnCommand( Ligth ligth ) : m_ligth( ligth ) {}
	void execute() {
		m_ligth.on();
	}
	void undo() {
		m_ligth.off();
	}
};

//实例化的命令接口：关 
class LightOffCommand : public Command {
private:
	Ligth m_ligth;
public:
	LightOffCommand( Ligth ligth ) : m_ligth( ligth ) {}
	void execute() {
		m_ligth.off();
	}
	void undo() {
		m_ligth.on();
	}
};
//遥控器 
class RemoteControl {
private:
	Command *m_Oncommand[ 7 ];
	Command *m_Offcommand[ 7 ];
	Command *m_pre_command;
public:
	RemoteControl() {
		Command *nocommand = new NoCommand();
		fill( m_Oncommand, m_Oncommand + 7, nocommand );
		fill( m_Offcommand, m_Offcommand + 7, nocommand );
	}
	~RemoteControl() {
		delete m_Oncommand[ 0 ];
	}
	//插入命令 
	void setCommand( int index, Command* onCommand, Command* offCommand ) {
		m_Oncommand[ index ] = onCommand;
		m_Offcommand[ index ] = offCommand;
	}
	//命令启动 
	void onButtonWasPressed( const int index ) {
		m_Oncommand[ index ]->execute();
		m_pre_command = m_Oncommand[ index ];
	}
	
	void offButtonWasPressed( const int index ) {
		m_Offcommand[ index ]->execute();
		m_pre_command = m_Offcommand[ index ];
	}
	void undoButtonWasPressed() {
		m_pre_command->undo();
	}
};

int main(int argc, char *argv[])
{
	Ligth ligth;
	RemoteControl *contrcl = new RemoteControl();
	LightOnCommand *ligthoncommand = new LightOnCommand( ligth );
	LightOffCommand *ligthoffcommand = new LightOffCommand( ligth );
	contrcl->setCommand( 0, ligthoncommand, ligthoffcommand );
	contrcl->onButtonWasPressed( 0 );
	contrcl->undoButtonWasPressed();
	
	return 0;
}