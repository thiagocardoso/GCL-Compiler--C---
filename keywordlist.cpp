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
	this->keylist.insert("if");
	this->keylist.insert("for");
	this->keylist.insert("while");	
}

bool KeywordList::isKeyWord(string Value){
	this->it = this->keylist.find(Value);
	return (this->it!=this->keylist.end());
}
