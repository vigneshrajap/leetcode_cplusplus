# Lemonade Change

Determine whether you can provide change to every customer in order using $5, $10, and $20 bills.

## Approach

Track the number of $5 and $10 bills available and process each payment greedily.

### Idea

- For a $5 bill, increase the $5 count.
- For a $10 bill, give one $5 as change.
- For a $20 bill, prefer giving one $10 and one $5; otherwise give three $5 bills.
- If at any point you cannot make change, return `false`.

This greedy strategy preserves larger bills for later customers.

See [sample.cpp](sample.cpp).