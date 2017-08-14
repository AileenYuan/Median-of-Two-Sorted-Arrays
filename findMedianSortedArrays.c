class Solution {
public:
    int GetNumIndex(int a, int b)
    {
       return (a < b) ? 1 : 2;         //return value is a pos
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Len = nums1.size();
	    int nums2Len = nums2.size();
	    int numsLength = nums1Len + nums2Len;    //get the sum length of two array
        
        vector<int> nums;
          
        if(0 == nums1Len && 0 == nums2Len)
         {
             return -1;
         }
        else{
            int nIndex = 0,nIndex1= 0, nIndex2= 0;
           
            while(nIndex1 < nums1Len && nIndex2 < nums2Len)
            {
                int a = nums1[nIndex1], b = nums2[nIndex2];
                if(1 == GetNumIndex(a, b))
                {
                    nums.push_back(nums1[nIndex1]);
                    nIndex1 ++;           
                }
                else
                {
                    nums.push_back(nums2[nIndex2]);
                    nIndex2 ++;
                }
                nIndex ++;
            }
            
            if(nums1Len == nIndex1)
            {
                while(nIndex2 < nums2Len){
                    nums.push_back(nums2[nIndex2]);
                    nIndex2 ++;
                    nIndex ++;
                }
            }
            else if(nums2Len == nIndex2)
            {
                while(nIndex1 < nums1Len){
                    nums.push_back(nums1[nIndex1]);
                    nIndex1 ++;
                    nIndex ++;
                }
            }

            double d = 0;
            if(1 == numsLength){
                d = nums[0];
            }
            else if(numsLength % 2){
                d = nums[(numsLength -1 ) / 2];
            }
            else
            {
                d =  double((nums[numsLength / 2] + nums[numsLength / 2 -1 ])) /2;
            }
            return d;
            
        }
    }
        
};
