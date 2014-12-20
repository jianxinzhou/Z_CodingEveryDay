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

// 1. ����������ӽ�㲻����ջ��ֱ����������ΪNULL��������ǰ���������ջ��ͬʱ��Ҫ��һʱ���ӡ��㡣
// 2. ���ӽ���ջ
// 3. �Һ��Ӽ�����ջ���ظ�1�Ĺ���
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

// 1. ����������ӽ�㲻����ջ��ֱ����������ΪNULL������
// 2. �����������ջ��ʱ����д�ӡ
// 3. �Һ��Ӽ�����ջ���ظ�1�Ĺ���
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

// 1. ����������ӽ�㲻����ջ
// 2. �����������ΪNULL���������Һ��ӽ�������ջ���ظ�1��ֱ���Һ��ӽ��ҲΪNULL
// 3. �����������ջ��ʱ����д�ӡ
// 4. ��һ����Һ��Ӽ�����ջ���ظ�1�Ĺ���
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
			// if stack not empth, if right subtree�� pop again so set root NULL
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

	// 3�ֱ������������ڴ�ӡ��ʱ����ͬ
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