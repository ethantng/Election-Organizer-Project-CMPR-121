#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include<iostream>
#include<string>
const int no_of_campuses = 4;
using namespace std;

class PersonType
{
private:
	string firstName;
	string lastName;
	int id = 0;

public:
	PersonType()
	{
		firstName = " ";
		lastName = " ";
		id = 0;
	}

	void setPersonInfo(string first, string last, int ID)
	{
		firstName = first;
		lastName = last;
		id = ID;
	}

	string getFirstName() const
	{
		return firstName;
	}

	string getLastName() const
	{
		return lastName;
	}

	int getId() const
	{
		return id;
	}

	void printName() const
	{
		cout << lastName << ", " << firstName << endl;
	}



};

#endif
