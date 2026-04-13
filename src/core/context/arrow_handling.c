/*
** EPITECH PROJECT, 2026
** execute
** File description:
** command
*/
#include <termios.h>
#include "../../../include/minishell.h"

static int is_arrow(char arrow[2], char ch)
{
    if (ch != ARROW_START)
        return -1;
    read(STDIN_FILENO, &arrow[0], 1);
    if (arrow[0] != '[')
        return -1;
    return 0;
}

static void left_arrow(char arrow, int *cursor)
{
    if (arrow != 'D')
        return;
    *cursor -= *cursor > 0 ? 1 : 0;
    write(1, "\b", 1);
}

static void right_arrow(char arrow, int *cursor, int len)
{
    if (arrow != 'C')
        return;
    *cursor += *cursor < len ? 1 : 0;
    write(1, "\x1b[C", 3);
}

int arrow_handling(char ch, int *cursor, int len)
{
    char arrow[2];

    if (is_arrow(arrow, ch) == -1)
        return 0;
    read(STDIN_FILENO, &arrow[1], 1);
    left_arrow(arrow[1], cursor);
    right_arrow(arrow[1], cursor, len);
    return 1;
}
