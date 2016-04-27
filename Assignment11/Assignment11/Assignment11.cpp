#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char ** argv) {
    Graph* g = new Graph(argv[1]);
    string st;
    string en;

    int sel=0;
    while (sel != 6) {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Print vertices"<<endl;
        cout<<"2. Find districts"<<endl;
        cout<<"3. Find shortest path"<<endl;
        cout<<"4. Find shortest distance"<<endl;
        cout<<"5. Road trip"<<endl;
        cout<<"6. Quit"<<endl;
        cin>>sel;
        if (sel > 6 || sel < 1) {
            sel = 6;
        }
        switch (sel) {
        case 1:
            g->printVertices();
            break;
        case 2:
            g->findDistricts();
            break;
        case 3:
            cout<<"Enter a starting city:"<<endl;
            getline(cin,st);
            getline(cin,st);
            cout<<"Enter an ending city:"<<endl;
            getline(cin,en);
            g->shortestPath(st, en);
            break;
        case 4:
            cout<<"Enter a starting city:"<<endl;
            getline(cin,st);
            getline(cin,st);
            cout<<"Enter an ending city:"<<endl;
            getline(cin,en);
            g->shortestDistance(st, en);
            break;
        case 5:
            cout<<"Enter a starting city:"<<endl;
            getline(cin,st);
            getline(cin,st);
            g->roadTrip(st);
            break;
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }

    return 0;
}
