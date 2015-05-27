// File that demonstrates usage of Word_Counter and 
// Progress_Monitor classes

#include "progress_monitor.h"
#include "word_counter.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	// validate and open file
	ifstream filename;	
	filename.open(argv[1]);
	if (!filename.is_open()) {
		cout << "Unable to open " << argv[1] << "\n";
		exit(EXIT_FAILURE);
		}
		
	// initialize classes
	Word_Counter word_counter;
	Progress_Monitor monitor;
	
	// initialize PROGRESS_STATUS members
	PROGRESS_STATUS *progress = new PROGRESS_STATUS;
	progress->termination_val = word_counter.get_filesize(filename);	
	progress->current_status = 0;
	
	// separate thread to monitor progress
	pthread_t th_status;
	int status = pthread_create(&th_status, NULL, display_progress, (void *) progress);
	if (status != 0) {
		cout << "Error when created thread. \nError Number: " << status << "\n";
		exit(-1);
		}
	
	// count words and report number of words to console
	long num_words = word_counter.count_words(filename, progress);
	cout << "\nNumber of words: " << num_words << endl;
	
	return 0;
	
}




