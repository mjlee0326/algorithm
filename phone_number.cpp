#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(string s1, string s2){
	return s1.size() < s2.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
		unordered_multiset<string> set;

		auto it = phone_book.begin();

		string str;
		string str_tmp;
		int size = 0;

		sort(phone_book.begin(), phone_book.end(), compare);

		for(int k =0; k < phone_book.size(); k++){
			str = *it; //str: *it 원본값

			if(size != str.length()){
				set.clear();
				size = str.length(); //size: 원본 str의 길이
				for(const auto& i : phone_book){
					if(i != *it && i.length() >= size){
						str_tmp = i.substr(0, size); //str_tmp: size 길이로 자른 str(해시에 저장)
						if(set.find(str) != set.end()){
							answer = false;
							return answer;
						}
						set.insert(str_tmp);
					}
				}
			}
			else{
				//unordered_set으로 했을 때 erase로 "456" 지우면 "4566" 값도 확인을 못하게 됨
				//unordered_multiset으로 해결 
				str_tmp = *(it-1);
				set.erase(set.find(str));
				set.insert(str_tmp.substr(0, size));
			}

			auto result = set.find(str);
			if(result != set.end()){
				answer = false;
				return answer;
			}
			it++;
		}

		answer = true;
    return answer;
}

int main(){
	bool answer;
	answer = solution({"119", "1195524421", "97674223"});
	cout<<boolalpha<<answer<<endl;
	
	answer = solution({"123", "456", "789"});
	cout<<boolalpha<<answer<<endl;

	answer = solution({"12", "123", "1235", "567", "88"});
	cout<<boolalpha<<answer<<endl;

	answer = solution({"123", "456", "789", "4566"});
	cout<<boolalpha<<answer<<endl;

	answer = solution({"111113", "1112", "12"});
	cout<<boolalpha<<answer<<endl;

	return 0;
}
