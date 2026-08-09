# Number of Recent Calls

Implement a class to count the number of requests that occur within the last 3000 milliseconds.

## Approach

Store each request timestamp and count how many fall within the sliding window.

### Idea

1. Append each new ping time to the request list.
2. Count how many timestamps are `>= t - 3000`.
3. Return that count.

This is a straightforward sliding window implementation. A queue would be more efficient, but the sample uses a vector.

See [sample.cpp](sample.cpp).