#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){
    int H, L, i, j;
    scanf("%d %d", &H, &L);
    int grid[205][205], vis[205][205] = {0};
    for(i = 0; i < H; i++){
        for(j = 0; j < L; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int ans = INT_MAX, di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    int queue[50000][2];
    for(i = 0; i < H; i++){
        for(j = 0; j < L; j++){
            if(!vis[i][j]){
                int color = grid[i][j], size = 0, front = 0, rear = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
                vis[i][j] = 1;
                while(front < rear){
                    int ci = queue[front][0], cj = queue[front][1];
                    front++;
                    size++;
                    int k;
                    for(k = 0; k < 4; k++){
                        int ni = ci + di[k], nj = cj + dj[k];
                        if(ni >= 0 && ni < H && nj >= 0 && nj < L && !vis[ni][nj] && grid[ni][nj] == color){
                            vis[ni][nj] = 1;
                            queue[rear][0] = ni;
                            queue[rear][1] = nj;
                            rear++;
                        }
                    }
                }
                if(size < ans) ans = size;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
