#include <iostream>

using namespace std;

void check0(int);

int main(){
	int x,y;
	double d;
	int a=1;
do{
	try{
		int i;
		double* myarray;
		for(i=0;i<10000000000000;i++){
			cout<<"Allocate Memory..."<<i<<endl;
			myarray = new double[5000000];
		}
		cout<<"Enter 2 number:";
		cin>>x>>y;
		if(cin.fail()) throw 101;
		if(abs(x)>1000 ||abs(y)>1000) throw "alue out of range";
		check0(y); 
		
		//Normal Code
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
	}
	catch(const char* error){
		cerr<<error<<endl;
		a = 1;
		
		//return -1;
	}
	catch(int e){
		switch(e){
			case 101: cerr<<"Incorrect Number"<<endl;
			case 0: cerr<<"Error Divided by 0"<<endl;
		}
		cin.clear();
		cin.ignore(50,'\n');
	}
	catch(...){
		cout<<"Memory Leak"<<endl;
		a=0;

	}
}while(a);
	return 0;
}

void check0(int x){
	if(x==0) throw(x);
}
