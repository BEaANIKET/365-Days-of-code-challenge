#include <bits/stdc++.h>
using namespace std;

class heap{
   public:
    
    int arr[100];
    int size;

    heap(){
        size = 0;
    }

    void insert(int val){

        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            return ;
        }

        arr[1] = arr[size];
        size --;

        int i = 1;
        while(i<size){

            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
            }
            else{
                return ;
            }
        }

    }

    void display(){
        for(int i=1;i<=size;i++){
            cout<<arr[i] <<" ";
        }cout<<endl;
    }
};

void maxHeapify(int arr[],int n,int i){

    int largest  = i;
    int left = 2*i;
    int right = 2*i +1;

    if(left <= n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void minHeapify(int arr[],int n,int i){

    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left ;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right ;
    }

    if(smallest != i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,n,smallest);
    }

    return ;
}

void heapSort(int arr[] , int n){
    
    int size = n;
    while(size>1){
        
        // step 1 
        swap(arr[1],arr[size]);
        size--;

        // step 2 heapify
        maxHeapify(arr,size,1);      
    }

    return ;
}

int main(){
 
    // heap h;
    // h.insert(3);
    // h.insert(30);
    // h.insert(40);
    // h.insert(33);
    // h.insert(20);
    // h.insert(18);
    // h.insert(50);
    // h.display();
    // h.deleteFromHeap(); 
    // h.display();


    // cout<<"heapify"<<endl;
    int arr[6] = {-1,33,40,3,20,18};
    int n = 6;
    for(int i=n/2;i>0;i--){
        maxHeapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    

    cout<<"HeapSort"<<endl;
    int p = n;
    heapSort(arr,n);
     for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // cout<<"minHeapify"<<endl;
    // int arr[6] = {-1,33,40,3,20,18};
    // int n = 6;
    // for(int i=n/2;i>0;i--){
    //     minHeapify(arr,n,i);
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    return 0;
}
