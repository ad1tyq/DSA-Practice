#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr){
    int max_val = arr[0];
    for(int i=0; i<arr.size(); i++) if(arr[i]>max_val) max_val = arr[i];
    
    vector<int> count(max_val+1);
    for(int i=0; i<count.size(); i++) count[i] = 0;

    for(int i=0; i<arr.size(); i++) count[arr[i]]++;
    for(int i=1; i<count.size(); i++) count[i] += count[i-1];

    vector<int> output(arr.size());
    for(int i=arr.size()-1; i>=0; i--){
        int num = arr[i];
        int index = count[num]-1;
        output[index] = num;
        count[num]--;
    }
    arr = output;
}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";

    }
}

int main(){
    vector<int> arr = {1, 0, 3, 1, 3, 1};
    cout << "Original array:\n";
    print(arr);
    countSort(arr);
    cout << "\nSorted array: \n";
    print(arr);
    return 0;
}
