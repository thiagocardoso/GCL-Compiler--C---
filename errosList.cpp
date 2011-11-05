#include <list>
#include <string>
using namespace std;

class ListaErros{
	private: 
		static ListaErros *instance;
		ListaErros(){};

		std::list<string> lista;
		std::list<string>::iterator iter;
		
	public:
		void first();
		void next();
		void last();
		void prior();
		bool eof();
		bool isEmpty();
		void addErro(string Erro);
		string getErro();	
		int size();
		
		static ListaErros *getInstance();

};

ListaErros *ListaErros::instance = 0; 


ListaErros *ListaErros::getInstance(){
	if (!instance) instance = new ListaErros();
	return instance;	
};

void ListaErros::first(){
	this-> iter = this->lista.begin();
};

void ListaErros::next(){
	this-> iter++;
};

void ListaErros::last(){
	this-> iter = this->lista.end();
};

void ListaErros::prior(){
	this->iter--;
};

bool ListaErros::eof(){
	return this-> iter == this->lista.end();
};

bool ListaErros::isEmpty(){
	return this->lista.empty();
};

void ListaErros::addErro(string Erro){
	this->lista.push_back(Erro);
};

string ListaErros::getErro(){
	std::list<string>::iterator item;

	item = this -> iter;
	
	return *item;
};

int ListaErros::size(){
	return this->lista.size();
};
