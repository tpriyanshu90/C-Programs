/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM: GENERATE POWERSET USING BACKTRACKING*
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void printSet(vector<int> v){
	for(auto i: v)
		cout<<i<<" ";
	cout<<'\n';
}

void backtrack(vector<int> const iniSet, vector<int>& subset, int n){
	if(n==0){
		printSet(subset);
		return;
	}
	subset.push_back(iniSet[n-1]);
	backtrack(iniSet,subset,n-1);
	subset.pop_back();
	backtrack(iniSet,subset,n-1);
}

int main()
{
    int n;
    cout<<"Enter the no. of elements in set: ";
    cin>>n;
    vector<int> v(n);
    vector<int> powSet;
    for(int i=0;i<n;i++)
    	cin>>v[i];
    cout<<"\nThe subsets are: \n";
    backtrack(v,powSet,v.size());
    return 0;
}