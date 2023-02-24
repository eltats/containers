#include <iostream>
#include <iomanip>

#define MAX(a, b) ((a)>(b)?(a):(b))

class Tree_ {
  public:
    Tree_();
    void Insert(int key);
    void Print();
  // private:
    Tree_ *Left;
    Tree_ *Right;
    int Key;
    unsigned char GetHeight(Tree_ *node);
    Tree_ *root;
    Tree_ *LeftRotate(Tree_ *node);
    Tree_ *RightRotate(Tree_ *node);
    char GetBalance(Tree_ *node);
    Tree_ *Insert(Tree_ *node, int key);
    void Print(const std::string& prefix, const Tree_* node, bool isLeft);
    unsigned char height;
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


void Tree_::Print(const std::string& prefix, const Tree_* node, bool isLeft) {
  if( node != nullptr ) {
      std::cout << prefix;
      std::cout << (isLeft ? "├──" : "└──" );
      std::cout << ' ' << node->Key << ' ' <<  std::endl;
      Print(prefix + (isLeft ? "│   " : "    "), node->Left, true);
      Print(prefix + (isLeft ? "│   " : "    "), node->Right, false);
  }
}

void Tree_::Print() {
    Print("", this->root, false);
}

Tree_* Tree_::Insert(Tree_ *node, int key) {

  if (node == nullptr) {
    Tree_ *res = new Tree_();
    res->Key = key;
    res->Left = nullptr;
    res->Right = nullptr;
    res->height = 1;
    return res;
  } else {
    if (node->Key < key) {
      node->Right = Insert(node->Right, key);
    } else {
      node->Left = Insert(node->Left, key);
    }
    node->height = 1 + MAX(GetHeight(node->Left), GetHeight(node->Right));
    char balance = GetBalance(node);
    if (balance == 2 && key < node->Left->Key) {
      return LeftRotate(node);
    } else if (balance == -2 && key > node->Left->Key) {
      return RightRotate(node);
    }
    else if (balance == -2 && key < node->Left->Key) {
      node->Right = RightRotate(node->Right);
      return LeftRotate(node);
    } else if (balance == 2 && key > node->Left->Key) {
      node->Left = LeftRotate(node->Left);
      return RightRotate(node);
    }
  }
  return node;
}

void Tree_::Insert(int key) {
  root = Insert(root, key);
}

Tree_* Tree_::LeftRotate(Tree_ *x) {
  // Tree_ *x = node;
  // Tree_ *y = x->Left;
  // x->Left = y->Right;
  // y->Right = x;
  Tree_ *y = x->Right;
  Tree_ *t2 = y->Left;

  y->Left = x;
  x->Right = t2;
  x->height = MAX(GetHeight(x->Left), GetHeight(x->Right));
  y->height = MAX(GetHeight(y->Left), GetHeight(y->Right));
  return y;
}

Tree_* Tree_::RightRotate(Tree_ *y) {
  Tree_ *x = y->Left;
	Tree_ *T2 = x->Right;

	// Perform 
	x->Right = y;
	y->Left = T2;
  x->height = MAX(GetHeight(x->Left), GetHeight(x->Right));
  y->height = MAX(GetHeight(y->Left), GetHeight(y->Right));
  return x;
}

int main() {
  Tree_ tree;
  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(3);
  tree.Insert(12);
  tree.Insert(8);
  tree.Insert(-2);
  tree.Insert(-6);
  // tree.Insert(-3);
  // tree.Insert(-10);
  // tree.Insert(-12);
  // tree.Insert(-15);
  tree.Print();
}