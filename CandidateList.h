#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H
#include "Candidatetype.h"
#include <iostream>
#include <string>
#include <iomanip>
class Node
{
public:
	Node() : link(nullptr) {}
	Node(const CandidateType& newCandidate, Node* theLink)
		: candidate(newCandidate), link(theLink) {}
	Node* getLink() const { return link; }
	CandidateType getCandidate() const { return candidate; }
	void setCandidate(const CandidateType& newCandidate)
	{
		candidate = newCandidate;
	}
	void setLink(Node* theLink) { link = theLink; }
	~Node() {}
private:
	CandidateType candidate;
	Node* link; //pointer that points to next node
};
class CandidateList
{
public:
	
	CandidateList();
	
	void addCandidate(const CandidateType&);
	
	int getWinner() const;
	
	bool isEmpty() const;
	
	bool searchCandidate(int) const;
	
	void printCandidateName(int) const;
	
	void printAllCandidates() const;
	
	void printCampusVotes(int, int) const;
	
	void printCandidateTotalVotes(int) const;
	
	void printFinalResults() const;
	
	void clearList();
	
	~CandidateList();
private:
	// searchCandidate
	bool searchCandidate(int, Node*&) const;
	Node* first; // pointer to the first candidate in the list
	Node* last; // pointer to last candidate in the list
	int count; // number of candidates in the list
};
#endif
