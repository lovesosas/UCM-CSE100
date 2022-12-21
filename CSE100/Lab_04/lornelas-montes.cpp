#include <iostream>
#include <algorithm>
using namespace std;


void maxHeapify(int * array, int arraySize, int index){
    int tempInt2;
    int left = 2*index +1;
    int right = 2*index +2;
    int largest = index;
    if(left < arraySize && array[left] > array[index]){
        largest = left;
    }

    if(right < arraySize && array[right] > array[largest]){
        largest = right;
    }

    if(largest != index){
        tempInt2 = array[index];
        array[index] = array[largest];
        array[largest] = tempInt2;
        maxHeapify(array, arraySize, largest);
    }

    return;
}

void buildMaxHeap(int * array, int arraySize){
    for(int i = (arraySize/2)-1; i >=0; i--){
        maxHeapify(array, arraySize, i);
    }

    return;
}


void heapSort(int * array, int arraySize){
    int tempInt;
    buildMaxHeap(array, arraySize);
    for(int i = arraySize-1; i>=0; i--){
        tempInt = array[i];
        array[i] = array[0];
        array[0] = tempInt;
        maxHeapify(array, i, 0);
    }
    return;
}


int main(){
    int arraySize;
    cin >> arraySize;
    int array[arraySize];
    for(int i = 0; i < arraySize; i++){
         cin >> array[i];
    }

    heapSort(array, arraySize);

    for(int i = 0; i < arraySize; i++){
         cout << array[i] << ';';
    }
    return 0;
}