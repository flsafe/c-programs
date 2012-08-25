#undef NDEBUG

#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <debug.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) if(!(test)) {log_err(message, NULL); return message; }

#define mu_run_test(test) debug("\n-----%s", " " #test, NULL); \
	message = test(); tests_run++ ; if (message) return message;

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
	char *result = NULL;\
	argc = argc;\
	debug("----- RUNNING: %s", argv[0]);\
		printf("-----\nRUNNING: %s\n", argv[0]);\
	    result = name();\
	    if(result != 0){\
			printf("FAILED: %s\n", result);\
		}\
		else {\
			printf("ALL TESTS PASSED\n");\
		}\
		printf("Tests run: %d\n", tests_run);\
			exit(result != 0);\
}

int tests_run;

#endif
