/**
 * @file task-1.c
 * @author Demian Domozhirov (conducterdomian@yandex.ru | tg: @trelawnm)
 *
 * @brief Program to check if all digits in a natural number are unique.
 *
 * Program takes the number `N` and calculate, does that number fit the roles
 * of task. If so, the `YES` will be printed and `NO` otherwise. In case of
 * any error such as wrong imput `n/a` will be printed.
 *
 * @version 1.0
 * @date 10.09.2025
 */
#include <stdio.h>

void printWelcomeMessage(void);

/**
 * @brief Main entery point for execute programm.
 *
 * @return `0` - as signal to the sistem, that program finished without errors.
 */
int main(void) {
  printWelcomeMessage();

  unsigned long num;
  scanf("%lu", &num);

  int seen = 0;

  while (num > 0) {
    int mask = 1 << (num % 10);

    if (seen & mask) {
      printf("NO\n");
      return 0;
    }

    seen |= mask;
    num /= 10;
  }

  printf("YES\n");
  return 0;
}

/**
 * @brief Function to print welcome message - helps user understand what our
 * program does and what limitations it has.
 */
void printWelcomeMessage(void) {
  printf(
      "=============================================================\n"
      "ПРОГРАММА: Проверка уникальности цифр в числе\n"
      "ВЕРСИЯ: 1.0\n"
      "АВТОР: Доможиров Демьян (ЗИВТ-252, ОмГТУ)\n"
      "=============================================================\n\n"

      "НАЗНАЧЕНИЕ:\n"
      "Определяет, являются ли все цифры натурального числа N различными.\n\n"

      "ВОЗМОЖНОСТИ ПРОГРАММЫ:\n"
      "- Проверка чисел любой разрядности (в пределах типа long)\n"
      "- Обработка натуральных чисел\n"
      "- Защита от некорректного ввода\n\n"

      "ОГРАНИЧЕНИЯ НА ВВОД:\n"
      "- Вводимое число должно быть натуральным (целое положительное)\n\n"
      // "- Не допускается ввод символов, дробных чисел, отрицательных чисел\n"
      // "- Максимальная разрядность числа ограничена размером типа long\n\n"

      "ВЫВОДИМЫЕ РЕЗУЛЬТАТЫ:\n"
      "YES - если все цифры числа уникальны\n"
      "NO  - если в числе есть повторяющиеся цифры\n\n"
      // "n/a - если введены некорректные данные\n\n"

      "Введите натуральное число N: ");
  return;
}