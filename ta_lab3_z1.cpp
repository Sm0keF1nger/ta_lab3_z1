#include <stdio.h>
#include <stdbool.h>

double geometricSeries(double a, double ratio, int numTerms);
void printGeometricSequence(double a, double ratio, int numTerms);

int main() {
    double firstTerm, ratio;
    int numTerms;
    bool validInput = false;

    while (!validInput) {
        printf("Enter the first term of the geometric sequence: ");
        if (scanf_s("%lf", &firstTerm) != 1) {
            printf("Invalid input. Please enter a floating-point number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the ratio of the geometric sequence: ");
        if (scanf_s("%lf", &ratio) != 1) {
            printf("Invalid input. Please enter a floating-point number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the number of terms in the geometric sequence: ");
        if (scanf_s("%d", &numTerms) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
            continue;
        }

        validInput = true;
    }

    double sum = geometricSeries(firstTerm, ratio, numTerms);

    printf("\nGeometric Sequence:\n");
    printGeometricSequence(firstTerm, ratio, numTerms);

    printf("\n\nSum of the geometric sequence: %.2lf\n", sum);

    return 0;
}

double geometricSeries(double a, double ratio, int numTerms) {
    if (numTerms == 1) {
        return a;
    }
    else {
        return a + geometricSeries(a / ratio, ratio, numTerms - 1);
    }
}

void printGeometricSequence(double a, double ratio, int numTerms) {
    if (numTerms == 1) {
        printf("%.2lf\n", a);
    }
    else {
        printf("%.2lf ", a);
        printGeometricSequence(a / ratio, ratio, numTerms - 1);
    }
}
