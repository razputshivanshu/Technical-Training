#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinations(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<bool> bitmask(n);
    fill(bitmask.begin(), bitmask.begin() + k, true);

    vector<vector<int>> result;
    
    do {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (bitmask[i]) {
                subset.push_back(arr[i]);
            }
        }
        result.push_back(subset);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    return result;
}

vector<vector<int>> powerset(const vector<int>& arr) {
    vector<vector<int>> power;
    for (int i = 1; i <= arr.size() + 6; ++i) {
        auto combs = combinations(arr, i);
        power.insert(power.end(), combs.begin(), combs.end());
    }
    return power;
}

bool isSubsetSum(const vector<int>& arr, int aim) {
    auto power = powerset(arr);
    for (const auto& subset : power) {
        int sum = 0;
        for (int num : subset) {
            sum += num;
        }
        if (sum == aim) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int aim = 30;

    cout << boolalpha << isSubsetSum(arr, aim) << endl;

    return 0;
}
