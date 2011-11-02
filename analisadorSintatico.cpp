#include <string.h>
#include <list>
#include "analisadorLexico.cpp"
//#include "producao.cpp"
#include "syntaxHandles.cpp"
#include "syntaxHandlesImpl.cpp"
#include "node.cpp"
using namespace std;

class ArvoreSintaticaAbstrata {
};

class AnalisadorSintatico {
	private:
		Gramatica grammar;
		//ArvoreSintaticaAbstrata arvore;
		AnalisadorLexico *anaLexico;
		Handle * actualHandle;
		Token * actualToken;
		bool accept;
		bool error;
		std::list<Token*> pilhaToken;
		Node* rootNode;		
		void setUpGrammar();
	protected:
		bool ValidaHandle(Handle * handle, Node* parentNode);
		void printNodes(Node* actual, int nivel);
	public:
		AnalisadorSintatico(string caminhoArquivo);
		~AnalisadorSintatico();
		Node* getArvoreSintatica();
		void GeraArvoreSintatica();
		void ListaHandles();
		bool ValidaProducoes();
		void Erro(string Message);
		void printArvoreSintatica();		
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
	//this->grammar.setSimboloInicial(new IndexOrComp());
	this->grammar.setSimboloInicial(new Program());
	this->grammar.getSimboloInicial()->setUpHandle();
}

Node* AnalisadorSintatico::getArvoreSintatica(){
	return rootNode;
}

void AnalisadorSintatico::printNodes(Node* actual, int nivel){
	int i;
	bool bloco = false;

	if(actual!=NULL){
		for(i=0;i<nivel;i++){
			cout << " | ";
		}
		cout << " Handle: \"" << actual->getHandle()->getHandleName()<< "\" ";
		
		if (actual->getToken()!=NULL){
			cout << "Token: \"" << actual->getToken()->getLexema() << "\" ";
		}	
		
		cout <<endl;
		
		actual->firstChild();
		while(!actual->eof()){
			bloco = true;
			printNodes(actual->getChild(), nivel+1);
			
			actual->nextChild();
		}
		
		if(bloco){
			for(i=0;i<nivel;i++){
			cout << " | ";
			}
			
			cout << " |_____________" <<endl;
		}
	}
}

void AnalisadorSintatico::printArvoreSintatica(){
	this->printNodes(this->rootNode,0);
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

bool AnalisadorSintatico::ValidaHandle(Handle * handle, Node* parentNode){
	bool result = true;
	NonTerminalHandle *ntHandle;
	TerminalHandle *tHandle;
	Node* newNode = new Node(handle);	
	
	handle->setUpHandle();
		
	if(handle->getType()==htNonTerminal){		
		//cout << "Entrou não terminal: " << handle->getHandleName() <<endl;
		
		ntHandle = (NonTerminalHandle*)handle;
		ntHandle->getList()->first();
		while((!ntHandle->getList()->eof())&&(result)){
			result = ValidaHandle(ntHandle->getList()->getHandle(), newNode);		
			
			ntHandle->getList()->nextHandle();
		}
		
		if (!result){
			ntHandle->getOtherList()->first();
			while((!ntHandle->getOtherList()->eof())&&(!result)){
				result = ValidaHandle(ntHandle->getOtherList()->getHandle(), newNode);
				
				ntHandle->getOtherList()->nextHandle();
			}
		}
		
		if (!result){			
			result = ntHandle->getAllowEmpty();						
		}		
	}else{
		if (this->actualToken!=NULL){		
			//cout << "Entrou terminal: " << this->actualToken->getLexema() << " Teste: " << handle->getHandleName() <<endl;			
			tHandle = (TerminalHandle*)handle;
			
			switch (tHandle->getToken()->getTipo()){
				case ttNumber:
				case ttId:{
					result = tHandle->getToken()->getTipo()==this->actualToken->getTipo();
					break;
				}
				case ttKeyword:
				case ttSymbol:{
					result = tHandle->getToken()->getLexema()==this->actualToken->getLexema();
					break;
				}			
			}
			
			newNode->setToken(this->actualToken);
		}else{
			result = false;
		}		
	}	
	
	if (result){
		this->pilhaToken.push_front(this->actualToken);			
				
		newNode->setParentNode(parentNode);			
		parentNode->insertChild(newNode);					
		
		if(handle->getType()==htTerminal){
//          if((!this->anaLexico->SourceEOF())||(!this->anaLexico->bufferEOF())){
             this->actualToken = this->anaLexico->getToken();							
//          }
        }
		
		//cout << "Reconheceu handle: " << handle->getHandleName() <<endl;
	}else{
		Erro("Não reconheceu handle: " + handle->getHandleName());
		//cout << "Não reconheceu handle: " << handle->getHandleName() <<endl;
	}
	
	return result;
}

bool AnalisadorSintatico::ValidaProducoes(){
	bool result = true;			
	this->rootNode = new Node(this->grammar.getSimboloInicial());	
		
	this->accept = true;
	this->actualToken = this->anaLexico->getToken();	
//	while(((!this->anaLexico->SourceEOF())||(this->actualToken!=NULL))&&(result)){
		//cout << "----------------------------------entrou na validacao" <<endl;
		//if(this->actualToken!=NULL){
			result = this->ValidaHandle(this->grammar.getSimboloInicial(), this->rootNode);						
		//}else{
		//	cout << "---------------------------------->TOKEN NULL"<<endl;
		//}
//	}
	
	this->accept = (this->anaLexico->SourceEOF()) && result;	
	return this->accept;
}

void AnalisadorSintatico::Erro(string Message){
}
