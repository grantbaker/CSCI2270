#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char ** argv) {
    Graph* g = new Graph(argv[1]);
    string st;
    string en;

    int sel=0;
    while (sel != 4) {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Print vertices"<<endl;
        cout<<"2. Find districts"<<endl;
        cout<<"3. Find shortest path"<<endl;
        cout<<"4. Quit"<<endl;
        cin>>sel;
        if (sel > 4 || sel < 1) {
            sel = 4;
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
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }

    return 0;
}
