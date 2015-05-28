# Multithreading
Simple C++ command line application that demonstrates use of multiple threads. One thread counts the number of words in a text file, another thread displays its progress until completion. The total number of words in the supplied text file is shown after completion.


# Components:

Progress_Monitor:

This entity monitors the progress of a task by displaying a progress bar to indicate where the task is currently at in completion. This entity has only one thread function used for POSIX thread class. A pthread is initialized and performs monitoring of the task while it is concurrently running. The task is measured by taking its current byte in the file divided by the total size of the file. "-"'s and "+"'s signs are used to represent the progress meter.

Example:

---------+---------+---------+---------+---------+

Each "+" represents 20% completion.


Progress_Status:

struct data type that holds data about the current location in a given text file and the total size of a file. These data members are used in Progress_Monitor and Word_Counter to monitor progress.


Word_Counter:

This class counts the number of words in the supplied text file. As its counting words, it is updating a member variable in Progress_Status, current_status, that keeps track of where it is in the text file. Other member functions include returning total size of text file.  



# How to run:

*Note: must be using a UNIX environment to run the "make" command

1. Clone the repo and bring the command line prompt to the directory that contains all source files
2. Type the command "make" to initiate the Makefile
3. The Makefile should compile and link all of the classes into an executable called "wordcount"
4. To use the application type: wordcount filename.txt
5. filename.txt is any .txt file that contains text. Sample text files can be downloaded in the "Sample Text" folder.



# Test Plans

*Needs to be implemented

Each component in application will be tested individually

Word_Counter:
	[] get_filesize returns the correct number of total bytes in file
	[] count_words returns the correct number of words 
	
	- test files should include empty files, single character files, files with only new lines, etc
	
Progress_Monitor:
	[] display_progress prints to console


