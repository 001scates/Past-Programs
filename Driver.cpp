//Name: Terry Scates
//Email: tscates2012@my.fit.edu
//Purpose: To implement linked list class
//		   by reading in a list of music
//		   and putting it in the linked list
//Algorithm:
//		Declare a linked list head node
//		Ask user for number of tracks they want to input
//		Ask user to input data for each track
//		Create each track as a new node and add it to a list
//		Show front of unsorted list 
//		Sort list
//		Show end of sorted list
//		Show sorted list
//		Ask user what they would want to filter music by
//		Read user input for Artist or Genre
//		filter list to show only desired tracks

#include "LinkedListClass.h"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

Node *makeNode(Node *n); //will read in music tracks and put them in Node format

int main()
{
	LinkedList list;
	int tracks = 0; //will be number of tracks user will input;

	cout << "Enter number of tracks to put in the catalog: ";
	cin >> tracks;
	cin.ignore();
	
	for (int i = 0; i < tracks; i++)
	{
		list.append(makeNode(new Node)); //should continue to add new nodes
	}


	cout << "Front of list" << endl;
	list.front();

	cout << "Sorting list" << endl;
	list.sort();

	cout << "back of list" << endl;
	list.back();

	cout << "Display entire list" << endl;
	list.display();

	string input;
	string type;

	cout << "What would you like to filter: Artist or Genre " << endl;

	cin >> input;
	cin.ignore();
	if (input == "Artist")
	{
		cout << "Enter Artist name you want: " << endl;
		getline(cin, type);
		cout << "Here is the list: " << endl;
		list.filter(input, type);
	}
	else if(input == "Genre")
	{ 
		cout << "Enter Genre you want: " << endl;
		getline(cin, type);
		cout << "Here is the list: " << endl;
		list.filter(input, type);
	}
	else
	
	{
		cout << "Error not an option: Enter an Artist or Genre" << endl;
		while ((input != "Artist") || (input != "Genre"))
		{
			getline(cin, input);
		}
		cout << "Enter Genre you want or Artist you want: ";
		getline(cin, type);
		cout << "Here is the list: " << endl;
		list.filter(input, type);
	}

	list.empty();

	return 0;

}

Node* makeNode(Node *n)
{
	n = new Node;
	string readIn;
	cout << "Enter information for a track" << endl;
	
	cout << "Artist: ";
	getline(cin, readIn);
	n->Artist = readIn;

	cout << "Song Title: ";
	getline(cin, readIn);
	n->SongTitle = readIn;

	cout << "Release date: ";
	getline(cin, readIn);
	n->ReleaseDate = readIn;

	cout << "Genre: ";
	getline(cin, readIn);
	n->Genre = readIn;

	cout << "Duration: ";
	getline(cin, readIn);
	n->Duration = readIn;

	n->next = nullptr;

	return n;
}