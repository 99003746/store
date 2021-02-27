#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main( int argc, char *argv[] )

{

int fd;
int nbytes;
int fp;

int ch=0,word=0,line=0,count=0;



fd=open(argv[1],O_RDONLY);

	if(fd<0)

	{

		perror("open");

		exit(1);

	}
   char *buf = (char *) calloc(100, sizeof(char)); 


	nbytes=read(fd,buf,100);

		if(nbytes<0)

	{

		perror("read");

		exit(2);

	}

int i;

for(int i=0; buf[i]!='\0'; i++)

{

ch++;

if(buf[i]== '\t' || buf[i]== ' ')

{

word++;

}

if(buf[i]=='\n')

{

line++;

}

}

   printf("Number of characters = %d\n", ch);

   printf("Number of words = %d\n", word);

   printf("Number of Lines = %d\n", line);
}
 

	    

 

 

 

	

	

/*fp=open("filename.txt",O_WRONLY|O_CREAT, 0666);

	if(fp<0)

	{

		perror("open");

		exit(1);

	}

	write(fp,buf,nbytes);

	close(fd);

	close(fp);

	exit(0);

	} */








/*#include <fcntl.h> 
#include<stdio.h>
int main() 
{ 
 int fd, sz; 
 char *c = (char *) calloc(100, sizeof(char)); 
 
 fd = open("filename.txt", O_RDONLY); 

 if (fd < 0) 
 {
      perror("r1"); exit(1);
 } 
 
 sz = read(fd, c, 100); 
 c[sz] = '\0'; 
 // printf("file data: % s\n", c); 
 int words_count=0,line_count=0,i=0;
 int inword;
 for(i=0;i<strlen(c);i++)
 {
 if(c == ' ' || c == '\t' || c == '\n' || c == '\0')
    {
 if(inword)

        {
 inword=0;
 
 words_count++;
        }
    }
 if(c[i]=='\n')
 line_count++;
 else 
 inword=1;

}
 printf("\ntotal no lines %d\ntotal no of words %d\ntotal no of characters: %d\n",line_count,words_count,i);
 close(fd);
} */