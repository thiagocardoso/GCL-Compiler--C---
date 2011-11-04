#include <map>
#include <list>
using namespace std;

class Identificador{
};

class ListaIdentificadores{
	private:
		std::list<Identificador*> lista;
		std::list<Identificador*>::iterator it;	
};

class AnalisadorSemantico{
	private:
		Node* arvore;
		std::map<int, ListaIdentificadores*> varList; //int = escopo -> Escopo x Lista
		std::map<int, ListaIdentificadores*> procList;// ^^ 
		int escopoAtual;
	protected:
		void validarNo(Node* actualNode);
		void Erro(string message);
		void adicionarEscopo();
		void removerEscopo();	
		void criarListas();
	public:
		AnalisadorSemantico(Node* arvoreSintatica);
		void Executar();
};

AnalisadorSemantico::AnalisadorSemantico(Node* arvoreSintatica){
	this->arvore = arvoreSintatica;
	this->escopoAtual = 0;
	
	this->criarListas();
}

void AnalisadorSemantico::Executar(){
     this->validarNo(this->arvore);
}

void AnalisadorSemantico::validarNo(Node* actualNode){
	bool novoEscopo = false;
	
	switch(actualNode->getHandle()->getType()){
		case htNonTerminal:{		
			novoEscopo = (actualNode->getHandle()->getHandleName()=="module")||(actualNode->getHandle()->getHandleName()=="procedureDef");
			
			if(novoEscopo){
				this->adicionarEscopo();
			}
			
			actualNode->firstChild();
			while(!actualNode->eof()){
				this->validarNo(actualNode->getChild());
				
				actualNode->nextChild();
			}
			
			if(novoEscopo){
				this->removerEscopo();
			}
			
			break;
		}
		case htTerminal:{
			break;
		}
	}	
}

void AnalisadorSemantico::criarListas(){
	this->varList[this->escopoAtual] = new ListaIdentificadores();
	this->procList[this->escopoAtual] = new ListaIdentificadores();
}

void AnalisadorSemantico::adicionarEscopo(){
	this->escopoAtual++;
	this->criarListas();
}

void AnalisadorSemantico::removerEscopo(){
	if (this->escopoAtual>0){		
		this->varList.erase(this->escopoAtual);
		this->procList.erase(this->escopoAtual);
		this->escopoAtual--;
	}
}

void AnalisadorSemantico::Erro(string message){
}
