
int main(){

    unsigned int num = 0x00000002;
    int position = 5;
    unsigned int set,clear = 0;

    set = num | (1U << position);
    clear = set & ~(1U << position);

    return 0;
}