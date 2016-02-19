#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG

typedef int Datatpye;

typedef struct bs_tree {
	Datatpye data;
	struct bs_tree *left;
	struct bs_tree *right;
}BS_Tree;

void print_inorder(BS_Tree *root)
{
	if (root == NULL) return;
	print_inorder(root->left);
	printf("%p: data = %d\n", root, root->data);
	print_inorder(root->right);
	return ;
}

BS_Tree *insert_sort_BS_Tree (BS_Tree *root, Datatpye data)
{
	BS_Tree *current = root;
	if (current == NULL) {
		current = (BS_Tree *) malloc (sizeof(BS_Tree));
		assert(current != NULL);
		#ifdef DEBUG
		printf("malloc (BS_Tree *) at %p\n", current);
		#endif //DEBUG
		current->data = data;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	
	if (data < current->data)
		current->left = insert_sort_BS_Tree(current->left, data);
	else
		current->right = insert_sort_BS_Tree(current->right, data);
	
	return current;
}

BS_Tree *find_delete_leaf_and_its_parent(BS_Tree *root, BS_Tree **parent)
{
	BS_Tree *del_leaf = root;
	if (del_leaf == NULL) return NULL;
	*parent = del_leaf;
	if (del_leaf->left != NULL)
		while (del_leaf->left != NULL || del_leaf->right != NULL) {
			*parent = del_leaf;
			if (del_leaf->right != NULL)
				del_leaf = del_leaf->right;
			else
				del_leaf = del_leaf->left;
		}
	else if (del_leaf->right != NULL)
		while (del_leaf->left != NULL || del_leaf->right != NULL) {
			*parent = del_leaf;
			if (del_leaf->left != NULL)
				del_leaf = del_leaf->left;
			else
				del_leaf = del_leaf->right;
		}
	return del_leaf;
}

BS_Tree *remove_BS_Tree_data(BS_Tree *root, Datatpye data)
{
	BS_Tree *data_pos = root;
	BS_Tree *data_parent = NULL;
	BS_Tree *delete_node;
	BS_Tree *delete_node_parent = NULL;

	//find data_pos
	while (data_pos != NULL && data_pos->data != data) {
		data_parent = data_pos;
		if (data < data_pos->data)
			data_pos = data_pos->left;
		else
			data_pos = data_pos->right;
	}
	//case: tree is empty or not find data
	if (data_pos == NULL) return root;
	//case: root is a leafnode
	if (data_pos->left == NULL && data_pos->right == NULL) {
		#ifdef DEBUG
		printf("line %d: free %p\n", __LINE__, data_pos);
		#endif //DEBUG
		free(data_pos);
		return NULL;
	}
	
	delete_node_parent = data_parent;
	delete_node = find_delete_leaf_and_its_parent(data_pos, &delete_node_parent);
	
	data_pos->data = delete_node->data;
	if (delete_node_parent !=  NULL) {
		if (delete_node_parent->left == delete_node)
			delete_node_parent->left = NULL;
		else if (delete_node_parent->right == delete_node)
			delete_node_parent->right = NULL;
		#ifdef DEBUG
		else printf("line %d: delete_node_parent doesn't "
			"point to delete_node", __LINE__);
		#endif //DEBUG
	}
	
	#ifdef DEBUG
	printf("line %d: free %p\n", __LINE__, delete_node);
	#endif //DEBUG
	free(delete_node);
	
	return root;
}

BS_Tree *destroy_BS_tree (BS_Tree *root)
{
	if (root == NULL) return NULL;
	
	if (root->left != NULL)
		root->left = destroy_BS_tree(root->left);
	if (root->right != NULL)
		root->right = destroy_BS_tree(root->right);
	
	if (root->left == NULL && root->right == NULL) {
		#ifdef DEBUG
		printf("free %p\n", root);
		#endif //DEBUG
		free(root);
		return NULL;
	}
	
	return NULL;
}

int main (void)
{
	Datatpye data;
	char c;
	BS_Tree *root = NULL;
	
	do {
		scanf("%d", &data);
		c = getchar();
		#ifdef DEBUG
		printf("input insert data: %d\n", data);
		#endif //DEBUG
		root = insert_sort_BS_Tree(root, data);
	} while(c != '\n');
	
	putchar('\n');
	do {
		scanf("%d", &data);
		c = getchar();
		#ifdef DEBUG
		printf("input remove data: %d\n", data);
		#endif //DEBUG
		root = remove_BS_Tree_data(root, data);
		#ifdef DEBUG
		printf("print_inorder:\n");
		print_inorder(root);
		putchar('\n');
		#endif // DEBUG
	} while(c != '\n');
	
	if (root == NULL)
		printf("tree is empty\n");
	else {
		printf("print_inorder:\n");
		print_inorder(root);
		putchar('\n');
	}
	
	destroy_BS_tree(root);
	return 0;
}
