#include <iostream>
#include <vector>
#include <climits>

std::vector<int> getSecondOrderElements(int n, std::vector<int> arr) {
    
    int f1 = arr[0];
    int s1 = INT_MAX;

    int f2 = arr[0];
    int s2 = INT_MIN;

    for (int i = 1; i < n; i++) {
        
         if (arr[i] < f1) {
             s1 = f1;
             f1 = arr[i];
         }     
         else if (arr[i] > f1 && arr[i] < s1) {
             s1 = arr[i];
         }

         if (arr[i] > f2) {
             s2 = f2;
             f2 = arr[i];
         }     
         else if (arr[i] < f2 && arr[i] > s2) {
             s2 = arr[i];
         }
    }

    return {s2, s1};
}


