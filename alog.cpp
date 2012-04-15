//
//  alog.cpp
//  full function of alog
//
//  Created by Dawen Rie on 12-4-5.
//  Copyright (c) 2012年 G4 Workshop. All rights reserved.
//
#include "alog.h"

#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

#include <event2/buffer.h>

static pthread_mutex_t alog_mutex = PTHREAD_MUTEX_INITIALIZER;
static FILE *logfp = stdout;

void alog_setfp(FILE *fp){
    pthread_mutex_lock(&alog_mutex);
    logfp = fp;
    pthread_mutex_unlock(&alog_mutex);
}
static void printnow(){
    time_t now = time(NULL);
    struct tm *nowtm = localtime(&now);
    static char buf[64];
    strftime(buf, sizeof buf, "[%m%d %H:%M:%S] ", nowtm);
    fprintf(logfp, "%s", buf);
}

void alog(const char *file, long line, alogLevel level, const char *format, ...){
    pthread_mutex_lock(&alog_mutex);
    
    printnow();
    
    if(level == ALOG_LEVEL_ERROR)
        fprintf(logfp, "ERROR:%s(%ld):", file, line);
    
    va_list va;
    va_start(va, format);
    vfprintf(logfp, format, va);
    va_end(va);
    fprintf(logfp, "\n");
    fflush(logfp);
    pthread_mutex_unlock(&alog_mutex);
}

void alog_bin(unsigned char *buf, size_t length)
{
    pthread_mutex_lock(&alog_mutex);
    printnow();
    for (size_t i = 0; i<length; ++i){
        fprintf(logfp, "%02X ", buf[i]);
    }
    fprintf(logfp, "\n");
    fflush(logfp);
    pthread_mutex_unlock(&alog_mutex);
}

void alog_buffer(evbuffer *evbuff)
{
    size_t length = evbuffer_get_length(evbuff);
    unsigned char *buf = new unsigned char[length];
    evbuffer_copyout(evbuff, buf, length);
    alog_bin(buf, length);
    delete buf;
}
