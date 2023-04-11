#include <stdio.h>

void room_print(int sala[20][40]) {
    int f, c;
    printf("Seats: [0=free/1=booked]\n   ");
    for(c=0;c<40;c++){
        printf("%4i", c);
    }
    for(f=0;f<20;f++){
        if(f<10)
            printf("\n0%i - ", f);
        if(f>=10)
            printf("\n%i - ", f);
        for(c=0;c<40;c++){
            printf("[%i] ", sala[f][c]);
        }
    }
}

void clear_init(int sala[20][40]){
    int f, c;
    for(f=0;f<20;f++){
        for(c=0;c<40;c++){
            sala[f][c]=0;
        }
    }
}
void clear(int sala[20][40]){
    int f, c;
    for(f=0;f<20;f++){
        for(c=0;c<40;c++){
            sala[f][c]=0;
        }
    }
    room_print(sala);
    printf("\nReset complete!\n");
    fflush(stdin);
    getchar();
}

int main() {
    int sala[20][40];
    int f, c, l, r;
    char ans;
    clear_init(sala);
    do{
        start:
        system("cls");
        printf("Welcome to Cinema X, please make your selection: \n1. Zero out the room\n2. Book seats\n3. Book a whole row\n4. Check for empty seats\n5. Print room map\n6. Exit\nSelection: ");
        fflush(stdin);
        scanf("%c", &ans);
    }while(ans<'1'||ans>'6');

    switch (ans) {
        case '1':
            clear(sala);
            goto start;
        case '2':
            room_print(sala);
        reset2:
            printf("\nPlease select a seat (F C): ");
            fflush(stdin);
            scanf("%i %i", &f, &c);
            if(sala[f][c]==1){
                printf("Asiento ya reservado, escoja otro.");
                goto reset2;
            }
            sala[f][c]=1;
            printf("Seat in Fila: %i, Asiento: %i has been reserved", f, c);
            fflush(stdin);
            getchar();
            goto start;
        case '3':
            room_print(sala);
        reset3:
            do {
                printf("\nPlease select a row: ");
                fflush(stdin);
                scanf("%i", &f);
            } while (f<0||f>20);
            for(c=0;c<40;c++) {
                if (sala[f][c]==1) {
                    printf("La fila %i no esta completamente libre, seleccione otra\n", f);
                    goto reset3;
                }
            }
            for(c=0;c<40;c++) {
                sala[f][c]=1;
            }
            printf("Fila %i ha sido reservada", f);
            fflush(stdin);
            getchar();
            goto start;
        case '4':
            room_print(sala);
            for(f=0, l=0, r=0;f<20;f++){
                for(c=0;c<40;c++){
                    if(sala[f][c]==0){
                        l+=1;
                    }
                    else
                        r+=1;
                }
            }
            printf("\nHay %i asientos libres y %i asientos reservados", l, r);
            fflush(stdin);
            getchar();
            goto start;
        case '5':
            room_print(sala);
            fflush(stdin);
            getchar();
            goto start;
        case '6':
            break;
    }
}
