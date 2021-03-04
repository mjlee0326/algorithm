#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

struct citizen{
	string name;
	int age;
};

ostream &operator<<(ostream &ostr, const citizen &c){
	return(ostr<<"["<<c.name<<", "<<c.age<<"]");
}

int main(){
	forward_list<citizen> citizens={
		{"Kim", 20}, {"Lee", 25}, {"Park", 33}, {"Jin", 42}
	};

	auto citizens_copy=citizens; //deep copy

	cout<<"전체 시민들: ";
	for(const auto &c :citizens){
		cout<<c<<" ";
	}
	cout<<endl;
}
