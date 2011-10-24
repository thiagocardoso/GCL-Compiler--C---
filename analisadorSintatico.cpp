#include <string.h>
#include <list>
#include "analisadorLexico.cpp"
//#include "producao.cpp"
#include "syntaxHandles.cpp"
#include "syntaxHandlesImpl.cpp"
using namespace std;

class ArvoreSintaticaAbstrata {
};

class AnalisadorSintatico {
	private:
		Gramatica grammar;
		ArvoreSintaticaAbstrata arvore;
		AnalisadorLexico *anaLexico;
		Handle * actualHandle;
		Token * actualToken;
		bool accept;
		bool error;
		std::list<Token*> pilhaToken;
		
		void setUpGrammar();
	protected:
		bool ValidaHandle(Handle * handle);
	public:
		AnalisadorSintatico(string caminhoArquivo);
		~AnalisadorSintatico();
		ArvoreSintaticaAbstrata getArvoreSintatica();
		void GeraArvoreSintatica();
		void ListaHandles();
		bool ValidaProducoes();
		void Erro(string Message);
};

AnalisadorSintatico::AnalisadorSintatico(string caminhoArquivo){	
	this->anaLexico = new AnalisadorLexico(caminhoArquivo);	
	this->setUpGrammar();
	this->accept = false;
	this->error = false;
}

AnalisadorSintatico::~AnalisadorSintatico(){	
}

void AnalisadorSintatico::setUpGrammar(){
	RegisterHandlesCommand com;	
	com.setGrammar(&this->grammar);
	com.Execute();	
	
	//this->grammar.setSimboloInicial(new BooleanConstant());
	//this->grammar.setSimboloInicial(new RelationalOperator());
	this->grammar.setSimboloInicial(new IndexOrComp());
	this->grammar.getSimboloInicial()->setUpHandle();
}

ArvoreSintaticaAbstrata AnalisadorSintatico::getArvoreSintatica(){
	return arvore;
}

void AnalisadorSintatico::GeraArvoreSintatica(){
	Token* myToken;	
	
	while (not(this->anaLexico->SourceEOF())){
		myToken = this->anaLexico->getToken();	
		if (myToken != NULL){
			cout <<endl;
			switch (myToken->getTipo()){
				case ttId:
					cout << "Identificador:";
					break;
				case ttNumber:
					cout << "Número:";
					break;
				case ttKeyword:
					cout << "Palavra Reservada:";
					break;
				case ttSymbol:
					cout << "Símbolo:";
					break;
				default: break;				
			}			
			cout << myToken->getLexema()<< " linha: "<< myToken->getLine() << " coluna:"<< myToken->getColumn() <<endl;
		}						
	}			
}

void AnalisadorSintatico::ListaHandles(){	
	this->grammar.setUp();	
	this->grammar.printHandleList();	
}

bool AnalisadorSintatico::ValidaHandle(Handle * handle){
	bool result = true;
	NonTerminalHandle *ntHandle;
	
	handle->setUpHandle();
		
	if(handle->getType()==htNonTerminal){		
		cout << "Entrou não terminal: " << handle->getHandleName() <<endl;
		
		ntHandle = (NonTerminalHandle*)handle;
		ntHandle->getList()->first();
		while((!ntHandle->getList()->eof())&&(result)){
			result = ValidaHandle(ntHandle->getList()->getHandle());		
			
			ntHandle->getList()->nextHandle();
		}
		
		if (!result){
			ntHandle->getOtherList()->first();
			while((!ntHandle->getOtherList()->eof())&&(!result)){
				result = ValidaHandle(ntHandle->getOtherList()->getHandle());
				
				ntHandle->getOtherList()->nextHandle();
			}
		}
		
		if (result){
			this->pilhaToken.push_front(this->actualToken);
			this->actualToken = this->anaLexico->getToken();
		}		
		else{		
			//if (!ntHandle->getAllowEmpty()){
			//	this->Erro("Token errado!");
			//	this->actualToken = this->anaLexico->getToken();
			//}
			if (ntHandle->getAllowEmpty()){
				result = true;
				this->actualToken = this->anaLexico->getToken();
			}
			//result = ntHandle->getAllowEmpty();
		}		
	}else{
		cout << "Entrou terminal: " << this->actualToken->getLexema() << " Teste: " << handle->getHandleName() <<endl;
		result = handle->getHandleName()==this->actualToken->getLexema();
	}	
	
	if (result){
		cout << "Reconheceu handle: " << handle->getHandleName() <<endl;
	}else{
		cout << "Não reconheceu handle: " << handle->getHandleName() <<endl;
	}
	
	return result;
}

bool AnalisadorSintatico::ValidaProducoes(){
	bool result = true;		
		
	this->accept = true;
	this->actualToken = this->anaLexico->getToken();	
	while(((!this->anaLexico->SourceEOF())||(this->actualToken!=NULL))&&(result)){
		cout << "----------------------------------entrou na validacao" <<endl;
		result = this->ValidaHandle(this->grammar.getSimboloInicial());	
		if(this->actualToken!=NULL){
			cout << "---------------------------------->" << this->actualToken->getLexema() <<endl;
		}else{
			cout << "---------------------------------->TOKEN NULL"<<endl;
		}
	}
	
	this->accept = (this->anaLexico->SourceEOF()) && result;	
	return this->accept;
}

void AnalisadorSintatico::Erro(string Message){
}
