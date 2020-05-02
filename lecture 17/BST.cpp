// BST
#include <iostream>
using namespace std;

class node{

public:
	int data;
	node* left;
	node* right;

	node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};


node* Insertion_into_BST(node* root,int data){
	if(root==NULL){
		root=new node(data);
		return root;
	}
	if(data<root->data){
		root->left=Insertion_into_BST(root->left,data);
	}
	else{
		root->right=Insertion_into_BST(root->right,data);
	}
	return root;

}

node* CreateBST(){
	int data;cin>>data;
	node* root=NULL;
	while(data!=-1){
		root=Insertion_into_BST(root,data);
		cin>>data;
	}
	return root;
}

void inorder(node* root){
	if(root==NULL){
		return;
	}
//	ans++;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}

bool search(node* root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	else if(root->data<key){
		search(root->right,key);
	}
	else{
		search(root->left,key);
	}
}
#include<climits>
bool is_BST(node* root,int mini=INT_MIN,int maxi=INT_MAX){
	if(root==NULL){
		return true;
	}

	if(root->data>=mini && root->data<=maxi && is_BST(root->left,mini,root->data) && is_BST(root->right,root->data,maxi)){
		return true;
	}
	else{
		return false;
	}

}
int height(node* root){
	if(root==NULL){
		return 0;
	}
	int left_height=height(root->left);
	int right_height=height(root->right);

	int my_height=max(left_height,right_height) + 1;
	return my_height;
}
#include<cmath>
bool is_balaced(node* root){
	if(root==NULL){
		return true;
	}
	if(abs(height(root->left)-height(root->right))<=1 && is_balaced(root->left) && is_balaced(root->right)){
		return true;
	}
	else{
		return false;
	}
}
node* CreateTreeUsigiopo(int* io,int* po,int s,int e,int &lastptr){
	if(s>e){
		return NULL;
	}
	node* root=new node(po[lastptr]);
	lastptr--;
	int index;
	for(int i=0;i<=e;i++){
		if(io[i]==root->data){
			index=i;
			break;
		}
	}
	root->right=CreateTreeUsigiopo(io,po,index+1,e,lastptr);
	root->left=CreateTreeUsigiopo(io,po,s,index-1,lastptr);
	return root;
}

node* CreateTreefromsortedarray(int* a,int s,int e){
	//ase case
	if(s>e){
		return NULL;
	}

	int mid=(s+e)/2;

	node* root=new node(a[mid]);

	root->left=CreateTreefromsortedarray(a,s,mid-1);
	root->right=CreateTreefromsortedarray(a,mid+1,e);

	return root;


}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};

	node* root=CreateTreefromsortedarray(a,0,9);

	//int io[]={1,3,4,6,7,8,10,13,14};
	//int po[]={1,4,7,6,3,13,14,10,8};
	//int lastptr=8;
	//node *root=CreateTreeUsigiopo(io,po,0,8,lastptr);
	//node* root=CreateBST();
	inorder(root);
	//cout<<boolalpha<<is_balaced(root);
	return 0;
}