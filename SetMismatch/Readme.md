
# Set Mismatch

Given an array `nums` containing `n` integers where the numbers are supposed to be from `1` to `n`, one number in `nums` appears twice (duplicate) and one number is missing. Return `{duplicate, missing}`.

## Approach (sample.cpp) — Frequency array

- Create a frequency vector `freq` of size `n+1` initialized to `0`.
- Count occurrences of each number in `nums`.
- The duplicated number is the one with `freq[i] == 2` and the missing number has `freq[i] == 0`.

This approach is simple, robust, and runs in a single pass after counting.

### Complexity (sample.cpp)

- Time: O(n) — one pass to count and one pass to scan counts.
- Space: O(n) — the auxiliary frequency array of size `n+1`.

## Alternative (sample1.cpp) — Mathematical (sum + sum of squares)

Use arithmetic to derive the duplicate and missing numbers without extra arrays:

- Let S = sum(1..n) and P = sum of squares 1^2..n^2.
- Let S' = sum(nums) and P' = sum of squares of elements in `nums`.
- Then diff = S' - S = duplicate - missing.
- And sqdiff = P' - P = duplicate^2 - missing^2 = (duplicate - missing) * (duplicate + missing) = diff * (duplicate + missing).
- From these two equations solve for `duplicate` and `missing`.

This method uses constant extra space and is numerically safe for typical 32-bit limits when using 64-bit intermediate types.

### Complexity (sample1.cpp)

- Time: O(n)
- Space: O(1)

## Alternative (sample2.cpp) — In-place index marking

Modify the input array (or a copy) to mark seen numbers by flipping the sign at their corresponding index:

- For each value `val` in `nums`, let `idx = abs(val) - 1`.
- If `nums[idx]` is already negative, `abs(val)` is the duplicate.
- Otherwise, set `nums[idx] = -nums[idx]` to mark it seen.
- After the pass, the index `i` with a positive `nums[i]` indicates the missing number `i+1`.

This method runs in linear time and uses constant extra space, but it destroys (mutates) the input array.

### Complexity (sample2.cpp)

- Time: O(n)
- Space: O(1) (in-place; O(n) if you first copy the input to avoid mutating it)

## Other Notes

- Sorting `nums` and scanning for the duplicate/missing is another valid approach: Time O(n log n), Space O(1) if sorting in-place.
- Choose the approach based on constraints: if low extra memory is required, prefer the mathematical or in-place methods; if simplicity and clarity are priorities, the frequency-array approach (`sample.cpp`) is straightforward.

