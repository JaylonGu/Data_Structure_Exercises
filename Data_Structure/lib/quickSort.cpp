#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

void insertionSort(int *array, int size){
    for(int i=0,j; i<size-1; i++){
        int t=array[i+1];
        for(j=i+1; j>0 && t<array[j-1]; j--){
            array[j]=array[j-1];
        }
        array[j]=t;
    }
}

void printArray(int *array, int size){
    for(int i=0;i<size;++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int medianPivot(int *a, int l, int r){
    int m=l+(r-l)/2;
    if(a[l]>a[m]) swap(a[l],a[m]);
    if(a[l]>a[r]) swap(a[l],a[r]);
    if(a[m]>a[r]) swap(a[m],a[r]);
    swap(a[m],a[r-1]);
    return a[r-1];
}

const int cutoff=3;

void qSort(int *a, int l, int r){
    if(r-l<cutoff) insertionSort(a+l,r-l+1);
    else{
        int pivot;
        pivot=medianPivot(a,l,r);
        int i=l+1, j=r-2;   // 如果r-l<=2可能会导致数组越界
        while(1){
            while(a[i]<pivot) i++;
            while(a[j]>pivot) j--;
            if(i<j) swap(a[i],a[j]);
            else break;
        }
        swap(a[i],a[r-1]);
        qSort(a,l,i-1);
        qSort(a,i+1,r);
    }
}

void quickSort(int *array, int size){
    qSort(array, 0, size-1);
}

int main(){
    int array[6]={11,2,33,44,5,66};
    quickSort(array,6);
    printArray(array,6);
    return 0;
}