#include <time.h>

void sendTimeToClient(int clientSocketFD){
	time_t rawtime;
  	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char buffer[256];
	read(clientSocketFD, buffer, sizeof(buffer));
	sprintf(buffer, "The Time is %s", asctime(timeinfo));
	write(clientSocketFD, buffer, sizeof(buffer));
}

void PerformServerTask(int sockfd){
	int newsockfd, client_len, result;
	struct sockaddr_in client_address;
	fd_set masterfds, copyfds;

	//initialize the master fd set
	FD_ZERO(&masterfds);

	//add the listening fd to master, this is the server file descriptor
	FD_SET(sockfd, &masterfds);

	//Now wait for client and requests. Because you have passed a null pointer as the timeout
	//parameter, no timout will occur. The program will exit and report an error if select returns
	//a value less than 1

	while(1){
		char ch[256];
		int nread;

		//copy the master fd set
		copyfds = masterfds;
		//select function provides syncrhronous IO
		//every time we call select it destroys the fd set, thats why we copy it and use it
		result = select(FD_SETSIZE, &copyfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
		//after this time test result. If there has been an error the program exists
		if(result<1){
			perror("Server Error");
			exit(1);
		}
		//once you know you;ve got activity, you can find which descriptor its on by checking
		//each in turn using FD_ISSET
		for (int fd = 0; fd < FD_SETSIZE; fd++)
		{
			if (FD_ISSET(fd, &copyfds))
			{
				if (fd == sockfd)
				{
					//accept new connection
					//add the new connection to the list of connected clients

					client_len = sizeof(client_address);
					newsockfd = accept(sockfd, (struct sockaddr *)&client_address, &client_len);
					//important part to select and multiple clients

					//save new client sockfd to master set
					FD_SET(newsockfd, &masterfds);
					printf("Adding client with fd- %d\n", newsockfd);
				}

				//if it isnt the server, it must be client activity
				//if close is received, the client has gone away
				//and you remove it from the descriptor set.
				//other wise you serve the client 
				//ass in the previous examples
				else{
					ioctl(fd, FIONREAD, &nread);
					//input/output control is a system call for device-specific input/output operations
					if(nread == 0){
						//drop the client and remove it from the set
						close(fd);
						FD_CLR(fd, &masterfds);
						printf("removing client from fd %d\n", fd);
					}else{
						sendTimeToClient(fd);
					}
				}
			}
		}
	}
}

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
	return 0;
}
