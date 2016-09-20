#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

int threeSumClosestBruteForce(vector<int>& a, int target) {
    int n = a.size(), sum = 0, dist = numeric_limits<int>::max();
    int a1 = 0, a2 = 0, a3 = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                int s = a[i] + a[j] + a[k];
                int d = abs(s - target);
                if (d < dist) {
                    dist = d;
                    sum = s;
                    a1 = a[i]; a2 = a[j]; a3 = a[k];
                }
                if (d == 0) {
                    j = n; i = n;
                    break;
                }
            }
        }
    }
    cout << "best sum: " << sum << " (target: " << target << ")" << endl;
    cout << a1 << "\t" << a2 << "\t" << a3 << endl;
    return sum;
}

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size(), sum = 0, dist = numeric_limits<int>::max();
    vector<int> a(nums);
    sort(a.begin(), a.end());
    for (int i = 0, ai = numeric_limits<int>::max(); i < n-2; ++i) {
        if (a[i] == ai) continue;
        ai = a[i];
        int j = i+1, k = n-1, s = a[i] + a[j] + a[k], d = abs(s - target);
        if (d < dist) {
            dist = d;
            sum = s;
        }
        while (j < k-1) {
            if (s < target) {
                s -= a[j++];
                s += a[j];
            } else if (s > target) {
                s -= a[k--];
                s += a[k];
            } else {
                return s;
            }
            d = abs(s - target);
            if (d < dist) {
                dist = d;
                sum = s;
            }
        }
    }
    return sum;
}

int main() {
    //vector<int> a({87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4});
    //int target = -275;

    vector<int> a({56,57,-47,-14,23,31,20,39,-51,7,-4,43,-53,32,24,56,-28,90,-75,-6,21,-100,41,-84,95,95,44,84,70,-22,-86,-6,90,-87,65,-28,-29,-94,98,-28,-100,23,-25,6,-56,-54,-5,53,-88,-25,-31,-71,-13,-62,73,-35,-78,16,99,97,84,-27,-43,-50,18,-16,-61,7,-17,16,-92,28,43,-38,-33,-27,84,-72,-100,-91,-97,-99,59,-63,73,99,98,-100,-37,-80,3,18,93,-81,12,-75,-43,99,10,10,-6,13,0,76,-82,-5,27,-38,-81,77,-55,-100,90,-32,-25,-15,-16,68,-6,87,65,-38,82,78,-61,87,-72,46,50,-60,86,39,69,85,-49,28});
    int target = -289;

    threeSumClosestBruteForce(a, target);

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto sum = threeSumClosest(a, target);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "best sum: " << sum << " (target: " << target << ")" << endl;
}
