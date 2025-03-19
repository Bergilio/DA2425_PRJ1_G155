#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>

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
    double dist = 0;

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
	bool isProcessing() const;
	void setVisited(bool visited);
	void setProcessing(bool processing);
	unsigned int getIndegree() const;
	double getDist() const;
	void setIndegree(unsigned int indegree);
	void setDist(double dist);
	int getLow() const;
	void setLow(int value);
	int getNum() const;
	void setNum(int value);

	Edge * addEdge(Vertex *d, int driving, int walking);
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

	Vertex * getDest() const;
	int getDriving() const;
    int getWalking() const;
	bool isSelected() const;
	Vertex * getOrig() const;
	Edge *getReverse() const;
	double getFlow() const;

	void setSelected(bool selected);
	void setReverse(Edge *reverse);
	void setFlow(double flow);
};

class Graph {
protected:
	std::vector<Vertex *> vertexSet;

	double ** distMatrix = nullptr;
	int **pathMatrix = nullptr;

public:
	~Graph();

	Vertex * findVertex(const int &id) const;

	Vertex * findVertexCode(const std::string &code) const;

	bool addVertex(const std::string &location, int id, const std::string &code, bool parking);

	bool addBidirectionalEdge(const std::string &code1, const std::string &code2, int driving, int walking);

	std::vector<Vertex *> getVertexSet() const;
};

#endif //GRAPHMAP_H
