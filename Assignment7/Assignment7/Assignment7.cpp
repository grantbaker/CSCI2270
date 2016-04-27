#include <iostream>
#include "MovieTree.h"

using namespace std;

int main(int argc, char** argv) {
    MovieTree * mt = new MovieTree(argv[1]);
    mt->menu();
    return 0;
}
