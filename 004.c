#include <stdio.h>
#include <stdlib.h>
struct employee{
    int id;
    char name;
    int age ;
 
};
int main(){
    void *ptr = malloc(sizeof(struct employee));
    struct employee *sptr = (struct employee*)ptr;
    sptr->id = 0x44eeff11;
    sptr->name ='S';
    sptr->age = 0x663388dd;
    FILE *fh = fopen ("employee.emp","wb");
    if (fh != NULL){
        fwrite(ptr,sizeof(struct employee), 1,fh);
        fclose(fh);
        printf("----------------------\n");
    }

    fh = fopen ("employee.emp","rb");
     if (fh != NULL){
        fread(ptr,sizeof(struct employee), 1,fh);
        fclose(fh);
        printf("id: %x\n", sptr->id);
        printf("char: %c\n", sptr->name);
        printf("id: %x\n", sptr->age);
     }
    
    free(sptr);
    return 0;

}
