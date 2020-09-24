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

int H,W;
int mat[1001][1001];

int solve(){

	int res[1001][1001];
	memset(res,0,sizeof(res));
	for(int i=0;i<=1000;i++){
		if(mat[0][i]==0)
			break;
		res[0][i]=1;
	}
	for(int i=0;i<=1000;i++){
		if(mat[i][0]==0)
			break;
		res[i][0]=1;
	}

	for(int i=1;i<H;i++){
		for(int j=1;j<W;j++){
			if(mat[i][j]==0)
				res[i][j]=0;
			else{
				res[i][j]= (res[i-1][j] + res[i][j-1])%mod;
				res[i][j]%=mod;
			}
		}
	}

	return res[H-1][W-1];
}

int32_t main()
{
	cin>>H>>W;
	string str;

	for(int i=0;i<H;i++){
		cin>>str;
		for(int j=0;str[j];j++){
			if(str[j]=='#')
				mat[i][j]=0;
			else
				mat[i][j]=1;
		}
	}

	cout<<solve()<<endl;

	return 0;
}