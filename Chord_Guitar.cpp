//Chord_Guitar.cpp
//Anh-Khoa Than
//Thomas
//Yash
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <fstream>
#include "Chord_Guitar.h"


using namespace std;

Guitar::Guitar()
{
 start_creation = false;
}

void Guitar::build_chord(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
if(start_creation == false)
{
node *n = new node;
head = n;
tail = n;
n->chord = chord;
n->string_guitar1 = string_guitar1;
n->string_guitar2 = string_guitar2;
n->string_guitar3 = string_guitar3;
n->string_guitar4 = string_guitar4;
n->string_guitar5 = string_guitar5;
n->string_guitar6 = string_guitar6;

n->next = NULL;
n->previous = NULL;
start_creation = true;
}
else if (start_creation == true)
{
node *n1 = new node;
n1->chord = chord;
n1->string_guitar1 = string_guitar1;
n1->string_guitar2 = string_guitar2;
n1->string_guitar3 = string_guitar3;
n1->string_guitar4 = string_guitar4;
n1->string_guitar5 = string_guitar5;
n1->string_guitar6 = string_guitar6;

n1->next = NULL;
n1->previous = tail;
tail->next = n1;
tail = tail->next;
if(tail->chord == "Gsharp")
{
	tail->loop = head;
	head->loop = tail;
}else
 {
	tail->loop = NULL;
 }
}
}

void Guitar::find_chord(std::string chord)
{
bool found = false;
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)
	{
		found = true;
		cout << chord << " chord has been found! Congratulations! You won!!" << endl;
		cout << tail->string_guitar1 << endl;
		cout << tail->string_guitar2 << endl;
		cout << tail->string_guitar3 << endl;
		cout << tail->string_guitar4 << endl;
		cout << tail->string_guitar5 << endl;
		cout << tail->string_guitar6 << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

	
}

void Guitar::add_chord(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
node *n = new node;
while(tail->next!=NULL)
{
	tail = tail->next;
}
node *n1 = new node;
n1->chord = chord;
n1->string_guitar1 = string_guitar1;
n1->string_guitar2 = string_guitar2;
n1->string_guitar3 = string_guitar3;
n1->string_guitar4 = string_guitar4;
n1->string_guitar5 = string_guitar5;
n1->string_guitar6 = string_guitar6;
n1->next = NULL;
n1->previous = tail;
tail->next = n1;
tail = tail->next;
cout << chord << " has been succesfull added! Press 8 to display it!" << endl;
}

void Guitar::delete_chord(string chord)
{
	bool found = false;
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)
	{
		found = true;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord!" << endl;
	}
	else
	{
		if(tail->previous == NULL)
		{
			tail = tail->next;
			delete head;
			head = tail;
			head->previous = NULL;
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
		if(tail->next == NULL)
		{
			cout <<"the test" << endl;
			node *yash = tail->previous;
			delete tail;
			yash->next = NULL;
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
		if(tail->next !=NULL && tail->previous!=NULL)
		{
			tail->previous->next = tail->next;
			tail->next->previous = tail->previous;
			delete tail;
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
	}
	
		
			
}

void Guitar::transpose_chord_up(string chord, int number_move_up)
{
	bool found = false;
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)
	{
		while(number_move_up != 0)
		{
			if(tail->chord == "Gsharp")
			{
				tail = tail->loop;
			}
			else
				{
						tail = tail->next;
				}
			
			number_move_up--;
			cout << tail->chord << endl;
		}
	
	
		found = true;
		cout << tail->chord << " chord has been found! Congratulations! You won!!" << endl;
		cout << tail->string_guitar1 << endl;
		cout << tail->string_guitar2 << endl;
		cout << tail->string_guitar3 << endl;
		cout << tail->string_guitar4 << endl;
		cout << tail->string_guitar5 << endl;
		cout << tail->string_guitar6 << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

void Guitar:: transpose_chord_down(string chord, int number_move_down)
{
bool found = false;
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)
	{
		while(number_move_down != 0)
		{
			if(tail->chord == "A")
			{
				tail = tail->loop;
			}
			else
				{
						tail = tail->previous;
				}
			
			number_move_down--;
			cout << tail->chord << endl;
		}
	
	
		found = true;
		cout << tail->chord << " chord has been found! Congratulations! You won!!" << endl;
		cout << tail->string_guitar1 << endl;
		cout << tail->string_guitar2 << endl;
		cout << tail->string_guitar3 << endl;
		cout << tail->string_guitar4 << endl;
		cout << tail->string_guitar5 << endl;
		cout << tail->string_guitar6 << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

void Guitar::change_chord(string chord, string new_chord_name, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
	bool found = false;
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)
	{
		found = true;
		tail->chord = new_chord_name;
		tail->string_guitar1 = string_guitar1;
		tail->string_guitar2 = string_guitar2;
		tail->string_guitar3 = string_guitar3;
		tail->string_guitar4 = string_guitar4;
		tail->string_guitar5 = string_guitar5;
		tail->string_guitar6 = string_guitar6;
		cout << chord << "has been successfully changed! Please enter 2 to see it!" << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

void Guitar::display_chord()
{
	if(head == NULL)
	{
		cout << "Build list first" << endl;
	}
	else
	{
	tail = head;
	while(tail->next!=NULL)
	{
		cout << tail->chord << endl;
		tail = tail->next;
	}
	cout << tail->chord << endl;
}
}

void Guitar::clear_all_chords()
{	
node*temp = head;
node*all_cleared = head;
while(all_cleared!=NULL)
{
	cout << all_cleared->chord << endl;
	all_cleared = all_cleared->next;
	delete temp;
	temp = all_cleared;
}
delete temp;
temp = NULL;
all_cleared = NULL;
head = NULL;
tail = NULL;
}

void Guitar::write_to_file()
{
	tail = head;
	ofstream outFile("test.txt");
	while(tail!=NULL){
		outFile<< tail->chord;
		outFile<< ",";
		outFile<< tail->string_guitar6;
		outFile<< ",";
		outFile<< tail->string_guitar5;
		outFile<< ",";
		outFile<< tail->string_guitar4;
		outFile<< ",";
		outFile<< tail->string_guitar3;
		outFile<< ",";
		outFile<< tail->string_guitar2;
		outFile<< ",";
		outFile<< tail->string_guitar1 << endl;
		tail=tail->next;
	}
	outFile.close();
}
