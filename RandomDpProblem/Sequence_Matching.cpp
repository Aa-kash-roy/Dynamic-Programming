// link : https://atcoder.jp/contests/abc185/tasks/abc185_e
/* 
  It is based on considering all choices possible i.e Pruning all cases to get the optimal value.
  Similar to knapsack type.
  
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define MAXN        200001

typedef tree<int, null_type, 
     less_equal<int>, rb_tree_tag,
          tree_order_statistics_node_update> 
    Ordered_set; 
// s.find_by_order(idx) find using index..!
// s.order_of_key(val) Gives iterator to the key..! 

/* First solve then try Writing Code.. And be cool ^_^ and calm. */

int n, m, a[1005], b[1005], dp[1005][1005]; 

int go(int l, int r)
{
    if(l==0)
        return r;
    if(r==0)
        return l;

    if(dp[l][r] != -1)
        return dp[l][r];
    if(a[l-1] == b[r-1])
        return dp[l][r] = go(l-1, r-1);
    else
    {
        int op1 = 1 + go(l-1, r-1);
        int op2 = min(go(l-1, r), go(l, r-1)) + 1;

        return dp[l][r] = min(op1, op2);
    }
}

void solve(){

    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];

    cout<<go(n,m)<<endl;
}

int32_t main()
{    
    int t=1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}
