#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include "token.cpp"
#include "readbuffer.cpp"
#include "keywordlist.cpp"
using namespace std;

enum lexState {S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, 
			   S13, S14};

class AnalisadorLexico {
	private:
		ReadBuffer ReadBuf;
		string FileName;
		string DataBlock;
		string Buffer;
		lexState Estado;	
		bool ValidToken;
		tokenType CurrentTokenType;
		KeywordList palavrasReservadas;		
	protected:
		bool IsValidChar(char Value);
		void Automato(char Value);
		void TrataIdentificador(char Value);
		void TrataDigito(char Value);
		void TrataSimbolo(char Simbolo);
		void TokenFound();		
	public:
		AnalisadorLexico(string NomeArquivo);
		~AnalisadorLexico();
		void setFileName(string Value);
		string getFileName();				
		Token* getToken();
		bool SourceEOF();
};

AnalisadorLexico::AnalisadorLexico(string NomeArquivo){
	this->setFileName(NomeArquivo);
	Estado = S0;
	Buffer = "";
	DataBlock = "";	
	ValidToken = false;
	CurrentTokenType = ttNone;
	this->ReadBuf.OpenFile(NomeArquivo);
}

AnalisadorLexico::~AnalisadorLexico(){	
	this->ReadBuf.CloseFile();
}

void AnalisadorLexico::setFileName(string Value)
{
	this->FileName = Value;
}

bool AnalisadorLexico::SourceEOF(){
	return not(this->ReadBuf.IsFileGood());
}

string AnalisadorLexico::getFileName()
{
	return this->FileName;
}

bool AnalisadorLexico::IsValidChar(char Value){
	bool isValid = false;
	isValid = (Value!=' ');
	isValid = int(Value) > 32;
	return isValid;
}

Token* AnalisadorLexico::getToken(){
	TokenFactory tkFactory;		
	Token* returnToken = NULL;
	
	while ((this->ReadBuf.IsFileGood())and(not(this->ValidToken))){	
		this->Automato(this->ReadBuf.getChar());
	}
	
	if (this->ValidToken){
		returnToken = tkFactory.getToken(this->CurrentTokenType, this->ReadBuf.getBuffer());
	}
	
	this->ValidToken = false;
	return returnToken;
}

void AnalisadorLexico::TrataSimbolo(char Simbolo){
	switch (Simbolo){
		case '.': // .
		//case '.': 
		case '=': break;
		case ':': // =  		
		case '-': // - //>
		//case '-':
		case ',': break;  
		case ';': break;  
		case '(': break; 
		case ')': break; 
		case '[': // ] 
		//case '[': 
		//case ']':		
		case '#': break;   
	    case '<': // =
	    case '>': // =  
	    case '&': break;   
	    case '|': break;  
	    case '~': break;  
	    case '+': break;   	    
	    case '*': break;   
	    case '/': break;   
	    case '\'': break;	    
	    default: break;
	}
}

void AnalisadorLexico::TokenFound(){
	ValidToken = true;
	Estado = S0;	
	this->ReadBuf.PriorColNumber();	
	
	if(this->palavrasReservadas.isKeyWord(this->ReadBuf.getBuffer())){
		this->CurrentTokenType = ttKeyword;
	}
}

void AnalisadorLexico::TrataIdentificador(char Value){
	if ((isalpha(Value))or(isdigit(Value))){
		this->ReadBuf.AddToBuffer(Value);
	}else{
		if ((Value=='_')and(this->ReadBuf.getLastCharOnBuffer()!='_')){
			this->ReadBuf.AddToBuffer(Value);			
		}else{	
			//devolve identificador no buffer e volta pra S0
			this->TokenFound();
		}
	}	
}

void AnalisadorLexico::TrataDigito(char Value){
	if (isdigit(Value)){
		this->ReadBuf.AddToBuffer(Value);
	}else{
		//devolve digito no buffer e volta pra S0
		this->TokenFound();
	}	
}

void AnalisadorLexico::Automato(char Value){
	switch (Estado) {
		case S0:{
			if (this->IsValidChar(Value)){
				this->ReadBuf.ClearBuffer();
				if (isalpha(Value)){		
					this->CurrentTokenType = ttId;			
					Estado = S1;					
					this->Automato(Value);
				}else{
					if (isdigit(Value)){						
						this->CurrentTokenType = ttNumber;
						Estado = S2;												
						this->Automato(Value);
					}else{
						this->CurrentTokenType = ttSymbol;
						//cout << 'Teste: ' << (int) Value << endl;
						this->TrataSimbolo(Value);
					}
				}
			}			
			break;
		}
		case S1:{
			this->TrataIdentificador(Value);
			break;
		}
		case S2:{
			this->TrataDigito(Value);
			break;
		}		
		default: break;
	}
}
