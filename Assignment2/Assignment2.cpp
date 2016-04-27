#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct word {
    string text;
    int num;
};

int isInCommonWords(string word);
word * wordArrayDoubling(word * wordArray, int s);

int main(int argc, char *argv[]) {
    ifstream listIn;
    string line;
    string wordIn;
    word *wordArray = new word[100];
    word swapWord1;
    word swapWord2;
    int top;
    int numWords=0;
    int arrayLength=100;
    int arrayDoubled=0;
    int totalNumWords = 0;
    int uniqueWords = 0;
    int i,j,k,l;

    stringstream in(argv[2]);
    int topNumber;
    in>>topNumber;
    //topNumber = 10;

    listIn.open(argv[1]);
    //listIn.open("HungerGames_edit.txt");
    //listIn.open("test.txt");

    if (listIn.good()) {
        while(getline(listIn, line)) {

            stringstream ss(line);

            while(ss>>wordIn) {
                if (!isInCommonWords(wordIn)) {
                    //cout<<"read: "<<wordIn<<endl;
                    totalNumWords++;
                    top = 0;
                    for(i=0; i<numWords; i++) {
                        if(wordIn.compare(wordArray[i].text) == 0) {
                            (wordArray[i].num)++;
                            //cout<<i<<"th word matched: "<<wordArray[i].text<<endl;
                            top = 1;
                        }
                    }
                    if (top == 0) {
                        wordArray[numWords].text = wordIn;
                        wordArray[numWords].num = 1;
                        numWords++;
                        if(numWords+1>=arrayLength) {
                            //cout<<"attempting to double array: "<<numWords<<" "<<arrayLength<<endl;
                            wordArray = wordArrayDoubling(wordArray, arrayLength);
                            arrayDoubled++;
                            arrayLength*=2;
                        }
                    }
                }
            }
        }
    }
    word *topTenWords = new word[topNumber];
    for (i=0;i<topNumber;i++) {
        topTenWords[i].num = 0;
    }
    for (i=0;i<numWords; i++) {
        if (wordArray[i].num==1)
            uniqueWords++;
        if(wordArray[i].num>topTenWords[topNumber-1].num){
            for (k=0;k<topNumber;k++) {
                if (wordArray[i].num>topTenWords[k].num) {
                    swapWord1 = topTenWords[k];
                    topTenWords[k] = wordArray[i];
                    for (j=k+1;j<topNumber;j++) {
                        swapWord2 = topTenWords[j];
                        topTenWords[j] = swapWord1;
                        swapWord1 = swapWord2;
                    }
                    k=topNumber;
                }
            }
        }
    }

    for(i=0;i<topNumber;i++) {
        cout<<topTenWords[i].num<<" - "<<topTenWords[i].text<<endl;
    }
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<arrayDoubled<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<numWords<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<totalNumWords<<endl;

}

int isInCommonWords(string word) {
    string commonWordList[] = {"the", "be", "to", "of", "and",
                               "a", "in", "that", "have", "i", "it", "for", "not",
                               "on", "with", "he", "as", "you", "do", "at", "this",
                               "but", "his", "by", "from", "they", "we", "say", "her",
                               "she", "or", "an", "will", "my", "one", "all", "would",
                               "there", "their", "what", "so", "up", "out", "if",
                               "about", "who", "get", "which", "go", "me"
                              };
    int i;
    for(i=0; i<50; i++) {
        if(word.compare(commonWordList[i]) == 0)
            return 1;
    }
    return 0;
}

word * wordArrayDoubling(word * wordArray, int s) {
    int j=0;
    word * array2 = new word[s*2];
    for(j=0; j<s; j++) {
        array2[j] = wordArray[j];
    }
    delete []wordArray;

    return array2;
}
