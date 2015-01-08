#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int var = 0;
	int state = 0;
	int next_state = 0;
	while(1) {
		scanf("%d",&var);
		switch(state){
			case 0:
				if(var==9) next_state = 1;
				else next_state = 0;
				break;
			case 1:
				if(var==7) next_state = 2;
				else next_state = 0;
				break;
			case 2:
				if(var==7) next_state = 3;
				else next_state = 0;
				break;
			default:
				next_state = 0;
				break;
		}
		if (next_state==0) break;
		if (next_state==3){
			printf("Hooray");
			break;
		}
		state = next_state;		
	}
}
