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

BS_Tree *find_first_BS_Tree_data (BS_Tree *root, Datatpye data)
{
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	
	if (data < root->data)
		return find_first_BS_Tree_data(root->left, data);
	else
		return find_first_BS_Tree_data(root->right, data);
}

BS_Tree *find_max_BS_Tree_data(BS_Tree *root)
{
	
	if (root == NULL) return NULL;
	if (root->left == NULL && root->right == NULL) return root;
	if (root->right != NULL) return find_max_BS_Tree_data(root->right);
	return root;
}

BS_Tree *find_min_BS_Tree_data(BS_Tree *root)
{
	if (root == NULL) return NULL;
	if (root->left == NULL && root->right == NULL) return root;
	if (root->left != NULL) return find_min_BS_Tree_data(root->left);
	return root;
}

BS_Tree *find_data_parent(BS_Tree *root, Datatpye data)
{
	BS_Tree *current = root;
	BS_Tree *parent;
	if (current == NULL || current->data == data)
		return NULL;
	if (current->left != NULL && current->left->data == data)
		return current;
	if (current->right != NULL && current->right->data == data)
		return current;
	
	parent = find_data_parent(root->left, data);
	if (parent != NULL) return parent;
	parent = find_data_parent(root->right, data);
	if (parent != NULL) return parent;
	return NULL;
}

BS_Tree *remove_BS_Tree_data(BS_Tree *root, Datatpye data)
{
	BS_Tree *current = root;
	BS_Tree *data_pos = current;
	BS_Tree *data_parent = NULL;
	BS_Tree *delete_node;
	BS_Tree *delete_node_parent;
	
	//case: tree is empty
	if (root == NULL) return NULL;
	//find data_pos
	while (data_pos != NULL && data_pos->data != data) {
		data_parent = data_pos;
		if (data < data_pos->data)
			data_pos = data_pos->left;
		else
			data_pos = data_pos->right;
	}
	//case: not find data
	if (data_pos == NULL) return root;
	//case: data_pos at leaf node
	if (data_pos->left == NULL && data_pos->right == NULL) {
		if (data_parent != NULL) {
			if(data_parent->left == data_pos)
				data_parent->left = NULL;
			if(data_parent->right == data_pos)
				data_parent->right = NULL;
		}
		
		#ifdef DEBUG
		printf("free %p\n", data_pos);
		#endif //DEBUG
		free(data_pos);
		if (data_parent != NULL)
			return root;
		else
			return NULL;
	}
	//case: data_pos has left subtree 
	//(replace left subtree right most leaf node to find data)
	if (data_pos->left != NULL) {
		delete_node_parent = data_pos;
		delete_node = data_pos->left;
		while(delete_node->left != NULL || delete_node->right != NULL) {
			delete_node_parent = delete_node;
			if (delete_node->right != NULL)
				delete_node = delete_node->right;
			else if (delete_node->left != NULL)
				delete_node = delete_node->left;
		}
		data_pos->data = delete_node->data;
		if (delete_node_parent->left == delete_node)
			delete_node_parent->left = NULL;
		else if (delete_node_parent->right == delete_node)
			delete_node_parent->right = NULL;
		#ifdef DEBUG
		printf("free %p\n", delete_node);
		#endif //DEBUG
		free(delete_node);
		return root;
	}
	//case: data_pos has right subtree 
	//(replace right subtree left most leaf node to find data)
	if (data_pos->right != NULL) {
		delete_node_parent = data_pos;
		delete_node = data_pos->right;
		while(delete_node->left != NULL || delete_node->right != NULL) {
			delete_node_parent = delete_node;
			if (delete_node->left != NULL)
				delete_node = delete_node->left;
			else if (delete_node->right != NULL)
				delete_node = delete_node->right;
		}
		data_pos->data = delete_node->data;
		if (delete_node_parent->left == delete_node)
			delete_node_parent->left = NULL;
		else if (delete_node_parent->right == delete_node)
			delete_node_parent->right = NULL;
		#ifdef DEBUG
		printf("free %p\n", delete_node);
		#endif //DEBUG
		free(delete_node);
		return root;
	}
	
	return NULL;
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
	
	destroy_BS_tree(root);
	return 0;
}
