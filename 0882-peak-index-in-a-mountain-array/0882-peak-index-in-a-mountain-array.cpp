class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        while(st <= end){
            int mid = (st + end) / 2;

            if(mid == st)
                return st + 1;
            else if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if(arr[mid] < arr[mid - 1])
                end = mid - 1;
            else
                st = st + 1;
        }        

        return -1; //just in case
    }
};