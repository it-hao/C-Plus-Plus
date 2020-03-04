/*
	Name: ���ֲ��ҵĸ����㷨 
	Author: Hao Shen 
	Date: 03/04/2020 09:19
	Description: 
*/
#include<iostream>
#include<vector> 
using namespace std;
//�����Ķ��ֲ����㷨������ʵ��  �Ҹ����Ƽ��Ժ�ͳһʹ�� [0, size-1]������ 
// ע�ͺ�Ĵ��붼�Ǹ��˲����Ƽ��ķ����� 

class Solution {
public:
	// ��������	
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
    // �ݹ���ʽ 
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
	//	������ҵ������ж�����������߽� 
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
	//   ������ҵ������ж����������ұ߽� 
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
    // ���ҵ�һ�����ڻ���ڵ��� target ����  || 
	// ���磺[3,4,6,7,10]�в��ҵ�һ�����ڻ���ڵ���5����
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
    // �������һ��С�ڻ�С�ڵ��� target ����  || 
	//	���磺[3,4,6,7,10]�в������һ��С�ڻ�С�ڵ���5����
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

    // ʹ��[0, size] ������ 
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
//		// ���� [1, 2]�в��� 0
//		// ���� [1, 2]�в��� 3 
//        return target == nums[left] ? left : -1;
//    }

    // [2,3,3,3,4]�ҳ���һ��3���ֵ�λ�ã�Ҳ����3����߽磬Ҳ���� 1���������Ϊ��3С����ֻ��һ�� 
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
//		// Խ������ && ����һ����� 
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
//		// Խ������ && ����һ����� 
//		if(left == nums.size() || nums[left] != target)	return -1; 
//        return left;
//    }
