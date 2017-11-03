/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class color{
    
    virtual void accept(class visitor* v)=0;//private pure virtual function for template design pattern...
//    virtual void example(){cout<<"edfd";}//virtual function can define its own definitionin base class {cout<<0;}
    public: 
            void accept_call_derived_template(class visitor* v){
                accept(v);
            }
};

class red: public color{
    public: 
            
            void accept(class visitor* v);
};

class blue : public color{
    public:
            void accept(class visitor* v);
};

class visitor{
    public:
            virtual void visit(blue*)=0;
            virtual void visit(red*)=0;
};

class visitor1: public visitor{
    public:
            void visit(blue* b);
            void visit(red* r);
};

class visitor2: public visitor{
    public:
            void visit(blue* b);
            void visit(red* r);
};


void red::accept(class visitor* v){
    v->visit(this);    
}
    
void blue::accept(class visitor* v){
    v->visit(this);
}
          

void visitor1::visit(blue* b){
    cout<<"visitor 1 blue"<<endl;
}
            
void visitor1::visit(red* r){
    cout<<"visitor 1 red"<<endl;
}
 
 void visitor2::visit(blue* b){
    cout<<"visitor 1 blue"<<endl;
}
            
void visitor2::visit(red* r){
    cout<<"visitor 1 red"<<endl;
}
     

int main()
{
   color *c[]={new blue, new red};
   visitor1 v1;
   visitor2 v2;
   c[0]->accept_call_derived_template(&v1);
   c[1]->accept_call_derived_template(&v2);

    return 0;
}



