#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	char result[64][DIRSIZ+1];
	int i, res;

	if(argc < 2){
		res = lsdel(".", result);
		if(res >= 1){
			for(i = 0; i < res; i++){
				if(result[i] != 0)
					printf("%s\n", result[i]);
			}
			exit();
		}
		if(res == -1){
			printf("Navedena putanja nije validna.\n");
			exit();
		}
		if(res == -2){
			printf("Nema obrisanih datoteka u navedenom direktorijumu.\n");
			exit();
		}

	}
	else{
		res = lsdel(argv[1], result);
		if(res >= 1){
			for(i = 0; i < res; i++){
				if(result[i] != 0)
					printf("%s\n", result[i]);
			}
			exit();
		}
		if(res == -1){
			printf("Navedena putanja nije validna.\n");
			exit();
		}
		if(res == -2){
			printf("Nema obrisanih datoteka u navedenom direktorijumu.\n");
			exit();
		}
	}
}