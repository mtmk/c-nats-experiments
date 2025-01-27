cmake_minimum_required(VERSION 3.21)
project(c_nats_experiments C)

# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

SET(LIB_SOURCE_FILES
        src/asynccb.c
        src/buf.c
        src/comsock.c
        src/conn.c
        src/crypto.c
        src/dispatch.c
        src/hash.c
        src/js.c
        src/jsm.c
        src/msg.c
        src/natstime.c
        src/nats.c
        src/nkeys.c
        src/nuid.c
        src/opts.c
        src/parser.c
        src/pub.c
        src/srvpool.c
        src/stats.c
        src/status.c
        src/sub.c
        src/timer.c
        src/url.c
        src/util.c
        src/glib/glib.c
        src/glib/glib_async_cb.c
        src/glib/glib_dispatch_pool.c
        src/glib/glib_gc.c
        src/glib/glib_last_error.c
        src/glib/glib_ssl.c
        src/glib/glib_timer.c)

set(LIB_WIN_SOURCE_FILES
        src/win/cond.c
        src/win/mutex.c
        src/win/sock.c
        src/win/strings.c
        src/win/thread.c)

set(LIB_UNIX_SOURCE_FILES
        src/unix/cond.c
        src/unix/mutex.c
        src/unix/sock.c
        src/unix/thread.c)


if (WIN32)
    list(APPEND LIB_SOURCE_FILES ${LIB_WIN_SOURCE_FILES})
else ()
    list(APPEND LIB_SOURCE_FILES ${LIB_UNIX_SOURCE_FILES})
endif ()

add_executable(c_nats_experiments main.c ${LIB_SOURCE_FILES})
target_include_directories(c_nats_experiments PRIVATE src)
