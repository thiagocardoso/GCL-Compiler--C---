#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class ReadBuffer {
	private:
		ifstream SourceFile;
		int FilePos;
		int BufferPos;
		int LineNumber;
		int ColNumber;
		string BufferRead;
		string BufferWrite;
	protected:
		void LoadBuffer();		
	public:
		ReadBuffer();	
		~ReadBuffer();
		int getLineNumber();
		int getColNumber();		
		void OpenFile(string SourceName);
		void CloseFile();
		void AddToBuffer(char Value);
		void ClearBuffer();
		void PriorColNumber();
		bool IsFileOpen();
		bool IsFileGood();
		bool IsBufferWriteEmpty();
		bool IsBufferEmpty();
		string getBuffer();	
		char getLastCharOnBuffer();
		char getChar();
		 
};

ReadBuffer::ReadBuffer(){	
	this->FilePos = 0;
	this->BufferPos = 0;		
	this->LineNumber = -1;
	this->ColNumber = -1;
	this->BufferRead = "";
	this->BufferWrite = "";
}

ReadBuffer::~ReadBuffer(){
	if (this->IsFileOpen()){
		this->SourceFile.close();	
	}
}

int ReadBuffer::getLineNumber(){
	return this->LineNumber;
}

int ReadBuffer::getColNumber(){
	return this->ColNumber;
}		

void ReadBuffer::OpenFile(string SourceName){
	this->SourceFile.open(SourceName.c_str());	
}

void ReadBuffer::CloseFile(){
	this->SourceFile.close();
}

void ReadBuffer::PriorColNumber(){
	this->ColNumber--;
}

bool ReadBuffer::IsFileOpen(){
	return (this->SourceFile.is_open());
}

bool ReadBuffer::IsBufferEmpty(){
	return (this->BufferRead.empty());
}

bool ReadBuffer::IsFileGood(){
	return (this->SourceFile.good());
}

void ReadBuffer::LoadBuffer(){
	getline(this->SourceFile, this->BufferRead);
	this->ColNumber = -1;
	this->LineNumber++;	
}

char ReadBuffer::getChar(){
	if ((this->IsBufferEmpty())or(this->ColNumber==this->BufferRead.size())){
		this->LoadBuffer();
	}	
	this->ColNumber++;
	return this->BufferRead[this->ColNumber];
}

char ReadBuffer::getLastCharOnBuffer(){
	return this->BufferWrite[this->BufferWrite.size()-1];
}

void ReadBuffer::AddToBuffer(char Value){
	this->BufferWrite += Value;
}

void ReadBuffer::ClearBuffer(){
	this->BufferWrite = "";
}

string ReadBuffer::getBuffer(){
	return this->BufferWrite;
}

bool ReadBuffer::IsBufferWriteEmpty(){
	return (this->BufferWrite.empty());
}

