#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

unsigned int getLeafCount(struct node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getLeafCount(node->left) +
		getLeafCount(node->right);
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void print2DUtil(node* root, int space) {
	if (root == NULL)
		return;

	space += 3;

	print2DUtil(root->right, space);

	cout << endl;
	for (int i = 3; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	print2DUtil(root->left, space);
}

void print2D(node* root)
{
	print2DUtil(root, 0);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Leaf count of the tree is : " << getLeafCount(root) << endl;
	print2D(root);
	return 0;
}