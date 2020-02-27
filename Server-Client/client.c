#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 80

int main() { 
    int socketDescriptor = 0;
    int valread;
    const char* IP = "192.168.2.117";

    //structure for handling internet addresses
    struct sockaddr_in serv_addr; 

    //greetings
    const char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    
    //create socket 
    //socket(domain, type, protocol)
    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("ERROR PROBLEM WITH SOCKET "); 
        return -1; 
    } 
    printf("socket created\n");
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0){ 
        perror("ERROR PROBLEM WITH ADDRESS "); 
        return -1; 
    } 
    printf("Adress converted \n");
   
    if (connect(socketDescriptor, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){ 
        perror("ERROR PROBLEM WITH Connection "); 
        return -1; 
    } 
    printf("connection created\n");

    //sending Client messsage
    send(socketDescriptor , hello , strlen(hello) , 0 ); 

    printf("Client message sent\n");
    
    //reading Server messege 
    valread = read( socketDescriptor , buffer, 1024); 
    
    //output mesage
    printf("%s\n",buffer ); 
    
    return 0; 
} 