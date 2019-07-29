/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Longest Palindromic Substring using Dynamic Programming and print the substring*
* Time Complexity : O(n^2) *
* Space Complexity : O(n^2) *
*******************************************/
#include <bits/stdc++.h>
using namespace std;


string LPS(string s, int n){
    bool dp[n][n];
    int maxLen = 1;
    int PAT = 0;
    for(int i=0;i<n;i++){
        dp[i][i] = true;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            maxLen = 2;
            PAT = i;
            dp[i][i+1] = true;
        }
    }
    for(int curLen = 0; curLen<=n;curLen++){
        for(int i=0;i<n-curLen+1;i++){
            int j = i+curLen-1;
            if(s[i]==s[j]&& dp[i+1][j-1]){
                maxLen = curLen;
                PAT = i;
                dp[i][j] = true;
            }
        }
    }
    return (s.substr(PAT, maxLen+PAT));
}

int main()
{
    string s1;
    cout<<"Enter the String: ";
    cin>>s1;
    cout<<"Longest Common Substring : ";
    cout<<LPS(s1,s1.length())<<'\n';
    return 0;
}