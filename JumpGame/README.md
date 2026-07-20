# Jump Game (Greedy)

Problem: Given an array of non-negative integers `nums`, where `nums[i]` is the maximum jump length from position `i`, determine if you can reach the last index starting from the first index.

Solution summary:

- Approach: Greedy. Iterate from left to right maintaining the furthest index reachable (`maxReachable`). If the current index `i` ever exceeds `maxReachable`, the last index is unreachable. Update `maxReachable = max(maxReachable, i + nums[i])`. If `maxReachable` reaches or passes the last index, return true early.

- Why it works: At each step we only need to know the maximum reachable index so far; any jump options that land at or before that index are dominated by the best reachable position.

Complexity:

- Time: O(n), where n = `nums.size()` (single pass).
- Space: O(1) extra space.

Example:

- Input: [2,3,1,1,4] -> Output: true (0->1->4)
- Input: [3,2,1,0,4] -> Output: false

Reference implementation:

See `sample.cpp` in this folder for the C++ implementation.

Quick test (one-file run):

Create a small driver or compile & run inline using a heredoc. Example driver (add below `sample.cpp` or paste into a new file):

```cpp
#include <bits/stdc++.h>
using namespace std;

// paste the Solution class from sample.cpp here

int main() {
	Solution s;
	vector<int> a1 = {2,3,1,1,4};
	cout << (s.canJump(a1) ? "true" : "false") << "\n";
	vector<int> a2 = {3,2,1,0,4};
	cout << (s.canJump(a2) ? "true" : "false") << "\n";
	return 0;
}
```

Compile & run:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o jump sample.cpp driver.cpp
./jump
```

Or combine class and `main()` into a single file and compile that.

If you'd like, I can add a ready-to-run `driver.cpp` to this folder.
