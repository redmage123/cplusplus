// LabOne.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	ifstream myFile;
	//FILE * fp;
	//string camis;
//	string record;
	//char record[8192];

	struct all_rest{
		string camis;
		string dba;
		string boro;
		string building;
		string street;
		string zipcode;
		string phone;
		string cusinedes;
		string inspection;
		string action;
		string violationcode;
		string violationdes;
		string criticalflag;
		string score;
		string grade;
		string gradedate;
		string recorddate;
		string inspectiontype;
	};

	struct all_rest* ar = new all_rest[200];

	int i =0;
	
	myFile.open("New_York_City_Restaurant.csv");
	
	
	//testing to see if the file actually openend
	
	if (myFile.is_open())
	{
		
		while(!myFile.eof())
		{
			printf("We're in the main while loop\n");
			if (i ==0) {
		 	  i++;
			   continue;
			}
		
		
			
			getline(myFile,ar[i].camis,',');	
			getline(myFile,ar[i].dba,',');
			getline(myFile,ar[i].boro,',');
			getline(myFile,ar[i].building,',');
			getline(myFile,ar[i].street,','); 
			getline(myFile,ar[i].zipcode,','); 
			getline(myFile,ar[i].phone,',');
			getline(myFile,ar[i].cusinedes,',');
			getline(myFile,ar[i].inspection,',');
			getline(myFile,ar[i].action,','); 
			getline(myFile,ar[i].violationcode,',');
			getline(myFile,ar[i].violationdes,',');
			getline(myFile,ar[i].criticalflag,','); 
			getline(myFile,ar[i].score,','); 
			getline(myFile,ar[i].grade,','); 
			getline(myFile,ar[i].gradedate,','); 
			getline(myFile,ar[i].recorddate,',');
			getline(myFile,ar[i].inspectiontype); 
			i++;
			cout<< i <<endl;
		}
		for(int z= 0; z<200; z++)
		{
			cout <<ar[z].camis <<endl;
		}

	}
}
