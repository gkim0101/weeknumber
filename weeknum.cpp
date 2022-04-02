#include <iostream>
#include <ctime>

int week_num(const std::tm& tm){
	constexpr int DAYS_PER_WEEK=7;

	const int wday = tm.tm_wday;
	const int delta = wday ? wday-1 : DAYS_PER_WEEK-1;
	return (tm.tm_yday + DAYS_PER_WEEK - delta)/DAYS_PER_WEEK;
}

int main(){
	std::time_t t=std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout<<(now->tm_year+1900)<<'-'
		<< (now->tm_mon +1) <<'-'
		<< now->tm_mday
		<<std::endl;
	
	std::cout<<week_num(*now)<<std::endl;
	

	return 0;
}
