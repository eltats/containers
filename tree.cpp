#include <iostream>

class Tree_ {
  public:
  int Key;
  Tree_ *Left;
  Tree_ *Right;
  Tree_ *Parent;
  Tree_ *root;
  Tree_ *Insert(Tree_ *node, int key);
  void Insert(int key);
  void Print(Tree_ *node);
  void Print();
};

Tree_* Tree_::Insert(Tree_ *node, int key) {
  if (node == nullptr) {
    node = new Tree_;
    node->Key = key;
    node->Left = nullptr;
    node->Right = nullptr;
    node->Parent = nullptr;
  }
  else if (node->Key < key) {
    node->Right = Insert(node->Right, key);
    node->Right->Parent = node;
  }
  else 
  {
    node->Left = Insert(node->Left, key);
    node->Left->Parent = node;
  }
  return node;
}

void Tree_::Insert(int key) {
  root = Insert(root, key); 
}

void Tree_::Print(Tree_ *node) {
  if (node == nullptr)  
    return;
  Print(node->Left);
  std::cout << node->Key << " ";
  Print(node->Right);
}

void Tree_::Print() {
  Print(root);
  std::cout << std::endl;
}

int main() {
  Tree_ tree;
  tree.root = nullptr;
  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(12);
  tree.Insert(8);
  tree.Insert(-2);
  tree.Insert(-6);
  tree.Insert(-3);
  tree.Print();
}