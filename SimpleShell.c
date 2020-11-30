#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void prompt_string(){

static int clear_screen = 1;
if (clear_screen){ //clears the screen
	
	const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J"; //This ANSI function clears the screen
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12); //creates a screen
	clear_screen = 0;
	
	
	

}
		
printf(#); //This displays the prompt

	
	
	
	
	
	
}

void read_command (char command1[], char *parameters[]){ //Reads commands, returns command1 and parameters
	
	char lines [1200];
	
	int count_lines = 0
	int i = 0;
	int j = 0;
	
	char *array12[200];
	char *pch;
	
	//Reads one line
	for(;;){
		
		int c = fgetc(stdin);
		lines[countlines++] = (char) c;
		if(c == '\n') 
		 break;
		
		
	}
	
	if(count_lines == 1) return;
	
	//Breaks lines into tokens
	pch = strtok (lines, "\n");
	
	//parses the lines into words
	while (pch != NULL){
	
	 array[i++] = strdup (pch);
	 pch = strtok (NULL, "\n");
	 
	 }
	
	//The first word is the command1
	strcpy (command1, array12[0]);
	
	for(int j = 0; j < i; j++){
		parameters[j] = array12[j];
		parameters[j] = NULL; //NULL-terminates the parameter list
		
	}
	
}

int main(){
	
	char command1[100]; //1st array to hold commands
	char command2[100]; //2nd array to hold commands
	char *parameters[20]; //array to hold parameters
	
	//Environment variables, (Assume that the commands are in the directory named bin)
	char *envp[] = {(char *) "PATH=/bin", 0};
	
	while(1){
		
		prompt_string(); //Shows the prompt on the screen
		read_command (command1, parameters); //reads the command and parameters
		
		if(fork()!= 0) //Parent Process
		 wait(NULL); //Waits for child process
		 
		else{
			
			strcpy (command1, "/bin/"); //copies the bin directory into command1
			strcat (command1, command2); //concatenates command1 and command2
			execv (command1, parameters, envp); //executes the command
			
		}
		
		if(strcmp (command1, "exit") == 0)
		  break; //If the command is "exit" then it will break
		  
		  
		
	}
	
	return 0;
	
	
	
	
	
	
	
	
	
	
}




