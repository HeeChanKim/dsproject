#include "bst.h"
#include <stdlib.h>
bst_node* bst_search(bst_node* root, int target_rid) 
{
	if (root == NULL) return NULL;
	if (target_rid == root->rid) return root;
	if (target_rid < root->rid)
		return bst_search(root->left, target_rid);
	if (target_rid > root->rid)
		return bst_search(root->right, target_rid);

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

int bst_delete(bst_node** root, bst_node* t) { return 0; }
void bst_print(bst_node* root) {}