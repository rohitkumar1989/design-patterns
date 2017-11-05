#include<iostream>
//#include<program2.h>
using namespace std;

class element{
	const char* strelement;
    public: 
		  element(const char* str):strelement(str){}
	      virtual void accept(class visitor&)=0;	
           void print(const char* str){
			 cout<<str<<" "<<strelement<<endl;
		 }
};

class that: public element{
	public: 
		   that(const char* strtemp):element(strtemp){}
	       void accept(class visitor&);
};

class those: public element{
	public: 
	       those(const char* strtemp):element(strtemp){}
		   void accept(class visitor&);
};

class visitor{
	public:
		   virtual void visit(those*)=0;
		   virtual void visit(that*)=0;
};

class visit1:public visitor{
	public:
		   void visit(those*);
		   void visit(that*);
};		

class visit2:public visitor{
	public:
		   void visit(those*);
		   void visit(that*);
};

void those::accept(visitor& v){
	v.visit(this);
}

void that::accept(visitor& v){
	v.visit(this);
}

void visit1::visit(those* c){
		c->print("visit one");
}

void visit1::visit(that* c){
		c->print("visit two");
}

void visit2::visit(those* c){
		c->print("visit one");
}

void visit2::visit(that* c){
		c->print("visit two");
}


int main()
{
	visit1 v1;
	visit2 v2;
	volatile int size=4;
	element *e[size]={new that("that"),new those("those"),new that("that"),new those("those")};
	//element *e[size]={new that("that"),new those("those"),&that("that"),new those("those")};
	//cannot take address of temporary object
	for(int i=0;i<size;i++)
	{
		e[i]->accept(v1);	//can not address usung *e[i].accept(V1)
		e[i]->accept(v2);	
				
	}
	
	
	return 0;
}