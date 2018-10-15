/* file_name : main.cpp
 * author_name : Smitkumar Contractor
 * contact : smitcontractor@gmail.com
 * brief : perform quickSort
 */
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

/* function name : partition
 * arguments : array, begin and end index
 * brief : The key process in quickSort is partition(). Target of partitions is,
  given an array and an element x of array as pivot, put x at its correct
  position in sorted array and put all smaller elements (smaller than x) before
  x, and put all greater elements (greater than x) after x. All this should be
  done in linear time.
 * retruns : void
 */
int partition(int* arr, int begin , int end) {
  int pivot = arr[end];
  int index = begin;
  for (int i = begin; i < end; i++) {
    if (arr[i] < pivot) {
      swap(arr[i], arr[index]);
      index++;
    }
  }
  swap(arr[index], arr[end]);
  return index;
}

/* function name : quickSort
 * arguments : array, begin and end index
 * brief : QuickSort is a Divide and Conquer algorithm. It picks an element as
  pivot and partitions the given array around the picked pivot. There are many
  different versions of quickSort that pick pivot in different ways.
 * retruns : void
 */
void quickSort(int* arr, int begin, int end) {
  if (begin >= end)
    return;
  int pivot = partition(arr, begin ,end);
  quickSort(arr, begin, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

int main() {
  int start = 0;
  int end = 7;
  int arr[8] = {7, 2, 1, 6, 8, 5, 3, 4};
  quickSort(arr, start, end);
  for (int i = 0; i <= end; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
