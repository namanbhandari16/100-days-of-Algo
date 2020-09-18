// learned from gfg
#include <bits/stdc++.h> 
using namespace std; 
void swap(int *n1, int *n2){
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j=low; j<=high -1; j++){
        if(arr[j]< pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return (i+1);
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        //pi is partitioning index
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter values "<<"\n";
    for(int &i : arr)cin>>i;
    quickSort(arr,0,arr.size()-1);
    cout<<"sorted array is :\n";
    for(auto i:arr)cout<<i<<" ";
    
}
