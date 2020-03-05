#pragma once

#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
void	err(int ret, const char* fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	const char* arg = va_arg(argp, const char*);
	printf(fmt, arg);
	va_end(argp);
	exit(ret);
}

void	errx(int ret, const char* fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	const char* arg = va_arg(argp, const char*);
	printf(fmt, arg);
	va_end(argp);
	exit(ret);
}
