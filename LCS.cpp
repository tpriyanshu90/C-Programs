/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Longest Common Subsequence *
*******************************************/
#include <bits/stdc++.h>
using namespace std;

//Iterative Method
int LCS(string s1, string s2, int i, int j){
	if(s1[i]=='\0' || s2[j]=='\0')
		return 0;
	else if(s1[i]==s2[j])
		return 1+LCS(s1,s2,i+1,j+1);
	else{
		return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
	}
}

//Dynamic Programming Method
int DP_LCS(string s1, string s2, int m, int n) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (s1[i-1] == s2[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     return L[m][n]; 
} 

int main()
{
    string s1,s2;
    cout<<"Enter First String: ";
    cin>>s1;
    cout<<"Enter Second String: ";
    cin>>s2;
    cout<<"Iterative Answer : ";
    cout<<LCS(s1,s2,0,0)<<'\n';
    cout<<"Dynamic Programming Answer : ";
    cout<<DP_LCS(s1,s2,s1.length(),s2.length())<<'\n';
    return 0;
}