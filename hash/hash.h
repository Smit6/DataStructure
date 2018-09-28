#ifndef __HASH_H
#define __HASH_H
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;

list<string>::iterator it;

class Hash {
public:
  int hashFunc(string ins) {
    unsigned int numberHash = 0;
  	unsigned int x = 0;
  	for (unsigned int i = 0; i < ins.length(); i++) {
  		numberHash = (numberHash << 5) + (unsigned int)(ins[i]);
  		if ((x = numberHash & 0xFF000000) != 0)
  			numberHash ^= (x >> 15);
  		numberHash &= ~x;
  	}
  	return numberHash % 10;
  }
  void hash_insert(string name) {
    int number = hashFunc(name);
    hashTable[number].push_back(name);
  }
  void print() {
    for (int i = 0; i < 10; i++) {
      cout << i << " :";
      it = hashTable[i].begin();
      while (it != hashTable[i].end()) {
        cout << " --> " << *it;
        it++;
      }
      cout << endl;
    }
    cout << "-------" << endl;
  }
  void remove_(string name) {
    int number = hashFunc(name);
    it = hashTable[number].begin();
    while (it != hashTable[number].end()) {
      if (*it == name) {
        hashTable[number].erase(it);
        break;
      }
      it++;
    }
  }
private:
  list<string> hashTable[10];
};

// #include <list>
// #include <iostream>
//
// using std::list;
// using std::cout;
// using std::endl;
// using std::string;
//
// list<string>::iterator it;
//
// class Hash {
// public:
//   int hashFunc(string ins) {
//     unsigned int numberHash = 0;
//   	unsigned int x = 0;
//   	for (unsigned int i = 0; i < ins.length(); i++) {
//   		numberHash = (numberHash << 5) + (unsigned int)(ins[i]);
//   		if ((x = numberHash & 0xFF000000) != 0)
//   			numberHash ^= (x >> 15);
//   		numberHash &= ~x;
//   	}
//   	return numberHash % 10;
//   }
//   void hash_insert(string str) {
//     int number = hashFunc(str);
//     hashTable[number].push_back(str);
//   }
//   void print() {
//     cout << "------------------------" << endl;
//     for (int i = 0; i < 10; i++) {
//       it = hashTable[i].begin();
//       cout << i << " ---> ";
//       while (it != hashTable[i].end()) {
//         cout << *it << " -- ";
//         it++;
//       }
//       cout << endl;
//     }
//     cout << "------------------------" << endl;
//   }
//   void remove_(string str) {
//     int number = hashFunc(str);
//     it = hashTable[number].begin();
//     while (it != hashTable[number].end()) {
//       if (*it == str) {
//         hashTable[number].erase(it);
//         break;
//       }
//       it++;
//     }
//   }
// private:
//   list<string> hashTable[10];
// };

#endif
