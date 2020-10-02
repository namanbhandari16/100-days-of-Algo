// LINK:https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers/0/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1)
        cout<<n<<"\n";
        else{
            lli dp[n+1];
            dp[0]=0;
            dp[1]=1;
            cout<<dp[1]<<" ";
            for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
            cout<<dp[i]<<" ";
            }
            cout<<"\n";
        }
    }
}