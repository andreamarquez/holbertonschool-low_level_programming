#ifndef FILEIO_H
#define FILEIO_H

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
void print_error_and_exit(const char *message, int exit_code);

#endif /* FILEIO_H */
