# Jump Game II (Greedy)

Problem: Given an array of non-negative integers `nums`, where `nums[i]` is the maximum jump length from position `i`, return the minimum number of jumps required to reach the last index starting from the first index.

Solution summary:

- Approach: Greedy (level-based). Iterate through the array maintaining the current jump's reachable range (`currEnd`) and the farthest index reachable within the next jump (`farthest`). For each index `i`, update `farthest = max(farthest, i + nums[i])`. When `i` reaches `currEnd`, a jump is required: increment `jumps` and set `currEnd = farthest`.

- Edge cases: If the array length is 0 or 1, the answer is 0 (no jumps needed).

Why it works: The algorithm expands reachable ranges jump by jump and always chooses the farthest possible reach within the current window before increasing the jump count, which yields the minimum number of jumps.

Complexity:

- Time: O(n) — single pass through the array.
- Space: O(1) extra space.

Example:

- Input: [2,3,1,1,4] -> Output: 2 (0->1->4)
- Input: [2,3,0,1,4] -> Output: 2

Reference implementation:

See `sample.cpp` in this folder for the C++ implementation.

Quick test (driver):

Create a small `driver.cpp` or append a `main()` to test the `Solution` class. Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

// paste the Solution class from sample.cpp here

int main() {
	Solution s;
	vector<int> a1 = {2,3,1,1,4};
	cout << s.jump(a1) << "\n"; // 2
	vector<int> a2 = {2,3,0,1,4};
	cout << s.jump(a2) << "\n"; // 2
	return 0;
}
```

Compile & run:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o jump sample.cpp driver.cpp
./jump
```

If you want, I can add a ready-to-run `driver.cpp` file to this folder.
