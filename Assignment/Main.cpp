#include <conio.h>
#include <string.h>
#include <LoadData.h>
#include <Universe.h>

const int FILE_NAME_LENGTH = 17; //each file name consists of 12 characters (13, because of /0 at the end of each array + extra 4 characters for ".CSV" in an ExportToCSV() function

void ChooseFileToRead(char *fileName);

void ExportToCSV(Cell grid[DIMENSION][DIMENSION], char *fileName);


int main(int argc, char **argv)
{	
	Cell universe[DIMENSION][DIMENSION];	
	Body bodyArray[MAX_BODIES_NUMBER]; //maxBodiesNumber is defined in LoadData.h
	Body *pbodyArray = bodyArray; //a pointer to an array of data
	char *pFileName; //a pointer to string with desired file name assigned by ChooseFileToRead() function
	char sFileName[FILE_NAME_LENGTH]; //string for storing a file name
	pFileName = sFileName;	//assigning the address of sFileName[] to a pointer pFileName


	ChooseFileToRead(pFileName);
	LoadData(pFileName, pbodyArray); //now all the values from a chosen textfile are stored in Body bodyArray[]
	
	//calculate potential for each point
	for (int k = 0; k < DetermineHowManyBodies(pFileName); k++)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
 				universe[i][j].fPotential[k] = CalculatePointPotential(i, j, bodyArray[k]);
			}
		}
	}

	//calculate net potential for each point
	for (int k = 0; k < DetermineHowManyBodies(pFileName); k++)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				universe[i][j].CalculateNetPotential();
			}
		}
	}

	//export to a CSV file
	ExportToCSV(universe, pFileName);

	getch();
	return 0;
}

void ChooseFileToRead(char *fileName)
{
	int iChoice;

	printf("Which file would you like to open? \n 1. bodies1.txt \n 2. bodies2.txt \n 3. bodies3.txt \n 4. bodies4.txt \n");
	scanf("%d", &iChoice);

	switch (iChoice)
	{
	case 1: {strcpy(fileName, "bodies1.txt"); };
			break;
	case 2: {strcpy(fileName, "bodies2.txt"); };
			break;
	case 3: {strcpy(fileName, "bodies3.txt"); };
			break;
	case 4: {strcpy(fileName, "bodies4.txt"); };
			break;	
	default:
	{
		printf("You must choose an integer between 1 and 4! Would you like to continue [1]? Press any other digit to exit the program. \n\n\n");
		scanf("%d", &iChoice);
		if (iChoice != 1)
			exit(-1);
		else
			ChooseFileToRead(fileName);
	}
	break;
	}
}

void ExportToCSV(Cell grid[DIMENSION][DIMENSION], char *fileName)
{
	FILE *output;	
	char FileExt[] = ".csv";
	char *pFileExt = FileExt;
	strcat(fileName, pFileExt);
	output = fopen(fileName, "w");

	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			fprintf(output, "%f,", grid[i][j].fNetPotential);
		}
		if(DIMENSION-i != 1)
			fprintf(output, "\n");  //to avoid creating an empty new line at the end of a .csv file
	}
	fclose(output);
}