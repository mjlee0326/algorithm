#include <iostream>
#include <type_traits>

using namespace std;

struct Base{};

struct Derived : Base {} ;

int main(){
	typedef common_type<char, short, int>::type A;
	typedef common_type<float, double>::type B;
	typedef common_type<Derived, Base>::type C;
	typedef common_type<Derived*, Base*>::type D;
	typedef common_type<const int, volatile int>::type E;


	cout<<boolalpha;
	cout<<"typedefs of int: "<<endl;

	cout<<"A: "<<is_same<int, A>::value<<endl;
	cout<<"B: "<<is_same<int, B>::value<<endl;
	cout<<"C: "<<is_same<int, C>::value<<endl;
	cout<<"D: "<<is_same<int, D>::value<<endl;
	cout<<"E: "<<is_same<int, E>::value<<endl;

	exit(0);
	
}
