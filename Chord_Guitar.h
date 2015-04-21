//Chord_Guitar.h
#include <iostream>
#include <string>
#ifndef GUITAR_H
#define GUITAR_H
//Anh-Khoa Than
//Thomas
//Yash
struct node
{
	std::string chord;
    std::string string_guitar1;
    std::string string_guitar2;
    std::string string_guitar3;
    std::string string_guitar4;
    std::string string_guitar5;
    std::string string_guitar6;
    node(){};
    node *next;
    node *previous;
    node *loop;

};

class Guitar
{
    public:
        Guitar();
        void build_chord(std::string chord, std::string string_guitar1, std::string string_guitar2, std::string string_guitar3, std::string string_guitar4, std::string string_guitar5, std::string string_guitar6);
        void find_chord(std::string chord);
        void add_chord(std::string chord, std::string string_guitar1, std::string string_guitar2, std::string string_guitar3, std::string string_guitar4, std::string string_guitar5, std::string string_guitar6);
        void delete_chord(std::string chord);
        void transpose_chord_up(std::string chord, int number_move_up);
        void transpose_chord_down(std::string chord, int number_move_down);
        void change_chord(std::string chord, std::string new_chord_name, std::string string_guitar1, std::string string_guitar2, std::string string_guitar3, std::string string_guitar4, std::string string_guitar5, std::string string_guitar6);
        void display_chord();
        void clear_all_chords();
        void write_to_file();
    protected:
    private:
    node *head;
    node *tail;
    bool start_creation = false;
};

#endif // GUITAR_H

//List of Public Methods
//1. create a chord list with a file
//2. display a chord
//3. add a chord
//4. delete a chord
//5. transpose up a selected chord
//6. transpose down a selected chord
//7. show a current list of chords
//8. clear all chords
//9. change a chord
//10. save changes
