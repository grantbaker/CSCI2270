#include "MovieTree.h"

using namespace std;

MovieTree::MovieTree(char * infile) {
    MovieTree::root = NULL;
    ifstream in;
    //stringstream ss;
    string line;

    string rankingStr;
    //int ranking;
    string title;
    string yearStr;
    //int year;
    string quantityStr;
    //int quantity;

    in.open(infile);

    if (in.good()) {
        while (getline(in,line)) {
            stringstream ss(line);
            getline(ss,rankingStr,',');
            getline(ss,title,',');
            getline(ss,yearStr,',');
            getline(ss,quantityStr,',');

            MovieTree::addMovieNode(MovieTree::stringToInt(rankingStr),title,MovieTree::stringToInt(yearStr),MovieTree::stringToInt(quantityStr));
        }
    }
}

MovieTree::~MovieTree() {

}

void MovieTree::menu() {
    int sel = 1;
    while (sel != 4) {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Quit"<<endl;
        cin>>sel;
        if (sel>4 || sel<1){
            sel = 4;
        }
        switch (sel) {
        case 1:
            MovieTree::findMovie();
            break;
        case 2:
            MovieTree::rentMovie();
            break;
        case 3:
            MovieTree::printMovieInventory(MovieTree::root);
            break;
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }
}

int MovieTree::stringToInt(string in) {
    stringstream ss(in);
    int n;
    ss>>n;
    return n;
}

void MovieTree::addMovieNode(int ranking, string title, int year, int quantity) {
    if (MovieTree::root == NULL) {
        MovieTree::root = new MovieNode(ranking, title, year, quantity);
        return;
    } else {
        MovieNode * parent;
        MovieNode * tmp = root;
        while (tmp!=NULL) {
            parent = tmp;
            if (title.compare(tmp->title)<0) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        if (title.compare(parent->title)<0) {
            parent->left = new MovieNode(ranking, title, year, quantity);
            (parent->left)->parent = parent;
        } else {
            parent->right = new MovieNode(ranking, title, year, quantity);
            (parent->right)->parent = parent;
        }
    }
}

MovieNode * MovieTree::search(string title) {
    MovieNode * tmp = MovieTree::root;
    while (tmp!=NULL && tmp->title != title) {
        if (title.compare(tmp->title)<0) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return tmp;
}

void MovieTree::findMovie() {
    string title;
    cout<<"Enter title:"<<endl;
    getline(cin, title);
    getline(cin, title);
    MovieNode * tmp = MovieTree::search(title);
    if (tmp == NULL) {
        cout<<"Movie not found."<<endl;
    } else {
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<tmp->ranking<<endl;
        cout<<"Title:"<<tmp->title<<endl;
        cout<<"Year:"<<tmp->year<<endl;
        cout<<"Quantity:"<<tmp->quantity<<endl;
    }
}

void MovieTree::rentMovie() {
    string title;
    cout<<"Enter title:"<<endl;
    getline(cin, title);
    getline(cin, title);
    MovieNode * tmp = MovieTree::search(title);
    if (tmp == NULL) {
        cout<<"Movie not found."<<endl;
    } else if (tmp->quantity==0){
        cout<<"Movie out of stock."<<endl;
    } else {
        cout<<"Movie has been rented."<<endl;
        tmp->quantity--;
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<tmp->ranking<<endl;
        cout<<"Title:"<<tmp->title<<endl;
        cout<<"Year:"<<tmp->year<<endl;
        cout<<"Quantity:"<<tmp->quantity<<endl;
    }
}

void MovieTree::printMovieInventory(MovieNode * rt) {
    if (rt->left != NULL) {
        MovieTree::printMovieInventory(rt->left);
    }
    cout<<"Movie: "<<rt->title<<" "<<rt->quantity<<endl;
    if (rt->right != NULL) {
        MovieTree::printMovieInventory(rt->right);
    }
}
