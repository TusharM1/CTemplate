#ifndef STRINGS_H
#define STRINGS_H

typedef struct String {
	int code;
	const char* string;
} String;

String success_S = {0, "Success.\n"};
String unknown_error_S = {1, "Error: Unknown Error.\n"};
String unknown_format_S = {2, "Error: Unknown Format.\n"};

String message_received_S = {0, "Success: Message Received.\n"};
String message_received_F = {0, "Success: Message Received: \"%s\".\n"};

#endif
