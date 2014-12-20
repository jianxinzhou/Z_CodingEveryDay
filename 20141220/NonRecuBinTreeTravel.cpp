#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
	string data;
	Node *left;
	Node *right;
};

Node *newNode(string data)
{
	Node *node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node *createBinTree()
{
/*
       A
     /   \
    B     C
   / \   / \
  D   F G   I
     /   \
    E     H
*/


	Node *root = newNode("A");
	root->left = newNode("B");
	root->right = newNode("C");
	root->left->left = newNode("D");
	root->left->right = newNode("F");
	root->left->right->left = newNode("E");
	root->right->left = newNode("G");
	root->right->right = newNode("I");
	root->right->left->right = newNode("H");

	return root;
}

// 1. 根结点与左孩子结点不断入栈，直到遇到左孩子为NULL的子树。前序遍历，入栈的同时就要第一时间打印结点。
// 2. 左孩子结点出栈
// 3. 右孩子继续入栈，重复1的过程
void PreOrderTraversal(Node *root)
{
	stack<Node *> s;
	while (root || !s.empty())
	{
		// push to stack
		while (root)
		{
			s.push(root);
			cout << root->data << " ";
			root = root->left;
		}

		// pop from stack
		if (!s.empty())
		{
			Node *node = s.top();
			s.pop();
			root = node->right;
		}
	}
}

// 1. 根结点与左孩子结点不断入栈，直到遇到左孩子为NULL的子树
// 2. 中序遍历：弹栈的时候进行打印
// 3. 右孩子继续入栈，重复1的过程
void InOrderTraversal(Node *root)
{
	stack<Node *> s;
	while (root || !s.empty())
	{
		// push to stack
		while (root)
		{
			s.push(root);
			root = root->left;
		}

		// pop from stack
		if (!s.empty())
		{
			Node *node = s.top();
			cout << node->data << " ";
			s.pop();
			root = node->right;
		}
	}
}

// 1. 根结点与左孩子结点不断入栈
// 2. 如果遇到左孩子为NULL的子树，右孩子结点继续入栈，重复1，直到右孩子结点也为NULL
// 3. 后序遍历：弹栈的时候进行打印
// 4. 上一层的右孩子继续入栈，重复1的过程
void PostOrderTraversal(Node *root)
{
	stack<Node *> s;
	while (root || !s.empty())
	{
		// push to stack
		while (root)
		{
			s.push(root);
			if (root->left)
			{
				root = root->left;
			}
			else
			{
				root = root->right;
			}
		}

		// pop from stack
		if (!s.empty())
		{
			Node *node = s.top();
			cout << node->data << " ";
			s.pop();
			// if stack empty, the node popped right now must be the root node,set root NULL can break the loop 
			// if stack not empth, if right subtree， pop again so set root NULL
			if (!s.empty() && node != s.top()->right)  
			{
				root = s.top()->right;
			}
			else
			{
				root = NULL;
			}
			
		}
	}
}

int main(int argc, const char *argv[])
{
	Node *root = createBinTree();
	Node *rootBak = root;

	// 3种遍历的区别在于打印的时机不同
	PreOrderTraversal(root);
	cout << endl;

	InOrderTraversal(root);
	cout << endl;

	PostOrderTraversal(root);
	cout << endl;

	system("pause");
	return 0;
}

/*
Output:
A B D F A C G H I
D B E F A G H C I
D E F B H G I C A
*/