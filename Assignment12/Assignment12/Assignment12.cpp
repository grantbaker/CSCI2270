#include <iostream>
#include "HashTable.h"
#include <sstream>

using namespace std;

int stringToInt(string in) {
    stringstream ss(in);
    int n;
    ss>>n;
    return n;
}

int main() {

    HashTable* table = new HashTable(10);
    string st,st2;

    int sel=0;
    while (sel != 5) {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert movie"<<endl;
        cout<<"2. Delete movie"<<endl;
        cout<<"3. Find movie"<<endl;
        cout<<"4. Print table contents"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>sel;
        if (sel > 5 || sel < 1) {
            sel = 5;
        }
        switch (sel) {
        case 1:
            cout<<"Enter title:"<<endl;
            getline(cin, st);
            getline(cin, st);
            cout<<"Enter year:"<<endl;
            getline(cin, st2);
            table->insertMovie(st, stringToInt(st2));
            break;
        case 2:
            cout<<"Enter title:"<<endl;
            getline(cin, st);
            getline(cin, st);
            table->deleteMovie(st);
            break;
        case 3:
            cout<<"Enter title:"<<endl;
            getline(cin, st);
            getline(cin, st);
            table->findMovie(st);
            break;
        case 4:
            table->printTableContents();
            break;
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }

    return 0;
}
