/**
 * @file client.c
 * @author "Tushar Mahajan"
 * @date "9 Aug 2020"
 * @brief This is the main file for the client.
 * This file contains all the code exclusive to the client.
 */

#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int function() {
	return 10;
}

/**
 * @brief This is the main function that runs the client.
 * @param argc Command line arguments count
 * @param argv Command line arguments
 * @return int Program status return code
 */
int main(int argc, char* argv[]) {
	printf("Client %d\n", commands());
	return EXIT_SUCCESS;
}
