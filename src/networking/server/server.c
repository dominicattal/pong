#include "server.h"
#include <winsock2.h>
#include <pthread.h>
#include <stdio.h>

#define DEFAULT_PORT "27015"

static pthread_t thread_id;

static void *server(void* vargp) {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char *message, client_reply[2000];
    int recv_size;

    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code: %d", WSAGetLastError());
        exit(1);
    }

    printf("Winsock initialized.\n");

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code: %d", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }
    printf("Bind done.\n");

    // Listen to incoming connections
    listen(server_socket, 3);

    printf("Waiting for incoming connections...\n");

    c = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET) {
        printf("Accept failed with error code: %d", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }
    printf("Connection accepted.\n");

    // Receive a message from client
    if ((recv_size = recv(client_socket, client_reply, 2000, 0)) == SOCKET_ERROR) {
        printf("recv failed with error code: %d", WSAGetLastError());
        closesocket(client_socket);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    // Add a null terminator to make it a proper string
    client_reply[recv_size] = '\0';
    printf("Client message received: %s\n", client_reply);

    // Send a reply to the client
    message = "Hello Client, I have received your message.";
    send(client_socket, message, strlen(message), 0);

    // Cleanup
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
}

void server_start(void) {
    pthread_create(&thread_id, NULL, &server, NULL);
}