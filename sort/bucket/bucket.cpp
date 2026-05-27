#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<float>& arr){
   if(arr.empty()) return;

   vector< vector<float> > buckets(arr.size());

   for(int i=0; i<arr.size(); i++){
       int bucketIndex = arr.size() * arr[i];
       buckets[bucketIndex].push_back(arr[i]);
   }

   // sorting individual buckets using insertion cause its faster than merge & quick cause here there are usually 3-4 elements per bucket
   for(int i=0; i<arr.size(); i++){
       // insertion sort
       for(int j=1; j<buckets[i].size(); j++){
           float key = buckets[i][j];
           int k = j - 1;
           while(k>=0 && buckets[i][k] > key){
               buckets[i][k+1] = buckets[i][k];
               k--;
           }
           buckets[i][k+1] = key;
       }
   }

   int index = 0;
   for(int i=0; i<arr.size(); i++){
       for(int j=0; j<buckets[i].size(); j++){
           arr[index++] = buckets[i][j];
       }
   }
}

void print(vector<float>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";

    }
}

int main(){
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    cout << "Original array:\n";
    print(arr);
    bucketSort(arr);
    cout << "\nSorted array: \n";
    print(arr);
    return 0;
}
