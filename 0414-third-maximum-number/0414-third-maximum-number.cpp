class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size() ;
        // Take a set data structure and push th elements of the nums vector one by one in the set 
        // Set will ensure -> No duplicates + sort the elements from small to large 
        set<int> distinctNumbers ;
        for(int &num : nums){
            // traverse in the nums and insert elements one by one 
            distinctNumbers.insert(num) ;
        
        if(distinctNumbers.size() > 3){
            distinctNumbers.erase(distinctNumbers.begin()) ;
            }
        }
        if(distinctNumbers.size() == 3){
            return *distinctNumbers.begin() ;
        }
        else{
            // If the size of set is less than 3 then return the absolute maximum 
            // in order to return the entire set maximum element reverse the set , to get highest element in the begining and then return that !
            return *distinctNumbers.rbegin() ;
        }
        
    }
};