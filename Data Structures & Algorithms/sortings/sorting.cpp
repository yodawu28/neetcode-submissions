#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <set>
#include <iomanip>
#include <string>

using namespace std;

void helper(vector<int> &nums, int s, int e) {
    if (s >= e) {
        return;
    }

    int i = s;

    for (int j = s; j < e; j++) {
        if (nums[j] <= nums[e]) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[e]);
    
    helper(nums, s, i - 1);
    helper(nums, i + 1, e);
}

void helperMid(vector<int>&nums, int s, int e) {
    if (s >= e) {
        return;
    }
    
    int m = (s + e) / 2;
    int l = s;
    int r = e;
    
    while (l < r) {
        // di chuyen tu trai qua phai
        while (l < r) {
            if (nums[l] >= nums[m]) {
                break;
            }
            l++;
        }
        
        while (r > -1) {
            if (nums[r] <= nums[m]) {
                break;
            }
            r--;
        }
        
        if (nums[r] == nums[m]) {
            m = l;
        } else if (nums[l] == nums[m]) {
            m = r;
        }
        swap(nums[l], nums[r]);
    }
    
    helperMid(nums, s, m-1);
    helperMid(nums, m+1, e);
}

void quickSort(vector<int> &nums) {
//    helper(nums, 0, nums.size() - 1);
    helperMid(nums, 0, nums.size() - 1);
}

void interchangeSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}

void selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int minElement = i + 1;
        for (int j = i + 1; j < nums.size()- 1; j++) {
            if (nums[minElement] > nums[j]) {
                minElement = j;
            }
        }
        if (nums[i] > nums[minElement]) {
            swap(nums[i], nums[minElement]);
        }
    }
}

void bubbleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = nums.size() - 1; j > i; j--) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}

void insertionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int x = nums[i+1];
        int j = i;
        while (j >= 0 && nums[j] >= x) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
}


void printArray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums = {7,1,9,11,3,6,8,4,5,10};
//    vector<int> nums = {6,7,5,3,8,1,4};
    quickSort(nums);
    
//    interchangeSort(nums);
    
//    selectionSort(nums);
    
//    bubbleSort(nums);
    
//    insertionSort(nums);
    
    printArray(nums);
    
    return 1;
}
