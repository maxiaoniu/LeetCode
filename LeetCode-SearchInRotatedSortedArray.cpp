class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto first =  begin(nums);
        auto last =  end(nums);
        
        int len = last - first;
        int half;
        auto middle = first;
        
        while(len>0) {
            half = len>>1;
            middle = first + half;
            
            if(*middle == target)
                return middle-nums.begin();
            //the upper is sorted
            if(*first > *middle) {
                if(*middle < target && *(last-1)>=target) {
                    first = middle + 1;
                } else {
                    last = middle;
                }
            }
            //the bottom is sorted
            else if(*first <= *middle) {
                if(*middle > target && *first <= target) {
                    last  = middle;
                } else {
                    first  = middle + 1;
                }
            }
            len = last - first;
            
        }
        return -1;
    }
};
