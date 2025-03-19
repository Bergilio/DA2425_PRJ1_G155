#include "GraphMap.h"

/*-------------------------------------Vertex-------------------------------------*/

Vertex::Vertex(const std::string &l, int id, const std::string &c, bool p): location(l), id(id), code(c), parking(p) {};

std::string Vertex::getLocation() const {
	return this->location;
}

std::string Vertex::getCode() const {
	return this->code;
}

bool Vertex::getParking() const {
  return this->parking;
}

int Vertex::getId() const {
  return this->id;
}

std::vector<Edge *> Vertex::getIncoming() const {
  return this->incoming;
}

std::vector<Edge *> Vertex::getAdj() const {
  return this->adj;
}

bool Vertex::isVisited() const {
  return this->visited;
}

bool Vertex::isProcessing() const {
  return this->processing;
}

void Vertex::setVisited(bool v) {
  this->visited = v;
}

void Vertex::setProcessing(bool p) {
  this->processing = p;
}

unsigned int Vertex::getIndegree() const {
  return this->indegree;
}

double Vertex::getDist() const {
  return this->dist;
}

void Vertex::setIndegree(unsigned int i) {
  this->indegree = i;
}

void Vertex::setDist(double d) {
  this->dist = d;
}

int Vertex::getLow() const {
  return this->low;
}

int Vertex::getNum() const {
  return this->num;
}

void Vertex::setLow(int l) {
  this->low = l;
}

void Vertex::setNum(int n) {
  this->num = n;
}

Edge * Vertex::addEdge(Vertex *d, int driving, int walking) {
    auto newEdge = new Edge(this, d, driving, walking);
    this->adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}


/*-------------------------------------Edge-------------------------------------*/

Edge::Edge(Vertex *l1, Vertex *l2, int d, int w): orig(l1), dest(l2), driving(d), walking(w) {};

Vertex *Edge::getDest() const {
  return this->dest;
}

Vertex *Edge::getOrig() const {
  return this->orig;
}

int Edge::getWalking() const {
  return this->walking;
}

int Edge::getDriving() const {
  return this->driving;
}

bool Edge::isSelected() const {
  return this->selected;
}

double Edge::getFlow() const {
  return this->flow;
}

Edge *Edge::getReverse() const {
  return this->reverse;
}

void Edge::setFlow(double f) {
  this->flow = f;
}

void Edge::setSelected(bool s) {
  this->selected = s;
}

void Edge::setReverse(Edge *r) {
  this->reverse = r;
}

/*-------------------------------------Graph-------------------------------------*/

Vertex * Graph::findVertex(const int &id) const {
  for (auto v : this->vertexSet) {
    if (v->getId() == id) {
      return v;
    }
  }
  return nullptr;
}

//  Find a Vertex using its code: useful for the Distances.csv processing as locations are given using the code
Vertex * Graph::findVertexCode(const std::string &code) const {
  for (auto v : this->vertexSet) {
    if (v->getCode() == code) {
      return v;
    }
  }
  return nullptr;
}

std::vector<Vertex *> Graph::getVertexSet() const {
  return this->vertexSet;
}

bool Graph::addVertex(const std::string &location, int id, const std::string &code, bool parking) {
  if (this->findVertex(id) != nullptr) {
    return false;
  }
  this->vertexSet.push_back(new Vertex(location, id, code, parking));
  return true;
}

bool Graph::addBidirectionalEdge(const std::string &code1, const std::string &code2, int driving, int walking) {
  auto v1 = findVertexCode(code1);
  auto v2 = findVertexCode(code2);
  if (v1 == nullptr || v2 == nullptr) {
    return false;
  }
  auto e1 = v1->addEdge(v2, driving, walking);
  auto e2 = v2->addEdge(v1, driving, walking);

  return true;
}
