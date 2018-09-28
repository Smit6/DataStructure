#include "graph.h"

int main() {
  Graph g;
  g.addV('a');
  g.addV('b');
  g.addV('c');
  g.addV('d');
  g.addV('e');
  g.addE('a', 'b');
  g.addE('b', 'c');
  g.addE('d', 'c');
  g.addE('a', 'd');
  g.addE('d', 'e');
  // g.addV('0');
  // g.addV('1');
  // g.addV('2');
  // g.addV('3');
  // g.addE('0', '1');
  // g.addE('0', '2');
  // g.addE('1', '2');
  // g.addE('2', '0');
  // g.addE('2', '3');
  // g.addE('3', '3');
  g.print();
  g.dfs('c');
  g.bfs('c');
  return 0;
}
