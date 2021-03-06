/**
 * =====================================================================================
 *
 *   @file main.h
 *   @author Victor Perron (), victor@iso3103.net
 *
 *        Version:  1.0
 *        Created:  09/20/2012 08:26:35 PM
 *
 *
 *   @section DESCRIPTION
 *
 *       General headers
 *
 *   @section LICENSE
 *
 *      LGPLv2.1 http://www.gnu.org/licenses/lgpl.html
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef _SATAN_MAIN_H_
#define _SATAN_MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#define errorLog(fmt, ...) \
	do { \
		fprintf(stderr,"%s [%s:%d] " fmt "\n", __func__,__FILE__,__LINE__, ##__VA_ARGS__); \
		fflush(stderr); \
	} while(0)

#ifdef DEBUG
#define debugLog(fmt, ...) \
	do { \
		printf("%s [%s:%d] " fmt "\n", __func__,__FILE__,__LINE__, ##__VA_ARGS__); \
		fflush(stdout); \
	} while(0)

#else
#define debugLog(fmt, ...)
#endif

#define STATUS_OK 0
#define STATUS_ERROR -1

#define MAX_STRING_LEN 256
#define str_equals(a,b) strncmp(a,b,MAX_STRING_LEN) == 0

typedef struct s_process_item_t {
  pid_t pid;
  char *message_id;
  char *command;
} process_item;

#ifdef __cplusplus
}
#endif

#endif // _SATAN_MAIN_H_
