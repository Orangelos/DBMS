#include<stdio.h>
#include<stdlib.h>
struct spisokotchislenia{
    int poradok;
    char nomerstudaka[20];
    char fam[20];
    char ima[20];
    int koldolg;
    char email[20];
    char phone[20];
};
//Прототипы
//------------------------------------------------------------------------------------------------------------------------------------------
void men(struct spisokotchislenia [1000] );
void vivod(struct spisokotchislenia [1000],int);
void stroki(struct spisokotchislenia [1000],int*);
void poisk(struct spisokotchislenia [1000],int*);
void poiskogr(struct spisokotchislenia [1000],int*);
void vivodshapki(void);
void vivodpoiska(struct spisokotchislenia [1000],int);
void vodf(struct spisokotchislenia [1000],int*);
void dobavka(struct spisokotchislenia [1000],int*);
void udal(struct spisokotchislenia [1000],int*,int [1000]);
void vivodf(struct spisokotchislenia [1000],int);
void sort(struct spisokotchislenia [1000],int);
void proverka(struct spisokotchislenia [1000],int*);
//------------------------------------------------------------------------------------------------------------------------------------------










// МАНЭ
//------------------------------------------------------------------------------------------------------------------------------------------
int main(void)
{
    struct spisokotchislenia student[1000]={0};
    system("clear");
    men(student);
}
//------------------------------------------------------------------------------------------------------------------------------------------







// Функция Меню
//------------------------------------------------------------------------------------------------------------------------------------------
void men(struct spisokotchislenia student[1000]){
    int menu=0,kol=0,mas[1000]={0};
    static int strok=0;
    for(int i=0;i<1000;i++)
        mas[i]=-1;
    for(int i=0;i<1000;i++)
        for(int j;j<20;j++)
            
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\033[0;34m \n");
    printf("__________________________________________________________________________________СПИСОК ОТЧИСЛЕНИЯ_________________________________________________________________________________\n");
    printf("\n");
    printf("\n");
    printf("                                                           Выбирите пункты меню:\n");
    printf("\n");
    printf("                                                   1. Показать базу данных\n");
    printf("                                                   2. Ввести количесто студентов и базу данных (возможно только 1 раз)\n");
    printf("                                                   3. Поиск \n");
    printf("                                                   4. Ввод БД с Файла (возможно только 1 раз) \n");
    printf("                                                   5. Добавление строк\n");
    printf("                                                   6. Удаление строк\n");
    printf("                                                   7. Вывод БД в файл\n");
    printf("                                                   8. Cортировка\n");
    printf("                                                   9. Перезапуск БД\n");
    printf("\033[1;34m\n");
    scanf("%d",&menu);
    if (menu==1)
        vivod(student,strok);
    if (menu==2){
        if (strok==0)
            stroki(student,&strok);
        else{
            printf("\033[1;31mВы уже вводили бд\n");
            men(student);
        }
        
    }
    if (menu==3)
        poisk(student,&strok);
    if (menu==4){
        if (strok==0)
            vodf(student,&strok);
        else{
            printf("\033[1;31mВы уже вводили бд\n");
            men(student);
        }
    }
    if(menu==5)
        dobavka(student, &strok);
    if(menu==6){
        
        printf("\033[1;36mВведите строки, которые нужно удалить (до %d) - введите 0 для остановки ввода \n",strok);
        for(int i=0;i<1000;i++){
            scanf("%d",&kol);
          if(kol!=0)
              mas[i]=kol-1;
          else break;
            
        }
        udal(student, &strok,mas);
    }
    if(menu==7)
        vivodf(student, strok);
    if(menu==8)
        sort(student,strok);
    if (menu==9){
        strok=0;
        main();
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------









// Функция вывод
//------------------------------------------------------------------------------------------------------------------------------------------
void vivod( struct spisokotchislenia student[1000],int strok){
    int m=1;
    system("clear");
    printf("\033[1;36m");
    printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
    
    
    printf("\u2503 n/n      \u2503Номер Студенческого \u2503          Фамилия         \u2503                  Имя            \u2503Кол-во долгов  \u2503    Почта           \u2503  Телефон      \u2503\n");
    
    printf("\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B\n");
    for(int i=0;i<strok;i++){
        printf("\u2503 %4d     \u2503 %7s            \u2503 %20s     \u2503 %20s            \u2503   %2d          \u2503%20s\u2503  %11s  \u2503 \n",student[i].poradok,  student[i].nomerstudaka,  student[i].fam, student[i].ima,student[i].koldolg,student[i].email,student[i].phone     );
if (i==strok-1)
{
    printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
    break;
}
        printf("\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B\n");
        }
    
    printf("Если хотите вернутся в меню введите 0\n");
    scanf("%d",&m);
    if (m==0)
        men(student);
}
//------------------------------------------------------------------------------------------------------------------------------------------














//Функция ввод кол-во студентов и бд
//------------------------------------------------------------------------------------------------------------------------------------------
void stroki(struct spisokotchislenia student[1000],int *strok){
    int m=1;
    printf("Введите количество студентво \n");
    scanf("%d",strok);
    for(int i=0;i<=*strok-1;i++){
        student[i].poradok=i+1;
        printf("Номер студенческого студента %d\n", i+1);
        scanf("%s",student[i].nomerstudaka);
        printf("Фамилия студента %d\n",i+1);
        scanf("%s",student[i].fam);
        printf("Имя студента %d\n",i+1);
        scanf("%s",student[i].ima);
        printf("Кол-во задолжностей студента %d\n",i+1);
        scanf("%d",&student[i].koldolg);
        printf("Email студента %d\n",i+1);
        scanf("%s",student[i].email);
        printf("Телефон студента %d\n",i+1);
        scanf("%s",student[i].phone);
        printf("-----------------------------------------------------\n");
    }
    proverka(student,strok);
    vivod(student,*strok);
    
    printf(" \033[1;31m Если хотите ернутся в меню, введите 0\n");
    scanf("%d",&m);
    if (m==0)
        men(student);
}
//------------------------------------------------------------------------------------------------------------------------------------------
















// Функция поиск
//------------------------------------------------------------------------------------------------------------------------------------------
void poisk(struct spisokotchislenia student[1000],int *strok1){
    int strok=*strok1;
    int m=0,chislo=0,sum=0,k=0,k0=0,set=0,st=0,menu=0,mas[1000]={0},p=0,sh=0,ss=0,mass[1000];
    char slovo1[6]={0},slovo2[20]={0},slovo3[11]={0};
    for(int i=0;i<1000;i++)
        mas[i]=-1;
    for(int i=0;i<1000;i++)
        mass[i]=-1;
    printf("");
    printf("");
    printf("");
    printf("");
    printf("  \033[1;36m               Выберите варианты поиска:\n");
    printf("             1. Поиск по столбцу\n");
    printf("             2. Общий поиск\n");
    scanf("%d",&k0);
    if (k0==1){
        printf("                 Выберите тип поиска:\n");
        printf("             1. Полный поиск\n");
        printf("             2. Частичный поиск\n");
        printf("             3. Поиск с ограничениями\n");
        scanf("%d",&k);
        if(k==3)
            poiskogr(student,strok1);
        if (k==1)
        {
            printf("Выберете столбец (1-7)\n");
            scanf("%d",&m);
            
            if (m==1){
                printf("Введите число\n");
                scanf("%d",&chislo);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++)
                        if (chislo==student[i].poradok){
                            vivodpoiska(student,i);
                            mas[ss]=i;
                            ss+=1;
                    }
            }
            if (m==5){
                printf("Введите число\n");
                scanf("%d",&chislo);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++)
                        if (chislo==student[i].koldolg){
                            mas[ss]=i-1;
                            ss+=1;
                            vivodpoiska(student,i);
                    }
            }
            
            if(m==2){
                printf("Введите номер студенческого\n");
                scanf("%s",slovo1);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++){
                    for(int j=0;j<6;j++)
                        if (student[i].nomerstudaka[j]==slovo1[j])
                            sum=sum+1;
                    if (sum==6){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    sum=0;
                        }

                    
            }
            
            if(m==3){
                printf("Bведите фамилию\n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++){
                    for(int j=0;j<20;j++)
                        if (student[i].fam[j]==slovo2[j])
                            sum=sum+1;
                    if (sum==20){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    sum=0;
                        }
            }
            
            
            if(m==4){
                printf("Bведите имя\n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++){
                    for(int j=0;j<20;j++)
                        if (student[i].ima[j]==slovo2[j])
                            sum=sum+1;
                    if (sum==20){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    sum=0;
                        }
            }
            
            if(m==6){
                printf("Bведите емайл\n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<strok;i++){
                    for(int j=0;j<20;j++)
                        if (student[i].email[j]==slovo2[j])
                            sum=sum+1;
                    if (sum==20){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    sum=0;
                        }
            }
            
            if(m==7){
                printf("Bведите телефон\n");
                scanf("%s",slovo3);
                printf("Результаты поиска:\n");
                system("clear");
                vivodshapki();
                for(int i=0;i<strok;i++){
                    for(int j=0;j<11;j++)
                        if (student[i].phone[j]==slovo3[j])
                            sum=sum+1;
                    if (sum==11){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    sum=0;
                        }
            }
            }
        
        
        
        if(k==2){
        voz:
            printf("Выберете столбец \n");
            scanf("%d",&m);
            if((m==1)||(m==5)){
                printf("Частичный поиск не работает с 1 и 5 столбцами\n");
                goto voz;
            }
            if(m==2){
                printf("Введите последовательность цифр (до 6)\n");
                scanf("%s",slovo1);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<6;i++)
                    if (slovo1[i]!='\0')
                        set+=1;
                    else
                        goto m;
                
            m:
                for(int i=0;i<strok;i++){
                    
                    for(int j=0;j<6;j++){
                        if(student[i].nomerstudaka[j]==slovo1[0])
                            for(int k=0;k<set;k++)
                                if(student[i].nomerstudaka[j+k]==slovo1[k])
                                    st=st+1;
                        
                        if(st==set)
                            break;
                        else
                            st=0;
                    }
                    if (st==set){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    st=0;
                }
            }
            if(m==3){
                printf("Введите фамилию или её часть \n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<20;i++)
                    if (slovo2[i]!='\0')
                        set+=1;
                    else
                        goto m1;
            m1:
                for(int i=0;i<strok;i++){
                    
                    for(int j=0;j<20;j++){
                        if(student[i].fam[j]==slovo2[0])
                            for(int k=0;k<set;k++)
                                if(student[i].fam[j+k]==slovo2[k])
                                    st=st+1;
                        
                        if(st==set)
                            break;
                        else
                            st=0;
                    }
                    if (st==set){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    st=0;
                }
            }
            
            if(m==4){
                printf("Введите имя или его часть \n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<20;i++)
                    if (slovo2[i]!='\0')
                        set+=1;
                    else
                        goto m2;
            m2:
                for(int i=0;i<strok;i++){
                    
                    for(int j=0;j<20;j++){
                        if(student[i].ima[j]==slovo2[0])
                            for(int k=0;k<set;k++)
                                if(student[i].ima[j+k]==slovo2[k])
                                    st=st+1;
                        
                        if(st==set)
                            break;
                        else
                            st=0;
                    }
                    if (st==set){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    st=0;
                }
            }
            if(m==6){
                printf("Введите почту или её часть \n");
                scanf("%s",slovo2);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<20;i++)
                    if (slovo2[i]!='\0')
                        set+=1;
                    else
                        goto m3;
            m3:
                for(int i=0;i<strok;i++){
                    
                    for(int j=0;j<20;j++){
                        if(student[i].email[j]==slovo2[0])
                            for(int k=0;k<set;k++)
                                if(student[i].email[j+k]==slovo2[k])
                                    st=st+1;
                        
                        if(st==set)
                            break;
                        else
                            st=0;
                    }
                    if (st==set){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    st=0;
                }
            }
            if(m==7){
                printf("Введите телефон или его часть \n");
                scanf("%s",slovo3);
                system("clear");
                printf("Результаты поиска:\n");
                vivodshapki();
                for(int i=0;i<11;i++)
                    if (slovo3[i]!='\0')
                        set+=1;
                    else
                        goto m4;
            m4:
                for(int i=0;i<strok;i++){
                    
                    for(int j=0;j<11;j++){
                        if(student[i].phone[j]==slovo3[0])
                            for(int k=0;k<set;k++)
                                if(student[i].phone[j+k]==slovo3[k])
                                    st=st+1;
                        
                        if(st==set)
                            break;
                        else
                            st=0;
                    }
                    if (st==set){
                        mas[ss]=i;
                        ss+=1;
                        vivodpoiska(student,i);
                    }
                    st=0;
                }
            }
            
            
            
            
        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Хотите ли вы удалить найденное - введите 1 или 0 если хотите вернутся в меню\n");
        scanf("%d",&menu);
        if(menu==1)
            udal(student,strok1,mas);
        else if(menu==0)
            men(student);
        
            }
    
    if(k0==2){
        printf("  Введите любые символы (до 20)\n");
        
        scanf("%s",slovo2);
        system("clear");
        printf("Результаты поиска:\n");
        vivodshapki();
        
        for(int i=0;i<20;i++)
            if (slovo2[i]!='\0')
                set+=1;
            else
                goto k3;
    k3:
        
        
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<20;j++){
                if(student[i].nomerstudaka[j]==slovo2[0])
                    for(int k=0;k<set;k++)
                        if(student[i].nomerstudaka[j+k]==slovo2[k])
                            st=st+1;
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st==set){
                mass[p]=i;
                sh=+1;
            }
            st=0;
            
            
            
            
            
            for(int j=0;j<20;j++){
                if(student[i].ima[j]==slovo2[0])
                    for(int k=0;k<set;k++)
                        if(student[i].ima[j+k]==slovo2[k])
                            st=st+1;
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st==set){
                mass[p]=i;
                sh=+1;
            }
            st=0;
            
            
            
          
            for(int j=0;j<20;j++){
                if(student[i].fam[j]==slovo2[0])
                    for(int k=0;k<set;k++)
                        if(student[i].fam[j+k]==slovo2[k])
                            st=st+1;
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st==set){
                mass[p]=i;
                sh=+1;
            }
            st=0;
            
            
            
           
            for(int j=0;j<20;j++){
                if(student[i].email[j]==slovo2[0])
                    for(int k=0;k<set;k++)
                        if(student[i].email[j+k]==slovo2[k])
                            st=st+1;
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st==set){
                mass[p]=i;
                sh=+1;
            }
            st=0;
            
            for(int j=0;j<20;j++){
                if(student[i].phone[j]==slovo2[0])
                    for(int k=0;k<set;k++)
                        if(student[i].phone[j+k]==slovo2[k])
                            st=st+1;
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st==set){
                mass[p]=i;
                sh=+1;
            }
            st=0;
            if (sh!=0)
            p=p+1;
            sh=0;
            }
        
        for(int l=0;l<p;l++)
            vivodpoiska(student,mass[l] );
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        
        printf("Хотите ли вы удалить найденное - введите 1 или 0 если хотите вернутся в меню\n");
        scanf("%d",&menu);
        if(menu==1)
            udal(student,strok1,mass);
        else if(menu==0)
            men(student);
        
    }
    
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------























// Вывод шапки
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void vivodshapki(void){
    printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2533\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");


    printf("\u2503 n/n      \u2503Номер Студенческого \u2503          Фамилия         \u2503                  Имя            \u2503Кол-во долгов  \u2503    Почта           \u2503  Телефон      \u2503\n");

    printf("\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B\n");
    
}
//------------------------------------------------------------------------------------------------------------------------------------------
                 

void vivodpoiska(struct spisokotchislenia student[1000],int i){
    
    printf("\u2503 %4d     \u2503 %6s             \u2503 %20s     \u2503 %20s            \u2503   %2d          \u2503%20s\u2503  %11s  \u2503 \n",student[i].poradok,  student[i].nomerstudaka,  student[i].fam, student[i].ima,student[i].koldolg,student[i].email,student[i].phone     );
    printf("\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B\n");
}






//Ввод БД с файла
//------------------------------------------------------------------------------------------------------------------------------------------
                 
void vodf(struct spisokotchislenia student[1000],int *strok){
    char filename[]="/Users/orangelos/Desktop/Proverkax.txt";
    system("clear");
      FILE *fa=fopen(filename,"r");
    char str,bd[10000];
    int i=0,kol=0,m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,q=0;
      if (fa==NULL)
          printf("\033[1;31m !!!!");
    
    while((str=fgetc(fa))!=EOF){
        if (str=='\n')
            *strok+=1;
        bd[i]=str;
        i=i+1;
    }
    *strok+=1;
    
    for (int i=0;i<*strok;i++){
        student[i].poradok=i+1;
        
        
        
        for(int j=0;j<100;j++)
            if (bd[j+m2]!='\n')
                m1=m1+1;
            else
                break;
        
        for(int j=0;j<m1;j++){
            if(bd[j+m2]==' ')
                kol=kol+1;
            
            if ((kol==1)&&(m3==0))
                for(int k=0;k<6;k++){
                    student[i].nomerstudaka[k]=bd[j+k+1+m2];
                    m3=1;
                }
            
            if ((kol==2)&&(m4==0))
                for(int k=0;k<20;k++){
                    if(bd[j+k+1+m2]!=' '){
                        student[i].ima[k]=bd[j+k+1+m2];
                        m4=1;
                    }
                    else goto k1;
                }
        k1:
            if ((kol==3)&&(m5==0))
                for(int k=0;k<20;k++){
                    if(bd[j+k+1+m2]!=' '){
                        student[i].fam[k]=bd[j+k+1+m2];
                        m5=1;
                    }
                    else goto k2;
                }
        k2:
            if ((kol==4)&&(m6==0)){
                student[i].koldolg=bd[j+1+m2]-48;
                m6=1;
            }
                
            
            
            if ((kol==5)&&(m7==0))
                for(int k=0;k<20;k++){
                    if(bd[j+k+1+m2]!=' '){
                        student[i].email[k]=bd[j+k+1+m2];
                        m7=1;
                    }
                    else goto k3;
                }
        k3:
             
            if ((kol==6)&&(m8==0))
                for(int k=0;k<11;k++){
                    if(bd[j+k+1+m2]!=' '){
                        student[i].phone[k]=bd[j+k+1+m2];
                        m8=1;
                    }
                }
            
        }
        m3=0;
        m4=0;
        m5=0;
        m6=0;
        m7=0;
        m8=0;
        
        kol=0;
        m2=m2+m1+1;
        m1=0;
    }
      fclose(fa);
    proverka(student,strok);
    printf("\033[1;32m БД записана - Вернутся в меню - введите 0 \n");
    scanf("%d",&q);
    if(q==0)
        men(student);
    }
//------------------------------------------------------------------------------------------------------------------------------------------
                 






// Поиск с ограничениями
//------------------------------------------------------------------------------------------------------------------------------------------
void poiskogr(struct spisokotchislenia student[1000],int *strok1){
    int k=0,set=0,st=0,strok=*strok1,mas[1000]={0},ss=0,menu=0;
    char slovo[20];
    for(int i=0;i<1000;i++)
        mas[i]=-1;
voz:
    printf("Выберите столбец\n ");
    scanf("%d",&k);
    if((k==1)||(k==5)){
        printf("\033[1;31m ограниченный поиск не работает с 1 и 5 столбцами\n");
        goto voz;
    }
    printf("Введите символ,цифры или словосочетание, которое должно отсутсвовать\n");
    scanf("%s",slovo);
    for(int i=0;i<20;i++)
        if (slovo[i]!='\0')
            set+=1;
        else
            goto k3;
k3:
    vivodshapki();
    if(k==2){
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<6;j++){
                if(student[i].nomerstudaka[j]==slovo[0])
                    for(int k=0;k<set;k++)
                        if(student[i].nomerstudaka[j+k]==slovo[k])
                            st=st+1;
                
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st!=set){
                mas[ss]=i;
                ss+=1;
                vivodpoiska(student,i);
            }
            st=0;
        }
    }
    if(k==3){
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<20;j++){
                if(student[i].fam[j]==slovo[0])
                    for(int k=0;k<set;k++)
                        if(student[i].fam[j+k]==slovo[k])
                            st=st+1;
                
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st!=set){
                mas[ss]=i;
                ss+=1;
                vivodpoiska(student,i);
            }
            st=0;
        }
    }
    
    
    if(k==4){
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<20;j++){
                if(student[i].ima[j]==slovo[0])
                    for(int k=0;k<set;k++)
                        if(student[i].ima[j+k]==slovo[k])
                            st=st+1;
                
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st!=set){
                mas[ss]=i;
                ss+=1;
                vivodpoiska(student,i);
            }
            st=0;
        }
    }
    if(k==6){
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<20;j++){
                if(student[i].email[j]==slovo[0])
                    for(int k=0;k<set;k++)
                        if(student[i].email[j+k]==slovo[k])
                            st=st+1;
                
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st!=set){
                mas[ss]=i;
                ss+=1;
                vivodpoiska(student,i);
            }
            st=0;
        }
    }
    
    
    if(k==7){
        for(int i=0;i<strok;i++){
            
            for(int j=0;j<20;j++){
                if(student[i].phone[j]==slovo[0])
                    for(int k=0;k<set;k++)
                        if(student[i].phone[j+k]==slovo[k])
                            st=st+1;
                
                if(st==set)
                    break;
                else
                    st=0;
            }
            if (st!=set){
                mas[ss]=i;
                ss+=1;
                vivodpoiska(student,i);
            }
            st=0;
        }
    }
    printf("Хотите ли вы удалить найденное - введите 1 или 0 если хотите вернутся в меню\n");
    scanf("%d",&menu);
    if(menu==1)
        udal(student,strok1,mas);
    else if(menu==0)
        men(student);
}
//------------------------------------------------------------------------------------------------------------------------------------------



















//Добавление строки
//------------------------------------------------------------------------------------------------------------------------------------------
void dobavka(struct spisokotchislenia student[1000],int *strok){
    int nomer=0,kol=0,ch=0;
    printf("\033[1;36mВведите номер строки, после которой хотите добавить строки\n");
    scanf("%d",&nomer);
    printf("Введите количество строк добавления\n");
    scanf("%d",&kol);
    *strok+=kol;
    for(int i=0;i<kol;i++)
        for(int j=*strok;j>nomer+i;j--){
            
            student[j].koldolg=student[j-1].koldolg;
            
            for(int k=0;k<6;k++)
            student[j].nomerstudaka[k]=student[j-1].nomerstudaka[k];
            
            for(int k=0;k<20;k++)
            student[j].fam[k]=student[j-1].fam[k];
            
            for(int k=0;k<20;k++)
            student[j].ima[k]=student[j-1].ima[k];
            
            for(int k=0;k<20;k++)
            student[j].email[k]=student[j-1].email[k];
            
            for(int k=0;k<11;k++)
            student[j].phone[k]=student[j-1].phone[k];
        }
    for(int i=0;i<*strok;i++)
        student[i].poradok=i+1;

    for(int i = nomer;i<nomer+kol;i++)
    {
            printf("Номер студенческого студента %d\n", i+1);
            scanf("%s",student[i].nomerstudaka);
            printf("Фамилия студента %d\n",i+1);
            scanf("%s",student[i].fam);
            printf("Имя студента %d\n",i+1);
            scanf("%s",student[i].ima);
            printf("Кол-во задолжностей студента %d\n",i+1);
            scanf("%d",&student[i].koldolg);
            printf("Email студента %d\n",i+1);
            scanf("%s",student[i].email);
            printf("Телефон студента %d\n",i+1);
            scanf("%s",student[i].phone);
            printf("-----------------------------------------------------\n");
        }
        
        
        
    
    
    
    
    printf("Если хотите вернутся в меню введите 0\n");
    scanf("%d",&ch);
    if(ch==0)
        men(student);
}
//------------------------------------------------------------------------------------------------------------------------------------------























// Удаление строк
//------------------------------------------------------------------------------------------------------------------------------------------
void udal(struct spisokotchislenia student[1000],int *strok,int mas[1000]){
    int kol=0,ch=0;
    for (int i=0;i<1000;i++)
        if(mas[i]!=-1)
            kol+=1;
    else
        break;
    for(int i=0;i<kol;i++)
    printf("\033[1;32m %d  ",mas[i]);
    
    for (int i=0;i<kol;i++){
        for(int j=mas[i];j<*strok;j++){
            
            student[j].koldolg=student[j+1].koldolg;
            
            for(int k=0;k<6;k++)
                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
            
            for(int k=0;k<20;k++)
                student[j].fam[k]=student[j+1].fam[k];
            
            for(int k=0;k<20;k++)
                student[j].ima[k]=student[j+1].ima[k];
            
            for(int k=0;k<20;k++)
                student[j].email[k]=student[j+1].email[k];
            
            for(int k=0;k<11;k++)
                student[j].phone[k]=student[j+1].phone[k];
        }
        for (int p=0;p<kol;p++)
            mas[p]-=1;
    }
    *strok-=kol;
    
    for(int i=0;i<*strok-kol;i++)
        student[i].poradok=i+1;
    
    
    
    printf(" - Cтрок удалены\n");
    printf("Если хотите вернутся в меню введите 0\n");
    scanf("%d",&ch);
    if(ch==0)
        men(student);
    
    
}
//-----------------------------------------------------------------------------------------------------------------------------------















// Вывод в файл
//-----------------------------------------------------------------------------------------------------------------------------------
void vivodf( struct spisokotchislenia student[1000],int strok){
    FILE *fp;
    int ch=0;
    fp=fopen("/Users/orangelos/Desktop/vivod.txt","w");
    if(fp==NULL)
        printf("!!!!!");
    
    
    for(int i=0;i<strok;i++)
        fprintf(fp,"%d %s %s %s %d %s %s\n",student[i].poradok,student[i].nomerstudaka,student[i].fam,student[i].ima,student[i].koldolg,student[i].email,student[i].phone);
    
    fclose(fp);
    printf(" БД записана в файл \n");
    printf("Если хотите вернутся в меню введите 0\n");
    scanf("%d",&ch);
    if(ch==0)
        men(student);
}
//-----------------------------------------------------------------------------------------------------------------------------------











//Cортировка
//-----------------------------------------------------------------------------------------------------------------------------------
void sort(struct spisokotchislenia student[1000],int strok){
    int n=0,k=0,por=0,ch=0;
    char chare;
    printf("Введите столбец\n");
    scanf("%d",&n);
    if(n==1){
        printf("Выберите тип сортровка:\n");
        printf("1.По возростанию\n");
        printf("2. По убыванию\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                if(student[j].poradok<student[j+1].poradok)
                {
                    por=student[j].poradok;
                    student[j].poradok=student[j+1].poradok;
                    student[j+1].poradok=por;
                    
                    por=student[j].koldolg;
                    student[j].koldolg=student[j+1].koldolg;
                    student[j+1].koldolg=por;
                    
                    for(int k=0;k<6;k++){
                        chare=student[j].nomerstudaka[k];
                        student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                        student[j+1].nomerstudaka[k]=chare;
                    }
                    for(int k=0;k<20;k++){
                        chare=student[j].fam[k];
                        student[j].fam[k]=student[j+1].fam[k];
                        student[j+1].fam[k]=chare;
                    }
                    for(int k=0;k<20;k++){
                        chare=student[j].ima[k];
                        student[j].ima[k]=student[j+1].ima[k];
                        student[j+1].ima[k]=chare;
                    }
                    for(int k=0;k<20;k++){
                        chare=student[j].email[k];
                        student[j].email[k]=student[j+1].email[k];
                        student[j+1].email[k]=chare;
                    }
                    for(int k=0;k<11;k++){
                        chare=student[j].phone[k];
                        student[j].phone[k]=student[j+1].phone[k];
                        student[j+1].phone[k]=chare;
                    }
                }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                    if(student[j].poradok>student[j+1].poradok)
                    {
                        por=student[j].poradok;
                        student[j].poradok=student[j+1].poradok;
                        student[j+1].poradok=por;
                        
                        por=student[j].koldolg;
                        student[j].koldolg=student[j+1].koldolg;
                        student[j+1].koldolg=por;
                        
                        for(int k=0;k<6;k++){
                            chare=student[j].nomerstudaka[k];
                            student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                            student[j+1].nomerstudaka[k]=chare;
                        }
                        for(int k=0;k<20;k++){
                            chare=student[j].fam[k];
                            student[j].fam[k]=student[j+1].fam[k];
                            student[j+1].fam[k]=chare;
                        }
                        for(int k=0;k<20;k++){
                            chare=student[j].ima[k];
                            student[j].ima[k]=student[j+1].ima[k];
                            student[j+1].ima[k]=chare;
                        }
                        for(int k=0;k<20;k++){
                            chare=student[j].email[k];
                            student[j].email[k]=student[j+1].email[k];
                            student[j+1].email[k]=chare;
                        }
                        for(int k=0;k<11;k++){
                            chare=student[j].phone[k];
                            student[j].phone[k]=student[j+1].phone[k];
                            student[j+1].phone[k]=chare;
                        }
                    }
            }
        }
    
    if(n==5){
        printf("Выберите тип сортровка:\n");
        printf("1.По возростанию\n");
        printf("2. По убыванию\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].koldolg<student[j+1].koldolg)
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].koldolg>student[j+1].koldolg)
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        }
        
    }
        
        
        
        
        
    if(n==2){
        printf("Выберите тип сортровка:\n");
        printf("1.По возростанию\n");
        printf("2. По убыванию\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].nomerstudaka[0]<student[j+1].nomerstudaka[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].nomerstudaka[0]>student[j+1].nomerstudaka[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        }
    }
            
    if(n==3){
        printf("Выберите тип сортровка:\n");
        printf("1.По алфавиту\n");
        printf("2. Обратно алфавиту\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].fam[0]<student[j+1].fam[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].fam[0]>student[j+1].fam[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        }
        
    }
    if(n==4){
        printf("Выберите тип сортровка:\n");
        printf("1.По алфавиту\n");
        printf("2. Обратно алфавиту\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].ima[0]<student[j+1].ima[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].ima[0]>student[j+1].ima[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        }
        
    }
    if(n==6){
        printf("Выберите тип сортровка:\n");
        printf("1.По алфавиту\n");
        printf("2. Обратно алфавиту\n");
        scanf("%d",&k);
        if(k==2)
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].fam[0]<student[j+1].fam[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        if(k==1){
            for(int i=0;i<strok-1;i++)
                for(int j=0;j<strok-1;j++)
                    if((student[j+1].poradok!=0)&&(student[j].poradok!=0))
                        if(student[j].fam[0]>student[j+1].fam[0])
                        {
                            por=student[j].poradok;
                            student[j].poradok=student[j+1].poradok;
                            student[j+1].poradok=por;
                            
                            por=student[j].koldolg;
                            student[j].koldolg=student[j+1].koldolg;
                            student[j+1].koldolg=por;
                            
                            for(int k=0;k<6;k++){
                                chare=student[j].nomerstudaka[k];
                                student[j].nomerstudaka[k]=student[j+1].nomerstudaka[k];
                                student[j+1].nomerstudaka[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].fam[k];
                                student[j].fam[k]=student[j+1].fam[k];
                                student[j+1].fam[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].ima[k];
                                student[j].ima[k]=student[j+1].ima[k];
                                student[j+1].ima[k]=chare;
                            }
                            for(int k=0;k<20;k++){
                                chare=student[j].email[k];
                                student[j].email[k]=student[j+1].email[k];
                                student[j+1].email[k]=chare;
                            }
                            for(int k=0;k<11;k++){
                                chare=student[j].phone[k];
                                student[j].phone[k]=student[j+1].phone[k];
                                student[j+1].phone[k]=chare;
                            }
                        }
        }
    }
            if(n==7){
                printf("Для 7 столбца сортировка не имеет смысла, повтор - \n");
                sort(student,strok);
            }
    
    
    
    printf(" Cортировка завершина \n");
    printf("Если хотите вернутся в меню введите 0\n");
    scanf("%d",&ch);
    if(ch==0)
        men(student);
}
//-----------------------------------------------------------------------------------------------------------------------------------




//Проверка
//-----------------------------------------------------------------------------------------------------------------------------------
void proverka(struct spisokotchislenia student[1000],int *strok){
    for (int i=0;i<*strok;i++){
        int st=0,st1=0,st2=0,len1=0,len2=0,st6=0,st7=0;
        
        
        
        for(int k=0;k<6;k++)
            if(student[i].nomerstudaka[k]!=EOF)
                st=st+1;
        if(st!=6)
        {   printf("\033[1;31m \n");
            printf("Вы ввели некоректные данные во 2 столбце, порядковый номер - %d\n",student[i].poradok+1);
            printf("Повторите ввод\n");
            *strok=0;
            men(student);
        }
        
    
        
        for(int k=0;k<20;k++)
            if( student[i].email[k]=='@')
                st1=1;
        if (st1<1){
            printf("\033[1;31m \n");
            printf("Вы ввели некоректные данные в 6 столбце, порядковый номер - %d\n",student[i].poradok+1);
            printf("Повторите ввод");
            *strok=0;
             men(student);
        }
       
           if( student[i].phone[0]=='8')
               st2+=1;
        if (st2!=1){
            printf("\033[1;31m \n");
            printf("Вы ввели некоректные данные в 7 столбце, порядковый номер - %d\n",student[i].poradok+1);
            printf("Повторите ввод");
            *strok=0;
            men(student);
        }
        
        
//        for(int j=0;j<20;j++){
//            if(student[i].fam[j]!=0)
//                len1+=1;
//            if(student[i].ima[j]!=0)
//                len2+=1;
//        }
//
//        for(int j=0;j<20;j++)
//            if ((student[i].fam[j]!='0')&&(student[i].fam[j]!='1')&&(student[i].fam[j]!='2')&&(student[i].fam[j]!='3')&&(student[i].fam[j]!='4')&&(student[i].fam[j]!='5')&&(student[i].fam[j]!='6')&&(student[i].fam[j]!='7')&&(student[i].fam[j]!='8')&&(student[i].fam[j]!='9'))
//                st6+=1;
//        if(st6!=len1){
//            printf("Вы ввели некоректные данные в 3 столбце, порядковый номер - %d\n",student[i].poradok);
//            printf("Повторите ввод");
//            *strok=0;
//            men(student);
//
//        }
//
//        for(int j=0;j<20;j++)
//            if ((student[i].ima[j]!='0')&&(student[i].ima[j]!='1')&&(student[i].ima[j]!='2')&&(student[i].ima[j]!='3')&&(student[i].ima[j]!='4')&&(student[i].ima[j]!='5')&&(student[i].ima[j]!='6')&&(student[i].ima[j]!='7')&&(student[i].ima[j]!='8')&&(student[i].ima[j]!='9'))
//                st7+=1;
//        if(st6!=len2){
//            printf("Вы ввели некоректные данные в 3 столбце, порядковый номер - %d\n",student[i].poradok);
//            printf("Повторите ввод");
//            *strok=0;
//            men(student);
            
        }
        
    }

//-----------------------------------------------------------------------------------------------------------------------------------
