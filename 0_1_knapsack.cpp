/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : 0/1 Knapsack problem Dynamic Programming*
*******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int m,n;
    cout<<"Enter the size of Knapsack: ";
    cin>>m;
    cout<<"\nEnter the number of items: ";
    cin>>n;
    vector<int> weight(n);
    vector<int> profit(n);
    int mat[n+1][m+1];
    for(int i=0;i<n+1;i++)
    	for(int j=0;j<m+1;j++)
    		if(i==0 || j==0)
    			mat[i][j]=0;
    cout<<"\nEnter the weight of "<<n<<" items: ";
    for(int i=0;i<n;i++)
    	cin>>weight[i];
    cout<<"\nEnter the profit of "<<n<<" items: ";
    for(int i=0;i<n;i++)
    	cin>>profit[i];
    int row=1,wt=1;
    for(int row=1;row<=n;row++){
        for(int wt=1;wt<=m;wt++){
            if(wt<weight[row-1])
                mat[row][wt]=mat[row-1][wt];
            else
                mat[row][wt] = max(profit[row-1]+mat[row-1][wt-weight[row-1]], mat[row-1][wt]);
        }
    }
    cout<<"\nMaximum profit : "<<mat[n][m]<<'\n';
    return 0;
}