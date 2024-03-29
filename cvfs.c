#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<iostream>
//#include<io.h>

#define MAXINODE 5

#define READ 1
#define WRITE 2

#define MAXFILESIZE 100

#define REGULAR 1//file type .c,.txt
#define SPECIAL 2// 

#define START 0
#define CURRENT 1
#define END 2

typedef struct superblock
{
    int totalnodes;
    int freeinode;
}SUPERBLOCK,*PSUPERBLOCK;

typedef struct inode
{
    char filename[50];
    int inodenumber;
    int filesize;
    int fileactualsize;
    int filetype;
    char *Buffer;
    int Linkcount;
    int referencecount;
    int permission;//1 23
    struct inode *next;
}INODE,*PINODE,***PPINODE;

typedef struct filetable
{
    int readoffset;
    int writeoffsite;
    int count;
    int mode;
    PINODE ptrinode;
}*FILETABLE,*PFILETABLE;

typedef struct ufdt
{
    PFILETABLE ptrfiletable;
}UFDT;

UFDT UFDTArr[50];
SUPERBLOCK SUPERBLOCKobj;
PINODE head = NULL;

void man(char *name)
{
    if(name == NULL)return;

    if(strcmp(name,"create")==0 )
    {
        printf("Description : used to create new regular file \n");
        printf("Usage : create File_name permission\n");
    }
    else if(strcmp(name,"read")==0)
    {
        printf("Description : Used to create new regular file\n");
        printf("Usage: create File_name Permission\n");
    }
    else if(strcmp(name,"ls")==0)
    {
        printf("Description : Used to read data from regular file\n");
        printf("Usage : write File_name\n After this enter the data that we want to write\n");
    }
    else if(strcmp(name,"stat")==0)
    {
        printf("Description : Used to display information of file\n ");
        printf("Usage : stat File_name\n");
    }
    else if(strcmp(name,"fstat")==0)
    {
        printf("Description : Used to display information of file\n");
        printf("Usage : truncate File_name\n");
    }
    else if(strcmp(name,"truncate")==0)
    {
        printf("Description : Used to remove data from file\n");
        printf("Usage : truncate File_name\n");
    }
    else if(strcmp(name,"open")==0)
    {
        printf("Description : Used to open existing file\n");
        printf("Usage : open file_name mode");
    }
    else if(strcmp(name,"close")==0)
    {
        printf("Description : Used to close opened file\n");
    }
    else if(strcmp(name,"closeall")==0)
    {
        printf("Description : Used to close all opened file\n");
        printf("Usage : closeall\n");
    }
    else if(strcmp(name,"lseek")==0)
    {
        printf("Description : Used to change file offset\n");
        printf("Usage : lseek File_Name ChangeInoffset startpoint\n");
    }
    else if(strcmp(name,"rm")==0)
    {
        printf("Description : Used to delete the file\n");
        printf("Usage : rm File_Name\n");
    }

else
{
    printf("ERROR : NO manual entry available:\n");
}
}

void displayHelp()
{
    printf("Is : To List out all files\n");
    printf("clear : To clear console\n");
    printf("open : To open the file\n");
    printf("close : To close the file \n");
    printf("read : to read the contents from file\n");
    printf("write : to write the content into file\n");
    printf("exit: To terminate file system");
    printf("stat : To display information of file using name \n");
    printf("fstat : To display information of file using file descriptor\n");
    printf("truncate : To remove all data from file\n");
    printf("rm : To Delete the file\n");
}

int GetFDFromName(char *name)
{
    int i=0;
    while(i<MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
             if(strcmp((UFDTArr[i].ptrfiletable->ptrinode->filename),name)==0)
                      break;
        }
        i++;
    }

    if(i==MAXINODE)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

PINODE Get_Inode(char*name)
{
    PINODE temp = head;
    int i=0;

    while(temp != NULL)
    {
        if(strcmp(name,temp->filename)==0)
        {
            break;
        }
        temp=temp->next;
    }
}

void CreateDILB()
{
    int i=1;
    PINODE newn = NULL;
    PINODE temp = head;

    while(i<=MAXINODE)
    {
        newn = (PINODE)malloc(sizeof(INODE));
        
        newn->Linkcount = 0;
        newn->referencecount=0;
        newn->filetype=0;
        newn->filesize=0;

        newn->Buffer = NULL;
        newn->next = NULL;

        newn->inodenumber=i;

        if(temp == NULL)
        {
            head=newn;
            temp=head;
        }
        else
        {
            temp->next=newn;
            temp=temp->next;
        }
        i++;
    }



    printf("DILB created succesfully \n");
}

void InitialiseSuperBlock()
{
    int i = 0;
    while(i<MAXINODE)
    {
        UFDTArr[i].ptrfiletable = NULL;
        i++;
    }
     
     SUPERBLOCKobj.totalnodes = MAXINODE;
     SUPERBLOCKobj.freeinode = MAXINODE;
}

int CreateFile(char *name,int permission)
{
    int i=0;
    PINODE temp = head;

    if((name==NULL) || (permission==0) || (permission > 3))
    {
        return -1;
    }
    if(SUPERBLOCKobj.freeinode == 0)
    {
        return -2;
    }
    (SUPERBLOCKobj.freeinode)--;

    if(Get_Inode(name) != NULL)
    {
        return -3;
    }
    while(temp != NULL)
    {
        if (temp->filetype == 0)
        {
            break;
        }
        temp=temp->next;
        
    }
    while(i<MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
             break;
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));

    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = permission;
    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffsite = 0;

    UFDTArr[i].ptrfiletable->ptrinode = temp;

    strcpy(UFDTArr[i].ptrfiletable->ptrinode->filename,name);
    UFDTArr[i].ptrfiletable->ptrinode->filetype = REGULAR;
    UFDTArr[i].ptrfiletable->ptrinode->referencecount=1;
    UFDTArr[i].ptrfiletable->ptrinode->Linkcount=1;
    UFDTArr[i].ptrfiletable->ptrinode->filesize = MAXFILESIZE;
    UFDTArr[i].ptrfiletable->ptrinode->fileactualsize = 0;
    UFDTArr[i].ptrfiletable->ptrinode->permission = permission;
    UFDTArr[i].ptrfiletable->ptrinode->Buffer = (char *)malloc(MAXFILESIZE);

    return i;
}

//rm_File(Demo.txt)
int rm_File(char *name)
{
    int fd = 0;

    fd = GetFDFromName(name);
    if(fd == -1)
    {
        return -1;
    }

    (UFDTArr[fd].ptrfiletable->ptrinode->Linkcount)--;

    if(UFDTArr[fd].ptrfiletable->ptrinode->Linkcount == 0)
    {
        UFDTArr[fd].ptrfiletable->ptrinode->filetype = 0;
       //free(UFDTArr[fd].ptrtable->ptrinode->Filetype=0;
       free(UFDTArr[fd].ptrfiletable);
    }

    UFDTArr[fd].ptrfiletable = NULL;
    (SUPERBLOCKobj.freeinode)++;
}

int ReadFile(int fd,char *arr,int isize)
{
    int read_size = 0;
    if(UFDTArr[fd].ptrfiletable == NULL)   return -1;

    if(UFDTArr[fd].ptrfiletable->mode !=READ && UFDTArr[fd].ptrfiletable->mode != READ+WRITE)
        return -2;

    if(UFDTArr[fd].ptrfiletable->ptrinode->permission != READ && UFDTArr[fd].ptrfiletable->ptrinode->permission != READ+WRITE)
        return -2;

    if(UFDTArr[fd].ptrfiletable->readoffset == UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize)
      return -3;

    if(UFDTArr[fd].ptrfiletable->ptrinode->filetype != REGULAR)
     
     return -4;

     read_size = (UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset);

     if(read_size < isize)
     {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),read_size);
        
        UFDTArr[fd].ptrfiletable->readoffset = UFDTArr[fd].ptrfiletable->readoffset + read_size;
    }
    else
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),isize);

        (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + isize ;
    }
    return isize;
}

int WriteFile(int fd,char *arr,int isize)
{
    if(((UFDTArr[fd].ptrfiletable->mode) != WRITE) && ((UFDTArr[fd].ptrfiletable->mode) != READ+WRITE)) 
          return -1;
    
    if(((UFDTArr[fd].ptrfiletable->ptrinode->permission) != WRITE) && ((UFDTArr[fd].ptrfiletable->mode) != READ+WRITE))
         return -1;

    if((UFDTArr[fd].ptrfiletable->writeoffsite) == MAXFILESIZE)
        return -2;

    if((UFDTArr[fd].ptrfiletable->ptrinode->filetype) != REGULAR)
       return -3;

    strncpy((UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->writeoffsite),arr,isize);

    (UFDTArr[fd].ptrfiletable->writeoffsite) = (UFDTArr[fd].ptrfiletable->writeoffsite)+isize;

    (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) == (UFDTArr[fd].ptrfiletable ->ptrinode->fileactualsize) + isize;

    return isize;
}

int openfile(char *name , int mode)
{
    int i = 0;
    PINODE temp = NULL;

    if(name == NULL || mode <=0)
       return -1;

    temp = Get_Inode(name);

    if(temp==NULL)
       return -2;

    if(temp->permission < mode)
       return -3;

    while(i<5)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
           break;
        i++;
    }
    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));
    if(UFDTArr[i].ptrfiletable == NULL)
       return -1;
    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = mode;

    if(mode == READ + WRITE)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
        UFDTArr[i].ptrfiletable->writeoffsite = 0;
    }
   else if(mode == READ)
   {
    UFDTArr[i].ptrfiletable->readoffset = 0;
   }
   else if(mode == WRITE)
   {
    UFDTArr[i].ptrfiletable->writeoffsite = 0;
   }

   UFDTArr[i].ptrfiletable->ptrinode = temp;
   (UFDTArr[i].ptrfiletable->ptrinode->referencecount)++;

   return i;
}

void closefilebyname(int fd)
{
    UFDTArr[fd].ptrfiletable->readoffset=0;
    UFDTArr[fd].ptrfiletable->writeoffsite=0;
    (UFDTArr[fd].ptrfiletable->ptrinode->referencecount)--;
}

int closefilebyname(char *name)
{
    int i=0;
    i = GetFDFromName(name);

    if(i==-1)
    {
        return -1;
    }

    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffsite=0;
    (UFDTArr[i].ptrfiletable->ptrinode->referencecount)--;

    return 0;
}

void closeallfile()
{
    int i=0;
    while(i<5)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
            UFDTArr[i].ptrfiletable->readoffset = 0;
            UFDTArr[i].ptrfiletable->writeoffsite=0;
         (UFDTArr[i].ptrfiletable->ptrinode->referencecount)--;
          break;
        }
        i++;
    }
}
int LseekFile(int fd,int size,int from)
{
    if((fd<0) || (from > 2)) 
       return -1;
    
    if(UFDTArr[fd].ptrfiletable == NULL)
       return -1;

    if((UFDTArr[fd].ptrfiletable->mode == READ) || (UFDTArr[fd].ptrfiletable->mode == READ+WRITE))
    {
        if(from==CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) > UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize)
               return -1;

            if(((UFDTArr[fd].ptrfiletable->readoffset) +size) < 0)
               return -1;

           (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset)+size;
        } 

        else if(from == START)
        {
            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))
                return -1;
            if(size < 0 )
                return -1;

            (UFDTArr[fd].ptrfiletable->readoffset) = size;
        }  

        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size > MAXFILESIZE)
                return -1;

            if(((UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size))
               return -1;

            (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize)+size;
        }
    } 
    else if(UFDTArr[fd].ptrfiletable->mode == WRITE)
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->writeoffsite) + size) > MAXFILESIZE)
               return -1;
            
            if(((UFDTArr[fd].ptrfiletable->writeoffsite) + size ) < 0)
               return -1;

            if(((UFDTArr[fd].ptrfiletable->writeoffsite) + size) > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))

            (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) = (UFDTArr[fd].ptrfiletable->writeoffsite) + size;

            (UFDTArr[fd].ptrfiletable->writeoffsite) = (UFDTArr[fd].ptrfiletable->writeoffsite) + size;
        }
        else if(from == START)
        {
            if(size > MAXFILESIZE) 
               return -1;

            if(size < 0)
               return -1;

            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))

            (UFDTArr[fd].ptrfiletable->writeoffsite) = size;
        }
        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size > MAXFILESIZE)
                return -1;

            if(((UFDTArr[fd].ptrfiletable->writeoffsite) + size)<0)
                return -1;

            (UFDTArr[fd].ptrfiletable->writeoffsite) = (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size;

        }
    }
}

void ls_file()
{
    int i =0;
    PINODE temp = head;
    if(SUPERBLOCKobj.freeinode == MAXINODE)
    {
        printf("Error : There are no files \n");
        return;
    }

    printf("\n File Name\tInode number\tFile size\tLink count\n");
    printf("------------------------------------------------------\n");

    while(temp != NULL)
    {
        if (temp->filetype != 0)
        {
            printf("%s\t\t%d\t\t%d\n",temp->filename,temp->inodenumber,temp->filesize,temp->Linkcount);

        }
        temp = temp->next;
        
    }

    printf("--------------------------------------------------------\n");

}  

int fstat_file(int fd)
{
    PINODE temp = head;
    int i= 0;

    if(fd < 0)
       return -1;

    if(UFDTArr[fd].ptrfiletable == NULL)
       return -2;

    temp = UFDTArr[fd].ptrfiletable->ptrinode;

    printf("\n-------Statistical Information about file--------\n");
    printf("File name : %s\n",temp->filename);
    printf("Inode number %d\n",temp->inodenumber);
    printf("File size : %d\n",temp->filesize);
    printf("Actual file size :%d\n",temp->fileactualsize);
    printf("Link Count : %d\n",temp->Linkcount);
    printf("Reference count : %d\n",temp->referencecount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read Only\n");
    }
    else if (temp->permission == 2)
    {
        printf("File Permission : Write\n");
    }
    else if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }
    
    printf("-------------------------------------------------------\n");
    return 0;
    
}

int stat_file(char *name)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
       return -1;

    while(temp!=NULL)
    {
        if(strcmp(name,temp->filename) == 0)
            break;
        temp = temp->next;
    }

    if(temp == NULL)
       return -2;

    printf("\n-------Statistical Information about file--------\n");
    printf("File name : %s\n",temp->filename);
    printf("Inode number %d\n",temp->inodenumber);
    printf("File size : %d\n",temp->filesize);
    printf("Actual file size :%d\n",temp->fileactualsize);
    printf("Link Count : %d\n",temp->Linkcount);
    printf("Reference count : %d\n",temp->referencecount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read Only\n");
    }
    else if (temp->permission == 2)
    {
        printf("File Permission : Write\n");
    }
    else if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }
    
    printf("-------------------------------------------------------\n");
    return 0;


    
}

int truncate_File(char *name)
{
    int fd = GetFDFromName(name);
    if(fd==-1)
       return -1;

       memset(UFDTArr[fd].ptrfiletable->ptrinode->Buffer,0,1024);
       UFDTArr[fd].ptrfiletable->readoffset = 0;
       UFDTArr[fd].ptrfiletable->writeoffsite = 0;
       UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize = 0;
}

int main()
{
    char *ptr = NULL;
    int ret = 0,fd=0,count;
    char command[4][80],str[80],arr[1024];

    InitialiseSuperBlock();
    CreateDILB();

    while(1)
    {
        fflush(stdin);
        strcpy(str,"");

        printf("\n Marvellous VFS : > ");

        fgets(str,80,stdin);// scanf("&[^'\n']s",str);

        count = sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]); // function is return the number of vairiables filled

        if(count == 1)
        {
            if(strcmp(command[0],"ls") == 0)
            {
                ls_file();
            }
            else if(strcmp(command[0],"closeall")==0)
            {
                closeallfile();
                printf("All Files closed succesfully\n");
                continue;
            }
            else if(strcmp(command[0],"clear")== 0)
            {
                system("cls");
                continue;
            }
            else if(strcmp(command[0],"help")==0)
            {
                displayHelp();
                continue;
            }
            else if(strcmp(command[0],"exit") == 0)
            {
                printf("Terminate the Marvellous Virtual File System\n");
                break;
            }
            else
            {
                printf("\n ERROR : Command not found !!!\n");
                continue;
            }
        }

        else if(count == 2)
        {
            if(strcmp(command[0],"stat") == 0)
            {
                ret = stat_file(command[1]);
                if(ret == -1)
                   printf("ERROR : Incorrect parameters\n");
                if(ret == -2)
                   printf("ERROR : There is no such file\n");
                continue;
            }
            else if(strcmp(command[0],"fstat")==0)
            {
                ret = fstat_file(atoi(command[1]));
                if(ret == -1)
                   printf("ERROR : Incorrect parameters\n");
                if(ret == -2)
                   printf("ERROR : There is no such file\n");
                continue;
            }

            else if(strcmp(command[0],"close") == 0)
            {
                ret = closefilebyname(command[1]);
                if(ret ==-1)
                   printf("ERROR : There is no such file\n");
                continue;
            }

            else if(strcmp(command[0],"rm") == 0)
            {
                ret = rm_File(command[1]);
                if(ret == -1)
                   printf("ERROR : There is no such file\n");
                continue;
            }

            else if(strcmp(command[0],"man") == 0)
            {
                man(command[1]);
            }

            else if(strcmp(command[0],"write") == 0)
            {
                fd = GetFDFromName(command[1]);
                if(fd == -1)
                {
                    printf("ERROR : Inocorrect parameter\n");
                    continue;
                }
                printf("Enter the data :\n");
                scanf("%[^\n]",arr);

                ret = strlen(arr);
                if(ret == 0)
                {
                    printf("Error : Incorrect parameter\n");

                    continue;
                }
                ret = WriteFile(fd,arr,ret);
                if(ret == -1)
                  printf("ERROR : Permission denied\n");
                if(ret == -1)
                  printf("ERROR : There is no sufficient memory to write\n");

                if(ret == -3)
                  printf("ERROR : There is not regular file\n");
            }

            else if(strcmp(command[0],"truncate") == 0)
            {
                ret = CreateFile(command[1],atoi(command[2]));
                if(ret >= 0)
                   printf("File is succesfully crated with file descriptor : %d\n",ret);

                if(ret == -1)
                   printf("ERROR : Incorrect parameters\n");

                if(ret == -2)
                   printf("ERROR : There is no inodes\n");

                if(ret == -3)
                   printf("ERROR : File alredy exists\n");

                if(ret == -4)
                   printf("ERROR : Meomory allocation failure\n");

                continue;
            }

            else if(strcmp(command[0],"read") == 0)
            {
                fd = GetFDFromName(command[1]);

                if(fd == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }
                ptr = (char *)malloc(sizeof(atoi(command[2]))+1);

                if(ptr==NULL)
                {
                    printf("ERROR : Memory allocation failure\n");
                    continue;
                }

                ret = ReadFile(fd,ptr,atoi(command[2]));
                if(ret == -1)
                   printf("ERROR : File not existing\n");
                
                if(ret == -2)
                   printf("ERROR : Permission denied\n");

                if(ret == -3)
                  printf("ERROR : Reached at end of file\n");

                if(ret==-4)
                  printf("ERROR : It is not regular file\n");

                if(ret == 0)
                  printf("ERROR : File empty\n"); 

                if(ret > 0)
                {
                    write(2,ptr,ret);
                }
                continue;
            }

            else
            {
                printf("\n ERROR : Incorrect parameters\n");
            }
            ret = LseekFile(fd,atoi(command[2]),atoi(command[3]));

            if(ret == -1)
            {
                printf("ERROR : Unable to perform lseek\n");
            }
        }
        else
        {
            printf("\n ERROR : Command not found !!!\n");
            continue;
        }
    
}
return 0;
}



    