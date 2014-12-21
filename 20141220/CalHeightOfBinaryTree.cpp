/**
 * 计算二叉树的高度
 * Height = max(heightOfLeftSubTree, heightOfRightSubTree) + 1
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

int PostOrderGetHeight(Node *root)
{
	int HL, HR, MaxH;
	if (root)
	{
		HL = PostOrderGetHeight(root->left);   // calculate the height of left subtree
		HR = PostOrderGetHeight(root->right);  // calculate the height of right subtree
		MaxH = (HL > HR) ? HL : HR;            // get the bigger height of the left and right subtrees     
		return (MaxH + 1);                     // return the height of tree
	}
	else
	{
		return 0;                              // the height of empty tree is zero
	}
}

int main(int argc, const char *argv[])
{
	Node *root = createBinTree();
	cout << "The height of tree is : " << PostOrderGetHeight(root) << endl;
	system("pause");
	return 0;
}

/*
output:
The height of tree is 4
*/
