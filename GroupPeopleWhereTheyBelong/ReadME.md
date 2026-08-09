# Group People Where They Belong

Group people according to their desired group sizes.

## Approach

Use a map from group size to a temporary list of member indexes.

### Idea

1. Iterate through `groupSizes` with each person's index.
2. Append the index into the bucket for that size.
3. When a bucket reaches its target size, move it to the result and clear it.

This ensures each returned group has exactly the required size.

See [sample.cpp](sample.cpp).