/***************************

	QUESTION-   Powers Of Two
	Link-		https://codeforces.com/contest/1095/problem/C
	
***************************/


#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	bitset<32> t(n);
	stack<int> s;
	for(int i=0;i<32;i++){
		if(t[i]){
			s.push(1<<i);
		}
	}
	if(k<s.size() || k>n){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	while(s.size()!=k){
		int temp=s.top();
		s.pop();
		if(temp==1){
			cout<<1<<" ";
			k--;
		}
		else{
			s.push(temp/2);
			s.push(temp/2);
		}
	}
	while(s.size()!=0){
		cout<<s.top()<<" ";
		s.pop();
	}
}

/******************

	author- Pranjal_stoned

******************/