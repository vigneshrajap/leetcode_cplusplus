# Partition Labels

Partition a string into as many parts as possible so that each letter appears in at most one part.

## Approach

Compute the last occurrence index for every character, then expand partitions greedily.

### Idea

1. First pass: record the last index of each character.
2. Iterate through the string and maintain `far_end` as the farthest last occurrence seen so far.
3. When the current index reaches `far_end`, close the current partition.
4. Save the partition size and start a new partition.

Each partition is as large as needed to include all occurrences of its characters.

See [sample.cpp](sample.cpp).