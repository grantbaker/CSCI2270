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
    if (CommunicationNetwork::head != NULL && CommunicationNetwork::tail != NULL)
        CommunicationNetwork::deleteNetwork();
}

void CommunicationNetwork::buildNetwork() {
    CommunicationNetwork::head = new City{"Los Angeles"};
    City *tmp = CommunicationNetwork::head;
    tmp->next = new City{"Phoenix"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Denver"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Dallas"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"St. Louis"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Chicago"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Atlanta"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Washington, D.C."};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"New York"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    tmp->next = new City{"Boston"};
    (tmp->next)->previous = tmp;
    tmp = tmp->next;
    CommunicationNetwork::tail = tmp;
    CommunicationNetwork::printNetwork();
}

void CommunicationNetwork::printNetwork() {
    std::cout<<"===CURRENT PATH==="<<std::endl;
    std::cout<<"NULL";
    if(CommunicationNetwork::head!=NULL) {
        std::cout<<" <- ";
        City *tmp = CommunicationNetwork::head;
        while(tmp->next != NULL) {
            std::cout<<tmp->name<<" <-> ";
            tmp = tmp->next;
        }
        std::cout<<tmp->name<<" -> NULL"<<std::endl;
    } else {
        std::cout<<std::endl;
    }
    std::cout<<"=================="<<std::endl;
}

int CommunicationNetwork::addCity(std::string in, std::string prev) {
    //std::cout<<"adding city: "<<in<<" after: "<<prev<<std::endl;
    City *tmp;
    if (prev.compare("First") == 0) {
        tmp = new City(in);
        tmp->next = CommunicationNetwork::head;
        CommunicationNetwork::head->previous = tmp;
        CommunicationNetwork::head = tmp;
        return 0;
    } else {
        tmp = CommunicationNetwork::head;
        while(tmp != NULL) {
            if(tmp->name.compare(prev) == 0) {
                City *newCity = new City {in};
                newCity->next = tmp->next;
                newCity->previous = tmp;
                tmp->next = newCity;
                (newCity->next)->previous = newCity;
                return 0;
            }
            tmp = tmp->next;
        }
        return -1;
    }
}

int CommunicationNetwork::deleteCity(std::string in) {
    City *tmp = CommunicationNetwork::head;
    while(tmp != NULL) {
        if(tmp->name.compare(in) == 0) {
            if(tmp->next) {
                (tmp->next)->previous = tmp->previous;
            } else {
                CommunicationNetwork::tail = tmp->previous;
            }
            if(tmp->previous) {
                (tmp->previous)->next = tmp->next;
            } else {
                CommunicationNetwork::head = tmp->next;
            }
            delete tmp;
            return 0;
        }
        tmp = tmp->next;
    }
    return -1;
}

void CommunicationNetwork::transmitWord(std::string wordIn) {
    City *tmp = CommunicationNetwork::head;
    tmp->message = wordIn;
    std::cout<<tmp->name<<" received "<<tmp->message<<std::endl;
    while (tmp->next != NULL) {
        (tmp->next)->message = tmp->message;
        tmp->message = "";
        tmp = tmp->next;
        std::cout<<tmp->name<<" received "<<tmp->message<<std::endl;
    }
    while (tmp->previous != NULL) {
        (tmp->previous)->message = tmp->message;
        tmp->message = "";
        tmp = tmp->previous;
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

void CommunicationNetwork::deleteNetwork() {
    if(CommunicationNetwork::head != NULL) {
        City *tmp = CommunicationNetwork::head->next;
        City *tmp2 = CommunicationNetwork::head;
        while (tmp!=NULL) {
            std::cout<<"deleting "<<tmp2->name<<std::endl;
            delete tmp2;
            tmp2 = tmp;
            tmp = tmp->next;
        }
        std::cout<<"deleting "<<tmp2->name<<std::endl;
        delete tmp2;
    }
    CommunicationNetwork::head = NULL;
    CommunicationNetwork::tail = NULL;
}
