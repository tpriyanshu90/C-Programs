/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;
#define mod 1000000007

ul fast_power(ul base, ul power){
	ul res=1;
	while(power>0){
		if(power&1)
			res=(res*base)%mod;
		base=(base*base) % mod;
		power>>=1;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<fast_power(2,100)<<'\n';
    return 0;
}