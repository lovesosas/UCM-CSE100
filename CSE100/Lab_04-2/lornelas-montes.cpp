#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int partition(int * array, int arrayLow, int arrayHigh){
    int temp;
    int temp2;
    int random = rand() % arrayHigh;
    int pivot = array[arrayLow];
    int i = arrayHigh+1;
    for(int j = arrayHigh; j > arrayLow; j--){
        if(array[j] > pivot){
            i--;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp2 = array[i-1];
    array[i-1] = array[arrayLow];
    array[arrayLow] = temp2;

    return i-1;
}


void quickSort(int * array, int arrayLow, int arrayHigh){
    if(arrayLow < arrayHigh){
        int Q = partition(array, arrayLow, arrayHigh);
        quickSort(array, arrayLow, Q-1);
        quickSort(array, Q+1, arrayHigh);
    }

    return;
}

int main(){
    int arraySize;
    cin >> arraySize;
    int array[arraySize];
    for(int i = 0; i < arraySize; i++){
         cin >> *(array + i);
    }
    
    quickSort(array, arraySize-arraySize, arraySize-1);

    for(int i = 0; i < arraySize; i++){
         cout << *(array + i) << ';';
    }

    return 0;
}