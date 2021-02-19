#include <iostream>
#include <list>
#include <string>
#include <unordered_set>

using namespace std;

list<int> removeDuplicates(const list<int>& in){
	list<int> out;

	for(auto ival : in){
		bool isDup=false;
		for(auto oval : out){
			if(ival == oval){
				isDup=true;
			}
		}
		if(!isDup){
			out.push_back(ival);
		}
	}

	return out;
}

//중복 제거가 목적이라면, 집합을 떠올리자
list<int> removeDuplicates_2(const list<int>& in){
	unordered_set<int> s(in.begin(), in.end());
	list<int>out(s.begin(), s.end());
	return out;
}

//cout<<boolalpha; -> output: true, false
bool checkNesting(string str){
	int cnt=0;

	if(str[0]!='('){
		return false;
	}
	for(int i=0; i<str.length(); i++){
		if(str[i]=='('){
			cnt++;
		}
		if(str[i]==')'){
			if(cnt<1){
				return false;
			}
			else{
				cnt--;
			}
		}
	}
	if(cnt!=0){
		return false;
	}
	return true;

}

int main(int argc, char* argv[]){

	if(argc!=2){
		cout<<"check input"<<endl;
		return -1;
	}

	cout<<boolalpha;
	cout<<checkNesting(argv[1])<<endl;
	return 0;
}
