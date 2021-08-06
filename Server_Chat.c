#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define PORT 4000

int main(){
 
     
     int SOCKSOCK ;
     int NewSock ;
     char buffer[1024];
     char buffer2[1024];

     socklen_t addr_size;
     struct sockaddr_in IP_bind;
     struct sockaddr_in IP_connect; 
     
     SOCKSOCK = socket(AF_INET,SOCK_STREAM,0);
     printf("[+]Server Socket Created Sucessfully.\n");
     IP_connect.sin_family= AF_INET;
     IP_connect.sin_port = htons(PORT);
     IP_connect.sin_addr.s_addr = INADDR_ANY;

     
     if (bind(SOCKSOCK,(struct sockaddr*)&IP_connect,sizeof(IP_connect))> -1){
       printf("[+]Bind Connection done\n" );             
     }
     else{
           printf("[+]Server Socket Error Connect.\n");
           return 0;
     }
     listen(SOCKSOCK, 5);
     addr_size = sizeof(IP_bind);
     NewSock = accept(SOCKSOCK,(struct sockaddr*)&IP_bind,&addr_size);
     printf("[+]Server Socket Listen in port %d\n[*]Server>\n",PORT) ;
     while (1){   
          bzero(buffer,1024);
          read(NewSock,buffer,sizeof(buffer));
          printf("[*]Clinet> %s",buffer);
          bzero(buffer2,1024);
          fgets(buffer2 ,1024,stdin); 
          printf("[*]Server> %s",buffer2);          
          write(NewSock,buffer2,strlen(buffer2));
              
     }
     close(SOCKSOCK); 
     printf("[+]Closing the connection.");

     return 0 ;
}


