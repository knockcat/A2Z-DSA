// Largest Element in Array

// Approach 1

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxi = INT_MIN;
        for(auto itr : arr)
        {
            maxi = max(maxi,itr);
        }
        return maxi;
    }
};

// Approach 2

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        return *max_element(begin(arr),end(arr));
    }
};

// Approach 3

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        sort(begin(arr),end(arr));
        return arr[arr.size()-1];
    }
};
