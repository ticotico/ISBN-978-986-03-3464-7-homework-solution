#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct bs_tree {
	int data;
	int sub_node_count;
	struct bs_tree *left;
	struct bs_tree *right;
	
}BS_Tree;

BS_Tree *insert_sort_BS_Tree(BS_Tree *root, int data)
{
	BS_Tree *current = root;
	if (root == NULL) {
		current = (BS_Tree *) malloc (sizeof(BS_Tree));
		assert(current != NULL);
		if (debug) printf("malloc (BS_Tree *) at %p\n", current);
		current->data = data;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	
	if (data <= current->data)
		current->left = insert_sort_BS_Tree(current->left, data);
	else
		current->right = insert_sort_BS_Tree(current->right, data);
	
	return current;
}

int insert_sub_node_count (BS_Tree *root)
{
	int left_count, right_count, total_count;
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) {
		root->sub_node_count = 1;
		return 1;
	} 
	left_count = insert_sub_node_count(root->left);
	right_count = insert_sub_node_count(root->right);
	root->sub_node_count = 1 + left_count + right_count;
	return root->sub_node_count;
}

BS_Tree *find_kth_min_data (BS_Tree *root, int k)
{
	int left_count;
	if (root == NULL) return NULL;
	if (k <= 0 || k > root->sub_node_count) return NULL;
	left_count = (root->left)->sub_node_count;
	if (k == left_count) return root->left;
	if (k == left_count + 1) return root;
	
	return find_kth_min_data(root->right, k - left_count - 1);
}

void print_inorder (BS_Tree *root)
{
	if (root == NULL) return ;
	print_inorder(root->left);
	printf("%d %d\n", root->data, root->sub_node_count);
	print_inorder(root->right);
}

BS_Tree *delete_BS_Tree(BS_Tree *root)
{
	if (root == NULL) return NULL;
	delete_BS_Tree(root->left);
	delete_BS_Tree(root->right);
	if (debug) printf("free (BS_Tree *) at %p\n", root);
	free(root);
	return NULL;
}

int main (void)
{
	int data, k;
	BS_Tree *root = NULL;
	BS_Tree *ptr_kth_min;
	
	do {
		scanf("%d", &data);
		if (debug) printf("input data %d\n", data);
		root = insert_sort_BS_Tree(root, data);
	}while (getchar() != '\n');
		
	insert_sub_node_count(root);
	if (debug) print_inorder(root);
	
	do {
		scanf("%d", &k);
		if (debug) printf("input k = %d\n", k);
		ptr_kth_min = find_kth_min_data(root, k);
		printf("%d %d\n", k, ptr_kth_min->data);
	}while (getchar() != '\n');
	
	root = delete_BS_Tree(root);
	return 0;
}
