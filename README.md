# CAP2012 – Data Structures | CA3 – LeetCode Problem Solving (C++)

16 LeetCode problems solved in C++, organised by difficulty.
Each file contains the LeetCode `Solution` class (or design class), a header comment with the
approach and time/space complexity, and a `main()` with the LeetCode examples plus boundary test cases.

> To submit on LeetCode, paste only the class (not the `ListNode` struct, helpers or `main()`).

| S.No | LC # | Level | Problem | Unit | Approach | Time | Space |
|---|---|---|---|---|---|---|---|
| 01 | 1342 | Easy | [Number of Steps to Reduce a Number to Zero](Easy/01_LC1342_NumberOfSteps_Easy.cpp) | I | Simulation loop | O(log n) | O(1) |
| 02 | 704 | Easy | [Binary Search](Easy/02_LC704_BinarySearch_Easy.cpp) | II | Binary search | O(log n) | O(1) |
| 03 | 35 | Easy | [Search Insert Position](Easy/03_LC035_SearchInsertPosition_Easy.cpp) | II | Binary search (lower bound) | O(log n) | O(1) |
| 04 | 283 | Easy | [Move Zeroes](Easy/04_LC283_MoveZeroes_Easy.cpp) | II | Two pointers, in place | O(n) | O(1) |
| 05 | 141 | Easy | [Linked List Cycle](Easy/05_LC141_LinkedListCycle_Easy.cpp) | III | Floyd's slow/fast pointers | O(n) | O(1) |
| 06 | 203 | Easy | [Remove Linked List Elements](Easy/06_LC203_RemoveLinkedListElements_Easy.cpp) | III | Dummy node + traversal | O(n) | O(1) |
| 07 | 876 | Easy | [Middle of the Linked List](Easy/07_LC876_MiddleOfLinkedList_Easy.cpp) | III | Slow/fast pointers | O(n) | O(1) |
| 08 | 225 | Easy | [Implement Stack using Queues](Easy/08_LC225_StackUsingQueues_Easy.cpp) | IV | One queue, rotate on push | push O(n), others O(1) | O(n) |
| 09 | 160 | Easy | [Intersection of Two Linked Lists](Easy/09_LC160_IntersectionOfTwoLists_Easy.cpp) | III | Two pointers switching heads | O(m+n) | O(1) |
| 10 | 19 | Medium | [Remove Nth Node From End of List](Medium/10_LC019_RemoveNthFromEnd_Medium.cpp) | III | Dummy + gap of n pointers | O(L) | O(1) |
| 11 | 707 | Medium | [Design Linked List](Medium/11_LC707_DesignLinkedList_Medium.cpp) | III | Singly list with sentinel + size | O(n) | O(n) |
| 12 | 641 | Medium | [Design Circular Deque](Medium/12_LC641_DesignCircularDeque_Medium.cpp) | IV | Circular array buffer | O(1) | O(k) |
| 13 | 946 | Medium | [Validate Stack Sequences](Medium/13_LC946_ValidateStackSequences_Medium.cpp) | IV | Stack simulation | O(n) | O(n) |
| 14 | 54 | Medium | [Spiral Matrix](Medium/14_LC054_SpiralMatrix_Medium.cpp) | II | Four shrinking boundaries | O(m·n) | O(1) |
| 15 | 4 | Hard | [Median of Two Sorted Arrays](Hard/15_LC004_MedianOfTwoSortedArrays_Hard.cpp) | II | Binary search on partition | O(log min(m,n)) | O(1) |
| 16 | 42 | Hard | [Trapping Rain Water](Hard/16_LC042_TrappingRainWater_Hard.cpp) | II | Two pointers with left/right max | O(n) | O(1) |

Units: I – Basic Concepts; II – Arrays; III – Linked Lists; IV – Stacks & Queues.

## LeetCode submission results

All 16 solutions were submitted on LeetCode (C++) and **Accepted**, passing every hidden test case:

| S.No | Problem | Test cases passed |
|---|---|---|
| 01 | 1342 Number of Steps | 204 / 204 |
| 02 | 704 Binary Search | 47 / 47 |
| 03 | 35 Search Insert Position | 68 / 68 |
| 04 | 283 Move Zeroes | 75 / 75 |
| 05 | 141 Linked List Cycle | 29 / 29 |
| 06 | 203 Remove Linked List Elements | 66 / 66 |
| 07 | 876 Middle of the Linked List | 36 / 36 |
| 08 | 225 Implement Stack using Queues | 22 / 22 |
| 09 | 160 Intersection of Two Linked Lists | 41 / 41 |
| 10 | 19 Remove Nth Node From End | 208 / 208 |
| 11 | 707 Design Linked List | 53 / 53 |
| 12 | 641 Design Circular Deque | 54 / 54 |
| 13 | 946 Validate Stack Sequences | 152 / 152 |
| 14 | 54 Spiral Matrix | 27 / 27 |
| 15 | 4 Median of Two Sorted Arrays | 2099 / 2099 |
| 16 | 42 Trapping Rain Water | 326 / 326 |

## Compile and run a solution

```bash
g++ -std=c++17 Easy/01_LC1342_NumberOfSteps_Easy.cpp -o a && ./a
```
