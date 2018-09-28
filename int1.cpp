// includes
#include <iostream>
#include <string>

// using statemets
using std::cout;
using std::endl;
using std::string;

/* @function_name :
 *
 * @brief :
 *
 * @param :
 *
 * @return :
 */
 bool solution(int total_money, int total_damage, vector<int> &costs, vector<int> &damages) {
   int size = costs.size();
      int tempInt;
      float tempFloat;
      vector<int> damageCosts[size];
      // Here we are constructing the damagecosts array by damage / costs to know which cost is better to damage
      for (int i = 0; i < size; i++) {
        damageCosts[i] = damages[i] / costs[i];
      }
      // We are sorting the costs and damages with respect to the damageCosts by using bubble sort algorithm
      for (int i = 0; i < size - 1; i++) {
          for (int j = 0; j < size - i - 1; j++) {
              if (damageCosts[j] < damageCosts[j + 1]) {
                  //Here we are swapping the data using tempFloat data variable
                  tempFloat = damageCosts[j];
                  damageCosts[j] = damageCosts[j + 1];
                  damageCosts[j + 1] = tempFloat;
                  // above 3 line for sorting damage costs

                  //Here we are swapping the data using tempInt data variable
                  tempInt = damages[j];
                  damages[j] = damages[j + 1];
                  damages[j + 1] = tempInt;
                  // above 3 for sorting damages

                  //Here we are swapping the data using tempInt data variable
                  tempInt = costs[j];
                  costs[j] = costs[j + 1];
                  costs[j + 1] = tempInt;
                  // above 3 for sorting costs
              }
          }
      }
   double key3;
   int i, key2, key3, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           ratio[j+1] = ratio[j];
           j = j-1;
       }
       ratio[j+1] = key;
   }


      int ind = 0;
      boolean damagable = false;
      // Now we are checking are we able to damage the openent or not
      while (total_money > 0) {
          // Here we are subtracting the best from the total money so that we will know whether we can damage or not
          total_money -= costs[ind];
          // And we also removing best damage from total damages so that we will know whether we can or not damage
          total_damage -= damages[ind];
          if (total_damage <= 0) {
              damagable = true;
              break;
          }
      }

      return damagable;
 }

int main () {
  return 0;
}
