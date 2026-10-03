
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;

//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];

//             if (mp.find(complement) != mp.end()) {
//                 return {mp[complement], i};
//             }

//             mp[nums[i]] = i;
//         }

//         return {};
//     }
// };

// int main() {
//     Solution sol;

//     vector<int> nums = {2, 7, 11, 15};
//     int target = 9;

//     vector<int> ans = sol.twoSum(nums, target);

//     cout << "Indices: ";
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }

//     return 0;
// }