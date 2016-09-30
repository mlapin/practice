#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int> map;
  for (int i = 0; i < nums.size(); ++i) {
    auto item = map.find(nums[i]);
    if (item != map.end()) {
      return {item->second, i};
    }
    map[target - nums[i]] = i;
  }
  return {};
}

vector<int> twoSum1(vector<int>& a, int b) {
  int n = a.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] + a[j] == b) return {i, j};
    }
  }
  return {};
}

int main() {
  vector<int> a({7, 2, 3, 4, 5});
  int b = 6;
  vector<int> ind = twoSum(a, b);
  if (ind.size() > 0) {
    cout << "indexes: " << ind[0] << " " << ind[1] << endl;
    cout << a[ind[0]] << " + " << a[ind[1]] << " = " << a[ind[0]] + a[ind[1]] << endl;
  } else {
    cout << "no solution" << endl;
  }
}
