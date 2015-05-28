// Header file for word_counter

#ifndef word_counter_h
#define word_counter_h

#include "progress_status.h"

#include <fstream>
#include <sys/stat.h>

class Word_Counter {
private:
	long word_count;

public:
	Word_Counter();
	int get_filesize(ifstream&);
	long count_words(ifstream&, Progress_Status*);
};


#endif
