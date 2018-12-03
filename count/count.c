#include "count.h"


int main(int argc, char** argv){
	FILE* file = NULL;
	char hex[16];
	int num;
	int count = 0;
	if (argc!= 2){
		printf("error\n");
		exit(0);
	}
	
	file = fopen(argv[1], "r");
	
	if (file == NULL){
		printf("error\n");
		exit(0);
	}
	
	node *hashTable[1000];
	int i = 0;
	for (i =0; i <1000;i++){
		hashTable[i] = NULL;
	}

	while(fscanf(file, "%s \n", hex) != EOF){
		int key;
		num = (int)strtol(hex, NULL, 0);	//converts to decimal
		key = (num % 999);
		///printf("%d\n", num);
		if (key < 0)
			key = -(key);
		if (hashTable[key] == NULL){
			node* insert = (node*)malloc(sizeof(node));
			insert->data = num;
			insert->next = NULL;
			hashTable[key] = insert;
			count++;
		}
		else if (hashTable[key] != NULL){
			if (hashTable[key]->data == num){	//if first value in hashtable = the input
				continue;
			}
			else {
				
				
				node* tmp = hashTable[key];
				node* prev = tmp;
				tmp = tmp->next;
				while (tmp != NULL){
					if (tmp->data == num){
						break;
					} 
					prev = tmp;
					tmp = tmp->next;
				}
				if (tmp == NULL){
					node* insert = (node*)malloc(sizeof(node));
					insert->data = num;
					insert->next = NULL;
					prev->next = insert;
					count++;
				}
			}
			
		}
		//printf("%d\n", key);	
		//printf("%s\n", &hex);
		
	}
	fclose(file);
	
	printf("%d\n", count);
	return 0;
}
