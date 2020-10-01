#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *a,int n){
    int i,j,key;
    for(i=1;i<n;i++){
       j=i-1;
       key=a[i];
       while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
       }
     a[j+1]=key;
    }

}

void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main(){
int arr[]={5,18,-2,0,6};
 int n = sizeof(arr)/sizeof(arr[0]); 
insertionSort(arr,n);
print(arr,n);
return 0;
}
