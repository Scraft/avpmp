#ifndef __FIXER_H__
#define __FIXER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h> /* int64_t */

#include "files.h"

#define PACKED __attribute__((packed))

/* windows junk */
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define __cdecl

#define TRUE    1
#define FALSE   0

#define stricmp         strcasecmp
#define _stricmp        strcasecmp

#define strnicmp	strncasecmp
#define _strnicmp	strncasecmp

#define	lstrlen		strlen
#define lstrcat		strcat

#define _tcslen		strlen
#define _tcscpy		strcpy

size_t _mbclen(const unsigned char *s);

#define RGBA_MAKE(r, g, b, a)   ((((a) << 24) | ((r) << 16) | ((g) << 8) | (b)))

#define MAX_PATH	PATH_MAX

typedef int GUID;
typedef int DPID;
typedef int HINSTANCE;
typedef int WPARAM;
typedef int LPARAM;
typedef int HANDLE;

typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;
typedef char TCHAR;
typedef DWORD * LPDWORD;
typedef char * LPTSTR;

#define TEXT(x) x

typedef struct RECT
{
	int left;
	int top;
	int right;
	int bottom;
} RECT;

typedef RECT RECT_AVP;

#if !defined(__INTEL_COMPILER)
typedef int64_t __int64;
#else
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif

typedef time_t FILETIME;

/* this SYSTEMTIME is incorrect, but it is also currently unused */
typedef struct SYSTEMTIME 
{
	int wYear; /* should be uint16_t, not int32_t */
	int wMonth;
	int wDay;
	/* int wDayOfWeek; */
	int wHour;
	int wMinute;
	int wSecond;
	/* int wMilliseconds; */	
} SYSTEMTIME;

#define	VK_BACK				1
#define VK_END				2
#define VK_HOME				3
#define VK_LEFT				4
#define VK_UP				5
#define VK_RIGHT			6
#define VK_DOWN				7
#define VK_INSERT			8
#define VK_DELETE			9
#define VK_TAB				10

#define INVALID_HANDLE_VALUE		-1
#define GENERIC_WRITE			0x0001
#define CREATE_ALWAYS			0x0002
#define FILE_FLAG_RANDOM_ACCESS		0x0004
#define GENERIC_READ			0x0008
#define OPEN_EXISTING			0x0010
#define FILE_CURRENT			0x0020
#define FILE_BEGIN			0x0040	
#define FILE_END			0x0080
#define FILE_SHARE_READ			0x0100
#define FILE_SHARE_WRITE		0x0200
#define OPEN_ALWAYS			0x0400
#define FILE_ATTRIBUTE_READONLY		0x0800
#define FILE_ATTRIBUTE_DIRECTORY	0x1000
#define FILE_ATTRIBUTE_NORMAL		0x2000


HANDLE CreateFile(const char *file, int write, int x, int y, int flags, int flags2, int z);
HANDLE CreateFileA(const char *file, int write, int x, int y, int flags, int flags2, int z);
int WriteFile(HANDLE file, const void *data, int len, /* unsigned long */ void *byteswritten, int x);
int ReadFile(HANDLE file, void *data, int len, /* unsigned long */ void *bytesread, int x);
int GetFileSize(HANDLE file, int x);
int CloseHandle(HANDLE file);
int DeleteFile(const char *file);
int DeleteFileA(const char *file);
int GetDiskFreeSpace(int x, unsigned long *a, unsigned long *b, unsigned long *c, unsigned long *d);
int CreateDirectory(char *dir, int x);
int MoveFile(const char *newfile, const char *oldfile);
int MoveFileA(const char *newfile, const char *oldfile);
int CopyFile(const char *newfile, const char *oldfile, int x);
int GetFileAttributes(const char *file);
int GetFileAttributesA(const char *file);
unsigned int SetFilePointer(HANDLE file, int x, int y, int z);
int SetEndOfFile(HANDLE file);

unsigned int timeGetTime();
unsigned int GetTickCount();

typedef struct DPNAME
{
	int dwSize;
	
	char *lpszShortNameA;
	char *lpszLongNameA;
} DPNAME;

#define DP_OK	0

typedef int HRESULT;

#define DPRECEIVE_ALL			1
#define DPSYS_ADDPLAYERTOGROUP		2
#define	DPSYS_CREATEPLAYERORGROUP	3
#define DPPLAYERTYPE_PLAYER		4
#define DPSYS_DELETEPLAYERFROMGROUP	5
#define DPSYS_HOST			6
#define DPSYS_SESSIONLOST		7
#define DPSYS_SETPLAYERORGROUPDATA	8
#define DPSYS_SETPLAYERORGROUPNAME	9
#define DPEXT_HEADER_SIZE		10
#define DPERR_BUSY			11
#define DPERR_CONNECTIONLOST		12
#define DPERR_INVALIDPARAMS		13
#define DPERR_INVALIDPLAYER		14
#define DPERR_NOTLOGGEDIN		15
#define DPERR_SENDTOOBIG		16
#define DPERR_BUFFERTOOSMALL		17
#define DPID_SYSMSG			18
#define DPSYS_DESTROYPLAYERORGROUP	19
#define DPID_ALLPLAYERS			20

typedef struct DPMSG_GENERIC
{
	int dwType;
} DPMSG_GENERIC;
typedef DPMSG_GENERIC * LPDPMSG_GENERIC;

typedef struct DPMSG_CREATEPLAYERORGROUP
{
	int dwType;
	
	DPID dpId;
	int dwPlayerType;
	
	DPNAME dpnName;
} DPMSG_CREATEPLAYERORGROUP;
typedef DPMSG_CREATEPLAYERORGROUP * LPDPMSG_CREATEPLAYERORGROUP;

typedef struct DPMSG_DESTROYPLAYERORGROUP
{
	int dwType;
	
	DPID dpId;
	int dwPlayerType;	
} DPMSG_DESTROYPLAYERORGROUP;
typedef DPMSG_DESTROYPLAYERORGROUP * LPDPMSG_DESTROYPLAYERORGROUP;

#define JOYCAPS_HASR		1

typedef struct JOYINFOEX
{
	int dwXpos;
	int dwYpos;
	int dwRpos;
	int dwUpos;
	int dwVpos;
	int dwPOV;
} JOYINFOEX;

typedef struct JOYCAPS
{
	int wCaps;
} JOYCAPS;

#ifdef __cplusplus
};
#endif

#endif
