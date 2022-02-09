#include <iostream>

using namespace std;

template<class T>
void swap(T *arr, int i, int j){
  T temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
};

template<class T>
int pivot_index(T *arr, int left, int right){
  int shift = left;
  
  for(int i=left+1; i <= right; ++i){
    if(arr[left] > arr[i]){ // Sorting in ascending order. For descending order descending order switch to arr[left] < arr[i]
      swap(arr, ++shift, i);
    }
  }

  swap(arr, shift, left);
  return shift;
};

template<class T>
void quick_sort(T *arr, int left, int right){
  if(left < right){
    int pivot = pivot_index(arr, left, right);

    quick_sort(arr, left, pivot);
    quick_sort(arr, pivot+1, right);
  }
};

template<class T>
void print_array(T *arr, int size){
  for(int i = 0; i < size ; ++i){
    cout << arr[i];
    
    if(i < size - 1)
      cout << ", ";
    else
      cout << "\n";
  }
};

int main() {
  int int_arr[] = {48,61,11,22,83,56,97,32,76};
  int size_of_int_arr = sizeof(int_arr)/sizeof(*int_arr);
  
  print_array(int_arr, size_of_int_arr);
  quick_sort(int_arr, 0, size_of_int_arr-1);
  print_array(int_arr, size_of_int_arr);

  cout << "-------------------------------" << endl;
  
  double double_arr[] = {4.8,6.1,1.1,2.2,8.3,5.6,9.7,3.2,7.6};
  int size_of_double_arr = sizeof(double_arr)/sizeof(*double_arr);

  print_array(double_arr, size_of_double_arr);
  quick_sort(double_arr, 0, size_of_double_arr-1);
  print_array(double_arr, size_of_double_arr);
  
  return 0;
}
