#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define HEADER \
    "===================================================\n" \
    "ПРОГРАММА: Поиск самого частого символа ASCII\n" \
    "ВЕРСИЯ: 1.0\n" \
    "АВТОР: Доможиров Демьян (ЗИВТ-252, ОмГТУ)\n" \
    "===================================================\n\n"

void printWelcomeMessage(void);

int main(int argc, char *argv[]) {
    char list[256] = {0};

    if (argc != 2) {
        printf(
            HEADER
            "Ошибка! Пример использования:\n"
            "%s ./way/to/example.txt",
            argv[0]
        );
        return SUCCESS;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf(
            HEADER
            "Ошибка! Не удалось открыть файл... %s\n"
            "Проверьте что файл существует или путь указан верно.",
            argv[1]
        );
        return SUCCESS;
    }

    printWelcomeMessage();
    
    int ch = 0;
    int max = 0;
    // scan the file
    while ((ch = fgetc(file)) != EOF) {
        list[ch] += 1;
        if (list[ch] > max)
            max = list[ch];
    }

    FILE *output = fopen("out.txt", "w");
    if (max) {
        printf("Найденные символы: ");
        for (int i = 0; i < 256; ++i) {
            if (list[i] == max) {
                fputc(i, output);
                printf("%c", i);
            }
        }
    } else {
        printf("Файл пуст...");
    }


    fclose(file);
    fclose(output);
}

void printWelcomeMessage(void) {
  printf(
      HEADER

      "НАЗНАЧЕНИЕ:\n"
      "Поиск в файле самых частых символов, их запись в отдельный файл\n\n"

      "ОГРАНИЧЕНИЯ:\n"
      "Не обрабатывает символы в строгом понимании.\n"
      "Читает по одному байту, не может сохранять и отслеживать символы UNICOD, только ASCII\n\n"

      "ВЫВОДИМЫЕ РЕЗУЛЬТАТЫ:\n"
      "Сохраняет результат в файл out.txt\n"
      "Так же выводит получившийся набор символов в терминал.\n\n"
    );
  return;
}