/***************************

	QUESTION-   Petr and a Combination Lock
	Link-		https://codeforces.com/contest/1097/problem/B

***************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int f=0;
	for(int i=0;i<(1<<n);i++){
		bitset<32> t(i);
		int s=0;
		
		for(int j=0;j<n;j++){
			if(t[j]){
				s+=arr[j];
			}
			else{
				s-=arr[j];
			}
			if(s>=360){
				s-=360;
			}
			if(s<0){
				s+=360;
			}
		}
		
		if(s==0){
			f=1;
		}
	}
	if(f){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
}

/******************

	author- cybertron00

******************/