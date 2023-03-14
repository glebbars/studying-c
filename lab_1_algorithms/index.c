#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\033[32m"
#define RESET "\x1b[0m"

void first_task(int **array, int array_size, int *pIteration_count);
void second_task(int **array, int array_size, int *pInteration_count);

int main(void)
{
  srand(time(NULL));
  int **array;
  int task_num,            // номер завдання
      array_size,          // розмір масиву
      i, j,                // індекси елементів масиву
      iteration_count = 0; // кількість ітерацій

  printf("\n**********************************************\nЛабораторна робота №1 на тему 'СКЛАДНІСТЬ АЛГОРИТМУ'. Виконав Барський Гліб, ТР-з21.\n\nПочаток виконання...\n\nВиберіть номер завдання: \n1: В кожному стовпчику знайти мінімальний елемент. Поміняти місцями стовпчики з найбільшим і найменшим мінімальними елементами. \n2: Провести обмін елементів матриці за вказаною схемою, любим обраним методом. \n");

  scanf("%d", &task_num);
  printf("DONE...\n Виберіть розмірність масиву:\n:: ");
  scanf("%d", &array_size);

  // використовуємо функцію malloc для динамічного розподілу пам'яті під часу run time. Це робиться тому що ми не знаємо скільки нам потрібно виділити пам'яті с самого початку виконання програми
  array = (int **)malloc(array_size * sizeof(int *));
  for (int i = 0; i < array_size; i++)
    array[i] = (int *)malloc(array_size * sizeof(int));

  // заповнюємо масив рандомними числами від -999 до 999
  for (i = 0; i < array_size; i++)
    for (j = 0; j < array_size; j++)
      array[i][j] = -999 + rand() % 1999;

  switch (task_num)
  {
  case 1:
    first_task(array, array_size, &iteration_count);
    break;

  case 2:
    second_task(array, array_size, &iteration_count);
    break;

  default:
    printf("Хибний вибір...\nБудь ласка оберіть варіант завдання серед запропонованих");
    return 0;
    break;
  }
  unsigned int end_time = clock();

  printf("\nВиконання завершено.\nЧас виконання програми: %d ms | %dµs\nКількість ітерацій: %d\n", end_time / 1000, end_time, iteration_count);
}

void first_task(int **array, int array_size, int *pIteration_count)
{
  int i, j, // індекси елементів масиву
      temp; // тимчасове значення при перестановці

  int min_value, max_value, min_value_column, max_value_column; // мінімальне та максимальне значення серед мінімільних елементів кожного стовпчика та індекси їх стовпчиків
  int min_temp;

  printf("\n**********************************************\nПочаток виконання завдання №1...\n\nПошук найменшого та найбільшого значення в масиві серед мінімальних елементів кожного стовпчика...\n**********************************************\nМАСИВ:\n\n");

  max_value = min_value = array[0][0];     // присваюємо початкові значення
  max_value_column = min_value_column = 0; // присваюємо початкові значення

  for (j = 0; j < array_size; j++)
  {
    min_temp = array[0][j];
    for (i = 1; i < array_size; i++) // починаємо з другого елементу, тому що ми на одній строчці вище вже присвоїли значення першого
    {
      if (array[i][j] < min_temp)
      {
        min_temp = array[i][j];
        *pIteration_count += 1;
      }
    }
    if (min_temp < min_value)
    {
      min_value = min_temp;
      min_value_column = j;
    }
    if (min_temp > max_value)
    {
      max_value = min_temp;
      max_value_column = j;
    }
    *pIteration_count += 1;
  }

  for (i = 0; i < array_size; i++)
  {
    for (j = 0; j < array_size; j++)
    {
      if (array[i][j] == min_value)
        printf(RED "%5.d" RESET, array[i][j]); // виділяємо найменше мінімальне значення червоним
      else if (array[i][j] == max_value)
        printf(GREEN "%5.d" RESET, array[i][j]); // виділяємо найбільше мінімальне значення зеленим
      else
        printf("%5.d", array[i][j]);
    }
    printf("\n");
  }

  printf(
      "\n**********************************************\n\n- Найменший елемент: %d (індекс стовпчику: %d).\n- Найбільший елемент: %d (індекс стовпчику: %d).\n\nЗаміна місцями %d та %d стовпчика(Згідно умови)", min_value, min_value_column, max_value, max_value_column, min_value_column, max_value_column);

  for (i = 0; i < array_size; i++)
  {
    temp = array[i][min_value_column];
    array[i][min_value_column] = array[i][max_value_column];
    array[i][max_value_column] = temp;
    *pIteration_count = *pIteration_count + 3;
  }

  printf("\nНовий вигляд маcиву...\n**********************************************\n\n");

  for (i = 0; i < array_size; i++)
  {
    for (j = 0; j < array_size; j++)
    {
      if (array[i][j] == min_value)
        printf(RED "%5.d" RESET, array[i][j]); // виділяємо найменше мінімальне значення червоним
      else if (array[i][j] == max_value)
        printf(GREEN "%5.d" RESET, array[i][j]); // виділяємо найбільше мінімальне значення зеленим
      else
        printf("%5.d", array[i][j]);
    }
    printf("\n");
  }
  printf("\n**********************************************\n");
  free(array); // делакуємо пам'ять виділену раніше для масиву функцією malloc
}

void second_task(int **array, int array_size, int *pIteration_count)
{
  int i, j, // індекси елементів масиву
      temp; // тимчасове значення при перестановці

  printf("Початок виконання завдання №2...\n\n Провести обмін елементів матриці за вказаною схемою, любим обраним методом.\n\n**********************************************\nМАСИВ:\n\n");

  for (i = 0; i < array_size; i++)
  {
    for (j = 0; j < array_size; j++)
    {
      if (i == j || array_size - i - 1 == j)
        printf(BLUE "%5.d" RESET, array[i][j]); // виділяємо діагональні елементи синім
      else if ((i < j || array_size - j - 1 > i) && (i > j || array_size - j - 1 < i))
      {
        if (j < array_size / 2)
          printf(GREEN "%5.d" RESET, array[i][j]); // виділяємо зеленим ліву частину
        else
          printf(RED "%5.d" RESET, array[i][j]); // виділяємо червоним праву частину
      }
      else
        printf("%5.d", array[i][j]);
    }
    printf("\n");
  }

  printf("\n**********************************************\n\nОбробка....\n");

  for (i = 0; i < array_size; i++)
    for (j = 0; j < array_size / 2; j++)
    {
      if ((i < j || array_size - j - 1 > i) && (i > j || array_size - j - 1 < i))
      {
        temp = array[i][j];
        array[i][j] = array[i][array_size - j - 1];
        array[i][array_size - j - 1] = temp;
        *pIteration_count = *pIteration_count + 3;
      }
      *pIteration_count += 1;
    }

  printf("Вивід обробленого масиву:\n\n**********************************************\nМАСИВ:\n\n");

  for (i = 0; i < array_size; i++)
  {
    for (j = 0; j < array_size; j++)
    {
      if (i == j || array_size - i - 1 == j)
        printf(BLUE "%5.d" RESET, array[i][j]); // виділяємо діагональні елементи синім
      else if ((i < j || array_size - j - 1 > i) && (i > j || array_size - j - 1 < i))
      {
        if (j < array_size / 2)
          printf(RED "%5.d" RESET, array[i][j]); // виділяємо червоним ліву частину
        else
          printf(GREEN "%5.d" RESET, array[i][j]); // виділяємо зеленим праву частину
      }
      else
        printf("%5.d", array[i][j]);
    }
    printf("\n");
  }

  printf("\n**********************************************\n");
  free(array); // делакуємо пам'ять виділену раніше для масиву функцією malloc
}