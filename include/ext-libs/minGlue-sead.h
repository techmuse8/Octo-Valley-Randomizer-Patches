/*  Glue functions for the minIni library, based on the C/C++ stdio library
 *
 *  Or better said: this file contains macros that maps the function interface
 *  used by minIni to the standard C/C++ file I/O functions.
 *
 *  By CompuPhase, 2008-2014
 *  This "glue file" is in the public domain. It is distributed without
 *  warranties or conditions of any kind, either express or implied.
 */

/* map required file I/O types and functions to the standard C library */

#include <stdio.h>
#include <stdbool.h>

typedef struct sead_file {
    void* handle;
    void* device;
} sead_file;

enum seadfile_open_flags {

    seadfile_open_r = 0,
    seadfile_open_w = 1,
    seadfile_open_rw = 2, 
    seadfile_open_c = 3
};



#define INI_FILETYPE                    sead_file

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int seadfile_read(INI_FILETYPE *file, char* outBuffer, int size);
int seadfile_open(INI_FILETYPE *file, const char* filename, enum seadfile_open_flags open_flags);
int seadfile_close(INI_FILETYPE *file);
int seadfile_tell(INI_FILETYPE *file, long* pos);
int seadfile_seek(INI_FILETYPE *file, int pos);

#ifdef __cplusplus
}
#endif // __cplusplus

#define ini_openread(filename,file)     (seadfile_open(file,filename,seadfile_open_r) != NULL)
//#define ini_openwrite(filename,file)    ((*(file) = fopen((filename),"wb")) != NULL)
//#define ini_openrewrite(filename,file)  ((*(file) = fopen((filename),"r+b")) != NULL)
#define ini_close(file)                 (seadfile_close(file) == 1)
#define ini_read(buffer,size,file)      (seadfile_read(file,buffer,size) != NULL)
//#define ini_write(buffer,file)          (fputs((buffer),*(file)) >= 0)
//#define ini_rename(source,dest)         (rename((source), (dest)) == 0)
//#define ini_remove(filename)            (remove(filename) == 0)

#define INI_FILEPOS                     long int
#define ini_tell(file,pos)              (seadfile_tell(file,pos))
#define ini_seek(file,pos)              (seadfile_seek(file,*(pos)) == 1)


/* for floating-point support, define additional types and functions */
//#define INI_REAL                        float
#define ini_ftoa(string,value)          sprintf((string),"%f",(value))
#define ini_atof(string)                (INI_REAL)strtod((string),NULL)
