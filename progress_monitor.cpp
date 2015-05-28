// Implementation file for progress_monitor.cpp

#include "progress_monitor.h"


// Internal thread function for pthread library
// calculates how much progress
// the word counter has done and prints a progress
// bar to indicate where it is in completion
// example: 
// ---------+----------+---------+
// every '+' signifies 20% completion

void *display_progress(void *prog_status) {
	Progress_Status* progress = (Progress_Status*) prog_status;
	int num_printed = 0;
	
	while (num_printed < NUM_HYPHENS) {
		int processed = ((float) progress->current_status / (float) progress->termination_val * NUM_HYPHENS) - num_printed;
		num_printed += processed;
	
		for (int i = 0; i < processed; i++) 
			(num_printed % PROGRESS_WIDTH) == 0 ? cout << "+" : cout << "-";	
		cout.flush();
		}
	pthread_exit(NULL);
}
