class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int index=abs(nums[i]);
            if(nums[index]>0){
                //then we will mark it negative
                nums[index]*=-1;
            }
            else{
                //this means it is already negative
                // so we will return that index
                return index;
            }
        }
        return -1;
    }
};