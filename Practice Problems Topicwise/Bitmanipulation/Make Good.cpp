/***************************

	QUESTION-   Make Good
	Link-		https://codeforces.com/contest/1270/problem/C
	
***************************/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		ll sum=0;
		ll sum_xor=0;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			sum_xor^=arr[i];
		}
		
		cout<<2<<endl;
		cout<<sum_xor<<" "<<(sum+sum_xor)<<endl;
	}	
}

/******************

	author- Pranjal_stoned

******************/