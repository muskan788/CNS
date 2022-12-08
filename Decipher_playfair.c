#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void revMap(int i,int j,int x,int y,char key[5][5],char plain_text[],int idx){
	if(j == y){
			((i-1) % 5 > -1) ? (i = (i-1) % 5) : (i = (i+4) % 5);
		    ((x-1) % 5 > -1) ? (x = (x-1) % 5) : (x = (x+4) % 5);
	}
	
	else if(i == x){
		    ((j-1) % 5 > -1) ? (j = (j-1) % 5) : (j = (j+4) % 5);
		    ((y-1) % 5 > -1) ? (y = (y-1) % 5) : (y = (y+4) % 5);
	}
	
	else{
		int temp = j;
		j = y;
		y = temp;
	}
	plain_text[idx] = key[i][j];
	plain_text[idx+1] = key[x][y];
}

void decipher(char key[5][5],char cipher_text[]){
	char plain_text[1000];
	int n = strlen(cipher_text);
	int c_i;
	for(c_i=0;c_i<n;c_i+=2){
		int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
	    bool mod1 = false,mod2 = false;
	    int i,j;
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(cipher_text[c_i] == key[i][j]){
					x1 = i;
					y1 = j;
					mod1 = true;
				}
                if(cipher_text[c_i + 1] == key[i][j]){
					x2 = i;
					y2 = j;
					mod2 = true;
				}
                if(mod1 && mod2)
                    break;					
			}
		}
		revMap(x1,y1,x2,y2,key,plain_text,c_i);
	}
	plain_text[c_i] = '\0';
	
	printf("\nPlain Texr: %s\n",plain_text);
}
void generateKey(char key[5][5], char plain_text[]){
	char alpha[25] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char K[25];
	int i=0,k=0;
	while(plain_text[i] != '\0'){
		if(plain_text[i] < 'J' && alpha[(plain_text[i]%65)] == '\0')
			i++;
		else if(plain_text[i] > 'J' && plain_text[i] <= 'Z' && alpha[(plain_text[i]%65)-1] == '\0')
			i++;
		else{
			K[k++] = plain_text[i];
			(plain_text[i] < 'J') ? (alpha[(plain_text[i]%65)] = '\0') : (alpha[(plain_text[i]%65)-1] = '\0');
			i++;
		}
	}
	i=0;
	while(k < 26){
		if(alpha[i] == '\0')
			i++;
		else{
			K[k++] = alpha[i];
			alpha[i] = '\0';
			i++;
		}
	}
	//printf("\n%s\n",K);
	k=0;
	int j;
    for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			key[i][j] = K[k++];
		}
	}
}

int main(){
	char cipher_text[1000];
	char key[25];
	
	printf("Enter Cipher Text:\n");
	scanf("%s",cipher_text);
	printf("\nEnter Key:\n");
	scanf("%s",key);	

	char keyMatrix[5][5];
	generateKey(keyMatrix,key);

	
	
	printf("\nKey: \n");
	int k=0,i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c ",keyMatrix[i][j]);
		}
		printf("\n");
	}
	
	
	decipher(keyMatrix,cipher_text);
	
	return 0;
}
