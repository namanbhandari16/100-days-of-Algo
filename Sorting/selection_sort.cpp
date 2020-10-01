#include<bits/stdc++.h>
using namespace std;


void selectionSort(int *a,int n){
    int i,j,key;
    for(i=0;i<n-1;i++){
      int min_index = i;

        for(j=i+1;j<n;j++){
            if(a[j]<a[min_index])
                min_index=j;
        }
      swap(a[i],a[min_index]);
    }
}

void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}

int main(){

int arr[]={5,1,2,0,6};
int n = sizeof(arr)/sizeof(arr[0]); 
selectionSort(arr,n);
print(arr,n);
return 0;
}
