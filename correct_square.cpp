#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(a % b == 0)
		return b;
	return gcd(b, a%b);
}

// w와 h가 서로소인 사각형으로 축소 w' h'
// 대각선은 도착지점에 도착할 때까지 w'-1만큼 평행이동, h'-1만큼 수직이동 -> 지날 때마다 사용할 수 없는 사각형 +1
// 처음 지점(대각선 시작)의 정사각형 +1
// 따라서 (w'-1) + (h'-1) + 1 = w' + h' - 1

// 축소 시킨 사각형을 다시 복구하기 위해 공약수를 곱해줌

// w * h - gcd (w, h)


long long solution(int w,int h) {
    long long answer = (long long) w * (long long)h; 
		int gcd_result;

		gcd_result = gcd(w, h);
		answer -= (w + h - gcd_result);

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
