#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int task1();
int task2();

int main()
{

  int task;

  while (task != 1 || task != 2)
  {
    printf("Оберіть номер завдання:\n1 - з одновимірним масивом;\n2 - з "
           "двовимірним масивом\n::");
    scanf("%d", &task);

    if (task == 1)
    {
      task1();
      break;
    }
    else if (task == 2)
    {
      task2();
      break;
    }
  }

  return 0;
}

// перше завдання про одновимірний масив
int task1()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]); // розрахунок розмірності масиву

  int i, even_index = -1;

  for (i = 0; i < size; i++)
  {
    if (arr[i] % 2 == 0)
    {
      even_index = i; // після знаходження першого чотного елементу записуємо в
                      // even_index та припиняємо цикл
      break;
    }
  }

  if (even_index != -1)
  {
    for (i = even_index; i < size - 1; i++)
    {
      arr[i] = arr[i + 1]; // сдвиг всіх елементів вліво
    }
    size--; // декрементація розмірності масиву
  }

  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// друге завдання про двовимірний масив

// функція виводу масиву в консоль
void printArray(int **arr, int rows, int cols)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

// функція запросу індексу новго рядка для двовимірного масиву
int enterNewRowIndex(int rows)
{
  int rowIndex;

  printf("Введіть індекс нового рядка: ");
  scanf("%d", &rowIndex);

  if (rowIndex < 0)
    rowIndex =
        0; // якщо було введено негативне число, то рядок буде з індексом 0

  if (rowIndex > rows)
    rowIndex = rows; // якщо було введено число більше розміру масиву на 1, то
                     // індексом буде останній в масиві

  return rowIndex;
}

int task2()
{
  int rows = 3, cols = 4;
  int i, j;

  srand(time(NULL));

  int **arr = (int **)malloc(
      rows * sizeof(int *)); // алокація пам'яті - динамічне виділення пам'яті
                             // на двовимірний масив

  for (i = 0; i < rows; i++)
  {
    arr[i] = (int *)malloc(cols * sizeof(int));
    for (j = 0; j < cols; j++)
    {
      arr[i][j] = rand() % 100; // генерація рандомних чисел від 0 до 99
    }
  }

  printf("Початковий двовимірний масив:\n");
  printArray(arr, rows, cols);

  int newRowIndex = enterNewRowIndex(rows); // індекс нового рядку

  rows++; // збільшення кількості рядків

  arr = (int **)realloc(
      arr,
      rows *
          sizeof(
              int *)); // реалокація пам'яті - динамічний перерозподіл пам'яті
                       // на двовимірний масив з новою кількістю рядків

  for (i = rows - 1; i > newRowIndex; i--)
    arr[i] = arr[i - 1]; // сдвиг рядків вниз

  arr[newRowIndex] = (int *)malloc(
      cols * sizeof(int)); // динамічне виділення пам'яті на новий рядок

  for (j = 0; j < cols; j++)
    arr[newRowIndex][j] =
        rand() % 100; // заповнення рандомними числами нового рядку

  printf("Результуючий двовимірний масив:\n");
  printArray(arr, rows, cols);

  for (i = 0; i < rows; i++)
    free(arr[i]); // делакоція пам'яті для кожного внутрішнього масиву
                  // двовимірний масиву

  free(arr); //  делакоція пам'яті двовимірний масиву

  return 0;
}