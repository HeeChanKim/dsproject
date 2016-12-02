#include "bst.h"
#include <stdlib.h>

bst_node* bst_search(bst_node* root, int target_rid) 
{
	if (root == NULL) return NULL;
	while (root) {
		if (target_rid == root->rid) {
			return root;
		}
		else if (target_rid < root->rid) {
			root = root->left;
		}
		else if (target_rid > root->rid) {
			root = root->right;
		}
	}

	return NULL;
}

bst_node* bst_search_with_parent(bst_node* root, int target_rid, bst_node** parent)
{
	if (root == NULL) return NULL;
	*parent = NULL;
	while (root) {
		if (target_rid == root->rid) {
			return root;
		}
		else if (target_rid < root->rid) {
			*parent = root;
			root = root->left;
		}
		else if (target_rid > root->rid) {
			*parent = root;
			root = root->right;
		}
	}

	return NULL;
}

int bst_insert(bst_node** root, bst_node* t) 
{
	if (*root == NULL) {
		*root = t;
		return 1;
	}
	if (t->rid < (*root)->rid)
		return bst_insert(&(*root)->left, t);

	if (t->rid > (*root)->rid)
		return bst_insert(&(*root)->right, t);

	return 0;
}

int bst_delete(bst_node** root, int target_rid)
{
	return 0;
}

void bst_print(bst_node* root) {}

int bst_hasChild(bst_node* t)
{
	int child = 0;
	if (t->left != NULL) child++;
	if (t->left != NULL) child++;

	return child;
}