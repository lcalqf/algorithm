
/*
author : ez
date : 2015/7/11
describe : Convert IP string into IP numeric
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#pragma warning(disable:4996)
/* ip 字符串合法性由调用者保证 */
unsigned int ip_str2int(const char* ip)
{
	unsigned int re = 0;
	unsigned char tmp = 0;
	while (1) {
		if (*ip != '\0' && *ip != '.') {
			tmp = tmp * 10 + *ip - '0';
		}
		else 
		{
			re = (re << 8) + tmp;
			if (*ip == '\0')
				break;
			tmp = 0;
		}
		ip++;
	}
	return re;
}

/* str长度合法性由调用者保证 */
void ip_int2str(unsigned int ip, char str[])
{
	unsigned char *val = (unsigned char *)&ip;
	sprintf(str, "%u.%u.%u.%u", val[3], val[2], val[1], val[0]);
}

int main()
{
	char *ip = "192.168.8.10";
	int addr[20];
	unsigned int re=ip_str2int(ip);
	return 0;
}


