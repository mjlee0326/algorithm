#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

template <typename T>

class dynamic_array{
	T* data;
	size_t n;

	public:
	dynamic_array(int n){
		this->n = n;
		data = new T[n];
	}

	dynamic_array(const dynamic_array<T>& other){
		n=other.n;
		data=new T[n];

		for(int i=0; i<n; i++){
			data[i]=other[i];
		}
	}

	T& operator[](int index){
		return data[index];
	}

	const T& operator[](int index) const{
		return data[index];
	}

	T& at(int index){
		if(index < n){
			return data[index];
		}
		throw "Index out of range";
	}

	size_t size() const{
		return n;
	}

	~dynamic_array(){
		delete[] data;
	}

	T* begin(){
		return data;
	}

	const T* begin() const{
		return data;
	}

	T* end(){
		return data+n;
	}

	const T* end() const{
		return data+n;
	}

	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2){
		dynamic_array<T> result(arr1.size() + arr2.size());
		copy(arr1.begin(), arr1.end(), result.begin());
		copy(arr2.begin(), arr2.end(), result.begin()+arr1.size());

		return result;
	}

	//배열에 저장된 모든 데이터를 문자열로 반환
	string to_string(const string& sep=", "){ //데이터 구분을 위한 문자열 sep
		if(n==0){
			return "";
		}
		
		ostringstream os;

		os<<data[0];

		for(int i=1; i<n; i++){
			os << sep << data[i];
		}

		return os.str(); //ostringstream을 str로 바꿈
	}
};

struct student{
	string name;
	int standard; //학급 정보
};

//<< 을 통한 표준 출력
ostream& operator<<(ostream& os, const student& s){
	return (os << "[" << s.name<<", " << s.standard<<"]");
}


int main(){

	int nStudents;
	cout<<"1반 학생 수 입력: ";
	cin>>nStudents;

	dynamic_array<student> class1(nStudents);
	
	for(int i=0; i<nStudents; i++){
		string name;
		int standard;

		cout<<i+1<<"번째 학생 이름과 나이 입력: ";
		cin>>name>>standard;
		
		class1[i]=student{name, standard};
	}

	try{
		//class1[nStudents]=student{"testName", 3}; //segment error
		class1.at(nStudents)=student{"testName", 8};
	}
	catch(...){
		cout<<"exception"<<endl;
	}

	//deep copy
	auto class2=class1;

	cout<<"1반을 복사하여 2반 생성: "<<class2.to_string()<<endl;

	//두 학급을 합쳐서 새로운 큰 학급 생성
	auto class3 = class1 + class2;
	cout<<"1반과 2반을 합쳐 3반 생성: "<<class3.to_string()<<endl;

	return 0;
}


