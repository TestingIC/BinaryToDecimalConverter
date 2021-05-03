#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main () {
	bool input_is_binary = false;

	const int maximum_input_length = 10;
	char input[maximum_input_length];

	while (input_is_binary == false) {
		printf("Quick note: Please don't enter more than %d digit(s) as I can't figure out how to avoid a buffer overflow error.\n", maximum_input_length - 2);
		printf("Decimal to convert to binary: ");

		fgets(input, maximum_input_length, stdin);	

		if ((int)input[maximum_input_length-2] != 10 && (int)input[maximum_input_length-2] != 0) {
			printf("%d", (int)input[maximum_input_length-2]);
			printf("More than %d digit(s) were entered! Exiting\n", maximum_input_length - 2);
			exit(0);
		}

		for (int location_in_input = 0; location_in_input < maximum_input_length; location_in_input++) {
			int character_as_integer = input[location_in_input];
			if (character_as_integer > 47 && character_as_integer < 50) {
				input_is_binary = true;
			}
			else if ((character_as_integer >= 2 && character_as_integer <= 9) || (character_as_integer >= 11 && character_as_integer <= 47) || (character_as_integer >= 50)) {
				printf("Please only put 1s and 0s!\n");
				input_is_binary = false;
			}
		}
	}

	input[strlen(input) - 1] = '\0';
	
	int result = 0;
	int power = maximum_input_length - 3;
	
	for (int location_in_input = 0; location_in_input <= maximum_input_length - 2; location_in_input++) {
		int character_as_integer = input[location_in_input];
		if (character_as_integer == 49) {
			result += pow(2, power);
		}
		power--;
	}

	printf("In binary, %s is: %d\n", input, result);

	return 0;
}
