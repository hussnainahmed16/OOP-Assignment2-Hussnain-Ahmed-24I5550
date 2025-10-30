
# OOP_Assignment 2

This document explains the purpose, logic, implementation approach, and learning outcomes of all parts of the assignment.

---

## **Q1 — Recursive Character Repositioning**
This program recursively swaps characters between two boundaries in an array until the indices meet.
It demonstrates:
- Recursion base cases
- Swapping logic
- Pointer/array manipulation

Source: fileciteturn0file0

---

## **Q1 (Part B) — Integer Partition Pattern (Recursion)**
This code prints all integer partitions of a number using recursion. For each call, the program chooses a value ≤ `n` and recurses with the reduced number.

Key concepts:
- Recursion tree exploration
- Controlled non-increasing sequences

Source: fileciteturn0file1

---

## **Q2 — Polymorphism with Linked List Storage**
NASA-themed simulation storing `Feature` objects. Uses:
- Abstract base class
- Virtual functions
- Derived classes (`LandFeature`, `WaterFeature`)
- Singly Linked List for dynamic storage

Demonstrates:
- Polymorphism
- Dynamic binding
- Linked list traversal
- Memory-safe deletion

Source: fileciteturn0file2

---

## **Q3 — Doubly Linked List Library System**
Maintains books with:
- Add at beginning
- Add at end
- Add at position
- Delete by ID
- Forward & backward display

Demonstrates:
- Bidirectional navigation
- Edge-case deletion (head/tail/single node)
- Traversal safety

Source: fileciteturn0file3

---

## **Q4 — Ticket Queue (FIFO)**
Implements a movie ticket booking system:
- Enqueue new customers
- Dequeue served customers
- Traversal display
- Memory cleanup

Concepts shown:
- FIFO queueing rules
- Rear/Front pointers
- Smart deletion handling

Source: fileciteturn0file4

---

## **Q5A — Stacks + Pattern Generation**
Implements two stack types:
- Linked-list-based
- Array-based

Then uses them to print iterative patterns based on integer breakdown.

Emphasizes:
- Stack push/pop discipline
- Iterative pattern generation
- Controlled looping logic

Source: fileciteturn0file5

---

## **Algorithm Analysis (Summary)**

### Linked List Stack
| Operation | Complexity | Reason |
|-----------|-------------|--------|
| Push | O(1) | Only reassigns top pointer |
| Pop | O(1) | Moves top pointer and deletes node |
| Memory | More overhead | Pointer stored per node |

### Array Stack
| Operation | Complexity | Reason |
|-----------|-------------|--------|
| Push | O(1) | Index increment |
| Pop | O(1) | Index decrement |
| Limitation | Fixed capacity | Possible overflow |

### Performance Notes
- Array stacks are faster due to cache locality.
- Linked stacks grow dynamically, preventing overflow.

---

## **Conclusion**
Through the implementation of queues, stacks, recursion, linked lists, and polymorphism, this assignment demonstrates:

- Dynamic memory management
- Data structure modeling
- Efficient traversal logic
- Class organization
- Safe deletion practices

The work collectively strengthens core knowledge essential for advanced programming and system design.

---

**Student:** 24I-5550

