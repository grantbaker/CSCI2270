#include "Graph.h"

Graph::Graph(char* file) {
    std::ifstream in;
    std::string line;
    std::string word;
    std::string name;
    bool a;
    int dist,i,j;

    in.open(file);
    if (in.good()) {
        std::getline(in,line);
        std::stringstream ss(line);
        std::getline(ss,word,',');
        while (std::getline(ss,word,',')) {
            Graph::addVertex(word);
        }

        while (std::getline(in,line)) {
            std::stringstream ss(line);
            std::getline(ss,name,',');
            j = 0;
            a = false;
            while (std::getline(ss,word,',')) {
                dist = Graph::stoi(word);
                if (dist > 0) {
                    if (a) {
                        Graph::addEdge(name, Graph::vertices[j]->name, dist);
                    }
                }
                if (dist == 0) {
                    a = true;
                }
                j++;
            }
            i++;

        }
    }
}

Graph::~Graph() {

}

int Graph::stoi(std::string s) {
    std::stringstream ss(s);
    int i;
    ss>>i;
    return i;
}

void Graph::addVertex(std::string name) {
    Graph::vertices.push_back(new vertex(name));

}

void Graph::addEdge(std::string v1, std::string v2, int weight) {
    vertex* c1 = Graph::findVertex(v1);
    vertex* c2 = Graph::findVertex(v2);
    if (c1 == NULL || c2 == NULL) {
        return;
    }
    c1->adj.push_back(new adjVertex(c2, weight));
    c2->adj.push_back(new adjVertex(c1, weight));
}

vertex* Graph::findVertex(std::string name) {
    int i=0;
    while (i<Graph::vertices.size()) {
        if (name.compare(Graph::vertices[i]->name) == 0) {
            return Graph::vertices[i];
        }
        i++;
    }
    return NULL;
}

void Graph::printVertices() {
    int i=0;
    int j;
    while (i<Graph::vertices.size()) {
        std::cout<<Graph::vertices[i]->district<<":"<<Graph::vertices[i]->name<<"-->";
        j=0;
        int sz = Graph::vertices[i]->adj.size();
        while (j<sz-1) {
            std::cout<<vertices[i]->adj[j]->v->name;
            std::cout<<"***";
            j++;
        }
        std::cout<<vertices[i]->adj[j]->v->name;
        std::cout<<std::endl;
        i++;
    }

}

void Graph::findDistricts() {
    int i=0;
    int j=1;
    while (i<Graph::vertices.size()) {
        if (Graph::vertices[i]->district == -1) {
            Graph::BFTraversalLabel(Graph::vertices[i], j);
            j++;
        }
        i++;
    }
}

void Graph::BFTraversalLabel(vertex* start, int distID) {
    std::queue<vertex*> q;
    vertex* c;
    int i;

    q.push(start);
    while (!q.empty()) {
        c = q.front();
        q.pop();
        //std::cout<<c->name<<std::endl;
        c->district = distID;
        i=0;
        while (i<c->adj.size()) {
            if (c->adj[i]->v->district == -1){
                q.push(c->adj[i]->v);
            }
            i++;
        }
    }
}

void Graph::shortestPath(std::string start, std::string en) {
    Graph::setUnvisited();
    vertex* v1 = Graph::findVertex(start);
    vertex* v2 = Graph::findVertex(en);
    if (!v1 || !v2) {
        std::cout<<"One or more cities doesn't exist"<<std::endl;
        return;
    }
    if (v1->district != v2->district) {
        std::cout<<"No safe path between cities"<<std::endl;
        return;
    }
    if (v1->district == -1) {
        std::cout<<"Please identify the districts before checking distances"<<std::endl;
        return;
    }

    std::queue<queueVertex*> q;
    std::vector<queueVertex*> paths;
    queueVertex* c;
    std::vector<vertex*> path;
    int i;

    path.push_back(v1);
    q.push(new queueVertex(0, path));
    while (!q.empty()) {
        c = q.front();
        q.pop();
        c->path.back()->visited = true;
        //std::cout<<c->path.back()->name<<std::endl;
        if (c->path.back() == v2) {
            paths.push_back(c);
        }
        i=0;
        while (i<c->path.back()->adj.size()) {
            //std::cout<<":"<<c->path.back()->adj[i]->v->name<<std::endl;
            if (!(c->path.back()->adj[i]->v->visited)) {
                path = c->path;
                path.push_back(c->path.back()->adj[i]->v);
                q.push(new queueVertex(c->distance + 1, path));
            }
            i++;
        }
    }

    int minLength = 9999;
    queueVertex* shortest;
    for (i=0; i<paths.size(); i++) {
        if (paths[i]->distance < minLength) {
            minLength = paths[i]->distance;
            shortest = paths[i];
        }
    }
    std::cout<<minLength;
    for (i=0; i<shortest->path.size(); i++) {
        std::cout<<","<<shortest->path[i]->name;
    }
    std::cout<<std::endl;
    Graph::setUnvisited();
}

void Graph::setUnvisited() {
    int i=0;
    while (i<Graph::vertices.size()) {
        Graph::vertices[i]->visited = false;
        i++;
    }
}

void Graph::shortestDistance(std::string start, std::string en) {
    Graph::setUnvisited();
    vertex* v1 = Graph::findVertex(start);
    vertex* v2 = Graph::findVertex(en);
    if (!v1 || !v2) {
        std::cout<<"One or more cities doesn't exist"<<std::endl;
        return;
    }
    if (v1->district != v2->district) {
        std::cout<<"No safe path between cities"<<std::endl;
        return;
    }
    if (v1->district == -1) {
        std::cout<<"Please identify the districts before checking distances"<<std::endl;
        return;
    }

    std::queue<queueVertex*> q;
    std::vector<queueVertex*> paths;
    queueVertex* c;
    std::vector<vertex*> path;
    int i;

    path.push_back(v1);
    q.push(new queueVertex(0, path));
    while (!q.empty()) {
        c = q.front();
        q.pop();
        c->path.back()->visited = true;
        //std::cout<<c->path.back()->name<<std::endl;
        if (c->path.back() == v2) {
            paths.push_back(c);
        }
        i=0;
        while (i<c->path.back()->adj.size()) {
            //std::cout<<":"<<c->path.back()->adj[i]->v->name<<std::endl;
            if (!(c->path.back()->adj[i]->v->visited)) {
                path = c->path;
                path.push_back(c->path.back()->adj[i]->v);
                q.push(new queueVertex(c->distance + c->path.back()->adj[i]->weight, path));
            }
            i++;
        }
    }

    int minLength = 327670;
    queueVertex* shortest;
    for (i=0; i<paths.size(); i++) {
        if (paths[i]->distance < minLength) {
            minLength = paths[i]->distance;
            shortest = paths[i];
        }
    }
    std::cout<<minLength;
    for (i=0; i<shortest->path.size(); i++) {
        std::cout<<","<<shortest->path[i]->name;
    }
    std::cout<<std::endl;
    Graph::setUnvisited();

}

void Graph::roadTrip(std::string start) {
    Graph::setUnvisited();
    vertex* v = Graph::findVertex(start);

    if (!v) {
        return;
    }
    if (v->district == -1) {
        std::cout<<"Please identify the districts before checking distances"<<std::endl;
        return;
    }

    //std::cout<<"1"<<std::endl;

    int numberCities = Graph::findNumberCitiesInDistrict(v);

    std::queue<queueVertex*> q;
    std::vector<queueVertex*> paths;
    queueVertex* c;
    std::vector<vertex*> path;
    int i;

    //std::cout<<"2 "<<numberCities<<std::endl;

    path.push_back(v);
    q.push(new queueVertex(0, path));
    while (!q.empty()) {
        c = q.front();
        q.pop();
        c->path.back()->visited = true;
        //std::cout<<c->path.back()->name<<c->path.size()<<std::endl;
        if (c->path.back() == v && c->path.size() == numberCities+1) {
            paths.push_back(c);
        }
        for (i=0; i<c->path.back()->adj.size(); i++) {
            //std::cout<<": "<<c->path.back()->adj[i]->v->name<<std::endl;
            if (!Graph::vertexInPath(c->path.back()->adj[i]->v, c) || (c->path.back()->adj[i]->v == v && c->path.size() == numberCities)) {
                path = c->path;
                path.push_back(c->path.back()->adj[i]->v);
                //std::cout<<":: "<<c->path.back()->adj[i]->v->name<<std::endl;
                q.push(new queueVertex(c->distance + c->path.back()->adj[i]->weight, path));
            }
        }
    }

    //std::cout<<"3 "<<paths.size()<<std::endl;

    int minLength = 327670;
    queueVertex* shortest;
    for (i=0; i<paths.size(); i++) {
        if (paths[i]->distance < minLength) {
            minLength = paths[i]->distance;
            shortest = paths[i];
        }
    }

    //std::cout<<"4"<<std::endl;

    std::cout<<minLength<<std::endl;
    std::cout<<minLength;
    for (i=0; i<shortest->path.size(); i++) {
        std::cout<<","<<shortest->path[i]->name;
    }
    std::cout<<std::endl;
    Graph::setUnvisited();
}

int Graph::findNumberCitiesInDistrict(vertex* v) {
    Graph::setUnvisited();

    std::queue<vertex*> q;
    vertex* c;
    int i;
    int total = 0;

    q.push(v);
    while (!q.empty()) {
        c = q.front();
        q.pop();
        if (!(c->visited)) {
            //std::cout<<c->name<<std::endl;
            c->visited = true;
            total++;
            i=0;
            while (i<c->adj.size()) {
                if (!(c->adj[i]->v->visited)) {
                    q.push(c->adj[i]->v);
                }
                i++;
            }
        }
    }
    Graph::setUnvisited();
    return total;
}

bool Graph::vertexInPath(vertex* city, queueVertex* pathV) {
    int i;
    for (i=0; i<pathV->path.size(); i++) {
        if (pathV->path[i] == city) {
            return true;
        }
    }
    return false;
}
