#include <iostream>
using namespace std;
int a[100][100];
int n;

int sum (int *g){
    int c = 0;
    for (int i = 0; i<n; i++){
        c = c + g[i];
    }
    return c;
}

int check(int *g, int *no){
    int q;
    for (int i = 0; i < n; i++){
        if (no[i] == 1){
            q = 1;
            for (int j = 0; j < n; j++){
                if (g[j] == 1){
                    if (a[i][j] == 1) {
                        q = 0;
                        break;
                    }
                }
            }
            if (q == 1){
                return 0;
            }
        }
    }
    return 1;
}


int algo(int *g, int *no, int *comp){
    int v;
    int g_curr[n];
    int no_curr[n];
    int g_new[n];
    int no_new[n];


    for (int i = 0; i < n; i++){
        g_curr[i] = g[i];
        no_curr[i] = no[i];
    }

    while (sum(g_curr) != 0 && check(g_curr, no_curr) == 1){
        for (int i = 0; i < n; i++){
            if (g_curr[i] == 1){
                v = i;
                comp[i] = 1;
                break;
            }
        }
        for (int i = 0; i < n; i++){
            g_new[i] = 0;
            no_new[i] = 0;
        }
        for (int j = 0; j < n; j++){
            if (g_curr[j] == 1 && a[j][v] == 0 && j != v){
                g_new[j] = 1;
            }
        }
        for (int j = 0; j < n; j++){
            if (no_curr[j] == 1 && a[j][v] == 0 && j != v){
                no_new[j] = 1;
            }
        }

        if (sum(g_new) == 0 && sum(no_new) == 0){
            for (int p = 0; p < n; p++){
                if (comp[p] == 1){
                    printf("%d ",p);
                }
            }
            printf("\n");
        }
        else{
            algo(g_new, no_new, comp);
        }


        comp[v] = 0;
        g_curr[v] = 0;
        no_curr[v] = 1;
    }

    return 0;
}



int main(){
    int x, u;
    printf("Размерность матрицы:");
    scanf("%d", &n);
    int g[n];
    int no[n];
    int comp[n];
    for (int i = 0; i < n; i++){
        g[i] = 1;
        no[i] = 0;
        comp[i] = 0;
    }
    printf("Ввести всю матрицу смежности (0 по умолчанию) или только нижний треугольник, включая диагональ? (1):");
    scanf("%d", &x);
    if (x == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                scanf("%d", &u);
                a[i][j] = u == 0? 1:0;

                a[j][i] = a[i][j];
                if (i == j) {
                    a[i][j] = 1;
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &u);
                a[i][j] = u == 0? 1:0;
                if (i == j) {
                    a[i][j] = 1;
                }
            }
        }
    }


    algo(g, no, comp);

    return 0;
}


