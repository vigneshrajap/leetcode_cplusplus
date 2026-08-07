# Number of Students Unable to Eat Lunch

You are given two arrays:
- `students`: the order in which students want to eat sandwiches
- `sandwiches`: the sequence of sandwiches available

Each student wants either a `0`-sandwich or a `1`-sandwich. A student can only take a sandwich if it matches their preference. The task is to determine how many students will remain unable to eat.

## Approach

Instead of simulating every student-sandwich interaction directly, this solution counts how many students want each type of sandwich.

1. Count how many `0`-preferring and `1`-preferring students exist.
2. Scan the sandwich queue from left to right.
3. If the current sandwich type is available, decrement the corresponding count.
4. If the preferred student count for that sandwich type is already zero, stop because no more students of that type can be served.
5. The remaining students are the ones who cannot eat.

## Why this works

Once a sandwich type is no longer available among the students who want it, the rest of the students of the other type will also be unable to eat because the queue has effectively become blocked.

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(1)
