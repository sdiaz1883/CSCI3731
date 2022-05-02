#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#define LSIZ 128 
#define RSIZ 10 
using namespace std;

class FileStreamBuf : public streambuf{
	public:
	FILE * pFile;
   	char buffer [100];
   	static const int array = 5;
   	
	FileStreamBuf(FILE * file){
		this->pFile =file;
		setp(&buffer[0],&buffer[array]);
		setg(&buffer[0],&buffer[array],&buffer[array]);
	}
	
	virtual int underflow()
	{
		
    	int i = 0;
		while(fgets(&buffer[i], LSIZ, pFile)) 
		{
	        i++;
	    }
	    setg(&buffer[i],&buffer[i+1],&buffer[array]);
	    return i;
	}
	
	virtual int uflow()
	{
		int i = 0;
		while(fgets(&buffer[i], LSIZ, pFile)) 
		{
	        i++;
	    }
	    setg(&buffer[i],&buffer[i+1],&buffer[array]);
	    return i;
	}
	
	virtual int overflow(int c) 
	{
		char p = c;
		buffer[0] = p;
		setp(&buffer[0],&buffer[array]);
		return c;			
	}
	virtual int sync(){
		
		char* ptr = pptr();
		setp(ptr,&buffer[array]);
		return 0;
	}
	~FileStreamBuf(){
		fclose(pFile);
	}
};

int main()
{
	fstream  afile;
	FILE* file = fopen("file.txt","r");
	FileStreamBuf* fsb = new FileStreamBuf(file);
	ostream* os = new ostream(fsb);
	return 0;
}
