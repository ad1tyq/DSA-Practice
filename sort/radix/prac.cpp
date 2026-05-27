#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr, int exp){
    vector<int> output(arr.size());
    int count[10] = {0};

    for(int i=0; i<arr.size(); i++) count[(arr[i]/exp)%10]++;
    for(int i=1; i<10; i++) count[i] += count[i-1];

    for(int i=arr.size()-1; i>=0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr){
   if (arr.empty()) return;

   int max_val = arr[0];
   for(int i=0; i<arr.size(); i++) if(arr[i] > max_val) max_val = arr[i];

   for(int exp = 1; max_val/exp > 0; exp *= 10) countSort(arr, exp);
}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";

    }
}

int main(){
    vector<int> arr = {53, 89, 150, 36, 633, 233};
    cout << "Original array:\n";
    print(arr);
    radixSort(arr);
    cout << "\nSorted array: \n";
    print(arr);
    return 0;
}
