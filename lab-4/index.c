#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

enum keyString
{
  age,
  height
};

struct dani
{                        // дані про особу
  char name[20];         // прізвище й ініціали
  char sex[20];          // стать
  char socialStatus[30]; // соціальний стан
  char familyStatus[50]; // сімейний стан
  int age;               // вік
  int height;            // зріст
};

// void sortVstavkamiVik(struct dani osoba[], int n);
// void sortVstavkamiZrist(struct dani osoba[], int n);
void sortVstavkami(struct dani osoba[], int n, char sortKey[2]);
void vyvids(struct dani osoba[], int n);
void vvidsa(struct dani *danir);

int main()
{
  /* Робота зі структурами */
  struct dani osoba[N] =
      {
          {"Петрова К.В", "жіноча", "вчитель", "у відносинах", 32, 175},
          {"Зайцев Р.О", "чоловіча", "робітник", "одружен", 48, 195},
          {"Когут О.К", "жіноча", "домогосподарка", "одружена", 56, 168},
          {"Скрипка С.Б", "жіноча", "учениця", "в активному пошуку", 14, 156}};

  system("chcp 1251 & cls");

  printf("Введіть дані про останню особу\n");
  printf("\t(прізвище й ініціали, стать, соціальний стан, сімейний стан, вік, зріст особи)\n");
  vvidsa(&osoba[N - 1]);

  printf("\nПочаткові дані\n");
  vyvids(osoba, N);

  // sortVstavkamiVik(osoba, N);
  sortVstavkami(osoba, N, "a");

  printf("\nВідсортовані за віком дані\n");
  vyvids(osoba, N);

  // sortVstavkamiZrist(osoba, N);
  sortVstavkami(osoba, N, "h");

  printf("\nВідсортовані за зрістом дані\n");
  vyvids(osoba, N);

  printf("\n\n");
  system("pause");
  return 0;
}

/* Ввід даних в поля структури, переданої за адресою */
void vvidsa(struct dani *danir)
{
  scanf("%s%s%s%s%d%d", (*danir).name, (*danir).sex, (*danir).socialStatus, (*danir).familyStatus, &(*danir).age, &(*danir).height);
}

/* Сортування простими вставками за елементом "age" */
// void sortVstavkamiVik(struct dani osoba[], int n)
// {
//   int i, j;
//   struct dani key;

//   for (i = 1; i < n; i++)
//   {
//     key = osoba[i];
//     j = i - 1;

//     while (j >= 0 && osoba[j].age > key.age)
//     {
//       osoba[j + 1] = osoba[j];
//       j--;
//     }
//     osoba[j + 1] = key;
//   }
// }

/* Сортування простими вставками */
void sortVstavkami(struct dani osoba[], int n, char sortKey[2])
{
  int i, j;
  struct dani key;

  for (i = 1; i < n; i++)
  {
    key = osoba[i];
    j = i - 1;

    /* Сортування за елементом "age" */
    if (strcmp(sortKey, "a") == 0)
    {
      while (j >= 0 && osoba[j].age > key.age)
      {
        osoba[j + 1] = osoba[j];
        j--;
      }
      osoba[j + 1] = key;
    }

    /* Сортування за елементом "height" */
    else if (strcmp(sortKey, "h") == 0)
    {
      while (j >= 0 && osoba[j].height > key.height)
      {
        osoba[j + 1] = osoba[j];
        j--;
      }
      osoba[j + 1] = key;
    }
  }
}

// /* Сортування простими вставками за елементом "height" */
// void sortVstavkamiZrist(struct dani osoba[], int n)
// {
//   int i, j;
//   struct dani key;

//   for (i = 1; i < n; i++)
//   {
//     key = osoba[i];
//     j = i - 1;

//     while (j >= 0 && osoba[j].height > key.height)
//     {
//       osoba[j + 1] = osoba[j];
//       j--;
//     }
//     osoba[j + 1] = key;
//   }
// }

/* Вивід полів структури */
void vyvids(struct dani osoba[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("\t%s, %s, %s, %s, %d, %d\n", osoba[i].name, osoba[i].sex, osoba[i].socialStatus, osoba[i].familyStatus, osoba[i].age, osoba[i].height);
}