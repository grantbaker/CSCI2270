#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Listing{
    string cat;
    int forSaleWanted;
    int price;
};

int least(int i, int j) {
    if (i<j)
        return i;
    else
        return j;
}

int transaction(Listing * dataArray, Listing * newEntry, int *i, int *k, int *iterations) {
    int j;

    cout<<dataArray[*k].cat<<" "<<least(dataArray[*k].price, newEntry->price)<<endl;
    (*i)--;
    //cout<<"i decremented: i="<<*i<<endl;

    for(j=*k; j<*i; j++) {
        (*iterations)++;
        dataArray[j] = dataArray[j+1];
    }
    return 0;
}

int searchArray(Listing * dataArray, Listing * newEntry, int *i, int * iterations) {
/* Returns 1 if successful (i.e. transaction() is called)
 * Returns 0 if unsuccessful
 */
    int k;
    Listing arrayEntry;

    for(k=0; k<*i; k++) {
        //cout<<"---------"<<k<<endl;
        (*iterations)++;
        arrayEntry = dataArray[k];
        if(arrayEntry.cat.compare(newEntry->cat) == 0) {
            //cout<<"same cat"<<endl;
            if(arrayEntry.forSaleWanted != newEntry->forSaleWanted) {
                //cout<<"different forSaleWanted"<<endl;
                if(arrayEntry.forSaleWanted == 0) {
                    //cout<<"arrayEntry for sale"<<endl;
                    if(arrayEntry.price <= newEntry->price) {
                        //cout<<"Price is good"<<endl;
                        transaction(dataArray, newEntry, i, &k, iterations);
                        return 1;
                    }
                } else {
                    //cout<<"newEntry for sale"<<endl;
                    if(arrayEntry.price >= newEntry->price) {
                        //cout<<"Price is good"<<endl;
                        transaction(dataArray, newEntry, i, &k, iterations);
                        return 1;
                    }
                }
            }
        }
    }
    //cout<<"Match not found. Adding to dataArray"<<endl;

    return 0;
}

int main(int argc, char *argv[]) {
    ifstream listIn;
    string entry;
    int c1, c2, k, i=0;
    int iterations=0;
    Listing newEntry;
    Listing *dataArray = new Listing[100];

    //listIn.open(argv[1]);
    listIn.open("messageBoard.txt");
    //listIn.open("test.txt");
    if(listIn.good()) {
        //cout<<"Opened successfully"<<endl;
        while(getline(listIn,entry)) {
            iterations++;
            //cout<<"LINE READ: "<<entry<<endl;

            c1 = entry.find(", ");
            newEntry.cat = entry.substr(0,c1);

            c2 = entry.substr(c1+2).find(", ") + c1+1;
            if(entry.substr(c1+2,c2-c1-1).compare("wanted") == 0)
                newEntry.forSaleWanted = 1;
            else
                newEntry.forSaleWanted = 0;

            stringstream strcvt(entry.substr(c2+2));
            strcvt>>newEntry.price;

            if(!searchArray(dataArray, &newEntry, &i, &iterations)) {
                dataArray[i] = newEntry;
                i++;
                //cout<<"i incremented: i="<<i<<endl;
            }


        }
    }

    cout<<"#"<<endl;

    for(k=0; k<i; k++) {
        if(dataArray[k].forSaleWanted == 0)
            entry = "for sale";
        else
            entry = "wanted";
        cout<<dataArray[k].cat<<", "<<entry<<", "<<dataArray[k].price<<endl;
        iterations++;
    }

    cout<<"#"<<endl;
    cout<<"loop iterations:"<<iterations<<endl;
    delete []dataArray;
    return 0;
}
