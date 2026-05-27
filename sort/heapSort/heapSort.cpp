#include <iostream>
#include <vector>
using namespace std;

void swap_val(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void heapify(vector<int>& arr, int n, int i){
    while(true){
        int largest = i;
        int left = (i*2)+1;
        int right = (i*2)+2;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap_val(arr[i], arr[largest]);
            i = largest;
        } else {
            break; // heap is valid now stop sinking
        }
    }
}

void heapSort(vector<int>& arr){
    // building a max heap here
    // starting from the last non leaf which is (n/2)-1
    for(int i = (arr.size()/2)-1; i>=0; i--){
        heapify(arr, arr.size(), i);
    }

    for(int i=arr.size()-1; i>0; i--){
        // basically deleting and keeping the max of the heap to the end of the array and its staring from n-1, n-2...
        swap_val(arr[0], arr[i]);
        heapify(arr, i, 0); // i is the new size of the heap

    }    

}

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original: ";
    print(arr);

    heapSort(arr);

    cout << "Sorted:   ";
    print(arr);
    return 0;
}
