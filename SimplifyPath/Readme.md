# Simplify Path

Problem
- Given an absolute Unix-style file path, return the simplified canonical path.

Key idea
- Walk the path tokens separated by `/` and simulate directory navigation with a stack:
	- ignore empty tokens and `.`
	- `..` pops one entry if the stack is non-empty
	- other tokens push onto the stack
	- join the stack with `/` to form the canonical path (return `/` when empty)

Example
- Input: `/a//b/./../c/`
- Output: `/a/c`

Implementation
- Reference: [SimplifyPath/sample_1.cpp](SimplifyPath/sample_1.cpp#L1-L200)
- The file uses `std::stack` and tokenizes by searching for `/` prefixes.

Complexity
- **Time:** O(n) expected for a single pass; O(n^2) worst-case for this implementation because repeated `find`/`erase` on `std::string` can cause quadratic behavior when the input is large and many erases occur.
- **Space:** O(n) extra for the stack and the resulting string, where n is the length of the input path.

Notes
- This implementation is simple and easy to read; if you need guaranteed linear time in practice, consider a single-pass index-based tokenizer (no repeated `erase`).

Want changes?
- I can (a) keep the current implementation and further document it, (b) swap it for a strictly O(n) single-pass variant and update the README accordingly, or (c) add a small test harness. Which would you prefer?

Other implementations
---------------------

`sample_2.cpp` — stringstream + vector
- Approach: use `std::stringstream` and `std::getline(ss, token, '/')` to split tokens, push valid directories onto a `std::vector` used as a stack, then join with `/`.
- Pros: concise and easy to read; fewer manual index manipulations.
- Cons: `std::stringstream` can be a bit heavier and may allocate per token.

`sample_3.cpp` — `std::string_view` views
- Approach: use a `std::string_view` over the input and push lightweight `string_view` slices into a `std::vector` to avoid copying substrings; reconstruct the canonical path once at the end.
- Pros: minimizes temporary string allocations; good performance and low allocation overhead.
- Cons: stores views into the original input string, so be careful if the input buffer is modified or doesn't outlive the views (here it's local, so reconstruction happens before end).

Complexity comparison
---------------------

Implementation | Approach | Time | Space | Notes
---|---:|---:|---:|---
[SimplifyPath/sample_1.cpp](SimplifyPath/sample_1.cpp#L1-L200) | `find` + `erase` tokenization + `std::stack` | O(n) expected; O(n^2) worst-case (repeated erase on std::string) | O(n) | Simple and readable but repeated `erase` may cause quadratic behavior for pathological inputs.
[SimplifyPath/sample_2.cpp](SimplifyPath/sample_2.cpp#L1-L200) | `std::stringstream` + `getline` + `vector` | O(n) (tokenization + pushes) | O(n) | Clear and concise; may incur per-token allocations from `std::string` and stringstream internals.
[SimplifyPath/sample_3.cpp](SimplifyPath/sample_3.cpp#L1-L200) | `std::string_view` slices + `vector` | O(n) | O(n) (views + final result) | Best allocation behavior — avoids creating substring copies during tokenization; reconstructs result once.

Which comparison detail should I expand (benchmarks, memory snapshots, or code snippets)?
)
