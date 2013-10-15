#ifndef  __CONFIRM_HPP__
#define  __CONFIRM_HPP__

/**
 * @file confirm.hpp
 * @brief 用于服务器的验证工作。
 * @author sxkj5
 * @version 1.0
 * @date 2013-06-06
 */

#ifndef  CONFIRM_SERVER_IP
		//#define  CONFIRM_SERVER_IP "192.168.0.254"
		#define  CONFIRM_SERVER_IP "222.186.50.76"
#endif

#ifndef  CONFIRM_SERVER_PORT
#define  CONFIRM_SERVER_PORT  4231
#endif

#ifndef  CONFIRM_USERNAME_LEN
#define  CONFIRM_USERNAME_LEN  (1<<6)
#endif

#ifndef  CONFIRM_PASSWD_LEN
#define  CONFIRM_PASSWD_LEN  (1<<6)
#endif

#ifndef  CONFIRM_SUCCESS
#define  CONFIRM_SUCCESS  (1)
#endif

#include "Config.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class Confirm
{
public :
	Confirm() : confirm_flag()
	{
		cfd = socket(AF_INET, SOCK_STREAM, 0);
        if (cfd < 0)
        {
            printf ("[AUTH]: error socket\n");
            exit (-1);
        }
		//assert(-1 != cfd);

		struct sockaddr_in ci = {0};
		ci.sin_family = AF_INET;
		ci.sin_port = htons(CONFIRM_SERVER_PORT);
		ci.sin_addr.s_addr = inet_addr(CONFIRM_SERVER_IP);
		//assert(-1 != connect(cfd, (struct sockaddr*)&ci, sizeof ci));
        if (connect (cfd, (struct sockaddr*)&ci, sizeof (ci)) == -1)
        {
            printf ("[AUTH]: error connect\n");
            exit (-1);
        }
		memcpy(buf, CONFIG->username.c_str(), CONFIRM_USERNAME_LEN);
		memcpy(buf+CONFIRM_USERNAME_LEN, CONFIG->passwd.c_str(), CONFIRM_PASSWD_LEN);

	}

	~Confirm()
	{
		close(cfd);
	}

	void send_data()
	{
		int bytes_left = CONFIRM_USERNAME_LEN + CONFIRM_PASSWD_LEN;
		int written_bytes = 0;
		char* ptr = buf;
		while (bytes_left > 0)
		{
			written_bytes = send (cfd, ptr, bytes_left, 0);
			if (written_bytes <= 0)
			{
				if (errno == EINTR)
				{
					if (written_bytes < 0)
					{
						written_bytes = 0;
						cout << "EINTR......" << endl;
						continue;
					}
				}
				else if (errno == EAGAIN)
				{
					if (written_bytes < 0)
					{
						written_bytes = 0;
						usleep (50);
						cout << "EAGAIN......" << endl;
						continue;
					}
				}
				else
				{
					break;
				}
			}
			bytes_left -= written_bytes;
			ptr += written_bytes;
		}
	}

	void recv_data()
	{
        time_t old_time = time (NULL);
		for (;;)
		{
			int nrecv = recv(cfd, &confirm_flag, sizeof(confirm_flag), 0);

			assert(-1 != nrecv);
            if (nrecv == 0)
            {
                if (time(NULL) - old_time >= 15) {
                    printf ("out\n");
                    exit (-1);
                }
            }

			if (0 != nrecv)
			{
#ifdef  ___DEBUG
				cout << "confirm.hpp : confirm_flag = " << confirm_flag << endl;
#endif
				break;
			}
		}
	}

	bool confirm()
	{
		send_data();
		recv_data();
		return (CONFIRM_SUCCESS == confirm_flag);
	}
private :
	int confirm_flag;
	int cfd;
	char buf[CONFIRM_USERNAME_LEN + CONFIRM_PASSWD_LEN];
};

#endif  // __CONFIRM_HPP__
