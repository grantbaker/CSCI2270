#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct CarData {
    string model;
    string make;
    string year;
};

int main() {
    CarData carArray[10];
    int i=0,k=0;
    ifstream inFile; // create an instance, can be named whatever you want
    string data;
    inFile.open("structtext.txt"); //open the file
    if(inFile.good()) {  //error check
        cout<<"Opened successfully"<<endl;
        while(getline(inFile, data)) {  //read/get every line of the file and store it
            cout<<data<<endl; //can see the data (each line) printed
            stringstream ss(data); //create a stringstream variable from the string data

            ss>>carArray[i].make;
            ss>>carArray[i].model;
            ss>>carArray[i].year;
            i++;
        }
    }
    else {
        cout<<"File unsuccessfully opened"<<endl;
    }
    inFile.close(); //close the file

    cout<<"---------------------------"<<endl;
    cout<<"Data stored in struct array"<<endl;

    for(k=0; k<i; k++) {
        cout<<"Car "<<k+1<<": "<<carArray[k].year<<" "<<carArray[k].make<<" "<<carArray[k].model<<endl;
    }

    return 0;
}
