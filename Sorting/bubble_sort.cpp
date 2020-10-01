#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *a,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }

    }
}

void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main(){
int arr[]={5,18,-2,0,6};
 int n = sizeof(arr)/sizeof(arr[0]); 
bubbleSort(arr,n);
print(arr,n);
return 0;
}
