#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <list>

using std::map;
using std::list;
using std::cout;
using std::endl;

list<char>::iterator it;
list<char>::iterator adjit;

class Graph {
public:
  void addV(char v) {
    vrt.push_back(v);
  }
  void addE(char v1, char v2) {
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  void print() {
    it = vrt.begin();
    while (it != vrt.end()) {
      cout << *it << ": ";
      adjit = adj[*it].begin();
      while (adjit != adj[*it].end()) {
        cout << *adjit << "-";
        adjit++;
      }
      cout << endl;
      it++;
    }
    cout << endl;
  }
  void dfs(char name) {
    map<char, bool> visited;
    it = vrt.begin();
    while (it != vrt.end()) {
      visited[*it] = false;
      it++;
    }
    dfsSupp(name, visited);
    cout << endl;
  }
  void dfsSupp(char name, map<char, bool> &visited) {
    visited[name] = true;
    cout << name << " ";
    list<char>::iterator ita;
    for (ita = adj[name].begin(); ita != adj[name].end(); ++ita)
      if (!visited[*ita])
        dfsSupp(*ita, visited);
  }
  void bfs(char name) {
    map<char, bool> visited;
    it = vrt.begin();
    while (it != vrt.end()) {
      visited[*it] = false;
      it++;
    }
    visited[name] = true;
    list<char> q;
    q.push_back(name);
    while(!q.empty()) {
      char temp = q.front();
      cout << temp << " " << endl;
      q.pop_front();
      list<char>::iterator adjit;
      for (adjit = adj[temp].begin(); adjit != adj[temp].end(); ++adjit) {
        if (!visited[*adjit]) {
          q.push_back(*adjit);
          visited[*adjit] = true;
        }
      }
    }
  }
private:
  list<char> vrt;
  map<char, list<char>> adj;
};

// #include <map>
// #include <list>
//
// using std::cout;
// using std::endl;
// using std::map;
// using std::list;
//
// list<char>::iterator it;
// list<char>::iterator adjIt;
//
// class Graph {
// public:
//   void addV(char ch) {
//     vrt.push_back(ch);
//   }
//   void addE(char v1, char v2) {
//     adj[v1].push_back(v2);
//     adj[v2].push_back(v1);
//   }
//   void print() {
//     it = vrt.begin();
//     while (it != vrt.end()) {
//       cout << *it << " : ";
//       adjIt = adj[*it].begin();
//       while (adjIt != adj[*it].end()) {
//         cout << " -- " << *adjIt;
//         adjIt++;
//       }
//       it++;
//       cout << endl;
//     }
//   }
//   void dfsSupp(char ch, map<char, bool> &visited) {
//     visited[ch] = true;
//     cout << ch << " ";
//     list<char>::iterator ita;
//     ita = adj[ch].begin();
//     while (ita != adj[ch].end()) {
//       if (!visited[*ita]) {
//         dfsSupp(*ita, visited);
//       }
//       ita++;
//     }
//   }
//   void dfs(char ch) {
//     map<char, bool> visited;
//     for (it = vrt.begin(); it != vrt.end(); it++)
//       visited[*it] = false;
//     dfsSupp(ch, visited);
//     cout << endl;
//   }
//   void bfs(char ch) {
//     map<char, bool> visited;
//     for (it = vrt.begin(); it != vrt.end(); it++)
//       visited[*it] = false;
//     visited[ch] = true;
//     list<char> q;
//     q.push_back(ch);
//     char front;
//     while (!q.empty()) {
//       front = q.front();
//       cout << front << " ";
//       q.pop_front();
//       for (adjIt = adj[front].begin(); adjIt != adj[front].end(); adjIt++) {
//         if (!visited[*adjIt]) {
//           q.push_back(*adjIt);
//           visited[*adjIt] = true;
//         }
//       }
//     }
//     cout << endl;
//   }
// private:
//   list<char> vrt;
//   map<char, list<char>> adj;
// };

#endif
