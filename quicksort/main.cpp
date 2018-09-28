#include <iostream>

using std::cout;
using std::endl;
using std::swap;

// int partition(int* arr, int start, int end) {
//   int pivot = arr[end];
//   int index = start;
//   for (int i = start; i < end; i++) {
//     if (arr[i] < pivot) {
//       swap(arr[i], arr[index]);
//       index++;
//     }
//   }
//   swap(arr[index], arr[end]);
//   return index;
// }
//
// void quickSort(int* arr, int start, int end) {
//   if (start >= end)
//     return;
//   int pivot = partition(arr, start, end);
//   quickSort(arr, start, pivot - 1);
//   quickSort(arr, pivot + 1, end);
// }

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
