#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void findNearestSum(vector<int>& arr, int target, int currentSum, int& nearest) {
    if (currentSum == target) {
        nearest = currentSum;
        return;
    }

    if (currentSum > target) {
        nearest = min(nearest, currentSum);
        return;
    }

    for (int i = 0; i < arr.size(); ++i) {
        findNearestSum(arr, target, currentSum + arr[i], nearest);
        if (nearest == target) // if nearest is already equal to target, no need to explore further
            return;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, target;
        cin >> n >> target;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int nearest = INT_MAX; 

        findNearestSum(arr, target, 0, nearest);

       cout << nearest << endl;
    }

    return 0;
}
