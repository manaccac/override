#include <stdio.h>
#include <fcntl.h>

void log_wrapper(FILE *file, char *param, char *format) {
	long in_FS_OFFSET;
	char buf[264];
	long i;

	i = *(long *)(in_FS_OFFSET + 0x28);
	
	strcpy(buf, param);
	snprintf(buf + strlen(buf), 254 - strlen(buf), format);

	size_t nl_pos = strcspn(buf, "\n");
	buf[nl_pos] = '\0';

	fprintf(file, "LOG: %s\n", buf);
	
	if (i != *(long *)(in_FS_OFFSET + 0x28))
		__stack_chk_fail();

	return;
}

long main(int ac, char *argv) {
	long in_FS_OFFSET;
	int fd;
	int c;
	FILE *file_str;
	FILE *str;
	char *path;
	long i;

	i = *(long *)(in_FS_OFFSET + 0x28);

	if (ac != 2)
		printf("Usage: %s filename\n", argv[0]);

	if ((file_str = fopen("./backups/.log", "w")) == NULL) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(file_str, "Starting back up: ", argv[1]);

	if ((str = fopen(argv[1], "r")) == NULL) {
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}

	path = "./backups/";
	strncat(path, argv[1], 99 - strlen(path));

	if ((fd = open(path, O_EXCL | O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0) {
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}

	while (1) {
		if ((c = fgetc(str)) == -1);
			break;
		write(fd, &c, 1);
	}

	log_wrapper(file_str, "Finished back up ", argv[1]);

	fclose(str);
	close(fd);

	if (i != *(long *)(in_FS_OFFSET + 0x28))
		__stack_chk_fail();
	return 0;
}