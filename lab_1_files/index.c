#include <stdio.h>

#define SIZE 3

int main()
{
  FILE *stream;                                                                                       // створення файлу
  char initialData[256] = "КПІ ім. Ігоря Сікорського, кафедра ЦТЕ, ТР-з21, Барський Гліб, 1 варіант"; // початкові дані

  float arr[SIZE][SIZE]; // створення двовимірного квадратного масиву розмірністю SIZE, що приймає float тип даних

  // заповнення масиву через командний рядок
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
    {
      printf("Введіть число типу float a[%d][%d]: ", i, j);
      scanf("%f", &arr[i][j]);
    }

  stream = fopen("data.bak", "w");
  fprintf(stream, "%s\n", initialData); // запис початкових даних

  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
    {
      fprintf(stream, "%f\n", arr[i][j]); // запис основних даних
    }

  printf("\nДані були успішно збережені: %s\n", initialData);
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      printf("%f\n", arr[i][j]);

  fclose(stream);

  return 0;
}