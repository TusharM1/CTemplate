#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int main(int argc, char* argv[]) {
	printf("Client %d\n", commands());
	return EXIT_SUCCESS;
}
