#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define GREEN "\033[32m"
#define RESET "\x1b[0m"

int main()
{
  srand(time(NULL));
  int arr[ROWS][COLS];

  printf("\nЛабораторна робота №2 на тему 'Методи сортування'. Виконав Барський Гліб, ТР-з21.\nЗавдання: відсортувати елементи рядків під головною діагоналю\n");

  // заповнюємо масив рандомними числами від 1  до 100
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      arr[i][j] = rand() % 100 + 1;

  printf("\nПочатковий масив %dх%d:\n", ROWS, COLS);
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%5.d", arr[i][j]);
    }
    printf("\n");
  }

  // сортування рядків матриці під головною діагоналю
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < i; j++)
    {
      for (int k = j + 1; k < i; k++)
      {
        if (arr[i][j] > arr[i][k])
        {
          int temp = arr[i][j];
          arr[i][j] = arr[i][k];
          arr[i][k] = temp;
        }
      }
    }
  }

  // Вивід відсортованого масиву
  printf("\nВідсортований масив:\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (j < i)
      {
        printf(GREEN "%5.d" RESET, arr[i][j]); // виділяємо відсортованні елементи зеленим кольором
      }
      else
      {
        printf("%5.d", arr[i][j]);
      }
    }
    printf("\n");
  }

  unsigned int end_time = clock();

  printf("\nВиконання завершено.\nЧас виконання програми: %d ms | %dµs\n", end_time / 1000, end_time);
  return 0;
}
