#include <iostream>
#include <list>
#define MAX 100

using namespace std;

list<int> removeDuplicates(const list<int>& in){

	list<int> out;

	for(auto ival : in){
		bool found=false;
		for(auto oval : out){
			if(ival==oval){
				found=true;
				break;
			}
		}

		if(!found){
			out.push_back(ival);
		}
	}
	return out;
}

int main(int argc, char* argv[]){
	list<int>::iterator iter;
	list<int> list={10, 6, 64, 21, 53, 21, 10, 4, 2};

	list=removeDuplicates(list);

	iter=list.begin();
	
	while(iter!=list.end()){
		cout<<*iter<<" ";
		iter++;
	}

	cout<<endl;

	return 0;
}
