#include <iostream>
#include <string>
#include <list>
using namespace std;

class Node{
	private:
		std::list<Node*> nodeList;
		std::list<Node*>::iterator it;
		Handle* handle;
		Token* token;
		Node* parentNode;
	public:
		Node(Handle* handle);
		void insertChild(Node* aNode);
		void firstChild();
		void nextChild();
		void lastChild();
		void priorChild();
		Node* getParentNode();
		Node* getChild();		
		void setParentNode(Node* parent);	
		Handle* getHandle();
		Token* getToken();		
		void setToken(Token* token);	
		bool eof();
};

Node::Node(Handle* handle){
	this->it = nodeList.begin();
	this->handle = handle;
	this->token = NULL;	
}

void Node::setToken(Token* token){
	this->token = token;
}

Handle* Node::getHandle(){
	return this->handle;
}

Token* Node::getToken(){
	return this->token;
}	

void Node::insertChild(Node* aNode){
	this->nodeList.push_back(aNode);
}

void Node::firstChild(){
	this->it = this->nodeList.begin();
}

bool Node::eof(){
	return this->it==nodeList.end();
}

void Node::nextChild(){
	this->it++;
}

void Node::lastChild(){
	this->it = this->nodeList.end();
}

void Node::priorChild(){
	this->it--;
}

Node* Node::getParentNode(){
	return this->parentNode;
}

void Node::setParentNode(Node* parent){
	this->parentNode = parent;
}

Node* Node::getChild(){
	std::list<Node*>::iterator elem;

	elem = this->it;

	return *elem;		
}
