// Second Largest

// Approach 1

class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        // code here

        int maxi, smaxi;
        maxi = smaxi = INT_MIN;

        for (int i = 0; i < n; ++i)
            maxi = max(maxi, arr[i]);

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > smaxi and arr[i] != maxi)
                smaxi = arr[i];
        }

        if (smaxi == INT_MIN)
            return -1;
        return smaxi;
    }
};

// Approach 2

class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        // code here

        sort(arr, arr + n);

        int val = arr[n - 1];

        int idx = n - 1;

        while (arr[idx] == val)
            --idx;

        if (idx == -1)
            return -1;
        else
            return arr[idx];
    }
};

// Approach 3

class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        // code here

        int maxi = INT_MIN;
        int smaxi = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > maxi)
            {
                smaxi = maxi;
                maxi = arr[i];
            }
            else if (arr[i] > smaxi and arr[i] != maxi)
            {
                smaxi = arr[i];
            }
        }

        if (smaxi == INT_MIN)
            return -1;
        return smaxi;
    }
};