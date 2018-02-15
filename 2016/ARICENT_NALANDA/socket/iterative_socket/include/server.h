#define MAX_NAMELEN 80
#define BACKLOG 5
#define BUFSIZE 256
void show_filtered_output();
void process_file(int client_sd, char *file); 
void put_matched_pattern_in_ds(char *file);
void send_data_to_client(int conn_sd);
bool check_file_validity(char *file);

extern void read_file(int conn_sd);

