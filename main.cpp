#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

void PrintQueue(queue<int> inputQueue, char* numDays){
	int days = atoi(numDays);
	//cout << days << endl;
	for(int i = 0; i < days; i++){
		cout << inputQueue.front() << ",";
		inputQueue.pop();
	}
	cout << endl;
}

int ComputeAverage(queue<int> inputQueue, char* numDays){
	int average, sum(0);
	int days = atoi(numDays);

	for(int i = 0; i < days; i++){
		sum += inputQueue.front();
		inputQueue.pop();
	}
	average = sum / days;

	cout << "Average " << average << endl;
	return 0;
}

int main(int arg0, char* arg[]) {
  ifstream fin;
	queue<int> casesQueue;
	int cases;
	int numDays = atoi(arg[2]);
	
	cout << "Using Data from " << arg[1] << " with a " << arg[2] << " day rolling average" << endl;
	
	/*
	cout << "You are accessing the file " << arg[1] << endl;
	cout << "You have input " << arg[2] << endl;
	*/
	
	fin.open("cases.txt");
	while(fin >> cases) {
			casesQueue.push(cases);
	}

	while(casesQueue.size() >= numDays) {
		//cout << casesQueue.size() << endl;
		PrintQueue(casesQueue, arg[2]);
		ComputeAverage(casesQueue, arg[2]);
		casesQueue.pop();
	}
	//cout << casesQueue.size() << endl;
	fin.close();
	return 0;
}