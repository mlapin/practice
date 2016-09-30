#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

vector<int> argsort(const vector<int> &a) {
  vector<int> ix(a.size());
  iota(ix.begin(), ix.end(), 0);
  sort(ix.begin(), ix.end(), [&a](const int i, const int j){
    return a[i] < a[j];
  });
  return ix;
}

int main() {
  vector<int> a = {3, 5, 1, 4, 2};

  for (int i : a) cout << i << " ";
  cout << endl;

  vector<int> ix = argsort(a);
  for (int i : ix) cout << a[i] << " ";
  cout << endl;
}
