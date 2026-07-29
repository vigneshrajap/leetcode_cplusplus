# Max Increase to Keep City Skyline

## Problem Explanation

You are given an $n \times n$ grid that represents the heights of buildings in a city. Each building can be increased in height, but the increase must not make any building taller than the maximum height visible from its row or column skyline.

For each cell, the row skyline is the maximum height in that row, and the column skyline is the maximum height in that column. A building at position $(i, j)$ can be increased only up to:

$$
\min(\text{rowMax}[i], \text{colMax}[j])
$$

The goal is to find the total amount by which all buildings can be increased while preserving the skyline constraints.

## What Needs to Be Solved

We need to compute the maximum possible increase for every building such that:

- each building height does not exceed the maximum height of its row,
- each building height does not exceed the maximum height of its column,
- and the total increase across the whole grid is maximized.

In other words, for each building we add the difference between the allowed maximum height and its current height, but only if that value is positive.

## How the Solution Works

The approach uses two arrays:

- `row_max[i]`: the maximum height in row `i`
- `col_max[j]`: the maximum height in column `j`

These values are computed in a single pass over the grid.

After that, each cell is evaluated using:

$$
\text{increase} = \min(\text{rowMax}[i], \text{colMax}[j]) - \text{grid}[i][j]
$$

If this value is positive, it means the building can be increased by that amount without breaking the skyline rule. The sum of all such increases is returned.

This works because the tallest building that can be visible from either the row or the column side is the minimum of those two skyline limits.

## Complexity Analysis

Let $n$ be the size of the grid.

- Time complexity: $O(n^2)$
  - We inspect every cell a constant number of times.
- Space complexity: $O(n)$
  - We store one array for row maxima and one array for column maxima.

This is efficient for the problem because the grid is square and the solution avoids any unnecessary recomputation.
