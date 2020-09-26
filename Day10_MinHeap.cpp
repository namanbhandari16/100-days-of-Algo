//thanks to gfg
#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y); 
class MinHeap{
    int *Arr;
    int capacity;
    int heap_size;
    public:
     MinHeap(int capacity);
     int parent(int i){
       return (i-1)/2;
     }
     int left(int i){
         return (2*i+1);
     }
     int right(int i){
         return (2*i+2);
     }
     void insertKey(int k);
     void deleteKey(int k);
     int extractMin();
     void MinHeapify(int i);
     int getMin() { return Arr[0]; } 
     void decreaseKey(int i,int newVal);

};
//method to remove minimum element (root) from minHeap
int MinHeap::extractMin(){
   if(heap_size <=0)
      return INT_MAX;
    if(heap_size ==1){
        heap_size--;
        return Arr[0];
    }
    int root = Arr[0];
    Arr[0] = Arr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i){
   decreaseKey(i,INT_MIN);
   extractMin();
}

void MinHeap::decreaseKey(int i,int newval){
    Arr[i] = newval;
    while (i!=0 && Arr[parent(i)]>Arr[i])
    {
        swap(&Arr[i],&Arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && Arr[l] < Arr[i]){
        smallest = l;
    }
    if(r < heap_size && Arr[r]<Arr[smallest])
        smallest = r;
    if(smallest != i){
        swap(&Arr[i], &Arr[smallest]);
        MinHeapify(smallest);
    }

}

void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout<<"Overflow\n";
        return;
    }
    heap_size++;
    int i= heap_size-1;
    Arr[i] = k;
    //fix min heap Arr as new element is just pushed back
    while (i!=0 && Arr[parent(i)]> Arr[i])
    {
        swap(&Arr[i], &Arr[parent(i)]);
        i = parent(i);
    }
    
}

MinHeap::MinHeap(int cap){
    heap_size=0;
    capacity=cap;
    Arr = new int[cap];
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main(){
 MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
}