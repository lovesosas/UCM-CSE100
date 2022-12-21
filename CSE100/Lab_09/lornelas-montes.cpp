#include <iostream>
using namespace std;


void memCutRod(int * array, int input, int * newArray, int * length){

    //int * newArray = new int[input];
    //int * length = new int[input];
    *(newArray + 0) = 0;
    *(array + 0) = 0;

    for(int i = 1; i <= input; i++){
        int q = -2147483648;
        int bLength = -1;
        for(int j = 1; j <= i; j++){
            if(q < array[j] + newArray[i-j]){
                q = array[j] + newArray[i-j];
                bLength = j;
            }
        }
        newArray[i] = q;
        length[i] = bLength;
    }
    return;
}




int main(){
    int input;

    
    cin >> input;
    //input = input + 1;
    //cout << "test" << endl;
    int * array = new int[input+1];
    int * newArray = new int[input+1];
    int * length = new int[input+1];

    for(int i = 1; i <= input; i++){
        cin >> array[i];
    }
    //cout << "test2" << endl;
    /*
    for(int i = 0; i < input; i++){
        if(array[i] == 0){
            return 0;
        }
    }
  */
    //cout << "test3" << endl;
    memCutRod(array, input, newArray, length);
    //cout << "test4" << endl;
    cout << newArray[input] << endl;
    while(input > 0){
        cout << length[input] << " ";
        input = input - length[input];
    }
    cout << "-1" << endl;

    delete []newArray;
    delete []length;
    delete []array;
    return 0;
}