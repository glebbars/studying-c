#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Максимальна кількість автосервісів в масиві структур
#define MAX_AUTOSERVICES 10

struct autoservice // Структура «Автосервіс»
{
  int reg_num;         // реєстраційний номер автомобіля
  char brand[20];      // марка
  int mileage;         // пробіг
  char master[20];     // майстер, який виконав ремонт
  int renovation_cost; // сума ремонту
};

int main()
{
  struct autoservice autoservices[MAX_AUTOSERVICES];

  int num_autoservices = 0; // поточна кількість автосервісів в масиві

  // заповнення масиву структур даними
  autoservices[num_autoservices].reg_num = 782901;
  strcpy(autoservices[num_autoservices].brand, "Toyota");
  autoservices[num_autoservices].mileage = 1000;
  strcpy(autoservices[num_autoservices].master, "Oleg");
  autoservices[num_autoservices].renovation_cost = 150;
  num_autoservices++;

  autoservices[num_autoservices].reg_num = 467291;
  strcpy(autoservices[num_autoservices].brand, "Honda");
  autoservices[num_autoservices].mileage = 75000;
  strcpy(autoservices[num_autoservices].master, "Mark");
  autoservices[num_autoservices].renovation_cost = 2000;
  num_autoservices++;

  FILE *stream;
  stream = fopen("autoservice.txt", "w"); // відкриття файлу у форматі запису
  if (stream == NULL)
  {
    printf("Помилка при відкриванні файлу\n");
    exit(1);
  }

  printf("\nПопередньо сформовані та підготовлені для запису в файл дані:\n"); // друкування попередньо сформованих та підготовлених для запису в файл даних.
  for (int i = 0; i < num_autoservices; i++)
  {
    printf("%d %s %d %s %d\n", autoservices[i].reg_num, autoservices[i].brand, autoservices[i].mileage, autoservices[i].master, autoservices[i].renovation_cost);
  }

  for (int i = 0; i < num_autoservices; i++)
  {
    fprintf(stream, "%d %s %d %s %d\n", autoservices[i].reg_num, autoservices[i].brand, autoservices[i].mileage, autoservices[i].master, autoservices[i].renovation_cost); // запис кожної структури у файл
  }

  fclose(stream); // закриття файлу

  stream = fopen("autoservice.txt", "r"); // відкриття файлу у форматі читання
  if (stream == NULL)
  {
    printf("Помилка при відкриванні файлу\n");
    exit(1);
  }

  for (int i = 0; i < num_autoservices; i++)
  {
    fscanf(stream, "%d %s %d %s %d\n", &autoservices[i].reg_num, autoservices[i].brand, &autoservices[i].mileage, autoservices[i].master, &autoservices[i].renovation_cost); // читання структур з файлу
  }

  fclose(stream); // закриття файлу

  printf("\nРезультат виконання операції читання даних із файлу:\n"); // друкування попередньо сформованих та підготовлених для запису в файл даних.
  for (int i = 0; i < num_autoservices; i++)
  {
    printf("%d %s %d %s %d\n", autoservices[i].reg_num, autoservices[i].brand, autoservices[i].mileage, autoservices[i].master, autoservices[i].renovation_cost);
  }

  return 0;
}
