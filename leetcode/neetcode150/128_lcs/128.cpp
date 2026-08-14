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
    int n = nums.size();
    if (n == 0)
      return 0;
    int lcs = 1;

    unordered_set<int> hashset;
    for (int i = 0; i < n; i++)
      hashset.insert(nums[i]); // O(1)

    for (int x : hashset) {
      if (hashset.find(x - 1) ==
          hashset.end()) { // no number is smaller than this
        int count = 1;
        int current = x;
        while (
            hashset.find(current + 1) !=
            hashset
                .end()) { // finding whether there are numbers bigger than this
          current++;
          count++;
        }
        lcs = max(lcs, count);
      }
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
