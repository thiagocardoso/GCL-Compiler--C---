using namespace std;

class RegisterHandlesCommand {		
	private:
		Gramatica *grammar;
	public:
		void setGrammar(Gramatica *grammarValue);
		void Execute();
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

class VariableMore: public NonTerminalHandle{
	public: 
		void InnerSetup();
		void createHandleList();	
};

class VariableMore2: public VariableMore{
	public:
		void createHandleList();
};

class VariableMore3: public VariableMore{
	public:
		void createHandleList();
};

class VariableMore4: public VariableMore{
	public:
		void createHandleList();
};

class NextItem: public NonTerminalHandle{
	public:
		void InnerSetup();	
		void createHandleList();	
};

class NextItem2: public NextItem{
	public:
		void createHandleList();
};

class VariableAccess: public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class ConstantName: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();

};

class MultiplyOperator: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};


class MultiplyOperator2: public MultiplyOperator{
	public:
		void createHandleList();
};

class MultiplyOperator3: public MultiplyOperator{
	public:
		void createHandleList();
};

class AddingOperator: public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class AddingOperator2: public AddingOperator{
	public:
		void createHandleList();

};

class Factor: public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList(); 
};

class Factor2: public Factor{
	public:
		void createHandleList();
};

class Factor3: public Factor{
	public:
		void createHandleList();
};

class Factor4: public Factor{
	public:
		void createHandleList();
};

class Factor5: public Factor{
	public:
		void createHandleList();
};

class Factor6: public Factor{
	public:
		void createHandleList();
};

class TermParts:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class Term:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class SimpleExprParts:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList(); 
};

class SimpleExprOp:public NonTerminalHandle{
	public: 
		void InnerSetup();
		void createHandleList();
};

class SimpleExprOp2:public SimpleExprOp{
	public:
		void createHandleList(); 
};

class SimpleExpression:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class SimpleExpression2:public SimpleExpression{
	public:
		void createHandleList();
};

class RelationalExpression:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class RelationalExpression2:public RelationalExpression{
	public:
		void createHandleList();
};


class BooleanOperator:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class BooleanOperator2:public BooleanOperator{
	public:
		void createHandleList();

};
class EmptyStatement:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class ReadStatement:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class VariableAccessList:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class VariableAccessList2:public NonTerminalHandle{
	public:
        void InnerSetup();
		void createHandleList();
};

class WriteStatement:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class WriteItemParts:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};

class WriteItemParts2:public WriteItemParts{
	public:
		void InnerSetup();           
		void createHandleList();
};

class WriteItem:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList(); 
};

class WriteItem2:public WriteItem{
	public:
		void createHandleList(); 
};


class StringConst:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
};


class Letters:public NonTerminalHandle{
	public: 
		void InnerSetup();
		void createHandleList();
};


class Letters2:public Letters{
	public: 
		void createHandleList();
};


class ExpressionList:public NonTerminalHandle{
	public:
		void InnerSetup();
		void createHandleList();
}; 


class ExpressionList2:public NonTerminalHandle{
	public:
		void createHandleList();
}; 

class Program: public NonTerminalHandle {	
	public:
		void InnerSetup();
		void createHandleList();
}; 

class Module: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Modules: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Modules2: public Modules {
	public:		
		void createHandleList();
};

class ModuleOpt: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Block: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class DefinitionPart: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class DefinitionParts: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class DefinitionParts2: public DefinitionPart {
	public:		
		void createHandleList();
};

class Definition: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Definition2: public Definition {
	public:		
		void createHandleList();
};

class Definition3: public Definition {
	public:		
		void createHandleList();
};

class Definition4: public Definition {
	public:		
		void createHandleList();
};

class Definition5: public Definition {
	public:		
		void createHandleList();
};

class ConstantDef: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class VariableDef: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Type: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class Type2: public Type {
	public:		
		void createHandleList();
};

class TypeOpt: public NonTerminalHandle {
	public:		
		void InnerSetup();
		void createHandleList();
};

class TypeOpt2: public TypeOpt {
	public:				
		void createHandleList();
};

class TypeSymbol: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class TypeSymbol2: public TypeSymbol {
	public:				
		void createHandleList();
};

class TypeSymbol3: public TypeSymbol {
	public:				
		void createHandleList();
};

class TypeSymbol4: public TypeSymbol {
	public:				
		void createHandleList();
};

class TypeSymbol5: public TypeSymbol {
	public:				
		void createHandleList();
};

class TupleType: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class TupleParts: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class TupleParts2: public TupleParts {
	public:			
		void createHandleList();
};

class ArrayType: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ArrayParts: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ArrayParts2: public ArrayParts {
	public:		
		void createHandleList();
};

class RangeType: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class VariableList: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class VariableListParts: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class VariableListParts2: public VariableListParts {
	public:		
		void createHandleList();
};

class TypeDef: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ProcedureDecl: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ProcedureDeclOpt: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ProcedureDef: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ParamPart: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ParamPartOpt: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ParamPartOptParts: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ParamPartOptParts2: public ParamPartOptParts {
	public:		
		void createHandleList();
};

class ParamDef: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class ParamDef2: public ParamDef {
	public:		
		void createHandleList();
};

class StatementParts: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class StatementParts2: public StatementParts {
	public:		
		void createHandleList();
};

class Statement: public NonTerminalHandle {
	public:
		void InnerSetup();				
		void createHandleList();
};

class Statement2: public Statement {
	public:			
		void createHandleList();
};

class Statement3: public Statement {
	public:			
		void createHandleList();
};

class Statement4: public Statement {
	public:			
		void createHandleList();
};

class Statement5: public Statement {
	public:			
		void createHandleList();
};

class Statement6: public Statement {
	public:			
		void createHandleList();
};

class Statement7: public Statement {
	public:			
		void createHandleList();
};

class Statement8: public Statement {
	public:			
		void createHandleList();
};

class Statement9: public Statement {
	public:			
		void createHandleList();
};

class AssignStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class IfStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class GuardedCommandList: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class GuardedCommandList2: public GuardedCommandList {
	public:		
		void createHandleList();
};

class GuardedCommandParts: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class GuardedCommand: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class DoStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class ForStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class ReturnStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class CallStatement: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class CallStatement2: public CallStatement {
	public:		
		void createHandleList();
};

class ArgumentList: public NonTerminalHandle {
	public:
		void InnerSetup();
		void createHandleList();
};

class ArgumentList2: public ArgumentList {
	public:		
		void createHandleList();
};

class Expression: public NonTerminalHandle {
	public:		
		void InnerSetup();
		void createHandleList();
};

class Expression2: public Expression {
	public:				
		void createHandleList();
};

// ImplementaÃ§Ã£o

void RegisterHandlesCommand::Execute(){
	//this->grammar->registerHandle(new BooleanConstant());
	//this->grammar->registerHandle(new RelationalOperator());	
	//this->grammar->registerHandle(new VariableMore());     	* Testar com as outras produÃ§Ãµes*
	//this->grammar->registerHandle(new VariableAccess());
	this->grammar->registerHandle(new AddingOperator());	
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
	this->getList()->addHandle(exp);	
	this->getList()->addHandle(hFactory.getTerminalHandle("]", ttSymbol, "]"));
}

void VariableMore::InnerSetup(){
	this->setHandleName("variableMore");
	this->setAllowEmpty(true);
}

void VariableMore::createHandleList(){
	HandleFactory hFactory;
	
	this->getList()->addHandle(hFactory.getTerminalHandle("\"",ttSymbol,"\""));
	this->getList()->addHandle(hFactory.getTerminalHandle("\"",ttSymbol,"\""));
	
	this->getOtherList()->addHandle(new VariableMore2);
	this->getOtherList()->addHandle(new VariableMore3);
	this->getOtherList()->addHandle(new VariableMore4);
}

void VariableMore2::createHandleList(){
	HandleFactory hFactory;
	Expression * exp = new Expression();
	IndexOrComp *indexOrComp = new IndexOrComp();
	
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));
	this->getList()->addHandle(exp);
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));
	this->getList()->addHandle(indexOrComp);
}

void VariableMore3::createHandleList(){
	HandleFactory hFactory;
	IndexOrComp *indexOrComp = new IndexOrComp();
	NextItem *nextItem = new NextItem();
	
	
	this->getList()->addHandle(hFactory.getTerminalHandle(".",ttSymbol,"."));
	this->getList()->addHandle(nextItem);
	this->getList()->addHandle(indexOrComp);
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));
}

void VariableMore4::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
}

void NextItem::InnerSetup(){
	this->setHandleName("nextItem");
}

void NextItem::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));
	
	this->getOtherList()->addHandle(new NextItem2);
}	

void NextItem2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident", ttId, "Ident"));
}

void VariableAccess::InnerSetup(){
	this->setHandleName("variableAccess");
}

void VariableAccess::createHandleList(){
	HandleFactory hFactory;
	VariableMore * varMore = new VariableMore();
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident")); 
	this->getList()->addHandle(varMore);
}

void ConstantName::InnerSetup(){
	this->setHandleName("constantName");
}

void ConstantName::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
}

void MultiplyOperator::InnerSetup(){
	this->setHandleName("multiplyOperator");
	
}

void MultiplyOperator::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("*",ttSymbol,"*"));
}

void MultiplyOperator2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("/",ttSymbol,"/"));
}

void MultiplyOperator3::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("\\",ttSymbol,"\\"));
}

void AddingOperator::InnerSetup(){
	this->setHandleName("addingOperator");
}

void AddingOperator::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("+",ttSymbol,"+"));
}

void AddingOperator2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("-",ttSymbol,"-"));
}

void Factor::InnerSetup(){
	this->setHandleName("factor");
}

void Factor::createHandleList(){
	this->getList()->addHandle(new VariableAccess);
	this->getOtherList()->addHandle(new Factor2);
	this->getOtherList()->addHandle(new Factor3);
	this->getOtherList()->addHandle(new Factor4);
	this->getOtherList()->addHandle(new Factor5);
	this->getOtherList()->addHandle(new Factor6);
}

void Factor2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));
}

void Factor3::createHandleList(){
	this->getList()->addHandle(new BooleanConstant);
}

void Factor4::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));
	this->getList()->addHandle(new ExpressionList);
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));
}

void Factor5::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("(",ttSymbol,"("));
	this->getList()->addHandle(new Expression);
	this->getList()->addHandle(hFactory.getTerminalHandle(")",ttSymbol,")"));
} 

void Factor6::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("~",ttSymbol,"~"));
	this->getList()->addHandle(new Factor);
}

void TermParts::InnerSetup(){
	this->setAllowEmpty(true);
	this->setHandleName("termParts"); 
}

void TermParts::createHandleList(){
	this->getList()->addHandle(new MultiplyOperator);
	this->getList()->addHandle(new Factor);
	this->getList()->addHandle(new TermParts);
}

void Term::InnerSetup(){
	this->setHandleName("term");
}

void Term::createHandleList(){
	this->getList()->addHandle(new Factor);
	this->getList()->addHandle(new TermParts);
}

void SimpleExprParts::InnerSetup(){
	this->setAllowEmpty(true);
	this->setHandleName("simpleExprParts");
}

void SimpleExprParts::createHandleList(){
	this->getList()->addHandle(new AddingOperator);
	this->getList()->addHandle(new Term);
	this->getList()->addHandle(new SimpleExprParts);
}

void SimpleExprOp::InnerSetup(){
	this->setHandleName("simpleExprOp");
}

void SimpleExprOp::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("+",ttSymbol,"+"));
	this->getOtherList()->addHandle(new SimpleExprOp2);	
}

void SimpleExprOp2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("-",ttSymbol,"-"));
}

void SimpleExpression::InnerSetup(){
	this->setHandleName("simpleExpression");
}

void SimpleExpression::createHandleList(){
	this->getList()->addHandle(new SimpleExprOp);
	this->getList()->addHandle(new Term);
	this->getList()->addHandle(new SimpleExprParts);
	
	this->getOtherList()->addHandle(new SimpleExpression2);
}

void SimpleExpression2::createHandleList(){
  	this->getList()->addHandle(new Term);
	this->getList()->addHandle(new SimpleExprParts);
}

void RelationalExpression::InnerSetup(){
	this->setHandleName("relationalExpression");
}

void RelationalExpression::createHandleList(){
	this->getList()->addHandle(new SimpleExpression); 
	
	this->getOtherList()->addHandle(new RelationalExpression2);
}

void RelationalExpression2::createHandleList(){
	this->getList()->addHandle(new SimpleExpression);
	this->getList()->addHandle(new RelationalOperator);
	this->getList()->addHandle(new SimpleExpression);
}

void BooleanOperator::InnerSetup(){
	this->setHandleName("booleanOperator");
	
} 

void BooleanOperator::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("&",ttSymbol,"&"));
	
	this->getOtherList()->addHandle(new BooleanOperator2);
}

void BooleanOperator2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("|",ttSymbol,"|"));
}

void EmptyStatement::InnerSetup(){
	this->setHandleName("empyStatement");	
}

void EmptyStatement::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("skip",ttKeyword,"skip"));
}

void ReadStatement::InnerSetup(){
	this->setHandleName("readStatement");
}

void ReadStatement::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("read",ttKeyword,"read"));
	this->getList()->addHandle(new VariableAccessList);
}

void VariableAccessList::InnerSetup(){
	this->setHandleName("variableAccessList");
}

void VariableAccessList::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(new VariableAccess);
	//this->getOtherList()->addHandle(new VariableAccessList2);
	this->getList()->addHandle(new VariableAccessList2);
}

void VariableAccessList2::InnerSetup(){
	this->setHandleName("variableAccessList2");
	this->setAllowEmpty(true);
}

void VariableAccessList2::createHandleList(){
	HandleFactory hFactory;	
	this->getList()->addHandle(new VariableAccess);
	this->getList()->addHandle(hFactory.getTerminalHandle(",",ttSymbol,","));
	this->getList()->addHandle(new VariableAccessList);
}

void WriteStatement::InnerSetup(){
	this->setHandleName("writeStatement");
}

void WriteStatement::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("write",ttKeyword,"write"));
	this->getList()->addHandle(new WriteItemParts);
}

void WriteItemParts::InnerSetup(){
	this->setHandleName("writeItemParts");
}

void WriteItemParts::createHandleList(){
	this->getList()->addHandle(new WriteItem);
	this->getList()->addHandle(new WriteItemParts2);
}

void WriteItemParts2::InnerSetup(){
	this->setHandleName("writeItemParts2");
	this->setAllowEmpty(true);
}

void WriteItemParts2::createHandleList(){
	HandleFactory hFactory;
    this->getList()->addHandle(hFactory.getTerminalHandle(",",ttSymbol,","));
	this->getList()->addHandle(new WriteItem);
	this->getList()->addHandle(new WriteItemParts2);
}

void WriteItem::InnerSetup(){
	this->setHandleName("writeItem");
}

void WriteItem::createHandleList(){
	this->getList()->addHandle(new StringConst);
	this->getOtherList()->addHandle(new WriteItem2);
}

void WriteItem2::createHandleList(){
	this->getList()->addHandle(new Expression);
}


void StringConst::InnerSetup(){
	this->setHandleName("stringConst");
}

void StringConst::createHandleList(){
	HandleFactory hFactory;
	
	this->getList()->addHandle(hFactory.getTerminalHandle("\"",ttSymbol,"\""));
	this->getList()->addHandle(new Letters);
	this->getList()->addHandle(hFactory.getTerminalHandle("\"",ttSymbol,"\""));
}

void Letters::InnerSetup(){
	this->setHandleName("letters");
}

void Letters::createHandleList(){
	HandleFactory hFactory;
	
	this->getList()->addHandle(hFactory.getTerminalHandle("letter",ttSymbol,"letter"));
	this->getOtherList()->addHandle(new Letters2);
}

void Letters2::createHandleList(){
	HandleFactory hFactory;
	
	this->getList()->addHandle(hFactory.getTerminalHandle("letter",ttSymbol,"letter"));
	this->getList()->addHandle(new Letters);
}


void ExpressionList::InnerSetup(){
	this->setHandleName("expressionList");
}

void ExpressionList::createHandleList(){
	this->getList()->addHandle(new Expression);
	this->getOtherList()->addHandle(new ExpressionList2);
}

void ExpressionList2::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(new Expression);
	this->getList()->addHandle(hFactory.getTerminalHandle(",",ttSymbol,","));
	this->getList()->addHandle(new ExpressionList);
}

void Program::InnerSetup(){
	this-> setHandleName("program");
}

void Program::createHandleList(){
	this->getList()->addHandle(new Module);	
	this->getList()->addHandle(new Modules);
}

void Module::InnerSetup(){
	this-> setHandleName("module");
}

void Module::createHandleList(){
	HandleFactory hFactory;
	
	this->getList()->addHandle(hFactory.getTerminalHandle("module",ttKeyword,"module"));
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(new DefinitionPart);
	this->getList()->addHandle(new ModuleOpt);
	this->getList()->addHandle(hFactory.getTerminalHandle(".",ttSymbol,"."));
}

void Modules::InnerSetup(){
	this->setHandleName("modules");
	this->setAllowEmpty(true);
}

void Modules::createHandleList(){
	this->getList()->addHandle(new Module);	
	this->getList()->addHandle(new Modules);
	
//	this->getOtherList()->addHandle(new Modules2);		
}

void Modules2::createHandleList(){
	//this->getList()->addHandle(new Modules);
}

void ModuleOpt::InnerSetup(){
	this->setHandleName("moduleOpt");
	this->setAllowEmpty(true);
}

void ModuleOpt::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("private",ttKeyword,"private"));	
	this->getList()->addHandle(new Block);
}

void Block::InnerSetup(){
	this->setHandleName("block");	
}

void Block::createHandleList(){
	HandleFactory hFactory;
	this->getList()->addHandle(new DefinitionPart);
	this->getList()->addHandle(hFactory.getTerminalHandle("begin",ttKeyword,"begin"));	
	this->getList()->addHandle(new StatementParts);
	this->getList()->addHandle(hFactory.getTerminalHandle("end",ttKeyword,"end"));	
}

void DefinitionPart::InnerSetup(){
	this->setHandleName("definitionPart");
}

void DefinitionPart::createHandleList(){	
	this->getList()->addHandle(new DefinitionParts);
}

void DefinitionParts::InnerSetup(){
	this->setHandleName("definitionParts");
	this->setAllowEmpty(true);
}

void DefinitionParts::createHandleList(){
	HandleFactory hFactory;	
	this->getList()->addHandle(new Definition);
	this->getList()->addHandle(hFactory.getTerminalHandle(";",ttSymbol,";"));	
	this->getList()->addHandle(new DefinitionParts);
	//this->getOtherList()->addHandle(new DefinitionParts2);
}

void DefinitionParts2::createHandleList(){	
	this->getList()->addHandle(new DefinitionPart);
}

void Definition::InnerSetup(){
	this->setHandleName("definition");	
}

void Definition::createHandleList(){	
	this->getList()->addHandle(new ConstantDef);	
	
	this->getOtherList()->addHandle(new Definition2);
	this->getOtherList()->addHandle(new Definition3);
	this->getOtherList()->addHandle(new Definition4);
	this->getOtherList()->addHandle(new Definition5);
}

void Definition2::createHandleList(){	
	this->getList()->addHandle(new VariableDef);	
}

void Definition3::createHandleList(){	
	//this->getList()->addHandle(new ProcedureDef);	
}

void Definition4::createHandleList(){	
	this->getList()->addHandle(new TypeDef);	
}

void Definition5::createHandleList(){	
//	this->getList()->addHandle(new ProcedureDecl);	
}

void ConstantDef::InnerSetup(){
	this->setHandleName("constantDef");	
}

void ConstantDef::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("const",ttKeyword,"const"));		
	this->getList()->addHandle(new ConstantName);	
	this->getList()->addHandle(hFactory.getTerminalHandle("=",ttSymbol,"="));
	//this->getList()->addHandle(new Constant);	
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));	
}

void VariableDef::InnerSetup(){
	this->setHandleName("variableDef");	
}

void VariableDef::createHandleList(){	
	this->getList()->addHandle(new Type);	
	this->getList()->addHandle(new VariableList);
}

void Type::InnerSetup(){
	this->setHandleName("type");	
}

void Type::createHandleList(){	
	this->getList()->addHandle(new TypeSymbol);	
	this->getList()->addHandle(new TypeOpt);
	
	this->getOtherList()->addHandle(new Type2);
}

void Type2::createHandleList(){	
	this->getList()->addHandle(new TupleType);		
}

void TypeOpt::InnerSetup(){
	this->setHandleName("typeOpt");	
	this->setAllowEmpty(true);
}

void TypeOpt::createHandleList(){	
	this->getList()->addHandle(new ArrayType);
	
	this->getOtherList()->addHandle(new TypeOpt2);
}

void TypeOpt2::createHandleList(){	
	this->getList()->addHandle(new RangeType);		
}

void TypeSymbol::InnerSetup(){
	this->setHandleName("typeSymbol");		
}

void TypeSymbol::createHandleList(){
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("Integer",ttKeyword,"Integer"));			
	
	this->getOtherList()->addHandle(new TypeSymbol2);	
	this->getOtherList()->addHandle(new TypeSymbol3);	
	this->getOtherList()->addHandle(new TypeSymbol4);	
	this->getOtherList()->addHandle(new TypeSymbol5);	
}

void TypeSymbol2::createHandleList(){
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("Boolean",ttKeyword,"Boolean"));			
}

void TypeSymbol3::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Real",ttKeyword,"Real"));			
}

void TypeSymbol4::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("String",ttKeyword,"String"));			
}

void TypeSymbol5::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));			
}

void TupleType::InnerSetup(){
	this->setHandleName("tupleType");		
}

void TupleType::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));			
	this->getList()->addHandle(new TypeSymbol);		
	this->getList()->addHandle(new TupleParts);		
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));			
}

void TupleParts::InnerSetup(){
	this->setHandleName("tupleParts");	
	this->setAllowEmpty(true);
}

void TupleParts::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle(",",ttSymbol,","));
	this->getList()->addHandle(new TypeSymbol);
	
	this->getOtherList()->addHandle(new TupleParts2);
}

void TupleParts2::createHandleList(){	
	this->getList()->addHandle(new TupleParts);		
}

void ArrayType::InnerSetup(){
	this->setHandleName("arrayType");		
}

void ArrayType::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("array",ttKeyword,"array"));
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));
	this->getList()->addHandle(new ArrayParts);	
}

void ArrayParts::InnerSetup(){
	this->setHandleName("arrayParts");	
	this->setAllowEmpty(true);
}

void ArrayParts::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));	
	//this->getList()->addHandle(new ArrayParts2);	
	
	this->getOtherList()->addHandle(new ArrayParts2);
}

void ArrayParts2::createHandleList(){	
	this->getList()->addHandle(new ArrayParts);		
}

void RangeType::InnerSetup(){
	this->setHandleName("rangeType");		
}

void RangeType::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("range",ttKeyword,"range"));
	this->getList()->addHandle(hFactory.getTerminalHandle("[",ttSymbol,"["));
	//this->getList()->addHandle(new Constant);
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));
	this->getList()->addHandle(hFactory.getTerminalHandle("..",ttSymbol,".."));
	//this->getList()->addHandle(new Constant);
	this->getList()->addHandle(hFactory.getTerminalHandle("Number",ttNumber,"0"));
	this->getList()->addHandle(hFactory.getTerminalHandle("]",ttSymbol,"]"));	
}

void VariableList::InnerSetup(){
	this->setHandleName("variableList");		
}

void VariableList::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));	
	this->getList()->addHandle(new VariableListParts);	
}

void VariableListParts::InnerSetup(){
	this->setHandleName("variableListParts");		
	this->setAllowEmpty(true);
}

void VariableListParts::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle(",",ttSymbol,","));
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));	
	
	//this->getOtherList()->addHandle(new VariableListParts2);
}

void VariableListParts2::createHandleList(){		
	this->getList()->addHandle(new VariableListParts);	
}

void TypeDef::InnerSetup(){
	this->setHandleName("typeDef");		
}

void TypeDef::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("typedef",ttKeyword,"typedef"));	
	this->getList()->addHandle(new Type);
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));		
}

void ProcedureDecl::InnerSetup(){
	this->setHandleName("procedureDecl");		
}

void ProcedureDecl::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("proc",ttKeyword,"proc"));	
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));		
	this->getList()->addHandle(new ProcedureDeclOpt);	
}

void ProcedureDeclOpt::InnerSetup(){
	this->setHandleName("procedureDeclOpt");
	this->setAllowEmpty(true);		
}

void ProcedureDeclOpt::createHandleList(){		
	this->getList()->addHandle(new ParamPart);	
}

void ProcedureDef::InnerSetup(){
	this->setHandleName("procedureDef");
}

void ProcedureDef::createHandleList(){	
	this->getList()->addHandle(new ProcedureDecl);	
	this->getList()->addHandle(new Block);		
}

void ParamPart::InnerSetup(){
	this->setHandleName("paramPart");
}

void ParamPart::createHandleList(){	
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("(",ttSymbol,"("));
	this->getList()->addHandle(new ParamPartOpt);		
	this->getList()->addHandle(hFactory.getTerminalHandle(")",ttSymbol,")"));		
}

void ParamPartOpt::InnerSetup(){
	this->setHandleName("paramPartOpt");
}

void ParamPartOpt::createHandleList(){		
	this->getList()->addHandle(new ParamDef);		
	this->getList()->addHandle(new ParamPartOptParts);		
}

void ParamPartOptParts::InnerSetup(){
	this->setHandleName("paramPartOptParts");
	this->setAllowEmpty(true);
}

void ParamPartOptParts::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle(";",ttSymbol,";"));
	this->getList()->addHandle(new ParamDef);			
	
	this->getOtherList()->addHandle(new ParamPartOptParts2);
}

void ParamPartOptParts2::createHandleList(){		
	this->getList()->addHandle(new ParamPartOptParts);			
}

void ParamDef::InnerSetup(){
	this->setHandleName("paramDef");	
}

void ParamDef::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("val",ttKeyword,"val"));
	this->getList()->addHandle(new VariableDef);
	
	this->getOtherList()->addHandle(new ParamDef2);
}

void ParamDef2::createHandleList(){		
	HandleFactory hFactory;
	this->getList()->addHandle(hFactory.getTerminalHandle("ref",ttKeyword,"ref"));
	this->getList()->addHandle(new VariableDef);
}

void StatementParts::InnerSetup(){
	this->setHandleName("statementParts");
	this->setAllowEmpty(true);	
}

void StatementParts::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(new Statement);
	this->getList()->addHandle(hFactory.getTerminalHandle(";",ttSymbol,";"));	
	
	this->getList()->addHandle(new StatementParts2);
//	this->getOtherList()->addHandle(new StatementParts2);
}

void StatementParts2::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(new Statement);
	this->getList()->addHandle(hFactory.getTerminalHandle(";",ttSymbol,";"));
	this->getList()->addHandle(new StatementParts);
}

void Statement::InnerSetup(){
	this->setHandleName("statement");	
}

void Statement::createHandleList(){		
	this->getList()->addHandle(new EmptyStatement);
	
	this->getOtherList()->addHandle(new Statement2);
	this->getOtherList()->addHandle(new Statement3);
	this->getOtherList()->addHandle(new Statement4);
	this->getOtherList()->addHandle(new Statement5);
	this->getOtherList()->addHandle(new Statement6);
	this->getOtherList()->addHandle(new Statement7);
	this->getOtherList()->addHandle(new Statement8);
	this->getOtherList()->addHandle(new Statement9);
}

void Statement2::createHandleList(){		
	this->getList()->addHandle(new ReadStatement);	
}

void Statement3::createHandleList(){		
	this->getList()->addHandle(new WriteStatement);	
}

void Statement4::createHandleList(){		
	this->getList()->addHandle(new AssignStatement);	
}

void Statement5::createHandleList(){		
	this->getList()->addHandle(new ReturnStatement);	
}

void Statement6::createHandleList(){		
	this->getList()->addHandle(new CallStatement);	
}

void Statement7::createHandleList(){		
	this->getList()->addHandle(new IfStatement);	
}

void Statement8::createHandleList(){		
	this->getList()->addHandle(new DoStatement);	
}

void Statement9::createHandleList(){		
	this->getList()->addHandle(new ForStatement);	
}

void AssignStatement::InnerSetup(){
	this->setHandleName("assignStatement");	
}

void AssignStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(new VariableAccessList);			
	this->getList()->addHandle(hFactory.getTerminalHandle(":=",ttSymbol,":="));
	this->getList()->addHandle(new ExpressionList);
}

void IfStatement::InnerSetup(){
	this->setHandleName("ifStatement");	
}

void IfStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("if",ttKeyword,"if"));
	this->getList()->addHandle(new GuardedCommandList);			
	this->getList()->addHandle(hFactory.getTerminalHandle("fi",ttKeyword,"fi"));	
}

void GuardedCommandList::InnerSetup(){
	this->setHandleName("guardedCommandList");	
}

void GuardedCommandList::createHandleList(){		
	this->getList()->addHandle(new GuardedCommand);			
	
	this->getOtherList()->addHandle(new GuardedCommandList2);
}

void GuardedCommandList2::createHandleList(){	
	this->getList()->addHandle(new GuardedCommand);
	this->getList()->addHandle(new GuardedCommandParts);
}

void GuardedCommandParts::InnerSetup(){
	this->setHandleName("guardedCommandParts");	
}

void GuardedCommandParts::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("[]",ttSymbol,"[]"));
	this->getList()->addHandle(new GuardedCommandList);				
}

void GuardedCommand::InnerSetup(){
	this->setHandleName("guardedCommand");	
}

void GuardedCommand::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(new Expression);	
	this->getList()->addHandle(hFactory.getTerminalHandle("->",ttSymbol,"->"));
	this->getList()->addHandle(new StatementParts);				
}

void DoStatement::InnerSetup(){
	this->setHandleName("doStatement");	
}

void DoStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("do",ttKeyword,"do"));
	this->getList()->addHandle(new GuardedCommandList);	
	this->getList()->addHandle(hFactory.getTerminalHandle("od",ttSymbol,"od"));	
}

void ForStatement::InnerSetup(){
	this->setHandleName("forStatement");	
}

void ForStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("forall",ttKeyword,"forall"));
	this->getList()->addHandle(new VariableAccess);	
	this->getList()->addHandle(hFactory.getTerminalHandle("->",ttSymbol,"->"));
	this->getList()->addHandle(new StatementParts);				
	this->getList()->addHandle(hFactory.getTerminalHandle("llarof",ttKeyword,"llarof"));
}

void ReturnStatement::InnerSetup(){
	this->setHandleName("returnStatement");	
}

void ReturnStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("return",ttKeyword,"return"));
	this->getList()->addHandle(new Expression);		
}

void CallStatement::InnerSetup(){
	this->setHandleName("callStatement");	
}

void CallStatement::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(new ArgumentList);	
	
	this->getOtherList()->addHandle(new CallStatement2);
}

void CallStatement2::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(hFactory.getTerminalHandle(".",ttSymbol,"."));
	this->getList()->addHandle(hFactory.getTerminalHandle("Ident",ttId,"Ident"));
	this->getList()->addHandle(new ArgumentList);	
}

void ArgumentList::InnerSetup(){
	this->setHandleName("argumentList");	
}

void ArgumentList::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("(",ttSymbol,"("));	
	this->getList()->addHandle(hFactory.getTerminalHandle(")",ttSymbol,")"));
	
	this->getOtherList()->addHandle(new ArgumentList2);
}

void ArgumentList2::createHandleList(){	
	HandleFactory hFactory;	
	this->getList()->addHandle(hFactory.getTerminalHandle("(",ttSymbol,"("));	
	this->getList()->addHandle(new ExpressionList);	
	this->getList()->addHandle(hFactory.getTerminalHandle(")",ttSymbol,")"));	
}

void Expression::InnerSetup(){
	this->setHandleName("expression");	
}

void Expression::createHandleList(){	
	this->getList()->addHandle(new RelationalExpression);
	
	this->getOtherList()->addHandle(new Expression2);
}

void Expression2::createHandleList(){	
	this->getList()->addHandle(new RelationalExpression);
	this->getList()->addHandle(new BooleanOperator);
	this->getList()->addHandle(new Expression);	
}
