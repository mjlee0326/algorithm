#include <iostream>
#include <string>
#include <vector>
#define MAX_VAL 1000
#define MAX_DIGIT 5

using namespace std;


string solution(vector<int> numbers) {
    string answer = "";
		int large, index, num;
		int size=numbers.size();
		string temp1, temp2;
		
		string str1, str2;
		for(int i=0; i<size; i++){
			str1=to_string(numbers[0]);
			index=0;
			for(int j=1; j<numbers.size(); j++){
				str2=to_string(numbers[j]);
				if(str1[0]==str2[0]){
					for(int k=1; k<MAX_DIGIT; k++){
						if(str1[k]=='\0' && str2[k]<str1[0]){
							break;
						}

						else if(str2[k]=='\0' && str1[k]<str1[0]){
							str1=str2;
							index=j;
							break;
						}
						//null이 ascii 가장 작은 값
						else if(str1[k]<str2[k] && str2[k]!='0'){  //eg 3 30
							str1=str2;
							index=j;
							break;
						}
						else if(str1[k]=='0' && str2[k]!='0'){
							str1=str2;
							index=j;
							break;
						}
					}
				}
				else if(str1<str2){
					str1=str2;
					index=j;
				}
			}
			answer+=str1;
			if(str1[0]=='0' && answer=="0"){ //all zero
				break;
			}
			numbers.erase(numbers.begin()+index);
		}

    return answer;
}

int main(){
	vector<int> numbers={6, 10, 2};
	vector<int> numbers2={3, 30, 34, 5, 9};
	vector<int> numbers3={0, 0, 0, 0, 0};
	vector<int> numbers4={0, 5, 10, 15, 20};
	vector<int> numbers5={1000, 0, 5, 99, 100};
	vector<int> numbers6={40, 403};
	vector<int> numbers7={21, 212};
	vector<int> numbers8={10, 101};
	vector<int> numbers9={1, 11, 111, 1111};
	vector<int> numbers10={0, 5, 10, 15, 20};
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

	return 0;
}
