using namespace std;

class Variavel {
	private:
		string name;
	protected:
		void setName(string value);
	public:
		string getName();		
};

class ListaVariavel {
	private:
		std::list<Variavel*> lista;
		std::list<Variavel*>::iterator iter;		
	public:
		void first();
		void next();
		void last();
		void prior();
		bool eof();
		bool isEmpty();
		void addVariavel(Variavel* variavel);
		Variavel* getVariavel();	
		int size();
};

string Variavel::getName(){
	return this->name;
}

void Variavel::setName(string value){
	this->name = value;
}

void ListaVariavel::first(){
	this-> iter = this->lista.begin();
}

void ListaVariavel::next(){
	this-> iter++;
}

void ListaVariavel::last(){
	this-> iter = this->lista.end();
}

void ListaVariavel::prior(){
	this->iter--;
}

bool ListaVariavel::eof(){
	return this-> iter == this->lista.end();
}

bool ListaVariavel::isEmpty(){
	return this->lista.empty();
}

void ListaVariavel::addVariavel(Variavel* variavel){
	this->lista.push_back(variavel);
}

Variavel* ListaVariavel::getVariavel(){
	std::list<Variavel*>::iterator item;

	item = this -> iter;
	
	return *item;
}

int ListaVariavel::size(){
	return this->lista.size();
}
