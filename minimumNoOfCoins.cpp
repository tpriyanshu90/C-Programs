/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : Minimum Number of Coins Dynamic programming *
*******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int n,sum;
    cout<<"Enter the no. of coins : ";
    cin>>n;
    int coins[n];
    cout<<"\nEnter the coins denomination: \n";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<"\nEnter the sum to be obtained: ";
    cin>>sum;
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=j;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j>=coins[i-1]){
                dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][sum]<<'\n';
    return 0;
}