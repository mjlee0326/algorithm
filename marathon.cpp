#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
		unordered_multiset<string> set_p;
		unordered_multiset<string> set_c;

		auto it_com = completion.begin();
		auto it_par = participant.begin();

		//완주 선수 이름 set_c
		while(it_com != completion.end()){ 
			set_c.insert(*it_com);
			it_com++;
		}


		//multiset에 참가 선수 이름 있는지 확인
		for(int i = 0; i< participant.size(); i++){
			auto result = set_c.find(*it_par);
			if(result != set_c.end()){
				it_par++;
			}
			else{
				answer = *it_par;
				return answer;
			}
		}

		//동명이인 처리

		//참가 선수 이름 set_p
		it_par = participant.begin();

		while(it_par != participant.end()){ 
			set_p.insert(*it_par);
			it_par++;
		}
		it_com = completion.begin();

		for(int i = 0; i < completion.size(); i++){
			if(set_p.count(*it_com) != set_c.count(*it_com))
				return *it_com;
			it_com++;
		}
		
		
    return answer;
}

int main(){
	string sol;
	
	sol = solution({"leo", "kim", "eden"}, {"leo", "eden"});
	cout<<sol<<endl;
	sol = solution({"leo", "kim", "eden", "leo"}, {"leo", "eden", "kim"});
	cout<<sol<<endl;

	return 0;
}
