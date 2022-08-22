void main() {
    uint32_t i;
    uint8_t buf[100]; // 0x64

    fgets(buf, 100, stdin); // 0x64
    while (i < strlen(buf)) {
        if (buf[i] > 64 && buf[i] <= 90) {
            buf[i] = buf[i] ^ 32; //0x20
        }
        i++;
    }
    printf(buf);
    exit();
}