// MahGeneticAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	
	const int mxChoromosomesSize = 7;
	const int mxPop = 10;
	const int mxWeight = 15;	
	const int mxProfit = 18;
	const int mxLoop = 1;
	
	int weight[mxChoromosomesSize] = { 7, 5, 3, 1, 5, 9, 8 };
	int profit[mxChoromosomesSize] = { 2, 9, 8, 5, 4, 1, 2 };
	int chromosome[mxPop][mxChoromosomesSize];


	//STEP 1: randomly generate population
	for (int i = 0; i < mxPop; i++){		
		for (int j = 0; j < mxChoromosomesSize; j++){
			chromosome[i][j] = rand() % 2;
			cout << chromosome[i][j];
		}	
		cout << "\n";
	}

	//STEP 2: calcualte fitness AND get the best fitness
	cout << "get the fitness score:\n";

	int iBestProfitSoFar = 0;
	int iBestIdx = -1;

	for (int i = 0; i < mxPop; i++){
		int iTtlProfit = 0;
		int iTtlWeight = 0;
		for (int j = 0; j < mxChoromosomesSize; j++){
			if (chromosome[i][j] == 1){
				iTtlProfit += profit[j];
				iTtlWeight += weight[j];
			}		
		}

		if (iTtlWeight <= mxWeight){
			if (iTtlProfit>iBestProfitSoFar){
				iBestProfitSoFar = iTtlProfit;
				iBestIdx = i;
			}
		}
		
	}

	
	cout << "best profit first round - " << iBestProfitSoFar << endl;	
	for (int j = 0; j < mxChoromosomesSize; j++){
			cout << chromosome[iBestIdx][j];
	}
	cout << endl;
	
	//STEP 3: if we found the best for first round
	if (iBestProfitSoFar>mxProfit){
		cout << "found solution on first random population..." << endl;
		return 0;

	}

	//STEP 4: keep top candidate (iBestIdx), and generate and crossover two new population from previous (random or using roulette)
	for (int i = 0; i < mxPop; i++){
		for (int j = 0; j < mxChoromosomesSize; j++){
			
		}
		
	}

	
	getchar();
	return 0;
}

