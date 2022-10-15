
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This functions are used to read or write the contents into the file in character by character manner
//  Fucntion      : FILE *fopen(const char *file_name, const char *mode_of_operation);
//                  fputs(const char *str, FILE *stream);
//  Input         : The method accepts two parameters of character type.
//
//  Description   :  file_name: This is of C string type and accepts the name of the file that is needed to be opened.
//					mode_of_operation: This is also of C string type and refers to the mode of the file access. 
//                  Below are the file access modes for C: 
//					“r” – Searches file. Opens the file for reading only.
//                        If the file is opened successfully fopen() loads it into memory and sets up a pointer which points to the first character in it. 
//                        If the file cannot be opened fopen() returns NULL.
//					“w” – Searches file. If the file exists already, its contents are overwritten.
//                        If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. 
//                        It creates a new file for writing only(no reading).
//					“a” – Searches file. If the file is opened successfully fopen() loads it into memory and sets up a pointer that points to the last character in it.
//                        If the file doesn’t exist, a new file is created. 
//                        Returns NULL, if unable to open the file.
//                        The file is opened only for appending(writing at end of file).
//					“r+” – Searches file. Opens the file for both reading and writing. 
//                         If opened successfully, fopen() loads it into memory and sets up a pointer which points to the first character in it.
//                         Returns NULL, if unable to open the file.
//					“w+” – Searches file. If the file exists, its contents are overwritten. 
//                         If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file.
//                         The difference between w and w+ is that we can also read the file created using w+.
//					“a+” – Searches file. If the file is opened successfully fopen( ) loads it into memory and sets up a pointer which points to the last character in it.
//                         If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. 
//                         The file is opened for reading and appending(writing at end of file).
//					Return Value: The function is used to return a pointer to FILE if the execution succeeds else NULL is returned. 
//
//                  fputs: The C library function int fputs(const char *str, FILE *stream) writes a string to the specified stream up to but not including the null character.
//                  parameters are :
//                  str − This is an array containing the null-terminated sequence of characters to be written.
//                  stream − This is the pointer to a FILE object that identifies the stream where the string is to be written.
//
//                  fclose: It is used to close to file. 
//
//  Date          : 27/06/2021
//  Author        : Pranav Anil Waghmare
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include<stdio.h>

int main()
{

	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	char str[] ="Hello world";
	char ch;
	int i = 0;

	// Open the file in read mode
	fp1 = fopen("file.txt","r");
	if(fp1 == NULL)
	{
		printf("Unable to open file\n");
	}

	// fgetc function read single single character from the file till End of file occur
	printf("File contents are\n");
	while((ch = fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}

	// Close the opened file
	fclose(fp1);

	// Open the file in append mode
	fp2 = fopen("file.txt","a");
	if(fp2 == NULL)
	{
		printf("Unable to open file\n");
	}

	printf("Writing contents into the file\n");
	while(str[i]!= '\0')
	{
		fputc(str[i],fp2);
		// First patrameter :	Character to be write in file
		// Second parameter :	File pointer	
		i++;
	}

	// Close the opened file
	fclose(fp2);

	return 0;
}
