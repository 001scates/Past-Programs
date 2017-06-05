//Name: Terry Scates
//Email: tscates2012@my.fit.edu
//Purpose:
// To collect data from files and generate a summary report.
// Then store the summary in a file.  
//Algorithm:
//	Open category file
//	Read all categories and store them in array of strings
//each having a value from the file
//	For each category, add the expenses in array as well
//	have pointer array point to category and their expenses
//	close the category file
//	Point all pointers to group of expenses
//	Open expense file
//	Read each line and separate expenses from date
//	create array to store only values that were next to each expense
//	Start at first category in array of categories
//	Check if any name in expense array had matched with contents in category
//	create an array of totals for each category
//	Add all expenses that matched to the total array for categories
//	Go to next category and do the same
//	

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

string getExpense(string); //takes line read from expenses and gets the expense
double getCost(string); //takes line read from expenses and gets the costs
int main()
{
	const int MAX_CATEGORY = 12;
	ifstream categoryFile;
	categoryFile.open("Categories.txt");
	string currentCategory = " ";
	string *allCategories[MAX_CATEGORY]; //array of 12 pointers that will point to array of strings
	string CategoryNames[MAX_CATEGORY][100]; //array will hold expenses for each category 
	int numberExp[12]; //array of 12 numbers that are the number of expenses for each category
	int i = 0, x = 0; //i is the current category index, x is the count of the expenses
	getline(categoryFile, currentCategory);
	while (!categoryFile.eof())
	{
		CategoryNames[i][0] = currentCategory;//if not tabbed line then it is a main category not an expense
		getline(categoryFile, currentCategory);
		if (currentCategory[0] == '\t')
		{
			while (currentCategory[0] == '\t')
			{
				x++;
				CategoryNames[i][x] = currentCategory; //formats 2d array with category and all expenses in separate indexes
				getline(categoryFile, currentCategory); //gets the rest of expenses 
			}
			numberExp[i] = x; //array containing number of expenses to be used for lengths of arrays
			allCategories[i] = CategoryNames[i];
		}
		x = 0;
		i++;
	}
	cout << "Done with file" << endl;
	categoryFile.close(); 

	ifstream expenseFile;
	expenseFile.open("Expenditures_1.txt");
	double totalCosts[MAX_CATEGORY];
	string expenseLine,currentExpense;
	double cost;
	
	while (!expenseFile.eof())
	{
		getline(expenseFile, expenseLine);
		currentExpense = getExpense(expenseLine);
		cost = getCost(expenseLine);
		for (i = 0; i < MAX_CATEGORY; i++)
		{
			x = numberExp[i]; //gets the number of expenses for each category so j doesnt go through all 100 items
			for (int j = 1; j < x; j++)
			{
				string isMatch = allCategories[i][j];
				if (currentExpense == isMatch)
				{
					totalCosts[i] += cost; //only adds cost if expense matches and skips
				}
			}
		}
	}
	
	return 0;
}

string getExpense(string s)
{
	string output = "";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\t' || s[i] == ' ') 
		{
			output += s[i]; //will always start after date
			i++;
			while (s[i] != '\t' && s[i] != ' ')
			{

				output += s[i];  //will add each character after the tab or space after the date
				i++; //until the next tab or space
				if (s[i] == ' ' && (isalpha(s[i + 1]) || s[i + 1] == '&'))
				{
					output += s[i];
					i++;
				}
			}
			return output; //output will already have the value of the expense
		}
	}
	return "no expense";
}

double getCost(string s)
{
	string output = "";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\t' || s[i] == ' ')
		{
			i++;
			while (s[i] != '\t' && s[i] !=  ' ')
			{
				if (isalpha(s[i + 2]) || s[i + 2] == '&')
				{
					i++;
				}
				i++; // do nothing 
			}
			i++; //start at value after tab or space
			while (i < s.length())
			{
				output += s[i];	 //will add each character after the tab or space after the expense
				i++;
			}
		}
	}
	return stod(output);

}
