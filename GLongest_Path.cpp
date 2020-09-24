#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001


vi adj[100001];
int dp[100001];

int solve(int src){

	if(dp[src]!=-1)
		return dp[src];

	bool isLeaf = true;
	int best = 0;
	for(auto x:adj[src]){
		isLeaf = false;
		best = max(best,solve(x));
	}
	if(isLeaf)
		return dp[src]=0;
	else
		return dp[src]= 1+best;
}

int32_t main()
{
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].pb(y);
	}

	solve(1);
	int ans=INT_MIN;
	for(int i=1;i<=100000;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;

	return 0;
}