#include <parser.h>
#include <stdio.h>
#include "nats.h"

int main(void)
{
    printf("Hello, World!\n");

    natsConnection *conn = NULL;
    natsOptions *opts = NULL;
    natsStatus s = NATS_OK;

    printf("creating options\n");
    s = natsOptions_Create(&opts);
    if (s != NATS_OK) goto error;

    printf("set url\n");
    s = natsOptions_SetURL(opts, "nats://localhost:4222");
    if (s != NATS_OK) goto error;

    printf("connect\n");
    s = natsConnection_Connect(&conn, opts);
    if (s != NATS_OK) goto error;

    int64_t rtt = 0;
    s = natsConnection_GetRTT(conn, &rtt);
    if (s != NATS_OK) goto error;

    printf("rtt: %lld\n", rtt);

    s = natsConnection_Publish(conn, "foo", (const void *)"hello", 5);
    if (s != NATS_OK) goto error;

    printf("cleanup\n");
    natsConnection_Destroy(conn);
    natsOptions_Destroy(opts);

    printf("bye\n");
    return 0;

error:
    printf("===================\n");
    printf("       ERROR\n");
    printf("===================\n");
    printf("NATS Error: %u - %s\n", s, natsStatus_GetText(s));
    nats_PrintLastErrorStack(stderr);
    return 1;
}
