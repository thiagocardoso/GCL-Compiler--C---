#include <set>
using namespace std;

class KeywordList{
	private:
		std::set<string> keylist;
		std::set<string>::iterator it;
	protected:
		void SetupList();
	public:
		KeywordList();
		bool isKeyWord(string Value);
};

//Implementações KeywordList
KeywordList::KeywordList(){
	this->SetupList();
}

void KeywordList::SetupList(){
	this->keylist.insert("module");
	this->keylist.insert("private");
	this->keylist.insert("end");
	this->keylist.insert("const");
	this->keylist.insert("Boolean");
	this->keylist.insert("integer");
	this->keylist.insert("begin");
	this->keylist.insert("typedef");
	this->keylist.insert("array");
	this->keylist.insert("range");	
    this->keylist.insert("proc");
	this->keylist.insert("val");
	this->keylist.insert("ref"); 
	this->keylist.insert("return"); 
	this->keylist.insert("write"); 
	this->keylist.insert("read"); 
	this->keylist.insert("if"); 
	this->keylist.insert("fi"); 
	this->keylist.insert("do"); 
	this->keylist.insert("od"); 
	this->keylist.insert("true"); 
	this->keylist.insert("false"); 
	this->keylist.insert("forall"); 
	this->keylist.insert("llarof"); 
	this->keylist.insert("skip");
}

bool KeywordList::isKeyWord(string Value){
	this->it = this->keylist.find(Value);
	return (this->it!=this->keylist.end());
}
