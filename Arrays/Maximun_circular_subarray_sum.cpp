
/* MY COMPETITIVE CODING TEMPLATE */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (ll)(v).size()
#define F first 
#define S second 
#define lc "\n"
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
void YJ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

/*  CODE STARTS HERE */

/* KADANE'S ALGORITHM */
int kadane(int arr[],int n) 
{ 
    int max_so_far=0,sum=0; 
    for(int i=0;i<n;i++) 
    { 
        sum+=arr[i]; 
        if(sum<0) sum=0; 
        if(max_so_far<sum) max_so_far=sum; 
    } 
    return max_so_far; 
} 

int maxCircularSum(int arr[],int n) 
{ 
    int max_sum=kadane(arr,n); 
    int s=0,i; 
    for(i=0;i<n;i++) 
    { 
        s+=arr[i]; 
        arr[i]=-arr[i]; 
    } 
    s=s+kadane(arr,n);  
    return max(s,max_sum); 
} 

int main() 
{
    YJ(); fastio
    int n,i; cin>>n; int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    cout<<"Maximum circular sum is "<<maxCircularSum(arr,n)<<lc; 
    return 0;
}