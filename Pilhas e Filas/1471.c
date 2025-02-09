#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOLUNTEERS 10000

int main() {
    int N, R;
    int returned[MAX_VOLUNTEERS + 1];  // Array to keep track of volunteers who returned
    int volunteerId;
    
    // Loop to read multiple test cases until EOF
    while (scanf("%d %d", &N, &R) != EOF) {
        memset(returned, 0, sizeof(returned));  // Initialize the array
        
        // Read the IDs of the volunteers who returned
        for (int i = 0; i < R; i++) {
            scanf("%d", &volunteerId);
            returned[volunteerId] = 1;  // Mark the volunteer as returned
        }
        
        // Check which volunteers did not return
        int any_missing = 0;
        for (int i = 1; i <= N; i++) {
            if (!returned[i]) {
                printf("%d ", i);
                any_missing = 1;
            }
        }
        
        if (!any_missing) {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}
