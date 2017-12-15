#include "arrayqueue.h"
template<typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data,Node* left=nullptr,Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};
	Node* root_;
	//this function inserts the data into 
	//the tree with root pointed to by subRoot
	//subroot, short for subtree's root
	void insert(const T& data,Node*& subRoot){
		if(subRoot == nullptr){
			 subRoot=new Node(data);
		}
		else{
			if(data < subRoot->data_){
				insert(data,subRoot->left_);
			}
			else{
				insert(data,subRoot->right_);				
			}
		}
	}

	void preOrderPrint(const Node* subRoot) const{
		if(subRoot!=nullptr){
			cout << subRoot->data_ << " ";
			preOrderPrint(subRoot->left_);
			preOrderPrint(subRoot->right_);
		}
	}
	void inOrderPrint(const Node* subRoot) const{
		if(subRoot!=nullptr){
			inOrderPrint(subRoot->left_);
			cout << subRoot->data_ << " ";
			inOrderPrint(subRoot->right_);
		}
	}
	//function destroys all the nodes in
	// the tree with root subroot
	void destroy(Node* subRoot){
		if(subRoot){
			destroy(subRoot->left_);
			destroy(subRoot->right_);
			delete subRoot;
		}
	}
	//this function recursively finds the inorder successor.
	//when it finds it, it is detached and returned.
	Node* detachIS(Node*& subRoot){

	}
	//this function removes node containing 
	//data from tree who's root
	//is subRoot
	void remove(const T& data,Node*& subRoot){
		if(subRoot!=nullptr){
			if(data == subRoot->data_){
				Node* rm=subRoot;
				if(subRoot->left_==nullptr && subRoot->right_==nullptr){
					subRoot=nullptr;
				}
				else if(subRoot->left_!=nullptr && subRoot->right_==nullptr){
					//left child only
					subRoot = subRoot->left_;
				}
				else if(subRoot->left_==nullptr && subRoot->right_!=nullptr){
					//right child only
					subRoot=subRoot->right_;
				}
				else{
					Node* inOrderSuccessor=detachIS(subRoot->right_);
					inOrderSuccessor->left_=subRoot->left_;
					inOrderSuccessor->right_=subRoot->right_;
					subRoot=inOrderSuccessor;
				}	
				delete rm;
			}
			else if(data < subRoot->data_){
				remove(data, subRoot->left_);
			}
			else{
				remove(data, subRoot->right_);
			}
		}
	}
public:
	BST(){
		root_=nullptr;
	}
	void insert(const T& data){
		insert(data,root_);
	}
	void remove(const T& data){
		remove(data,root_);
	}
	//depthfirst
	void preOrderPrint() const{
		preOrderPrint(root_);		
	}
	//depthfirst
	void inOrderPrint() const{
		inOrderPrint(root_);
	}
	//breadthfirst
	void breadthFirstPrint() const{
		Queue<Node*> q;
		if(root_){
			q.enqueue(root_);
		}
		while(!q.empty()){
			Node* curr=q.front();
			q.dequeue();
			cout << curr->data_ << " ";
			if(curr->left_){
				q.enqueue(curr->left_);
			}
			if(curr->right_){
				q.enqueue(curr->right_);
			}
		}
	}
	~BST(){
		destroy(root_);
	}
};




