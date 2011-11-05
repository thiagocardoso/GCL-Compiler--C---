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

class TratadorProcDecl {
	private:
		std::map<int, ListaIdentificadores*> *list;
		int escopoAtual;
		Node* node;
	public:
		TratadorProcDecl(std::map<int, ListaIdentificadores*>* procList, Node* node, int escopoAtual);	
		void Execute();	
};

class TratadorVariableAccess {
	private:
		std::map<int, ListaIdentificadores*> *list;
		int escopoAtual;
		Node* node;
	public:
		TratadorVariableAccess(std::map<int, ListaIdentificadores*>* varList, Node* node, int escopoAtual);	
		void Execute();
};

class TratadorVariableDef {
	private:
		std::map<int, ListaIdentificadores*> *varList;
		std::map<int, ListaIdentificadores*> *typeList;
		int escopoAtual;
		Node* node;		
	protected:
		TypeIdent* getType(Node* typeNode);		
		void addVariavel(TypeIdent* type, Node* varNode);
	public:
		TratadorVariableDef(std::map<int, ListaIdentificadores*>* varList, std::map<int, ListaIdentificadores*>* typeList, Node* node, int escopoAtual);	
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
        typeNode->getChild()->getChild()->firstChild();
		typeSymbol = typeNode->getChild()->getChild()->getChild();
		
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

TratadorProcDecl::TratadorProcDecl(std::map<int, ListaIdentificadores*>* procList, Node* node, int escopoAtual){
	this->list = procList;
	this->escopoAtual = escopoAtual;
	this->node = node;
}

void TratadorProcDecl::Execute(){    
	Node* actual;	
	
	node->firstChild();
	actual = node->getChild();	
	if(actual->getToken()->getLexema()=="proc"){
		node->nextChild();
		actual = node->getChild();
		
		(*this->list)[this->escopoAtual]->addProc(actual->getToken());				
	}	
}

TratadorVariableAccess::TratadorVariableAccess(std::map<int, ListaIdentificadores*>* varList, Node* node, int escopoAtual){
	this->list = varList;
	this->escopoAtual = escopoAtual;
	this->node = node;	
}

void TratadorVariableAccess::Execute(){
	Node* actual;
	bool result = false;
	int escopo = this->escopoAtual;
	
	node->firstChild();
	actual = node->getChild();
	
	while((escopo>=0)&&(!result)){
		result = (*this->list)[escopo]->exists(actual->getToken()->getLexema());
		
		escopo--;
	}
	
	if(!result){
		//ERRO - VARIAVEL NAO DECLARADA
		cout << "Variavel não encontrada: " << actual->getToken()->getLexema()<<endl;
	}
}

TratadorVariableDef::TratadorVariableDef(std::map<int, ListaIdentificadores*>* varList, std::map<int, ListaIdentificadores*>* typeList, Node* node, int escopoAtual){
	this->varList = varList;
	this->typeList = typeList;
	this->escopoAtual = escopoAtual;
	this->node = node;	
}

void TratadorVariableDef::Execute(){
	Node* actual;
	TypeIdent* type = NULL;
	
	node->firstChild();
	actual = node->getChild();
	actual->firstChild();
	//if(actual->getChild()->getHandle()->getHandleName()=="typeSymbol"){
//		type = this->getType(actual->getChild());
	//}
    type = this->getType(actual);
	
	if(type!=NULL){
        node->nextChild();
        actual = node->getChild();
                   
//		actual->nextChild();
		if(actual->getChild()->getHandle()->getHandleName()=="variableList"){
			actual = actual->getChild();
			//actual->getHandle()->getHandleName()
			actual->firstChild();
			this->addVariavel(type, actual->getChild());
			
			actual->nextChild();
			if(actual->getChild()->getHandle()->getHandleName()=="variableListParts"){
				actual = actual->getChild();
				
				actual->firstChild();
				if(!actual->eof()){
					actual->nextChild();
					this->addVariavel(type, actual->getChild());
				}
			}
		}
	}else{
		//ERRO - TIPO NAO DECLARADO
	}
}

void TratadorVariableDef::addVariavel(TypeIdent* type, Node* varNode){
	VarType varType = vtTypeDef;
	
	if(type->getName()=="Boolean"){
		varType = vtBoolean;
	}

	if(type->getName()=="Integer"){
		varType = vtInteger;
	}
	
	if(type->getName()=="String"){
		varType = vtString;
	}
	
	if(type->getName()=="Real"){
		varType = vtReal;
	}
	
	(*this->varList)[this->escopoAtual]->addVar(varNode->getToken(), varType, type);
}

TypeIdent* TratadorVariableDef::getType(Node* typeNode){
	int escopo = this->escopoAtual;
	Node* typeSymbol;
	TypeIdent* resultType=NULL;
	
	typeNode->firstChild();
	
	if(typeNode->getChild()->getHandle()->getHandleName()=="typeSymbol"){	
        typeNode->getChild()->getChild()->firstChild();
		typeSymbol = typeNode->getChild()->getChild()->getChild();
		
		while((escopo>=0)&&(resultType==NULL)){
			resultType = (TypeIdent*) (*this->typeList)[escopo]->getIdentByName(typeSymbol->getToken()->getLexema());
		
			escopo--;
		}
		
		return resultType;
	}else{
		//TRATAR TUPLETYPE
	}
}
