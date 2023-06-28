//  simple code by broot force approach
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
       
//         int n=arr.size();
//         int j=0;
//         for(int i=1;i<n;i++){
//             if(arr[j]>arr[i]){
//                 return j;
//             }

//             j++;
//         }

//         return -1;
//     }
// };


// by binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int start=0;
        int end=n-1;
         int mid=start + (end-start)/2;

        while(start<end){
           
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=start + (end-start)/2;
            
        }

        return start;
    }
};