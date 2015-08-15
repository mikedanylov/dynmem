#include "header.h"

int menu(void){

	int option = 0;

	while (option < 1 || option > 5 || isdigit(option) != 0){
		printf("1. Add disc\n");
		printf("2. Display information of the discs\n");
		printf("3. Display the discs of an author using his name\n");
		printf("4. Delete disc\n");
		printf("5. Exit\n");

		printf("\n Make your choice: ");
		fflush(stdin);
		scanf("%d", &option);
	}

	return option;
}


tDisc* AddDisc(tDisc* pDisc, int* nDiscs){

	tDisc* tmp_disc = (tDisc*)realloc(pDisc, (*nDiscs + 1) * sizeof(tDisc));
	if (tmp_disc == NULL){
		printf("\nError allocating memory\n");
		FreeMemory(pDisc, *nDiscs);
		exit(-1);
	}
	else{
		(*nDiscs)++;
	}
	return tmp_disc;
}

void ReadDiscInfo(tDisc* pDisc, int nDiscs){
	
	int i;
	char** ppSongs = NULL;
	
	printf("\n*************************************************\n");
	printf("Enter Disc Info\n");
	printf("*************************************************\n");
	printf("title: ");
	fflush(stdin);
	fgets(pDisc->title, MAX_CHARAC_TITLE, stdin);
	printf("author: ");
	fflush(stdin);
	fgets(pDisc->nameAuthor, MAX_CHARAC_NAME, stdin);
	printf("number of songs: ");
	fflush(stdin);
	scanf("%d", &pDisc->numSongs);
	
	ppSongs = (char**)malloc( pDisc->numSongs * (sizeof(char*)));

	if (ppSongs == NULL){
		printf("\nError allocating memory\n");
		FreeMemory(pDisc, nDiscs);
		exit(-1);
	}
	else{
		pDisc->ppSong = ppSongs;
		
		for (i = 0; i < pDisc->numSongs; i++){
			ppSongs[i] = (char*)malloc(sizeof(char[MAX_CHARAC_TITLE]));
			
			if (ppSongs[i] == NULL){
				printf("\nError allocating memory\n");
				FreeMemory(pDisc, nDiscs);
				exit(-1);
			}
			else{
				pDisc->ppSong[i] = ppSongs[i];
				printf("----------------------------\n");
				printf("Input %d song name: ", i + 1);
				fflush(stdin);
				fgets(pDisc->ppSong[i], MAX_CHARAC_TITLE, stdin);
			}
		}
	}
}

void DisplayDiscs(tDisc* pDisc, int nDiscs){

	int i, j;

	printf("\n*************************************************\n");
	printf("DISCs INFO\n");
	printf("*************************************************\n");

	for (i = 0; i < nDiscs; i++){

		printf("title: \t\t\t%s", pDisc[i].title);
		printf("author: \t\t%s", pDisc[i].nameAuthor);
		printf("number od songs: \t%d\n", pDisc[i].numSongs);
		printf("list of songs:\n");
		
		for (j = 0; j < pDisc[i].numSongs; j++){
			printf("\t\t%d. %s", j + 1, pDisc[i].ppSong[j]);
		}
		printf("\n");
	}
	printf("\n*************************************************\n\n");
}

void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs){
	
	int i, j;
	char author[MAX_CHARAC_NAME];

	printf("\n*************************************************\n");
	printf("DISCs INFO BY AUTHOR\n");
	printf("*************************************************\n");
	printf("Input Author name: \t");
	fflush(stdin);
	fgets(author, MAX_CHARAC_NAME, stdin);

	for (i = 0; i < nDiscs; i++){

		if (strcmp(author, pDisc[i].nameAuthor) == 0){
			printf("title: \t\t\t%s", pDisc[i].title);
			printf("number od songs: \t%d\n", pDisc[i].numSongs);

			printf("list of songs:\n");
		
			for (j = 0; j < pDisc[i].numSongs; j++){
				printf("\t\t%d. %s", j + 1, pDisc[i].ppSong[j]);
			}
			printf("\n");
		}
	}
	printf("\n*************************************************\n\n");
}

int DeleteDisc(tDisc* pDisc, int* pnDiscs){

	int i, j;
	char title[MAX_CHARAC_TITLE];
	tDisc* tmp_pDisc = NULL;
	int init_nDiscs = *pnDiscs;

	printf("\n*************************************************\n");
	printf("REMOVE DISC BY TITLE\n");
	printf("*************************************************\n");
	printf("Input title: \t");
	fflush(stdin);
	fgets(title, MAX_CHARAC_TITLE, stdin);
	
	for (i = 0; i < *pnDiscs; i++){
		
		if (strcmp(title, pDisc[i].title) == 0){
			
			tmp_pDisc = (tDisc*)realloc(pDisc, (*pnDiscs - 1) * sizeof(tDisc));
			
			if (tmp_pDisc == NULL){
				printf("\nError allocating memory\n");
				FreeMemory(pDisc, *pnDiscs);
				exit(-1);
			}
			else{
				for (j = i; j < *pnDiscs; j++){
					pDisc[i] = pDisc[i + 1];
				}
				//for (j = 0; j < pDisc[*pnDiscs - 1].numSongs; j++)
				//	free(pDisc[*pnDiscs - 1].ppSong[j]);
				//free(pDisc[*pnDiscs - 1].ppSong);
				(*pnDiscs)--;
				pDisc = tmp_pDisc;
			}
		}
	}
	printf("\n*************************************************\n\n");
	if (init_nDiscs == *pnDiscs)
		return -1;
	else
		return 0;
}

void FreeMemory(tDisc* pDisc, int nDiscs){

	int i, j;
	for (i = 0; i < nDiscs; i++){
		for (j = 0; j < pDisc[i].numSongs; j++)
			if (pDisc[i].ppSong[j] != NULL)
				free(pDisc[i].ppSong[j]);
		if (pDisc->ppSong != NULL)
			free(pDisc->ppSong);
	}
	if (pDisc != NULL)
		free(pDisc);
}