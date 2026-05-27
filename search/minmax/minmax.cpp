#include <iostream>
using namespace std;

vector<int> findMinMax(vector<int> arr, int start, int end){
    int min, max;
    if(start == end){
        min = arr[start];
        max = arr[start];
    } else if (start + 1 == end){
        if(arr[start] < arr[end]){
            min = arr[start];
            max = arr[end];
        } else {
            min = arr[end];
            max = arr[start];
        }
    } else {
        int mid = start + (end - start) / 2;

        vector<int> left = findMinMax(arr, start, mid-1);
        vector<int> right = findMinMax(arr, mid+1, end);

        // by convention we are saving max in index 0 and min in index 1
        max = left[0] < right[0] ? right[0] : left[0];
        min = left[1] < right[1] ? left[1] : right[1];
    }

    vector<int> ans = {max, min};
    return ans;
}

int main(){
    vector<int> arr = {33, 11, 44, 55, 66, 22};
    vector<int> ans = findMinMax(arr, 0, arr.size()-1);

    cout << "min: " << ans[1] << endl << "max: " << ans[0];

    return 0;
}
