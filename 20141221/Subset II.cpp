/*
https://oj.leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &src)
	{
		std::sort(src.begin(), src.end());
		std::vector<std::vector<int>> des;
		std::vector<int> path;
		subsetRec(path, src, des, 0);
		return des;
	}

	void subsetRec(std::vector<int> &path,
		const std::vector<int> &src,
		std::vector<std::vector<int>> &des,
		size_t pos)
	{
		des.push_back(path);

		for (size_t ix = pos; ix != src.size(); ++ix)
		{
			if (ix > 0 && ix != pos && src[ix] == src[ix - 1])
			{
				continue;
			}

			path.push_back(src[ix]);
			subsetRec(path, src, des, ix + 1);
			path.erase(path.end() - 1);
		}
	}
};

int main(int argc, const char *argv[])
{
	Solution s;
	vector<int> src = {1,2,2};
	auto ret = s.subsetsWithDup(src);
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
1 2 2
2
2 2
*/
