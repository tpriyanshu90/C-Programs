/******************************************
* AUTHOR : PRIYANSHU TIWARI *
* NICK : tpriyanshu *
* PROGRAM : Ugly-Numbers using Dynamic Programming *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

map<int, int> mp;
map<int, int> vis;
map<int, int> state;

int solve(int i, int& count) {
	int temp = i;
	if (!vis[temp]) {
		if (i % 2 == 0)
			i = solve(i / 2, count);
		if (i % 3 == 0)
			i = solve(i / 3, count);
		if (i % 5 == 0)
			i = solve(i / 5, count);
		if (i == 1) {
			count++;
			mp[count] = temp;
			state[temp] = 1;
		}
		else {
			state[temp] = -1;
		}
		vis[temp] = 1;
	}
	return state[temp];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, count = 0;
	//store the result and provide the query throght stored results.
	cin >> n;
	for (int i = 1; count < n; i++) {
		solve(i, count);
	}
	cout << mp[n] << '\n';
	return 0;
}