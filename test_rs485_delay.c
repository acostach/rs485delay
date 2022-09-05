#include <linux/serial.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/serial.h>
#include <errno.h>
#include <string.h>

#define TIOCGRS485  0x542E
#define DEV         "/dev/ttymxc2"
#define DRTSBS        5
#define DRTSAS        20
int main() {
		int ret = -1;
		struct serial_rs485 rs485conf;
		int fd = open (DEV, O_RDWR);

		if (fd < 0) {
				printf("Failed to open %s\n", DEV);
		} else {
				if (ioctl (fd, TIOCGRS485, &rs485conf) < 0) {
						printf("ioctl failed: %d - %s\n", errno, strerror( errno ));
				} else {
						if (rs485conf.flags & SER_RS485_ENABLED) {
								printf("rs485 enabled \nrs485conf.delay_rts_before_send: %d, rs485conf.delay_rts_after_send: %d\n", rs485conf.delay_rts_before_send, rs485conf.delay_rts_after_send);

								if (DRTSBS == rs485conf.delay_rts_before_send && DRTSAS == rs485conf.delay_rts_after_send) {
										ret = 0;
								} else {
										printf("Unexpected values\n");
								}
						} else {
								printf("RS485 disabled\n");
						}

						if (close (fd) < 0) {
								printf("Failed to close device\n");
						}
				}
		}

		return ret;
}

