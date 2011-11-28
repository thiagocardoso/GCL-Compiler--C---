#include <iostream>
#include <string>
#include "errosList.cpp"
#include "analisadorSintatico.cpp"
#include "analisadorSemantico.cpp"
#include "codigoIntermediario.cpp"
using namespace std;

void Executa(string fileName){
	AnalisadorSintatico analSint(fileName);
	AnalisadorSemantico* analSem;
	GeradorCodigoIntermediario* codInt;
	//analSint.GeraArvoreSintatica();
	//analSint.ListaHandles();

	if (analSint.ValidaProducoes()){
		//cout << "Reconheceu!"<<endl;		
		//cout << endl;
		//analSint.printArvoreSintatica();		
		
		analSem = new AnalisadorSemantico(analSint.getArvoreSintatica());
		analSem->Executar();
		
		codInt = new GeradorCodigoIntermediario(analSint.getArvoreSintatica());
		codInt->Executar();
		
		codInt->printComandos();
	}else{
		cout << "Erro ao analisar sintaticamente o arquivo."<<endl;
    }    
}

int main(int argc, char** argv){
	int i;
	string fileName;
	for(i=1;i<argc;i++){
		fileName = argv[i];
	}

	if (fileName!=""){
		Executa(fileName);
	}else{
		cout << "Erro: informe um arquivo para compilar." <<endl;
	}	
}

