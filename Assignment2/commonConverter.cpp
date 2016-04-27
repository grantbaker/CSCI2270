#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    ifstream listIn;
    string word, output;
    string *wordList = new string[50];
    int i=0;

    listIn.open("commonWordList.txt");

    if(listIn.good()) {
        while(getline(listIn, word)) {
            cout<<word<<endl;
            stringstream ss(word);
        }
    }

    output = "{";
    cout<<output<<endl;
    for(i=0;i<49;i++) {
        output = output + "\"" + wordList[i] + "\", ";
        cout<<output<<endl;
    }
    output = output + "\"" + wordList[49] + "\"}";
    cout<<output<<endl;
}
