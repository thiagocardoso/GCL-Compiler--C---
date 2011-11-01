#include <iostream>
using namespace std;

enum tokenType {ttNone, ttKeyword, ttSymbol, ttId, ttNumber};

class Token {
	private:
		tokenType Tipo;
		string Lexema;
		string ErrorMessage;
		int line;
		int column;
	public:
		void setTipo(tokenType Value);
		tokenType getTipo();
		void setLexema(string Value);
		string getLexema();
		void setLine(int Value);
		int getLine();
		void setColumn(int Value);
		int getColumn();
		string getErrorMessage();
		void setErrorMessage(string value);
};

class TokenNumber: public Token {
	public:
		TokenNumber();		
};

class TokenSymbol: public Token {
	public:
		TokenSymbol();		
};

class TokenID: public Token {
	public:
		TokenID();		
};

class TokenKeyword: public Token {
	public:
		TokenKeyword();		
};

class TokenFactory {
	public:
		Token* getToken(tokenType Tipo, string Lexema, int line, int column);
};

//Implementações

void Token::setTipo(tokenType Value)
{
	this->Tipo = Value;
}

tokenType Token::getTipo()
{
	return this->Tipo;
}

void Token::setLexema(string Value)
{
	this->Lexema = Value;
}

string Token::getLexema()
{
	return this->Lexema;
}

TokenNumber::TokenNumber()
{		
	this->setTipo(ttNumber);
}

TokenSymbol::TokenSymbol()
{	
	this->setTipo(ttSymbol);	
}

TokenID::TokenID()
{		
	this->setTipo(ttId);
}

TokenKeyword::TokenKeyword()
{		
	this->setTipo(ttKeyword);
}

Token* TokenFactory::getToken(tokenType Tipo, string Lexema, int line, int column)
{
	Token* result;
	switch (Tipo) {
		case ttId: 
			result = new TokenID();
			break;
		case ttNumber: 
			result = new TokenNumber();
			break;			
		case ttSymbol: 
			result = new TokenSymbol();
			break;	
		case ttKeyword: 
			result = new TokenKeyword();
			break;
		default:
			result = NULL;
			break;
	}
	
	result->setLexema(Lexema);
	result->setLine(line);
	result->setColumn(column);	
	return result;
}


void Token::setLine(int Value){
	this->line = Value;
}

int Token::getLine(){
	return this->line;
} 
	
void Token::setColumn(int Value){
	this->column = Value;
}	

int Token::getColumn(){
	return this->column;	
}	

string Token::getErrorMessage(){
	return this->ErrorMessage;
}

void Token::setErrorMessage(string value){
	this->ErrorMessage = value;
}
	
