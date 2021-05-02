#include <iostream>

using namespace std;

int gcb(int a, int b){
	if(a % b == 0)
		return b;
	return gcb(b, a%b);
}


long long solution(int w,int h) {
    long long answer = (long long) w * (long long)h; 
		int lcm;

		lcm = gcb(w, h);
		answer -= (w + h - lcm);

		return answer;
}

int main(){
	long long answer;
	answer = solution(8, 12);
	cout<<answer<<endl;
	cout<<solution(5, 3)<<endl;
	cout<<solution(1, 8)<<endl;
	cout<<solution(4, 5)<<endl;
	cout<<solution(3, 5)<<endl;
}
