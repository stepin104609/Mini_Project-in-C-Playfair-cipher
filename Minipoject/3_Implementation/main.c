#inclue<Header.h>
#include<stdio.h>
#define size 100
#define ksize 30

//mian function
int main(){
		setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);
		char inp;
		puts("Please enter E for encryption and D for decryption: ");
		gets(&inp);
		if(inp==69||inp==101){
			char plain[size],key[ksize];
			//Get the original text and the text
			puts("Enter the plain text: ");
			gets(plain);
			puts("Enter the key: ");
			gets(key);

			makedistinct(key);
			char cmatrix[5][6]={0};
			//calling matrix function
			matrixx(key,cmatrix);
			plainedit(plain);
			//call the ciphering function
			playfair(plain,cmatrix);
		}
		else if(inp==68||inp==100){
			char cipher[size],key[ksize];
			puts("Enter the cipher text: \n");
			gets(cipher);
			puts("Enter the key: \n");
			gets(key);
			makedistinct(key);
			char cmatrix[5][6]={0};
			matrixx(key,cmatrix);
			//calling decryption function
			decrypt(cipher,cmatrix);
		}
		else
			puts("ERROR You have entered a wrong character");
		return 0;
}
