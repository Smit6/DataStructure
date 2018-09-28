#include <iostream>
#include "minpriority.h"
#include <map>

using std::cout;
using std::endl;
using std::map;

#ifndef GRAPH_H
#define GRAPH_H

// class Graph {
// public:
//   void addE(string name1, string name2, int wt) {
//     Neighbor *n1 = new Neighbor();
//     n1->name = name2;
//     n1->weight = wt;
//     Neighbor *n2 = new Neighbor();
//     n2->name = name1;
//     n2->weight = wt;
//     adjList[name1].push_back(n1);
//     adjList[name2].push_back(n2);
//   }
//   void addV(string name_) {
//     Vertex *v = new Vertex();
//     v->key = 1000;
//     v->pi = "NIL";
//     v->name = name_;
//     vertices[name_] = v;
//     sizeV++;
//   }
//   void print() {
//     map<string, Vertex*>::iterator it1;
//     int size = 0;
//     string curr_str = "";
//     for (it1 = vertices.begin(); it1 != vertices.end(); it1++) {
//       curr_str = it1->first;
//       cout << it1->first << " : ";
//       size = adjList[curr_str].size();
//       for (int i = 0; i < size; i++) {
//         cout << adjList[curr_str][i]->name << ", " <<
//         adjList[curr_str][i]->weight << " -- ";
//       }
//       cout << endl;
//     }
//   }
//   void sort() {
//     string nameTemp;
//     int keyTemp,i;
//     cout << "----- before sorting -----" << endl;
//     for (map<string, vector<Neighbor*>>::const_iterator
//       it = adjList.begin(); it != adjList.end(); ++it) {
//         for (unsigned int j = 0; j < it->second.size(); j++) {
//         cout << it->second[j]->name << " " << it->second[j]->weight << " --> ";
//       }
//       cout << endl;
//     }
//     for (map<string, vector<Neighbor*>>::const_iterator
//       it = adjList.begin(); it != adjList.end(); ++it) {
//       for (unsigned int j = 1; j < it->second.size(); j++) {
//         nameTemp = it->second[j]->name;
//         keyTemp = it->second[j]->weight;
//         i = j - 1;
//         while(i >= 0 && (it->second[i]->name > nameTemp)) {
//           it->second[i+1]->name = it->second[i]->name;
//           it->second[i+1]->weight = it->second[i]->weight;
//           i = i - 1;
//         }
//        it->second[i+1]->name = nameTemp;
//        it->second[i+1]->weight = keyTemp;
//       }
//     }
//     cout << "----- after sorting -----" << endl;
//     for (map<string, vector<Neighbor*>>::const_iterator
//       it = adjList.begin(); it != adjList.end(); ++it) {
//       for (unsigned int j = 0; j < it->second.size(); j++) {
//         cout << it->second[j]->name << " " << it->second[j]->weight << " --> ";
//       }
//       cout << endl;
//     }
//     cout << "size = " << sizeV << endl;
//   }
//   void dijkstra(string name) {
//     cout << "vertex\t" << "pi\t" << "key" << endl;
//     vertices[name]->key = 0;
//     for (map<string, Vertex*>::iterator it = vertices.begin();
//       it != vertices.end(); it++) {
//       minQ.insert(it->first, it->second->key);
//     }
//     string u = "";
//     int size = 0;
//     bool isMem = false;
//     while (( u = minQ.extractMin()) != "empty") {
//       size = adjList[u].size();
//       for (unsigned int i = 0; i < size; i++) {
//         string v = adjList[u][i]->name;
//         isMem = minQ.isMember(v);
//         if (isMem && vertices[u]->key != 1000 && (adjList[u][i]->weight +
//           vertices[u]->key < vertices[v]->key)) {
//           vertices[v]->key = vertices[u]->key + adjList[u][i]->weight;
//           vertices[v]->pi = u;
//           minQ.decreaseKey(v, vertices[u]->key);
//         }
//       }
//       cout << u << "\t" << vertices[u]->pi << "\t" << vertices[u]->key
//         << endl;
//     }
//   }
//   void mst(string startVertex) {
//     int size;
//     int weight = 0;
//     bool isMem = false;
//     string u;
//     sort();
//     vertices[startVertex]->key = 0;
//     for (map<string, Vertex*>::iterator it = vertices.begin();
//       it != vertices.end(); it++) {
//       minQ.insert(it->first, it->second->key);
//     }
//     while (( u = minQ.extractMin()) != "empty") {
//       size = adjList[u].size();
//       for (unsigned int i = 0; i < size; i++) {
//         isMem = minQ.isMember(adjList[u][i]->name);
//         if (isMem && (adjList[u][i]->weight <
//           vertices[adjList[u][i]->name]->key)) {
//           vertices[adjList[u][i]->name]->pi = u;
//           vertices[adjList[u][i]->name]->key = adjList[u][i]->weight;
//           minQ.decreaseKey(adjList[u][i]->name, adjList[u][i]->weight);
//         }
//       }
//       weight += vertices[u]->key;
//       cout << u << " " << vertices[u]->pi << " " << vertices[u]->key << endl;
//     }
//     cout << weight << endl;
//   }
// private:
//   class Vertex {
//   public:
//     string pi;
//     int key;
//     string name;
//   };
//   class Neighbor {
//   public:
//     string name;
//     int weight;
//   };
//   int sizeV = 0;
//   map<string, Vertex*> vertices;
//   map<string, vector<Neighbor*>> adjList;
//   MinPriorityQ minQ;
// };

class Graph {
public:
  void addV(string name) {
    Vertex* v = new Vertex();
    v->pi = "NIL";
    v->key = 1000;
    vertices[name] = v;
    sizeV++;
  }
  void addE(string v1, string v2, int wt) {
    Neighbor* n1 = new Neighbor();
    n1->name = v2;
    n1->weight = wt;
    Neighbor* n2 = new Neighbor();
    n2->name = v1;
    n2->weight = wt;
    adjList[v1].push_back(n1);
    adjList[v2].push_back(n2);
  }
  void print() {
    for (map<string, Vertex*>::iterator it = vertices.begin();
      it != vertices.end(); it++) {
      cout << it->first << " : ";
      for (int i = 0; i != adjList[it->first].size(); i++) {
        cout << " -- " << adjList[it->first][i]->name << " "
          << adjList[it->first][i]->weight;
      }
      cout << endl;
    }
  }
  void sort() {
      string nameTemp;
      int keyTemp,i;
      cout << "----- before sorting -----" << endl;
      for (map<string, vector<Neighbor*>>::const_iterator
        it = adjList.begin(); it != adjList.end(); ++it) {
          for (unsigned int j = 0; j < it->second.size(); j++) {
          cout << it->second[j]->name << " " << it->second[j]->weight << " --> ";
        }
        cout << endl;
      }
      for (map<string, vector<Neighbor*>>::const_iterator
        it = adjList.begin(); it != adjList.end(); ++it) {
        for (unsigned int j = 1; j < it->second.size(); j++) {
          nameTemp = it->second[j]->name;
          keyTemp = it->second[j]->weight;
          i = j - 1;
          while(i >= 0 && (it->second[i]->name > nameTemp)) {
            it->second[i+1]->name = it->second[i]->name;
            it->second[i+1]->weight = it->second[i]->weight;
            i = i - 1;
          }
         it->second[i+1]->name = nameTemp;
         it->second[i+1]->weight = keyTemp;
        }
      }
      cout << "----- after sorting -----" << endl;
      for (map<string, vector<Neighbor*>>::const_iterator
        it = adjList.begin(); it != adjList.end(); ++it) {
        for (unsigned int j = 0; j < it->second.size(); j++) {
          cout << it->second[j]->name << " " << it->second[j]->weight << " --> ";
        }
        cout << endl;
      }
      cout << "size = " << sizeV << endl;
    }
    void dijkstra(string str) {
      cout << "vertex\t" << "pi\t" << "key" << endl;
      vertices[str]->key = 0;
      for (map<string, Vertex*>::iterator it = vertices.begin();
        it != vertices.end(); it++) {
          minQ.insert(it->first, it->second->key);
      }
      string u = "";
      string v = "";
      int size = 0;
      bool isMem = false;
      int predicted_key = 0;
      while ((u = minQ.extractMin()) != "empty") {
        size = adjList[u].size();
        for (unsigned int i = 0; i < size; i++) {
          v = adjList[u][i]->name;
          isMem = minQ.isMember(v);
          predicted_key = vertices[u]->key + adjList[u][i]->weight;
          if (isMem && (predicted_key < vertices[v]->key)) {
            vertices[v]->key = predicted_key;
            vertices[v]->pi = u;
            minQ.decreaseKey(v, predicted_key);
          }
        }
        cout << u << "\t" << vertices[u]->pi << "\t" << vertices[u]->key
          << endl;
      }
    }
    void mst(string str) {
      vertices[str]->key = 0;
      for (map<string, Vertex*>::iterator it = vertices.begin();
        it != vertices.end(); it++)
        minQ.insert(it->first, it->second->key);
      bool isMem = false;
      string u = "";
      string v = "";
      int size = 0;
      int weight = 0;
      while ((u = minQ.extractMin()) != "empty") {
        size = adjList[u].size();
        for (int i = 0; i < size; i++) {
          v = adjList[u][i]->name;
          isMem = minQ.isMember(v);
          if (isMem && (adjList[u][i]->weight < vertices[v]->key)) {
            vertices[v]->key = adjList[u][i]->weight;
            vertices[v]->pi = u;
            minQ.decreaseKey(v, adjList[u][i]->weight);
          }
        }
        weight += vertices[u]->key;
        cout << u << " " << vertices[u]->pi << " " << vertices[u]->key << endl;
      }
      cout << weight << endl;
    }
private:
  class Vertex {
  public:
    string pi;
    unsigned int key;
  };
  class Neighbor {
  public:
    string name;
    unsigned int weight;
  };
  int sizeV = 0;
  map<string, Vertex*> vertices;
  map<string, vector<Neighbor*>> adjList;
  MinPriorityQ minQ;
};

#endif
