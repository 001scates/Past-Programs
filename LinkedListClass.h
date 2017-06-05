//Name: Terry Scates
//Email: tscates2012@my.fit.edu
//Purpose: To create a linked list for 
//	       creating a music catalog to
//		   be used in driver program
//Algorithm:
//			Under functions def
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Node
{
	string Artist;		//Accepts any string won't check if they are numbers or letters -__-
	string SongTitle;
	string ReleaseDate;
	string Genre;
	string Duration;
	Node *next;
};

class LinkedList
{
	private:
		Node *head;

	public:
		LinkedList()
		{
			head = nullptr;
		
		}
		
		~LinkedList()
		{
			delete head;
		}

		Node *getHead()
		{
			return head;
		}

		void front();
		void back();
		bool empty();
		int size();
		void append(Node *n);
		void remove(int x); //removes element in position x from 1 to the size;
		void insert(Node *n);
		void sort(); //will return a sorted version of the linked list by song name
		void display();
		void filter(string s, string t); //s will be based on what the person wants to sort by
		bool comesBefore(Node *newNode, Node *current); //will compare data for nodes to sort them in music list
		bool inList(Node* n);
};

#endif // !LINKEDLIST_H

