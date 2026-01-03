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

#define LOWER 0    // lower limit of table
#define UPPER 100  // upper limit
#define STEP 11    // step size

void printWelcomeMessage(void);

/**
 * @brief Main entery point for execute programm.
 *
 * @return `0` - as signal to the sistem, that program finished without errors.
 */
int main(void) {
  printWelcomeMessage();

  int cels;
  for (cels = LOWER; cels <= UPPER; cels += STEP)
    printf("%3d %6.1f\n", cels, (9.0 / 5.0) * (cels + 32));

  return 0;
}

/**
 * @brief Function to print welcome message - helps user understand what our
 * program does and what limitations it has.
 */
void printWelcomeMessage(void) {
  printf(
      "=============================================================\n"
      "ПРОГРАММА: Вывод таблицы температур\n"
      "ВЕРСИЯ: 1.0\n"
      "АВТОР: Доможиров Демьян (ЗИВТ-252, ОмГТУ)\n"
      "=============================================================\n\n"

      "НАЗНАЧЕНИЕ:\n"
      "Печатает таблицу соотношения температур Цельсия к Фарингейту\n\n"

      "ОГРАНИЧЕНИЯ НА ВВОД:\n"
      "- Программа не принимает никакого ввода. Чтобы изменить диапазон - "
      "нужно поменять константы в коде программы\n\n"

      "ВЫВОДИМЫЕ РЕЗУЛЬТАТЫ:\n"
      "- Таблица температур\n\n"
  );
  return;
}