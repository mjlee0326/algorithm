#include <iostream>
#include "mapreduce.hpp"

//맵리듀스를 사용하여 소수 확인하기

using namespace std;
namespace prime_calculator{
	if(number > 2){
		if(number % 2 == 0)
			return fasle;

		//std::abs(n) return |n|
		long const n = abs(number);
		long const sqrt_number = static_cast<long>(sqrt(static_cast<double>(n)));

		for(long i = 3; i <= sqrt_number; i+=2){
			if(n % i == 0)
				return false;
		}
	}
	else if (number == 0 || number == 1)
		return false;

	return true;
}

tempalte<typename MapTask>
class number_source : mapreduce::detail::noncopyable{

}
