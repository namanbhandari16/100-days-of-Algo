// Author - @pranav230
// Problem : Set and Unset the nth bit from right in the given number

#include<bits/stdc++.h>

using namespace std;

int32_t main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	
	int x,y;
	cout<<"Enter the bit to set: ";
	cin>>x;
	
	cout<<"Enter the bit to erase or unset: ";
	cin>>y;
	
	cout<<"Number with set bit is: "<<(n | (1<<(x-1))<<endl;
	
	cout<<"Number with unset bit is: "<<(n & ~(1<<(y-1)))<<endl;
	
    return 0;
}

