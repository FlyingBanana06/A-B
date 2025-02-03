int choose_mode();

char* get_test_case();
int get_length();
void generate_test_case();

char* get_answer();

void process_command(char ans[11], int mode);
int parse_command(char cmd[8], char A[3], char B[3]);
void replace_string(char ans[11], char A[3], char B[3]);