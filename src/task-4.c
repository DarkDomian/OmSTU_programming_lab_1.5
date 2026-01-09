/* TODO:
    Изобразить на экране движение шара по бильярду без луз. Скорость движения
   шара уменьшается с постоянным ускорением.
*/

#define TABLE_WIDTH 20
#define TABLE_LENGTH 10

#define WALL_CHAR '#'
#define EMPT_CHAR ' '
#define BALL_CHAR '@'

typedef struct {
  float pos_x;
  float pos_y;
  float velosety;
  float dir_x;
  float dir_y;
  float deceleration;
} Ball_t;

typedef struct {
  int width;
  int length;
} Table_t;

#define CLER_TERM "\033c\033[H"

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void printWelcomeMessage(void);
void getModelProp(Ball_t *ball, Table_t *table);
void mainLoop(Ball_t *ball, Table_t *table);
void calcModel(Ball_t *ball, Table_t *table);

void printModel(Ball_t *ball, Table_t *table);

int main(void) {
  // initialize simulation with:
  // - taking vector of ball
  // - print welcome message
  //   int table_width, table_length;
  Ball_t ball;
  Table_t table;

  printWelcomeMessage();
  getModelProp(&ball, &table);

  // game loop:
  // - clear field, return cursor on the start
  // - use sleep
  // - print new filed with new position of the ball
  mainLoop(&ball, &table);
}

void printWelcomeMessage(void) {
  printf(
      "===================================================\n"
      "ПРОГРАММА: Моделирование поведения бильярдного шара\n"
      "ВЕРСИЯ: 1.0\n"
      "АВТОР: Доможиров Демьян (ЗИВТ-252, ОмГТУ)\n"
      "===================================================\n\n"

      "НАЗНАЧЕНИЕ:\n"
      "Смоделировать движение шара на бильярдном поле, с постоянным "
      "замедлением\n\n"

      "ОГРАНИЧЕНИЯ:\n"
      "- Программа не принимает никакого ввода. Чтобы изменить параметры - "
      "нужно поменять константы в коде программы\n\n"

      "ВЫВОДИМЫЕ РЕЗУЛЬТАТЫ:\n"
      "- Строка до обработки (before)\n"
      "- Строка после обработки, замена произведена (after)\n\n");
  return;
}

void getModelProp(Ball_t *ball, Table_t *table) {
  printf("Введите размеры поля (длина, ширина):\n");
  scanf("%d %d", &(table->length), &(table->width));
  table->length += 2;
  table->width += 2;

  printf("Введите позицию мяча (x, y) в пределах поля:\n");
  scanf("%f %f", &(ball->pos_x), &(ball->pos_y));
  // normalize ball position
  // can't be equal zero - need update
  if ((ball->pos_x < 1 || ball->pos_x > (table->length - 1)) ||
      (ball->pos_y < 1 || ball->pos_y > (table->width - 1))) {
    ball->pos_x = (int)ball->pos_x % table->length;
    ball->pos_y = (int)ball->pos_y % table->width;
    if (ball->pos_x < 0) ball->pos_x += table->length;
    if (ball->pos_y < 0) ball->pos_y += table->width;
  }

  printf("Введите скорость мяча (float, пиксель/тик):\n");
  scanf("%f", &(ball->velosety));

  printf("Введите вектор направления мяча (x, y):\n");
  scanf("%f %f", &(ball->dir_x), &(ball->dir_y));
  // vectore normalization
  float length = sqrt(ball->dir_x * ball->dir_x + ball->dir_y * ball->dir_y);
  if (length != 0) {
    ball->dir_x /= length;
    ball->dir_y /= length;
  }

  printf("Введите постоянную ускорения (float, пиксель/тик):\n");
  scanf("%f", &(ball->deceleration));
}

void mainLoop(Ball_t *ball, Table_t *table) {
  while (ball->velosety > 0) {
    printf(CLER_TERM);
    calcModel(ball, table);
    printModel(ball, table);
    sleep(1);
  }
}

void printModel(Ball_t *ball, Table_t *table) {
  char ch;

  for (int i = 0; i < table->length; ++i) {
    for (int j = 0; j < table->width; ++j) {
      if (i == 0 || i == table->length - 1)
        ch = WALL_CHAR;
      else if (j == 0 || j == table->width - 1)
        ch = WALL_CHAR;
      else if (i == round(ball->pos_x) && j == round(ball->pos_y))
        ch = BALL_CHAR;
      else
        ch = EMPT_CHAR;
      printf("%c", ch);

      if (j == table->width - 1) printf("\n");
    }
  }
  printf("position x: %2.3f, position y: %2.3f\nvelosety: %2.3f\n", ball->pos_x,
         ball->pos_y, ball->velosety);
}

void calcModel(Ball_t *ball, Table_t *table) {
  ball->velosety -= ball->deceleration;

  ball->pos_x += ball->velosety * ball->dir_x;
  ball->pos_y += ball->velosety * ball->dir_y;

  float diff;
  // handle pos_x overflow
  if (ball->pos_x > (table->length - 1.5)) {
    diff = ball->pos_x - (table->length - 1.5);

    ball->pos_x = (table->length - 1.5) - diff;
    ball->dir_x = -(ball->dir_x);
  } else if (ball->pos_x < 0.5) {
    ball->pos_x = 0.5 + fabsf(ball->pos_x);
    ball->dir_x = -(ball->dir_x);
  }

  // handle pos_y overflow
  if (ball->pos_y > (table->width - 1.5)) {
    diff = ball->pos_y - (table->width - 1.5);

    ball->pos_y = (table->width - 1.5) - diff;
    ball->dir_y = -(ball->dir_y);
  } else if (ball->pos_y < 0.5) {
    ball->pos_y = 0.5 + fabsf(ball->pos_y);
    ball->dir_y = -(ball->dir_y);
  }
}