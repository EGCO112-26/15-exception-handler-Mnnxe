#include <iostream>
using namespace std;

void check0(int);
class div0 : public exception{
	public:
		virtual const char* what() const throw(){
			return "Divided by 0";
		}
};
class fail : public exception{
	public:
		virtual const char* what() const throw(){
			cin.clear();
			cin.ignore(50,'\n');
			return "Incorrect Number";
		}
};

int main(){
	int x,y;
	double d;
	int a = 1;
do{
	try{
		cout<<"Enter 2 number:";
		cin>>x>>y;
		if(cin.fail()) throw fail();
		if(abs(x)>1000 ||abs(y)>1000) throw "Value out of range";
		check0(y); 
		//Normal Code
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;

		int i;
		double* myarray;
		for(i=0;i<10;i++){
			cout<<"Allocate Memory..."<<i<<endl;
			myarray = new double[50000000000000];
		}
		a=0;
	}
	/*
	catch(const char* error){
		cerr<<error<<endl;
		a = 1;
		
		//return -1;
	}
	catch(const int e){
		switch(e){
			case 101: cerr<<"Incorrect Number"<<endl;
			case 0: cerr<<"Error Divided by 0"<<endl;
		}
		
	}
	*/

	catch(exception &e){
		cout<<e.what()<<endl;
		//a = 1;
		if (typeid(e) == typeid(bad_alloc)) {
                a = 0; 
            } else {
                a = 1; // ถ้าเป็นอย่างอื่น (div0, fail, runtime_error) ให้รันต่อ
            }
	}


}while(a);
	return 0;
}

void check0(int x){
	div0 e;
	if(x==0) throw(e);
}
