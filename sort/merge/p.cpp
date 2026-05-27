#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector <int>& arr, int low, int mid, int high){
    int n1 = mid + 1 - low;
    int n2 = high - mid;
    
    vector <int> L(n1), R(n2);
    for(int i=0; i<n1; i++) L[i] = arr[low+i];
    for(int i=0; i<n2; i++) R[i] = arr[mid+1+i];

    int i=0, j=0, k=low;

    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++, k++;
        } else {
            arr[k] = R[j];
            j++, k++;
        }
    }

    while(i<n1){
        arr[k] = L[i];
        i++, k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++, k++;
    }


}

void mergeSort(vector<int>& arr, int low, int high){
    if (low < high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        mergeSort(arr, low, mid, high);
    }
}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(){
    vector<int> arr = {3, 7, 8, 5, 4, 2, 6, 1};
    printf("unsorted: "); print(arr);
    mergeSort(arr, 0, arr.size()-1);
    printf("sorted: "); print(arr);
    return 0;
}
