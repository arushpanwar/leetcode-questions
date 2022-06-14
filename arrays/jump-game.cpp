class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0,end=0;
        while(curr<=end){
            end=max(end,nums[curr]+curr);
            curr++;
            if(end>=nums.size()-1)return true;
        }
        return false;
    }
};
