#include <iostream>
#include <string>
#include "analisadorSintatico.cpp"
#include "analisadorSemantico.cpp"
using namespace std;

void Executa(string fileName){
	AnalisadorSintatico analSint(fileName);
	AnalisadorSemantico* analSem;
	//analSint.GeraArvoreSintatica();
	//analSint.ListaHandles();

	if (analSint.ValidaProducoes()){
		cout << "Reconheceu!"<<endl;		
		cout << endl;
		//analSint.printArvoreSintatica();		
		
		analSem = new AnalisadorSemantico(analSint.getArvoreSintatica());
		analSem->Executar();
	}else{
		cout << "Erro!"<<endl;
    }
    
    //system("pause");
}

int main(int argc, char** argv){
	int i;
	string fileName;
	//for(i=1;i<argc;i++){
	//	fileName = argv[i];
	//}

	//if (fileName!=""){
	//	Executa(fileName);
	//}else{
	//	cout << "Erro: informe um arquivo para compilar." <<endl;
	//}
	Executa("teste.txt");
}

