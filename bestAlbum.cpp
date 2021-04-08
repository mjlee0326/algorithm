#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

		map<string, int> m;
		map<int, string> genresM;

		auto it_g = genres.begin();
		auto it_p = plays.begin();

		for(int i = 0; i < genres.size(); i++){
			m[*(it_g+i)]+=*(it_p+i);
		}


		//map은 key값을 기준으로 오름차순 정렬이므로 map m의 key value값 temp
		for(const auto& tmpM : m){
			genresM[tmpM.second] = tmpM.first;
		}

		auto it_genresM = genresM.end();

		it_genresM--;
		
		int max1, max2, compare;

		for(int i = 0; i < genresM.size(); i++){
			max1 = 0;
			max2 = 0;
			int j = 0;
			auto it_cur = genres.begin();
			auto it1 = genres.end();
			auto it2 = genres.end();
			while(it_g + j != genres.end()){
				it_cur = find(it_g+j, genres.end(), it_genresM -> second);
				compare = 0;
				if(it_cur != genres.end())
					compare = *(plays.begin() + (it_cur - genres.begin())); 
				else
					break;

				if(compare > max1){
					max2 = max1;
					max1 = compare;
					j = it_cur - genres.begin();
					
					it2 = it1;
					it1 = it_cur;
				}

				else if(compare > max2){
					max2 = compare;
					j = it_cur - genres.begin();

					it2 = it_cur;
				}

				j++;
			}

			if(it1 != genres.end())
				answer.push_back(it1 - genres.begin());
			if(it2 != genres.end())
				answer.push_back(it2 - genres.begin());
			it_genresM--;
		}

    return answer;
}

void print(vector<int> answer){
	for(const auto& a : answer)
		cout<<a<<"  ";

	cout<<endl<<endl;
}

int main(){
	vector<int> answer;

	answer = solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
	print(answer);

	answer = solution({"A", "B", "C", "A", "C"}, {200, 400, 121, 631, 221});
	print(answer);

	answer = solution({"A", "B", "C", "A", "C"}, {300, 400, 121, 300, 221});
	print(answer);

	answer = solution({"A", "A", "B", "B"}, {6, 6, 4, 4});
	print(answer);
	
	answer = solution({"classic", "pop", "classic", "classic","jazz","pop", "Rock", "jazz"}, {500, 600, 150, 800, 1100, 2500, 100, 1000});
	print(answer);
	return 0;
}
