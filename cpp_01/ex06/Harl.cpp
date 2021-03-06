#include "Harl.hpp"

using std::endl; using std::cout;

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {
	void (Harl::*mfunc[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::nomatch};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int idx = 0;
	while (idx < 4 && level != levels[idx]) idx++;

	switch(idx) {
		case 0:
			(this->*mfunc[0])();
		case 1:
			(this->*mfunc[1])();
		case 2:
			(this->*mfunc[2])();
		case 3:
			(this->*mfunc[3])();
			break ;
		default:
			(this->*mfunc[4])();
	}
}

void Harl::warning() {
	cout
	<< "[ WARNING ]\n"
	<< "I think I deserve to have some extra bacon for free.\n"
	   "I’ve been coming for years whereas you started working here since last month.\n"
	<< endl;
}

void Harl::error() {
	cout
	<< "[ ERROR ]\n"
	<< "This is unacceptable! I want to speak to the manager now.\n"
	<< endl;
}

void Harl::info() {
	cout
	<< "[ INFO ]\n"
	<< "I cannot believe adding extra bacon costs more money.\n"
	   "You didn’t put enough bacon in my burger! If you did,"
	   "I wouldn’t be asking for more!\n"
	<< endl;
}

void Harl::debug() {
	cout
	<< "[ DEBUG ]\n"
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
	<< endl;
}

void Harl::nomatch() {
	cout
	<< "[ Probably complaining about insignificant problems ]"
	<< endl;
}
