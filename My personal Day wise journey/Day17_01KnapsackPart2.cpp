//day 17 
//01 kanpsack using bottom up dp approach
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n){
  //create a table let call it T
  int T[n+1][W+1];
  //build a table in bottom up manner
  for(int i=0;i<=n;i++){
      for(int w=0;w<=W;w++){
          if(i==0 || w==0)
              T[i][w] = 0;
          else if(wt[i-1]>W)
              T[i][w] = T[i-1][w];
          else if(wt[i-1]<=W){
              //either take it or not
              T[i][w] = max(T[i-1][w],val[i-1]+T[i-1][w-wt[i-1]]);
          }

      }
  }
  return T[n][W];
}

int main(){
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<knapSack(W,wt,val,n)<<endl;
    return 0;
}
/*
Time Complexity: O(N*W).
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W).
The use of 2-D array of size ‘N*W’.
*/