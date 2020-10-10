/*

You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

*/

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
set<string> res;


// Recursive solution..!
void solve(string str,int sz,int flag){
	if(str.length()==sz){
		res.insert(str);
	}
	else
	{
		if(flag){
			str+='0';
			solve(str,sz,0);
		}
		else
		{
			solve(str+'1',sz,1);
			solve(str+'0',sz,0);
		}
	}
}


int32_t main()
{
	test
	{
		int n;cin>>n;

		int zero_ending=1,one_ending=1;
		for(int i=2;i<=n;i++){
			int temp = zero_ending;
			zero_ending+=one_ending;
			one_ending = temp;
		}

		cout<<zero_ending + one_ending<<endl;
	}
	return 0;
}
