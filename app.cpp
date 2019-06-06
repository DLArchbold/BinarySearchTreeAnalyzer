/*Below are the reference links to code and algorithms that have aided me very much in 
completing this assignment. Credits due to them where applicable.
Reference links: 
1) http://www.cplusplus.com/reference/string/string/length/
2) https://stackoverflow.com/questions/19967134/bst-find-height-recursivly
3) https://www.geeksforgeeks.org/find-deepest-node-binary-tree/
4) http://www.cplusplus.com/forum/beginner/25408/
*/



#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"
#include	<string>
//type = student
//type2 = BTNode *
using namespace std;

bool readFile(char *, BST *);
int i = 0;
int LHeight, Rheight;
int choice = 0;
int order;
int source;

int menu();

int main() {


	BST t1;
	BST t2;


	char filename[30];


	menu();


while (choice != 7)
{
		while (choice == 1)
		{
			char filename[30];
			cout << "Please enter filename to read file from: \n";
			cin >> filename;
			if (readFile(filename, &t1) == false)
			{
				cout << "File doesn't exist.\n\n" << endl;
			}
			choice = menu();
		}

		while (choice == 2)
		{
			if (t1.deepestNodes() == false)
			{
				cout << "\nEmpty tree, could not find deepest nodes.\n";
			}

			choice = menu();
		}


		while (choice == 3)
		{

			cout << "\nPlease enter order (1 for asending, 2 for descending)";
			cin >> order;
			cout <<"\nPlease enter source (1 to print to screen, 2 to 'student-info.txt' file.";
			cin >> source;


			if (t1.display(order, source) == false)
			{
				cout << "\nEmpty tree, could not display\n";
			}




			choice = menu();

		
		}


		while (choice == 4)
		{
			Student Std;
			cout << "\nPlease enter the student ID of cloned subtree root:";
			cout << "\n(t1 and t2 will be printed using pre-order processing.)";
			cin >> Std.id;
			t2.root = NULL;



			if (t2.CloneSubtree(t1, Std) == false)
			{
				cout << "\nThe tree to clone from is empty.\n";

			}
			else {
				cout << "***********START of t1**************\n";
				t1.preOrderPrint();
				cout << "\n***********END of t1**************\n";
				cout << "***********START of t2**************\n";
				t2.preOrderPrint();
				cout << "***********END of t2**************\n";
			}

		
			choice = menu();
		}


		while (choice == 5)
		{
			Student Std;
			cout << "\nPlease enter the student ID to get ancestor of that node.";
			cin >> Std.id;



			if (t1.printAncestor(Std) == false)
			{
				cout << "\nEither he tree to print any ancestor from is empty, or node to ";
					 cout << "print ";
					cout << "ancestors of could not be found.\n";

			}

			choice = menu();
		}



		while (choice == 6)
		{
			if (t1.printSpiral() == false)
			{
				cout << "\nEmpty tree, could not print all nodes in spiral order.\n";
			}

			choice = menu();
		}








	
}






	system("pause");
	return 0;
}

bool readFile(char *filename, BST *t1)
{

	ifstream StudentIn;
	StudentIn.open(filename);
	if (StudentIn.fail())
	{
		return false;
	}

	


	char StoreVal[100];
	int ReadNo = 0;
	string StrStr1;
	int namelength;
	while (true)
	{




		if (StudentIn.eof())
		{
			break;
		}

		Student StoreStd;
		//----------------------ID

		for (i = 0; i < 3; i++)
		{
			StudentIn >> StoreVal;
		}

		//StStoreVal = StoreVal;
		StoreStd.id = stoi(StoreVal);

		//cout << StoreStd.id << endl;
		
		








		//----------------------Name
		for (i = 0; i < 2; i++)
		{
			StudentIn >> StoreVal;
		}

		getline(StudentIn, StrStr1);

		for (i = 0; i < StrStr1.length(); i++) //Copy from string to c-string
		{
			StoreVal[i] = StrStr1[i + 1];
		}

	
		for (i = 0; i < (100-StrStr1.length()); i++) //Set rest to null
		{
			StoreVal[StrStr1.length() + i] = NULL;
		}

		strcpy(StoreStd.name, StoreVal);
		//cout << StoreStd.name << endl;






		//----------------------Addresss
		for (i = 0; i < 2; i++)
		{
			StudentIn >> StoreVal;
		}
		getline(StudentIn, StrStr1);

		
		
		
		//cout << StrStr1;


		int length = StrStr1.length();
		//StrStr1.substr(11, 100);
		
		for (i = 0; i < length; i++) //Copy from string to c-string
		{
			StoreVal[i] = StrStr1[i+1];
		}

	

		namelength = strlen(StoreVal);

		for (i = 0; i < (100 - namelength); i++) //Set rest to null
		{
			StoreVal[namelength + i] = NULL;
		}

		strcpy(StoreStd.address, StoreVal);
		
		//cout << StoreStd.address << endl;
		
		
		
		
		
		//------------------DOB

		for (i = 0; i < 3; i++)
		{
			StudentIn >> StoreVal;
		}
		namelength = strlen(StoreVal);

		for (i = 0; i < (100 - namelength); i++) //Set rest to null
		{
			StoreVal[namelength + i] = NULL;
		}

		strcpy(StoreStd.DOB, StoreVal);
		//cout << StoreStd.DOB << endl;
		
		
		
		
		
		//------------------PhoneNumber

		for (i = 0; i < 3; i++)
		{
			StudentIn >> StoreVal;
		}
		namelength = strlen(StoreVal);

		for (i = 0; i < (100 - namelength); i++) //Set rest to null
		{
			StoreVal[namelength + i] = NULL;
		}

		strcpy(StoreStd.phone_no, StoreVal);

		//cout << StoreStd.phone_no << endl;
		
		
		
		
		
		
		//------------------Course

		for (i = 0; i < 3; i++)
		{
			StudentIn >> StoreVal;
		}
		namelength = strlen(StoreVal);

		for (i = 0; i < (100 - namelength); i++) //Set rest to null
		{
			StoreVal[namelength + i] = NULL;
		}

		strcpy(StoreStd.course, StoreVal);




		//cout << StoreStd.course << endl;
		
		
		
		
		
		
		
		//----------------------CGPA
		for (i = 0; i < 3; i++)
		{
			StudentIn >> StoreVal;
		}
		namelength = strlen(StoreVal);

		for (i = 0; i < (100 - namelength); i++) //Set rest to null
		{
			StoreVal[namelength + i] = NULL;
		}

		double cgpa = atof(StoreVal);
		StoreStd.cgpa = cgpa;

		//cout << StoreStd.cgpa << endl;














		//break;
		




		ReadNo++;
		(*t1).insert(StoreStd);

	}



	cout << "Number of student records successfully read: " << ReadNo << endl;


	//(*t1).inOrderPrint();



	StudentIn.close();


	return true;
}

int menu()
{
	
	cout << "\n\n(1) Read data to BST" << endl;
	cout << "(2) Print deepest nodes" << endl;
	cout << "(3) Display student" << endl;
	cout << "(4) Clone subtree" << endl;
	cout << "(5) Print Ancestor" << endl;
	cout << "(6) Print Spiral" << endl;
	cout << "(7) Exit" << endl;
	cout << "\nPlease enter 1-7 to perform functions.\n";
	
	cin >> choice;
	return choice;


}