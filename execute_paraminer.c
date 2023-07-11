#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

long get_mem_usage() {

	struct rusage myusage;
	
	getrusage(RUSAGE_SELF, &myusage);
	return myusage.ru_maxrss;
}

int main(int argc, char *argv[]){
	
	long mem = get_mem_usage();
	float times_without_cond[90];
	float times_with_cond[90];
	int time1 = 0, time2 = 0;
	FILE *fiche;
	fiche = fopen("new_datTestTime.txt", "a");
	//fiche = fopen("deschet_test.txt", "a");
	if(argv[1]){
		
		printf("%s\n", argv[1]);

	}
	else{

		printf("Il faut specifier le dataset, nous somme par defaut dans le dossier data/...\n");
		printf("veillez reesayer en specifiant le dataset Merci!\n");
		return 0;

	}


	if(!argv[2]){

		printf("Vous devez specifier le minsup\n");
		printf("Veillez reesayer en specifiant le minsup Merci!\n");
		return 0;

	}
	else{

		printf("%s\n", argv[2]);
		int x = atoi(argv[2]);
		printf("%d", x+1);
		//return 0;

	}
	
	if(argv[2] && argv[1]){
	    for(int i = 1; i<=37; i++){
		char code[50] = "paraminer_graduals data/gri/";
		
		strcat(code,argv[1]);
		strcat(code," ");
		int x = atoi(argv[2]);
		x = x + i;
		char str[5];
		sprintf(str, "%d", x);
		strcat(code,str);
		printf("%s\n", code);
		
		time1 = clock();
		//printf("consommation 1 : %ld\n", get_mem_usage());
		system((char *)code);
		time2 = clock();
		times_with_cond[i] = (float)((float)(time2 - time1)/600.0);
		
		time1=0;
		time2=0;
		//sleep(2);
		time1 = clock();
		strcat(code, " -t 1");
		//printf("consommation 2 : %ld\n", get_mem_usage());
		system((char *)code);
		time2 = clock();
		times_without_cond[i] = (float)((float)(time2 - time1)/600.0);
	
		
		
		
	    }
	}
	
	
	fprintf(fiche,"\n");
	fprintf(fiche, "without cond: ");
	for(int i = 0; i<=89; i++){
		fprintf(fiche,"%f,", times_without_cond[i]);
	}
	fprintf(fiche,"\n");
	fprintf(fiche, "with cond: ");
	for(int i = 0; i<=89; i++){
		
		fprintf(fiche,"%f,", times_with_cond[i]);
	}
	//printf("%ld", mem);
	
	printf("\n");
fclose(fiche);	

}
