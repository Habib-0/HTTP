#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
using namespace std;

int main(){

    //AF_NET: ipv4 protocol SOCK_STREAm TCP socket
    int serverSocket= socket(AF_INET, SOCK_STREAM, 0);

    if(serverSocket == -1){
        perror("socket");
        return 1;

    }
    cout <<"socket created\n";
    


    //definig the server adress
    //htons() converts port to network byte order
    //INADDR_ANY accept connection on any ip
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
    //listen for the incoming connection
    listen(serverSocket,5);

    //accept the client connection
    int clientSocket = accept(serverSocket,nullptr,nullptr);
    
    //Recive data from client
    char buffer[1024]= {0};
    recv(clientSocket,buffer,sizeof(buffer),0);

    const char* response= 
  
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: 12\r\n"
    "Connection: close\r\n"
    "\r\n"
    "Connection succeded  !";

    send(clientSocket,response,strlen(response),0);






    cout<< "Massage from client:"<<buffer<<endl;

    //close the servrsocket
    close(serverSocket);

     


}
