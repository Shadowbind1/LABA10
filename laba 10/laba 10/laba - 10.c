#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>


double fa(double x);
double fb(double x);

double cos_n(double x, int N);
double cos_eps(double x, double eps);

double area_rectangle(double width, double height);
void   definition_rectangle(void);
void   draw_rectangle(int a, int b);

int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, ".UTF - 8");
    int main_choice;

    do {
        printf("\n========== ЛАБОРАТОРНАЯ РАБОТА 10 (вариант 4) ==========\n");
        printf("1) Задание 1 – две функции\n");
        printf("2) Задание 2 – cos(x) тремя способами\n");
        printf("3) Задание 3 – прямоугольник\n");
        printf("0) Выход\n");
        printf("Выберите задание: ");
        scanf("%d", &main_choice);

        switch (main_choice)
        {

        case 1:
        {
            double x;
            int choice;

            printf("\nВведите значение x: ");
            scanf("%lf", &x);

            do {
                printf("\n--- Меню задания 1 ---\n");
                printf("1) fa(x)\n");
                printf("2) fb(x)\n");
                printf("3) Произведение fa*fb\n");
                printf("4) Разность квадратов\n");
                printf("5) Удвоенная сумма\n");
                printf("0) Назад\n");
                printf("Выбор: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1: printf("fa(x) = %lf\n", fa(x)); break;
                case 2: printf("fb(x) = %lf\n", fb(x)); break;
                case 3: printf("Произведение = %lf\n", fa(x) * fb(x)); break;
                case 4: printf("Разность квадратов = %lf\n", fa(x) * fa(x) - fb(x) * fb(x)); break;
                case 5: printf("Удвоенная сумма = %lf\n", 2 * (fa(x) + fb(x))); break;
                case 0: break;
                default: printf("Неверный выбор!\n");
                }
            } while (choice != 0);
            break;
        }


        case 2:
        {
            double x, eps;
            int N;

            printf("\nВведите x (в радианах): ");
            scanf("%lf", &x);
            printf("Введите число членов ряда N: ");
            scanf("%d", &N);
            printf("Введите точность eps: ");
            scanf("%lf", &eps);

            printf("\n----- Сравнение результатов (cos) -----\n");
            printf("Стандартная cos(x)  = %.10f\n", cos(x));
            printf("Сумма N членов      = %.10f\n", cos_n(x, N));
            printf("Ряд с точностью eps = %.10f\n", cos_eps(x, eps));
            break;
        }


        case 3:
        {
            double a, b;
            double result;
            int choice;

            printf("\nEnter two sides: ");
            scanf("%lf %lf", &a, &b);

            do {
                printf("\n--- Меню задания 3 ---\n");
                printf("1) Рассчитать площадь\n");
                printf("2) Вывести определение фигуры\n");
                printf("3) Нарисовать фигуру\n");
                printf("0) Назад\n");
                printf("Выбор: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    result = area_rectangle(a, b);
                    printf("Area = %.2f\n", result);
                    break;
                case 2:
                    definition_rectangle();
                    break;
                case 3:
                    draw_rectangle((int)a, (int)b);
                    break;
                case 0: break;
                default: printf("Неверный выбор!\n");
                }
            } while (choice != 0);
            break;
        }

        case 0:
            printf("Программа завершена.\n");
            break;

        default:
            printf("Неверный выбор!\n");
        }
    } while (main_choice != 0);

    return 0;
}



double fa(double x)
{
    double y;
    y = x * x + 3 * x - 2;
    return y;
}

double fb(double x)
{
    double y;
    y = 2 * x * x - 5;
    return y;
}


double cos_n(double x, int N)
{
    double sum = 0.0;
    double term = 1.0;
    int sign = 1;

    for (int k = 0; k < N; k++) {
        sum += sign * term;
        term = term * x * x / ((2.0 * k + 1) * (2.0 * k + 2));
        sign = -sign;
    }
    return sum;
}

double cos_eps(double x, double eps)
{
    double sum = 0.0;
    double term = 1.0;
    int sign = 1;
    int k = 0;

    while (fabs(term) > eps) {
        sum += sign * term;
        term = term * x * x / ((2.0 * k + 1) * (2.0 * k + 2));
        sign = -sign;
        k++;
    }
    return sum;
}

double area_rectangle(double width, double height)
{
    double square;
    square = width * height;
    return square;
}

void definition_rectangle(void)
{
    printf("Прямоугольник — четырёхугольник, у которого все углы прямые,\n");
    printf("а противоположные стороны равны и параллельны.\n");
}

void draw_rectangle(int a, int b)
{
    printf("Рисунок прямоугольника %d x %d:\n", a, b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            printf("* ");
        printf("\n");
    }
}