#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


CommunicationNetwork::CommunicationNetwork() {
    CommunicationNetwork::head = NULL;
    CommunicationNetwork::tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork() {

}

void CommunicationNetwork::buildNetwork() {
    CommunicationNetwork::head = new City{"Los Angeles"};
    City *tmp = CommunicationNetwork::head;
    tmp->next = new City{"Phoenix"};
    tmp = tmp->next;
    tmp->next = new City{"Denver"};
    tmp = tmp->next;
    tmp->next = new City{"Dallas"};
    tmp = tmp->next;
    tmp->next = new City{"St. Louis"};
    tmp = tmp->next;
    tmp->next = new City{"Chicago"};
    tmp = tmp->next;
    tmp->next = new City{"Atlanta"};
    tmp = tmp->next;
    tmp->next = new City{"Washington, D.C."};
    tmp = tmp->next;
    tmp->next = new City{"New York"};
    tmp = tmp->next;
    tmp->next = new City{"Boston"};
    CommunicationNetwork::printNetwork();
}

void CommunicationNetwork::printNetwork() {
    std::cout<<"===CURRENT PATH==="<<std::endl;
    City *tmp = CommunicationNetwork::head;
    while(tmp != NULL) {
        std::cout<<tmp->name<<" -> ";
        tmp = tmp->next;
    }
    std::cout<<"NULL"<<std::endl;
    std::cout<<"=================="<<std::endl;
}

int CommunicationNetwork::addCity(std::string in, std::string prev) {
    //std::cout<<"adding city: "<<in<<" after: "<<prev<<std::endl;
    City *tmp;
    if (prev.compare("First") == 0) {
        tmp = new City(in);
        tmp->next = CommunicationNetwork::head;
        CommunicationNetwork::head = tmp;
        return 0;
    } else {
        tmp = CommunicationNetwork::head;
        while(tmp != NULL) {
            if(tmp->name.compare(prev) == 0) {
                City *newCity = new City {in};
                newCity->next = tmp->next;
                tmp->next = newCity;
                return 0;
            }
            tmp = tmp->next;
        }
        return -1;
    }
}

void CommunicationNetwork::transmitWord(std::string wordIn) {
    City *tmp = CommunicationNetwork::head;
    tmp->message = wordIn;
    std::cout<<tmp->name<<" received "<<tmp->message<<std::endl;
    while (tmp->next != NULL) {
        (tmp->next)->message = tmp->message;
        tmp = tmp->next;
        std::cout<<tmp->name<<" received "<<tmp->message<<std::endl;
    }
}

void CommunicationNetwork::transmitMsg(char * filename) {
    City *tmp = CommunicationNetwork::head;
    if (tmp == NULL) {
        std::cout<<"Empty List"<<std::endl;
        return;
    }

    std::ifstream in;
    in.open(filename);

    if(in.good()) {
        //std::cout<<"opened file"<<std::endl;
        std::string lineIn;
        std::string wordIn;

        while(std::getline(in,lineIn)) {
            std::stringstream ss(lineIn);
            while(ss>>wordIn) {
                CommunicationNetwork::transmitWord(wordIn);
            }
        }
    }
}
