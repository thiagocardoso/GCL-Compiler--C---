#include <map>
#include <list>
#include "identificador.cpp"
#include "tratadoresSemanticos.cpp"
using namespace std;

class AnalisadorSemantico{
	private:
		Node* arvore;
		std::map<int, ListaIdentificadores*> varList; //int = escopo -> Escopo x Lista
		std::map<int, ListaIdentificadores*> procList;// ^^
		std::map<int, ListaIdentificadores*> typeList;
		int escopoAtual;
	protected:
		void validarNo(Node* actualNode);
		void Erro(string message);
		void adicionarEscopo();
		void removerEscopo();	
		void criarListas();
		void adicionarVariavel(Node* node, VarType tipo);
		void variableDef(Node* node);
		void procedureDef(Node* node);
		void typeDef(Node* node);
		void assignStatement(Node* node);
		void validaAssign(Node* node);
		void criarTiposBase();
		bool chamaTratador(Node* node);
	public:
		AnalisadorSemantico(Node* arvoreSintatica);
		void Executar();
};

AnalisadorSemantico::AnalisadorSemantico(Node* arvoreSintatica){
	this->arvore = arvoreSintatica;
	this->escopoAtual = 0;
	
	this->criarListas();
	this->criarTiposBase();
}

void AnalisadorSemantico::criarTiposBase(){
	Token* token;
	
	token = new TokenID();
	token->setLexema("Integer");
	this->typeList[0]->addType(token, NULL);
	
	token = new TokenID();
	token->setLexema("Boolean");
	this->typeList[0]->addType(token, NULL);
	
	token = new TokenID();
	token->setLexema("String");
	this->typeList[0]->addType(token, NULL);
	
	token = new TokenID();
	token->setLexema("Real");
	this->typeList[0]->addType(token, NULL);
}

void AnalisadorSemantico::Executar(){
     this->validarNo(this->arvore);
}

void AnalisadorSemantico::validarNo(Node* actualNode){
	bool novoEscopo = false;
	
	switch(actualNode->getHandle()->getType()){
		case htNonTerminal:{					
			novoEscopo = (actualNode->getHandle()->getHandleName()=="module")||(actualNode->getHandle()->getHandleName()=="procedureDef");
			
			cout << "Avaliando:" << actualNode->getHandle()->getHandleName() <<endl;
			
			if(novoEscopo){
				this->adicionarEscopo();
				
				cout << "Adicionou Escopo:" << this->escopoAtual <<endl;
			}			
			
			if(!this->chamaTratador(actualNode)){			
				actualNode->firstChild();
				while(!actualNode->eof()){
					this->validarNo(actualNode->getChild());
					
					actualNode->nextChild();
				}
				
				if(novoEscopo){
					cout << "Removeu Escopo:" << this->escopoAtual <<endl;
					
					this->removerEscopo();				
				}
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
    this->typeList[this->escopoAtual] = new ListaIdentificadores();
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

bool AnalisadorSemantico::chamaTratador(Node* node){
     bool result = false;
     
    if(node->getHandle()->getHandleName()=="typeDef"){
		this->typeDef(node);
		result = true;
    }
     
     return result;
}

void AnalisadorSemantico::adicionarVariavel(Node* node, VarType tipo){	
	//navegar pela "variableList" encontrando os Idents e declarando como variavel
}

void AnalisadorSemantico::variableDef(Node* node){
	//pegar o primeiro nó filho que é o tipo, tratar e chamar o "adicionarVariavel" passando o segundo nó que é a variableList
}

void AnalisadorSemantico::procedureDef(Node* node){
	//ignorar o primeiro nó filho que é o "proc", pegar o segundo nó "ident" e adicionar na lista de procedures
}

void AnalisadorSemantico::validaAssign(Node* node){
	//percorre o "variableAccessList" verificando se as variáveis existem na lista de variaveis declaradas
}

void AnalisadorSemantico::assignStatement(Node* node){
	//passar o primeiro nó filho(variableAccessList) para o "validaAssign"
}

void AnalisadorSemantico::typeDef(Node* node){
	//ignorar o primeiro nó filho que é o "typedef", buscar o tipo base a partir do segundo, passar o token do terceiro nó para adicionar (identificador)
	TratadorTypeDef tratador(&this->typeList, node, this->escopoAtual);
	tratador.Execute();
}

void AnalisadorSemantico::Erro(string message){
}
