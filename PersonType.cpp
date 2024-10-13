#include "PersonType.h"
#include <string>
#include <iostream>
#include <iomanip>

PersonType::PersonType()
{
	int ssn = 0;
}

PersonType::PersonType(std::string first, std::string last, int SSN)
{
	firstname = first;
	lastname = last;
	ssn = SSN;
}

void PersonType::setPersonInfo(std::string first, std::string last, int SSN)
{
    firstname = first;
    lastname = last;
	ssn = SSN;
}

std::string PersonType::getFirstName() const
{
	return firstname;
}

std::string PersonType::getLastName() const
{
    return lastname;
}

double PersonType::getSSN() const
{
	return ssn;
}

void PersonType::printName()
{
    std::cout << lastname << ", " << firstname << std::endl;
}

void PersonType::printPersonInfo()
{
	printSSN();
    std::cout << " " << firstname << " " << lastname << std::endl;
}

void PersonType::printSSN()
{
    
	std::cout << std::setw(3) << std::setfill('0') << (ssn / 1000000) << "-"
		<< std::setw(2) << std::setfill('0') << ((ssn / 10000) % 100) << "-"
		<< std::setw(4) << std::setfill('0') << (ssn % 10000);


}

PersonType::~PersonType()
{

}