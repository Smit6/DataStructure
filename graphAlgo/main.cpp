#include "graph.h"

int main() {
  Graph g;
  g.addV("a");
  g.addV("b");
  g.addV("c");
  g.addV("d");
  g.addV("e");
  g.addV("f");
  g.addV("g");
  g.addV("h");
  g.addV("i");
  g.addE("a", "b", 4);
  g.addE("a", "h", 8);
  g.addE("b", "c", 8);
  g.addE("b", "h", 11);
  g.addE("c", "d", 7);
  g.addE("c", "i", 2);
  g.addE("c", "f", 4);
  g.addE("d", "e", 9);
  g.addE("d", "f", 14);
  g.addE("e", "f", 10);
  g.addE("f", "g", 2);
  g.addE("g", "h", 1);
  g.addE("g", "i", 6);
  g.addE("h", "i", 7);
  g.print();
  g.sort();
  g.dijkstra("a");
  g.mst("a");
  return 0;
}
