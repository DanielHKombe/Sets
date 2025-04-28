#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Set
{
	vector<vector<int>>ASets;
	vector<string>sets;
	vector<int>ISec;
	vector<int>USec;
	int* USet, size;

public:
	Set(vector<vector<int>>TSets, vector<string>names, const int Uarry[], int Usize);

	Set(const Set& obj);

	~Set();

	void getInSec(vector<int>isec)
	{
		ISec = isec;
	}

	void getUnSec(vector<int>usec)
	{
		USec = usec;
	}

	void printASets();
	void printSetD(vector<vector<int>>SetD);

	void printSetC(vector<vector<int>>SetC);

	void printSet(vector<int>Uset);

	vector<int> ISet();
	bool numCheck(int num);
	vector<int> uSet();
	bool InumCheck(int num, vector<int>Usec);

	vector<vector<int>> setDifference();

	vector<vector<int>> setComplement();
};

