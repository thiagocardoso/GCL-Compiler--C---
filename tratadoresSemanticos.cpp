using namespace std;

class TratadorTypeDef {
	private:
		std::map<int, ListaIdentificadores*> *list;
		Node* node;
		TypeIdent* baseType;
		Token* token;
	protected:
		TypeIdent* setBaseType(Node* typeNode);		
	public:
		TratadorTypeDef(std::map<int, ListaIdentificadores*>* typeList, Node* node);
		void Execute();
		
};

TratadorTypeDef::TratadorTypeDef(std::map<int, ListaIdentificadores*>* typeList, Node* node){
	this->list = typeList;
	this->node = node;
	this->baseType = NULL;
	this->token = NULL;
}

TypeIdent* TratadorTypeDef::setBaseType(Node* typeNode){
	this->list[0]->getIdentByName("ab");
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
		
		this->token = actual->getToken();
	}	
}
