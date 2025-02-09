#include <stdio.h>
#include <string.h>

#define MAX_SUBMISSIONS 300

typedef struct {
    int time;
    int incorrect_attempts;
    int is_correct;
} Problem;

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        Problem problems[26] = {0};  // Um array de problemas para cada letra ('A' a 'Z')
        char problem_id;
        int time;
        char verdict[10];

        for (int i = 0; i < N; i++) {
            scanf(" %c %d %s", &problem_id, &time, verdict);

            int index = problem_id - 'A';

            if (strcmp(verdict, "correct") == 0) {
                problems[index].is_correct = 1;
                problems[index].time = time;
            } else if (strcmp(verdict, "incorrect") == 0) {
                problems[index].incorrect_attempts++;
            }
        }

        int total_problems = 0;
        int total_time = 0;

        for (int i = 0; i < 26; i++) {
            if (problems[i].is_correct) {
                total_problems++;
                total_time += problems[i].time + (problems[i].incorrect_attempts * 20);
            }
        }

        printf("%d %d\n", total_problems, total_time);
    }

    return 0;
}
