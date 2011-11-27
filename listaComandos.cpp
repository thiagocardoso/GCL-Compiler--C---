using namespace std;

class Comando {
};

class ListaComando {
	private:
		std::list<Comando*> lista;
		std::list<Comando*>::iterator iter;		
	public:
		void first();
		void next();
		void last();
		void prior();
		bool eof();
		bool isEmpty();
		void addComando(Comando* comando);
		Comando* getComando();	
		int size();
};

void ListaComando::first(){
	this-> iter = this->lista.begin();
}

void ListaComando::next(){
	this-> iter++;
}

void ListaComando::last(){
	this-> iter = this->lista.end();
}

void ListaComando::prior(){
	this->iter--;
}

bool ListaComando::eof(){
	return this-> iter == this->lista.end();
}

bool ListaComando::isEmpty(){
	return this->lista.empty();
}

void ListaComando::addComando(Comando* comando){
	this->lista.push_back(comando);
}

Comando* ListaComando::getComando(){
	std::list<Comando*>::iterator item;

	item = this -> iter;
	
	return *item;
}

int ListaComando::size(){
	return this->lista.size();
}
