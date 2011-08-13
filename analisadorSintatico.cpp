#include <string.h>
#include "analisadorLexico.cpp"
#include "producao.cpp"
using namespace std;

class ArvoreSintaticaAbstrata {
};

class AnalisadorSintatico {
	private:
		ArvoreSintaticaAbstrata arvore;
		AnalisadorLexico *anaLexico;
	public:
		AnalisadorSintatico(string caminhoArquivo);
		~AnalisadorSintatico();
		ArvoreSintaticaAbstrata getArvoreSintatica();
		void GeraArvoreSintatica();
};

AnalisadorSintatico::AnalisadorSintatico(string caminhoArquivo){
	this->anaLexico = new AnalisadorLexico(caminhoArquivo);
}

AnalisadorSintatico::~AnalisadorSintatico(){	
}

ArvoreSintaticaAbstrata AnalisadorSintatico::getArvoreSintatica(){
	return arvore;
}

void AnalisadorSintatico::GeraArvoreSintatica(){
	Token* myToken;	
	
	while (not(this->anaLexico->SourceEOF())){
		myToken = this->anaLexico->getToken();	
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
			cout << myToken->getLexema()<< " linha: "<< myToken->getLine() << " coluna:"<< myToken->getColumn() <<endl;
		}						
	}			
}
