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

class VariavelNumber: public Variavel {
	public:
		VariavelNumber(string valor);
		string getValue();
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
		ListaComando* getListaComandos();
		ListaVariavel* getListaVariaveis();
		void printComandos();
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

VariavelNumber::VariavelNumber(string valor){
	this->setName(valor);
}

string VariavelNumber::getValue(){
	return this->getName();
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
		cout << this->cabeca->getName();
		
		//result += this->cabeca->getName();
	}
	
	cout << " := ";
	//result +=  ":=";
	
	if(this->direita1 != NULL){
		cout << this->direita1->getName();
		//result += this->direita1->getName();
	}
	
	if(this->operador != NULL){
		cout << this->operador->getName();
		//result += this->operador->getName();
	}
	
	if(this->direita2 != NULL){
		cout << this->direita2->getName();
		//result += this->direita2->getName();
	}
	
	cout << ";"<< endl;
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

ListaComando* GeradorCodigoIntermediario::getListaComandos(){
	return &this->comandos;
}

ListaVariavel* GeradorCodigoIntermediario::getListaVariaveis(){
	return &this->variaveis;
}

void GeradorCodigoIntermediario::printComandos(){
	this->comandos.first();
	while(!this->comandos.eof()){
		//cout << ((Atribuicao*)this->comandos.getComando())->getExpressao();
		((Atribuicao*)this->comandos.getComando())->getExpressao();
		this->comandos.next();
	}
}

void GeradorCodigoIntermediario::trataAssign(Node* node){
	Node* actual = NULL;
	Node* aux = NULL;
	Atribuicao* comando = new Atribuicao();
	Variavel* cabeca = NULL;
	Variavel* direita1 = NULL;
	Operador* operador = NULL;
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
	
	actual = actual->getChild(); //term
	actual->firstChild();
	actual = actual->getChild(); //factor
		
	actual = actual->getChild(); //term
	actual->firstChild();
	actual = actual->getChild(); //factor			
	
	actual->firstChild();
	actual = actual->getChild(); //factor		
	
	actual->firstChild();
	aux = actual->getChild(); //factor			
	
	direita1 = new VariavelNumber(aux->getToken()->getLexema());
	comando->setDireita1(direita1);
	
	this->comandos.addComando(comando);
}

void GeradorCodigoIntermediario::Executar(){
	this->navegaNo(this->root);
}
