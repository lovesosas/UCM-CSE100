#include <iostream>
using namespace std;
#include <list>
#include <bits/stdc++.h>
#include <string>

int hashSize;
string commandNumberString;
int commandNumberInt;
char commandLetter;
//int commandNumber;

int hasher(int key){
    key = key % hashSize;
    return key;

}

void insertKey(int key, list<int> list[]){
    int j = hasher(key);
    while(hashSize != 0){
        list[j].push_front(key);
        break;
    }

   
    //cout << "insertKey " << key;
    return;
}

void deleteKey(int key, list<int> list[]){
     std::list<int> :: iterator step; 
    bool ifRemoved = false;
    int j = hasher(key), i = 0;

    
    for(step = list[j].begin(); step != list[j].end(); ++step, i++){
        if(*step == key){
            list[i].erase(step);
            cout << key << ":DELETED;" << endl;
            ifRemoved = true;
            break;
        }
    }

    if(!ifRemoved){
        cout << key << ":DELETE_FAILED;" << endl;
    }
    //cout << "deleteKey " << key;
    return;
}

void searchKey(int key, list<int> list[]){
     std::list<int> :: iterator step;
    bool ifFound = false;
    int j = hasher(key), i = 0;
    for(step = list[j].begin(); step != list[j].end(); ++step, i++){
        if(*step == key){
            cout << key << ":FOUND_AT" << j << "," << i << ";" << endl;
            ifFound = true;
        }
    }
    if(!ifFound){
        cout << key << ":NOT_FOUND;" << endl;
    }

    //cout << "searchKey " << key;
    return;
}

void printTable(list<int> list[]){
     std::list <int>::iterator step;
    for(int i = 0; i < hashSize; i++){
        cout << i << ":"; 
        for(step = list[i].begin(); step != list[i].end(); ++step){ 
            cout << *step << "->";
        }
        cout << ";" << endl;
    }
    //cout << "printTable ";
    return;
}

void splitString(string commandInput){
    if(commandInput[0]== 'o' && commandInput.length() == 1){
        commandLetter = 'o';
        return;
    }

    if(commandInput[0]== 'e' && commandInput.length() == 1){
        commandLetter = 'e';
        return;
    }

    //cout << "testere1";
    for(int i = 1; i < commandInput.length(); i++){
        commandNumberString.push_back(commandInput[i]);
        //cout << "test1" << endl;
        //cout << commandNumberString << endl;
    }

    if(commandInput[0] == 'i'){
            //cout << "test2" << endl;
            commandNumberInt = stoi(commandNumberString);
            commandLetter = 'i';
            commandNumberString.clear();
        }

        if(commandInput[0] == 'd'){
            commandNumberInt = stoi(commandNumberString);
            commandLetter = 'd';
            commandNumberString.clear();
        }

        if(commandInput[0] == 's'){
            commandNumberInt = stoi(commandNumberString);
            commandLetter = 's';
            commandNumberString.clear();
        }

    //commandNumber = atoi(commandNumber);
    //cout << commandNumber;
    return;
}

int main(){
    string commandInput;
    //char commandNumber;
    cin >> hashSize;
    list<int> list[hashSize];
    cin >> commandInput;
    //bool flag;
    
    while(commandLetter != 'e'){
        //cout << "test";
        splitString(commandInput);
        //cout << "test";
        switch(commandLetter){
            case 'i':
            //cout << "test1";
            insertKey(commandNumberInt, list);
            //cout << "test2";
            break;
            case 'd':
            deleteKey(commandNumberInt, list);
            break;
            case 's':
            searchKey(commandNumberInt, list);
            break;
            case 'o':
            printTable(list);
            break;
        }
        if(commandLetter == 'e'){
            goto jump;
        }
        cin >> commandInput;
        //split:
        //splitString(commandInput);
    }
    jump:
    //:)

    return 0;
}