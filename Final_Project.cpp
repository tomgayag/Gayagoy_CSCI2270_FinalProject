//Final_Project.cpp
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
#include <string>
#include <sstream>
#include "Chord_Guitar.h"
using namespace std;

int main(int argc, char *argv[])
{
	Guitar *the_guitar = new Guitar();
	 ifstream myfile(argv[1]);
	 string list_of_chords;
	 string chord ;
     string string_guitar1;
     string string_guitar2;
     string string_guitar3;
     string string_guitar4;
     string string_guitar5;
     string string_guitar6;
    

	int lets_play_guitar;
	bool Quit = false;
	while (Quit!=true)
	{
	    cout << "======Main Menu=====" << endl;
		cout << "Chord Creation" << endl;
		cout << "Find Chord" << endl;
		cout << "Add Chord" << endl;
		cout << "Delete Chord" << endl;
		cout << "Tranpose Chord Up" << endl;
		cout << "Transpose Chord Down" << endl;
		cout << "Change Chord" << endl;
		cout << "Display Chord" << endl;
		cout << "Write To File" << endl;
		cout << "Save Changes" << endl;
		cout << "Quit" << endl;
		cin >> lets_play_guitar;;
		cin.clear();
		cin.ignore(10000, '\n');

		switch(lets_play_guitar)
		{
        case 1:
        {
			cout << "Let's create the guitar chords so we can begin the lesson!" << endl;
			while (getline (myfile, list_of_chords))
    {
        stringstream ss(list_of_chords);
       
        getline(ss, chord, ',');
        getline(ss, string_guitar1, ',');
        getline(ss, string_guitar2, ',');
        getline(ss, string_guitar3, ',');
        getline(ss, string_guitar4, ',');
        getline(ss, string_guitar5, ',');
        getline(ss, string_guitar6, ','); 
        cout << "------------" << endl;
        cout << chord << endl;
        cout << string_guitar1 << endl;
        cout << string_guitar2 << endl;
        cout << string_guitar3 << endl;
        cout << string_guitar4 << endl;
        cout << string_guitar5 << endl;
        cout << string_guitar6 << endl;
        the_guitar->chord_creation(chord,string_guitar1, string_guitar2,string_guitar3,string_guitar4,string_guitar5, string_guitar6);
		}
			break;
		}
        case 2:
        {
			cout << "Let's find the chord" << endl;
			break;
		}
        case 3:
        {
			string node_to_add;
			cout << "Let's add the chord" << endl;
			cout << "Enter chord to add" << endl;
			getline(cin,node_to_add);
			the_guitar->add_chord(node_to_add,string_guitar1, string_guitar2,string_guitar3,string_guitar4,string_guitar5, string_guitar6);
			break;
		}
        case 4:
        {
			string node_to_delete;
			cout << "Enter chord to delete" << endl;
			getline(cin, node_to_delete);
            cout << "Let's delete the chord" << endl;
            the_guitar->delete_chord(node_to_delete);
            break;
		}
        case 5:
        {
			cout << "Let's tranpose the chord up" << endl;
			break;
		}
		case 6:
		{
			cout << "Let's tranpose the chord down" << endl;
			break;
		}
		case 7:
		{
			cout << "Let's change the chord" << endl;
			break;
		}
		case 8:
		{
			cout << "Display all chords" << endl;
			the_guitar->display_chord();
			break;
		}
		case 9:
		{
			cout << "Write to file" << endl;
			break;
		}
		case 10:
		{
			cout << "Save changes" << endl;
			break;
		}
		case 11:
		{
			Quit = true;
			cout << "This is the end of the guitar lesson" << endl;
			break;
		}
		}
	}

    return 0;
}



