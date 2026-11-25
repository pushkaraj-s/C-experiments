[← Back to main README](../README.md)

# Linked List in C and C++

The same singly linked list written twice, which makes a nice side by side comparison of procedural C and object oriented C++.

| File | Language |
|---|---|
| [`Linked_List.c`](Linked_List.c) | C |
| [`Linked_List.cpp`](Linked_List.cpp) | C++ |

## C vs C++ at a glance

| | [C version](Linked_List.c) | [C++ version](Linked_List.cpp) |
|---|---|---|
| Node | `struct node` with a `link` pointer | `class Node` with a constructor |
| Memory | `malloc` and `free` | `new` and `delete` |
| State | Global `head` | `head` and `tail` inside a `List` class |
| `push_back` | Walks the list, O(n) | Uses `tail`, O(1) |
| Extras | `count_nodes()` | `insert(val, pos)`, `search(key)` |

## Sample Output

<details>
<summary><b>Show sample output (C version)</b></summary>

<br/>

```text
List is Empty
45
45->NULL
44->45->NULL
43->44->45->NULL
42->43->44->45->NULL
41->42->43->44->45->NULL
41->42->43->44->45->46->NULL
Total Nodes = 6
42->43->44->45->46->NULL
42->43->44->45->NULL
Total Nodes = 4
```

</details>

<details>
<summary><b>Show sample output (C++ version)</b></summary>

<br/>

```text
3->2->1->NULL
3->2->1->4->NULL
4->3->2->1->4->NULL
3->2->1->4->NULL
1
```

The last line is the index returned by `search(2)`.

</details>
