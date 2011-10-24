#include <typeinfo>
using namespace std;

enum handleType {htTerminal, htNonTerminal};

class Handle{
	private:
		string handleName;
		string handleDesc;
		handleType type;
	protected:
		void setType(handleType hType);
	public:
		void setHandleName(string value);
		void setHandleDesc(string value);		
		string getHandleName();
		string getHandleDesc();
		handleType getType();
		virtual void setUpHandle()=0;
};

class HandleList{
	private:
		std::list<Handle*> list;	
		std::list<Handle*>::iterator it;
	public:
		void addHandle(Handle *value);
		void nextHandle();
		void priorHandle();
		void first();
		void last();
		bool eof();
		Handle* getHandle();
		std::list<Handle*>::iterator getIterator();
};

class TerminalHandle: public Handle{
	private:
		Token *token;
	public:
		TerminalHandle(Token *tokenValue);
		void setUpHandle();	
		Token* getToken();	
};

class NonTerminalHandle: public Handle{
	private:
		HandleList list;
		HandleList otherList;
		string production;
		bool allowEmpty;
	protected:
		virtual void InnerSetup();
	public:
		void setProduction(string value);
		string getProduction();
		void setAllowEmpty(bool value);
		bool getAllowEmpty();
		HandleList* getList();		
		HandleList* getOtherList();
		virtual void createHandleList()=0;
		void setUpHandle();
};

class HandleFactory {
	public:
		Handle* getTerminalHandle(string handleName, tokenType tkType, string tkLexema);
};

class Gramatica{
	private:
		HandleList list;
		bool loaded;
		Handle * simboloInicial;
		//static Gramatica *instance;
		//Gramatica();
	public:		
		//Gramatica getInstance();
		Gramatica();
		void setUp();
		void registerHandle(Handle *handle);
		void setSimboloInicial(Handle* sI);
		Handle* findHandle(string name);
		Handle* getSimboloInicial();
		HandleList* getHandleList();		
		void printHandleList();
};

Handle* HandleFactory::getTerminalHandle(string handleName, tokenType tkType, string tkLexema){
	TerminalHandle *thandle;
	TokenFactory tkFactory;			
	thandle = new TerminalHandle(tkFactory.getToken(tkType, tkLexema, 0, 0));
	thandle->setHandleName(handleName);
	return thandle;		
}

handleType Handle::getType(){
	return this->type;
}

void Handle::setType(handleType hType){
	this->type = hType;
}

void Handle::setHandleName(string value){
	this->handleName = value;
}

void Handle::setHandleDesc(string value){
	this->handleDesc = value;
}

string Handle::getHandleName(){
	return this->handleName;
}

string Handle::getHandleDesc(){
	return this->handleDesc;
}

Gramatica::Gramatica(){
	this->loaded = false;
	
	//this->simboloInicial = new BooleanConstant();
	//this->simboloInicial->setUpHandle();
}

void Gramatica::setSimboloInicial(Handle* sI){
	this->simboloInicial = sI;
}

Handle* Gramatica::getSimboloInicial(){
	return this->simboloInicial;
}

void Gramatica::setUp(){
	this->list.first();
	while(!this->list.eof()){		
		this->list.getHandle()->setUpHandle();		
		this->list.nextHandle();
	}
}

HandleList* Gramatica::getHandleList(){
	return &this->list;
}

void Gramatica::printHandleList(){	
	/*
	this->list.first();
	while(!this->list.eof()){		
		cout << this->list.getHandle()->getHandleName() <<endl;		
		this->list.nextHandle();
	}
	*/	
	this->getHandleList()->first();
	while(!this->getHandleList()->eof()){
		cout << this->getHandleList()->getHandle()->getHandleName() <<endl;		
		this->getHandleList()->nextHandle();
	}
}

void Gramatica::registerHandle(Handle *handle){
	this->list.addHandle(handle);
}

void HandleList::first(){
	this->it = this->list.begin();
}

void HandleList::last(){
	this->it = this->list.end();
	this->it--;
}

void HandleList::nextHandle(){
	if (!this->eof()){
		this->it++;
	}
}

void HandleList::priorHandle(){
	if (this->it != this->list.begin()){
		this->it--;
	}	
}

bool HandleList::eof(){	
	return this->it==this->list.end();
}

void HandleList::addHandle(Handle *value){
	this->list.push_back(value);
}

std::list<Handle*>::iterator HandleList::getIterator(){
	return this->it;
}

Handle* HandleList::getHandle(){
	std::list<Handle*>::iterator elem;
	
	elem = this->it;
	
	return *elem;		
}

void NonTerminalHandle::InnerSetup(){	
}

void NonTerminalHandle::setAllowEmpty(bool value){
	this->allowEmpty = value;
}

bool NonTerminalHandle::getAllowEmpty(){
	return this->allowEmpty;
}

void NonTerminalHandle::setProduction(string value){
	this->production = value;
}

HandleList* NonTerminalHandle::getList(){
	return &this->list;
}

HandleList* NonTerminalHandle::getOtherList(){
	return &this->otherList;
}

string NonTerminalHandle::getProduction(){
	return this->production;
}

void NonTerminalHandle::setUpHandle(){
	this->setAllowEmpty(false);
	this->setType(htNonTerminal);
	this->InnerSetup();
	this->createHandleList();	
	
	this->getOtherList()->first();
	while(!this->getOtherList()->eof()){
		this->getOtherList()->getHandle()->setUpHandle();
		this->getOtherList()->nextHandle();
	}
}

TerminalHandle::TerminalHandle(Token *tokenValue){
	this->token = tokenValue;
}

Token* TerminalHandle::getToken(){
	return this->token;
}

void TerminalHandle::setUpHandle(){
	this->setType(htTerminal);
}
