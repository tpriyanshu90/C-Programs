/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : ADD OR SUBTARCT WITHOUT ARITHMETIC OPERATORS *
******************************************/
#include <bits/stdc++.h>
using namespace std;

int add(int a, int b){
	while(b!=0){
		int carry = a&b;
		a = a^b;
		b = carry<<1;
	}
	return a;
}

int sub(int a, int b){
	while(b!=0){
		int borrow = (~a)&b;
		a = a^b;
		b = borrow<<1;
	}
	return a;
}


int main()
{
	int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    cout<<"Sum : "<<add(a,b);
    cout<<"\nSubtraction : "<<sub(a,b)<<'\n';
    return 0;
}