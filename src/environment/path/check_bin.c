/*
** EPITECH PROJECT, 2026
** check_bin
** File description:
** bin
*/
#include "minishell.h"
#include <stdlib.h>
#include <string.h>

char *loop_bin(main_t *main_stock, char *command)
{
    int i = 0;
    char *path_bin = NULL;

    if (main_stock == NULL || main_stock->path == NULL)
        return NULL;
    for (; main_stock->path[i] != NULL; i++) {
        path_bin = check_bin(command, main_stock->path[i]);
        if (path_bin != NULL)
            return path_bin;
    }
    return NULL;
}

static char *build_path(char *path, char *name)
{
    char *tmp = my_strconcat(path, "/");
    char *full_path;

    if (tmp == NULL)
        return NULL;
    full_path = my_strconcat(tmp, name);
    free(tmp);
    return full_path;
}

int check_is_dir(char *command)
{
    struct stat st;

    if (command == NULL)
        return 0;
    if (stat(command, &st) == 0 && S_ISDIR(st.st_mode)) {
        my_putstrerror(command);
        my_putstrerror(": Permission denied.");
        return 1;
    }
    return 0;
}

char *check_bin(char *command, char *path)
{
    DIR *dir = opendir(path);
    struct dirent *dr;

    if (command == NULL || path == NULL || dir == NULL)
        return NULL;
    if (check_is_dir(command) == 1)
        return NULL;
    dr = readdir(dir);
    while (dr != NULL) {
        if (my_strcmp(dr->d_name, command) == 0) {
            closedir(dir);
            return build_path(path, dr->d_name);
        }
        dr = readdir(dir);
    }
    closedir(dir);
    return NULL;
}
