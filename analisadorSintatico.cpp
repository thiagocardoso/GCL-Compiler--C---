#include <string.h>
#include "token.cpp"
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
		AnalisadorSintatico();
		~AnalisadorSintatico();		
};

AnalisadorSintatico::AnalisadorSintatico(){
	this->anaLexico = new AnalisadorLexico("teste.txt");
}

AnalisadorSintatico::~AnalisadorSintatico(){	
}
