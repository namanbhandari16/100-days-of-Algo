#include<iostream>
using namespace std;


void selectionsort(int a[] , int n){
    int minimum;

    for(int i=0;i<n-1;i++){
        minimum=i;

        for(int j=i+1;j<n;j++){            //finding minimum from i+1 to last element
            if(a[j]<a[minimum]) minimum=j;      
        }
                //swapping of a[minimum] and a[i]
        int temp=a[minimum];        //temp is a temporary variable
        a[minimum]=a[i];
        a[i]=temp;
    }

}


int main(){
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements"<<endl;        //accepting the elements in array
    for(int i=0;i<n;i++){         //index starting from 0
        cin>>a[i];
    }
    selectionsort(a,n);            //calling selectionsort to sort
    cout<<"Sorted array is using selectionsort is"<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

/*  n=5
    Enter the elements
    3 2 1 4 5

    Sorted array is using selectionsort is
    1
    2
    3
    4
    5       */
