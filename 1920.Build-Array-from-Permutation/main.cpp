#include<iostream>
#include<vector>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
	vector<int> temp = nums;
	for (int i = 0; i < nums.size(); ++i) {
		temp[i] = nums[nums[i]];
	}

	return temp;
}


int main() {

	vector<int> nums = { 0, 2, 1, 5, 3, 4 };
	vector<int> result = buildArray(nums);

	for (int i : result) {
		cout << i << " ";
	}

	return 0;
}