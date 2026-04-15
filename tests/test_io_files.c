/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** test_io_files
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "c_zsh.h"

// Tests for get_file_size_stat
Test(get_file_size_stat, returns_negative_for_null_filepath)
{
    cr_assert_eq(get_file_size_stat(NULL), -1);
}

Test(get_file_size_stat, returns_file_size)
{
    FILE *tmp = fopen("/tmp/test_size_42sh.txt", "w");
    fprintf(tmp, "hello");
    fclose(tmp);

    cr_assert_eq(get_file_size_stat("/tmp/test_size_42sh.txt"), 5);

    unlink("/tmp/test_size_42sh.txt");
}

Test(get_file_size_stat, returns_negative_for_nonexistent_file)
{
    cr_assert_eq(get_file_size_stat("/tmp/nonexistent_file_xyz123.txt"), -1);
}

Test(get_file_size_stat, handles_empty_file)
{
    FILE *tmp = fopen("/tmp/test_empty_42sh.txt", "w");
    fclose(tmp);

    cr_assert_eq(get_file_size_stat("/tmp/test_empty_42sh.txt"), 0);

    unlink("/tmp/test_empty_42sh.txt");
}

// Tests for openator
Test(openator, returns_null_for_null_filepath)
{
    char *result = openator(NULL);
    cr_assert_null(result);
}

Test(openator, returns_null_for_nonexistent_file)
{
    char *result = openator("/tmp/nonexistent_file_xyz123.txt");
    cr_assert_null(result);
}

Test(openator, reads_file_content)
{
    FILE *tmp = fopen("/tmp/test_content_42sh.txt", "w");
    fprintf(tmp, "hello world");
    fclose(tmp);

    char *result = openator("/tmp/test_content_42sh.txt");
    cr_assert_str_eq(result, "hello world");
    free(result);

    unlink("/tmp/test_content_42sh.txt");
}

Test(openator, reads_file_with_newlines)
{
    FILE *tmp = fopen("/tmp/test_newlines_42sh.txt", "w");
    fprintf(tmp, "line1\nline2\nline3");
    fclose(tmp);

    char *result = openator("/tmp/test_newlines_42sh.txt");
    cr_assert_str_eq(result, "line1\nline2\nline3");
    free(result);

    unlink("/tmp/test_newlines_42sh.txt");
}

