# Gayagoy_CSCI2270_FinalProject

Project Summary:
	This program is a text-based chord book interface simulator. It stores data on chord structures for a standard 6 string guitar. The program will come with a base file with a standard list of chords for use. The program should be executed with the base file of chords so that it has something o run with. The user can now look up chords from the chord list and the program will display it for the user. The user can also edit the chord list by adding and deleting chords at will from the main menu interface. Users can also transpose any chord they like up or down. This project should help organize chords for new or expert guitarists.

How to Run:
	In order to run, load the files and compile the Final_Project.cpp and Chord_Guitar.cpp files together. Then run the executable with the attached initial text file. The program should prompt with a main menu that should display any available uses for the program. Further project documentation and explanation for methods are located in comment blocks within the Chord_Guitar.cpp file. For simple explanations for each function, use the “help” function in from the main menu of the executed program. After each save, it is recommended to restart the program and rerun it using the newly generated .txt file in the folder. This will allow the initial build of the list to use the info you saved.

	Directions:
	1.) Clone the file directory and extract all of the files into a separate folder
	2.) Using the terminal in your VM, navigate to the directory you have extracted the files into
	3.) Once there, use the following commands to run program
		g++ Final_Project.cpp Chord_Guitar.cpp -std=c++11
		./a.out Chord_Guitar.txt
	4.) This should compile the files and run the program using the executable you just created, from here just follow the on screen prompts in the main menu. Use the help function and input a number from any function to get a better explanation of the function. 
	5.) If saving results, to rerun the program you must replace the 2nd line in the terminal with 
	./a.out NewSavedChord.txt
This will allow you to build the list using your most recent saved additions. 

Dependencies:
Requires C++ 11 and access to fstream and iostream libraries. Also requires the standard use library. 

System Requirements:
Run using terminal, preferably on vm software, available on any machine. 

Group Members:
Thomas Gayagoy
Anh-khoa Than
Yash Parekh

Contributors:

Open issues/bugs:
	- Problem running other methods after using the save method
		How to Replicate: run the build function and add a new chord, then save the document and try to add another code.
		Current solution: The program exits after each save to stop the user from using any more functions.




