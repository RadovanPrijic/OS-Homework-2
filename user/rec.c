#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	int res;

	if(argc < 2){
		printf("Nije naveden parametar na komandnoj liniji.\n");
		exit();
	}
	else{
		res = rec(argv[1]);
		if(res == 0){
			printf("Uspesan oporavak.\n");
			exit();
		}
		if(res == -1){
			printf("Roditeljski direktorijum za navedenu datoteku nije validan.\n");
			exit();
		}
		if(res == -2){
			printf("Ne postoji obrisana datoteka sa navedenim nazivom.\n");
			exit();
		}
		if(res == -3){
			printf("Inode datoteke je iskoriscen za nesto drugo.\n");
			exit();
		}
		if(res == -4){
			printf("Neki blok datoteke je iskoriscen za nesto drugo.\n");
			exit();
		}
	}
}