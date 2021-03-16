//-----------------------------------------------------------------------------
//
// NAME
//  sed253 -- Simplified editor
//
// SYNOPSIS
//  sed253
//  sed253 -s pattern string
//  sed253 -d line1 line2
//
// DESCRIPTION
//  Simplified editor.  Copies lines read from stdin to stdout.  Options:
//
//  -s Substitute every occurrence of pattern with string
//  -d Delete line1 through line2 inclusive
//
// ERRORS
//  Prints usage message and exits abnormally for invalid commands.  Prints an
//  error message and exits abnormally for other issues.
//
// LIMITATIONS
//  Lines of text are limited to a maximum of 1023 chars.
//
// AUTHORS
//  Epoch...................................................................jrc
//
//-----------------------------------------------------------------------------

//Bring in the definitions for our helper functions
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "copy.h"
#include "substitute.h"
#include "delete.h"
#include "copy.c"
#include "substitute.c"
#include "delete.c"

//-----------------------------------------------------------------------------
// usage -- Prints a usage message and exists with status=2
//-----------------------------------------------------------------------------
void usage(char* s) {

	//Print the usage message to sstderr
	fprintf(stderr, "Usage: sed253  %s\n", s);

	//Force an exit
	exit(2);
}
// main -- the main function
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
	
	int exitStatus = 1;

	if (argc == 4) {
		if (strcmp(argv[1], "-s")==0) {
			exitStatus = doSubstitute(argv[2], argv[3]);
			
		}
		else if (strcmp(argv[1], "-d")==0) {
			exitStatus = doDelete(argv[2], argv[3]);
		}
		else {
			usage(argv[0]);
		}
	}

	else if (argc == 1) {
		exitStatus = doCopy();
	}

	else {
		usage(argv[0]);
	}
	
  return exitStatus;
}
