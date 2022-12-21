#include <iostream>
using namespace std;
#include <vector>

void countingSort(int ** array, int ** arraySorted, int k, int n){
    int * arrayC = new int[10];
    for(int i = 0; i < 10; i++){
        arrayC[i] = 0;
    }
    //cout << "countTest";
    //here
    for(int j = 0; j < n; j++){
        //cout << "countTest2";
        arrayC[array[j][k]] = arrayC[array[j][k]]+1;
    }

    //cout << "countTest";
    for(int i = 1; i < 10; i++){
        arrayC[i] = arrayC[i] + arrayC[i-1];
    }
    //cout << "countTest";
    for(int j = n-1; j >=0; j--){
        arraySorted[arrayC[array[j][k]]-1] = array[j];
        arrayC[array[j][k]] = arrayC[array[j][k]] - 1;
    }
    //cout << "testCounting";

    return;
}




void radixSort(int **array, int ** arraySorted, int n){
    
    for(int i = 9; i >=0; i--){
        //cout << "testradixSort";
        countingSort(array, arraySorted, i, n);
        //cout << "testradixSort2";
        for (int i = 0; i < n; i++) {
            array[i] = arraySorted[i];
        }
    }
    return;
}



int main(){
    int rowSize;
    int colSize = 10;
    cin >> rowSize;


    int **array = new int*[rowSize];
    for(int i = 0; i < rowSize; i++){
        array[i] = new int[colSize];
    }

    int **arraySorted = new int*[rowSize];
    for(int i = 0; i < rowSize; i++){
        arraySorted[i] = new int[colSize];
    }

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> *(*(array + i) + j);
            //cin >> array[i][j];
            //*(*(B+i) + j)
        }
    }
    //cout << "testmain1";
    //here
    radixSort(array, arraySorted, rowSize);



    //cout << "testmain2";

    //test print
    /*
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arraySorted[i][j] << ";";
        }
        cout << endl;
    }
    cout << endl;
    */
 
    //actual print
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 10; j++) {
            cout << *(*(arraySorted+i) + j) << ";";
        }
        cout << endl;
    }
    
    //cout << "testmain";
    /*
    for (int i = 0; i < 10; i++){
        delete[] array[i]; // Delete columns
    }
    
    for (int i = 0; i < 10; i++){
        delete[] arraySorted[i]; // Delete columns
    }
    */
    
    delete[] array; // Delete Rows
    delete[] arraySorted;
    
    return 0;
}