#ifndef NATS_EXPERIMENTS_HEADER_FILENAME_H
#define NATS_EXPERIMENTS_HEADER_FILENAME_H

#include <stdio.h>

static void
ne_dump_buffer(const char *buffer, int len) {
    printf(">>> Dump Buffer: ");

    for (int i = 0; i < len; i++) {
        if (buffer[i] >= 32 && buffer[i] <= 126) {
            // Printable ASCII range
            putchar(buffer[i]);
        } else if (buffer[i] == '\n') {
            printf("\\n");
        } else if (buffer[i] == '\r') {
            printf("\\r");
        } else {
            printf("\\x%02x", buffer[i]);
        }
    }
    putchar('\n');
}

#endif // NATS_EXPERIMENTS_HEADER_FILENAME_H
