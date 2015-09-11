#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   card_name[]: buffer-array where result is stored 
*/
void read_card(char card_name[]){
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

/* Changes counter based on value of val variable.

   val: integer where value is stored
   count: integer returned
*/
int counter(int *val, int *count){
	if ((*val>2) && (*val<7)){
		*count = *count + 1;
	} else if (*val == 10){
		*count = *count - 1;
	}
	return *count;
}

/* Checks user's input and adjusts val variable accordingly.

   card_name[]: buffer-array where result is stored
   count: integer passed to counter method 
*/
void choises(char card_name[], int *count){
	while (card_name[0]!='X'){
		int val = 0;
		read_card(card_name);
		switch (card_name[0]){
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if ((val<1) || (val>10)){
					puts("I don't understand that value!");
					continue;
				}
		}
		
		printf("Current count: %i\n", counter(&val, count));
	}
}

/* Main file method */
int main(){
	char card_name[3];
	int count = 0;
	choises(card_name, &count);
	return 0;
} 
