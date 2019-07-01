/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Longest Palindromic Subsequence using Dynamic Programming *
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
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    string s1;
    cout<<"Enter the String: ";
    cin>>s1;
    cout<<"Length of Longest Common Subsequence : ";
    cout<<DP_LPS(s1,s1.length())<<'\n';
    return 0;
}