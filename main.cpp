#include <iostream>
#include <string>
#include "errosList.cpp"
#include "analisadorSintatico.cpp"
#include "analisadorSemantico.cpp"
#include "codigoIntermediario.cpp"
using namespace std;

void Executa(string fileName, bool imprimeArvore, bool imprimeCodigo){
	AnalisadorSintatico analSint(fileName);
	AnalisadorSemantico* analSem;
	GeradorCodigoIntermediario* codInt;
	//analSint.GeraArvoreSintatica();
	//analSint.ListaHandles();

	if (analSint.ValidaProducoes()){
		//cout << "Reconheceu!"<<endl;		
		//cout << endl;
		if(imprimeArvore){
			analSint.printArvoreSintatica();		
		}
		
		analSem = new AnalisadorSemantico(analSint.getArvoreSintatica());
		analSem->Executar();
		
		codInt = new GeradorCodigoIntermediario(analSint.getArvoreSintatica());
		codInt->Executar();
		
		if (imprimeCodigo){
			codInt->printComandos();
		}
	}else{
		cout << "Erro ao analisar sintaticamente o arquivo."<<endl;
    }    
}

int main(int argc, char** argv){
	int i;
	bool imprimeArvore = false;
	bool imprimeCodigo = false;
	string fileName;
	string com = "";
	
	if(argc>0){
		fileName = argv[1];	
		
		if(argc>=2){
			com = argv[2];			
			imprimeArvore = com=="-da";
			imprimeCodigo = com=="-di";
		}		
	}
	//for(i=1;i<argc;i++){
		
	//}

	if (fileName!=""){
		Executa(fileName, imprimeArvore, imprimeCodigo);
	}else{
		cout << "Erro: informe um arquivo para compilar." <<endl;
	}	
}

