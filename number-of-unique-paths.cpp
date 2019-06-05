/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int res;
int maxPaths(int i,int j, int r, int c){
    if(i==r-1&&j==c-1){
    	res+=1;
        return 1;
    }
    if(i<r-1&&j<c-1){
        maxPaths(i+1,j,r,c);
        maxPaths(i,j+1,r,c);
    }
    if(i==r-1){
        maxPaths(i,j+1,r,c);
    }
    if(j==c-1)
        maxPaths(i+1,j,r,c);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        res=0;
        cin>>a>>b;
        cout<<maxPaths(0,0,a,b)<<'\n';
    }
    return 0;
}