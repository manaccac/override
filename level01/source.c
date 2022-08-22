char a_user_name[256]; // 0x804a040

int verify_user_name(void)
{
	puts("verifying username....\n");
	return memcmp("dat_wil", a_user_name, 7); // check juste si les 7 premiers char sont dat_wil
}

int verify_user_pass(char *pass)
{
	return memcmp("admin", pass, 5); // check juste si les 5 premiers char sont admin
}

void main() {
    int i;
    char str[64];

    i = 0;
    bzero(str, 64); // c'est pas un bzero mais c'est pareil flemme d'ecrire tout

    puts('********* ADMIN LOGIN PROMPT *********');
    printf('Enter Username:');
    fgets(a_user_name, 256, stdin);
    if (verify_user_name()) {
        puts('nope, incorrect username...');
        return;
    }
    printf('Enter Password:');
    i = verify_user_pass(fgets(user_pass, 100, stdin));
    // heure du bordel
    if (i == 0) {
        puts("nope, incorrect password...\n");
        return;
    } else {
        if (i == 0)
            return;
        puts("nope, incorrect password...\n");
        return;
    }
}