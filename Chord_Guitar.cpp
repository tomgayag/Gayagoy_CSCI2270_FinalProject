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

void Guitar::chord_creation(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
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
}
}

void Guitar::find_chord(std::string chord)
{

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
		cout <<"Chord does not exist" << endl;
	}
	else
	{
		if(tail->previous == NULL)
		{
			tail = tail->next;
			delete head;
			head = tail;
			head->previous = NULL;
		}
		if(tail->next == NULL)
		{
			cout <<"the test" << endl;
			node *yash = tail->previous;
			delete tail;
			yash->next = NULL;
		}
		if(tail->next !=NULL && tail->previous!=NULL)
		{
			tail->previous->next = tail->next;
			tail->next->previous = tail->previous;
			delete tail;
		}
	}
	
		
			
}
        
void Guitar::transpose_chord_up(string chord)
{

}

void Guitar:: transpose_chord_down(string chord)
{

}

void Guitar::change_chord(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{

}

void Guitar::display_chord()
{
	tail = head;
	cout << "test" << endl;
	while(tail->next!=NULL)
	{
		cout << tail->chord << endl;
		tail = tail->next;
	}
	cout << tail->chord << endl;
}

void Guitar::write_to_file()
{

}
