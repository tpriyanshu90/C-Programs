/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* Program : Coin Changing Number of ways to get total dynamic programming *
*******************************************/
#include <bits/stdc++.h>
using namespace std;

int findWays(int coins[],int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j]=0;
            else if(j==0)
                dp[i][j]=1;
        }
    }
    for (int i = 1; i <=n; i++)
    {
        for(int j=1;j<=sum;j++){
            if(j>=coins[i-1])
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n,sum;
    cout<<"Enter no. of Coins : ";
    cin>>n;
    cout<<"Enter the denomination of coins : ";
    int coins[n];
    for (int i = 0; i < n; i++)
        cin>>coins[i];
    cout<<"Enter the sum to be obtained : ";
    cin>>sum;
    cout<<"\nNo of ways to get a sum of "<<sum<<" is : "<<findWays(coins,n,sum)<<'\n';
    return 0;
}