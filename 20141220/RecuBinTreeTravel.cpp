#include <iostream>
#include <string>
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
{/*
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
		cout << root->data << " ";
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}

void InOrderTravelsal(Node *root)
{
	if (root)
	{
		InOrderTravelsal(root->left);
		cout << root->data << " ";
		InOrderTravelsal(root->right);
	}
}

void PostOrderTraversal(Node *root)
{
	if (root)
	{
		PostOrderTraversal(root->left);
		PostOrderTraversal(root->right);
		cout << root->data << " ";
	}
}

int main(int argc, const char *argv[])
{
	Node *root = createBinTree();
	Node *rootBak = root;
	
	PreOrderTraversal(root);
	cout << endl;
	
	InOrderTravelsal(root);
	cout << endl;
	
	PostOrderTraversal(root);
	cout << endl;
	
	system("pause");
	return 0;
}
