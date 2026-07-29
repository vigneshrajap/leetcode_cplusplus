
# Delete Node in a Linked List

Problem: Given only access to a node (not the head) in a singly-linked list, delete that node from the list. You are not given access to the head of the list and you may not be given the tail node.

Solution (from [sample.cpp](DeleteNodeinLinkedList/sample.cpp#L1-L17)):

- Approach: Copy the value from the next node into the given node, then bypass and delete the next node. This effectively removes the target node's original value from the list while keeping list connectivity.

- Key steps in the implementation:
	1. `node->val = node->next->val;`
	2. Save `node->next` in a temporary pointer.
	3. Set `node->next = node->next->next;` to bypass the removed node.
	4. `delete` the saved node pointer to free memory.

- C++ signature used: `void deleteNode(ListNode* node)` where `ListNode` is the standard singly-linked list node structure.

Constraints / Edge cases:
- The node to delete will not be the tail node (its `next` must be non-null).

Complexity:
- Time: O(1) — only a constant number of operations.
- Space: O(1) — no additional data structures used.

See implementation: [sample.cpp](DeleteNodeinLinkedList/sample.cpp#L1-L17)

