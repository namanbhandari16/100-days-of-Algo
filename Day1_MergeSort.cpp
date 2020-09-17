// learned from gfg
#include <bits/stdc++.h> 
using namespace std; 

void merge(int arr[],int left,int middle,int right){
  int nFirst = middle - left +1; //number of elements in first half
  int nSecond = right - middle;//number of elements in second half
  //create temp arr to store elements 
  int leftArr[nFirst],rightArr[nSecond];
  for(int i=0;i<nFirst;i++) leftArr[i] = arr[left+i];
  for(int i=0;i<nSecond;i++) rightArr[i] = arr[middle+i+1];
  //now merge temp arr back to arr
  int i=0,j=0,k=left;
  while(i<nFirst && j< nSecond){
    if(leftArr[i] <= rightArr[j]){
       arr[k] = leftArr[i];
       i++;
    }
    else {
       arr[k] = rightArr[j];
       j++;
    }
    k++;
  }
  
  //there may be some remaining elements in leftArr || rightArr
  // so we need to include them also
  while(i < nFirst){
    arr[k] = leftArr[i];
    i++;
    k++;
  }
  while(j < nSecond){
    arr[k] = rightArr[j];
    j++;
    k++;
  }

}

void mergeSort(int arr[],int left,int right){
  if(left<right){
    int middle = left +(right - left)/2;
    //sort first half or break it recursivly
    mergeSort(arr,0,middle);
    //sort second half
    mergeSort(arr,middle+1,right);
    //finally merge them in sorted manner
    merge(arr,left,middle,right);
  }
}

int main() 
{ 
   int arr[] = {3,4,2,4,7,2,1,10,45,23};
   int arrSize = sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr,0,arrSize -1);
   cout<<"array after merge sort -\n";
   for(int i=0;i<arrSize;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
} 
