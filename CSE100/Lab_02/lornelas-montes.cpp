#include <iostream>
using namespace std;

void merge(int *array, int arrayLow, int arrayHigh, int mid, int *& arraySorted){
    int i = arrayLow; 
    int j = mid+1;
    int arraySortedK = arrayLow;
    while(i <= mid && j <= arrayHigh ){
        if(array[i] < array[j]){
            arraySorted[arraySortedK] = array[i];
            arraySortedK++;
            i++;
        } else{
            arraySorted[arraySortedK] = array[j];
            arraySortedK++;
            j++;
        }
    }

    while(i<= mid){
        arraySorted[arraySortedK] = array[i];
        arraySortedK++;
        i++;
    }

    while(j <= arrayHigh){
        arraySorted[arraySortedK] = array[j];
        arraySortedK++;
        j++;
    }

    for(i = arrayLow; i < arraySortedK; i++){
        array[i] = arraySorted[i]; //fixed here...???
    }
    
    return;
}

void mergeSort(int* array, int arrayLow, int arrayHigh, int *& arraySorted){
    if(arrayLow && arrayHigh == 0){ //array only has one element (already sorted)
        return;
    }

    int mid = 0;
    if(arrayLow < arrayHigh){ //comparing indexes (not elements)
        mid = (arrayLow + arrayHigh)/2; //create a middle 
        mergeSort(array, arrayLow, mid, arraySorted); //left of array splitted
        mergeSort(array, mid+1, arrayHigh, arraySorted); //right of array splitted
        merge(array, arrayLow, arrayHigh, mid, arraySorted); //array is now splitted into individual elements. Now sort them back into the array in increaing order.
        

    //cout << "test";
    }
    return;
}

int main(){
    int arraySize = 0;
    cin >> arraySize;

    if(arraySize < 0){
        return 0;
    }

    int * array = new int [arraySize];
    int * arraySorted = new int[arraySize](); //a new array to hold and copy our sorted and merged elements

    int arrayLow = 0;
    int arrayHigh = arraySize-1;

    for(int i = 0; i < arraySize; i++){
        cin >> array[i];
    }
    
    mergeSort(array, arrayLow, arrayHigh, arraySorted);


    for (int i = 0; i < arraySize; i++)
    {
        cout << arraySorted[i] << ";";
    }

    delete[] array;
    delete[] arraySorted;
    
    return 0;

}