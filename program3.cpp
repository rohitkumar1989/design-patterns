#include<iostream>
#include<vector>
using namespace std;
class component{
	int value;
public:	component(int val):value(val){};
 virtual	void accept(class visitor*,component*)=0;
	virtual void traverse(){
		cout<<value;
	}
};
class visitor;
class visit1;
class primitive:public component{
	public:
		   void traverse(){
			   component::traverse();
		   }
		   primitive(int val):component(val){};
		   void accept(visitor* v,component* c);
};

class composite:public component{
public:
    vector<component*> children;
	public:
		   composite(int val):component(val){}
		   void traverse(){
		    //   cout<<children.size()<<"hii";
		      component::traverse();
		      
			  for(int i=0;i<children.size();i++){
			      //cout<<"adds";
				  children[i]->traverse();
				  
			  } 
		   }
		   void add(component* c){
		       //cout<<"add";
			   children.push_back(c);
		   }
           void accept(class visitor* v,component* c );
};




class visitor{
	public:
	virtual void visit(composite* c,component* com)=0;
	virtual void visit(primitive* c,component* com)=0;
   // void visit(primitive* c,component* com);
};

class visit1:public visitor{
	public:
	void visit(composite* c,component* com){
		c->add(com);
	}
	void visit(primitive* c,component* com){
	//	c->add(com);
	}
	
};

void composite::accept(visitor* v,component* c ){
			   v->visit(this,c);
}
void primitive::accept(visitor* v,component* c ){
			   v->visit(this,c);
}

int main(){
	
	component *c[]={new composite(3), new composite(2)};
	composite *comp;
	visit1 v;
	c[0]->accept(&v,new composite(4));
		c[0]->accept(&v,new composite(8));
	comp=dynamic_cast<composite*>(c[0]);
	comp->children[0]->accept(&v,new composite(7));
//	c[0]->add(new composite(7));pointer of component type cannot access add()
// but through  visitor it can be accessed..
	c[0]->traverse();
	return 0;
}
