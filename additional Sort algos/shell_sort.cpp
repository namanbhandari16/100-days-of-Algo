#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int

void swap(ll* a, ll* b){
    ll t = *a;
    *a = *b;
    *b = t;
}

int shellSort(vector<ll>& arr,ll n){
    ll gap = n/2;
    ll i,j;
    while(gap>0){
        
        for(i=0,j=gap;j<n;i++,j++){
            
            if(arr[i]>arr[j]){
                
                swap(&arr[i],&arr[j]);
                if(((i-gap)>=0)&&(arr[i-gap]>arr[i]))
                    swap(&arr[i-gap], &arr[i]);
                
            }
        }
        
        gap/=2;
        
    }
    
    return 0;
}


int main() {
	ll n,temp;
    cout<<"Enter number of elements : "<<endl;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    
    shellSort(arr, n);  
    cout << "SORTED ARRAY - ";  
    for (ll i = 0; i < n; i++)  
        cout << arr[i] << " ";
	return 0;
}