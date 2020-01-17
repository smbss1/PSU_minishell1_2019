/*
** EPITECH PROJECT, 2019
** my
** File description:
** Header contains all functions prototyped
*/

#ifndef _MY_
#define _MY_

/********************************STRUCT***********************************/

typedef struct {
    char *flag;
    void (*func)(void *, char *buffer);
    void (*pt)(void *, void *, char *buffer);
    char *param;
    char *prefix;
} flagstruct;

typedef struct {
    void (*func)(void *);
    void (*pt)(void *, char *);
    char *param;
    char *prefix;
} flag_t;

typedef struct s_vector
{
    void *data;
    struct s_vector *prev;
    struct s_vector *next;
} vector;

typedef struct s_dictionary
{
    char *key;
    void *data;
    struct s_dictionary *prev;
    struct s_dictionary *next;
} dictionary;

/****************************************************************************/
/****************************PUTS FUNCTION***********************************/

void my_putstr(char const *str);
void my_put_float(double nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putbase(int nb, const char *base);
void my_put_unsigned(unsigned int nb);
void my_printf(char *str, ...);

void my_putchar_void(void *c);
void my_put_float_void(void *nb);
void my_put_nbr_void(void *nb);
void my_putstr_void(void *nb);
void my_putbase_void(void *num, char *base);

void my_sputstr(char const *str, char *buffer);
void my_sput_float(double nb);
void my_sputchar(char c, char *buffer);
void my_sput_nbr(int nb, char *buffer);
void my_sputbase(int num, const char *base);
void my_sput_unsigned(unsigned int nb);
void my_sprintf(char *buffer, const char *str, ... );

void my_sputchar_void(void *c, char *buffer);
void my_sput_float_void(void *nb);
void my_sput_nbr_void(void *nb, char *buffer);
void my_sputstr_void(void *str, char *buffer);
void my_sputbase_void(void *num, char *base);

/****************************************************************************/

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_char_isalpha(char str);
int my_char_isnum(char str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcat(char *dest, char const *src);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
void my_swap(int *a, int *b);
int condition(char const *str, int i, long *p_verif, unsigned long *p_verif2);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str, char *delim);
char *my_strdup(char const *src);
char *my_char_to_str(char c);
char *my_charcat(char *dest, char src);
char my_int_to_char(int digit);
int my_char_to_int(char str);
char *my_strchr(char *str, int c);
char *my_strtok(char *str, char *delim);
int my_strtol(char *str, char **endptr);

int my_add(int a, int b);
int my_sub(int a, int b);
int my_mul(int a, int b);
int my_div(int a, int b);
int my_mod(int a, int b);

int readFile(char *file);
void writeFile(char *file, char *data);
int fs_open_file(char const *filepath);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

/******************************MEMORY FUNCTION*******************************/
/**
* \brief Allocates memory to the 2d array
* \param nb_rows : This is the num of rows that will be allocated for the array
* \param nb_cols : This is the num of col that will be allocated for the array
* \return A new allocated 2d array
*/
char **mem_alloc_2d_array(int nb_rows, int nb_cols);

/**
* \brief Allocates memory to the 2d array
* \note This function not return a char 2d array but an int 2d array
* \param nb_rows : This is the num of rows you want to allocate for the array
* \param nb_cols : This is the num of col you want to allocate for the array
* \return A new allocated 2d array
*/
int **mem_alloc_2d_array_int(int nb_rows, int nb_cols);

/****************************************************************************/


void free_2d_array(void **array);

void set_variable(char *str, char *name, char *data);
int get_number(char *str, char *word);
char *get_str(char *str, char *word);
char *get_variable_name(char *str, char *word);

/**
* \brief Reads a line from the specified file descriptor
*  and stores it into the string array
* \details It stops when either bytes characters are read,
*  the newline character is read, or the end-of-file is reached,
*  whichever comes first.
* \param my_string : This is an array of chars where the string read is stored.
* \param bytes : This is the maximum number of characters to be read
* \note Usually, the length of the array passed as my_string is used.
* \param fd : This is the file descriptor of the file where
*  characters are read from.
* \return
*  On success, the function returns the same my_string parameter.
*  If End-Of-File encountered or no characters have been read,
*  the contains of my_string will remain unchanged.
*  If an error occurs, a null pointer is returned.
*/
char *fs_get(char my_string[], int bytes, int fd);

/******************************VECTOR FUNCTIONS*******************************/

void vector_delete(vector **v, int index);
void vector_delete_all(vector *v);
vector *vector_add(vector **head_ref, void *data);
void *vector_pop(vector **array);
void *vector_get_at(vector **v, int index);
vector *vector_getnode_at(vector **v, int index);
void vector_set_at(vector **v, int index, void *item);
int vector_getsize(vector *begin);
void vector_foreach(vector *v, int (*callback)(void *));
void vector_reverse(vector **begin);

/****************************************************************************/

/*************************DICTIONARY FUNCTIONS*******************************/

dictionary *dictionary_add(dictionary **head_ref, char *key, void *data);
void dictionary_delete(dictionary **dict, char *key);
void dictionary_delete_all(dictionary *v);
dictionary *dictionary_getnode(dictionary **dict, char *key);
int dictionary_getsize(dictionary *begin);
void *dictionary_getvalue(dictionary **dict, char *key);
int dictionary_key_exists(dictionary **dict, char *key);
void dictionary_foreach_value(dictionary *v, int (*callback)(void *));
void dictionary_foreach_key(dictionary *v, int (*callback)(char *));
void dictionary_foreach(dictionary *v, int (*callback)(char *, void *));
void dictionary_sort(dictionary **dict, int (*compare)(void *, void *));
void dictionary_sort_by_key(dictionary **dict);

/****************************************************************************/

#endif