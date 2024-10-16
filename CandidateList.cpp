#include "CandidateList.h"
using namespace std;
// Default constructor
CandidateList::CandidateList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}
// addCandidate
void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	if (count == 0)
	{
		first = new Node(newCandidate, nullptr);
		last = first;
	}
	else
	{
		last->setLink(new Node(newCandidate, nullptr));
		last = last->getLink();
	}
	++count;
}
// getWinner
int CandidateList::getWinner() const
{
	if (first == nullptr)
	{
		cerr << "=> List is empty.";
		return 0;
	}
	else
	{
		Node* current = first;
		Node* highestVotes = current;
		while (current->getLink() != nullptr)
		{
			if (highestVotes->getCandidate().gettotal_votes() <
				current->getLink()->getCandidate().gettotal_votes())
			{
				highestVotes = current->getLink();
			}
			current = current->getLink();
		}
		return highestVotes->getCandidate().getId();
	}
}
// isEmpty
bool CandidateList::isEmpty() const
{
	return (first == nullptr);
}
// searchCandidate
bool CandidateList::searchCandidate(int theID) const
{
	Node* target = nullptr;
	return searchCandidate(theID, target);
}
// printCandidateName
void CandidateList::printCandidateName(int theID) const
{
	Node* target = nullptr;
	if (searchCandidate(theID, target))
	{
		target->getCandidate().printName();
	}
}
// printAllCandidates
void CandidateList::printAllCandidates() const
{
	if (first == nullptr)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* current = first;
		while (current != nullptr)
		{
			current->getCandidate().printName();
			cout << endl;
			current = current->getLink();
		}
	}
}
// printKingdomVotes
void CandidateList::printCampusVotes(int theID, int index) const
{
	Node* target = nullptr;
	if (searchCandidate(theID, target))
	{
		cout << setw(5) << right << "*";
		cout << setw(3) << right <<
			target->getCandidate().getVotesByCampus(index);
		//cout << "( => )" << CAMPUS[index] << endl;
	}
}
// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int idNum) const
{
	Node* current = nullptr;
	if (searchCandidate(idNum, current))
	{
		cout << setw(6) << right << "=>";
		cout << " Total votes: " <<
			current->getCandidate().gettotal_votes() << endl;
	}
}
// printFinalResults
void CandidateList::printFinalResults() const
{
	if (first == nullptr)
	{
		cerr << "List is empty.";
	}
	else
	{
		cout << "************ FINAL RESULTS ************\n" << endl;
		cout << "LAST" << setw(16) << "FIRST" << setw(10) << "TOTAL"
			<< setw(7) << "POS" << endl;
		cout << "NAME" << setw(15) << "NAME" << setw(11) << "VOTES"
			<< setw(7) << "#" << endl;
		cout << "_______________________________________\n" << endl;
		Node* current = first;
		Node* highestVotes = first;
		while (current != nullptr)
		{
			if (highestVotes->getCandidate().gettotal_votes() <
				current->getCandidate().gettotal_votes())
			{
				highestVotes = current;
			}
			current = current->getLink();
		}
		int pos = 1;
		cout << setw(15) << left <<
			highestVotes->getCandidate().getLastName()
			<< setw(10) <<
			highestVotes->getCandidate().getFirstName()
			<< setw(5) << right <<
			highestVotes->getCandidate().gettotal_votes()
			<< setw(7) << pos << endl;
		int lastHigh = highestVotes->getCandidate().gettotal_votes();
		while (pos < count)
		{
			current = first;
			highestVotes = first;
			while (current != nullptr &&
				highestVotes->getCandidate().gettotal_votes() !=
				lastHigh - 1)
			{
				while (highestVotes->getCandidate().gettotal_votes() >
					lastHigh - 1)
				{
					highestVotes = highestVotes->getLink();
				}
				if (current->getCandidate().gettotal_votes() <
					lastHigh &&
					current->getCandidate().gettotal_votes() >
					highestVotes->getCandidate().gettotal_votes())
				{
					highestVotes = current;
				}
				current = current->getLink();
			}
			lastHigh = highestVotes->getCandidate().gettotal_votes();
			++pos;
			cout << setw(15) << left <<
				highestVotes->getCandidate().getLastName()
				<< setw(10) <<
				highestVotes->getCandidate().getFirstName()
				<< setw(5) << right <<
				highestVotes->getCandidate().gettotal_votes()
				<< setw(7) << pos << endl;
			if (pos % 5 == 0)
				cout << "- - - - - - - - - - - - - - - - - - - -"
				<< endl;
		}
		current, highestVotes = nullptr;
		cout << "_______________________________________" << endl;
	}
}
// clearList
void CandidateList::clearList()
{
	Node* current = first;
	while (first != nullptr)
	{
		first = first->getLink();
		delete current;
		current = nullptr;
	}
	count = 0;
	last = nullptr;
}
// Destructor
CandidateList::~CandidateList()
{
	clearList();
}
// searchCandidate
bool CandidateList::searchCandidate(int theID, Node*& target) const
{
	target = first;
	if (target == nullptr)
	{
		cerr << "=> List is empty.";
		return false;
	}
	else
	{
		while ((target != nullptr))
		{
			if (target->getCandidate().getId() == theID)
				return true;
			else
				target = target->getLink();
		}
		cout << " => ID not in the list." << endl;
		return false;
	}
}