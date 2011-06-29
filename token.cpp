#include <iostream>
using namespace std;

enum tokenType {ttNone, ttKeyword, ttSymbol, ttId, ttNumber};

class Token {
	private:
		tokenType Tipo;
		string Lexema;
	public:
		void setTipo(tokenType Value);
		tokenType getTipo();
		void setLexema(string Value);
		string getLexema();
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
		Token* getToken(tokenType Tipo, string Lexema);
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

Token* TokenFactory::getToken(tokenType Tipo, string Lexema)
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
	return result;
}
