
# Palindrome Linked List

Problem: Determine whether a singly-linked list is a palindrome (reads the same forward and backward).

Solution (from [sample.cpp](PalindromeLinkedList/sample.cpp#L1-L40)):

- Approach: Use the fast and slow pointer technique to find the midpoint, reverse the second half of the list in-place, then compare the first half and the reversed second half node-by-node.

- Key steps in the implementation:
	1. Advance `slow` by one and `fast` by two to locate the middle of the list.
	2. Reverse the list starting from `slow` (the second half) using iterative reversal.
	3. Compare values from the head and the head of the reversed second half; if all corresponding values match, the list is a palindrome.

- Edge cases:
	- Empty list or single-node list => return `true`.
	- The algorithm assumes standard singly-linked list nodes and handles both even and odd lengths.

Complexity:
- Time: O(n) — one pass to find middle, one to reverse, and one to compare.
- Space: O(1) — in-place reversal, constant extra space.

See implementation: [sample.cpp](PalindromeLinkedList/sample.cpp#L1-L40)

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
    
		ListNode *slow = head, *fast = head;

		// Traverse the LL, slow will be in the middle of LL
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
        
		// Step 2: Reverse the second half of the list
		ListNode* prev = nullptr;
		ListNode* curr = slow;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}

		// Step 3: Compare first half and reversed second half
		ListNode* firstHalf = head;
		ListNode* secondHalf = prev; // Head of reversed list
        
		while (secondHalf != nullptr) {
			if (firstHalf->val != secondHalf->val) {
				return false;
			}
			firstHalf = firstHalf->next;
			secondHalf = secondHalf->next;
		}

		return true;                                                                                
	}
};
```

## Alternative Approach: Array + Two Pointers

- Idea: Traverse the linked list and copy node values into a vector, then use two indices `l=0` and `r=n-1` to compare elements moving inward.
- Steps:
	1. Iterate the list and push each `node->val` into a `vector<int> arr`.
	2. Initialize `l = 0`, `r = arr.size() - 1`.
	3. While `l < r`, if `arr[l] != arr[r]` return `false`; otherwise `l++`, `r--`.
	4. If no mismatches found, return `true`.
- Complexity: Time O(n), Space O(n).

## Why Fast+Slow + Reverse Is Better

- The fast+slow + in-place reverse method achieves the same Time O(n) but uses Space O(1) (constant extra memory), while the array approach uses O(n) extra space.
- For large lists or memory-constrained environments the O(1) space usage is often decisive.
- The fast+slow method only temporarily mutates the list; if preserving the original list is required, you can reverse the second half back after comparison to restore the list.

