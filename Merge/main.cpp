/* file_name : main.cpp
 * author_name : Smitkumar Contractor
 * contact : smitcontractor@gmail.com
 * brief : perform mergeSort
 */
#include <iostream>

using std::cout;
using std::endl;

/* function name : merge
 * arguments : array, left index, middle index, right index
 * brief : The merge() function is used for merging two halves.
  The merge(arr, l, m, r) is key process that assumes that arr[l..m] and
  arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
 * retruns : void
 */
void merge(int* arr, int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int l[n1];
  int r[n2];
  for (int i = 0; i < n1; i++)
    l[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    r[i] = arr[middle + 1 + i];
  int j = 0;
  int k = 0;
  for (int i = left; i <= right; i++) {
    if (j != n1 && ((k == n2) || (l[j] < r[k]))) {
      arr[i] = l[j++];
    } else {
      arr[i] = r[k++];
    }
  }
}

/* function name : mergeSort
 * arguments : array, left index, right index
 * brief : Merge Sort is a Divide and Conquer algorithm. It divides input array
  in two halves, calls itself for the two halves and then merges the two sorted
  halves.
 * retruns : void
 */
void mergeSort(int* arr, int left, int right) {
  if (left >= right)
    return;
  int middle = (left + right) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle + 1, right);
  merge(arr, left, middle, right);
}

int main() {
  int arr[] = {1, 5, 2, 6, 3, 9, 4};
  int left = 0;
  int right = 6;
  mergeSort(arr, left, right);
  for (int i = 0; i <= right; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
