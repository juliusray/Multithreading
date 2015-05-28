// Header file for progress_monitor.h

#ifndef progress_monitor_h
#define progress_monitor_h

#include "progress_status.h"

#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;
const int NUM_HYPHENS = 50;
const int PROGRESS_WIDTH = 10;


//thread function
void *display_progress(void *prog_status);


#endif
