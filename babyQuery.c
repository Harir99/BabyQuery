#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"

int main ( int argc, char *argv[] ) {
	FILE *f1;
	int i = 0;
	char decade[5];
	char choice[10];
	struct pNames popNames;
    char maleSNumber[20];
    char femaleSNumber[20];
    char string[100];
	char year[5];
	int yearLoop = 1;
	int decadeLoop = 1;
	char choice1[10];
	char anotheryear[5];
	int yearInt;
	int valid = 0;


	while ( decadeLoop == 1){
	  	printf("What decade do you want to look at? [1880 to 2010] ");
		scanf("%s",decade);
		strcpy(year,decade);
		yearInt = atoi(year);
		yearLoop = 1;
		i = 0;

		if ( yearInt > 1879 && yearInt < 2011 && (yearInt % 10) == 0){
			strcat (decade, "Names.txt");
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
		}

		else{
			printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable\n");
			yearLoop = 0;
		}



		while(yearLoop == 1){
			valid = 0;
			while (valid == 0){
				printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top] ");
				scanf("%s",choice);


				if (strcmp (choice, "rank") == 0){
					int rank;
					int gender;
					valid = 0;
					while (valid == 0){
						printf("What rank do you wish to see? [1-200] ");
						scanf("%d", &rank);

						if (rank < 1 || rank > 200) {
							printf( "Only numbers between 1 and 200 are acceptable.\n");
						}
						else{
							valid = 1;
						}
					}
					valid = 0;
					while ( valid == 0) {
						printf("Would you like to see the male (0), female (1), or both (2) name(s)? [0-2] ");
						scanf("%d", &gender);


						if (gender >= 0 && gender <= 2) {

							valid = 1;

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

						else{
							printf( "The numbers 0, 1, or 2 are acceptable\n");
						}
					}
					valid =1;
				}

				else if (strcmp (choice, "search") == 0) {
					char name[50];
					int j;
					int gender;
					int maleFound = 0;
					int femaleFound = 0;

					printf("What name do you want to search for? [case sensitive] ");
					scanf("%s", name);

					printf("Do you wish to search male (0), female (1), or both (2) name(s)? [0-2] ");
					scanf("%d", &gender);

					if (gender >= 0 || gender <= 2) {
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
								printf("In %s, the female name %s was not ranked\n", year, name);
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

					if ( gender < -1 || gender > 3){
						printf( "Only the numbers 0, 1, or 2 are acceptable\n");
						return 1;
					}
					valid = 1;

				}
				else if (strcmp (choice, "top") == 0) {
					int k;
					int rank;
					int maleNum;
					int femaleNum;

					for (k = 0; k < 10; k++){
						maleNum = popNames.maleNumber[k];
						femaleNum = popNames.femaleNumber[k];
						rank = k+1;


						printf("%-2d %-12s %-8d %-12s %d \n", rank, popNames.maleName[k], maleNum,popNames.femaleName[k], femaleNum);
					}
					valid = 1;

				}
				else {
					printf("Please type in rank, search, or top exactly as requested.\n ");
				}
			}




			valid = 0;
			while ( valid == 0){
				printf("Do you want to ask another question about %s? [Y or N] ", year);
				scanf("%s",choice1);
				if (strcmp(choice1,"n") == 0 || strcmp(choice1,"N") == 0) {
					decadeLoop = 0;
					valid = 1;
				}
				else if (strcmp(choice1,"y") == 0 || strcmp(choice1,"Y") == 0) {
					valid = 1;
				}
				else {
					printf("Only the single characters Y or N are acceptable.\n");
				}


			}
			if (strcmp(choice1,"n") == 0){
				yearLoop = 0;
			}
		}

			valid = 0;
			while ( valid == 0){
				printf("Would you like to select another year? [Y or N] ");
				scanf("%s",anotheryear);
				if (strcmp(anotheryear,"n") == 0 || strcmp(anotheryear,"N") == 0) {
					decadeLoop = 0;
					valid = 1;
				}
				else if (strcmp(anotheryear,"y") == 0 || strcmp(anotheryear,"Y") == 0) {
					valid = 1;
				}
				else {
					printf("Only the single characters Y or N are acceptable.\n");
				}


			}


	}
		printf("Thank you for using babyQuery\n");

		return 0;
}
