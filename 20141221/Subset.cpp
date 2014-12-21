/*
http://www.lintcode.com/en/problem/subsets/
Subsets

Given a set of distinct integers, return all possible subsets.

Note
Elements in a subset must be in non-descending order.

The solution set must not contain duplicate subsets.

Example
If S = [1,2,3], a solution is:

[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &source)
	{
		// meet the requirement of "Elements in a subset must be in non-descending order".
		sort(source.begin(), source.end());

		vector<int> path;
		vector<vector<int>> target;

		subsetRec(path, source, target, 0);
		return target;
	}


	void subsetRec(vector<int> &path,
		           vector<int> &source,
		           vector<vector<int>> &target,
		           size_t pos)
	{
		target.push_back(path);

		for (size_t ix = pos; ix != source.size(); ++ix)
		{
			path.push_back(source[ix]);
			subsetRec(path, source, target, ix + 1);

			// backTracing
			path.erase(path.end() - 1);
		}
	}
};

int main(int argc, const char *argv[])
{
	Solution s;
	vector<int> src = {3,1,2};
	auto ret = s.subsets(src);
	for (const auto &vec : ret)
	{
		for (const auto &digit : vec)
		{
			cout << digit << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

/*
output:

1
1 2
1 2 3
1 3
2
2 3
3
*/
