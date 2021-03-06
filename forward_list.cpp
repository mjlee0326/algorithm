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

	cout<<"All citizens: ";
	for(const auto &c :citizens){
		cout<<c<<" ";
	}
	cout<<endl;

	//lambda expression
	citizens.remove_if([](const citizen &c){
				return (c.age<26);
			});
				
	cout<<"older than 26: ";
	for(const auto &c :citizens){
		cout<<c<<" ";
	}
	cout<<endl;

	citizens_copy.remove_if([](const citizen &c){
				return (c.age!=25);
			});

	cout<<"age 25: ";
	for(const auto &c :citizens_copy){
		cout<<c<<" ";
	}
	cout<<endl;


	//
}
