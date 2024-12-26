#include <iostream>
#include <vector>

using namespace std;

// 找出数组中唯一的奇数或偶数
int findUnique(vector<int>& nums) {
    int result = 0;
    bool isOddMajority = false;
    int oddCount = 0;
    
    // 先统计奇数的个数来判断是要找奇数还是偶数
    for (int num : nums) {
        if (num % 2 == 1) {
            oddCount++;
        }
    }
    
    isOddMajority = oddCount > nums.size() / 2;
    
    // 如果奇数占多数，就找偶数；如果偶数占多数，就找奇数
    for (int num : nums) {
        if (isOddMajority && num % 2 == 0) {
            result = num;
            break;
        } else if (!isOddMajority && num % 2 == 1) {
            result = num;
            break;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 3, 5, 7, 2, 9, 11}; // 2是唯一的偶数
    vector<int> nums2 = {2, 4, 6, 8, 3, 10, 12}; // 3是唯一的奇数
    
    cout << "唯一的数字是: " << findUnique(nums1) << endl; // 输出2
    cout << "唯一的数字是: " << findUnique(nums2) << endl; // 输出3
    
    return 0;
}
