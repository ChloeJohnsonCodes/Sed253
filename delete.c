#include "delete.h"

// doDelete -- Copies lines read from stdin to stdout and ommits lines numbered line1 through line2. 
// line1 and line2 can have characters in the argument, but numbers will be parsed from it. If there
// are no numbers in the argument, the program exits abnormally with an exit status of 0. 

int doDelete(char *line1, char *line2) {
	int i, j = 0;
	int numLines1;
	int numLines2;
	int lineCount = 0;
	int exitStatus = 1;
	char str[1023];
	char *line1Ptr = line1;
	char *line2Ptr = line2;
	char *nLine1 = (char*)malloc(strlen(line1));
	char *nLine2 = (char*)malloc(strlen(line2));
	
	if ((strlen(line1) > 1023) || (strlen(line2) > 1023)) {
	  free(nLine1);
	  free(nLine2);
	  return exitStatus;
	}
	for (i = 0; line1Ptr[i] != '\0'; i++) {
		if (strstr(&line1Ptr[i], "0") == &line1Ptr[i] || strstr(&line1Ptr[i], "1") == &line1Ptr[i] || strstr(&line1Ptr[i], "2") == &line1Ptr[i] || 
			strstr(&line1Ptr[i], "3") == &line1Ptr[i] || strstr(&line1Ptr[i], "4") == &line1Ptr[i] || strstr(&line1Ptr[i], "5") == &line1Ptr[i] || 
			strstr(&line1Ptr[i], "6") == &line1Ptr[i] || strstr(&line1Ptr[i], "7") == &line1Ptr[i] || strstr(&line1Ptr[i], "8") == &line1Ptr[i] || 
			strstr(&line1Ptr[i], "9") == &line1Ptr[i]) {
			nLine1[j] = line1Ptr[i];
			j++;
		}
		nLine1[j] = '\0';
	}
	j = 0;
	for (i = 0; line2Ptr[i] != '\0'; i++) {
		if (strstr(&line2Ptr[i], "0") == &line2Ptr[i] || strstr(&line2Ptr[i], "1") == &line2Ptr[i] || strstr(&line2Ptr[i], "2") == &line2Ptr[i] || 
			strstr(&line2Ptr[i], "3") == &line2Ptr[i] || strstr(&line2Ptr[i], "4") == &line2Ptr[i] || strstr(&line2Ptr[i], "5") == &line2Ptr[i] || 
			strstr(&line2Ptr[i], "6") == &line2Ptr[i] || strstr(&line2Ptr[i], "7") == &line2Ptr[i] || strstr(&line2Ptr[i], "8") == &line2Ptr[i] || 
			strstr(&line2Ptr[i], "9") == &line2Ptr[i]) {
			nLine2[j] = line2Ptr[i];
			j++;
		}
	}
	nLine2[j] = '\0';
	if ((nLine1[0] == '\0') || (nLine2[0] == '\0')) {
		free(nLine1);
		free(nLine2);
		return exitStatus;
	}
	numLines1 = atoi(nLine1);
	numLines2 = atoi(nLine2);
	if (numLines1 > numLines2) {
	  return exitStatus;
	}
	while (fgets(str, 1023, stdin) != NULL) {
		lineCount++;
		if (!((lineCount >= numLines1) && (lineCount <= numLines2))) {
		  fputs(str, stdout);
		  exitStatus = 0;
		}
	}
	free(nLine1);
	free(nLine2);
	return exitStatus;
}
