//PROGRAM FOR BINARY SEARCH TREE OPERATIONS

#include <bits/stdc++.h>
using namespace std;

struct NODE{
	int data;
	NODE *left,*right;
};

NODE* createNewNode(){
	NODE* node = new NODE;
	node->left = NULL;
	node->right = NULL;
	return node;
}

NODE* insert(NODE* node, int key){
	if(node==NULL){
		node = createNewNode();
		node->data = key;
	}
	else if(key<node->data){
		node->left = insert(node->left,key);
	}
	else{
		node->right = insert(node->right,key);
	}
	return node;
}

void inorder(NODE* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<' ';
		inorder(root->right);
	}
}

void preorder(NODE* root){
	if(root!=NULL){
		cout<<root->data<<' ';
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<' ';
	}
}

void search(NODE* node, int key){
	if(node!=NULL){
		if(node->data == key)
			cout<<"Element found";
		else if(key < node->data)
			search(node->left, key);
		else
			search(node->right,key);
	}
	else
		cout<<"Element not present!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    NODE * root = NULL;
    root = insert(root,5);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 1);
    inorder(root);
    cout<<'\n';
    preorder(root);
    cout<<'\n';
    postorder(root);
    cout<<'\n';
    search(root,11);
    cout<<'\n';
    return 0;
}