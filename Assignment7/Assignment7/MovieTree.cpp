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
    MovieTree::deleteAll(MovieTree::root);
}

void MovieTree::menu() {
    int sel = 1;
    while (sel != 6) {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Delete a movie"<<endl;
        cout<<"5. Count the movies"<<endl;
        cout<<"6. Quit"<<endl;
        cin>>sel;
        if (sel>6 || sel<1){
            sel = 6;
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
        case 4:
            MovieTree::deleteMovieNodeIn();
            break;
        case 5:
            MovieTree::countMovieNodes();
            break;
        default:
            cout<<"Goodbye!"<<endl;
            MovieTree::deleteAll(MovieTree::root);
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
        if (tmp->quantity == 0) {
            MovieTree::deleteMovieNode(tmp);
        }
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

void MovieTree::countMovieNodes() {
    int c = 0;
    MovieTree::countMovieNode(MovieTree::root, &c);
    cout<<"Tree contains: "<<c<<" movies."<<endl;
}

void MovieTree::countMovieNode(MovieNode* node, int* c) {
    if (node->left!=NULL) {
        MovieTree::countMovieNode(node->left, c);
    }
    *c = *c + 1;
    if (node->right!=NULL) {
        MovieTree::countMovieNode(node->right, c);
    }
}

void MovieTree::deleteMovieNodeIn() {
    string title;
    cout<<"Enter title:"<<endl;
    getline(cin, title);
    getline(cin, title);
    MovieNode* tmp = MovieTree::search(title);
    if (tmp == NULL) {
        cout<<"Movie not found."<<endl;
        return;
    }
    MovieTree::deleteMovieNode(tmp);
}

void MovieTree::deleteMovieNode(MovieNode* node) {
    int side = MovieTree::parentSide(node);
    if (node->left == NULL && node->right == NULL) {
        //cout<<"BOTH NULL CASE"<<endl;
        if (side == 0) {
            MovieTree::root = NULL;
        }
        if (side == 1) {
            node->parent->right = NULL;
        }
        if (side == -1) {
            node->parent->left = NULL;
        }
        delete node;
        return;
    }
    if (node->left != NULL && node->right == NULL) {
        //cout<<"LEFT EXISTS"<<endl;
        if (side == 0) {
            MovieTree::root = node->left;
        }
        if (side == 1) {
            node->parent->right = node->left;
        }
        if (side == -1) {
            node->parent->left = node->left;
        }
        delete node;
        return;
    }
    if (node->right != NULL && node->left == NULL) {
        //cout<<"RIGHT EXISTS"<<endl;
        if (side == 0) {
            MovieTree::root = node->right;
        }
        if (side == 1) {
            node->parent->right = node->right;
        }
        if (side == -1) {
            node->parent->left = node->right;
        }
        delete node;
        return;
    }
    if (node->right != NULL && node->left != NULL) {
        //cout<<"BOTH EXIST"<<endl;
        MovieNode* mn = MovieTree::treeMin(node->right);
        if (mn->parent != node) {
            mn->parent->left = mn->right;
            if (mn->right != NULL) {
                mn->right->parent = mn->parent;
            }
            mn->left = node->left;
            mn->left->parent = mn;
            mn->right = node->right;
            mn->right->parent = mn;
            mn->parent = node->parent;
            if (side == 0) {
                MovieTree::root = mn;
            }
            if (side == 1) {
                node->parent->right = mn;
            }
            if (side == -1) {
                node->parent->left = mn;
            }
        } else {
            mn->left = node->left;
            mn->left->parent = mn;
            mn->parent = node->parent;
            if (side == 0) {
                MovieTree::root = mn;
            }
            if (side == 1) {
                node->parent->right = mn;
            }
            if (side == -1) {
                node->parent->left = mn;
            }
        }

        delete node;
        return;
    }
}

MovieNode* MovieTree::treeMin(MovieNode* node) {
    MovieNode* tmp = node;
    while(tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

void MovieTree::deleteAll(MovieNode* node) {
    if (node->left != NULL) {
        deleteAll(node->left);
    }
    if (node->right != NULL) {
        deleteAll(node->right);
    }
    cout<<"Deleting: "<<node->title<<endl;
    delete node;
}

void MovieTree::replaceNode(MovieNode* in, MovieNode* target) {
    target->ranking = in->ranking;
    target->title = in->title;
    target->year = in->year;
    target->quantity = in->quantity;
}

int MovieTree::parentSide(MovieNode* node) {
    if (node->parent == NULL) {
        return 0;
    }
    if (node->parent->left == node) {
        return -1;
    }
    if (node->parent->right == node) {
        return 1;
    }
    return 0;
}
