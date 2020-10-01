#define mod 1000000007
//very basic dp problem
class Solution {
  public:
    
    long long int nthFibonacci(long long int n){
        vector<long long int>fibArr(n+2);
        fibArr[0]=0;
        fibArr[1]=1;
        if(n<=2)return fibArr[n-1];
        for(long long int i=2;i<=n;i++){
            fibArr[i]=fibArr[i-1]%mod+fibArr[i-2]%mod;
        }
       //for(auto i:fibArr)cout<<i<<" ";
        return fibArr[n]%mod;
    }
};
