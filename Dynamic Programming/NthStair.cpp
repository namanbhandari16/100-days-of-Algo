// LINK:https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// TIME COMPLEXITY:O(N) FOR PRECALCULATING ALL ANSWERS
#include<bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
using namespace std;

int main()
 {
	fast;
	lli t,n,a,b,i,tmp;
	lli dp[100000];
	dp[0]=1,dp[1]=2;
	for(i=2;i<100000;i++)
	dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
	cin>>t;
	while(t--){
	    cin>>n;
	    cout<<dp[n-1]<<"\n";
	}
	return 0;
}