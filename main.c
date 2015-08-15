#include "header.h"

int main(){

	int option = 0;
	int disc_position = 0;

	const int EXIT = 5;
	tDisc* pDisc = NULL;
	int nDiscs = 0;

	while (option != EXIT){
		option = menu();
		switch (option){
		case 1:
			pDisc = AddDisc(pDisc, &nDiscs);
			ReadDiscInfo(&pDisc[nDiscs - 1], nDiscs);
			break;
		case 2:
			DisplayDiscs(pDisc, nDiscs);
			break;
		case 3:
			PrintDiscsOfAuthor(pDisc, nDiscs);
			break;
		case 4:
			if (DeleteDisc(pDisc, &nDiscs) == -1)
				printf("There is no such disc!\n\n");
			else
				printf("Disc successfully removed!\n\n");
			break;
		case 5:
			
		}
	}

	FreeMemory(pDisc, nDiscs);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}