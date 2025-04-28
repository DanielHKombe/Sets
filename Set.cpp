#include "Set.h"

Set::Set(vector<vector<int>>TSets, vector<string>names, const int Uarry[], int Usize) :
	ASets(TSets),
	sets(names)
{
	size = Usize;
	USet = new int[size];
	for (int i = 0; i < size; i++)
		USet[i] = Uarry[i];
}

Set::Set(const Set& obj) :
	ASets(obj.ASets),
	sets(obj.sets),
	size(obj.size)
{
	USet = new int[size];
	for (int i = 0; i < size; i++)
		USet[i] = obj.USet[i];
}

Set::~Set()
{
	delete[]USet;
	USet = NULL;
}

void Set::printASets()
{
	cout << "Outputing the elements in the Universal set:\n{ ";
	for (int i = 0; i < size; i++)
	{
		cout << USet[i] << " ";
		/*if (i%11==0)
			cout << endl;*/
		if (i == (size - 1))
			cout << "}\n\n";
	}
	for (int i = 0; i < ASets.size(); i++)
	{
		cout << "Now outputing the elements in set: " << sets[i] << "\n{ ";
		int it = 0;
		for (int num : ASets[i])
		{
			cout << num << " ";
			/*if (it%11==0)
				cout << endl;*/
			if (it == (ASets[i].size() - 1))
				cout << "}\n\n";

			it++;
		}
	}
}
void Set::printSetD(vector<vector<int>>SetD)
{
	for (int i = 0; i < SetD.size(); i++)
	{
		cout << "Now outputing the elements in set: " << sets[i] << " Difference\n{ ";
		int it = 0;
		for (int num : SetD[i])
		{
			cout << num << " ";
			/*if (it%11==0)
				cout << endl;*/
			if (it == (SetD[i].size() - 1))
				cout << "}\n\n";

			it++;
		}
	}
}

void Set::printSetC(vector<vector<int>>SetC)
{
	for (int i = 0; i < SetC.size(); i++)
	{
		cout << "Now outputing the elements in set: " << sets[i] << " Complement\n{ ";
		int it = 0;
		for (int num : SetC[i])
		{
			cout << num << " ";
			/*if (it%11==0)
				cout << endl;*/
			if (it == (SetC[i].size() - 1))
				cout << "}\n\n";

			it++;
		}
	}
}

void Set::printSet(vector<int>Uset)
{
	int i = 0;
	cout << "{ ";
	for (int num : Uset)
		cout << num << " ";

	cout << "}\n\n";
}

vector<int> Set::ISet()
{
	vector<int>intSec;
	for (int i = 0; i < ASets[0].size(); i++)
	{
		if (numCheck(ASets[0][i]))
			intSec.push_back(ASets[0][i]);
	}
	return intSec;

}

bool Set::numCheck(int num)
{
	int count = 0;
	for (int i = 1; i < ASets.size(); i++)
	{
		for (int ct = 0; ct < ASets[i].size(); ct++)
			if (num == ASets[i][ct])
			{
				count++;
				break;
			}
	}
	if (count == (ASets.size() - 1))
		return true;
	return false;
}

vector<int> Set::uSet()
{
	int max = ASets[0].size();
	for (int i = 1; i < ASets.size(); i++)
	{
		if (max < ASets[i].size())
			max = ASets[i].size();
	}
	vector<int>Uset;
	for (int num : ISec)
		Uset.push_back(num);

	for (int i = 0; i < ASets.size(); i++)
	{
		for (int ct = 0; ct < ASets[i].size(); ct++)
		{
			if (InumCheck(ASets[i][ct], Uset))
				Uset.push_back(ASets[i][ct]);
		}
	}
	return Uset;
}

bool Set::InumCheck(int num, vector<int>Usec)
{
	for (int nums : Usec)
	{
		if (num == nums)
			return false;
	}
	return true;
}

vector<vector<int>> Set::setDifference()
{
	bool found = false;
	vector<vector<int>>setD(ASets.size());
	for (int i = 0; i < ASets.size(); i++)
	{
		for (int ct = 0; ct < ASets[i].size(); ct++)
		{
			found = false;
			for (int num : ISec)
			{
				if (ASets[i][ct] == num)
				{
					found = true;
					break;
				}

			}
			if (!found)
				setD[i].push_back(ASets[i][ct]);
		}
	}
	return setD;
}

vector<vector<int>> Set::setComplement()
{
	bool found = false;
	vector<vector<int>>setC(ASets.size());
	for (int i = 0; i < ASets.size(); i++)
	{
		for (int ct = 0; ct < size; ct++)
		{
			found = false;
			for (int u = 0; u < ASets[i].size(); u++)
			{
				if (USet[ct] == ASets[i][u])
				{
					found = true;
					break;
				}

			}
			if (!found)
				setC[i].push_back(USet[ct]);
		}
	}
	return setC;
}