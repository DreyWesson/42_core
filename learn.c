// Mini_talk
// A project to create a program that outputs the string from the server when the client sends a string to the server
// Manufactured using signal of UNIX
// Implementation method
// When the server is running, print the pid(getpid()) of the server and wait(pause()) to receive a signal using the signal(signal()) function.
// When the client is running, it starts receiving the pid of the server and the message to be sent.
// The client converts the ASCII code value of each character of the message to be sent into binary.
// A signal is sent to the server using the kill(kill()) function for each converted binary number.
// SIGUSR1 signal is regarded as binary 0 and SIGUSR2 signal as 1, and is transmitted to the server at a certain time interval.
// The server cuts the received signal every 8 times(1 byte = 8 bits), receives it in binary, converts it into decimal, and outputs it based on the ASCII code of the character.

// *****************************
// ************Server***********
// *****************************
// main function
// Get the id of the current process using the getpid() function, then print the pid.
// Afterwards, use the signal function to register which function to call when SIGUSR1 or SIGUSR2 signals are received.
// Because the pause function does not terminate the process until a signal comes in and keeps it in a waiting state, while (1) is used to run an infinite loop so that the signal can be continuously received.
// int main(void)
// {
// 	set_data(getpid()); //Initialize storage space to be used for receiving messages
// 	if (g_data.pid == 0)
// 		return(0);
// 	write(1, "pid : ", 6);
// 	write(1, g_data.pid, strlen(g_data.pid)); // Print the pid of the server
// 	write(1, "\n", 1);
// 	free(g_data.pid);
// 	signal(SIGUSR1, sig_usr1); // Execute sig_usr1 when SIGUSR1 signal is received
// 	signal(SIGUSR2, sig_usr2); // Execute sig_usr2 when SIGUSR2 signal is received
// 	while (1)
// 		pause(); // Stop the process from exiting
// 	return(0);
// }
// sig_usr1 function
// Executed when SIGUSR1 signal is received from client
// Considers the signal received from the client as 0 and puts 0 in the place corresponding to the current count among the 8 bits that make up the character.
// After that, the count is increased by 1. At this time, if the count is 8, 1 byte is completed, so a character is output and the count is initialized.
// Also, if the character is '\0', it outputs a new line because all strings have been received.
// void sig_usr1(int signum) // set SIGUSR1 signal to 0
// {
// 	char a;

// 	(void)signum;
// 	g_data.bit[g_data.count] = '0';
// 	//When executed, consider the current number of digits of the character binary number as 0 and put it in
// 	g_data.count++; // increment the number of digits
// 	if (g_data.count == 8) // When filling 8 bits
// 	{
// 		g_data.dec = change_dec(g_data.bit); // convert to decimal
// 		a = (char)g_data.dec;
// 		if (a == '\0') // If it is a character, \0 is the end of the character, so output a line break
// 			write(1, "\n", 1);
// 		else
// 			write(1, &a, 1); // output the completed character
// 		g_data.count = 0; // Initialize the digits to the first
// 	}
// }
// sig_usr2 function
// Executed when SIGUSR2 signal is received from the client
// Considers the signal received from the client as 1 and puts 1 in the place corresponding to the current count among the 8 bits constituting the character.
// After that, the count is increased by 1. At this time, if the count is 8, 1 byte is completed, so a character is output and the count is initialized.
// void sig_usr2(int signum) // SIGUSR2 signal to 1
// {
// 	char a;

// 	(void)signum;
// 	g_data.bit[g_data.count] = '1';
// 	//When executed, consider the current number of digits of the character binary number as 1 and put it in
// 	g_data.count++; // increment the number of digits
// 	if (g_data.count == 8) // When 8 bits are full
// 	{
// 		g_data.dec = change_dec(g_data.bit); // convert to decimal
// 		a = (char)g_data.dec;
// 		write(1, &a, 1); // output the completed character
// 		g_data.count = 0; // Initialize the number of digits
// 	}
// }
// **********************
// ********Client********
// **********************
// int main(int argc, char** argv)
// {
// 	char* str;
// 	char* save;

// 	if (argc != 3) // Check if pid and character were received at startup
// 		return(0);
// 	if (check_str(ft_atoi(argv[1], argv[2]))
// 		// Check if the received pid value is in the normal range or if it consists of numbers
// 		// Check if the received string is composed of ASCII code
// 		return(0);
// 		while (*argv[2])
// 		{
// 			str = change_bin((int)*argv[2]); //convert the current character to binary
// 				if (str == 0)
// 					return(0);
// 				save = str;
// 				while (*str) //repeat a string with binary numbers
// 				{
// 					send_msg(ft_atoi(argv[1]), *str);
// 					// Send 0 or 1 to the server depending on the currently stored binary number
// 					str++;
// 					usleep(200);
// 					// Wait 200 microseconds for the server to receive it because the server may not receive everything if it is sent without stopping.
// 				}
// 			argv[2]++; // to the next character
// 			free(save); // Release the string storage space we just looked at
// 		}
// 	send_end(ft_atoi(argv[1])); // Since everything has been sent, send \0 which means the end
// 	exit(0);
// 	return(0);
// }

// void send_msg(pid_t pid, char a)
// {
// 	if (a == '0') // if 0, send SIGUSR1 signal
// 		kill(pid, SIGUSR1);
// 	else if (a == '1') // If 1, send SIGUSR2 signal
// 		kill(pid, SIGUSR2);
// }

// void send_end(pid_t pid)
// {
// 	int i;

// 	i = 0;
// 	while (i != 8)
// 	{
// 		kill(pid, SIGUSR1); // Since this is the end, send 0 8 times to notify that it is \0
// 		i++;
// 		usleep(200);
// 	}
// 	return;
// }
// 
// 
// 
// 
// 
intro
While studying hard at 42Seoul, while proceeding with the ft_print subject, there was a part where Unicode had to be output directly with the write() function, so I studied it.

UNICODE ?
Unicode is an industry standard designed to consistently represent and handle all characters in the world on computers, and is established by the Unicode Consortium.In addition, this standard includes the ISO 10646 character set, character encoding, character information database, and algorithms for handling characters. - Source Wikipedia

Basically, the birth process of Unicode was to express characters on a computer with the size of 1 byte of the existing ASCII code(0 to 255).

However, since Ascii basically supports English characters, each country began to express characters in various ways, such as modifying Ascii to solve this problem and assigning it to their own language.Now, as the Internet develops, each When people in the country see the same code at the same time, it happens that they are expressed in different characters.

Unicode came out to solve this point.

Unicode is a code table in which characters and codes are matched one - to - one.

What is the difference between UTF - 8 and Unicode ?
As mentioned above, unicde is a commonly used rule all over the world.

However, various methods are used to express this rule in a computer, which is called encoding.

Among them, UTF - 8 is one of the representative encoding methods.

UTF - 8
UTF - 8 is one of the variable length character encoding methods for expressing Unicode.

Code value range of digits 1st byte 2nd byte 3rd byte 4th byte 5th byte 6th byte
7 bits 0 to 0x7F127 0xxxxxxx
11 bits 0x80128 to 0x7FF2, 047 110xxxxx 10xxxxxx
16 - bit 0x8002, 048 to 0xFFFF65, 535 1110xxxx 10xxxxxx 10xxxxxx
21 bits 0x1000065, 536 to 0x1FFFFF2, 097, 151 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
26 bit(unused) 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
31 bit(unused) 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
UTF - 8 uses at least 1 byte to 4 bytes variably, and at this time, it is determined according to the size of the character string that can be expressed.

For example, looking at the character ☠, the unicode value is 9760. It is converted to a size of 3 bytes through the UTF - 8 encoding method as shown below.

utf - 8 - encoding

Now let's implement the above method in C!

UTF - 8 Encoding with C!
After creating the header file, define it as follows.

#define UTF8_1 0x7F
#define UTF8_2 0x7FF
#define UTF8_3 0xFFFF
#define UTF8_4 0x1FFFFF
The value defined above is the maximum value for each byte when each encoding is performed.

Using this, it calculates how many bytes are needed through bit operation!

/* ************************************************ ************************** */
/* */
/* ::: :::::::: */
/* ft_putwchar_fd.c :+: :+: :+: */
/* +:+ +:+ +:+ */
/* By: jaeskim <jaeskim@student.42seoul.kr> +#+ +:+ +#+ */
/* +#+#+#+#+#+ +#+ */
/* Created: 2020/10/23 17:46:22 by jaeskim #+# #+# */
/* Updated: 2020/10/23 21:27:57 by jaeskim ### ########.fr */
/* */
/* ************************************************ ************************** */
#include <unistd.h>
#include "ft_utf8.h"
static void ft_utf_4(int unicode, int fd)
{
	unsigned char buf;
	buf = (unicode >> 18 & 7) | 240;
	write(fd, &buf, 1);
	buf = (unicode >> 12 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void ft_utf_3(int unicode, int fd)
{
	unsigned char buf;
	buf = (unicode >> 12 & 15) | 224;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void ft_utf_2(int unicode, int fd)
{
	unsigned char buf;
	buf = unicode >> 6 | 192;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void ft_utf_1(char unicode, int fd)
{
	write(fd, &unicode, 1);
}
void ft_putwchar_fd(int unicode, int fd)
{
	if ((unicode | UTF8_1) == UTF8_1)
		ft_utf_1(unicode, fd);
	else if ((unicode | UTF8_2) == UTF8_2)
		ft_utf_2(unicode, fd);
	else if ((unicode | UTF8_3) == UTF8_3)
		ft_utf_3(unicode, fd);
	else if ((unicode | UTF8_4) == UTF8_4)
		ft_utf_4(unicode, fd);
	else
		ft_putchar_fd(unicode, fd);
}
To explain each code, when you need to use 1 byte from the top using the value defined in ft_putwchar_fd, after performing the OR operation with the maximum value you can have, if the value is the same, it belongs to the range, so it corresponds to 1 byte.Let's move on to action!

Now, for each 2 byte, 3 byte, etc., the part that should be entered in each first byte is brought through shift operation, and after organizing through and operation, a fixed bit is added through or operation and then written.

Let's explain this part with the ☠(9760) character described above!.

First of all, since the value is 9760 when it first comes in as uncode, it goes down in order from the top and then goes to the ft_utf_3 function.

After that, once you convert 9760 to binary, it is 0010 0110 0010 0000.

And buf = (unicode >> 12 & 15) | 224; In part, 12 is moved through shift operation to become 1000 1000 0000 1001 and initialized to 0000 1001 through and operation.And finally, 1110 1001 is output through the OR operation that adds fixed bits.

And since the remaining 2 bytes use only 6 bits each except for the operation of shift operation, it is initialized through 63 and and operation, and a fixed bit is added through 128 and or operation to be output.

