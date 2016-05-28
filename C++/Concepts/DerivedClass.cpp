#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

class Base {
    int priv_;

public:
	int foo_;

    virtual void setDer( int )  = 0;
    virtual int getDer( void ) const = 0;
    
    virtual void setFoo( int )  = 0;
    virtual int getFoo( void ) const = 0; 

};

class Derived : public Base {
    int der_;
    
public:
    virtual void setDer( int temp ) {
        der_ = temp;
    }

    virtual int getDer( void ) const {
        return der_;
    }     

    virtual void setFoo( int temp ) {
        foo_ = temp;
    }

    virtual int getFoo( void ) const {
        return foo_;
    }

};

int main(){
    Derived *a = new Derived() ;

    Base *b = NULL;
    a->setDer(10);
    cout << endl;
    cout << a->getDer() << endl;

    a->setFoo(5);
    cout << a->getFoo()<<endl;

    b = a;
    cout << b->getDer();
	return 0;
}
