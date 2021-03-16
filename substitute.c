#include "substitute.h"

// doSubstitute -- Substitutes every occurence of pattern with string. 
// Each line is written to stdout.
//
// References: https://www.sanfoundry.com/c-program-search-replace-word/
//----------------------------------------------------------------------

int doSubstitute(char *pattern, char *string) {
	char str[1023];
	char *strPtr = str;
	int i, c = 0;
	int exitStatus = 1;

	if ((strlen(pattern) > 1023) || (strlen(string) > 1023)) {
		return exitStatus;
	}

	else {

		while (fgets(str, 1023, stdin) != NULL) {
		  exitStatus = 1;
		  c = 0;
		  strPtr = str;
			for (i = 0; str[i] != '\0'; i++) {
				if (strstr(&str[i], pattern) == &str[i]) {
					c++;
				}
			}
			char *nStr = (char*)malloc(strlen(str) + (c * (strlen(string) - strlen(pattern))));
			if (strlen(nStr) > 1023) {
			  free(nStr);
			  return exitStatus;
			}
			else {
				for (i = 0; *strPtr; i++) {
				    if (strstr(strPtr, pattern) == strPtr) {
					strncpy(&nStr[i], string, strlen(string));
					    i += strlen(string) - 1;
					    strPtr += strlen(pattern);
					}
					else {
					    nStr[i] = *strPtr++;
				    }
				}
				if (str[strlen(str) - 1] == '\n') {
				    nStr[i] = '\0';
				    fputs(nStr, stdout);
				    exitStatus = 0;
				}
				else if (str[strlen(str)] == '\0') {
				    nStr[i] = '\0';
				    fputs(nStr, stdout);
				    exitStatus = 0;
				    free(nStr);
				}
				else {
				  free(nStr);
				  return exitStatus;
				}
			}
		}
	}
	return exitStatus;
}