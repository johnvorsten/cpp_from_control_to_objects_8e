#include <string>
#include <map>
#include <iostream>

using namespace std;

class BankAccount{};

class SavingsAccount : BankAccount {
	private:
	double interestRate;
	int interestType;
	
	public:
	SavingsAccount();
	SavingsAccount(double a, string b) {
		interestRate = a;
		
		if (b == "Simple") {
			interestType = 1;
		}
		else if (b == "Compound") {
			interestType = 2;
		}
	}
		
	double getInterestRate() {
		return interestRate;
	}
		
	int getInterestType() {
		return interestType;
	}
		
};



int main () {

	int minutes = 1;
	auto res = minutes < 2 ? "undercooked" : (minutes >= 2 && minutes <= 4) ? "soft-boiled" : (minutes >= 5 && minutes <= 7) ? "hard-boiled" : (minutes >= 8 && minutes <= 11) ? "overcooked" : "invalid";
	std::cout << res;

	minutes = 3;
	res = minutes < 2 ? "undercooked" : (minutes > 2 && minutes < 4) ? "soft-boiled" : (minutes > 5 && minutes < 7) ? "hard-boiled" : (minutes > 8 && minutes < 11) ? "overcooked" : "invalid";
	std::cout << res;

	minutes = 6;
	res = minutes < 2 ? "undercooked" : (minutes > 2 && minutes < 4) ? "soft-boiled" : (minutes > 5 && minutes < 7) ? "hard-boiled" : (minutes > 8 && minutes < 11) ? "overcooked" : "invalid";
	std::cout << res;

	minutes = 9;
	res = minutes < 2 ? "undercooked" : (minutes > 2 && minutes < 4) ? "soft-boiled" : (minutes > 5 && minutes < 7) ? "hard-boiled" : (minutes > 8 && minutes < 11) ? "overcooked" : "invalid";
	std::cout << res;


    return 0;
}