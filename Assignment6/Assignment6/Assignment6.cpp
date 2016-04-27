#include <iostream>
#include "MovieTree.h"

using namespace std;

int main(int argc, char ** argv) {
    /*string a("a:b");
    string b("b");
    string c("c");
    cout<<a.compare(b)<<endl;
    cout<<b.compare(c)<<endl;
    cout<<b.compare(a)<<endl;*/
    MovieTree * mt = new MovieTree(argv[1]);
    mt->menu();
    return 0;
}
