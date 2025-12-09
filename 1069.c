#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

void solve() {
    char line[MAX_SIZE];
    
    if (scanf("%s", line) != 1) return;

    int count_open = 0;
    int total_diamonds = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        char current_char = line[i];

        if (current_char == '<') {
            count_open++;
        } else if (current_char == '>') {
            if (count_open > 0) {
                total_diamonds++;
                count_open--;
            }
        }
    }

    printf("%d\n", total_diamonds);
}

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) return 1;

    while (N--) {
        solve();
    }

    return 0;
}
