#include <iostream>
#include <string>
#include "analisadorLexico.cpp"
using namespace std;

int main(){	
	AnalisadorLexico anaLex("teste.txt");	
	Token* myToken;
	
	
	
	while (not(anaLex.SourceEOF())){
		myToken = anaLex.getToken();	
		if (myToken != NULL){
			cout <<endl;
			switch (myToken->getTipo()){
				case ttId:
					cout << "Identificador:";
					break;
				case ttNumber:
					cout << "Número:";
					break;
				case ttKeyword:
					cout << "Palavra Reservada:";
					break;
				case ttSymbol:
					cout << "Símbolo:";
					break;
				default: break;				
			}			
			cout << myToken->getLexema()<<endl;
		}						
	}	
}

