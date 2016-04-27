#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct City {
    std::string name;
    std::string message;
    City *next;
    City *previous;

    City(){};

    City(std::string initName, City *initNext, std::string initMessage) {
        name = initName;
        next = initNext;
        message = initMessage;
    }

    City(std::string initName) {
        name = initName;
        next = NULL;
        previous = NULL;
        message = "";
    }
};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();

        int addCity(std::string, std::string);
        int deleteCity(std::string);
        void buildNetwork();
        void deleteNetwork();
        void transmitMsg(char *);
        void printNetwork();
        void transmitWord(std::string);
    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H
