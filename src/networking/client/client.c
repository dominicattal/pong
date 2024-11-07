#include "client.h"
#include <winsock2.h>
#include <pthread.h>
#include <stdio.h>

static pthread_t thread_id;

void *client(void* vargp) {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    int recv_size;

    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code: %d", WSAGetLastError());
        exit(1);
    }

    printf("Winsock initialized.\n");

    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
    printf("Socket created.\n");

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error: %d", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        exit(1);
    }
    printf("Connected to server.\n");

    // Send a message to the server
    message = "Hello Server, this is the client.";
    if (send(client_socket, message, strlen(message), 0) < 0) {
        printf("Send failed with error code: %d", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        exit(1);
    }
    printf("Message sent.\n");

    // Receive a reply from the server
    if ((recv_size = recv(client_socket, server_reply, 2000, 0)) == SOCKET_ERROR) {
        printf("recv failed with error code: %d", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        exit(1);
    }

    // Add a null terminator to make it a proper string
    server_reply[recv_size] = '\0';
    printf("Server reply: %s\n", server_reply);

    // Cleanup
    closesocket(client_socket);
    WSACleanup();
}

void client_start(void) {
    pthread_create(&thread_id, NULL, &client, NULL);
}