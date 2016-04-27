#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <sstream>

class Queue {
    public:
        Queue(int);
        ~Queue();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printQueue();
        bool queueIsFull(); //send when full
        bool queueIsEmpty(); //send when empty
        void menu();

    protected:
    private:
        int queueSize;
        int queueHead;
        int queueTail;
        int queueCount;
        std::string *arrayQueue;
        std::string getWord();
        void getSentence();
};

#endif // QUEUE_H
