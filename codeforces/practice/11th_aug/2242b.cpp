#include <iostream>
using namespace std;
#include <vector>

int count(vector<int> &arr, int num, int start, int end) {
  int count = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] == num)
      count++;
  }
  return count;
}

// too greedy and was not taking into consideration whether the next split can
// be true or not
/* bool check_split(vector<int> &arr) {
  int start = 0, end = 0, n = arr.size(), i = 0;
  while (i < 3 && end < arr.size()) {
    if (i == 0) {
      if (count(arr, 1, start, end) >=
          count(arr, 2, start, end) + count(arr, 3, start, end)) {
        cout << "checkkk 1 ";
        i++;
        start = end + 1;
      }
      end++;
    } else if (i == 1) {
      if (count(arr, 2, start, end) + count(arr, 1, start, end) >=
          count(arr, 3, start, end)) {
        cout << "checkkk 2 ";
        i++;
        start = end + 1;
      }
      end++;
      cout << "start: " << start << " end: " << end << " ";
    } else if (i == 2) {
      if (start <= end && end < n && start < n) {
        cout << "checkkk 3 ";
        return 1;
      }
    }
  }
  return 0;
}*/

bool check_split(vector<int> &arr) {
  int end1 = 0, n = arr.size();
  for (int end1 = 0; end1 < n - 2; end1++) {
    if (count(arr, 1, 0, end1) >=
        count(arr, 2, 0, end1) + count(arr, 3, 0, end1)) {

      for (int end2 = end1 + 1; end2 < n - 1; end2++) {
        if (count(arr, 1, end1 + 1, end2) + count(arr, 2, end1 + 1, end2) >=
            count(arr, 3, end1 + 1, end2)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  int times;
  cin >> times;
  while (times > 0) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (check_split(arr)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    times--;
  }
  return 0;
}
