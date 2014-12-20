/**
 * 遍历二叉树的应用：输出二叉树中的叶子结点。
 */

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

void PreOrderTraversal(Node *root)
{
	if (root)
	{
		if (!root->left && !root->right)
		{
			cout << root->data << " ";
		}
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}

void InOrderTraversal(Node *root)
{
	stack<Node *> s;
	while (root || !s.empty())
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		
		if (!s.empty())
		{
			Node *node = s.top();
			s.pop();
			if (!node->left && !node->right)
			{
				cout << node->data << " ";
			}
			root = node->right;
		}
	}
}

void PostOrderTraversal(Node *root)
{
	stack<Node *> s;
	while (root || !s.empty())
	{
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

		if (!s.empty())
		{
			Node *node = s.top();
			if (!node->left && !node->right)
			{
				cout << node->data << " ";
			}
			s.pop();

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
D E H I
D E H I
D E H I
*/