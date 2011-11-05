#include <list>
#include <string>
using namespace std;

enum IdentType {itVar, itProc, itTypeDef};
enum VarType {vtInteger, vtBoolean, vtReal, vtString, vtTypeDef};

class Identificador {
	private:
		IdentType type;
		Token* token;
		string name;
	protected:
		void setType(IdentType value);
		void setToken(Token* value);
		void setName(string value);
	public:
		Token* getToken();
		IdentType getType();
		string getName();
};

class ProcIdent:public Identificador {
	public:
		ProcIdent(Token* token);
};

class TypeIdent: public Identificador {
	private:
		TypeIdent* baseType; 
		int rangeMin;
		int rangeMax;
		bool rangeDefined;
	protected:
		void setRangeDefined();
	public:
		TypeIdent(Token* token, TypeIdent* tipoBase);
		void setRangeMin(int value);
		void setRangeMax(int value);
		int getRangeMin();
		int getRangeMax();
		bool isValidInRange(int value);
		bool isRangeDefined();
		bool hasBaseType();
		TypeIdent* getBaseType();
};

class VarIdent:public Identificador {
	private:
		VarType tipoVariavel;
		TypeIdent* type;
	public:
		VarIdent(Token* token, VarType tipoVar, TypeIdent* type);
		VarType getTipoVariavel();
};

class ListaIdentificadores {
	private:
		std::list<Identificador*> lista;
		std::list<Identificador*>::iterator it;
	public:
        ListaIdentificadores();
		void addVar(Token* token, VarType tipoVar, TypeIdent* type);
		void addProc(Token* token);
		void addType(Token* token, TypeIdent* baseType);
		void next();
		void prior();		
		void first();
		void last();		
		bool isEmpty();
		bool eof();
		bool exists(string identName);
		Identificador* getIdentificador();
		Identificador* getIdentByName(string identName);
};

void Identificador::setType(IdentType value){
	this->type = value;
}

void Identificador::setToken(Token* value){
	this->token = value;
}

Token* Identificador::getToken(){
	return this->token;
}	
	
IdentType Identificador::getType(){
	return this->type;
}

void Identificador::setName(string value){
	this->name = value;
}

string Identificador::getName(){
	return this->name;
}

ProcIdent::ProcIdent(Token* token){
	this->setToken(token);
	this->setType(itProc);
	this->setName(token->getLexema());
	
	cout << "Adicionou procedimento: " << this->getName() << "." <<endl;	
}

TypeIdent::TypeIdent(Token* token, TypeIdent* tipoBase){
	this->setToken(token);
	this->setType(itTypeDef);
	this->setName(token->getLexema());
	this->baseType = tipoBase;
	this->rangeMin = 0;
	this->rangeMax = 0;
	this->rangeDefined = false;
	
	cout << "Adicionou tipo: " << this->getName() << "." <<endl;
}

bool TypeIdent::hasBaseType(){
	return this->baseType!=NULL;
}

void TypeIdent::setRangeDefined(){
	this->rangeDefined = (this->rangeMin==0)&&(this->rangeMax==0);
}

void TypeIdent::setRangeMin(int value){
	this->rangeMin = value;
	this->setRangeDefined();
}

void TypeIdent::setRangeMax(int value){
	this->rangeMax = value;
	this->setRangeDefined();
}

int TypeIdent::getRangeMin(){
	return this->rangeMin;
}

int TypeIdent::getRangeMax(){
	return this->rangeMax;
}

bool TypeIdent::isValidInRange(int value){
	return (value >= this->rangeMin)&&(value <= this->rangeMax);
}

bool TypeIdent::isRangeDefined(){
	return this->rangeDefined;
}

VarIdent::VarIdent(Token* token, VarType tipoVar, TypeIdent* type){
	this->setToken(token);
	this->setType(itVar);
	this->setName(token->getLexema());
	this->tipoVariavel = tipoVar;
	this->type = type;
	
	cout << "Adicionou variavel: " << this->getName() << "." <<endl;	
}

VarType VarIdent::getTipoVariavel(){
	return this->tipoVariavel;
}

ListaIdentificadores::ListaIdentificadores(){
    this->it = this->lista.begin();
}

void ListaIdentificadores::addVar(Token* token, VarType tipoVar, TypeIdent* type){
	this->lista.push_back(new VarIdent(token, tipoVar, type));	
}

void ListaIdentificadores::addProc(Token* token){
	this->lista.push_back(new ProcIdent(token));
}

void ListaIdentificadores::addType(Token* token, TypeIdent* baseType){
	this->lista.push_back(new TypeIdent(token, baseType));
}

void ListaIdentificadores::next(){
	this->it++;
}

void ListaIdentificadores::prior(){
	this->it--;
}

void ListaIdentificadores::first(){
	this->it = this->lista.begin();
}

void ListaIdentificadores::last(){
	this->it = this->lista.end();
}

bool ListaIdentificadores::isEmpty(){
}

bool ListaIdentificadores::eof(){
	return this->it==this->lista.end();
}

Identificador* ListaIdentificadores::getIdentificador(){
	std::list<Identificador*>::iterator elem;

	elem = this->it;

	return *elem;	
}

bool ListaIdentificadores::exists(string identName){
	bool result = false;
	
	this->first();
	while((!this->eof())&&(!result)){
		result = this->getIdentificador()->getName()==identName;
		
		if(!result){
			this->next();
		}
	}
	
	return result;
}

Identificador* ListaIdentificadores::getIdentByName(string identName){
	if(this->exists(identName)){
		return this->getIdentificador();
	}else{
		return NULL;
	}
}
