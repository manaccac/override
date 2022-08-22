void main() {
    int i;

    puts('*****************************');
    puts('* 	     -Level00 -		  *');
    puts('*****************************');
    printf('Password:');
    scanf('%d', &i);
    if (i != 5276) {
        puts('Invalid Password');
        return;
    }
    puts('Authentificated');
    system('/bin/sh');
    return;
}