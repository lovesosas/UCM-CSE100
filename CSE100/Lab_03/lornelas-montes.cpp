#include <iostream>
using namespace std;



int maxCrossingSubarray(int * array, int arrayLow, int arrayMid, int arrayHigh){
    int leftSum = 0;
    int sum = 0;
    int maxLeft = 0;
    for(int i = arrayMid; i >= arrayLow; i--){
        sum = sum + array[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = 0;
    sum = 0;
    int maxRight = 0;
    for(int j = arrayMid+1;j <= arrayHigh; j++){
        sum = sum + array[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }

    return (leftSum+rightSum);

}


int maxSubarray(int * array, int arrayLow, int arrayHigh){
    int arraySize = arrayHigh+1;
    int arrayMid;
    int leftLow, leftHigh;
    int leftSum, rightSum, crossSum;
    int rightLow, rightHigh;
    int crossLow, crossHigh;
    



    if(arraySize == 0){
        return 0;
    } else if(arrayHigh == arrayLow){
        return (arrayLow, arrayHigh, array[arrayLow]);
    } else{
        arrayMid = (arrayLow+arrayHigh)/2;
        (leftLow, leftHigh, leftSum) = maxSubarray(array, arrayLow, arrayMid);
        (rightLow, rightHigh, rightSum) = maxSubarray(array, arrayMid+1, arrayHigh);
        (crossLow, crossHigh, crossSum) = maxCrossingSubarray(array, arrayLow, arrayMid, arrayHigh);

    }

    if(leftSum >= rightSum && leftSum >= crossSum){
        return leftSum;
    } else if(rightSum >= leftSum && rightSum >=crossSum){
        return rightSum;
    } else{
        return crossSum;
    }

    return 0;
}




int main(){
    int arraySize;
    int input;
    cin >> arraySize;

    if(arraySize == 0){
        return 0;
    }

    int arrayHigh = arraySize-1;
    int arrayLow = 0;

    int * array = new int[arraySize];


    for(int i = 0; i < arraySize; i++){
        cin >> array[i];
    }
    //maxSubarray(array, arrayLow, arrayHigh);


    cout << maxSubarray(array, arrayLow, arrayHigh);
    delete []array;


    return 0;
}