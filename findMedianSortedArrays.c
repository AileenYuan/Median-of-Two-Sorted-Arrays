class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int nums1Len = nums1.size();
	     int nums2Len = nums2.size();
	     int numsLength = nums1Len + nums2Len;
	     vector<int> nums;// = new int(numsLength);
	     int nIndexBegin = 0;  //, nNumsPos = 0;
	     for(int i1 = 0; i1 < nums1Len; i1++){
		    for(int i2 = nIndexBegin; i2 < nums2Len; i2++){
			    if(nums1[i1] > nums2[i2]){
				    nums.push_back(nums2[i2]);
				   // nNumsPos ++;
			    }
			    else
			    {
				    nums.push_back(nums2[i1]);
				   // nNumsPos ++;
				    nIndexBegin = i2;
				    break;
			    }
		    }
	    }
	    double d = 0;
	    if(numsLength % 2){
		    d =  ((nums[(numsLength -1 ) / 2] + nums[(numsLength -1 ) / 2 -1 ]) /2);
	    }
	    else
	    {
		    d = nums[(numsLength -1 ) / 2];
	    }
	    return d;
        
    }
};
