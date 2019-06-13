/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : FIND MAXIMUM SUBARRAY SUM USING KDANE's ALGORITHM *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int findMaxSubArrSum(vector<int> v){
	int max_current,max_global;
	max_current=max_global=v[0];
	for(int i=1;i<v.size();i++){
		max_current=max(v[i],v[i]+max_current);
		if(max_current>max_global)
			max_global=max_current;
	}
	return max_global;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"\nEnter the array elements: \n";
    for(int i=0;i<n;i++)
    	cin>>v[i];
    cout<<"The maximum subarray sum is: "<<findMaxSubArrSum(v)<<'\n';
    return 0;
}