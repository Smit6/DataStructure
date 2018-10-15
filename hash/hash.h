/* file_name : hash.h
 * author_name : Smitkumar Contractor
 * contact : smitcontractor@gmail.com
 * brief : performs a hash class and it's procedures
 */
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
  /* function name : hashFunc
   * arguments : string to get hash code
   * brief : generates a number for a string given as an argumet.
    performs some bit randomization to get better results
   * retruns : int
   */
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
  /* function name : hash_insert
   * arguments : string to insert in to hashTable
   * brief : generates a number for a string given as an argumet.
    performs some bit randomization to get better results
   * retruns : void
   */
  void hash_insert(string name) {
    int number = hashFunc(name);
    hashTable[number].push_back(name);
  }
  /* function name : print
   * arguments : none
   * brief : prints hashTable
   * retruns : void
   */
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
  /* function name : remove_
   * arguments : string
   * brief : remove's a string from a hashTable
   * retruns : void
   */
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

#endif
