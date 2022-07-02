#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#include<conio.h>
#define y 121
#define ENTER 13
#define TAB 9
#define BKSP 8
int num;
int opt,price,from,route,distance,classofbus;
int choosenclass,randloop,i,buschoosen;
void payment(int price);
void form(int price);
void OTP();
void bus();
int seat;
char z12[15][20];
int ij,ji;
//defining the variables using structure
struct user
{
    char username[50];
    char password[50];
    char email[50];
    char name[50];
    char phone[12];
    char password2[50];
};
//defining a function for generating the user name
char generateusername(char email[50],char username[50])
{
    int i=0;
    while(i<strlen(email))

    {
        if(email[i]=='@')
            break;
        else
            username[i]=email[i];
        i++;
    }
    username[i]='\0';//adding the null character at the end of the string
}

//checking whether the reading input for name is full of letter or not
int checkString(char str1[])
{
    int i,x=0,p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' '))
        {
            continue;
        }
        else{ return 0; }
    }
    return 1;
}
void business_class(char from[50],char to[50])//function to book business class ticket
{
    system("cls");
    int op2,sum=0;
    char pwdd[10],c,ins;
    char userid[50],userpwd[50],bank[50];
    printf("\n\n\t\t\t\t\t\t your departure region is %s",from);
    printf("\n\n\t\t\t\t\t\t your arrival region is %s",to);
    printf("\n\n\t\t\t\t\t\t do you want to avail flight insurance(y/n)=>");//getting extra benefits from user and calculating the bill
    scanf("%c",&ins);
    scanf("%*c");
    if(ins=='y')
    {
        sum+=200;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you carry extra luggage(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=400;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail airport lounges(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=2500;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail priority boarding(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=3000;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t YOUR TOTAL TICKET COST +TAXES IS ...$%d",(sum+2500));//getting the mode of payment
    printf("\n\n\t\t\t\t\t\t enter the mode of payment");
    printf("\n\n\t\t\t\t\t\t 1.G pay\n\n\t\t\t\t\t\t 2.Paytm\n\n\t\t\t\t\t\t 3.net banking\n");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR OPTION=>");
    scanf("%d",&op2);
    if(op2==1||op2==2)
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR 4-DIGIT UPI ID==>");

        int k=0;
        while(1)
        {
            c= getch();
            if(c==ENTER||c==TAB){
            pwdd[k]='\0';
            break;}
            else if(c==BKSP){
                if(k>0){
                    k--;
                    printf("\b \b");
                }
            }

            else{
                pwdd[k++]=c;
                printf("* \b");}


        }
        sleep(3);

    printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");
    printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
    sleep(2);
    }

    else if(op2==3)
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR BANK NAME=>");//format for net banking
        scanf("%*c");
        scanf("%[^\n]s",bank);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR USED ID FOR NET BANKING=>");
        scanf("%*c");
        scanf("%[^\n]s",userid);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD FOR NET BANKING=>");
        scanf("%*c");
        scanf("%s",userpwd);
        sleep(3);
        printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");
        printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
        sleep(2);
    }

}
void economy_class(char from[50],char to[50])//function for booking economy class
{
    system("cls");
    int op2,sum=0;
    char pwdd[10],c,ins;
    char userid[50],userpwd[50],bank[50];
    printf("\n\n\t\t\t\t\t\t your departure region is %s",from);
    printf("\n\n\t\t\t\t\t\t your arrival region is %s",to);
    printf("\n\n\t\t\t\t\t\t do you want to avail flight insurance(y/n)=>");
    scanf("%c",&ins);
    scanf("%*c");
    if(ins=='y')
    {
        sum+=20;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you carry extra luggage(y/n)=>;");//adding extra benefits
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=40;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail airport lounges(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=250;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail priority boarding(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=300;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t YOUR TOTAL TICKET COST +TAXES IS ...$%d=>",(sum+2500));//generating the total
    printf("\n\n\t\t\t\t\t\t enter the mode of payment");
    printf("\n\n\t\t\t\t\t\t 1.Gpay\n\n\t\t\t\t\t\t 2.Paytm\n\n\t\t\t\t\t\t 3.net banking");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR OPTION=>");
    scanf("%d",&op2);
    if(op2==1||op2==2)
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR 4-DIGIT UPI ID==>");//getting the UPI id
        int k=0;
        while(1)
        {
            c= getch();
            if(c==ENTER||c==TAB){
            pwdd[k]='\0';
            break;}
            else if(c==BKSP){
                if(k>0){
                    k--;
                    printf("\b \b");
                }
            }

            else{
                pwdd[k++]=c;
                printf("* \b");}


        }
        sleep(2);

    printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");//giving success message
    printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
    sleep(2);
    }
    else if(op2==3)
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR BANK NAME=>");
        scanf("%*c");
        scanf("%[^\n]s",bank);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR USED ID FOR NET BANKING=>");
        scanf("%*c");
        scanf("%s",userid);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD FOR NET BANKING=>");
        scanf("%*c");
        scanf("%s",userpwd);
        sleep(3);
        printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");
        printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
        sleep(2);
    }

}
void first_class(char from[50],char to[50])//getting the details for first class
{
    system("cls");
    int op2,sum=0;
    char pwdd[10],c,ins;
    char userid[50],userpwd[50],bank[50];
    printf("\n\n\t\t\t\t\t\t your departure region is %s",from);
    printf("\n\n\t\t\t\t\t\t your arrival region is %s",to);
    printf("\n\n\t\t\t\t\t\t do you want to avail flight insurance(y/n)");
    scanf("%c",&ins);
    scanf("%*c");
    if(ins=='y')
    {
        sum+=250;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you carry extra luggage(y/n)=>");//adding extra benefits
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=42;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail airport lounges(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=222;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t do you want to avail priority boarding(y/n)=>");
    scanf("%*c");
    scanf("%c",&ins);
    if(ins=='y')
    {
        sum+=3000;
    }
    else
    {
        sum+=0;
    }
    printf("\n\n\t\t\t\t\t\t YOUR TOTAL TICKET COST +TAXES IS ...$%d",(sum+2500));
    printf("\n\n\t\t\t\t\t\t enter the mode of payment");
    printf("\n\n\t\t\t\t\t\t 1.G pay\n\n\t\t\t\t\t\t 2.Paytm\n\n\t\t\t\t\t\t 3.net banking");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR OPTION=>");
    scanf("%d",&op2);
    if(op2==1||op2==2)
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR 4-DIGIT UPI ID==>");
        int k=0;
        while(k<10)
        {
            c= getch();
            pwdd[k]=c;

            if(c==13)
                break;

            else
                printf("*");

                k++;
        }
        pwdd[k]='\0';
        sleep(2);

    printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");
    printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
    sleep(2);
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t ENTER YOUR BANK NAME=>");
        scanf("%*c");
        scanf("%[^\n]s",bank);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR USED ID FOR NET BANKING=>");
        scanf("%*c");
        scanf("%s",userid);
        printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD FOR NET BANKING=>");
        scanf("%*c");
        scanf("%s",userpwd);
        sleep(2);
        printf("\n\n\t\t\t\t\t\t YOUR TRANSACTION IS SUCCESSFULL ");
        printf("\n\n\t\t\t\t\t\t YOU WILL SHORTLY RECIEVE A MAIL");
        sleep(2);
    }

}


//main function
int main()
{
    FILE *pp1;
    pp1=fopen("username.txt","a");
    if(pp1==NULL){
        printf("error opening the file");
        exit(0);}
    char ch;
    int c=0;
    char uu[50];
    char pp[50];
    FILE *fp,*ptr;//defining files
    fp=fopen("UserDetails.dat","a");//opening the file for writing
    if(fp==NULL){
        printf("error opening the file");
        Sleep(2);
        exit(0);}
    struct user user;
    int option,i,j;
    int dd,mm,yy;
    int usrfound=1;
    char arr[30][15]={"LOS ANGELES","BERLIN","NEW YORK","WASHINGTON","MONTREAL","LONDON","VILNIUS","CAPE TOWN","GENEVA"
    ,"MITCHIGAN","VILNIUS","BERN","TALLIN","STOCKHOLM","PARIS","PRAGUE","BRUSSELS","SEOUL","DELHI","HELSINKI","ATHENS","WARSAW",
    "TEL AVIR","LISBON","OTTAWA","RIGA","OSLO"};//array to store the city names
    int choice,count6=0;
    int arr3[5]={'2','23','30','17','14'};
    char name[100],perAdd[100],currAdd[100],from[50],to[50];
    int passID,pn,flightNum,date,day,mon,year,op,c1=0,class_opt;
    int arr4[30]={'123','675','453','984','324','096','128','564','300','129','834','091','234','732','123','434','066'};//array to store flight number
    l1:printf("\n\n\t\t\t\t\t\t....................WELCOME TO MAKE MY TRIP......................");//choice page

    printf("\n\n\t\t\t\t\t\t\t\t!! YOU WILL LOVE THE WAY WE FLY !!");
    printf("\n\n\t\t\t\t\t\t\t WARNING: NEW USERS PLEASE REGISTER AND LOGIN");

    printf("\n\n\t\t\t\t\t\t......................ENTER YOUR CHOICES.........................");

    printf("\n\n\t\t\t\t\t\t 1.REGISTER\n");
    printf("\n\n\t\t\t\t\t\t 2.LOGIN\n");
    printf("\n\n\t\t\t\t\t\t 3.EXIT\n");
    printf("\n\n\t\t\t\t\t\t ALREADY A USER?PRESS 4\n");
    printf("\n\n\t\t\t\t\t\t ENTER YOUR OPTION=>");
    scanf("%d",&option);

    if(option>4||option<1)//statements for using invalid choice
    {
        printf("\a");//creates a beep sound
        printf("\n\n\t\t\t\t\t\t ENTER THE VALID OPTION!! ");
        printf("\n\n\t\t\t\t\t\t LOADING.......");
        sleep(3);
        system("cls");
        goto l1;
    }

    system("cls");
    switch(option)
    {
        case 1://for registration
        {
            int flag=0,opt;
            int i,j,k,n,z,count=0;;
            printf("\n\n\t\t\t\t\t\t......................WELCOME TO REGISTRATION PAGE.....................\n\n\n");//welcome to registration pasge
            printf("\n\n\t\t\t\t\t\t ENTER YOUR NAME:\t");//getting the details
            scanf("%s",&user.name);
            printf("\n\n\t\t\t\t\t\t ENTER YOUR EMAIL:\t");
            scanf("%s",&user.email);
            printf("\n\n\t\t\t\t\t\t ENTER YOUR NUMBER:\t");
            scanf("%s",&user.phone);
            printf("\n\n\t\t\t\t\t\t ENTER YOUR PASSWORD:\t");
            printf("\n\n\t\t\t\t\t\t WARNING :YOUR PASSWORD SHOULD CONTAIN ONE UPPERCASE ,ONE LOWERCASE,ONE SPECIAL CHARACTER\t");

            scanf("%s",&user.password);
            printf("\n\n\t\t\t\t\t\t CONFIRM YOUR PASSWORD:\t");
            scanf("%s",&user.password2);
            system("cls");
            printf("\t\t\t\t\t\t\t..........MATCHING REQUIREMENTS..............\n\n");
            printf("\t\t\t\t\t\t\t..............PLEASE WAIT....................\n\n");
            sleep(3);
            for(i=0;i<1;i++)//checking one time whether the given input are correct for registration
            {
                if(checkString(user.name)==1)//checking the name string
                {
                    printf("\t\t\t\t\t\t your name is valid\n\n");
                    sleep(1);
                }
                else
                {
                    printf("\a");
                    printf("\t\t\t\t\t\t your name is invalid\n\n");
                    flag=1;
                    sleep(1);
                }
                if(strlen(user.phone)==10)//checking the phone number
                {

                    printf("\t\t\t\t\t\t valid number\n\n");
                    sleep(1);
                }
                else
                {
                    printf("\a");
                    printf("\t\t\t\t\t\t Invalid number\n\n");
                    flag=1;
                    sleep(1);

                }

                for(j=0;j<strlen(user.email);j++)//checking the email
                {
                    if(isalpha(user.email[0])>0)
                    {
                        if(user.email[j]!='@')
                        {
                            c=1;
                        }
                        else if(user.email[j]=='@')
                        {
                            c=0;
                            break;
                        }
                    }
                    else
                    {
                        c=1;
                    }

                }
                if(c==1)
                {
                    printf("\a");
                    printf("\t\t\t\t\t\t  Invalid mail ID\n\n");//checking the correct mail
                    sleep(1);
                    flag=1;
                }
                if(c==0)
                {
                    printf("\t\t\t\t\t\t valid mail ID....\n\n");
                    sleep(1);
                }
                if(strlen(user.password)<8)//checking the length of password
                {
                    printf("\t\t\t\t\t\t Your password should contain at least 8 characters\n\n");
                    flag=1;
                    sleep(1);
                }
                /*int number,special,capital,small,a;
                for(a=0;a<strlen(user.password);a++)//checking the validity of password
                {
                    if(user.password[a]>='0' && user.password[a]<='9')
                        number=1;
                    if(user.password[a]>='a' && user.password[a]<='z')
                        small=1;
                    if(user.password[a]>='A' && user.password[a]<='Z')
                        capital=1;
                    if(user.password[a]=='!' || user.password[a]=='@' || user.password[a]=='#' || user.password[a]=='$' ||
                        user.password[a]=='%' || user.password[a]=='*')
                        special=1;

                }
                if(number==0 || special==0 || capital==0 || small==0)
                    printf("\t\t\t\t\t\t Invalid Password\n\n");
                else
                    printf("\t\t\t\t\t\t Valid Password\n\n");*/

                if(strcmp(user.password,user.password2)==0)//comparing two passwords
                {
                    printf("\t\t\t\t\t\t your password matched correctly!!\n\n");
                    sleep(1);
                }
                else
                {
                    printf("\a");
                    printf("\t\t\t\t\t\t oh no!!your password was not matched\n\n");
                    flag=1;
                    sleep(1);
                }
            }
            if(flag==0)//registered successfully
            {
                sleep(3);
                system("cls");
                printf("\t\t\t\t\t\t GREAT!!USER REGISTERED SUCCESSFULLY..............\n\n");

                fprintf(fp,"\n NAME:%s\nEMAIL%s\nPHONE NUMBER%s",user.name,user.email,user.phone);//storing in the excel file
                fprintf(pp1,"%s",user.name);
                fclose(pp1);
                fclose(fp);


                //calling the generating user name function from the given mail
                generateusername(user.email,user.username);
                printf("\n\n\t\t\t\t\t\t YOUR USERNAME WAS\t\t:%s",user.username);
                printf("\n\n\t\t\t\t\t\t YOUR PASSWORD WAS\t\t:");
                for(z=0;z<strlen(user.password);z++)
                {
                    printf("*");
                }
                l2:printf("\n\n\t\t\t\t\t\t TO SHOW THE PASSWORD=>PRESS 1...");//showing the password that is masked with asterisk
                scanf("%d",&opt);
                if(opt==1)
                    printf("\n\n\t\t\t\t\t\t YOUR PASSWORD WAS\t\t:%s",user.password);
                else{
                    goto l2;
                    }
                printf("\n\n\t\t\t\t\t\t DO YOU WANT TO CONTINUE TO LOGIN PAGE(y/n).........");//giving the prompt to user to continue or not
                scanf(" %c",&ch);
                if(ch=='y')
                {
                    printf("\n\n\t\t\t\t\t\t REDIRECTING.........");
                    sleep(3);
                    system("cls");
                    goto l1;
                }
                else
                {
                    return 0;
                }


            }
            else//printing the error in the giving credentials
            {
                printf("\a");//creating beep sound
                printf("\n\n\t\t\t\t\t\t SORRY!!TRY AGAIN :(:(............");
                printf("\n\n\t\t\t\t\t\t REDIRECTING.........");
                sleep(3);
                system("cls");
                goto l1;
            }
            break;
        }
        case 2://login page
        {
            char usr[50],pwd[50];
            printf("\t\t\t\t\t\t\t.............WELCOME TO LOGIN PAGE....................\n\n");//login inputs..
            printf("\n\n\t\t\t\t\t\t         ENTER YOUR USER NAME:\t\t");
            scanf("%s",&usr);
            printf("\n\n\t\t\t\t\t\t         ENTER YOUR PASSWORD:\t\t");
            int k=0;
            while(1)//getting password masked with asterisk
            {
                c= getch();
                if(c==ENTER||c==TAB){
                    pwd[k]='\0';
                    break;}
                else if(c==BKSP){
                    if(k>0){
                        k--;
                        printf("\b \b");
                    }
                }

                else{
                    pwd[k++]=c;
                    printf("* \b");}

            }
            sleep(2);

            if(strcmp(user.username,usr)==0){//checking for the correct user name
                printf("\n\n\t\t\t\t\t\t YOUR USERNAME MATCHED SUCCESFULLY!!\n\n");
                sleep(1);}
            else
            {
                printf("\n\n\t\t\t\t\t\t YOUR USERNAME NOT MATCHED !!\n\n");
                usrfound=0;
                sleep(1);
            }

            if(strcmp(user.password,pwd)==0){//checking for the correct password
                printf("\n\n\t\t\t\t\t\t YOUR PASSWORD MATCHED SUCCESSFULLY!!\n\n");
                sleep(1);}
            else
            {
                printf("\n\n\t\t\t\t\t\t YOUR PASSWORD NOT MATCHED!!\n\n");
                usrfound=0;
                sleep(1);
            }
            if(strcmp(user.username,usr)!=0)//printing the message "user not registered" if the name was not matched
            {
                if(strcmp(user.password,pwd)!=0)
                {
                    printf("\n\n\t\t\t\t\t\t USER NOT REGISTERED........\n\n");
                    usrfound=0;
                    sleep(1);
                }
            }


            if(usrfound==0)//redirecting again to first page
            {
                printf("\n\n\t\t\t\t\t\t REDIRECTING.........");
                sleep(4);
                system("cls");
                goto l1;
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t LOGIN SUCCESSFULL!!.........");
                fopen("UserDetails.dat","a+");
                fprintf(fp,"\n USER LOGIN DETAILS");
                fprintf(fp,"\nUSER NAME:%s",user.username);
                fprintf(fp,"\nPASSWORD:%s",user.password);
                fclose(fp);
                sleep(3);

            }
                break;

        }
        case 3://exit from the terminal
            {
                printf("\a");
                printf("\n\n\n\n\n\n\n OH NO!!BYE BYE!!......");
                sleep(3);
                exit(0);
            }
        case 4:
            {
                pp1=fopen("username.txt","r");
                int ff1=0;
                char z13[50];
                printf("\n\n\t\t\t\t\t\t ENTER YOUR NAME:");
                scanf("%s",user.name);
                while(fgets(z13,100,pp1))
                {
                    if(strcmp(z13,user.name)==0)
                    {
                        ff1=1;
                        break;
                    }
                }
                if(ff1==1){
                    printf("\n\n\t\t\t\t\t\t USER NAME MATCHED");

                    L20:system("cls");
                    printf("\n\n\t\t\t\t\t\t VERIFICATION OF OTP");
                    printf("\n\n\t\t\t\t\t\t PLEASE WAIT");
                    sleep(2);
                    char otp[6],ent_otp[6];char ch;
                    int jj,i;
                    srand((unsigned)time(NULL));
                    for(i=0;i<5;i++)
                    {
                        ch=rand()%10+44;
                        otp[i]=ch;

                    }
                    otp[i]='\0';
                    printf("\n\n\t\t\t\t\t\t your otp is :%s",otp);
                    printf("\n\n\t\t\t\t\t\t please verify your otp :");
                    scanf("%s",ent_otp);
                    if(strcmp(otp,ent_otp)==0)
                    {
                        printf("\n\n\t\t\t\t\t\t OTP verified");
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t OTP not verified");
                        printf("\n\n\t\t\t\t\t\t PRESS 1: to resend OTP");
                        scanf("%d",&jj);
                        if(jj==1)
                        {
                            goto L20;
                        }

                    }
                    sleep(2);
                    fclose(pp1);
                    system("cls");
                    goto L7;}
                else
                {
                    printf("\n\n\t\t\t\t\t\t USER NAME NOT MATCHED");
                    sleep(2);
                    fclose(pp1);
                    system("cls");
                    goto l1;

                }
                break;
            }
    }
    system("cls");
    L7:printf("\n\n\t\t\t\t\t\t DO YOU WANT TO BOOK BUS TICKET OR FLIGHT TICKET.......");
    printf("\n\n\t\t\t\t\t\t FOR BOOKING BUS TICKET PRESS 1\n\n\t\t\t\t\t\t FOR BOOKING FLIGHT TICKET PRESS 2");
    printf("\n\n\t\t\t\t\t\t  ENTER YOUR CHOICES=>");
    int t;
    scanf("%d",&t);
    if(t==2)
        goto l5;
    else
        goto A;

    A:srand(time(0));
    randloop=rand()%13;
    system("cls");
    printf("\n\n\t\t\t\t\t Welcome to MAKE MY TRIP -BUS RESERVATION PORTAL\t\t\n " );
    printf("\n\n\t\t\t\t\t\t 1 .RESERVATION");
    printf("\n\n\t\t\t\t\t\t 2 .SHOW ALL THE BUSES ");
    printf("\n\n\t\t\t\t\t\t 3 .PRICE LIST ");
    printf("\n\n\t\t\t\t\t\t 4 .EXIT ");
    scanf("%d",&opt);
    switch(opt)
    {
  case 1 :
	system("cls");
	printf("\n\t\t\t\t\t\tIn which class you want your journey :\n\n\t\t\t\t\t\t 1. AC\n\n\t\t\t\t\t\t 2. Non-AC");
	scanf("%d",&choosenclass);
	if(choosenclass==1)
	classofbus=6;
	else
	classofbus=3;
	system("cls");
	printf("FROM : ");
	printf("\n\n\t\t\t\t\t\t 1 . BANGALORE");
	printf("\n\n\t\t\t\t\t\t 2 . HYDERABAD");
	printf("\n\n\t\t\t\t\t\t 3 . CHENNAI");
	printf("\n\n\t\t\t\t\t\t 4 . MUMBAI");
	printf("\n\n\t\t\t\t\t\t 5 . DELHI");
	printf("\n\n\t\t\t\t\t\t 6 . PUNE");
	printf("\n\n\t\t\t\t\t\t 7 . Back to Main Menu\t ");
	int from1;
	scanf("%d",&from1);
	system("cls");
	switch(from1)
	{
	 case 1 :
		printf("\n\n\t\t\t\t\t\t Available roots from BANGALORE: ");
		printf("\n\n\t\t\t\t\t\t 1 . BANGALORE TO CHENNAI ");
		printf("\n\n\t\t\t\t\t\t 2 . BANGALORE TO JAIPUR");
		printf("\n\n\t\t\t\t\t\t 3 . BANGALORE TO PATHANKOT");
		printf("\n\n\t\t\t\t\t\t 4 . BANGALORE TO LUDHIYANA\t");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance = 128;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance =  40;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance =  171;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance =  116;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
	 case 2 :
		printf("\n\n\t\t\t\t\t\t Available roots from HYDERABAD : ");
		printf("\n\n\t\t\t\t\t\t 1 . HYDERABAD to CHANDIGARH ");
		printf("\n\n\t\t\t\t\t\t 2 . HYDERABAD to LUDHIYANA");
		printf("\n\n\t\t\t\t\t\t 3 . HYDERABAD to PATHANKOT");
		printf("\n\n\t\t\t\t\t\t 4 . HYDERABAD to AMBALA");
		printf("\n\n\t\t\t\t\t\t 5 . HYDERABAD to CHENNAI");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance =  126;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance = 40;
			price = distance*classofbus ;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance =  133;
			price = distance*classofbus ;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance =  150;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 5:
			distance = 342;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
	 case 3 :
		printf("\n\n\t\t\t\t\t\t Available roots from CHENNAI : ");
		printf("\n\n\t\t\t\t\t\t 1 . CHENNAI TO BANGALORE ");
		printf("\n\n\t\t\t\t\t\t 2 . CHENNAI TO COIMBATORE");
		printf("\n\n\t\t\t\t\t\t 3 . CHENNAI TO TIRUPATI");
		printf("\n\n\t\t\t\t\t\t 4 . CHENNAI TO HYDERABAD");
		printf("\n\n\t\t\t\t\t\t 5 . CHENNAI TO SECUNDARABAD");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance =  148;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance = 128;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance = 233;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance = 46;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 5:
			distance = 126;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
	 case 4 :
		printf("\n\n\t\t\t\t\t\t Available roots from MUMBAI : ");
		printf("\n\n\t\t\t\t\t\t 1 . MUMBAI TO PATNA  ");
		printf("\n\n\t\t\t\t\t\t 2 . MUMBAI to LUDHIYANA");
		printf("\n\n\t\t\t\t\t\t 3 . MUMBAI to PATHANKOT");
		printf("\n\n\t\t\t\t\t\t 4 . MUMBAI to PHAGWARA");
		printf("\n\n\t\t\t\t\t\t 5 . MUMBAI to Jalandhar");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance = 46;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance = 116;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance =  290;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance =  150;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 5:
			distance = 180;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
	 case 5 :
		printf("\n\n\t\t\t\t\t\t Available roots from DELHI : ");
		printf("\n\n\t\t\t\t\t\t 1 . DELHI to CHANDIGARH");
		printf("\n\n\t\t\t\t\t\t 2 . DELHI to LUDHIYANA");
		printf("\n\n\t\t\t\t\t\t 3 . DELHI to PATHANKOT");
		printf("\n\n\t\t\t\t\t\t 4 . DELHI to AMBALA");
		printf("\n\n\t\t\t\t\t\t 5 . DELHI to PHAGWARA");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance =  148;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance = 62;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance = 114;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance = 180;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			scanf("%d",&buschoosen);
			payment(price);
			exit(0);
		 case 5:
			distance = 30;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
	 case 6 :
		printf("\n\n\t\t\t\t\t\t Available roots from PUNE : ");
		printf("\n\n\t\t\t\t\t\t 1 . PUNE to DELHI ");
		printf("\n\n\t\t\t\t\t\t 2 . PUNE to CHENNAI");
		printf("\n\n\t\t\t\t\t\t 3 . PUNE to JAIPUR");
		printf("\n\n\t\t\t\t\t\t 4 . PUNE to JHARKHAND");
		printf("\n\n\t\t\t\t\t\t 5 . PUNE to CHENNAI");
		scanf("%d",&route);
		system("cls");
		switch(route)
		{
		 case 1:
			distance = 233;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 2:
			distance = 171;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 3:
			distance =  114;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 4:
			distance = 290;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 case 5:
			distance =  133;
			price = distance*classofbus;
			form(price);
			bus();
			fflush(stdin);
			payment(price);
			exit(0);
		 }
         case 7:
			goto A;

		 }
		 break;

  case 2 :
	  system("cls");
	  printf("\n\n\t\t\t\t\t\t Buses under MAKE MY TRIP ");
	  for(i=0;i<25;i++)
	  {
	   printf("\n\t\t\t\t\t\t%d - BUS NUMBER -  %dBCT%d",i+1,rand()%60,rand()%40);

	  }
	  getch();
      goto A;
	  break;
  case 3 :
	 printf("\n\n\t\t\t\t\t\t For AC seats 6 Rs. per Km per head ");
	 printf("\n\n\t\t\t\t\t\t For Non-Ac seat 3 Rs. per Km per head ");
	 getch();
     goto A;
	 break;
  case 4:
     exit(0);

 }
 exit(0);



    l5:system("cls");
    printf("\n\t\t\t\t\t WELCOME TO ALLIGIENT AIR LLC RESERVATION PORTAL");//reservation portal menu page
    printf("\n\n\t\t\t\t\t\t YOU WILL LOVE THE WAY WE FLY!!");
    printf("\n\n\t\t\t\t\t\t 1.CHECK AVAILABILITY ");
    printf("\n\n\t\t\t\t\t\t 2.RESERVATION");
    printf("\n\n\t\t\t\t\t\t 3.PROFILE VIEW");
    printf("\n\n\t\t\t\t\t\t 4.EXIT");
    printf("\n\n\t\t\t\t\t\t  ENTER YOUR CHOICES=>");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            system("cls");
            printf("\n\t\t\t\t\t\t checking available flight......");//checking the available flights and displaying
            printf("\n\t\t\t\t\t\t loading......");
            sleep(3);
            printf("\n\t\t\t\t\t\t FLIGHT NUM  \t FROM      \t\t\t\t  TO");
            printf("\n\t\t\t\t\t\t 123         \t MITCHIGAN \t\t\t\t  VILNIUS");
            printf("\n\t\t\t\t\t\t 675         \t OTTAWA    \t\t\t\t  NEW YORK");
            printf("\n\t\t\t\t\t\t 453         \t RIGA      \t\t\t\t  OSLO");
            printf("\n\t\t\t\t\t\t 984         \t CAPE TOWN \t\t\t\t  STOCKHOLM");
            printf("\n\t\t\t\t\t\t 324         \t LISBON    \t\t\t\t  GENEVA");
            printf("\n\t\t\t\t\t\t 096         \t BERN      \t\t\t\t  ATHENS");
            printf("\n\t\t\t\t\t\t 128         \t TALLIN    \t\t\t\t  BRUSSELS");
            printf("\n\t\t\t\t\t\t 654         \t SEOUL     \t\t\t\t  VILNIUS");
            printf("\n\t\t\t\t\t\t 564         \t MITCHIGAN \t\t\t\t  DELHI");
            printf("\n\t\t\t\t\t\t 300         \t WARSAW    \t\t\t\t  TEL AVIR");
            printf("\n\t\t\t\t\t\t 129         \t HELSINKI  \t\t\t\t  VILNIUS");
            printf("\n\t\t\t\t\t\t 834         \tLOS ANGELES\t\t\t\t  GENEVA");
            printf("\n\t\t\t\t\t\t 091         \t PARIS     \t\t\t\t  PRAGUE");
            printf("\n\t\t\t\t\t\t 234         \t PRAGUE    \t\t\t\t  LOS ANGELES");
            printf("\n\t\t\t\t\t\t 732         \t MONTREAL  \t\t\t\t  LONDON");
            printf("\n\t\t\t\t\t\t 123         \t TALLIN    \t\t\t\t  STOCK HOLM");
            printf("\n\t\t\t\t\t\t 434         \t MITCHIGAN \t\t\t\t  WARSAW");
            printf("\n\t\t\t\t\t\t 066         \t VILNIUS   \t\t\t\t  PARIS");
            l3:printf("\n PRESS 1 TO CONTINUE..");
            scanf("%d",&op);
            system("cls");
            if(op==1)
            {
                goto l5;
            }
            else
            {
                goto l3;
            }
            break;

        }

        case 2 :
        {
            system("cls");
            printf("\n\n\t\t\t\t\t\t PLEASE ENTER YOUR DETAILS IN CAPITAL LETTER\n");//getting the details from user
            printf("\n\n\t\t\t\t\t\t Enter your name : ");
            scanf("%*c%[^\n]s",name);
            scanf("%*c");
            printf("\n\n\t\t\t\t\t\t Enter your passport ID : ");
            scanf("%d",&passID);
            printf("\n\n\t\t\t\t\t\t Enter your phone number : ");
            scanf("%d",&pn);
            printf("\n\n\t\t\t\t\t\t Enter your permanent address : ");
            scanf("%*c%[^\n]s",perAdd);
            printf("\n\n\t\t\t\t\t\t Enter your current address : ");
            scanf("%*c%[^\n]s",currAdd);
            printf("\n\n\t\t\t\t\t\t DO YOU WANT TO CHECK THE AVAILABILITY AGAIN ?");
            printf("\n\n\t\t\t\t\t\t TO CHECK !! PRESS 1 :ELSE PRESS 2 :");
            int press;
            scanf("%d",&press);
            if(press==1)
            {
                printf("\n");
                printf("\n\t\t\t\t\t\t FLIGHT NUM  \t FROM      \t\t\t\t  TO");
                printf("\n\t\t\t\t\t\t 123         \t MITCHIGAN \t\t\t\t  VILNIUS");
                printf("\n\t\t\t\t\t\t 675         \t OTTAWA    \t\t\t\t  NEW YORK");
                printf("\n\t\t\t\t\t\t 453         \t RIGA      \t\t\t\t  OSLO");
                printf("\n\t\t\t\t\t\t 984         \t CAPE TOWN \t\t\t\t  STOCKHOLM");
                printf("\n\t\t\t\t\t\t 324         \t LISBON    \t\t\t\t  GENEVA");
                printf("\n\t\t\t\t\t\t 096         \t BERN      \t\t\t\t  ATHENS");
                printf("\n\t\t\t\t\t\t 128         \t TALLIN    \t\t\t\t  BRUSSELS");
                printf("\n\t\t\t\t\t\t 654         \t SEOUL     \t\t\t\t  VILNIUS");
                printf("\n\t\t\t\t\t\t 564         \t MITCHIGAN \t\t\t\t  DELHI");
                printf("\n\t\t\t\t\t\t 300         \t WARSAW    \t\t\t\t  TEL AVIR");
                printf("\n\t\t\t\t\t\t 129         \t HELSINKI  \t\t\t\t  VILNIUS");
                printf("\n\t\t\t\t\t\t 834         \tLOS ANGELES\t\t\t\t  GENEVA");
                printf("\n\t\t\t\t\t\t 091         \t PARIS     \t\t\t\t  PRAGUE");
                printf("\n\t\t\t\t\t\t 234         \t PRAGUE    \t\t\t\t  LOS ANGELES");
                printf("\n\t\t\t\t\t\t 732         \t MONTREAL  \t\t\t\t  LONDON");
                printf("\n\t\t\t\t\t\t 123         \t TALLIN    \t\t\t\t  STOCK HOLM");
                printf("\n\t\t\t\t\t\t 434         \t MITCHIGAN \t\t\t\t  WARSAW");
                printf("\n\t\t\t\t\t\t 066         \t VILNIUS   \t\t\t\t  PARIS");

            }
            else if(press ==2){
                printf("\n\n\t\t\t\t\t\t Enter the the three digit flight number : ");
                scanf("%d",&flightNum);}

            printf("\n\n\t\t\t\t\t\t From : ");
            scanf("%*c");
            scanf("%s",from);
            printf("\n\n\t\t\t\t\t\t To : ");
            scanf("%*c");
            scanf("%s",to);
            printf("\n\n\t\t\t\t\t\t day of journey=>");
            scanf("%d",&dd);
            printf("\n\n\t\t\t\t\t\t month of journey=>");
            scanf("%d",&mm);
            printf("\n\n\t\t\t\t\t\t year of journey=>");
            scanf("%d",&yy);
            system("cls");
            printf("\n\n\t\t\t\t\t\t VALIDATING THE DETAILS......");
            printf("\n\n\t\t\t\t\t\t PLEASE WAIT.....\n\n");
            sleep(2);
            int count1=0,count2=0,count3=0,count4=0,count5=0;
            //checking the correct name
            if(checkString(name)==1)//checking the name string
            {
                printf("\n\n\t\t\t\t\t\t your name is valid\n\n");
                sleep(2);
                count1=0;
            }
            else
            {
                printf("\a");
                printf("\n\n\t\t\t\t\t\t your name is invalid\n\n");
                count1=1;
                sleep(2);
            }


            int c3=0;//checking whether the departure region is correct or not
            for(i=0;i<30;i++)
            {
                if(strcmp(arr[i],from)==0)
                {
                    c3=0;
                    break;
                }
            }
            if(c3==0){
                printf("\n\n\t\t\t\t\t\t your departure region is matched");
                count2=0;
                sleep(2);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t your departure region is not matched");
                count2=1;
                sleep(2);

            }


            for(i=0;i<30;i++)
            {
                if(strcmp(arr[i],to)==0)//checking whether the arrival region is correct
                {
                    c3=0;
                    break;
                }
            }
            if(c3==0){
                printf("\n\n\t\t\t\t\t\t your arrival region is matched");
                count3=0;
                sleep(2);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t your arrival region is not matched");
                count3=1;
                sleep(2);

            }


            //check year
            if(yy>=1900 && yy<=9999)
            {
            //check month
                if(mm>=1 && mm<=12)
                {
                //check days
                    if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                        printf("\n\n\t\t\t\t\t\t Date is valid");
                        count5=0;}
                    else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                        printf("\n\n\t\t\t\t\t\t Date is valid");
                        count5=0;}
                    else if((dd>=1 && dd<=28) && (mm==2)){
                        printf("\n\n\t\t\t\t\t\t Date is valid");
                        count5=0;}
                    else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                        printf("\n\n\t\t\t\t\t\t Date is valid");
                        count5=0;
                        sleep(2);}
                    else{
                        printf("\n\n\t\t\t\t\t\t Day is invalid");
                        count5=1;
                        sleep(2);}
                }
                else
                {
                    printf("\n\n\t\t\t\t\t\t Month is not valid");
                    sleep(2);
                    count5=1;
                }
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t Year is not valid");
                sleep(3);
                count5=1;
            }


            if(count1==0 && count2==0 && count3==0  && count5==0 )//checking whether all the details are correct or not and redirecting according to the result
            {
                sleep(3);
                system("cls");
                printf("\n\n\t\t\t\t\t\t ALL THE DETAILS MATCHED AND VALIDATED CORRECTLY !!\n");//getting which type of class they want to book
                printf("\n\n\t\t\t\t\t\t YOUR FLIGHT HAS BEEN BOOKED CORRECTLY....\n");
                printf("\n\n\t\t\t\t\t\t ENTER THE TYPE OF CLASS");
                printf("\n\n\t\t\t\t\t\t 1.BUSINESS CLASS");
                printf("\n\n\t\t\t\t\t\t 2.ECONOMY CLASS");
                printf("\n\n\t\t\t\t\t\t 3.FIRST CLASS");
                printf("\n\n\t\t\t\t\t\t ENTER YOUR OPTION(1/2/3)=>");
                system("cls");
                scanf("%d",&class_opt);
                if(class_opt==1)
                    business_class(from,to);
                else if(class_opt==2)
                    economy_class(from,to);
                else
                    first_class(from,to);
                l4:printf("\n\n\t\t\t\t\t\t press 1 to continue\n");
                int p;
                scanf("%d",&p);
                if(p==1)
                {
                    printf("\n\n\t\t\t\t\t\t ENJOY YOUR JOURNEY\n");
                    printf("\n\n\t\t\t\t\t\t THANK YOU VISIT AGAIN..");
                    sleep(2);
                    system("cls");
                    ptr=fopen("user.dat","a");//storing the user details
                    fprintf(ptr,"\n\t\t\t\t\t\t FLIGHT RESERVATION DETAILS:");
                    fprintf(ptr,"\nNAME:%s\nPASSPORT:%d\nNUMBER:%d\nFLIGHT NUM:%d\nFROM:%s\nTO:%s\nDATE OF JOURNEY:%d.%d.%d\n",name,passID,pn,flightNum,from,to,dd,mm,yy);
                    fprintf(ptr,"CURRENT ADDRESS:%s\nPERMANENT ADDRESS:%s",currAdd,perAdd);
                    fclose(ptr);
                    goto l5;
                }
                else
                {
                    goto l4;

                }
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t SORRY ,YOUR DETAILS ARE NOT CORRECT :( :(");
                printf("\n\n\t\t\t\t\t\t SORRY FOR THE INCONVINIENCE !!");
                printf("\n\n\t\t\t\t\t\t redirecting.....");
                sleep(3);
                system("cls");
                goto l5;
            }
            break;


        }
        case 3://to display the details of the user after booking
        {
            int ps;
            l9:printf("\n\n\t\t\t\t\t\t please enter your passport ID");
            scanf("%d",&ps);
            if(ps==passID)
            {
                char cc;
                ptr=fopen("user.dat","r");
                while((cc=fgetc(fp))!=EOF)
                {
                    printf("%c",cc);
                }
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t please enter the correct passport ID");
                goto l9;
            }

            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
    }
    return 0;
}
void bus()
{
 srand(time(0));
 seat=rand()%30;
 printf("\n\n\t\t\t\t\t\t Buses Available between this route : ");
 for(i=0;i<randloop;i++)
 {
 printf("\n\n\t\t\t\t\t\t %d - BUS NUMBER -  %dBCT%d : PICKUP TIME - %d:%d%d ",i+1,rand()%60,rand()%40,rand()%23,rand()%6,rand()%9);
 }
 printf("\n\n\t\t\t\t\t\t Choose your choice : \t");
 scanf("%d",&buschoosen);
 if(seat<num)
 {
  system("cls");
  printf("\n\n\t\t\t\t\t\t Booking Failed...\n\n\t\t\t\t\t\t Sorry only %d seat is available in selected bus \n\n\t\t\t\t\t\t Sorry for your inconvenience ",seat);

  getch();
  exit(0);
 }
}
void form(int price)
{
 int total,k;
 int *n=&num ;
 system("cls");
 printf("\n\n\t\t\t\t\t\t Number of passenger : ");
 scanf("%d",n);
 total=price * num;
 system("cls");
 printf("\n\n\t\t\t\t\t\tTotal amount of ticket will be %d ",total);
 printf("\n\n\t\t\t\t\t\tPress 1 : if you want to proceed with book ticket :");
 scanf("%d",&k);
 system("cls");
 if(k==1)
 return;
}
void payment(int price)
{
   time_t t;
   time(&t);
   int j,age[100],i;
   char name[100][100];
   system("cls");
   for(i=0;i<num;i++)
   {
   fflush(stdin);
   printf("\n\n\t\t\t\t\t\t Enter name of %dth passenger :",i+1);
   gets(name[i]);
   printf("\n\n\t\t\t\t\t\t Age of passenger : ");
   scanf("%d",&age);
   }
   system("cls");
   printf("\n-----------------------------------YOUR TICKET----------------------------------\n");
   for(i=0;i<num;i++)
   {
   printf("\n\n\t\t\t\t\t\t Name:%s\n\n\t\t\t\t\t\t Age :%d\n\n\t\t\t\t\t\t Amount :%d",name[i],age[i],price);
   }
   printf("\n\n\n\t\t\t\t\t Press 1 to book ticket :");
   scanf("%d",&j);
   if(j==1)
   {
   printf("\n\n\t\t\t\t\t\t Booking Confirmed at %s \n\n\t\t\t\t\t\t Your ticket will be send to your account \n\n\t\t\t\t\t\t Birth Alloted : S%d \n\n\t\t\t\t\t\t Thank you for booking ticket with MAKE MY TRIP ",ctime(&t),rand()%100+1);
   }
   else
   {
   printf("\n\n\t\t\t\t\t\t Aborted");
   }
   getch();
}
/*void OTP()
{
    char otp[6],ent_otp[6];char ch;
    int jj,i;
    srand((unsigned)time(NULL));
    for(i=0;i<5;i++)
    {
        ch=rand()%10+44;
        otp[i]=ch;

    }
    otp[i]='\0';
    printf("\n\n\t\t\t\t\t\t your otp is :%s",otp);
    printf("\n\n\t\t\t\t\t\t please verify your otp :");
    scanf("%s",ent_otp);
    if(strcmp(otp,ent_otp)==0)
    {
        printf("\n\n\t\t\t\t\t\t OTP verified");
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t OTP not verified");
        printf("\n\n\t\t\t\t\t\t PRESS 1: to resend OTP");
        scanf("%d",&jj);
        if(jj==1)
        {
            goto L20;
        }

    }
}*/

