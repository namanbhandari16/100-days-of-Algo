/***************************

	QUESTION-   Preparing Olympiad
	Link-		https://codeforces.com/contest/550/problem/B

***************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,l,r,x;
	cin>>n>>l>>r>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int count=0;
	for(int i=0;i<(1<<n);i++){
		bitset<32> t(i);
		int s=0;
		
		int min=INT_MAX,max=INT_MIN;
		for(int j=0;j<n;j++){
			if(t[j]){
				s+=arr[j];
				if(arr[j]<min){
					min=arr[j];
				}
				if(arr[j]>max){
					max=arr[j];
				}
			}
		}
		if(s<l || s>r){
			continue;
		}
		if(max-min>=x){
			count++;
		}
	}
	cout<<count;
}

/******************

	author- Pranjal_stoned

******************/