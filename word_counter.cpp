// Implementation file for word_counter
#include "word_counter.h"

Word_Counter::Word_Counter() {
	word_count = 0;
}

// This get the file size of a given file by
// seeking to the end of the file, getting its 
// current position in file, then rewinding back
int Word_Counter::get_filesize(ifstream& file) {
	file.seekg(0L, ios::end);
	int size = file.tellg();
	file.seekg(0L, ios::beg);
	return size;
}

// counts number of words in a given text file.
// Also updates PROGRESS_STATUS member, current_status, by 
// retrieving its current location in the file using tellg()
long Word_Counter::count_words(ifstream &file, PROGRESS_STATUS *progress) {
	char current_char;
	while (!file.eof()) {
		progress->current_status = file.tellg();
		char prev = current_char;
		file.get(current_char);
		if (isspace(current_char) && (!(isspace(prev))))
			word_count++;
		}
	return word_count;

}

