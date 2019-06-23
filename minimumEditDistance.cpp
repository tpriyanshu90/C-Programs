/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : Minimum Edit Distance Dynamic programming *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    string s1,s2;
    cout<<"Enter the two strings: ";
    cin>>s1>>s2;
    int n1=s1.length();
    int n2=s2.length();
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
        }
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
                dp[i][j]=min(dp[i][j],dp[i][j-1]) + 1;
            }
        }
    }
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Minimum edits/deletes/adds : "<<dp[n1][n2]<<"\n";
    return 0;
}