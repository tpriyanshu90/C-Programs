/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program: Generate prime no. less than N,
* Simple method and Sieve of Eratosthenes method*
******************************************/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if(n<=1)
		return false;
	if(n<=3)
		return true;
	if(n%2==0 || n%3==0)
		return false;
	for(int i=5;i*i<=n;i+=6){
		if(n%i==0)
			return false;
	}
	return true;
}

void sieveOfEratosthenes(int n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p){
				prime[i]=false;
			}
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<' ';
	}
}
 
int main() 
{ 
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	cout<<"Prime no. less than "<<n<<" are : ";
	vector<int> v;
	v.push_back(2);
	for(int i=3;i<=n;i++){
		if(isPrime(i))
			v.push_back(i);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	cout<<"Using sieve of erathosthenes: ";
	sieveOfEratosthenes(n);
	cout<<'\n';
    return 0; 
} 