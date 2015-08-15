// All include directives that are needed
#include  <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "MemoryManager.h"

// Constants
#define MAX_CHARAC_NAME 20
#define MAX_CHARAC_TITLE 30

typedef struct{
	char title[MAX_CHARAC_TITLE]; // Example: "THE ESSENTIAL" int year;
	char nameAuthor[MAX_CHARAC_NAME];
	int numSongs; // The songs number
	char** ppSong; // The songs name
}tDisc;

extern int menu(void);
extern tDisc* AddDisc(tDisc* pDisc, int* nDiscs);
extern void ReadDiscInfo(tDisc* pDisc, int nDiscs);
extern void DisplayDiscs(tDisc* pDisc, int nDiscs);
extern void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs);
extern int DeleteDisc(tDisc* pDisc, int* pnDiscs);
extern int LookForDisc(tDisc* pDisc, int nDiscs);
extern void FreeMemory(tDisc* pDisc, int nDiscs);