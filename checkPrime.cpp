/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program: Check whether a number is prime *
******************************************/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;  
    return true; 
} 
  
  
// Driver Program to test above function 
int main() 
{ 
	int a,b;
	cin>>a>>b;
    isPrime(a)?  cout << " true\n": cout << " false\n"; 
    isPrime(b)?  cout << " true\n": cout << " false\n"; 
    return 0; 
} 