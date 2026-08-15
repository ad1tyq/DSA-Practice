#include <functional>
#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

class Solution {
public:
  // lowkey was very proud for using recursion but then forgot to take
  // complexity into account lmao
  /*int consecutive(vector<int> arr, int num) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (arr[i] == num + 1)
        return 1 + consecutive(arr, num + 1);
    }
    return 1;
  }

  int longestConsecutive(vector<int> &nums) {
    int lcs = 0, consec = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      consec = consecutive(nums, nums[i]);
      if (lcs < consec)
        lcs = consec;
    }
    return lcs;
  }*/

  int longestConsecutive(vector<int> &nums) {
    int lcs = 0, n = nums.size(), count = 0, current = 0;
    // make an unordered set and thats O(1)
    unordered_set<int> hashset;
    for (int i = 0; i < n; i++) {
      hashset.insert(nums[i]);
    }
    // now traverse through it to see whether there is a nums[i]-1 there or now
    for (int x : hashset) {
      // trying to check whether there is any number smaller than the current
      // value and if not then we will start checking its sequence
      if (hashset.find(x - 1) == hashset.end()) {
        count = 1;
        current = x;
        // checking whether there is a value in the next sequence of this value
        while (hashset.find(current + 1) != hashset.end()) {
          current++;
          count++;
        }
      }
      lcs = max(lcs, count);
    }
    return lcs;
  }
};

int main() {
  int n;
  cout << "enter size: ";
  cin >> n;
  vector<int> nums(n);
  cout << "enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  Solution sol;
  int lcs = sol.longestConsecutive(nums);
  cout << "lcs: " << lcs;
  return 0;
}
