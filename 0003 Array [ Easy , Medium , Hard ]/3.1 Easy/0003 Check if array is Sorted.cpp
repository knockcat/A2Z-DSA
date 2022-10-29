// Check if array is sorted

// Geeks For Geeks

class Solution
{
public:
    bool arraySortedOrNot(int arr[], int n)
    {
        // code here

        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }

        return true;
    }
};

// LeetCode

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > nums[(i + 1) % n])
                ++count;
        }

        return count <= 1;
    }
};