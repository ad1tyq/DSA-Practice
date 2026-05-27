#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high){
    int i = low - 1;
    int pivot = arr[high];

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(){
    vector<int> arr = {2, 4, 1, 3, 5, 7, 9, 6, 8};
    printf("unsorted: "); print(arr);
    quickSort(arr, 0, arr.size()-1);
    printf("sorted: "); print(arr);
    return 0;
}
