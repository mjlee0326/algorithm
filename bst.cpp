#include <iostream>

using namespace std;

struct node{
	int data;
	node* right;
	node* left;
};

struct bst{
	node* root = nullptr;

	node* find(int value){
		return find_impl(root, value);
	}

	private:
		node* find_impl(node* current, int value){
			if(!current){
				return NULL;
			}
			
			if(current -> data == value){
				cout<<"find "<<value<<endl;
				return current;
			}

			if(current -> data > value){ //현재 값이 더 크다. 왼쪽으로 이동
				cout<<current -> data<<": move left"<<endl;
				return find_impl(current -> left, value);
			}
			
			cout<<current -> data<<": move right"<<endl;
			return find_impl(current -> right, value);
		}

	public:
		void insert(int value){
			if(!root){
				root = new node{value, NULL, NULL};
			}
			else{
				return insert_impl(root, value);
			}
		}

	private:
		void insert_impl(node* current, int value){
			if(value < current -> data){ //삽입 값이 더 작음. 왼쪽으로 이동
				if(!current -> left){
					current -> left = new node{value, NULL, NULL};
				}
				else{
					insert_impl(current -> left, value);
				}
			}
			else{ //오른쪽으로 이동
				if(!current -> right){
					current -> right = new node{value, NULL, NULL};
				}
				else{
					insert_impl(current -> right, value);
				}

			}
			
		}

	public:
		void inorder(){
			return inorder_impl(root);
		}

	private:
		void inorder_impl(node* start){
			if(!start){
				return;
			}

			inorder_impl(start -> left);
			cout<<start->data<<" ";
			inorder_impl(start -> right);
		}

	public:
		node* successor(node* start){
			auto current = start -> right;
			while(current -> left && current){
				current = current -> left;
			}
			return current;
		}

		void deleteValue(int value){
			root = delete_impl(root, value);
		}

	private:
		node* delete_impl(node* start, int value){
			if(!start){
				return NULL;
			}
			if(value < start -> data){ //왼쪽으로
				start -> left = delete_impl(start -> left, value);
			}
			else if(value > start -> data){ //오른쪽으로
				start -> right = delete_impl(start -> right, value);
			}
			else{ // ==
				if(!start -> left){ //왼쪽 자식 노드 없거나 아예 없음
					auto tmp = start -> right;
					delete start;
					return tmp;
				}
				if(!start -> right){ //오른쪽 자식 노드만 없음
					auto tmp = start -> left;
					delete start;
					return tmp;
				}

				//자식 노드 둘 다
				auto succNode = successor(start);
				start -> data = succNode -> data;
				start -> right = delete_impl(start -> right, succNode -> data);
				}

			return start;
		}
};

int main(){
	bst tree;

	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(7);
	tree.insert(34);
	tree.insert(14);
	tree.insert(27);
	tree.insert(9);
	tree.insert(25);

	cout<<"in order"<<endl;
	tree.inorder();
	cout<<endl;

	tree.deleteValue(12);
	cout<<"in order after delete 12"<<endl;
	tree.inorder();
	cout<<endl;

	if(tree.find(12)){
		cout<<"12 in tree"<<endl;
	}
	else{
		cout<<"12 not in tree"<<endl;
	}

	return 0;
}
