#include <string.h>
#include <set>
#include "token.cpp"
#include "analisadorLexico.cpp"
#include "token.cpp"
using namespace std;

class TokenList {
	private:
		set<Token> list;
		set<Token>::iterator iter;
	public:
		void AddToken(Token *token);
		void NextToken();
		void PriorToken();
		void First();
		void Last();
};

class Production {
	private:
		TokenList listaToken;		
};

class ProductionList {
	private:
		set<Production> list;
		set<Production>::iterator iter;
	public
		void AddProduction(Production *production);
		ProductionList GetInstance();
}

// Implementações TokenList
void TokenList::AddToken(Token *token){
	this->list.insert(this->iter, token);
}

void TokenList::NextToken(){
	this->list.upper_bound();
}

void TokenList::PriorToken(){
}

void TokenList::First(){
}

void TokenList::Last(){
}

// Implementações ProductionList
void ProductionList::AddProduction(Production *production){
	this->list.insert(this->iter, production);
}
