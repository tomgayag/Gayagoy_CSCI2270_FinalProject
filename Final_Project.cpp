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
	cout << "               Welcome to our Chord Book!!!" << endl;
	while (Quit!=true)
	{
	    //cout << "======Main Menu=====" << endl;
	    cout << "  Please Select an Option:" << endl;
		cout << "1.) Build List of Chords " << endl;
		cout << "2.) Find a Chord" << endl;
		cout << "3.) Add a Chord" << endl;
		cout << "4.) Delete a Chord" << endl;
		cout << "5.) Transpose a Chord Up" << endl;
		cout << "6.) Transpose a Chord Down" << endl;
		cout << "7.) Change a Chord" << endl;
		cout << "8.) Display Chord List" << endl;
		cout << "9.) Clear all Chords" << endl;
		cout << "10.) Save And Quit" << endl;
		cout << "11.) Help" << endl;
		cout << "12.) Exit the Program" << endl;
		cin >> lets_play_guitar;;
		cin.clear();
		cin.ignore(10000, '\n');

		switch(lets_play_guitar)
		{
        case 1:
        {
			cout << "Creating a list..." << endl;
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
        //cout << "------------" << endl;
        //cout << chord << endl;
        //cout << string_guitar1 << endl;
        //cout << string_guitar2 << endl;
        //cout << string_guitar3 << endl;
        //cout << string_guitar4 << endl;
        //cout << string_guitar5 << endl;
        //cout << string_guitar6 << endl;
        the_guitar->build_chord(chord,string_guitar1, string_guitar2,string_guitar3,string_guitar4,string_guitar5, string_guitar6);
		}
		cout << "list complete!" <<endl;
			break;
		}
        case 2:
        {
			string chord_to_find;
			cout << "Enter chord to find" << endl;
			getline(cin, chord_to_find);
			the_guitar->find_chord(chord_to_find);
			break;
		}
        case 3:
        {
			string chord_to_add;
			cout << "Enter chord to add" << endl;
			getline(cin,chord_to_add);
			string new_string_guitar1;
			string new_string_guitar2;
			string new_string_guitar3;
			string new_string_guitar4;
			string new_string_guitar5;
			string new_string_guitar6;
			cout << "Enter new string guitar 1" << endl;
			getline(cin,new_string_guitar1);
			cout << "Enter new string guitar 2" << endl;
			getline(cin,new_string_guitar2);
			cout << "Enter new string guitar 3" << endl;
			getline(cin,new_string_guitar3);
			cout << "Enter new string guitar 4" << endl;
			getline(cin,new_string_guitar4);
			cout << "Enter new string guitar 5" << endl;
			getline(cin,new_string_guitar5);
			cout << "Enter new string guitar 6" << endl;
			getline(cin,new_string_guitar6);
			the_guitar->add_chord(chord_to_add, new_string_guitar1, new_string_guitar2,new_string_guitar3,new_string_guitar4,new_string_guitar5, new_string_guitar6);
			break;
		}
        case 4:
        {
			string chord_to_delete;
			cout << "Enter chord to delete" << endl;
			getline(cin, chord_to_delete);
            the_guitar->delete_chord(chord_to_delete);
            break;
		}
        case 5:
        {
			string number_move_up;
			string chord;
			cout << "Enter chord to move up" << endl;
			getline(cin, chord);
			cout << "Enter how many steps up" << endl;
			getline(cin, number_move_up);
			the_guitar->transpose_chord_up(chord, stoi(number_move_up));
			break;
		}
		case 6:
		{
			string number_move_down;
			string chord;
			cout << "Enter chord to move down" << endl;
			getline(cin, chord);
			cout << "Enter how many steps down" << endl;
			getline(cin, number_move_down);
			the_guitar->transpose_chord_down(chord, stoi(number_move_down));
			break;
		}
		case 7:
		{
			string current_chord;
			string new_chord_name;
			string new_string_guitar1;
			string new_string_guitar2;
			string new_string_guitar3;
			string new_string_guitar4;
			string new_string_guitar5;
			string new_string_guitar6;
			cout << "Enter current chord" << endl;
			getline(cin,current_chord);
			cout << "Enter new chord name" << endl;
			getline(cin, new_chord_name);
			cout << "Enter new string guitar 1" << endl;
			getline(cin,new_string_guitar1);
			cout << "Enter new string guitar 2" << endl;
			getline(cin,new_string_guitar2);
			cout << "Enter new string guitar 3" << endl;
			getline(cin,new_string_guitar3);
			cout << "Enter new string guitar 4" << endl;
			getline(cin,new_string_guitar4);
			cout << "Enter new string guitar 5" << endl;
			getline(cin,new_string_guitar5);
			cout << "Enter new string guitar 6" << endl;
			getline(cin,new_string_guitar6);
			the_guitar -> change_chord(current_chord, new_chord_name, new_string_guitar1, new_string_guitar2, new_string_guitar3, new_string_guitar4, new_string_guitar5, new_string_guitar6);
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
			cout << "Clear all chords" << endl;
			the_guitar->clear_all_chords();
			break;
		}
		case 10:
		{
			cout << "Write to file" << endl;
			the_guitar->write_to_file();
			break;
		}
		case 11:
        {
            string input;
            cout << "Which option do you need help with? (Enter number)" << endl;
            getline(cin,input);
            the_guitar->help(input);
            break;
        }
		case 12:
		{
			Quit = true;
			cout << "Thank you for using our chord book!" << endl;
			break;
		}
		}
	}

    return 0;
}



