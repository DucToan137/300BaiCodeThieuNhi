#include<iostream>
#include<vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	int max = *max_element(candies.begin(), candies.end());

	vector<bool> res;
	for(int i=0; i<candies.size(); ++i) {
		if(candies[i] + extraCandies >= max) {
			res.push_back(true);
		}
		else {
			res.push_back(false);
		}
	}

	return res;
}

int main() {

	return 0;
}