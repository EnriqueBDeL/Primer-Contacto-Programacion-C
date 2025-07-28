#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *filename, int *dim) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    size_t read_size = fread(buffer, 1, size, f);
    buffer[read_size] = '\0';

    fclose(f);
    *dim = (int)read_size;
    return buffer;
}

char *read_text(int *dim)
{
    int size = 2, i = 0;
    char *s = malloc(size * sizeof(char)), t;

    while(( t = getchar() ) != '\n') {
        if(t > 126 || t < 33)
            continue;

        if(++i >= size) {
            size *= 2;
            s = realloc(s, size * sizeof(char));
        }
        *(s + i - 1) = t;
    }

    s = realloc(s, i * sizeof(char) + 1);
    *(s + i) = '\0';
    *dim = i;
    return s;
}

int main(int argc, char **argv)
{
    int q, h = 1, d = 256, p = 0, t = 0, n, m;
    char *text, *pattern;

    printf("Rabin-Karp algorithm - Pattern matching\n");

    text = read_file("textobusq.txt", &n);
    printf("Text loaded from file (length %d)\n", n);

    printf("Pattern: ");
    pattern = read_text(&m);

    printf("Modulo [%d]: ", m);
    scanf(" %d", &q);

    for(int i = 0; i < m - 1; i++)
        h = ( h * d ) % q;

    for(int i = 0; i < m; i++) {
        p = ( d * p + pattern[i] ) % q;
        t = ( d * t + text[i] ) % q;
    }

    for(int s = 0; s <= n - m; s++) {
        if(p == t) {
            int i;
            for(i = 0; i < m && text[s + i] == pattern[i]; i++);
            if(i >= m)
                printf("Match at offset %d\n", s);
        }
        if(s < n - m) {
            t = ( ( t - h * text[s] ) * d + text[s + m] ) % q;
            if(t < 0)
                t += q;
        }
    }

    free(text);
    free(pattern);

    return 0;
}

