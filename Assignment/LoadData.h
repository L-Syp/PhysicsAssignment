#include <Universe.h>

int DetermineHowManyBodies(char sFileName[]) //returns a number of bodies in a text file
{
	FILE *fp;
	int value = 0;
	if ((fp = fopen(sFileName, "r")) == NULL)
	{
		printf("File cannot be opened! Try starting an application with administrator privileges.");
		scanf("%d", NULL);
		exit(-1);
	}
	fscanf(fp, "%d\n", &value);
	return value;
}

void LoadData(char sFileName[], Body *myData) //opens a text file and assigns its data to Body objects
{
	FILE *fp;
	int i = 0;

	//open a text file
	if ((fp = fopen(sFileName, "r")) == NULL)
	{
		printf("File cannot be opened! Try starting an application with administrator privileges.");
		scanf("%d", &i);
		exit(-1);
	}

	//read the file
	switch (DetermineHowManyBodies(sFileName))
	{
		case 1:
		{
			fscanf(fp, "%d\n%f,%f,%f", &i, &myData[0].x, &myData[0].y, &myData[0].mass);
			fclose(fp);
		}
		break;
		case 2:
		{
			fscanf(fp, "%d\n%f,%f,%f\n%f,%f,%f", &i, &myData[0].x, &myData[0].y, &myData[0].mass, &myData[1].x, &myData[1].y, &myData[1].mass);
			fclose(fp);
		}
		break;
		case 3:
		{
			fscanf(fp, "%d\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f", &i, &myData[0].x, &myData[0].y, &myData[0].mass, &myData[1].x, &myData[1].y, &myData[1].mass, &myData[2].x, &myData[2].y, &myData[2].mass);
			fclose(fp);
		}
		break;
		case 4:
		{
			fscanf(fp, "%d\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f", &i, &myData[0].x, &myData[0].y, &myData[0].mass, &myData[1].x, &myData[1].y, &myData[1].mass, &myData[2].x, &myData[2].y, &myData[2].mass,
				&myData[3].x, &myData[3].y, &myData[3].mass);
			fclose(fp);
		}
		break;
		case 5:
		{
			fscanf(fp, "%d\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f\n%f,%f,%f", &i, &myData[0].x, &myData[0].y, &myData[0].mass, &myData[1].x, &myData[1].y, &myData[1].mass, &myData[2].x, &myData[2].y, &myData[2].mass,
				&myData[3].x, &myData[3].y, &myData[3].mass, &myData[4].x, &myData[4].y, &myData[4].mass);
			fclose(fp);
		}
		break;
		default:
		{
			printf("ERROR, maximum number of the bodies is %d. Application will be terminated!", &MAX_BODIES_NUMBER);
			scanf("%d", &i);
			exit(-1);
		}
		break;
	}
}