using namespace std;

class RegisterHandlesCommand {		
	private:
		Gramatica *grammar;
	public:
		void setGrammar(Gramatica *grammarValue);
		void Execute();
};

class Expression: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class IndexOrComp: public NonTerminalHandle {	
	public:
		void InnerSetup();
		void createHandleList();
}; 

class IndexOrCompParts: public NonTerminalHandle {	
	public:
		void InnerSetup();
		void createHandleList();	
}; 

class IndexOrCompParts2: public IndexOrCompParts {
	public:
		void createHandleList();
};

class BooleanConstant: public NonTerminalHandle {
	public:		
		void InnerSetup();
		void createHandleList();
};

class BooleanConstant2: public BooleanConstant{
	public:
		void createHandleList();		
};

class RelationalOperator: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class RelationalOperator2: public RelationalOperator {
	public:
		void createHandleList();
};

class RelationalOperator3: public RelationalOperator {
	public:
		void createHandleList();
};

class RelationalOperator4: public RelationalOperator {
	public:
		void createHandleList();
};

class RelationalOperator5: public RelationalOperator {
	public:
		void createHandleList();
};

class RelationalOperator6: public RelationalOperator {
	public:
		void createHandleList();
};

void RegisterHandlesCommand::Execute(){
	//this->grammar->registerHandle(new BooleanConstant());
	this->grammar->registerHandle(new RelationalOperator());	
}

void RegisterHandlesCommand::setGrammar(Gramatica * grammarValue){
	this->grammar = grammarValue;
}

void BooleanConstant::InnerSetup(){
	this->setHandleName("booleanConstant");	
}

void BooleanConstant::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("True", ttKeyword, "True"));
	
	this->getOtherList()->addHandle(new BooleanConstant2);	
}

void BooleanConstant2::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("False", ttKeyword, "False"));		
}

void RelationalOperator::InnerSetup(){
	this->setHandleName("relationalOperator");
}

void RelationalOperator::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("<", ttSymbol, "<"));
	
	this->getOtherList()->addHandle(new RelationalOperator2);
	this->getOtherList()->addHandle(new RelationalOperator3);
	this->getOtherList()->addHandle(new RelationalOperator4);
	this->getOtherList()->addHandle(new RelationalOperator5);
	this->getOtherList()->addHandle(new RelationalOperator6);
}

void RelationalOperator2::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("=", ttSymbol, "="));
}

void RelationalOperator3::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle(">", ttSymbol, ">"));
}

void RelationalOperator4::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("<=", ttSymbol, "<="));
}

void RelationalOperator5::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle(">=", ttSymbol, ">="));
}

void RelationalOperator6::createHandleList(){
	HandleFactory hFactory;		
	this->getList()->addHandle(hFactory.getTerminalHandle("#", ttSymbol, "#"));
}

void IndexOrComp::InnerSetup(){
	//this->setAllowEmpty(false);
	this->setAllowEmpty(true);
	this->setHandleName("indexOrComp");
}

void IndexOrComp::createHandleList(){
	this->getList()->addHandle(new IndexOrCompParts());
	this->getList()->addHandle(new IndexOrComp());
}

void IndexOrCompParts::InnerSetup(){	
	this->setHandleName("indexOrCompParts");
}

void IndexOrCompParts::createHandleList(){
	HandleFactory hFactory;			
	this->getList()->addHandle(hFactory.getTerminalHandle(".", ttSymbol, "."));
	this->getList()->addHandle(hFactory.getTerminalHandle("Number", ttNumber, "0"));
	
	this->getOtherList()->addHandle(new IndexOrCompParts2);	
}

void IndexOrCompParts2::createHandleList(){
	HandleFactory hFactory;		
	Expression *exp = new Expression();
	
	this->getList()->addHandle(hFactory.getTerminalHandle("[", ttSymbol, "["));	
	//this->getList()->addHandle(exp);	
	this->getList()->addHandle(hFactory.getTerminalHandle("]", ttSymbol, "]"));
}

void Expression::InnerSetup(){
	this->setAllowEmpty(true);
}

void Expression::createHandleList(){
}

