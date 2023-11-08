//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Function to check if a Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n) {
        // Create a set to store the squares of the elements
        std::unordered_set<int> squaredSet;

        // Calculate the squares of the elements and store them in the set
        for (int i = 0; i < n; i++) {
            squaredSet.insert(arr[i] * arr[i]);
        }

        // Iterate through the array and check for Pythagorean triplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sumOfSquares = arr[i] * arr[i] + arr[j] * arr[j];
                if (squaredSet.find(sumOfSquares) != squaredSet.end()) {
                    return true;
                }
            }
        }

        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends