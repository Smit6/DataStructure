#include <iostream>
#include "hash.h"

int main() {
  Hash h;
  h.hash_insert("smit");
  h.print();
  h.remove_("smit");
  h.print();
  h.hash_insert("lalu");
  h.hash_insert("jambu");
  h.hash_insert("lambu");
  h.hash_insert("bandu");
  h.hash_insert("janto");
  h.hash_insert("ramu");
  h.hash_insert("bamu");
  h.hash_insert("gamu");
  h.hash_insert("daku");
  h.hash_insert("feku");
  h.print();
  h.remove_("gamu");
  h.print();
  return 0;
}
