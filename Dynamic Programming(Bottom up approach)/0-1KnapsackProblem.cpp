#include <iostream>
using namespace std;

int knapSackDP(int wt[], int val[], int cap, int n){
	int i,j;
	int DP[n+1][cap+1];
	
	for(i=0;i<(n+1);i++){
		for(j=0;j<(cap+1);j++){
			if(i==0||j==0){
				DP[i][j] = 0;
			}
			else if(wt[i-1]<=j)
				DP[i][j] = max (val[i-1] + DP[i-1][j-wt[i-1]], DP[i-1][j]);
			else
				DP[i][j] = DP[i-1][j];
		}
	}
	return DP[n][cap];
}

int main() {
	    int n, cap,i;
	    cin>>n>>cap;
	    int val[n],wt[n];
	    for(i=0;i<n;i++)
	       cin>>val[i];
	    for(i=0;i<n;i++)
	       cin>>wt[i];
	    int x = knapSackDP(wt, val, cap, n);
	    cout<<x<<endl;
	    return 0;
	
}