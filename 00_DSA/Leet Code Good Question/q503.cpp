// 533: Next Greater Element II

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int x = nums[i % n];
            while (!st.empty() && nums[st.top()] < x) {
                res[st.top()] = x;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};