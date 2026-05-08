#ifndef QM_COMMON_H
#define QM_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

#include "qm_constants.h"

typedef uint8_t  u8;
typedef int8_t   i8;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint64_t u64;
typedef int64_t  i64;
typedef float    f32;
typedef double   f64;
typedef size_t   usize;
typedef ssize_t  isize;

typedef enum {
    QM_INFO,
    QM_WARN,
    QM_ERROR
} QmLogLevel_t;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

static void _qm_log(
    const char *file,
    const char *func,
    const i32 line,
    const char *msg,
    const QmLogLevel_t level
) {
    const char *header;
    switch (level) {
        case QM_INFO:
            header = "INFO";
            break;
        case QM_WARN:
            header = "WARNING";
            break;
        case QM_ERROR:
            header = "ERROR";
            break;
    }

    fprintf((level == QM_INFO) ? stdout : stderr,
        "\n=========== %s ===========\n"
        "Logger: %s\n"
        "File: %s, Function: %s, Line: %d\n",
        header, msg, file, func, line
    );
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#define QM_LOG(msg, level) do { \
    _qm_log((__FILE__), (__func__), (__LINE__), (msg), (level)); \
} while (0)

#ifdef __cplusplus
}
#endif

#endif
