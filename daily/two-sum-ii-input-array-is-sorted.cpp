class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int p1=0,p2=numbers.size()-1;
        while(p1<p2){
            if(numbers[p1]+numbers[p2]==target){
                ans.push_back(p1+1);
                ans.push_back(p2+1);
                break;
            }else if(numbers[p1]+numbers[p2]<target)p1++;
            else p2--;
        }
        return ans;
    }
};
