#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++){
        if (arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] <= pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if ( i > pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quicksort(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p+1, end);
}

int main(){
    int* array;
    int size;
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    // insertion_sort(array, size);
    quicksort(array, 0, size-1);

    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    return 0;
}