#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include<iostream>
#include<string>
#include"PersonType.h"
using namespace std;

class CandidateType :public PersonType
{
private:
	int total_votes;
	int campusVotes[no_of_campuses];

public:
	CandidateType() :PersonType(), total_votes(0)
	{
		for (int i = 0; i < no_of_campuses; i++)
		{
			campusVotes[i] = 0;
		}
	}

	void update_votes_by_campus(int campusNumber, int numVotes)
	{
		total_votes += numVotes;
		campusVotes[campusNumber - 1] += numVotes;
	}

	int gettotal_votes() const
	{
		return total_votes;
	}

	int getVotesByCampus(int campusNumber) const
	{
		return campusVotes[campusNumber - 1];
	}

	void printCandidateInfo(int campusNumber) const
	{
		cout << getId() << " - " << getLastName() << ", " << getFirstName() << endl; 
	}

	void printCandidatetotal_votes() const
	{
		cout << getLastName() << ", " << getFirstName() << " Total votes (all campuses): " << total_votes << endl; 
	}

	void printCandidateDivisionVotes(int divisionNumber) const
	{
		cout << getLastName() << ", " << getFirstName() << " Campus " << divisionNumber << " total votes: " << campusVotes[divisionNumber - 1] << endl; 
	}

	~CandidateType()
	{

	}

};

#endif