# Finding Users Active Minutes

Given logs of user activity and an integer `k`, compute how many users have exactly `j` unique active minutes for each `j` from `1` to `k`.

## Approach

Use a map from user ID to a set of unique minutes and then count frequencies.

### Idea

1. For each log entry, insert the minute into the user's set.
2. Each set size is the user's active minute count.
3. Increment the result bucket at index `UAM - 1` for that count.

The final array contains counts for users with `1..k` active minutes.

See [sample.cpp](sample.cpp).