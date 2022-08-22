int auth(char *login, unsigned int i) {
    int len;
    int ret;
    long pret;

    len = strcspn(login, "\n");
    login[len] = '\0';
    len = strnlen(login, 0x20);
    if (len < 6)
        ret = 1;
    else {
        pret = ptrace(PTRACE_TRACEME);
        if (pret == -1) {
            puts("\x1b[32m.---------------------------.");
			puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
			puts("\x1b[32m\'---------------------------\'");
			ret = 1;
        }
        else
            ret = (i == hash(login)) ? 1 : 0;
        return ret;
    }
}

int main() {
    char login[32];
    unsigned int i;
    int n;

    puts("*****************");
    puts("levle06");
    puts("*****************");

    printf("-> enter login:");
    fgets(login, 0x20), stdin);

    puts("*****************");
    puts("new  account");
    puts("*****************");

    printf("-> enter serial:");
    scanf("%u", i);

    n = auth(login, i);
    if (n == 0) {
        puts("Authenticated!");
        system("/bin/sh");
    }
    return;
}