
/* transform.h
 * declare all transformation actions supported by the utility
 */

#pragma once

// case
void lower(char** aText);		// -c --case
void upper(char** aText);		// -C --CASE
void sentence(char** aText);	// -s --sentence
void word(char** aText);		// -w --word

// character play
void rotate13(char** aText);	// -r --rotate13
void flip(char** aText);		// -f --flip
void mock(char** aText);		// -m --mock

// int view
void charindx(char** aText);	// -i --index
void ascii(char** aText);		// -a --ascii

