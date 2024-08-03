
#include "transform.h"

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// ALL UPPER CASE
void upper(char** aText) {
	for (int i = 0; (*aText)[i] != '\0'; i++) {
		(*aText)[i] = toupper((*aText)[i]);
	}
	printf("%s\n", *aText);
}

// all lower case
void lower(char** aText) {
	for (int i = 0; (*aText)[i] != '\0'; i++) {
		(*aText)[i] = tolower((*aText)[i]);
	}
	printf("%s\n", *aText);
}

// Sentence case. Capital only after fullstop.
void sentence(char** aText) {
	bool lNewSentence = 1;

	for (int i = 0; (*aText)[i] != '\0'; i++) {
		if (lNewSentence && isalpha((*aText)[i])) {
			(*aText)[i] = toupper((*aText)[i]);
			lNewSentence = false;

		} else if (isspace((*aText)[i])) {
			if (i > 0 && ((*aText)[i-1] == '.' ||
						(*aText)[i-1] == '!' ||
						(*aText)[i-1] == '?'))
			{
				lNewSentence = true;
			}

		} else {
			(*aText)[i] = tolower((*aText)[i]);
		}
	}

	printf("%s\n", *aText);
}

// Every Word Capital
void word(char** aText) {
	bool lInWord = 0;

	for (int i = 0; (*aText)[i] != '\0'; i++) {
		if (isalpha((*aText)[i])) {
			if (!lInWord) {
				(*aText)[i] = toupper((*aText)[i]);
				lInWord = true;
			} else {
				(*aText)[i] = tolower((*aText)[i]);
			}
		} else {
			lInWord = false;
		}
	}

	printf("%s\n", *aText);
}

// ebgngr nyy punenpgref ol guvegrra
void rotate13(char** aText) {
	for (int i = 0; (*aText)[i] != '\0'; i++) {
		if (isalpha((*aText)[i])) {
			char base = isupper((*aText)[i]) ? 'A' : 'a';
			(*aText)[i] = base + (((*aText)[i] - base + 13) % 26);
		}
	}
	printf("%s\n", *aText);
}

// mOcK tExT
void troll(char** aText) {
	bool lSmall = true;

	for (int i = 0; (*aText)[i] != '\0'; i++) {
		if (lSmall) {
			(*aText)[i] = tolower((*aText)[i]);
		} else {
			(*aText)[i] = toupper((*aText)[i]);
		}

		lSmall = !lSmall;
	}
	printf("%s\n", *aText);
}

// cAPITAL BECOMES LOWER
void flip(char** aText) {
	for (int i = 0; (*aText)[i] != '\0'; i++) {
		if (isupper(*aText[i])) {
			(*aText)[i] = tolower((*aText)[i]);
		} else {
			(*aText)[i] = toupper((*aText)[i]);
		}
	}
	printf("%s\n", *aText);
}

// 1618091420 0308011819 0119 2008050918 0112160801020520 0914040524
void charindx(char** aText) {
    for (int i = 0; (*aText)[i] != '\0'; i++) {
        if (isalpha((*aText)[i])) {
            printf("%02d", tolower((*aText)[i]) - 'a' + 1);
        } else {
            printf("%c", (*aText)[i]);
        }
    }
    printf("\n");
}

