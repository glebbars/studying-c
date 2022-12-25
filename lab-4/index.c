#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

struct dani
{                        // дані про особу
  char name[20];         // прізвище
  char initials[5];      // ініціали
  char sex[20];          // стать
  char socialStatus[30]; // соціальний стан
  char familyStatus[50]; // сімейний стан
  int age;               // вік
  int height;            // зріст
};

void sortVstavkamiStat(struct dani osoba[], int n);
void sortVstavkamiZrist(struct dani osoba[], int n);
void vyvids(struct dani osoba[], int n);
void vvidsa(struct dani *danir);

int main()
{
  /* Робота зі структурами */
  struct dani osoba[N] =
      {
          {"Петрова", "К.В", "жіноча", "вчитель", "у відносинах", 32, 175},
          {"Зайцев", "Р.О", "чоловіча", "робітник", "одружен", 48, 195},
          {"Когут", "О.К", "жіноча", "домогосподарка", "одружена", 56, 168},
          {"Скрипка", "С.Б", "чоловіча", "ученик", "в активному пошуку", 14, 156}};

  system("chcp 1251 & cls");

  printf("Введіть дані про останню особу\n");
  printf("\t(прізвище, ініціали, стать, соціальний стан, сімейний стан, вік, зріст особи)\n");
  vvidsa(&osoba[N - 1]); //  передаємо структуру за адресою

  printf("\nПочаткові дані\n");
  vyvids(osoba, N); // вивід початкових даних

  sortVstavkamiStat(osoba, N); // сортування структур за статтю

  printf("\nВідсортовані за статтю дані\n");
  vyvids(osoba, N); // вивід відсортованої за статтю структури

  sortVstavkamiZrist(osoba, N); // сортування структур за зрістом

  printf("\nВідсортовані за зрістом дані\n");
  vyvids(osoba, N); // вивід відсортованих за зрістом структур

  printf("\n\n");
  system("pause");
  return 0;
}

/* Ввід даних в поля структури, переданої за адресою */
void vvidsa(struct dani *danir)
{
  scanf("%s%s%s%s%s%d%d", (*danir).name, (*danir).initials, (*danir).sex, (*danir).socialStatus, (*danir).familyStatus, &(*danir).age, &(*danir).height);
}

/* Сортування простими вставками за зростанням (від А до Я) за елементом "sex" */
void sortVstavkamiStat(struct dani osoba[], int n)
{
  int i, j;        // індекси елементів масиву
  struct dani key; // структура для порівняння при сортуванні

  for (i = 1; i < n; i++)
  {
    key = osoba[i];
    j = i - 1;

    while (j >= 0 && strcmp(osoba[j].sex, key.sex) > 0) // для порівняння двох строк використовуємо функцію strcmp. Для сортування за зростанням (від А до Я) потрібно, щоб результат функції був 1
    {
      osoba[j + 1] = osoba[j];
      j--;
    }
    osoba[j + 1] = key;
  }
}

/* Сортування простими вставками за зростанням за елементом "height" */
void sortVstavkamiZrist(struct dani osoba[], int n)
{
  int i, j;        // індекси елементів масиву
  struct dani key; // структура для порівняння при сортуванні

  for (i = 1; i < n; i++)
  {
    key = osoba[i];
    j = i - 1;

    while (j >= 0 && osoba[j].height > key.height) // порівнюємо зріст для сортування за зростанням
    {
      osoba[j + 1] = osoba[j];
      j--;
    }
    osoba[j + 1] = key;
  }
}

/* Вивід полів структури */
void vyvids(struct dani osoba[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("\t%s, %s, %s, %s, %s, %d, %d\n", osoba[i].name, osoba[i].initials, osoba[i].sex, osoba[i].socialStatus, osoba[i].familyStatus, osoba[i].age, osoba[i].height);
}