#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char** parse_args(char *line) {
	char **arg_array = malloc(64*sizeof(char*));
	printf("hi");
	
	if (!strchr(line, ' ')) {
		printf("no space");
		*(arg_array) = line;
		*(arg_array) = 0;
		return arg_array;
	}
	
	int index = 0;
	
	*(arg_array + (index++) ) = strsep(&line, " ");
	printf("%s\n", line);

	while(line) {
		*(arg_array + (index++) ) = strsep(&line, " ");
	}
	
	*(arg_array + (index) ) = 0;
	
	return arg_array;
}

int main() {
	char line[] = "ps -aux";
	char **args = parse_args(line);
	
	int test = 0;
	
	while (*(args+test)) {
		printf("%s\n", *(args+test));
		test++;
	}
	
	execvp(args[0], args);
	
	return 0;
}
