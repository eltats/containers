#include <iostream>
#define MAX(a, b) ((a)>(b)?(a):(b))

class Tree_ {
  public:
  Tree_();
  int Key;
  unsigned char height;
  Tree_ *Left;
  Tree_ *Right;
  Tree_ *Parent;
  Tree_ *root;
  Tree_ *Insert(Tree_ *node, int key);
  char GetBalance(Tree_ *node);
  // unsigned char SetBalance(Tree_ *node);
  void Insert(int key);
  void Print(Tree_ *node);
  void Print();
  unsigned char GetHeight(Tree_ *node);
};

Tree_::Tree_() : root(nullptr) {}

unsigned char Tree_::GetHeight(Tree_ *node) {
  if (node == nullptr)
    return 0;
  return node->height;
}

char Tree_::GetBalance(Tree_ *node) {
  if (node == nullptr)
    return 0;
  return GetHeight(node->Left) - GetHeight(node->Right);
}

// unsigned char Tree_::SetBalance(Tree_ *node) {
  
//   return GetBalance(node);
// }

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
  node->height = 1 + MAX(GetHeight(node->Left), GetHeight(node->Right));
  char balance = GetBalance(node);
  std::cout << (int)balance << std::endl;
  return node;
}

void Tree_::Insert(int key) {
  root = Insert(root, key); 
}

void Tree_::Print(Tree_ *node) {
  if (node == nullptr)  
    return;
  Print(node->Left);
  std::cout << node->Key << "." << (int)node->height << " ";
  Print(node->Right);
}

void Tree_::Print() {
  Print(root);
  std::cout << std::endl;
}

int main() {
  Tree_ tree;
  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(12);
  tree.Insert(8);
  tree.Insert(-2);
  tree.Insert(-6);
  tree.Insert(-3);
  tree.Print();
}