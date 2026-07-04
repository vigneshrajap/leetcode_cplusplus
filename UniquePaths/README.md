This is a "Grid DP" problem. It's an extension of the "Sequence DP" where dp[i] normally represents the max/min/best value for sequence ending at index i.

The key is that the robot can move to the right or down only. This translates to "the robot could only reach a cell from the top or left". Hence, the number of paths to reach a cell = number of paths to reach the cell to the left + number of paths to reach the cell at the top.

Let dp[r][c] represent the number of unique paths to reach cell (r, c). (r stands for row, and c stands for column. I found it more intuitive than i, j)

dp[r][c] = dp[r - 1][c] + dp[r][c - 1]

where (r - 1, c) is the cell on the top and (r, c - 1) is the cell at the left.

Looking at how we calculate our dp table, we require cells closer to the left to calculate cells closer to the right. In addition, we require cells closer to the top to calculate cells closer to the bottom. Thus, it makes sense to fill the dp matrix row by row from left to right. This way, we can guarantee that at any step, we have previously calculated the necessary cells that we may reuse the answer for.

Time Complexity: O(n * m).

Space Complexity: O(n * m).