/*
	Name: 二分查找的各种算法 
	Author: Hao Shen 
	Date: 03/04/2020 09:19
	Description: 
*/
#include<iostream>
#include<vector> 
using namespace std;
//基本的二分查找算法的三种实现  我个人推荐以后统一使用 [0, size-1]的区间 
// 注释后的代码都是个人并不推荐的方法。 

class Solution {
public:
	// 正常查找	
    int binarySearch0(vector<int> &nums, int target) {
        int left = 0;
		int right = nums.size() - 1; 
        while(left <= right){  
        	int mid = left + ((right - left)>>1);
			if(nums[mid] == target){ 
				return mid;
			} else if(nums[mid] < target){ 
				left = mid + 1;
			} else if(nums[mid] > target){ 
				right = mid - 1;
			}
		} 
        return -1;
    }
    // 递归形式 
    int binarySearch1(vector<int> &nums, int left, int right, int target) {
		if(left > right)	return -1;
		int mid = left + ((right - left)>>1);
		if(nums[mid] == target){
			return mid;
		}else if(nums[mid] < target){
			return binarySearch1(nums, mid + 1, right, target);
		}else{
			return binarySearch1(nums, left, mid - 1, target);
		}
    }
	//	如果查找的数字有多个，请查找左边界 
    int leftBound(vector<int> &nums, int target) {
        int left = 0;
		int right = nums.size() - 1; 
        while(left <= right){  
        	int mid = left + ((right - left)>>1);
			if(nums[mid] < target){
				left = mid + 1;; 
			} else if(nums[mid] > target){ 
				right = mid - 1;
			}else{
				if(mid == 0 || nums[mid - 1] != target)	return mid;
				else
					right = mid - 1;
			}
		}
		return -1;
    }
	//   如果查找的数字有多个，请查找右边界 
	int rightBound(vector<int> &nums, int target) {
        int left = 0;
		int right = nums.size() - 1; 
        while(left <= right){  
        	int mid = left + ((right - left)>>1);
			if(nums[mid] < target){
				left = mid + 1;; 
			} else if(nums[mid] > target){ 
				right = mid - 1;
			}else{
				if(mid == nums.size() - 1 || nums[mid + 1] != target)	return mid;
				else
					left = mid + 1;
			}
		}
		return -1;
    }
    // 查找第一个大于或大于等于 target 的数  || 
	// 例如：[3,4,6,7,10]中查找第一个大于或大于等于5的数
	int searchOne(vector<int> &nums, int target) {
        int left = 0;
		int right = nums.size() - 1; 
        while(left <= right){  
        	int mid = left + ((right - left)>>1);
			if(nums[mid] >= target){
				if(mid == 0 || nums[mid - 1] < target)	return mid;
				else
					right = mid - 1; 
			}else{ 
				left = mid + 1;
			}
		}
		return -1;
    }	
    // 查找最后一个小于或小于等于 target 的数  || 
	//	例如：[3,4,6,7,10]中查找最后一个小于或小于等于5的数
	int searchTwo(vector<int> &nums, int target) {
        int left = 0;
		int right = nums.size() - 1; 
        while(left <= right){  
        	int mid = left + ((right - left)>>1);
			if(nums[mid] <= target){
				if(mid == nums.size()-1 || nums[mid + 1] > target)	return mid;
				else
					left = mid + 1; 
			}else{ 
				right = mid - 1;
			}
		}
		return -1;
    }
};


int main()
{
	vector<int> nums{1, 2, 2, 3, 5};
	Solution s = Solution() ;
	int len = s.binarySearch1(nums, 0, 4, 6);
	cout<<len;
	return 0;
}

    // 使用[0, size] 的区间 
//    int binarySearch2(vector<int> &nums, int target) {
//        int left = 0;
//		int right = nums.size(); 
//        while(left < right){  
//        	int mid = left + ((right - left)>>1);
//			if(nums[mid] == target){
//				 return mid;
//			} else if(nums[mid] < target){ 
//				left = mid + 1;
//			} else if(nums[mid] > target){ 
//				right = mid;
//			}
//		} 
//		// 例如 [1, 2]中查找 0
//		// 例如 [1, 2]中查找 3 
//        return target == nums[left] ? left : -1;
//    }

    // [2,3,3,3,4]找出第一个3出现的位置，也就是3的左边界，也就是 1，可以理解为比3小的数只有一个 
//    int leftBound1(vector<int> &nums, int target) {
//        int left = 0;
//		int right = nums.size() - 1; 
//        while(left <= right){  
//        	int mid = left + ((right - left)>>1);
//			if(nums[mid] < target){
//				left = mid + 1;; 
//			} else if(nums[mid] > target){ 
//				right = mid - 1;
//			}else if(nums[mid] = target){ 
//				right = mid - 1;
//			}
//		}
//		// 越界的情况 && 上面一种情况 
//		if(left == nums.size() || nums[left] != target)	return -1; 
//        return left;
//    }

//    int leftBound3(vector<int> &nums, int target) {
//        int left = 0;
//		int right = nums.size(); 
//        while(left < right){  
//        	int mid = left + ((right - left)>>1);
//			if(nums[mid] < target){
//				left = mid + 1; 
//			} else if(nums[mid] > target){ 
//				right = mid;
//			}else if(nums[mid] = target){ 
//				right = mid;
//			}
//		}	
//		// 越界的情况 && 上面一种情况 
//		if(left == nums.size() || nums[left] != target)	return -1; 
//        return left;
//    }
