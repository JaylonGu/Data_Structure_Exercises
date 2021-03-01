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

void merge(int *array, int *tmp, int leftindex, int rightindex, int rightend){
    int leftend=rightindex-1, tmpi=leftindex, i=leftindex;
    while(leftindex<=leftend && rightindex<=rightend){
        if(array[leftindex]<=array[rightindex]){
            tmp[tmpi++]=array[leftindex++];
        }else{
            tmp[tmpi++]=array[rightindex++];
        }
    }
    while(leftindex<=leftend){
        tmp[tmpi++]=array[leftindex++];
    }
    while(rightindex<=rightend){
        tmp[tmpi++]=array[rightindex++];
    }
    for(;i<=rightend;i++) array[i]=tmp[i];
}

void msort(int *array, int *tmp, int left, int right){
    if(left>=right) return;
    int mid=left+(right-left)/2;
    msort(array,tmp,left,mid);
    msort(array,tmp,mid+1,right);
    merge(array,tmp,left,mid+1,right);
}

void mergeSort(int *array, int size){
    int *tmp;
    tmp=new int[size];
    if(!tmp) return;
    msort(array,tmp,0,size-1);
    delete [] tmp;
}

int main(){
    int array[6]={11,2,33,44,55,6};
    mergeSort(array,6);
    printArray(array,6);
    return 0;
}