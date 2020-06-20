#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
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