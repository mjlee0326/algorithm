#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_DIGIT 4

using namespace std;


string solution(vector<int> numbers) {
    string answer = "";
		vector<string> strVec;
		vector<int> copy(numbers);
		int large, index, num;
		int j;
		int size;
		string str1, str2;
		string str;


		for(int i=0; i<copy.size(); i++){
			strVec.push_back(to_string(copy[i]));
		}

		sort(strVec.begin(), strVec.end(), greater<>());

		/*
		for(int i=0; i<strVec.size(); i++){
			cout<<strVec[i]<<"  ";
		}
		
		cout<<endl;
*/


		if(strVec[0]=="0"){ //all zero
			answer+=strVec[0];
			return answer;
		}

		while(strVec.size()!=0){
			if(strVec.size()==1){
				answer+=strVec[0];
				break;
			}
			while(strVec.size()>1 && strVec[0][0]>strVec[1][0]){ //앞자리가 크다면 계속 추가
				answer+=strVec[0];
				strVec.erase(strVec.begin());
			}
			if(strVec.size()>1 && strVec[0][0]==strVec[1][0]){ //앞자리가 같음
				index=-1;
				int i=1;
				char num=strVec[0][0];
				int digit=-1;
				int k;

				while(strVec.size()>i && strVec[i][0]==num){ //앞자리 같은 수 index 찾기 (i-1)까지
					i++;
				}
				for(k=0; k<i; k++){//앞자리가 같은 수 사이에서
					j=0;
					while(strVec[k][j]==num){ //33(j 1) 999(j 7)
						j++;
					}
					if(strVec[k][j]=='\0'){ //3333 9999 다 같은 수
						digit=k;
						break;
					}
				}

				i=1;
				while(1){ //둘이 자릿수가 같으면 계속 다음칸으로
					if(strVec[0][i]<strVec[1][i]){ //strVec[0][i]가 null일 가능성 12 121   1111111
						if(strVec[0][i]=='\0'){
							while(strVec[1][i+1]!='\0'){ //strVec[1]의 끝자리 i
								i++;
							}
							j=0;
							while(strVec[0][j]==strVec[1][i]){//[1]의 끝값이랑 같다면 계속
								j++;
							}
							if(strVec[0][j]>strVec[1][i]){  //333333 digit [5]  335 j [2]
								index=0;
								break;
							}
						} 
						index=1;
						break;
					}
					else if(strVec[0][i]>strVec[1][i]){ //strVec[1][i]가 null일 가능성 121 12
						if(strVec[1][i]=='\0'){
							while(strVec[0][i+1]!='\0'){ //strVec[0]로의 끝자리 1
								i++;
							}
							j=0;
							while(strVec[1][j]==strVec[0][i]){ //2
								j++;
							}
							if(strVec[1][j]>strVec[0][i]){
								index=1;
								break;
							}
						}
						index=0;
						break;
					}
					i++;
				}
				if(index!=-1){
					for(int i=0; i<strVec[index].length(); i++){
						if(digit!=-1 && strVec[index][i]<num){
							index=digit;
							break;
						}
					}
					answer+=strVec[index];
					strVec.erase(strVec.begin()+index);
				}
			}
		}

    return answer;
}

int main(){
	vector<int> numbers={6, 10, 2};
	vector<int> numbers2={3, 30, 34, 5, 9};
	vector<int> numbers3={0, 0, 0, 0, 0};
	vector<int> numbers4={0, 5, 10, 15, 20};
	vector<int> numbers5={1000, 0, 5, 99, 100};
	vector<int> numbers6={403, 40};
	vector<int> numbers7={21, 212};
	vector<int> numbers8={212, 21};
	vector<int> numbers9={10, 101};
	vector<int> numbers10={1, 11, 111, 1111};
	vector<int> numbers11={0, 5, 10, 15, 20};
	vector<int> numbers12={33, 33};
	vector<int> numbers13={12, 121};
	vector<int> numbers14={121, 12};
	vector<int> numbers15={0, 1000, 0, 0};
	vector<int> numbers16={33, 9, 33, 25, 21, 212, 8, 0, 21};
	vector<int> numbers17={40, 403};
	vector<int> numbers18={998, 9, 999};
	vector<int> numbers19={9, 99991, 91};
	string answer;

	answer=solution(numbers);
	cout<<answer<<endl;
	answer=solution(numbers2);
	cout<<answer<<endl;
	answer=solution(numbers3);
	cout<<answer<<endl;
	answer=solution(numbers4);
	cout<<answer<<endl;
	answer=solution(numbers5);
	cout<<answer<<endl;
	answer=solution(numbers6);
	cout<<answer<<endl;
	answer=solution(numbers7);
	cout<<answer<<endl;
	answer=solution(numbers8);
	cout<<answer<<endl;
	answer=solution(numbers9);
	cout<<answer<<endl;
	answer=solution(numbers10);
	cout<<answer<<endl;
	answer=solution(numbers11);
	cout<<answer<<endl;
	answer=solution(numbers12);
	cout<<answer<<endl;
	answer=solution(numbers13);
	cout<<answer<<endl;
	answer=solution(numbers14);
	cout<<answer<<endl;
	answer=solution(numbers15);
	cout<<answer<<endl;
	answer=solution(numbers16);
	cout<<answer<<endl;
	answer=solution(numbers17);
	cout<<answer<<endl;
	answer=solution(numbers18);
	cout<<answer<<endl;
	answer=solution(numbers19);
	cout<<answer<<endl;
	return 0;
}
