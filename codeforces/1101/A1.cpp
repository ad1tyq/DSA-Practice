#include <iostream>
using namespace std;

int findMedian(vector<int> nums){
    stable_sort(nums.begin(), nums.end());
    if(nums.size() % 2 == 1) return nums[nums.size()/2];
    return (nums[nums.size()/2-1]+nums[nums.size()/2])/2;
}

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n), diff(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int median = findMedian(arr);

    int left_side = 0;
    int right_side = 0;

    for(int i=0; i<n; i++){
        diff[i] = arr[i] - median;
        if (diff[i] < 0){
            left_side++;
        } else if (diff[i] > 0){
            right_side++;
        }
    }

    return max(left_side, right_side);
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
