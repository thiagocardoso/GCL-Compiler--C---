#include <iostream>
#include <string>
using namespace std;

class Node {
	private:
		string Name;
		Node *LeftChild;
		Node *RightChild;
		
	public:
		void setName(string Value);
		void setLeftChild(Node *node);
		void setRightChild(Node *node);		
		string getName(); 
		Node* getLeftChild();
		Node* getRightChild();
		void AddLeftChild(string Name);
		void AddRightChild(string Name);
		bool HasLeftChild();
		bool HasRightChild();
};

void Node::setName(string Value)
{
	this->Name = Value;
}

void Node::setLeftChild(Node *node)
{
	this->LeftChild = node;
}

void Node::setRightChild(Node *node)
{
	this->RightChild = node;
}
		
string Node::getName()
{
	return this->Name;
}
 
Node* Node::getLeftChild()
{
	return this->LeftChild;
}

Node* Node::getRightChild()
{
	return this->RightChild;
}

void Node::AddLeftChild(string Name)
{	
	Node *node;
	
	if (not(this->HasLeftChild())){	
		node = new Node();
		node->setName(Name);
		this->setLeftChild(node);
	}
}

void Node::AddRightChild(string Name)
{
	Node *node;
	
	if (not(this->HasLeftChild())){	
		node = new Node();
		node->setName(Name);
		this->setRightChild(node);
	}
}

bool Node::HasLeftChild()
{
	if (this->LeftChild == NULL)
		return false;
	else
		return true;
	//return this->LeftChild != NULL;
}

bool Node::HasRightChild()
{
	if (this->RightChild == NULL)
		return false;
	else
		return true;
	//return this->RightChild != NULL;
}
