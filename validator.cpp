#include <iostream>
#include <string>

int ctoi(char c) {
	return c - '0';
}

bool isNumericString(const std::string& str)
{
	for (char c : str) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}

int calculateChecksum(const std::string& number)
{
	int sum = 0;
	int index = 0;

	for (char c : number) {
		int positionSum = ctoi(c);
		if (index % 2 == 0) {
			positionSum *= 2;
			if (positionSum > 9) {
				positionSum -= 9;
			}
		}
		index++;
		sum += positionSum;
	}

	return 10 - (sum % 10);
}

bool isValidNumber(const std::string& number)
{
	if (number.length() != 16) {
		std::cerr << "Invalid card number length" << std::endl;
		return false;
	}

	if (!isNumericString(number)) {
		std::cerr << "Number must contain only digits" << std::endl;
		return false;
	}

	int checksum = calculateChecksum(number.substr(0, 15));

	return checksum == ctoi(number[number.length() - 1]);
}

int main()
{
	std::string number;
	std::cout << "Enter card number: ";
	std::cin >> number;

	if (isValidNumber(number)) {
		std::cout << "Card Number " << number << " is valid" << std::endl;
	} else {
		std::cout << "Card Number " << number << " is invalid" << std::endl;
	}
	return 0;
}
