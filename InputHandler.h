#pragma once
#include <fstream>
#include <string>
#include "CandidateList.h"
#include "PersonType.cpp"

void createCandidateList(std::ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[no_of_campuses];
	string fName, lName;
	infile >> ssn;
	while (ssn != -999)
	{
		CandidateType newCandidate;
		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);
		for (int i = 0; i < no_of_campuses; ++i)
		{
			infile >> allVotes[i];
			newCandidate.update_votes_by_campus(i, allVotes[i]);
		}
		candidateList.addCandidate(newCandidate);
		infile >> ssn;
	}
}
void readCandidateData(CandidateList& candidateList)
{
	std::ifstream infile;
	infile.open("Candidate_data.txt");
	if (!infile)
	{
		cout << "Input file does not exist." << endl;
		exit(1);
	}
	createCandidateList(infile, candidateList);
	infile.close();
}