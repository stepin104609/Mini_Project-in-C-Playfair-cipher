#include "Header.h"
#include<stdio.h>
#define size 100
#define ksize 30

void decplainedit(char plain[]){
	int x=0;
	for(int i=0;plain[i]!='\0';i++){
			//putting an 'x' between the 2 similar occuring letters
			if(plain[i]=='x'){
				if(plain[i+1]=='\0')
					plain[i]='\0';
				else if(plain[i-1]==plain[i+1])
					for(int j=i;plain[j]!=0;j++)
						plain[j]=plain[j+1];
			}
			x++;
		}
}

void plainedit(char plain[]){
	char newplain[size];
	int x=0;
	for(int i=0;plain[i]!='\0';i++){
		//if there is an i or j in the string, ireplaced by j letter
		if(plain[i]==105||plain[i]==106)
			plain[i]=106;

		if(plain[i]!=32){
			newplain[x]=plain[i];
			x++;
		}
	}
	newplain[x]='\0';
	for(int i=0;newplain[i]!='\0';i=i+2){
		// putting an 'x' between the 2 similar letters
		if(newplain[i]==newplain[i+1]){
			for(int j=x;j>i;j--)
				newplain[j+1]=newplain[j];
			newplain[i+1]='x';
			x++;
		}
	}
	//if the number of plain letters is odd, it adds an 'x' to the end
	if(x%2!=0){
			newplain[x]='x';
			x++;
		}
	newplain[x]='\0';
	//copies the string newplain to the string plain
	for(int i=0;newplain[i]!='\0';i++)
		plain[i]=newplain[i];
	plain[x]='\0';
}

/* putting the key and alphabets in the matrix*/

void matrixx(char key[],char cmatrix[5][6]){
			int z=0;
			for(int x=0;x<5;x++){
				for(int y=0;y<6;y++){
					//at the end of any string, there must be a '\0' operator to
					//indicate the end of the string
					if(y==5)
						cmatrix[x][y]='\0';
					else {
						//Enters the characters into the 2D array
						if(key[z]!='\0'){
							cmatrix[x][y]=key[z];
							z++;
						}
					}
				}
			}
}

/*making the key distinct and adding the rest of the alphabets to it*/

void makedistinct(char key[]){
		char newkey[ksize];
		char n=0;
		int x=0;
		//Get a char and compare it to the rest of the string
		for(int i=0;key[i]!='\0';i++){
			char current=key[i];
			//if there is an i or j in the string, it's replaced by a j letter
			if(current==105||current==106)
				current=106;
			for(int m=0;key[m]!='\0';m++){
				//checks if character exists in another position in the entered string (key)
				if(current==key[m]&&m!=i)
					//if it's, a flag is changed
					n=1;
			}
			//if the character isn't found, it's added to the string newkey
			if(n==0){
				newkey[x]=current;
				x++;
			}
			else{
				//if the character is found in the entered string, it checks whether
				//it's in the string newkey or not
				char xyz=0;
				for(int j=0;j<x;j++)
					if(current==newkey[j])
						xyz=1;
				//if the character isn't is the string newkey, it's added to it
				if(xyz==0){
					newkey[x]=current;
					x++;
				}
				//sets the flag to 0 again
				n=0;
			}
		}
		// adding the rest of the alphabets to the string newkey
		char b=97;
		char bool;
		while(b<123){
			bool=0;
			if(b==105||b==106)
				b=106;
			//checks if the character b in the string newkey
			for(int j=0;j<x;j++)
				if(b==newkey[j])
					bool=1;
			//if it's not found ,it's added to the string
			if(bool==0){
				newkey[x]=b;
				b++;
				x++;
			}
			else{
				b++;
			}
		}
		newkey[x]='\0';
		//copy the string newkey to the string key
		for(int i=0;newkey[i]!='\0';i++)
			key[i]=newkey[i];
		key[x]=newkey[x];
}

// cipher Decryption function

void decrypt(char cipher[],char cmatrix[5][6]){
	char plain[size];
	int a,b,c,d,x;
	for(int i=0;cipher[i]!='\0';i=i+2){
		for(int n=0;n<5;n++)
			for(int m=0;m<5;m++){
				if(cipher[i]==cmatrix[n][m]){
					a=n;
					b=m;
				}
				if(cipher[i+1]==cmatrix[n][m]){
					c=n;
					d=m;
				}
			}

		if(a==c){
			if(b>0)
				b--;
			else
				b=4;
			if(d>0)
				d--;
			else
				d=4;
		}
		//if the 2 letters in the same column, each letter is moved up by 1
		//if one of the letters is already at the top of the column, then we have
		//the last one of the column
		else if(b==d){
			if(a>0)
				a--;
			else
				a=4;
			if(c>0)
				c--;
			else
				c=4;
		}
		//if it forms a rectangular, we swap the letters with the ones in each corner
		//of the rectangular(each letter must be swapped with the one in its row)
		else{
			int temp=d;
			d=b;
			b=temp;
		}
		plain[i]=cmatrix[a][b];
		plain[i+1]=cmatrix[c][d];
		x=i+2;
	}
	plain[x]='\0';
	decplainedit(plain);
	puts("PlainText is:");
	puts(plain);
}

//Encryption or ciphering function

void playfair(char plain[],char cmatrix[5][6]){
	char cipher[size];
	int a,b,c,d,x;
	for(int i=0;plain[i]!='\0';i=i+2){

			for(int n=0;n<5;n++)
			for(int m=0;m<5;m++){
				if(plain[i]==cmatrix[n][m]){
					a=n;
					b=m;
				}
				if(plain[i+1]==cmatrix[n][m]){
					c=n;
					d=m;
				}
			}
		//if the 2 letters in the same row, each letter is moved right by 1
		//if one of the letters is already at the rightmost position of the row, then we have
		//the leftmost of the row
		if(a==c){
			if(b<4)
				b++;
			else
				b=0;
			if(d<4)
				d++;
			else
				d=0;
		}

		else if(b==d){
			if(a<4)
				a++;
			else
				a=0;
			if(c<4)
				c++;
			else
				c=0;
		}
		//if it forms a rectangular, we swap the letters with the ones in each corner
		//of the rectangular(each letter must be swapped with the one in its row)
		else{
			int temp=d;
			d=b;
			b=temp;
		}
		cipher[i]=cmatrix[a][b];
		cipher[i+1]=cmatrix[c][d];
		x=i+2;
	}
	cipher[x]='\0';
	puts("CipherText is:");
	puts(cipher);
}



