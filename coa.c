#include<stdio.h>
int a = 0, b = 0, c = 0, a1 = 0, b1 = 0;

int com[33] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int anum[33] = {0}, anumcp[33] = {0}, bnum[33] = {0};
int acomp[33] = {0}, bcomp[33] = {0}, pro[33] = {0}, res[33] = {0};

void binary() {
    a1 = a;
    b1 = b;
    int r, r2, i, temp;

    for (i = 0; i < 33; i++) {
        r = a1 % 2;
        a1 = a1 / 2;
        r2 = b1 % 2;
        b1 = b1 / 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;
        if (r2 == 0) {
            bcomp[i] = 1;
        }
        if (r == 0) {
            acomp[i] = 1;
        }
    }

    c = 0;
    for (i = 0; i < 33; i++) {
        res[i] = com[i] + bcomp[i] + c;
        if (res[i] >= 2) {
            c = 1;
        } else {
            c = 0;
        }
        res[i] = res[i] % 2;
    }

    for (i = 32; i >= 0; i--) {
        bcomp[i] = res[i];
    }

    if (a < 0) {
        c = 0;
        for (i = 32; i >= 0; i--) {
            res[i] = 0;
        }

        for (i = 0; i < 33; i++) {
            res[i] = com[i] + acomp[i] + c;
            if (res[i] >= 2) {
                c = 1;
            } else {
                c = 0;
            }
            res[i] = res[i] % 2;
        }

        for (i = 32; i >= 0; i--) {
            anum[i] = res[i];
            anumcp[i] = res[i];
        }
    }

    if (b < 0) {
        for (i = 0; i < 33; i++) {
            temp = bnum[i];
            bnum[i] = bcomp[i];
            bcomp[i] = temp;
        }
    }
}

void add(int num[]) {
    int i;
    c = 0;

    for (i = 0; i < 33; i++) {
        res[i] = pro[i] + num[i] + c;

        if (res[i] >= 2) {
            c = 1;
        } else {
            c = 0;
        }

        res[i] = res[i] % 2;
    }

    for (i = 32; i >= 0; i--) {
        pro[i] = res[i];
        printf("%d", pro[i]);
    }

    printf(":");

    for (i = 32; i >= 0; i--) {
        printf("%d", anumcp[i]);
    }
}

void arshift() {
    int temp = pro[32], temp2 = pro[0], i;
    
    for (i = 1; i < 33; i++) {
        pro[i - 1] = pro[i];
    }

    pro[32] = temp;

    for (i = 1; i < 33; i++) {
        anumcp[i - 1] = anumcp[i];
    }

    anumcp[32] = temp2;

    printf("\nAR-SHIFT: ");
    for (i = 32; i >= 0; i--) {
        printf("%d", pro[i]);
    }

    printf(":");

    for (i = 32; i >= 0; i--) {
        printf("%d", anumcp[i]);
    }
}

int main() {
    int i, q = 0;
    printf("\t\tBOOTH'S MULTIPLICATION ALGORITHM");

    printf("\nEnter two numbers to multiply: ");
    printf("\nBoth must be less than 2147483648");

    // Simulating for two numbers each below 2147483648
    do {
        printf("\nEnter A: ");
        scanf("%d", &a);
        printf("Enter B: ");
        scanf("%d", &b);
    } while (a >= 2147483648 || b >= 2147483648);

    printf("\nExpected product = %d", a * b);
    
    binary();
    
    printf("\n\nBinary Equivalents are: ");
    printf("\nA = ");
    for (i = 32; i >= 0; i--) {
        printf("%d", anum[i]);
    }

    printf("\nB = ");
    for (i = 32; i >= 0; i--) {
        printf("%d", bnum[i]);
    }

    printf("\nB'+ 1 = ");
    for (i = 32; i >= 0; i--) {
        printf("%d", bcomp[i]);
    }

    printf("\n\n");

    for (i = 0; i < 33; i++) {
        if (anum[i] == q) {
            printf("\n-->");
            arshift();
            q = anum[i];
        } else if (anum[i] == 1 && q == 0) {
            printf("\n-->");
            printf("\nSUB B: ");
            add(bcomp);
            arshift();
            q = anum[i];
        } else {
            printf("\n-->");
            printf("\nADD B: ");
            add(bnum);
            arshift();
            q = anum[i];
        }
    }

    printf("\nProduct is = ");
    for (i = 32; i >= 0; i--) {
        printf("%d", pro[i]);
    }

    for (i = 32; i >= 0; i--) {
        printf("%d", anumcp[i]);
    }

    return 0;
}
