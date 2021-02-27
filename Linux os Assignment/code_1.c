
#include <fcntl.h> 

int main() 
{ 
 int file_1,file_2 ; 
 char c[100];

 //char *c = (char *) calloc(100, sizeof(char)); 
 
 file_1 = open("filename.txt", O_RDONLY); 

 if (file_1 < 0) 
 { 
      perror("ERROR :"); 
      exit(0); 
 }
 
 file_2 = read(file_1, c, 100); 

 c[file_2] = '\0'; 


 printf("Copied Data: % s\n", c); 
 
   int fd1 = open("Newfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
   
  

   printf("file created\n");

  write(fd1,c,strlen(c));

  printf("data written\n");
 
 //close(file_1);
}      
