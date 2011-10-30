#include <string.h>
#include <list>
using namespace std;

class ProductionElement{
};

class TerminalElement: public ProductionElement{
};

class NonTerminalElement: public ProductionElement{
};

class TokenList{
	private:
		std::list<ProductionElement*> list;	
		std::list<ProductionElement*>::iterator it;
	public:
		void AddElement(ProductionElement *element);
		void NextElement();
		void PriorElement();
		void First();
		void Last();
		bool Eof();
};

class Production{
	private:
		TokenList elementList;	
	protected:
		void SetupElementList();
	public:
		Production();
		~Production();
		TokenList getElementList();		
};

class ProductionList{
	private:
		//set<Production> list;
		//set<Production>::iterator iter;
	public:
		void AddProduction(Production *production);
		ProductionList GetInstance();
};

// Implementações TokenList
void TokenList:: AddElement(ProductionElement *element){
	this->list.push_back(element);
}

void TokenList::First(){
	this->it = this->list.begin();
}

void TokenList::Last(){
	this->it = this->list.end();
	this->it--;
}

void TokenList::NextElement(){
	if (this->it != this->list.end()){
		this->it++;
	}
}

void TokenList::PriorElement(){
	if (this->it != this->list.begin()){
		this->it--;
	}	
}

bool TokenList::Eof(){
	return this->it==this->list.end();
}

// Implementações Production

Production::Production(){
	this->SetupElementList();
}

Production::~Production(){	
}

TokenList Production::getElementList(){	
	return this->elementList;
}

void Production::SetupElementList(){
}

/*
// Implementações ProductionList
void ProductionList::AddProduction(Production *production){
	this->list.insert(this->iter, production);
}
*/
