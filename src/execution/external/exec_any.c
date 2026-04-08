/*
** EPITECH PROJECT, 2026
** exec
** File description:
** exec
*/

#include "minishell.h"

static char *make_env_entry(char *key, char *value)
{
    char *tmp = my_strconcat(key, "=");
    char *entry = my_strconcat(tmp, value ? value : "");

    free(tmp);
    return entry;
}

static char **build_env(env_t *stock_env)
{
    int count = 0;
    env_t *tmp = stock_env;
    char **env;
    int i = 0;

    for (; tmp; tmp = tmp->next)
        count++;
    env = malloc(sizeof(char *) * (count + 1));
    if (!env)
        return NULL;
    for (; stock_env; stock_env = stock_env->next) {
        env[i] = make_env_entry(stock_env->key, stock_env->value);
        i++;
    }
    env[i] = NULL;
    return env;
}

static void free_env(char **env)
{
    for (int i = 0; env[i]; i++)
        free(env[i]);
    free(env);
}

static int is_direct_path(char *cmd)
{
    for (int i = 0; cmd[i]; i++)
        if (cmd[i] == '/')
            return 1;
    return 0;
}

static int is_directory(char *cmd)
{
    struct stat st;

    if (!cmd)
        return 0;
    if (stat(cmd, &st) == -1)
        return 0;
    return S_ISDIR(st.st_mode);
}

static char *get_exec_path(main_t *main_stock, command_ctx_t *ctx)
{
    if (is_direct_path(ctx->command))
        return ctx->command;
    return loop_bin(main_stock, ctx->command);
}

static int dir_permission_denied(char *command)
{
    my_putstrerror(command);
    my_putstrerror(": Permission denied.\n");
    return 1;
}

static int command_not_found(char *command, char **env)
{
    my_putstrerror(command);
    my_putstrerror(": Command not found.\n");
    free_env(env);
    return 1;
}

static int run_and_cleanup(main_t *main_stock, command_ctx_t *ctx,
    char *path, char **env)
{
    int status = run_fork(main_stock, ctx, path, env);

    if (!is_direct_path(ctx->command))
        free(path);
    free_env(env);
    return status;
}

int exec_any(main_t *main_stock, command_ctx_t *ctx)
{
    char *path = get_exec_path(main_stock, ctx);
    char **env = build_env(main_stock->stock_env);

    if (is_directory(ctx->command))
        return dir_permission_denied(ctx->command);
    if (!env)
        return 1;
    if (!path)
        return command_not_found(ctx->command, env);
    return run_and_cleanup(main_stock, ctx, path, env);
}
