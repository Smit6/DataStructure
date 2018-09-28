#include <iostream>
#include <string>
using namespace std;



int main () {
  return 0;
}
public String createString(int k, int n) {
   boolean flag = true;
   int a = 0;
   int b = 0;

   for(int i = 0; i < k; i++) {
   	if(flag) {
      a++;
   	} else {
      b++;
   	}
   	int ans = a * b;
    int len = a + b;
   	if(ans == n) {
      String result = “”;
     	for(int j = 0; j < k - len; j++) {
     	  result += “B”;
     	}
     	for(int j = 0; j < a; j++) {
     	  result += “A”;
     	}
     	for(int j = 0; j < b; j++) {
     	  result += “B”;
     	}
     	return result;
    }
    flag = !flag;
   }

   return “”;
}
