#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;

int menu() {
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Delete City"<<endl;
    cout<<"6. Clear Network"<<endl;
    cout<<"7. Quit"<<endl;
    int choice;
    cin>>choice;
    if (choice>7 || choice<1) {
        choice = 7;
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

void getCityDel(CommunicationNetwork * network) {
    cout<<"Enter a city name: "<<endl;
    string in;
    getline(cin,in);
    getline(cin,in);
    if(network->deleteCity(in)) {
        cout<<"City not found."<<endl;
    }

}

int main(int argc, char ** argv) {
    int menuInt=0;
    CommunicationNetwork network;

    while (menuInt !=7) {
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
            network.transmitMsg(argv[1]);
            break;
        case 4:
            //cout<<"Adding city"<<endl;
            getCityIn(&network);
            break;
        case 5:
            getCityDel(&network);
            break;
        case 6:
            network.deleteNetwork();
            break;
        default:
            cout<<"Goodbye!"<<endl;
            break;
        }
    }
    return 0;
}
