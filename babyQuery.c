#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"

int main ( int argc, char *argv ) {
	FILE *f1;
	int i = 0;
	char decade[5];
	char choice[10];
	struct pNames popNames;
        char maleSNumber[20];
        char femaleSNumber[20];
        char string[100];
	char year[5];

  	printf("What decade do you want to look at? [1880 to 2010] ");
	scanf("%s",decade);
	strcpy(year,decade);
	if ( *year > 1880 || *year < 2010){
	strcat (decade, "Names.txt");
	}

	else {
		printf("Error - the decade you entered is not in the range 1880 - 2010\n");
	}

	 if ( (f1 = fopen(decade, "r")) != NULL ) {
		 while ( fgets(string, 100, f1) != NULL ) {
			 sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
			 removeCommas ( maleSNumber );
			 removeCommas ( femaleSNumber );
			 popNames.maleNumber[i] = atoi ( maleSNumber );
			 popNames.femaleNumber[i] = atoi ( femaleSNumber );
			 i++;
	      	}
	}else {
		 printf ( "Cannot open %s\n", decade);
		 return ( -2 );
	}

	printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top] ");
	scanf("%s",choice);

	if (choice == "rank" || choice == "search" || choice == "top"){
		printf("Error - the enter rank, search or top spelled correctly and all lower case \n ");
	}

		if (strcmp (choice, "rank") == 0){
			int rank;
			int gender;
			printf("What rank do you wish to see? [1-200] ");
			scanf("%d", &rank);

			if (rank < 1 || rank > 200) {
				printf( "Error - enter a rank between 1 - 200\n");
			}

			printf("Would you like to see the male (0), female (1), or both (2) name(s)? [0-2] ");
			scanf("%d", &gender);

			if (gender >= 0 || gender <= 2) {


				if (gender == 0){
					printf("Rank %d: Male: %s (%d)\n",rank,popNames.maleName[rank-1],popNames.maleNumber[rank-1]);
				}
				if (gender == 1){
					printf("Rank %d: Female: %s (%d)\n",rank,popNames.femaleName[rank-1],popNames.femaleNumber[rank-1]);
				}
				if (gender == 2){
					printf("Rank %d: Male: %s (%d) and Female: %s (%d)\n",rank,popNames.maleName[rank-1],popNames.maleNumber[rank-1],popNames.femaleName[rank-1],popNames.femaleNumber[rank-1] );
				}
			}

			else {
				printf( "Error - choose a number between 0 - 2 \n");
			}
		}

		if (strcmp (choice, "search") == 0) {
			char name[50];
			int j;
			int gender;
			int maleFound = 0;
			int femaleFound = 0;

			printf("What name do you want to search for? [case sensitive] ");
			scanf("%s", name);

			printf("Do you wish to search male (0), female (1), or both (2) name(s)? [0-2] ");
			scanf("%d", &gender);
			printf("%d",gender);

			if (gender == 0){
				for (j=0; j < 200; j++) {
					if (strcmp(name, popNames.maleName[j]) == 0){
						printf("In %s, the male name %s is ranked %d with a count of %d \n", year, name,j+1, popNames.maleNumber[j]);
						maleFound = 1;
					}
				}
				if (maleFound == 0) {
					printf("In %s, the male name %s was not ranked", year, name);
				}
			}
			if (gender == 1){
				for (j=0; j < 200; j++) {
					if (strcmp(name, popNames.femaleName[j]) == 0){
						printf("In %s, the female name %s is ranked %d with a count of %d \n", year, name,j+1, popNames.femaleNumber[j]);
						femaleFound = 1;
					}
				}
				if (femaleFound == 0) {
						printf("In %s, the female name %s was not ranked", year, name);
					}

			}

			if (gender == 2){
				int maleNum;
				int femaleNum;
				int maleRank;
				int femaleRank;

				for (j=0; j < 200; j++) {
					if (strcmp(name, popNames.maleName[j]) == 0){
						maleFound = 1;
						maleNum = popNames.maleNumber[j];
						maleRank = j+1;
					}

					if (strcmp(name, popNames.femaleName[j]) == 0){
						femaleFound = 1;
						femaleNum = popNames.femaleNumber[j];
						femaleRank = j+1;

					}

				}

				if ( maleFound == 1 && femaleFound == 0) {
					printf("In %s, the male name %s is ranked %d with a count of %d and the female name %s is not ranked\n", year, name,maleRank, maleNum,name);
				}

				if ( femaleFound == 1 && maleFound == 0) {
					printf("In %s, the female name %s is ranked %d with a count of %d and the male name %s is not ranked \n", year, name,femaleRank, femaleNum, name);
				}

				if ( femaleFound == 1 && maleFound == 1) {
					printf("In %s, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d \n", year, name,femaleRank, femaleNum, name, maleRank,maleNum);
				}

				if ( femaleFound == 0 && maleFound == 0) {
					printf("In %s, the female name %s is not ranked and the male name %s is not ranked \n", year, name, name);
				}

			}

		}
		if (strcmp (choice, "top") == 0) {
			int k;
			int rank;
			int maleNum;
			int femaleNum;

			for (k = 0; k < 10; k++){
				maleNum = popNames.maleNumber[k];
				femaleNum = popNames.femaleNumber[k];
				rank = k+1;


				printf("%d %s %d %s %d \n", rank, popNames.maleName[k], maleNum,popNames.femaleName[k], femaleNum);
			}
		}

	char choice1[10];
	char choice2[10];
	char answer[5];
	char anotheryear[5];
	char decadefile[5];

	printf("Do you want to ask another question about %s? [Y or N] ", year);
	scanf("%s",&choice1);

		if (strcmp(choice1,"y") == 0) {
			printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top] ");
			scanf("%s",&answer);
		}

		if (strcmp(choice1,"n") == 0){
			printf("Would you like to select another year? [Y or N] ");
			scanf("%s",&anotheryear);
		}
			if (strcmp(anotheryear,"y") == 0) {
				printf("What decade do you want to look at? [1880 to 2010] ");
				scanf("%s",&decadefile);
			}

			if (strcmp(anotheryear,"n") == 0){
				printf("Thank you for using babyQuery\n");
			}
}
int removeCommas ( char *commaStr ) {

	int length = 0;
	int i;
	int numCommas = 0;

	length = strlen (commaStr);

	for ( i = 0; i < length; i++) {
		if ( commaStr[i] == ',') {
			numCommas ++;
			commaStr[i] = commaStr[i + numCommas];
		}

		else {
			commaStr[i] = commaStr[i + numCommas];
		}
	}

	return numCommas;

}
