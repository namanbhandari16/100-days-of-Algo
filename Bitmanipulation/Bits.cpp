/***************************

	QUESTION-   Bits
	Link-		https://codeforces.com/contest/484/problem/A
	
***************************/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		ll l,r;
		cin>>l>>r;
		for(ll i=1;(l|i)<=r;i=i<<1){
			l=l|i;
		}
		cout<<l<<endl;
	}
}

/******************

	author- Pranjal_stoned

******************/