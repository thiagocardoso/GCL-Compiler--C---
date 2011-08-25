using namespace std;

class RegisterHandlesCommand {		
	private:
		Gramatica *grammar;
	public:
		void setGrammar(Gramatica *grammarValue);
		void Execute();
};

class BooleanConstant: public NonTerminalHandle {
	public:		
		void createHandleList();
};

class BooleanConstant2: public BooleanConstant{
	public:
		void createHandleList();		
};

void RegisterHandlesCommand::Execute(){
	this->grammar->registerHandle(new BooleanConstant());
}

void RegisterHandlesCommand::setGrammar(Gramatica * grammarValue){
	this->grammar = grammarValue;
}

void BooleanConstant::createHandleList(){
	HandleFactory hFactory;	
	this->setHandleName("booleanConstant");
	this->getList()->addHandle(hFactory.getTerminalHandle("True", ttKeyword, "True"));
	
	this->getOtherList()->addHandle(new BooleanConstant2);	
}

void BooleanConstant2::createHandleList(){
	HandleFactory hFactory;	
	this->setHandleName("booleanConstant");
	this->getList()->addHandle(hFactory.getTerminalHandle("False", ttKeyword, "False"));		
}
