#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int main(int argc, char* argv[]) {
	int command = commands();
	printf("Client %d\n", command);
	return EXIT_SUCCESS;
}
