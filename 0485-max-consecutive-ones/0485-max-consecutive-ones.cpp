class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int consi = 0;
        for(int i=0 ;i<nums.size();i++){
            if (nums[i]==1){
                consi++;
                maxi =max(maxi,consi); 
            }
            else{
                consi = 0;
            }
        }
        return maxi;
    }

};