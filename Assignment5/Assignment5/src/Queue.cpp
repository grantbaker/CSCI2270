#include "Queue.h"

using namespace std;

Queue::Queue(int sz) {
    queueSize = sz;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}

Queue::~Queue() {

}

string Queue::getWord() {
    cout<<"word: ";
    string word;
    cin>>word;
    return word;
}

void Queue::menu() {
    int in = 0;
    string word;
    while (in != 5) {
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>in;
        if (in > 5 || in < 1) {
            in = 5;
        }
        switch (in) {
        case 1:
            word = Queue::getWord();
            Queue::enqueue(word);
            break;
        case 2:
            Queue::dequeue();
            break;
        case 3:
            Queue::printQueue();
            break;
        case 4:
            Queue::getSentence();
            break;
        default:
            cout<<"Goodbye!"<<endl;
            //Queue::~Queue();
            return;
        }
    }
}

void Queue::enqueue(string in) {
    if (queueCount == queueSize) {
        cout<<"Queue is full."<<endl;
        return;
    }
    arrayQueue[queueTail] = in;
    queueTail++;
    if (queueTail == queueSize) {
        queueTail = 0;
    }
    cout<<"E: "<<in<<endl;
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
    queueCount++;
    return;
}

string Queue::dequeue() {
    if (queueCount == 0) {
        cout<<"Queue is empty."<<endl;
        return "";
    }
    string out;
    out = arrayQueue[queueHead];
    queueHead++;
    if (queueHead == queueSize) {
        queueHead = 0;
    }
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
    cout<<"word: "<<out<<endl;
    queueCount--;
    return out;
}

void Queue::printQueue() {
    int i = queueHead;
    while (i!=queueTail && queueCount != queueSize) {
        cout<<i<<": "<<arrayQueue[i]<<endl;
        i++;
        if (i==queueSize) {
            i=0;
        }
    }
    if (queueCount == queueSize) {
        cout<<queueHead<<": "<<arrayQueue[queueHead]<<endl;
        i = queueHead + 1;
        while (i!=queueTail) {
            cout<<i<<": "<<arrayQueue[i]<<endl;
            i++;
            if (i==queueSize) {
                i=0;
            }
        }
    }
    if (queueCount==0) {
        cout<<"Empty"<<endl;
    }
}

void Queue::getSentence() {
    cout<<"sentence: ";
    string word;
    string words;
    int i = 0;
    getline(cin,words);
    getline(cin,words);
    stringstream ss(words);
    while (ss>>word) {
        Queue::enqueue(word);
    }
}
