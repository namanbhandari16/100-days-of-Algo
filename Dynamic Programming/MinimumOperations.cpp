// LINK:https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)
#include <bits/stdc++.h>
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
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int ctr=0;
	    while(n){
	        if(!(n%2))
	        n/=2;
	        else
	        n-=1;
	        ctr++;
	        //cout<<"Ctr="<<ctr<<"and n="<<n<<"\n";
	    }
	    cout<<ctr<<"\n";
	}
	return 0;
}