#include "Set.h"

void sortArry(vector<int>&Uset, int size)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = Uset[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (Uset[index] < minValue)
            {
                minValue = Uset[index];
                minIndex = index;
            }
        }
        Uset[minIndex] = Uset[startScan];
        Uset[startScan] = minValue;
    }
}


int main()
{
	cout << "[ENTER] the number of elements in the Universe: ";
	int Unum;
	cin >> Unum;
	int *Uset = new int[Unum];
	cout << "[ENTER] all the " << Unum << " elements in the Universal set:\n";
	int elems;
	for (int i = 0; i < Unum; i++)
	{
		cin >> elems;
		Uset[i] = elems;
	}
	cout << "\nHow many sets do you want to create: ";
	int numSets;
	cin >> numSets;
	vector<vector<int>>Sets(numSets);
	
	vector<string>setNames;
	string name;
	for (int i = 0; i < numSets; i++)
	{	
		cout << "\nWhat will this set be called: ";
		cin.ignore();
		getline(cin, name);
		setNames.push_back(name);
		cout << "[ENTER] the number of elements in set " << name << ":\n";
		int num;
		cin >> num;
		cout << "[ENTER] all the " << num << " elements in set " << name << ":\n";
		for (int it = 0; it < num; it++)
		{
			cin >> elems;
			Sets[i].push_back(elems);
		}
		if (i < (numSets - 1))
			cout << "Alright, onto the next set\n\n";
	}
	Set set1(Sets, setNames, Uset, Unum);
	cout << "\n\n\n";
	set1.printASets();
	cout << "\n\n";
	cout << "The intersection of the sets is:\n";
	vector<int>InSet = set1.ISet();
	set1.getInSec(InSet);
	set1.printSet(InSet);
	vector<int>UnSet = set1.uSet();
	sortArry(UnSet, UnSet.size());
	set1.getUnSec(UnSet);
	cout << "\n\nThe union of the sets is:\n";
	set1.printSet(UnSet);
	cout << "\n\nNow it's time to find the set difference of:\n";
	for (int i = 0; i < setNames.size(); i++)
	{
		if (i == (setNames.size() - 1))
			cout << setNames[i] << " = \n";

		else
			cout << setNames[i] << " - ";
	}
	vector<vector<int>>setd = set1.setDifference();
	set1.printSetD(setd);
	cout << "\n\nLet's now find the set Complements\n";
	vector<vector<int>>setc = set1.setComplement();
	set1.printSetC(setc);
	delete[] Uset;
	Uset = nullptr;
	return 0;
}

