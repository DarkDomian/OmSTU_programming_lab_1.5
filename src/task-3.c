/**
 * @file task-3.c
 * @author Demian Domozhirov (conducterdomian@yandex.ru | tg: @trelawnm)
 *
 * @brief Word replacement program - replaces all occurrences of one word with another in a sentence
 *
 * @version 1.0
 * @date 04.01.2026
 */
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <string.h>

#define SENTENCE "hello world this is a test world"
#define REPLACEMENT_WORD "world"
#define REPLACEABLE_WORD "earth"

#define MAX_SIZE 1024

/**
 * @brief Prints program information and the original sentence
 * 
 * @param sentence The original sentence to display
 * 
 * @details Shows program name, version, author, purpose,
 *          limitations, and the original text
 */
void printWelcomeMessage(char *sentence);
/**
 * @brief Replaces all occurrences of word S with word W in the given sentence
 * 
 * @param sentence The input string to process (will be modified)
 * @param S The word to search for and replace
 * @param W The word to use as replacement
 * 
 * @note Uses POSIX strtok_r() for thread-safe tokenization
 * @warning The original sentence is modified during processing
 * @warning MAX_SIZE limits the length of both input and output
 */
void replaceWords(char *sentence, const char *S, const char *W);

int main() {
    char sentence[MAX_SIZE] = SENTENCE;
    char S[] = REPLACEMENT_WORD;
    char W[] = REPLACEABLE_WORD;
    
    printWelcomeMessage(sentence);

    replaceWords(sentence, S, W);

    printf("After: %s\n", sentence);
    
    return 0;
}

void replaceWords(char *sentence, const char *S, const char *W) {
    char result[MAX_SIZE] = {0};
    char *token;
    char *rest = sentence;
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
    
    // Copy the result back to the original sentence buffer
    memcpy(sentence, result, MAX_SIZE);
}

void printWelcomeMessage(char *sentence) {
  printf(
      "=========================================\n"
      "ПРОГРАММА: Замена слов в предложении\n"
      "ВЕРСИЯ: 1.0\n"
      "АВТОР: Доможиров Демьян (ЗИВТ-252, ОмГТУ)\n"
      "=========================================\n\n"

      "НАЗНАЧЕНИЕ:\n"
      "В исходном тексте, заменяет одно слово другим, если это возможно\n\n"

      "ОГРАНИЧЕНИЯ:\n"
      "- Программа не принимает никакого ввода. Чтобы изменить параметры - "
      "нужно поменять константы в коде программы\n\n"

      "ВЫВОДИМЫЕ РЕЗУЛЬТАТЫ:\n"
      "- Строка до обработки (before)\n"
      "- Строка после обработки, замена произведена (after)\n\n"

      "Before: %s\n",
      sentence
  );
  return;
}