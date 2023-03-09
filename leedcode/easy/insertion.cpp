#include<iostream>
using namespace std;

int display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
           cout<<arr[i]<<endl;

    }
    cout<<endl;
    
}

int insertion(int arr[],int size,int element,int index,int capecity){
    if (size>=capecity){
        return -1;
    }
    for(int i=size;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}

int main(){

int arr[100]={1,4,6,8,9};
int size=5,element=48,index=3;
display(arr,size);
insertion(arr,size,element,index,100);
size=size+1;
display(arr,size);
    return 0;
}