using namespace std;

class TratadorTypeDef {
	private:
		std::map<int, ListaIdentificadores*> *list;
		Node* node;
		int escopoAtual;
		TypeIdent* baseType;
		Token* token;
	protected:
		TypeIdent* setBaseType(Node* typeNode);		
	public:
		TratadorTypeDef(std::map<int, ListaIdentificadores*>* typeList, Node* node, int escopoAtual);
		void Execute();		
};

TratadorTypeDef::TratadorTypeDef(std::map<int, ListaIdentificadores*>* typeList, Node* node, int escopoAtual){
	this->list = typeList;
	this->node = node;
	this->escopoAtual = escopoAtual;
	this->baseType = NULL;
	this->token = NULL;
}

TypeIdent* TratadorTypeDef::setBaseType(Node* typeNode){
	int escopo = this->escopoAtual;
	Node* typeSymbol;
	
	typeNode->firstChild();
	
	if(typeNode->getChild()->getHandle()->getHandleName()=="typeSymbol"){	
		typeSymbol = typeNode->getChild()->getChild();
		
		while((escopo>=0)&&(this->baseType==NULL)){
			this->baseType = (TypeIdent*) (*this->list)[escopo]->getIdentByName(typeSymbol->getToken()->getLexema());
		
			escopo--;
		}
	}else{
		//TRATAR TUPLETYPE
	}
}

void TratadorTypeDef::Execute(){
	Node* actual;	
	
	node->firstChild();
	actual = node->getChild();	
	if(actual->getToken()->getLexema()=="typedef"){
		node->nextChild();
		actual = node->getChild();
		
		if(actual->getHandle()->getHandleName()=="type"){
			this->setBaseType(actual);
		}
		
		node->nextChild();
		actual = node->getChild();
		
		if(this->baseType!=NULL){
			(*this->list)[this->escopoAtual]->addType(actual->getToken(), this->baseType);		
		}else{
			//ERRO NAO ENCONTROU TIPO BASE
		}
	}	
}
