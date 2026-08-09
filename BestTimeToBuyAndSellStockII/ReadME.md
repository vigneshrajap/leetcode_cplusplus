# Best Time to Buy and Sell Stock II

Maximize profit from stock prices by making as many trades as you like, but you must sell before you buy again.

## Approach

This greedy solution adds every positive price difference between consecutive days.

### Idea

- Iterate from day `1` to the end.
- If `prices[i] > prices[i-1]`, add the difference to profit.
- Otherwise, skip that day.

This effectively captures all profitable upward moves while ignoring downward moves.

See [sample.cpp](sample.cpp).