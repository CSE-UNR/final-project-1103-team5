// Group: 1103-Team5
// Member: Kenneth Matthews
// Member: Keeley Qualls
// Member: Brandon Khamsopha
// Madlib Project


#include <stdio.h>

#define SIZE 100

int readFile(FILE* file_ptr, int Rows, int Cols, char stringArray[][SIZE]);
void getUserInput(int func_index, char answerArray[], int Cols, char stringArray[][SIZE]);
void new_line_remove(int counter, int Cols, char stringArray[][SIZE]);
void print_string(int counter, int Cols, char stringArray[][SIZE]);
int letter_counnter(int funct_index, int Cols, char stringArray[][SIZE]);
void ANV_determination(int lineCount, char stringArray[][SIZE], char answerArray[]);

int main(int argc, char* argv[]){
	//** Initializations / Declaration **//
	FILE* file_ptr;
	char stringArray[SIZE][SIZE];
	char answerArray[SIZE];
	char ANV_Case;
	int lineCount=0;
	
	
	
	    
	    
	//** Open the file in read mode **//
	if ((file_ptr = fopen(argv[1], "r")) == NULL){
		// check if file exists
		printf("Error: Could not open file.\n");
		return 0;
	}


	//** Read lines into stringArray and count them **//
	lineCount = readFile(file_ptr, SIZE, SIZE, stringArray);

	//** close file **//
	fclose(file_ptr);

	ANV_determination(lineCount, stringArray, answerArray);
	printf("\n");

	//** remove all new lines from array **// 
	new_line_remove(lineCount, SIZE, stringArray);

	//** Print the final output **//
	print_string(lineCount, SIZE, stringArray);
	return 0;
}

//** Functions **//

int readFile(FILE* file_ptr, int Rows, int Cols, char stringArray[][SIZE]){
	int Count=0;
	// Get Line into the array 
	for (int index=0; index < Rows; index++) {
		// this uses fgets and checks for null at the same time
		if (fgets(stringArray[index], Cols, file_ptr) == NULL) 
		{
		    break; 
		}
		// count the lines read to tell us how many ROWS were used
		Count++;
	}
	return Count;
}


void getUserInput(int func_index, char answerArray[], int Cols, char stringArray[][SIZE]){
    // get the input from user
    fgets(answerArray, Cols, stdin);


    // copying it into main string array
    for(int index =0; index < Cols; index++)
    {
        if(answerArray[index] == '\0')
            {
               stringArray[func_index][index] = '\0';
               break;
            }

        stringArray[func_index][index] = answerArray[index]; 
    }

}



void new_line_remove(int counter, int Cols, char stringArray[][SIZE])
{

    // replacing all new lines with null so it wount go to the new line
    for(int index = 0; index < counter; index++){
        for(int index2 = 0; index < SIZE; index2++){
            if(stringArray[index][index2]== '\0'){
                    break;
            }else if(stringArray[index][index2] == '\n'){
                    stringArray[index][index2] = '\0';
                    break;
            }
        }
    }
}

void print_string(int counter, int Cols, char stringArray[][SIZE]){
    for (int index = 0; index < counter; index++) {
        // use +1 to look to the next line for the decision statement reguarding puntions spaces 
        if(stringArray[index+1][0] == '.' || stringArray[index+1][0] == ',' || stringArray[index+1][0] == '!'|| stringArray[index+1][0] == '?'){
            for(int index2 = 0; index2< Cols; index2++){
                 printf("%c", stringArray[index][index2]);
            
            }
        }else{
            for(int index2 = 0; index2< Cols; index2++){
                 printf("%c", stringArray[index][index2]); 
            }
            // space after printed string
            printf(" ");
        }    
    }
    printf("\n");
}


int letter_counnter(int funct_index, int Cols, char stringArray[][SIZE]){
        int counter=0;
        while(stringArray[funct_index][counter] != '\0'){
            counter++;
        }

        return counter;
}

void ANV_determination(int lineCount, char stringArray[][SIZE],char answerArray[]){
	int letterCount=0;

	 //** Switch Statment based of single letter lines **//
	for(int index = 0; index < lineCount; index++ ){
		
        //** Count How Many letters in each line for switch **//
        letterCount = letter_counnter(index, SIZE, stringArray);

        //** if those lines have one letter use switch use 2 to include \n character **//
        if(letterCount==2)
        {
            switch(stringArray[index][0])
            {
             case 'A':
                printf("Please enter an adjective: ");
                getUserInput(index, answerArray, SIZE, stringArray);
                break;

             case 'N':
                printf("Please Enter a Noun: ");
                getUserInput(index, answerArray, SIZE, stringArray);
                break;

             case'V':
                printf("Plese enter a verb: ");
                getUserInput(index, answerArray, SIZE, stringArray);
                break;
            }
        }

    }

}

