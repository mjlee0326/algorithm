#include <iostream>
#include <algorithm>

struct singly_ll_node{
	int data;
	singly_ll_node* next;
};

class singly_ll{
	public:
		using node = singly_ll_node;
		using node_ptr = node*;

	private:
		node_ptr head;	
};

int main(){
	return 0;
}
