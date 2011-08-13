using namespace std;

class Handle{
	private:
		string handleName;
		string handleDesc;
	public:
		void setHandleName(string value);
		void setHandleDesc(string value);
		string getHandleName();
		string getHandleDesc();
};

class HandleList{
	public:
		void addHandle(Handle *value);
		void nextHandle();
		void priorHandle();
		void first();
		void last();
		bool eof();		
};

class TerminalHandle{
	private:
		Token *token;
	public:
		TerminalHandle(Token *tokenValue);
};

class NonTerminalHandle{
	private:
		HandleList list;
		string production;
	public:
		void setProduction(string value);
		string getProduction();
		void createHandleList();
};

class Gramatica{
	private:
		static Gramatica *instance;
		Gramatica();
	public:		
		Gramatica getInstance();
		void registerHandle(Handle *handle);
		Handle* findHandle(string name);
};

Gramatica::Gramatica(){
}

Gramatica::getInstance(){
	if (this.instance==NULL){
		this.instance = new Gramatica();
	}
	return this.instance;
}
