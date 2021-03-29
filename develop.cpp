#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> answer){
	for(int i = 0; i < answer.size(); i++){
		cout<<answer[i]<<"  ";
	}
	cout<<endl;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
		vector<int> wait;

		auto it_pg = progresses.begin();
		auto it_sp = speeds.begin();
		int day = 0;
		int rest = 0;
		int cnt;

		for(int i = 0; i < progresses.size(); i++){
			rest= 100 - *(it_pg + i);
			day = rest / *(it_sp + i);
			if(rest % *(it_sp + i) != 0){
				day++;
			}
			wait.insert(wait.end(), day);
		}

		auto it_wait = wait.begin();

		for(int i = 0; i <= wait.size(); i++){
			cnt =1;
			if(i >= wait.size()){
				answer.insert(answer.end(), cnt);
				break;
			}
			for(int j = 1; it_wait + i + j != wait.end(); j++){
				if(*(it_wait + i) >= *(it_wait + i + j)){ //앞 순서가 개발 날짜가 더 걸림
					cnt++;
					if(i + j + 1 == wait.size()){
						answer.insert(answer.end(), cnt);
						return answer;
					}
				}
				else{
					answer.insert(answer.end(), cnt);
					i+=cnt-1;
					break;
				}
			}
		}

    return answer;
}


int main(){
	vector<int> answer;
	answer = solution({93, 30, 55}, {1, 30, 5});
	print(answer);
	answer = solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});
	print(answer);

	return 0;
}
