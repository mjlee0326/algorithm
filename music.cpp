#include <iostream>
#include <algorithm>

using namespace std;

struct circle_node{
	int data; 
	circle_node* next;
};


class circle{
	public:
		using node = circle_node;
		using node_ptr = node*;

		void push_front(int val){
			auto new_node = new node {val, NULL};

			if(head!=NULL){
				new_node -> next = head;
			}
			head = new_node;
		}

		void pop_front(){

			auto first = head;

			if(head){
				head = head -> next;
				delete first;
			}
		
		}
	struct circle_iterator{
		private:
			node_ptr ptr;

		public:
			circle_iterator(node_ptr p) : ptr(p){}

			int& operator*() {return ptr->data;}

			node_ptr get() { return ptr;}

			//선행증가
			circle_iterator& operator++(){
				ptr = ptr -> next;
				return *this;
			}

			//후행증가
			circle_iterator operator++(int){
				circle_iterator result = *this;
				++(*this);
				return result;
			}

			friend bool operator==(const circle_iterator& left, const circle_iterator& right){
				return left.ptr == right.ptr;
			}

			friend bool operator!=(const circle_iterator& left, const circle_iterator& right){
				return left.ptr != right.ptr;
			}
	};

	circle_iterator begin(){
		return circle_iterator(head);
	}
	circle_iterator end(){
		return circle_iterator(NULL);
	}
	circle_iterator begin() const{
		return circle_iterator(head);
	}
	circle_iterator end() const{
		return circle_iterator(NULL);
	}

	//for deep copy

	circle() = default;

	circle(const circle& other) : head(NULL){
		if(other.head){
			head = new node{0, NULL};
			auto cur = head;
			auto it = other.begin();
			while(true){
				cur->data=*it;

				auto tmp = it;
				++tmp;

				if(tmp == other.end()){
					break;
				}

				cur -> next = new node{0, NULL};
				cur = cur->next;
				it = tmp;
			}
		}
	}

	//initialize list 를 사용하는 생성자 추가
	circle(const initializer_list<int>& ilist) : head(NULL){
		for(auto it = rbegin(ilist); it!=rend(ilist); it++){
			push_front(*it);
		}
	}

	private:
		node_ptr head;	
};

int main(){

	circle sll = {1, 2, 3};
	sll.push_front(0);

	cout<<"첫 번째 리스트: ";

	for(auto i: sll){
		cout<<i<<" "; //output :0 1 2 3
	}

	cout<<endl;

	auto sll2=sll;

	sll2.push_front(-1);
	cout<<"첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";

	for(auto i: sll2){
		cout<<i<<" "; //출력 -1 0 1 2 3
	}

	cout<<endl;


	cout<<"깊은 복사 후 첫 번째 리스트: ";

	for(auto i : sll){
		cout<<i<<" "; //출력 0 1 2 3
	}

	cout<<endl;
	return 0;
}
