#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "MutablePriorityQueue.h"

class Edge;

class Vertex {
protected:
    std::string location;
    int id;
    std::string code;
    bool parking;

    bool visited;
    bool processing;
    int low = -1, num = -1;
    unsigned int indegree;
    double dist;
    Edge * path = nullptr;

    std::vector<Edge *> adj;
    std::vector<Edge *> incoming;


public:
    Vertex(const std::string &location, int id, const std::string &code, bool parking);

    std::string getLocation() const;
    int getId() const;
    std::string getCode() const;
    bool getParking() const;

    std::vector<Edge *> getIncoming() const;
    std::vector<Edge *> getAdj() const;

    bool isVisited() const;
    void setVisited(bool visited);
    bool isProcessing() const;
    void setProcessing(bool processing);
    unsigned int getIndegree() const;
    void setIndegree(unsigned int indegree);
    double getDist() const;
    void setDist(double dist);
    int getLow() const;
    void setLow(int value);
    int getNum() const;
    void setNum(int value);
    Edge * getPath() const;
    void setPath(Edge * path);

    Edge * addEdge(Vertex *d, int driving, int walking);
    bool removeEdge(int id);
    void removeOutgoingEdges();
    void deleteEdge(Edge *edge);

    friend class MutablePriorityQueue<Vertex>;

    bool operator<(Vertex &vertex) const;

    int queueIndex = 0;
};


class Edge {
protected:
    Vertex *orig;
    Vertex *dest;
    int driving;
    int walking;
    bool selected = false;
    double flow;
    Edge *reverse = nullptr;

public:
    Edge(Vertex *orig, Vertex *dest, int driving, int walking);

    Vertex *getDest() const;
    int getDriving() const;
    int getWalking() const;
    bool isSelected() const;
    Vertex *getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);
};



class Graph {
protected:
    std::vector<Vertex *> vertexSet;
    double **distMatrix = nullptr;
    int **pathMatrix = nullptr;

public:
    ~Graph();

    Vertex *findVertexById(int id) const;
    Vertex *findVertexByCode(const std::string &code) const;

    bool addVertex(const std::string &location, int id, const std::string &code, bool parking);
    bool removeVertex(const int &id);
    bool addBidirectionalEdge(const std::string &code1, const std::string &code2, int driving, int walking);

    std::vector<Vertex *> getVertexSet() const;

    int getNumVertex() const;
};


#endif // GRAPH_H
