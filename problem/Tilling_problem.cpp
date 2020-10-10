/* 
Problem Statement

Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.
Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2

*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[100001];

int solve(int n,int m)
{
	if(n<0) return 0;
	else if(n==0) return 1;
	else if(dp[n]!=-1)
		return dp[n]%mod;
	else
		return dp[n]=(solve(n-1,m) + solve(n-m,m))%mod;
}
int main()
{
	int t;cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		int n,m;
		cin>>n>>m;

		cout<<solve(n,m)%mod<<endl;
	}
	return 0;
}
