/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Longest Common Substring using Dynamic Programming *
*******************************************/
#include <bits/stdc++.h>
using namespace std;


int DP_LCSubstring(string s1, string s2, int m, int n) 
{ 
   int L[m+1][n+1]; 
   int i, j,maxi; 
   for (i=0; i<=m; i++) 
    { 
      for (j=0; j<=n; j++) 
      { 
         if (i == 0 || j == 0) 
          L[i][j] = 0; 
   
         else if (s1[i-1] == s2[j-1]) 
           L[i][j] = L[i-1][j-1] + 1; 
   
         else
           L[i][j] = 0; 
      } 
   } 
    maxi=L[0][0];
    for (i=1; i<=m; i++) 
    { 
      for (j=1; j<=n; j++) 
      { 
         if(L[i][j]>maxi)
          maxi=L[i][j];
      } 
   }
    return maxi;
} 

int main()
{
    string s1,s2;
    cout<<"Enter First String: ";
    cin>>s1;
    cout<<"Enter Second String: ";
    cin>>s2;
    cout<<"Length of Longest Common Substring : ";
    cout<<DP_LCSubstring(s1,s2,s1.length(),s2.length())<<'\n';
    return 0;
}