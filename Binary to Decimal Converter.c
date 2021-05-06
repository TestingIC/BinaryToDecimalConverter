#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main () {
	system("clear");

	const int maximum_input_length = 20;

	printf("Hello! This program converts any binary into base 10. To exit the program, type exit when it is asking for binary.\n");

	while (true) {
		printf("Binary to convert: ");

		char input[maximum_input_length] = {'\0'};
		fgets(input, maximum_input_length, stdin);

		//Checks to see if '\n' is in the input. Used to make sure user doesn't step over maximum_input_length
		char *contains_newline = strstr(input, "\n");	

		//Exit if the maximum_input_length is exceeded
		if (contains_newline == NULL) {
			printf("The maximum number of characters has been exceeded, aborting.\n");
			exit(0);
		}

		//Exit if the user types in exit
		if (strstr(input, "exit") != NULL) {
			printf("Exiting!\n");
			exit(0);
		}

		int reformated_input_length = 0;

		for (int location_in_input = 0; location_in_input < maximum_input_length; location_in_input++) {
			char character = input[location_in_input];

			if (character == '0' || character == '1') {
				reformated_input_length += 1;
			}
		}

		//Exit if there are no 1s or 0s
		if (reformated_input_length == 0) {
			printf("There are no 0s or 1s! Please try again.\n");
		}
		else {
			//Add 1 space for the '\n'
			char reformated_input[reformated_input_length];

			//Create the reformated string
			int indepent_incrementer = 0;
			for (int location_in_input = 0; location_in_input < maximum_input_length; location_in_input++) {
				char character = input[location_in_input];

				if (character == '0' || character == '1') {
					reformated_input[indepent_incrementer] = character;
					indepent_incrementer += 1;
				}
			}

			reformated_input[reformated_input_length] = '\0';

			int result = 0;
			indepent_incrementer = 0;
			for (int power = reformated_input_length - 1; power >= 0; power--) {
				if (reformated_input[indepent_incrementer] == '1') {
					result += pow(2, power);
				}
				indepent_incrementer += 1;
			}

			printf("%s in base 10 is %d.\n", reformated_input, result);
		}
	}

	return 0;
}
