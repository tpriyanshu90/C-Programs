/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
******************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int *arr = new int[n];
    vector<int> LIS(n);
    cout<<"Enter array elements : \n";
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    	LIS[i]=1;
   	for(int i=1;i<n;i++){
   		for(int j=0;j<i;j++){
   			if(arr[i]>arr[j] && LIS[i]<LIS[j]+1)
   				LIS[i]=LIS[j]+1;
   		}
   	}
   	for(int i=0;i<n;i++)
    	cout<<LIS[i]<<" ";
   	cout<<"\nLength of Longest Common Subsequence is : "<<*max_element(LIS.begin(),LIS.end())<<'\n'; 
    return 0;
}