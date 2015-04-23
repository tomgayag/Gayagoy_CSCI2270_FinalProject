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

//This is the build chord function, which takes in the name of the chord, and each of the strings, as strings
void Guitar::build_chord(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
if(start_creation == false) //The boolean start_creation is initialized as false, so this statement will be true the first time that a chord is built
{
node *n = new node;		//We create a new node for the first chord, and since it is the first chord, it is set to be the head and the tail
head = n;
tail = n;
n->chord = chord;	//This string is the name of the node, (the chord name)
n->string_guitar1 = string_guitar1;		//string_guitar1 - string_guitar6 are the individual strings on the guitar for the first chord n are the placements for each string for the new chord
n->string_guitar2 = string_guitar2;
n->string_guitar3 = string_guitar3;
n->string_guitar4 = string_guitar4;
n->string_guitar5 = string_guitar5;
n->string_guitar6 = string_guitar6;

n->next = NULL;		//Since this is making the first chord, its next and previous pointers are set to be NULL
n->previous = NULL;
start_creation = true;	//The boolean start_creation is set to true since if there are already a chord (or chords) in the linked list then there will be different conditions
}
else if (start_creation == true)
{
node *n1 = new node;
n1->chord = chord;	//Again, this string is the name of the new chord
n1->string_guitar1 = string_guitar1;	//string_guitar1-string_guitar6 for the new chord n1
n1->string_guitar2 = string_guitar2;
n1->string_guitar3 = string_guitar3;
n1->string_guitar4 = string_guitar4;
n1->string_guitar5 = string_guitar5;
n1->string_guitar6 = string_guitar6;

n1->next = NULL;	//Since we are adding this chord to the end of the linked list, its next pointer is set to NULL
n1->previous = tail;	//Setting its previous pointer to tail sets it at the end
tail->next = n1;	//The old tail's next pointer is set to be the new chord
tail = tail->next;	//The tail is moved to the last node
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

//This is the find chord function, which takes in a string of the chord to be found
void Guitar::find_chord(std::string chord)
{
bool found = false;		//Initially, the boolean found is set to false
tail = head;
while(tail!=NULL)
{
	if(chord == tail->chord)	//tail is set to head, and tail goes through the linked list until the chord is found and when found, the user is notified and given the name of the chord and the positions for each string
	{
		found = true;
		cout << "| "<< tail->string_guitar6 << " - " << tail->string_guitar5 << " - " << tail->string_guitar4 << " - " << tail->string_guitar3 << " - " << tail->string_guitar2 << " - " << tail->string_guitar1 << " |" << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)			//or, if the chord is not found, the user is notified of that as well
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}


}

//This is the add chord function, which takes in the name of the chord, and each of the strings, as strings
void Guitar::add_chord(string chord, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
node *n = new node;
while(tail->next!=NULL)	//We loop through the linked list to find the tail, and set a new pointer, tail->next
{
	tail = tail->next;
}
node *n1 = new node;	//n1 is the new chord to be created
n1->chord = chord;		//n1->chord is a string which is the name of the chord
n1->string_guitar1 = string_guitar1;	//string_guitar1-string_guitar6 for the new chord
n1->string_guitar2 = string_guitar2;
n1->string_guitar3 = string_guitar3;
n1->string_guitar4 = string_guitar4;
n1->string_guitar5 = string_guitar5;
n1->string_guitar6 = string_guitar6;
n1->next = NULL;		//Add to the end of the linked list
n1->previous = tail;
tail->next = n1;
tail = tail->next;
cout << chord << " has been succesfull added! Press 8 to display it!" << endl; //Notify the user that the chord has been added
}

//This is the delete chord function, which takes in a string of the chord to be deleted
void Guitar::delete_chord(string chord)
{
	bool found = false;
tail = head;
while(tail!=NULL)	//First we find the chord to be deleted
{
	if(chord == tail->chord)	//If the chord is found, we change the bool found to be true
	{
		found = true;
		break;
	}
	tail = tail->next;
}
	if(found == false)	//If the chord isn't found, the user is notified
	{
		cout << chord << " does not exist! Please enter another chord!" << endl;
	}
	else
	{
		if(tail->previous == NULL)	//If the node to be deleted is the head (at the beginning)
		{
			tail = tail->next;	//the tail pointer is moved, head is deleted, and the new head is set and its previous pointer is set to NULL
			delete head;
			head = tail;
			head->previous = NULL;
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
		if(tail->next == NULL)	//If the node to be deleted is the tail (at the end)
		{
			cout <<"the test" << endl;
			node *yash = tail->previous;	//A new pointer is set to the previous of that node, the tail is deleted, and the previous node's next pointer is set to NULL
			delete tail;
			yash->next = NULL;
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
		if(tail->next !=NULL && tail->previous!=NULL)	//If the node to be deleted is somewhere in the middle
		{
			tail->previous->next = tail->next;		//The next pointer of the node previous to the tail is set to be the next value of the original tail
			tail->next->previous = tail->previous;	//The previous pointer of the node next to the tail is set to be the previous value of the original tail
			delete tail;							//The tail is deleted
			cout << chord << " has been removed! Press 8 to display new list of chords!" << endl;
		}
	}
}

//This is the transpose up function, which takes in the chord as a string and the number to traspose up as an int
void Guitar::transpose_chord_up(string chord, int number_move_up)
{
	bool found = false;
tail = head;
while(tail!=NULL)	//loop through the chord
{
	if(chord == tail->chord)	//If the chord is found
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

		//Once chord has been transposed, it is diplayed to the user
		found = true;
		cout << tail->chord << " chord has been found! Congratulations! You won!!" << endl;
        cout << "| "<< tail->string_guitar6 << " - " << tail->string_guitar5 << " - " << tail->string_guitar4 << " - " << tail->string_guitar3 << " - " << tail->string_guitar2 << " - " << tail->string_guitar1 << " |" << endl;
		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

//This is the transpose down function, which takes in the chord as a string and the number to traspose up down an int
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

		//Once the chord has been transposed down, it is displayed to the user
		found = true;
		cout << tail->chord << " chord has been found! Congratulations! You won!!" << endl;
		cout << "| "<< tail->string_guitar6 << " - " << tail->string_guitar5 << " - " << tail->string_guitar4 << " - " << tail->string_guitar3 << " - " << tail->string_guitar2 << " - " << tail->string_guitar1 << " |" << endl;

		break;
	}
	tail = tail->next;
}
	if(found == false)
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

//The change chord function allows the user to edit an already created chord
void Guitar::change_chord(string chord, string new_chord_name, string string_guitar1, string string_guitar2, string string_guitar3, string string_guitar4, string string_guitar5, string string_guitar6)
{
	bool found = false;
tail = head;
while(tail!=NULL)	//loops through chord
{
	if(chord == tail->chord)	//once found, the chord's name is changed
	{
		found = true;
		tail->chord = new_chord_name;			//The only property changed is the chord name, while the strings themselves remain the same
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
	if(found == false)	//Or, complains to the user if the chord is not found
	{
		cout << chord << " does not exist! Please enter another chord to find!" << endl;
	}

}

//The display chord function outputs the chord
void Guitar::display_chord()
{
	if(head == NULL)
	{
		cout << "Build list first" << endl; // If the chord is empty, the user is notified to build first
	}
	else
	{
	tail = head;
	while(tail->next!=NULL)			//Or if it is not empty, loop through the chord
	{
		cout << tail->chord << endl;
		tail = tail->next;
	}
	cout << tail->chord << endl; //And prints it out
}
}

//The clear all chords function removes all chords
void Guitar::clear_all_chords()
{
node*temp = head;
node*all_cleared = head;	//2 new nodes are created, temp and all_cleared, which are initialized to the head
while(all_cleared!=NULL)	//While all_cleared does not reach the end
{
	cout << all_cleared->chord << endl;	//print out the chord
	all_cleared = all_cleared->next;	//move all_cleared
	delete temp;					//delete the head
	temp = all_cleared;				//move the head
}
delete temp;		//delete the head
temp = NULL;		//re-define all to be NULL
all_cleared = NULL;
head = NULL;
tail = NULL;
}

//This funciton outputs the chord to a text file
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

//Selecting this option tells the user what each different option does
void Guitar::help(string select){
    if(select == "1"){
        cout <<"- This option builds a list from the text file run with the program"<<endl;
        return;
    }
    if(select == "2"){
       cout << "- This option finds a chord and displays the chord structure" << endl;
        return;
    }
    if(select == "3"){
        cout << "- This option allows you to add a chord that you created to the end of the list" << endl;
        return;
    }
    if(select == "4"){
        cout << "- This option allows you to delete a chord you added" << endl;
        return;
    }
    if(select == "5"){
        cout << "- This option transposes a chord you select up by how many half-steps you select" << endl;
        return;
    }
    if(select == "6"){
        cout << "- This option transposes a chord you select down by how many half-steps you select" << endl;
        return;
    }
    if(select == "7"){
        cout << "- This option allows you to change a chord that you added" << endl;
        return;
    }
    if(select == "8"){
        cout << "- This option displays the current list of chords" << endl;
        return;
    }
    if(select == "9"){
        cout << "- This option clears the current list of chords" << endl;
        return;
    }
    if(select == "10"){
        cout << "- This option saves the current list of chords into a text file and exits the program" << endl;
        return;
    }
    if(select == "12"){
        cout << "- This option exits the program without saving any changes" << endl;
        return;
    }
    if(select == "11"){
        cout << "- This is just the help option" << endl;
        return;
    }
    else{
        cout << "Invalid Option" << endl;
    }
}
