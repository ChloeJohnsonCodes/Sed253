#include "copy.h"

// doCopy -- copies stdin to stdout

int doCopy(void) {

	char str[1023];
	int exitStatus = 1;

	while (fgets(str, 1023, stdin) != NULL) {
	  fputs(str, stdout);
	  exitStatus = 0;
	}
	return exitStatus;
}