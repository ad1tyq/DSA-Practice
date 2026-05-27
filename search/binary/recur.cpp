#include <iostream>
using namespace std;

int binarySearch(vector<int> arr, int key, int start, int end){

    if (start <= end){
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) return binarySearch(arr, key, mid+1, end);
        return binarySearch(arr, key, start, mid-1);
    }
    return -1;
}

int main(){
	vector<int> arr = { 2, 3, 4, 10, 40 };
	int x = 10;
	int result = binarySearch(arr, x, 0, arr.size());
	if (result == -1) cout << "Element not found";
	else cout << "element present at index: " << result;
	return 0;
}
