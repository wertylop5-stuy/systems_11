#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char** parse_args(char *line) {
	char **arg_array = malloc(64*sizeof(char*));
	
	if (!strchr(line, ' ')) {
		*(arg_array) = line;
		*(arg_array+1) = 0;
		return arg_array;
	}
	
	int index = 0;
	
	//the program to run
	*(arg_array + (index++) ) = strsep(&line, " ");

	//get the args
	while(line) {
		*(arg_array + (index++) ) = strsep(&line, " ");
	}
	
	*(arg_array + (index) ) = 0;
	
	return arg_array;
}

int main() {
	char line[] = "ps -a -ux";
	char **args = parse_args(line);
	
	int test = 0;
	
	while (*(args+test)) {
		printf("component: %s\n", *(args+test));
		test++;
	}
	
	execvp(args[0], args);
	
	return 0;
}
