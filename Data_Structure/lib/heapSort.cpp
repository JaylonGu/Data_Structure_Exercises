#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

void percolateDown(int k, int *array, int size){
    int x;
    x=array[k];
    int i,child;
    for(i=k;i*2+1<size;i=child){
        child=i*2+1;
        if(child!=size-1 && array[child+1]>array[child]) child++;   // 大顶堆
        if(x<array[child])
            array[i]=array[child];
        else break;
    }
    array[i]=x;
}

void heapSort(int *array, int size){
    for(int i=size/2-1;i>=0;i--){
        percolateDown(i, array, size);
    }
    for(int i=size-1;i>0;i--){
        swap(array[0],array[i]);
        percolateDown(0,array,i);
    }
}

void printArray(int *array, int size){
    for(int i=0;i<size;++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array[6]={11,2,33,44,55,6};
    heapSort(array,6);
    printArray(array,6);
    return 0;
}