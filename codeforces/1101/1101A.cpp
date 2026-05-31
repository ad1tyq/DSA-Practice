#include <iostream>
using namespace std;
#include <algorithm>

int findMedian(vector<int> nums){
    stable_sort(nums.begin(), nums.end());
    if(nums.size() % 2 == 1) return nums[nums.size()/2];
    return (nums[nums.size()/2-1]+nums[nums.size()/2])/2;
}

void bubble_sort(vector<int>& diff, vector<int>& positions){
    for(int i=0; i<diff.size(); i++){
        for(int j = 0; j<diff.size()-1-i; j++){
            if(diff[j] > diff[j+1]){
                int temp1 = diff[j+1], temp2 = positions[j+1];
                diff[j+1] = diff[j]; positions[j+1] = positions[j];
                diff[j] = temp1; positions[j] = temp2;
            }
        }
    }
}

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n), diff(n), positions(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        positions[i] = i;
    }

    int median = findMedian(arr);

    for(int i=0; i<n; i++) {
        diff[i] = arr[i] - median;
        if (diff[i] < 0){
            diff[i] *= -1;
        }
    }

    bubble_sort(diff, positions);
    
    int double_changes = 0;
    for(int i=0; i<n; i++){
        if(diff[i]>0){
            i++;
            double_changes++;
        }
    }

    return double_changes;

    return 0;
}

int main(){
    int t, i=0;
    cin >> t;
    vector<int> a(t);
    while(t--){
        a[i++] = solve();
    }
    for(i=0; i<a.size(); i++){
        cout << a[i] << "\n";
    }

}
