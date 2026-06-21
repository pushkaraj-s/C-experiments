/* Theory:
FILE: Container in a storage device to store data.

- Files are used to persist the data
- Operations on file: create, open, read, write, close
- Types: Text = .txt, .c
         Binary files = .exe, .mp3, .jpg

File Pointer: FILE is a (hidden) structure that needs to be created for opening a file.

A file ptr that points to this structure is used to access this file.
#syntax: 
FILR *fptr;

Opening a file: 
fptr = fopen("filename", mode); //mode can be r, w etc based on read, write

If file dosen't exsist and we open it in r9read or rb(read binary) mode, it will return NULL pointer
on the other hand if we open in w(write) or wb(write binary) mode it will create nre file and return it's pointer

BEST Practice: Check if file exsists before ading from it.

Closing a file:
fclose(fptr);

Reading from a file:
char ch;
fscanf(fptr, "%c", &ch); 

Writting to a file:
chat ch = 'A';
fprintf(fptr, "%c", ch);

*/