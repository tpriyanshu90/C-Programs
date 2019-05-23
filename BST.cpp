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
	else if(key>node->data){
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

NODE* search(NODE* node, int key){
	if(node!=NULL){
		if(node->data == key){
			cout<<"Element found";
		}
		else if(key < node->data)
			node = search(node->left, key);
		else
			node = search(node->right,key);
	}
	else
		cout<<"Element not present!\n";
	return node;
}

NODE* minNode(NODE* node){
	if(node->left==NULL)
		return node;
	if(node!=NULL)
		return minNode(node->left);
}

NODE* delete_node(NODE* node, int key){
	if(node == NULL)
		return node;
	else if(key<node->data){
		node->left = delete_node(node->left,key);
	}
	else if(key>node->data){
		node->right = delete_node(node->right,key);
	}
	else{
		if(node->left==NULL){
			NODE* temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right==NULL){
			NODE* temp = node->right;
			free(node);
			return temp;
		}
		else{
			NODE* minRightNode = minNode(node->right);
			node->data = minRightNode->data;
			node->right = delete_node(node->right,minRightNode->data);
		}
	}
	return node;
}

int main()
{
    NODE* root = NULL;
    char ch('y');
    while(ch == 'y' || ch == 'Y'){
    	int choice, key;
    	cout<<"Which operation do you want to perform?\n1. Insertion\n2. Deletion\n3. Searching\n4. Inorder traversing\n5. Preorder traversing\n6. Postorder traversing\n7. Delete Complete Tree\n8. Exit\n";
    	cout<<"Your choice: ";
    	cin>>choice;
    	cin.ignore();
    	switch(choice){
    		case 1:
    			cout<<"\nEnter element to be inserted: ";
    			cin>>key;
    			if(root==NULL)
    				root = insert(root,key);
    			else
    				insert(root,key);
    			cout<<endl;
    			break;
    		case 2:
    			cout<<"\nEnter element to be deleted: ";
    			cin>>key;
    			delete_node(root,key);
    			cout<<"\nNode "<<key<<" Deleted Successfully!\n";
    			break;
    		case 3:
    			cout<<"\nEnter element to be searched: ";
    			cin>>key;
    			search(root,key);
    			break;
    		case 4:
    			cout<<"\nInorder traversal: ";
    			inorder(root);
    			break;
    		case 5:
    			cout<<"\nPreorder traversal: ";
    			preorder(root);
    			break;
    		case 6:
    			cout<<"\nPostorder traversal: ";
    			postorder(root);
    			break;
    		case 7:
    			root = NULL;
    			cout<<"\nBinary Search tree deleted.\n";
    			break;
    		case 8:
    			exit(1);
    		default:
    			cout<<"\nPlease choose correct option!\n";			
    	}
    	cout<<"\nDo you want to continue? (y/n) : ";
    	cin>>ch;
    }
    return 0;
}