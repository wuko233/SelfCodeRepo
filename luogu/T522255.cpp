#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> nums(4);
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < 4; ++j) {
            cin >> nums[j];
        }
        sort(nums.begin(), nums.end());
        
        if (nums[0] + nums[3] == nums[1] + nums[2]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

}