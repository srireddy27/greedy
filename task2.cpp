#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,int> pli;
const int MAXN = 205;
bool mark[MAXN];
long long int len[MAXN], val[MAXN], cval[MAXN];
int nxt[MAXN];
vector <int> f(vector <int> &a, vector <int> &b)
{
	int n = a.size(), m = b.size();
	vector < vector <long long int> > dp(n+1, vector <long long int> (m+1,0));
	vector <long long int> t1(n+1,0), t2(m+1,0);
	for (int i = 0; i < a.size(); ++i)
	{
		t1[i+1] = t1[i] + len[a[i]];
	}
	for (int i = 0; i < b.size(); ++i)
	{
		t2[i+1] = t2[i] + len[b[i]];
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if(!i && !j)
				continue;
			long long int ct = (t1[i] + t2[j]);
			if(i && j)
				dp[i][j] = min(dp[i-1][j] + ct*val[a[i-1]], dp[i][j-1] + ct*val[b[j-1]]);
			else if(!i)
				dp[i][j] = dp[i][j-1] + ct*val[b[j-1]];
			else
				dp[i][j] = dp[i-1][j] + ct*val[a[i-1]];
		}
	}
	vector <int> ret;
	int x = n, y = m;
	while(x > 0 || y > 0)
	{
		if(x == 0)
		{
			ret.push_back(b[y-1]);
			y--;
			continue;
		}
		if(y == 0)
		{
			ret.push_back(a[x-1]);
			x--;
			continue;
		}
		long long int ct = (t1[x] + t2[y]);
		if(dp[x][y] == dp[x-1][y] + ct*val[a[x-1]])
		{
			ret.push_back(a[x-1]);
			x--;
			continue;
		}
		else
		{
			ret.push_back(b[y-1]);
			y--;
			continue;
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int n;
		cin>>n;
		for (int i = 1; i <= n; ++i)
		{
			cin>>len[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin>>val[i];
		}
		int m;
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			cin>>u>>v;
			nxt[u] = v;
			mark[v] = true;
		}
		vector < vector <int> > chains;
		for (int i = 1; i <= n; ++i)
		{
			if(!mark[i])
			{
				vector <int> temp;
				int pos = i;
				while(pos)
				{
					temp.push_back(pos);
					pos = nxt[pos];
				}
				chains.push_back(temp);
			}
		}
		while(chains.size() > 1)
		{
			vector <int> temp = chains.back();
			chains.pop_back();
			chains[0] = f(chains[0],temp);
		}
		long long int fans = 0, ft = 0;
		for (int i = 0; i < chains[0].size(); ++i)
		{
			ft+=len[chains[0][i]];
			fans+=(ft*val[chains[0][i]]);
		}
		cout<<"Case "<<case_num<<": "<<fans<<"\n";
		// cleanup
		memset(mark, false, sizeof mark);
		memset(nxt, 0, sizeof nxt);
	}
	return 0;
}
