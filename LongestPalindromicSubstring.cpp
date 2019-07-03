/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Longest Palindromic Substring using Dynamic Programming *
* Time Complexity : O(n^2) *
* Space Complexity : O(n^2) *
*******************************************/
#include <bits/stdc++.h>
using namespace std;

int DP_LPS(string s, int n){
    int dp[n][n];
    for(int i=0; i < n; i++){
            dp[i][i] = 1;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n-l + 1; i++){
            int j = i + l - 1;
            if(l == 2 && s[i] == s[j]){
                dp[i][j] = 2;
            }else if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j-1] + 2;
            }else{
                dp[i][j] = 1;
            }
        }
    }
    int maxi=INT_MIN;
    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                if(dp[i][j]>maxi)
                    maxi=dp[i][j];
            }
        }
    }
    return maxi;
}

int main()
{
    string s1;
    cout<<"Enter the String: ";
    cin>>s1;
    cout<<"Length of Longest Common Substring : ";
    cout<<DP_LPS(s1,s1.length())<<'\n';
    return 0;
}