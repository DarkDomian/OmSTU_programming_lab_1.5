/**
 * @file task-2.c
 * @author Demian Domozhirov (conducterdomian@yandex.ru | tg: @trelawnm)
 *
 * @brief
 *
 * @version 1.0
 * @date 10.09.2025
 */
#include <stdio.h>
#include <string.h>

void replace_words_simple(char *input, const char *S, const char *W);

int main() {
    char input[1024] = "hello world this is a test world";
    char S[] = "world";
    char W[] = "earth";
    
    replace_words_simple(input, S, W);
    
    return 0;
}

void replace_words_simple(char *input, const char *S, const char *W) {
    char result[1024] = {0};
    char *token;
    char *rest = input;
    int first = 1;
    
    while ((token = strtok_r(rest, " ", &rest))) {
        if (!first) strcat(result, " ");
        
        if (strcmp(token, S) == 0) {
            strcat(result, W);
        } else {
            strcat(result, token);
        }
        
        first = 0;
    }
    
    printf("Result: %s\n", result);
}