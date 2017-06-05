#include "LinkedListClass.h"

bool LinkedList::inList(Node *n)
{
	Node *temp = head;
	while (temp->next)
	{
		if (n->SongTitle == temp->SongTitle)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void LinkedList::front()
{
	cout << head->Artist << endl;
	cout << head->SongTitle << endl;
	cout << head->ReleaseDate << endl;
	cout << head->Genre << endl;
	cout << head->Duration << endl;
	cout << "-------------------" << endl;
}

void LinkedList::back()
{
	Node *temp = head;
	while (temp->next)
	{
		temp = temp->next; //will go until temp has no next node
	}
	cout << temp->Artist << endl;
	cout << temp->SongTitle << endl;
	cout << temp->ReleaseDate << endl;
	cout << temp->Genre << endl;
	cout << temp->Duration << endl;
	cout << "-------------------" << endl;
}

bool LinkedList::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

int LinkedList::size()
{
	int count = 0;
	Node *temp = head;
	if (head == nullptr)
	{
		return count;
	}
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	count++;
	return count;
}

void LinkedList::append(Node *n)
{
	//node should already have been made
	Node *temp = nullptr;
	if (!head)
	{
		head = n;
	}
	else {
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
}

void LinkedList::remove(int x)
{
	Node *temp = nullptr;
	Node *prev = nullptr;
	int count = 1;
	if (x == 0)
	{
		cout << "Error start with 1: Enter desired track to remove";
		cin >> x;
	}
	else if (!head)
	{
		cout << "Error list is already empty";
	}
	else if (x == 1)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	else if (x == size())
	{
		temp = head;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = nullptr;
	}
	else {
		temp = head;
		for (int i = 1; i < x; i++)
		{
			prev = temp;
			temp = temp->next;
			
		}
		if (temp)
		{
			prev->next = temp->next; //node before deleted element will point to node after deleted element
			delete temp;
		}
	}
}

void LinkedList::insert(Node *n)
{
	Node *temp = nullptr;
	Node *prev = nullptr;

	if (!head)
	{
		head = n;
		n->next;
	}
	else {
		temp = head;
		while (temp != nullptr && !(comesBefore(n, temp)))
		{
			prev = temp;
			temp = temp->next;
		}

		if (prev == nullptr)
		{
			head = n;
			n->next = temp;
		}
		else {
			prev->next = n;
			n->next = temp;
		}
	}
}

void LinkedList::sort()
{
//Algorithm:
//			Set temp to current linked list
//			traverse through list and swap node if next node is lower
	//			-point prev node to the lower value
	//			-set head of prev node to point to higher value
//			check if head node is higher value and if so then swap with head node
//			continue through list until lowest values are in the beginning
//			continue until list has been searched
	Node *temp = nullptr;
	Node *prev = nullptr;
	if (!head)
	{
		cout << "Error no list to sort";
	
	}
	else {
		for (bool swap = true; swap;)
		{
			swap = false;
			prev = head;

			for (temp = head; temp->next != nullptr;)
			{
				if (!comesBefore(temp, temp->next))
				{
					if (head == temp)
					{
						head = temp->next;
						temp->next = head->next;
						head->next = temp;
						prev = head;
					}
					else
					{
						prev->next = temp->next; //
						temp->next = prev->next->next;
						prev->next->next = temp;
						temp = head;
					}

					swap = true;
				}
				else if (head != temp)
				{
					prev = prev->next;
					temp = temp->next;
				}
			    else if (!comesBefore(prev, temp))
				{
					//go back and traverse if not fully sorted
					prev = head;
				}
				else {
					temp = temp->next;
				}
			
			}
		}
	
	}

}

void LinkedList::display()
{
	int x = size();
	Node *temp = nullptr;

	if (!head)
	{
		cout << "Error empty list";
	}
	else {
		temp = head;
		for (int i = 0; i < x; i++)
		{
			cout << "Track " << i + 1 << endl;
			cout << temp->Artist << endl;
			cout << temp->SongTitle << endl;
			cout << temp->ReleaseDate << endl;
			cout << temp->Genre << endl;
			cout << temp->Duration << endl;
			cout << "--------------" << endl;
			temp = temp->next;
		}
	}
}

void LinkedList::filter(string s, string t)
//Algorithm:
//			Search for a node containing desired data
//			output node containing same data
//			continue to output nodes until similar until all nodes are listed			
//
{
	Node *temp = nullptr;
	int x = 0, y = size();
	if (s == "Artist")
	{
		temp = head;
		while (temp != nullptr)
		{
			if (temp->Artist == t)
			{
				x++; //keeps count of how many nodes are matched until end of traversing
				cout << temp->Artist << endl;
				cout << temp->SongTitle << endl;
				cout << temp->Genre << endl; 
				cout << temp->ReleaseDate << endl;
				cout << temp->Duration << endl; 
				cout << "----------------" << endl;
			}
			temp = temp->next;
		}
	}
	else if (s == "Genre")
	{
		temp = head;
		while (temp != nullptr)
		{
			if (temp->Genre == t)
			{
				x++; 
				cout << temp->Artist << endl;
				cout << temp->SongTitle << endl;
				cout << temp->Genre << endl;
				cout << temp->ReleaseDate << endl;
				cout << temp->Duration << endl;
				cout << "----------------" << endl;

			}
			temp = temp->next;
		}
	}
}

bool LinkedList::comesBefore(Node *current, Node *newNode)
{
	if (newNode == nullptr || current == nullptr)
	{
		return true;
	}
	if (newNode->SongTitle < current->SongTitle)
	{
		return false;
	}
	return true;
}