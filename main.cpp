//Author: Stefan Grosser
//Date: 9/21/2016
/*
Written for CS590D Algorithms for Data Science during the Fall 2016 semester.
Given the number of experiments, this program will run reservoir sampling
and output the statistics for each number.

It can be observed that errors of 10% occur around 20000, exhibiting near-uniform
sampling as the experiment size increases.
*/


#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int reservoirSampling()
{
	ifstream in("reservoir");
	
	int count = 0;
	int num = 0, randomCheck = 0;
	int res;
	while(in >> num)
	{
		count++;
		randomCheck = rand() % count + 1;
		if(randomCheck == count)
		{
			res = num;
		}
	}
	
	return res;
}

int main()
{
	srand(time(0));
	map<int, int> reservoirCount;
	
	int EXPERIMENT_SIZE;
	cout << "Number of experiments? " << endl;
	cin >> EXPERIMENT_SIZE;

	for(int i = 1; i<=100; i++)
	{
		reservoirCount[i] = 0;
	}
	for(int i = 0; i<EXPERIMENT_SIZE; i++)
	{
		reservoirCount[reservoirSampling()]+=1;
	}
	
	for(int i = 1; i <= 100; i++ )
	{
		cout << i << " -> " << reservoirCount[i] << endl;
	}
}
