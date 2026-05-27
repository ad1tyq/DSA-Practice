#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j=low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        // pi is the partitioning index; arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";

    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array:\n";
    print(arr);

    quickSort(arr, 0, arr.size()-1);
    cout << "\nSorted array: \n";
    print(arr);
    return 0;
}

