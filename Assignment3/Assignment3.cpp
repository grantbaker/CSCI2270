#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;

int menu() {
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;
    int choice;
    cin>>choice;
    if (choice>5 || choice<1) {
        choice = 5;
    }
    return choice;
}

void getCityIn(CommunicationNetwork * network) {
    cout<<"Enter a city name: "<<endl;
    string in;
    string prev;
    getline(cin,in);
    //cout<<"What was in \"in\":"<<in<<endl;
    getline(cin,in);
    cout<<"Enter a previous city name: "<<endl;
    getline(cin,prev);
    if(network->addCity(in,prev)) {
        cout<<"City not found."<<endl;
    }
}

int main() {
    int menuInt=0;
    CommunicationNetwork network;

    while (menuInt !=5) {
        menuInt = menu();

        switch (menuInt) {
        case 1:
            //cout<<"Building network"<<endl;
            network.buildNetwork();
            //cout<<"Network built"<<endl;
            break;
        case 2:
            //cout<<"Printing network path"<<endl;
            network.printNetwork();
            break;
        case 3:
            //cout<<"Transmitting message"<<endl;
            network.transmitMsg("messageIn.txt");
            break;
        case 4:
            //cout<<"Adding city"<<endl;
            getCityIn(&network);
            break;
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }
    return 0;
}
