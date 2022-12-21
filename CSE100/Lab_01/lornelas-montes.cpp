#include <iostream>
using namespace std;

int main(){
    int arraySize = 0;
    int compareValue;
    int compareOtherValue;
    cin >> arraySize; //users size for the array
    int * array = new int [arraySize]; //create a dynamic array on the heap with users size

    for(int i = 0; i < arraySize; i++){
        cin >> array[i];
    }

    for(int i = 1; i < arraySize; i++){
        compareValue = array[i];
        compareOtherValue = i - 1;


        while(compareValue < array[compareOtherValue] && compareOtherValue >= 0){
            array[compareOtherValue+1] = array[compareOtherValue];
            --compareOtherValue;
        
        }

        array[compareOtherValue+1] = compareValue;
        for(int f = 0; f < i+1 ; f++){
            cout << array[f] << ";";
    }
        cout << endl;
    }

    delete [] array;
    return 0;
}