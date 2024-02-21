# Binary Search Tree 

Here is C++ implementation of a Binary Search Tree (BSTree), which provides efficient operations for managing tree nodes and performing various operations such as insertion, deletion, traversal, and searching.

## Overview

The BSTree class represents the binary search tree structure. It consists of two main components:

### `TNode` Class

- Represents a node in the binary search tree.
- Attributes:
  - `data`: Value stored in the node.
  - `left`: Pointer to the left child node.
  - `right`: Pointer to the right child node.

### `BSTree` Class

- Represents the binary search tree structure.
- Attributes:
  - `root`: Pointer to the root node.
- Methods:
  - Traversal: `preOrder`, `inOrder`, `postOrder`.
  - Searching: `search`, `recSearch`.
  - Insertion: `insert`.
  - Deletion: `remove`.
  - Utility Methods: `countNodes`, `getHeight`, `createBalancedTree`, `findMin`, `findMax`, `makeEmpty`, `doubleTree`, `printAllPaths`, `displayInRange`.
  - Copy Constructor and Assignment Operator: `BSTree(const BSTree&)`, `operator=`.
  - Destructor: `~BSTree`.

## Usage


1. Create an instance of the `BSTree` class.
2. Use the provided methods to perform operations like insertion, deletion, traversal, searching, etc.

Example:

```cpp
#include "BSTree.h"

int main() {
    BSTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "Inorder traversal: ";
    tree.inOrder();
    
    cout << endl << "Minimum value in the tree: " << tree.findMin();
    cout << endl << "Maximum value in the tree: " << tree.findMax();
    
    return 0;
}
