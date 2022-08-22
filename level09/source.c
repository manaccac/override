struct s_message {
    char message[140];  /* message */
    char username[40];  /* message+140 */
    int len;    /* message+180 */
};

void set_message(struct s_message *data) {
	char buffer[1024];

	bzero(buffer, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buffer, 1024, 0);
	strncpy(data->message, buffer, data->len);
}

void secret_backdoor() {
	char buffer[128];

	fgets(buffer, 0x80, 0);
	system(buffer);
}

void set_username(struct s_message *data) {
	char buffer[128];
	int i;

	bzero(buffer, 128);
	puts(">: Enter your data");
	printf(">>: ");
	fgets(buffer, 128, 0);
	i = 0;
	while (i <= 40 && buffer[i])
	{
		data->username[i] = buffer[i];
		i++;
	}
	printf(">: Welcome, %s", data->username + 140);
}

void handle_msg(void) {
	struct s_message *data;

	bzero(data->username, 40);
	data->len = 140;
	set_username(&data);
	set_message(&data);
	puts(">: Msg sent!");
}

int main(int argc, const char **argv) {
	puts("--------------------------------------------");
	puts("|   ~Welcome to l33t-m$n ~    v1337        |");
	puts("--------------------------------------------");
	handle_msg();
}