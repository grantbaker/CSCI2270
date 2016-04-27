#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>
#include <sstream>
#include <fstream>


struct MovieNode {
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode * parent = NULL;
    MovieNode * left = NULL;
    MovieNode * right = NULL;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity) {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    };
};

class MovieTree {
    public:
        MovieTree(char * infile);
        ~MovieTree();

        void menu();
    protected:
    private:
        void printMovieInventory(MovieNode * rt);
        void addMovieNode(int ranking, std::string title, int year, int quantity);
        void countMovieNodes();
        void countMovieNode(MovieNode* node, int* c);
        void deleteMovieNodeIn();
        void deleteMovieNode(MovieNode* node);
        void deleteAll(MovieNode* node);
        void replaceNode(MovieNode* in, MovieNode* target);

        void findMovie();
        void rentMovie();

        MovieNode* search(std::string title);
        MovieNode* treeMin(MovieNode* node);
        MovieNode* root;

        int stringToInt(std::string in);
        int parentSide(MovieNode* node);
};

#endif // MOVIETREE_H
