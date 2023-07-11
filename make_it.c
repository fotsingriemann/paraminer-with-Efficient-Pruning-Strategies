#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>


long get_mem_usage() {

	struct rusage myusage;
	
	getrusage(RUSAGE_SELF, &myusage);
	return myusage.ru_maxrss;
}


int main() {

	printf("usage : %ld\n\n", get_mem_usage());
	printf("usage : %ld\n\n", get_mem_usage());

}

