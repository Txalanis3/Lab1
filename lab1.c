#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool delim_char(char c, char delim){
	if(c == delim || c == '\0'){
		return true;
	}else{
		return false;
	}
}

bool non_delim_char(char c, char delim){
	if(c != delim || c != '\0'){
		return true;
	}else{
		return false;
	}
}

//,,,,,,hello,,,,,world
char *word_start(char* str, char delim){
	while(delim_char(*str, delim)){
		str++;
	}
	return str;
}

char *end_word(char* str, char delim){
	while(!delim_char(*str, delim)){
		str++;
		if(*str == '\0'){
			return str;
		}
	}
	return str;
}

//,,,,hello,,,world
//str -> ,
//STR = WORD-start(STR)
//int i = 0
int count_tokens(char* str, char delim){
	int count = 0;
	while(*str != '\0'){
		str = word_start(str, delim);
		str = end_word(str, delim);
		count += 1;
	}
	return count;
}

char *copy_str(char *inStr, short len, char delim){
	char *copy = malloc((len+1)*sizeof(char));
	int i = 0;

	for(i = 0; i < len; i++){
		copy[i] = inStr[i];
	}

	copy[i] = '\0';
	return copy;
}

char** tokenize(char* str, char delim){
	int num_tokens = count_tokens(str, delim);
	char **tokens = (char**)malloc((num_tokens+1)*sizeof(char*));
	char *start;	//start = word_start(str)
	char *end;	//end = end_word(str)
	int i;
	char **t = tokens;

	for(i = 0; i < num_tokens; i++){
		str = word_start(str, delim);
		end = end_word(str, delim);
		*t = copy_str(str,(end - str),delim);
		str = end;
		t++;
	}
	tokens[i] = '\0';
	return tokens;
}

//print all tokens
void print_all_tokens(char** tokens){
	int i;
	for(i = 0; tokens[i] != 0; i++){
		printf("\nTokens[%d]: %s\n", i, tokens[i]);
	}
}

int main(){
	char input[] = ",,,Hello,,,World,,,!";
	char *pinput = input;
	char deli = ',';

	char *x = word_start(pinput, deli);
	printf("The first letter is: %c\n", *x);
	x = end_word(pinput, deli);
	printf("The delimeter is: %c\n", *x);
	char** return_str = tokenize(pinput, deli);

	int i = 0;
	while(return_str[i] != NULL){
		printf("%s\n", return_str[i]);
		i++;
	}
	return 0;
}
