#include "listaComandos.cpp"
#include "listaVariaveis.cpp"
using namespace std;

class Operador {
	private:
		string name;
	public:
		Operador(string name);
		string getName();
};

class VariavelTemp:public Variavel {
	public:
		VariavelTemp(string name);
};

class VariavelToken:public Variavel {
	private:
		Token* token;
	public:
		VariavelToken(Token* token);
};

class Atribuicao: public Comando {
	private:
		Variavel* cabeca;
		Variavel* direita1;
		Operador* operador;
		Variavel* direita2;
	public:
		void setCabeca(Variavel* cabeca);
		void setDireita1(Variavel* direita1);
		void setDireita2(Variavel* direita2);
		void setOperador(Operador* operador);
		Variavel* getCabeca();
		Variavel* getDireita1();
		Variavel* getDireita2();
		Operador* getOperador();
		string getExpressao();
};

class GeradorCodigoIntermediario {
	private:
		ListaComando comandos;
		ListaVariavel variaveis;
		Node* root;
	protected:
		void navegaNo(Node* actualNode);
		void trataAssign(Node* node);
	public:
		GeradorCodigoIntermediario(Node* arvoreAnotada);
		void Executar();
};

string Operador::getName(){
	return this->name;
}

VariavelTemp::VariavelTemp(string name){
	this->setName(name);
}

VariavelToken::VariavelToken(Token* token){
	this->token = token;
	this->setName(token->getLexema());
}

void Atribuicao::setCabeca(Variavel* cabeca){
	this->cabeca = cabeca;
}

void Atribuicao::setDireita1(Variavel* direita1){
	this->direita1 = direita1;
}

void Atribuicao::setDireita2(Variavel* direita2){
	this->direita2 = direita2;
}

void Atribuicao::setOperador(Operador* operador){
	this->operador = operador;
}

Variavel* Atribuicao::getCabeca(){
	return this->cabeca;
}

Variavel* Atribuicao::getDireita1(){
	return this->direita1;
}

Variavel* Atribuicao::getDireita2(){
	return this->direita2;
}
	
Operador* Atribuicao::getOperador(){
	return this->operador;
}

string Atribuicao::getExpressao(){
	string result = "";
		
	if(this->cabeca != NULL){
		result += this->cabeca->getName();
	}
	
	result +=  ":=";
	
	if(this->direita1 != NULL){
		result += this->direita1->getName();
	}
	
	if(this->operador != NULL){
		result += this->operador->getName();
	}
	
	if(this->direita2 != NULL){
		result += this->direita2->getName();
	}
}
			
GeradorCodigoIntermediario::GeradorCodigoIntermediario(Node* arvoreAnotada){
	this->root = arvoreAnotada;
}

void GeradorCodigoIntermediario::navegaNo(Node* actualNode){	
	if(actualNode->getHandle()->getType()==htNonTerminal){
			if(actualNode->getHandle()->getHandleName()=="assignStatement"){
				this->trataAssign(actualNode);
			}else{
				actualNode->firstChild();
				while(!actualNode->eof()){
					this->navegaNo(actualNode->getChild());
					
					actualNode->nextChild();
				}
			}
	}
}

void GeradorCodigoIntermediario::trataAssign(Node* node){
	Node* actual = NULL;
	Atribuicao* comando = new Atribuicao();
	Variavel* cabeca = NULL;
	Variavel* direita1 = NULL;
	Variavel* direita2 = NULL;
	
	node->firstChild();
	actual = node->getChild(); //variableAccessList
	actual->firstChild();
	actual = actual->getChild(); //variableAcess
	actual->firstChild();
	
	cabeca = new VariavelToken(actual->getChild()->getToken());
	variaveis.addVariavel(cabeca);
	
	comando->setCabeca(cabeca);
	
	node->nextChild();
	node->nextChild();
	
	actual = node->getChild();//expressionlist
	
	while(actual->getHandle()->getHandleName()!="simpleExpression"){
		actual->firstChild();
		actual = actual->getChild();
	}
	
	actual->firstChild();
	
	if(actual->getChild()->getHandle()->getHandleName()!="term"){
		actual->nextChild();
	}
	
	actual = actual->getChild(); //term
	actual->firstChild();
	actual = actual->getChild(); //factor
	
}

void GeradorCodigoIntermediario::Executar(){
	this->navegaNo(this->root);
}
