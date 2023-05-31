#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


#define WELCOME_MSG "\nWelcome to the BLK File Management System!\n"
#define CHOOSE_MSG "Choose if you want to create, delete or rename a file! You can also now create directories using the directory input!\n"
#define CREATE_MSG "You have selected creation mode! Type in the file name (.txt) and adress starting at the root folder that you want to create!\n"
#define DIR_CREATE_MSG "You have selected directory creation mode! Type in the dir's adress with it's name starting at the root folder.\n"
#define DELETE_MSG "You have selected deleting mode! Type in the files current adress starting at the root folder and it will be deleted!\n"
#define SUCCESS_MSG "Operation succesful!\n"
#define RENAME_MSG "You have selected renaming mode! Type in the files current adress starting at the root folder and name and a new name for it!\n"
#define ERR_LEN "UNKNOWN ERROR(0x1) Please contact our support team ar github.com∕boouke and provide the memory adress\n"
#define ERR_FILE_CREATE "FILE CREATE ERROR(0x2) Please restart the program, and try again. If you encounter the same problem contact our support team at github.com/boouke\n"

void choose(int* int_operation);
void create(void);
void name(void);
void dir_create(void);
void file_delete(void);

int main(){
    int int_operation = 0;
    printf("%s", WELCOME_MSG);
    choose(&int_operation);
    if(int_operation == 1){
        create();
        return 0;
    }
    else if(int_operation == 2){
        file_delete();
        return 0;
    }
    else if(int_operation == 3){
        dir_create();
        return 0;
    }
    else if(int_operation == 4){
        name();
        return 0;
    }
    return 0;
}
void choose(int* int_operation){
    int len = 50;
    char operation[200];
    char* buffer = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", CHOOSE_MSG);
    while (scanf("%s", operation) != 0 && (strcmp(operation, "create") != 0 && strcmp(operation, "delete") != 0 && strcmp(operation, "directory") != 0) && strcmp(operation, "rename") != 0){
        buffer = (char*)realloc(buffer, (strlen(operation) + 1) * sizeof(char));
        printf("%s is not a valid option. Please enter 'create', 'delete', 'rename' or 'directory':\n", operation);
    }
    if(strcmp(operation, "create") == 0){
        *int_operation = 1;
        return;
    }
    else if(strcmp(operation, "delete") == 0){
        *int_operation = 2;
        return;
    }
    else if(strcmp(operation, "directory") == 0){
        *int_operation = 3;
        return;
    }
    else if(strcmp(operation, "rename") == 0){
        *int_operation = 4;
        return;
    }
    free(buffer);
}
void create(void) {
    int len = 50;
    char* file_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", CREATE_MSG);
    while (scanf("%s", file_name) != 1){
        printf("%s at %p", ERR_LEN, file_name);
    }
    FILE* file = fopen(file_name, "w");
    if (file == NULL){
        printf("%s", ERR_FILE_CREATE);
    } else{
        printf("%s", SUCCESS_MSG);
        fclose(file);
    }
    free(file_name);
}

void file_delete(void){
    int len = 50;
    char* file_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", DELETE_MSG);
    while(scanf("%s", file_name) != 1){
        printf("%s at %p", ERR_LEN, file_name);
    }
    int rem = remove(file_name);
    if(rem == 0){
        printf("%s", SUCCESS_MSG);
    }
    else{
        printf("%s at %p", ERR_LEN, file_name);
    }
    free(file_name);
}
void dir_create(void) {
    int len = 50;
    char perms[10];
    char* dir_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", DIR_CREATE_MSG);
    while (scanf("%s", dir_name) != 1) {
        printf("%s at %p", ERR_LEN, dir_name);
    }
    printf("What permissions do you want to have? You can select all, read or write\n");
    while(scanf("%s", perms) != 1 && strcmp(perms, "all") != 0 && strcmp(perms, "write") != 0 && strcmp(perms, "read") != 0 && strcmp(perms, "r&w") != 0){
        printf("%s", ERR_LEN);
    }
    if(strcmp(perms, "all")){
        strcpy(perms, "S_IRWXU");
    }
    else if(strcmp(perms, "read")){
        strcpy(perms, "S_IWUSR");
    }
    else if(strcmp(perms, "write")){
        strcpy(perms, "S_IXUSR");
    }
    int creating = mkdir(dir_name, perms);
    if(creating == 0){
        printf("%s", SUCCESS_MSG);
        return;
    }
    else{
        printf("%s at %p", ERR_LEN, dir_name);
        return;
    }
    free(dir_name);
}

void name(void){
    int len = 50;
    char* file_name = (char*)malloc((len + 1) * sizeof(char));
    char* new_file_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", RENAME_MSG);
    while(scanf("%s", file_name) != 1){
        printf("%s", ERR_LEN);
    }
    while(scanf("%s", new_file_name) != 1){
        printf("%s", ERR_LEN);
    }
    if(rename(file_name,new_file_name) == 0){
        printf("%s", ERR_LEN);
    }
    else{
        printf("%s", SUCCESS_MSG);
    }
    free(file_name);
    free(new_file_name);
}
