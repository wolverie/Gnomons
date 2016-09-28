#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "lowsrc.h"
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define FLMIN 0
#define _MOPENR 0x1
#define _MOPENW 0x2
#define _MOPENA 0x4
#define _MTRUNC 0x8
#define _MCREAT 0x10
#define _MBIN 0x20
#define _MEXCL 0x40
#define _MALBUF 0x40
#define _MALFIL 0x80
#define _MEOF 0x100
#define _MERR 0x200
#define _MLBF 0x400
#define _MNBF 0x800
#define _MREAD 0x1000
#define _MWRITE 0x2000
#define _MBYTE 0x4000
#define _MWIDE 0x8000
#define O_RDONLY 0x0001
#define O_WRONLY 0x0002
#define O_RDWR 0x0004
#define O_CREAT 0x0008
#define O_TRUNC 0x0010
#define O_APPEND 0x0020
#define CR 0x0d
#define LF 0x0a
extern const long _nfiles;
char flmod[IOSTREAM];
unsigned char sml_buf[IOSTREAM];
#define FPATH_STDIN "C:\\stdin"
#define FPATH_STDOUT "C:\\stdout"
#define FPATH_STDERR "C:\\stderr"
extern void charput(unsigned char);
extern unsigned char charget(void);
#include <stdio.h>
FILE *_Files[IOSTREAM];
char *env_list[] = {
"ENV1=temp01",
"ENV2=temp02",
"ENV9=end",
'\0'
};
char **environ = env_list;
void _INIT_IOLIB( void )
{
_Files[0] = stdin;
_Files[1] = stdout;
_Files[2] = stderr;
if( freopen( FPATH_STDIN, "r", stdin ) == NULL )
stdin->_Mode = 0xffff;
stdin->_Mode = _MOPENR;
stdin->_Mode |= _MNBF;
stdin->_Bend = stdin->_Buf + 1;
if( freopen( FPATH_STDOUT, "w", stdout ) == NULL )
stdout->_Mode = 0xffff;
stdout->_Mode |= _MNBF;
stdout->_Bend = stdout->_Buf + 1;
if( freopen( FPATH_STDERR, "w", stderr ) == NULL )
stderr->_Mode = 0xffff;
stderr->_Mode |= _MNBF;
stderr->_Bend = stderr->_Buf + 1;
}
void _CLOSEALL( void )
{
long i;
for( i=0; i < _nfiles; i++ )
{
if( _Files[i]->_Mode & (_MOPENR | _MOPENW | _MOPENA ) )
fclose( _Files[i] );
}
}
long open(const char *name,
long mode,
long flg)
{
if( strcmp( name, FPATH_STDIN ) == 0 )
{
if( ( mode & O_RDONLY ) == 0 ) return -1;
flmod[STDIN] = mode;
return STDIN;
}
else if( strcmp( name, FPATH_STDOUT ) == 0 )
{
if( ( mode & O_WRONLY ) == 0 ) return -1;
flmod[STDOUT] = mode;
return STDOUT;
}
else if(strcmp(name, FPATH_STDERR ) == 0 )
{
if( ( mode & O_WRONLY ) == 0 ) return -1;
flmod[STDERR] = mode;
return STDERR;
}
else return -1;
}
long close( long fileno )
{
return 1;
}
long write(long fileno,
const unsigned char *buf,
long count)
{
long i;
unsigned char c;
if(flmod[fileno]&O_WRONLY || flmod[fileno]&O_RDWR)
{
if( fileno == STDIN ) return -1;
else if( (fileno == STDOUT) || (fileno == STDERR) )
{
for( i = count; i > 0; --i )
{
c = *buf++;
charput(c);
}
return count;
}
else return -1;
}
else return -1;
}
long read( long fileno, unsigned char *buf, long count )
{
long i;
if((flmod[fileno]&_MOPENR) || (flmod[fileno]&O_RDWR)){
for(i = count; i > 0; i--){
*buf = charget();
if(*buf==CR){
*buf = LF;
}
buf++;
}
return count;
}
else {
return -1;
}
}
long lseek( long fileno, long offset, long base )
{
return -1L;
}
