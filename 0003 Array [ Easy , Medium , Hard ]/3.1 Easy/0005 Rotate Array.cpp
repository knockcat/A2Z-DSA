// Rotate Array

// LeetCode

// Approach 1 Time O(n) Space O(n)

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i)
        {
            ans[(i + k) % n] = nums[i];
        }

        nums = ans;
    }
};

// Approach 2 Time O(n) Space O(1)

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        k %= nums.size();
        reverse(begin(nums), end(nums));
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};

// Geeks For Geeks

class Solution
{
public:
    void leftRotate(int arr[], int k, int n)
    {
        // Your code goes here

        k %= n;
        reverse(arr, arr + k);
        reverse(arr + k, arr + n);
        reverse(arr, arr + n);
    }
};