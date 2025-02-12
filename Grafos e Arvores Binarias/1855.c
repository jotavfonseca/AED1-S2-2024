#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char mapa[MAX][MAX];
bool visited[MAX][MAX][4];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int arrowToDir(char ch) {
    if (ch == '>') return 0;
    if (ch == 'v') return 1;
    if (ch == '<') return 2;
    if (ch == '^') return 3;
    return -1;
}

int main() {
    int W, H;
    scanf("%d %d", &W, &H);

    for (int i = 0; i < H; i++) {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < 4; k++)
                visited[i][j][k] = false;

    int r = 0, c = 0, dir = 0;

    while (1) {
        if (r < 0 || r >= H || c < 0 || c >= W) {
            printf("!\n");
            break;
        }

        if (visited[r][c][dir]) {
            printf("!\n");
            break;
        }
        visited[r][c][dir] = true;

        char cell = mapa[r][c];

        if (cell == '*') {
            printf("*\n");
            break;
        }

        int novaDir = arrowToDir(cell);
        if (novaDir != -1) {
            dir = novaDir;
        }

        r += dr[dir];
        c += dc[dir];
    }

    return 0;
}
