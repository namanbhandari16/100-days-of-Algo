//Program to sort a floating point array in a given range using Bucket Sort.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucket_sort(float A[],int N)
{
int i,j,bucket_index,index=0;
//Creating N empty buckets
vector<float> bucket[N];
//Pushing elements in different buckets
for(i=0;i<N;i++)
{
bucket_index=N*A[i];
bucket[bucket_index].push_back(A[i]);
}
//Sorting individual buckets
for(i=0;i<N;i++)
sort(bucket[i].begin(),bucket[i].end());
//Concatenating all buckets into the array
for(i=0;i<N;i++)
for(j=0;j<bucket[i].size();j++)
A[index++]=bucket[i][j];
}
//Driver code
int main()
{
int N,i;
float Array[]={0.786,0.546,0.876,0.3211,0.7433,0.1122};//Range of the array is from 0.1 to 0.9
N=sizeof(Array)/sizeof(Array[0]);
bucket_sort(Array,N);//Calling the bucket_sort function
cout<<"The sorted array is as follows:\n";
for(i=0;i<N;i++)
cout<<Array[i]<<",";
return 0;
}
