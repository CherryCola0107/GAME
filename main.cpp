#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string>
#include<ctime>
#include<time.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define MARTON_C 17
#define MARTON_A 8
#define MARTON_H 10
#define LEMONA_C 23
#define LEMONA_A 12
#define LEMONA_H 15
#define BRUJE_C 60
#define BRUJE_A 27
#define BRUJE_H 25

#define BANDAGE_C 20
#define BANDAGE_H 20
#define HERB_C 35
#define HERB_H 45
#define POTION_C 100
#define POTION_H 90

#define DAGGER_C 60
#define DAGGER_A 16
#define STEELSTICK_C 50
#define STEELSTICK_A 13
#define MACHETE_C 70
#define MACHETE_A 20
#define SWORD_C 85
#define SWORD_A 30
#define SPEAR_C 100
#define SPEAR_A 45

#define GENERAARMOR_C 45
#define GENERAARMOR_A 6
#define OCEANARMOR_C 60
#define OCEANARMOR_A 9
#define LANSTONARMOR_C 75
#define LANSTONARMOR_A 12
#define CROSSARMOR_C 90
#define CROSSARMOR_A 15
#define DIAMONDARMOR_C 150
#define DIAMONDARMOR_A 20

#define SANDWICH_C 10
#define FAKEPURPLEGEMNECKLACE_C 40
#define ROB 50
#define MAIDFEEDBACK 80
#define FAKEPURPLEGEMNECKLACE_S 90
#define REWARD 300
#define DONATE 60
#define HUNTER 300
#define LOSTHP 40

#define COINS 500
#define KASMONATTACK 15

#define SKILL1PP 3
#define SKILL2PP 2
#define SKILL3PP 3
#define SKILL4PP 3
#define SKILL5PP 3

using namespace std;
void color(short x)	//�Զ��庯���ݲ����ı���ɫ
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
    else//Ĭ�ϵ���ɫ��ɫ
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void getone(char& cht, char c)
    {
        do{
            cht=getch();
        }while(cht!=c);
    }

void gettwo(char& cht, char c1, char c2)
    {
        do{
            cht=getch();
        }while(cht!=c1 && cht!=c2);
    }

void getthree(char& cht, char c1, char c2, char c3)
    {
        do{
            cht=getch();
        }while(cht!=c1 && cht!=c2 && cht!=c3);
    }

void getsix(char& cht, char c1, char c2, char c3, char c4, char c5, char c6)
    {
        do{
            cht=getch();
        }while(cht!=c1 && cht!=c2 && cht!=c3 && cht!=c4 && cht!=c5 && cht!=c6);
    }

class Kasmon
{
public:
    int all_health=100,health=100, attack=15, defend=0;
    bool add_M=0, add_L=0, add_B=0;
    bool skill_1=0, skill_2=0, skill_3=0, skill_4=0, skill_5=0;
    bool use_heal=0;
    void status()
    {
        system("cls");
        cout<<"״̬��"<<endl<<endl<<endl;
        cout<<"����ֵ��"<<health<<endl<<endl;
        cout<<"��������"<<attack<<endl<<endl;
        cout<<"��������"<<defend<<endl<<endl<<endl;
        system("pause");
        system("cls");
    }
};
Kasmon kasmon;

class Enemy
{
public:
    int all_health,health, attack, defend;
};


class Backpack
{
public:
    int coins=COINS;
    string weapon="ͽ��", armor="��", shield="��";
    int weapon_add=0, armor_add=0;
    int marton=0, lemona=0, bruje=0;
    int bandage=0, herb=0, potion=0;
    int sandwich=0, book=0, fakepurplenecklace=0, iris=0;
    void show()
    {
        system("cls");
        cout<<"����"<<endl<<endl<<endl;
        cout<<"��ǰ��"<<coins<<"ö���"<<endl<<endl;
        cout<<"��ǰ������"<<weapon<<"�������������ӳɣ�"<<weapon_add<<endl<<endl;
        if(armor!="��")
            cout<<"��ǰ���ף�"<<armor<<"�����׷������ӳɣ�"<<armor_add<<endl<<endl;
        if(marton!=0)
            cout<<"��ǰ��"<<marton<<"ƿ��پ�"<<endl;
        if(lemona!=0)
            cout<<"��ǰ��"<<lemona<<"ƿ���ʾ�"<<endl;
        if(bruje!=0)
            cout<<"��ǰ��"<<bruje<<"ƿ��³Ү����"<<endl;
        if(bandage!=0)
            cout<<"��ǰ��"<<bandage<<"������"<<endl;
        if(herb!=0)
            cout<<"��ǰ��"<<herb<<"��ҩ��"<<endl;
        if(potion!=0)
            cout<<"��ǰ��"<<potion<<"�����־���"<<endl;
        if(sandwich!=0)
            cout<<"��ǰ��"<<sandwich<<"��������"<<endl;
        if(book!=0)
            cout<<"��ǰ��"<<book<<"���鼮"<<endl;
        if(fakepurplenecklace!=0)
            cout<<"��ǰ��"<<fakepurplenecklace<<"�����ϱ�ʯ����"<<endl;
        if(iris!=0)
            cout<<"��ǰ��1������ɫ�β"<<endl;
        cout<<endl<<endl<<endl<<endl;
    }
    void use()
    {
        char chh1,chh2;
        if(bandage>0)
            cout<<"��Dʹ�ñ���"<<endl<<endl;
        if(herb>0)
            cout<<"��Hʹ��ҩ��"<<endl<<endl;
        if(potion>0)
            cout<<"��Pʹ�����־���"<<endl<<endl;
        if(marton>0|| lemona>0 || bruje>0)
            cout<<"��Aʹ�þ�"<<endl<<endl;
        if(book>0)
            cout<<"��Oʹ���鼮"<<endl;
        bool have=0;
        do{
            getsix(chh1,27,'d','h','p','a','o');
            if(chh1=='d' && bandage>0)
                have=1;
            if(chh1=='h' && herb>0)
                have=1;
            if(chh1=='p' && potion>0)
                have=1;
            if(chh1=='a' && (marton>0 || lemona>0 || bruje>0) )
                have=1;
            if(chh1=='o' && book>0)
                have=1;
            if(chh1==27)
                have=1;
        }while(have==0);
        system("cls");
        switch(chh1)
        {
        case 'd':
            {
                if(bandage==0)
                    break;
                if(kasmon.health<100)
                {
                    cout<<"�����Ѿ�ʹ�ã�����ֵ�ָ�"<<BANDAGE_H<<endl<<endl;
                    kasmon.health+=BANDAGE_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    bandage-=1;
                }
                else
                {
                    cout<<"��û�����ˣ�����ʹ�ñ���"<<endl<<endl;
                }
                system("pause");
                system("cls");
                break;
            }
        case 'h':
            {
                if(herb==0)
                    break;
                if(kasmon.health<100)
                {
                    cout<<"ҩ���Ѿ�ʹ�ã�����ֵ�ָ�"<<HERB_H<<endl<<endl;
                    kasmon.health+=HERB_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    herb-=1;
                }
                else
                    cout<<"��û�����ˣ�����ʹ��ҩ��"<<endl<<endl;
                system("pause");
                system("cls");
                break;
            }
        case 'p':
            {
                if(potion==0)
                    break;
                if(kasmon.health<100)
                {
                    cout<<"���־����Ѿ�ʹ�ã�����ֵ�ָ�"<<POTION_H<<endl<<endl;
                    kasmon.health+=POTION_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    potion-=1;
                }
                else
                    cout<<"��û�����ˣ�����ʹ�����־���"<<endl<<endl;
                system("pause");
                system("cls");
                break;
            }
        case 'a':
            {
                if(marton==0 && lemona==0 && bruje==0)
                    break;
                cout<<"��ǰ��"<<marton<<"ƿ��پ�"<<endl;
                cout<<"��ǰ��"<<lemona<<"ƿ���ʾ�"<<endl;
                cout<<"��ǰ��"<<bruje<<"ƿ��³Ү����"<<endl<<endl;
                char choice;
                int own=0;
                cout<<"M          ʹ����پ�"<<endl;
                cout<<"L          ʹ�����ʾ�"<<endl;
                cout<<"B          ʹ�ò�³Ү����"<<endl<<endl;
                do{
                    choice=getch();
                    if(choice=='m'&&marton!=0)
                        own=1;
                    if(choice=='l'&&lemona!=0)
                        own=1;
                    if(choice=='b'&&bruje!=0)
                        own=1;
               }while(own==0);
                system("cls");
                cout<<"��Ҫ���ʹ����ƿ�ƣ�"<<endl<<endl;
                cout<<"I          ����"<<endl;
                cout<<"C          �����˿ڣ�Ч�ʽϵͣ�"<<endl<<endl<<endl;
                cout<<"esc        ����"<<endl;
                getthree(chh2,'i','c',27);
                system("cls");
                if(chh2=='i')
                {
                    if(kasmon.add_M==0 && kasmon.add_L==0 && kasmon.add_B==0)
                    {
                        switch(choice)
                        {

                        case 'm':
                            marton-=1;
                            kasmon.add_M=1;
                            kasmon.attack+=MARTON_A;
                            cout<<"��Ĺ���������С�����ӣ�������һ��ս����"
                            <<endl<<endl;
                            break;
                        case 'l':
                            lemona-=1;
                            kasmon.add_L=1;
                            kasmon.attack+=LEMONA_A;
                            cout<<"��Ĺ���������һ�������ӣ�������һ��ս����"
                            <<endl<<endl;
                            break;
                        case 'b':
                            bruje-=1;
                            kasmon.add_B=1;
                            kasmon.attack+=BRUJE_A;
                            cout<<"��Ĺ��������˿ɹ۵����ӣ�������һ��ս����"
                            <<endl<<endl;
                            break;
                        }
                    }
                    else
                        cout<<"���Ѿ��ȹ����ˣ��ٺȾ�Ҫ�ȶ���"<<endl<<endl;
                    system("pause");
                    system("cls");
                }
                else if(chh2=='c')
                {
                    if(kasmon.health<100)
                    {
                        switch(choice)
                        {
                        case 'm':
                            marton-=1;
                            kasmon.health+=MARTON_H;
                            cout<<"��پ��Ѿ����������˿ڣ�����ֵ�ָ�"<<MARTON_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                         case 'l':
                            lemona-=1;
                            kasmon.health+=LEMONA_H;
                            cout<<"���ʾ��Ѿ����������˿ڣ�����ֵ�ָ�"<<LEMONA_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                        case 'b':
                            bruje-=1;
                            kasmon.health+=BRUJE_H;
                            cout<<"��³Ү�����Ѿ����������˿ڣ�����ֵ�ָ�"<<BRUJE_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                        }
                    }
                    else
                        cout<<"��û�����ˣ�����ʹ�þ�������"<<endl<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            }//case'a'β��
        case 'o':
            {
                system("cls");
                kasmon.skill_2=1;
                cout<<"[��ʾ] ��ѧ���˼��ܡ��񵲷���"<<endl<<endl;
                cout<<"���ܽ��ܣ���һ��ʹ�ú����������6�㣬�ڶ���ʹ�ú����������3�㡣"<<endl<<endl;
                book=0;
                getch();
                break;
            }
        default:;
        }
    }
};
Backpack bp;

bool cck(int c)//������Ʒǰ�������Ƿ��㹻
{
    if(bp.coins-c<0)
    {
        cout<<"��Ҳ��㣡"<<endl<<endl;
        system("pause");
        return 0;
    }
    else
        return 1;
}

void blood(int a,int b)//��ǰѪ��|��Ѫ��
{
    int i=0;
    float n;
    n=100*(float)a/b;
    cout<<"HP :   ";
    for(i=0;i<100;i++)
    {
        if(i<=n)
            n>50?SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15| 8 | 66 | 64):SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15| 8 | 66 | 32);
        else if(i>n)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 118 | 32);
        cout<<" ";
    }
    color(21);
    cout<<endl;
}
//ս��ϵͳ�������ɵ�
void fight(Kasmon& a, Enemy& b,int num=0)
{
    switch(num)
    {
        case 1: PlaySound("ǿ��ս��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP); break;
        case 2: PlaySound("�������� Ұ����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP); break;
        case 3: PlaySound("�������漰��������.wav",NULL,SND_FILENAME | SND_ASYNC); break;
        case 4: PlaySound("�������漰��������.wav",NULL,SND_FILENAME | SND_ASYNC); break;
        case 5: PlaySound("�������漰��������.wav",NULL,SND_FILENAME | SND_ASYNC); break;
    }
    int a0=a.attack, d0=a.defend;
    int time_1=SKILL1PP; int time_2=SKILL2PP; int time_3=SKILL3PP; int time_4=SKILL4PP; int time_5=SKILL5PP;
    char c;
    int Gailv, randp, aatk, batk, ad, bd;
    srand((unsigned int)time(NULL));
    while(b.health>0 && a.health>0)
    {
        system("cls");
        cout<<"���ڽ���ս��..."<<endl<<endl;
        cout<<"ѡ�������ʹ�õļ��ܣ�"<<endl<<endl;
        cout<<"A       ��ͨ����"<<endl;
        if(a.skill_1==0)
            cout<<"1       [δѧϰ����]"<<endl;
        else
            cout<<"1       ��  ��"<<"         ʣ��ʹ�ô�����"<<time_1<<"/"<<SKILL1PP<<endl;
        if(a.skill_2==0)
            cout<<"2       [δѧϰ����]"<<endl;
        else
            cout<<"2       �񵲷���"<<"       ʣ��ʹ�ô�����"<<time_2<<"/"<<SKILL2PP<<endl;
        if(a.skill_3==0)
            cout<<"3       [δѧϰ����]"<<endl;
        else
            cout<<"3       ��  ��"<<"         ʣ��ʹ�ô�����"<<time_3<<"/"<<SKILL3PP<<endl;
        if(a.skill_4==0)
            cout<<"4       [δѧϰ����]"<<endl;
        else
            cout<<"4       ԭҰ�̿���"<<"     ʣ��ʹ�ô�����"<<time_4<<"/"<<SKILL4PP<<endl;
        if(a.skill_5==0)
            cout<<"5       [δѧϰ����]"<<endl;
        else
            cout<<"5       ���⼱����"<<"     ʣ��ʹ�ô�����"<<time_5<<"/"<<SKILL5PP<<endl;
        if( (bp.bandage!=0 || bp.herb!=0 || bp.potion!=0) && kasmon.health<100 && kasmon.use_heal==0)
            cout<<endl<<endl<<"H       ʹ��������Ʒ"<<endl;
        cout<<endl<<endl;
        bool he=0;
        do{
            c=getch();
            if((c=='H' || c=='h') && (bp.bandage!=0 || bp.herb!=0 || bp.potion!=0) && kasmon.health<100 )
                he=1;
            if(c!='H' && c!='h')
                he=1;
        }while(he==0);
        if(c=='A' || c=='a')
        {
            if(bp.weapon=="ͽ��")
            {
                randp=rand()%2+1;
                if(randp==1)
                    cout<<"��ݺݻ�ȭ��Է���ȥ����"<<endl;
                else
                    cout<<"��������ȣ���Է�Ϯȥ����"<<endl;
            }
            else
            {
                randp=rand()%2+1;
                if(randp==1)
                    cout<<"����Է��ݺݻӶ����е���������"<<endl<<endl;
                else
                    cout<<"�������������Է�����ȫ��һ������"<<endl<<endl;
            }
            cout<<"ͬʱ���Է�Ҳ��������˹�������"<<endl<<endl;
            Sleep(1000);
            aatk=rand()%12+a.attack-6;
            batk=( b.attack*(rand()%4+8) )/10;
            ad=batk-a.defend;
            bd=aatk-b.defend;
            if(ad<=0)
                ad=rand()%3+1;
            if(bd<=0)
                bd=rand()%3+1;
            a.health-=ad;
            b.health-=bd;
            cout<<"�Է�����ֵ -"<<bd<<endl;
            cout<<"�������ֵ -"<<ad<<endl<<endl;
            if(b.health>0)
            {

                cout<<"�Է�������ֵ:"<<b.health<<endl;
                blood(b.health,b.all_health);
            }
            else
                cout<<"�Է�������ֵ:0"<<endl;
            if(a.health>0)
            {

                cout<<"�������ֵ:"<<a.health<<endl;
                blood(a.health,a.all_health);
            }
            else
                cout<<"�������ֵ:0"<<endl;
        }
        if(c=='1')
        {
            if(a.skill_1==0)
                cout<<"������δ����...."<<endl;
            else
            {
                if(time_1<=0)
                    continue;
                time_1--;
                a.attack=(a.attack*120)/100;
                cout<<"���˺�һ����������������"<<endl;
                cout<<"��Ĺ�����������20%"<<endl;
                batk=( b.attack*(rand()%4+8) )/10;
                ad=batk-a.defend;
                if(ad<=0)
                    ad=rand()%3+1;
                a.health-=ad;
                cout<<"�����ͬʱ���Է����㷢���˹�������"<<endl<<endl;
                Sleep(1000);
                cout<<"�������ֵ -"<<ad<<endl<<endl;
                if(b.health>0)
                {

                    cout<<"�Է�������ֵ:"<<b.health<<endl;
                    blood(b.health,b.all_health);
                }
                else
                    cout<<"�Է�������ֵ:0"<<endl;
                if(a.health>0)
                {

                    cout<<"�������ֵ:"<<a.health<<endl;
                    blood(a.health,a.all_health);
                }
                else
                    cout<<"�������ֵ:0"<<endl;
            }
        }
        if(c=='2')
        {
            if(a.skill_2==0)
                cout<<"������δ����...."<<endl;
            else
            {
                if(time_2<=0)
                    continue;
                time_2--;
                cout<<"���������ؼܣ���ʼ����ע��񵲶Է��Ĺ�������"<<endl;
                if(time_2==SKILL2PP-1)
                {
                    kasmon.defend+=6;
                    cout<<"��ķ�����������6��"<<endl<<endl;
                }
                else
                {
                    kasmon.defend+=3;
                    cout<<"��ķ�����������3��"<<endl<<endl;
                }
            batk=( b.attack*(rand()%4+8) )/10;
            ad=batk-a.defend;
            if(ad<=0)
                ad=rand()%3+1;
            a.health-=ad;
            cout<<"�����ͬʱ���Է����㷢���˹�������"<<endl<<endl;
            Sleep(1000);
            cout<<"�������ֵ -"<<ad<<endl<<endl;

            if(b.health>0)
            {
                cout<<"�Է�������ֵ:"<<b.health<<endl;
                blood(b.health,b.all_health);
            }
            else
                cout<<"�Է�������ֵ:0"<<endl;
            if(a.health>0)
            {

                cout<<"�������ֵ:"<<a.health<<endl;
                blood(a.health,a.all_health);
            }
            else
                cout<<"�������ֵ:0"<<endl;
            }
        }
        if(c=='3')
        {
            if(a.skill_3==0)
                cout<<"������δ����...."<<endl;
            else
            {
                if(time_3<=0)
                    continue;
                time_3--;
                aatk=rand()%12+a.attack-6;
                batk=( b.attack*(rand()%4+8) )/10;
                ad=batk-a.defend;
                if(ad<=0)
                    ad=rand()%3+1;
                cout<<"�������ɨ�����ܣ��������ͼ��磬������ֱ��Է�Ҫ������"<<endl;
                cout<<"ͬʱ���Է�Ҳ���㷢���˹�������"<<endl<<endl;
                Sleep(1000);
                Gailv=rand()%100+1;
                if(Gailv<=40)
                {
                    bd=aatk*3-b.defend;
                    cout<<"��һ������������˺�!��˴ι������˺��Ѿ��������"<<endl<<endl;
                }
                else
                {
                    bd=(aatk*8)/10-b.defend;
                    cout<<"������һ��û�ܷ��������������"<<endl<<endl;
                }
                if(bd<=0)
                    bd=rand()%3+1;
                a.health-=ad;
                b.health-=bd;
                cout<<"�Է�����ֵ -"<<bd<<endl;
                cout<<"�������ֵ -"<<ad<<endl<<endl;
                if(b.health>0)
                {
                    cout<<"�Է�������ֵ:"<<b.health<<endl;
                 blood(b.health,b.all_health);
                }
                else
                    cout<<"�Է�������ֵ:0"<<endl;
                if(a.health>0)
                {
                     cout<<"�������ֵ:"<<a.health<<endl;
                     blood(a.health,a.all_health);
                }
                else
                    cout<<"�������ֵ:0"<<endl;
            }
        }
        if(c=='4')
        {
            if(a.skill_4==0)
                cout<<"������δ����...."<<endl;
            else
            {
                if(time_4<=0)
                    continue;
                time_4--;
                aatk=rand()%12+a.attack-6;
                batk=( b.attack*(rand()%4+8) )/10;
                cout<<"��ʹ����ϰ��ԭҰ�����ʹ̿�������Է������������Ĺ�������"<<endl<<endl<<endl;
                Sleep(1000);
                int i,j,t,aa; i=rand()%3+3;
                for(j=1;j<=i;++j)
                {
                    cout<<"��"<<j<<"�ι���,";
                    t=rand()%10+1;
                    if(t>=8)
                    {
                        cout<<"�ƴ����㣬ɱ����ʮ��ǿ��"<<endl<<endl;
                        aa=aatk;
                    }
                    else if(t>=4 && t<=7)
                    {
                        cout<<"�����ɹۣ�ɱ���Բ���С��"<<endl<<endl;
                        aa=(aatk*7)/10;
                    }
                    else
                    {
                        cout<<"������ѷ��ɱ��������Ƿȱ"<<endl<<endl;
                        aa=(aatk*4)/10;
                    }
                    bd=aa-b.defend;
                    if(bd<=0)
                        bd=rand()%3+1;
                    b.health-=bd;
                    cout<<"�Է�����ֵ -"<<bd<<endl<<endl;
                    if(b.health>0)
                    {
                        cout<<"�Է�������ֵ:"<<b.health<<endl;
                        blood(b.health,b.all_health);
                    }
                    else
                        cout<<"�Է�������ֵ:0"<<endl;
                    getch();
                    cout<<endl<<endl<<endl;
                }
                if(b.health>0)
                {
                    cout<<"ͬʱ���Է�Ҳ�����˷�������"<<endl<<endl;
                    ad=b.attack-a.defend;
                    if(ad<=0)
                        ad=rand()%3+1;
                    a.health-=ad;
                    Sleep(1000);
                    cout<<"�������ֵ -"<<ad<<endl<<endl;
                    if(a.health>0)
                    {

                        cout<<"�������ֵ:"<<a.health<<endl;
                        blood(a.health,a.all_health);
                    }
                    else
                        cout<<"�������ֵ:0"<<endl;
                }
            }
        }
        if(c=='5')
        {
            if(a.skill_5==0)
              cout<<"������δ����...."<<endl;
            else
            {
                if(time_5<=0)
                    continue;
                time_5--;
                int hpadd, he0;
                hpadd=rand()%11+20;
                he0=a.health;
                a.health+=hpadd;
                if(a.health>100)
                {
                    a.health=100;
                    hpadd=100-he0;
                }
                cout<<"��ʹ����ϰ�Ժ��������⼱�ȷ���������ֵ�ָ���"<<hpadd<<endl<<endl;
                cout<<"���ͬʱ���Է��˴εĹ������㻯�⡭��"<<endl<<endl;
                Sleep(1000);
                batk=( b.attack*(rand()%4+8) )/10;
                ad=batk-a.defend;
                if(ad<=0)
                    ad=rand()%3+1;

                if(b.health>0)
                {

                    cout<<endl<<"�Է�������ֵ:"<<b.health<<endl;
                    blood(b.health,b.all_health);
                }
                else
                    cout<<"�Է�������ֵ:0"<<endl;
                if(a.health>0)
                {
                    cout<<"�������ֵ:"<<a.health<<endl;
                    blood(a.health,a.all_health);
                }
                else
                    cout<<"�������ֵ:0"<<endl;
            }
        }
        if((c=='H' || c=='h') && kasmon.use_heal==0)
        {
            system("cls");
            if(bp.bandage!=0)
                cout<<"��Bʹ�ñ���"<<endl<<endl;
            if(bp.herb!=0)
                cout<<"��Hʹ��ҩ��"<<endl<<endl;
            if(bp.potion!=0)
                cout<<"��Pʹ�����־���"<<endl<<endl;
            char cc;
            getthree(cc,'b','h','p');
            if(cc=='b')
            {
                kasmon.health+=BANDAGE_H;
                cout<<"����ֵ�ָ�"<<BANDAGE_H<<endl;
                bp.bandage-=1;
            }
            else if(cc=='h')
            {
                kasmon.health+=HERB_H;
                cout<<"����ֵ�ָ�"<<HERB_H<<endl;
                bp.herb-=1;
            }
            else
            {
                kasmon.health+=POTION_H;
                cout<<"����ֵ�ָ�"<<POTION_H<<endl;
                bp.potion-=1;
            }
            kasmon.use_heal=1;
            if(kasmon.health>100)
                kasmon.health=100;
        }
        getch();
    }

    if(b.health<=0 && a.health>0)
    {

        cout<<endl<<"���գ���Ӯ����ս����"<<endl<<endl;
        if(num!=9&&num!=8)
        PlaySound("�հ�.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
    }
    else if(a.health<=0)
    {
        cout<<endl<<"����ս���������ˡ�"<<endl<<endl;
        getch();
        system("pause");
        system("cls");
        cout<<"����������˵��һ����ȥ���Ͼ���һ·�ϳ�����Σ�ա�"<<endl<<endl;
        getch();
        cout<<"�����¸ҵ�ð���߲�����Զ���ֵ�����״̬��"<<endl<<endl;
        getch();
        cout<<"Ҳ�����л��᣿"<<endl<<endl;
        getch();
        exit(0);
    }
    a.attack=a0; a.defend=d0;
    kasmon.use_heal=0;
    if(kasmon.add_M==1)
    {
        kasmon.add_M=0;
        kasmon.attack=kasmon.attack-MARTON_A;
    }
    if(kasmon.add_L==1)
    {
        kasmon.add_L=0;
        kasmon.attack=kasmon.attack-LEMONA_A;
    }
    if(kasmon.add_B==1)
    {
        kasmon.add_B=0;
        kasmon.attack=kasmon.attack-BRUJE_A;
    }
    system("pause");
    system("cls");
}

void daycost()
{
    system("cls");
    srand((unsigned int)time(NULL));
    int cost;
    cost=rand()%11+10;
    if((bp.coins-=cost)>=0)
       {
           cout<<"��һ������ˣ��㻨����"<<cost<<"��ҵ��ӷѣ���ʣ"<<bp.coins<<"��ҡ�"<<endl<<endl;
           system("pause");
           system("cls");
       }
    else
        {
            cout<<"���ź�����Ľ�Ҳ�����Ӧ�Խ��������г�����Ŀ������Ͼ�֮�õ��˽�����"<<endl<<endl;
            getch();
            exit(0);
        }
}


void  victory()
{
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<"                                                           "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"             ";color(6);cout<<"LONELY JOURNEY TO THE SOUTHLAND";color(16);cout<<"             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"�� �� �� ��";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"   ";color(4);cout<<"           ___  ____  _____  ____    _____ ";color(16);cout<<"           ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"   ";color(4);cout<<"  \\      /  |  |        |   |    |  |     |  \\   /";color(16);cout<<"    ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"   ";color(2);cout<<"   \\    /   |  |        |   |____|  |     |   \\ /";color(16);cout<<"     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"   ";color(11);cout<<"    \\  /    |  |        |   |  \\    |     |    |";color(16);cout<<"      ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"   ";color(23);cout<<"     \\/    _|_ |____    |   |   \\   |_____|    | ";color(16);cout<<"     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<"                                                           "<<endl;

}
void menu()
{
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102|32);cout<<"                                                           "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"             ";color(7);cout<<"LONELY JOURNEY TO THE SOUTHLAND";color(16);cout<<"             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"�� �� �� ��";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 109 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |  102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                   ";color(2);cout<<"'space'    ��ʼ����";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 103 | 32);cout<<" ";color(16);cout<<"                   ";color(4);cout<<"'h'         ��  �� ";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                   ";color(3);cout<<"'esc'      �˳���Ϸ";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<"                                                           "<<endl;color(16);
}
void maker()
{
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                                                                                       "<<endl;
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102|32);cout<<"                                                           "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"             ";color(7);cout<<"LONELY JOURNEY TO THE SOUTHLAND";color(16);cout<<"             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"�� �� �� ��";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 109 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |  102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"      ";color(2);cout<<"  �� �� �� �� ��              ";color(16);cout<<"                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);;
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       Nic";color(16);cout<<"                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 103 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       �����ļ�ʸ ";color(16);cout<<"             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       i-kun";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                 ��  л  ��  ��  ��  ��                  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<"                                                           "<<endl;color(16);
}
void help()
{
color(16);
cout<<" �㼴��������һ�������ʱ�գ�һ������ð���ߵ���������־����ʱ���������У�������������һ�С�"<<endl;
cout<<" �����У�����Ҫ���ݺ�����ð���ߣ�ֱ���ﵽ�����ó̵��յ㡣����һЩ��Ҫע������飺"<<endl<<endl;
color(6);cout<<" 1. ���"<<endl<<endl;color(11);
cout<<" �����ý�������н��ס��������һЩ��ң�����������Ľ�һ���Ϊ������������������ӻ���ٵı仯���ܴ�̶���ȡ��������ж���Ҫע�⣬ͨ��������ó��е�ÿһ�����ʱ��Ҫ֧��10~20�������Ϊ�ó��г�ס��һ����ӷѣ������һ����û���㹻�Ľ�ҿ���֧���������ó�Ҳ�����ò���ֹ��"<<endl;
cout<<" "<<endl;
color(6);cout<<" 2. ����Ʒ"<<endl;color(11);
cout<<" ����Ʒ����������ҩ�������־�������һ��ʮ����Ҫ����Ʒ����������ڱ����г�����������ס��ʱ��ʱ���������ָ�����ֵ��"<<endl;
cout<<" "<<endl;
color(6);cout<<" 3. ����"<<endl;color(11);
cout<<" ��ս���У�������ͨ�������⣬��һ�����ѡ��ʹ�ö�����ܣ�����Щ���ܶ���Ҫһ���¼��Ĵ���������ض����¼��ᵼ���޷�ѧϰ����ܡ�"<<endl;
cout<<" "<<endl;
color(6);cout<<" 4. ��Ϸ���̵���һЩ�������õĶ���������ʮ����Ҫ���ô���"<<endl;color(16);
color(6);cout<<" 5. ��Ϸ�о���ͣ��ʱ��������ɼ���������������������Ի�ʱ����Ҫ�������Ի����Զ����С�"<<endl;color(16);
cout<<" "<<endl;
cout<<" ף����Ϸ��죡  (���ո񷵻���ҳ��)  "<<endl;
}
int main()
{
    menu();
    PlaySound("�������漰��������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
    char ch,ch1,ch2,ch3;
    bool robfight=0, beggar=0, maid=0, teamfight=0, banout=0;
    unsigned seed;
    seed=time(0);
    srand(seed);
    loop :
    getthree(ch,32,27,'h');
    system("cls");
    if(ch==27)
        exit(0);
    else if(ch=='h')
    {
        help();
        gettwo(ch,32,27);
        system("cls");
        menu();
        goto loop;
    }
    else if(ch==32)
    {
        PlaySound("��ʼ����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"-----------------------------------------------"<<endl<<endl;//���� ��ʼ����
        cout<<"�������Խ�����ԵΪ��Ĭ·˹�Ĵ�½������ʪ�����գ�������件��������ڰ�Ĭ·˹��ÿһ�껨���У���ů���ڰ�Ĭ·˹����Ƕ�Ű�ɫ��˿�ĵ������Ĭ������ʱ��ÿ���������ס�����Ƕ��ڻ�Ц�������ˡ���"<<endl<<endl;
        cout<<"�⽫�ǰ�Ĭ·˹����һ����"<<endl<<endl;
        cout<<"��̤����С������������ĸ������ҵļ���ȥ���ڴ�ľ�����¶�һԾ���£�����������ػ������Ĳݵ���֮ǰ����һֱ�����ڸ������˵�С���С����С����������֮�У��ҳ����˴��ȹ���ǲ��ʱ�⣬ÿ�������ڴˣ���֪�Ƿ�Ҳ����С����ߴ���Ե�ʣ���ʱ��������Լ�������һֻ��ֻ���ڴ˴���Ϣ��"<<endl<<endl;
        cout<<"����ƹ�֮���С�������ƹ��ϰ�Ķ������д���к����������ǰ�Ĭ·˹��½�ı����ߡ�������Զ�����ŵ�һԱ�������ڹ�ȥ��ʮ�����ڳɹ������������Ŀ�˹��ķ�����������˵��ˣ�����֮�⻹�и����¼�����һ�ж��ñ����Ե������ʥ��ΰ�󡣼����������������һ�������ٹ�����飬��һֱ����֮���򣬿ɸ�����˵ʱ��δ����"<<endl<<endl;
        cout<<"���ҵ����˼��ţ�ĸ�׵�֪�����Ѿ���ң������ڲ��������£��ȴ������ڵ�Ѽ���Ϳ�������������Ȼ�����кܶ�������ʳ�"<<endl<<endl;
        cout<<"���׺͵ܵ��Ѿ��ڲ������ã�����ȥ�������Ѿ��Ⱥ��Ҷ�ʱ����¶��һ����Ȼ��΢Ц���������򴰵�λ�ã������ҵĳ�����"<<endl<<endl;
        cout<<"����һ�굱�����ʢ��һ�ͣ��ҵļ��˺��Ҷ�֪��ԭ�򡪡�"<<endl<<endl;
        cout<<"�ڽ��죬�����ڳ��ꡣ"<<endl<<endl;
        cout<<"�����ڻ���Ц�����㷹������ʱ��������Ҫ���Ҹ�������Ժ����ȥ������Ȼͬ�⣬�����ǲ�������ط��ʡ�����˵����Ҫ�����ҳ���֮��"<<endl<<endl;
        cout<<endl; system("pause");
        system("cls");
        cout<<"һƥ���Ҹ�ͷ������Ժ�����밲�������������ҿ�����ʱ�����е��˷�֮�����Կ��ơ�������ë���ǻ�ɫ��ȴ��ů��ӳ����ɢ���������Ĺ��󣬾��񻪹�Ŀ�˹��ķ��̺����Ϊ���Һ͹��������á����׸����ң��������������������ԭ�����׳����Ѹ�ݣ�Ҳ��������ѱ����Ʒ�֡������죬���׻��ؽ�������ƥ���ڽ��죬�����������ҡ�"<<endl<<endl;
        cout<<"����˹�ɣ���֪����ϲ����ƽԭ�ϲ����ۣ����ԣ�������������������ġ���"<<endl<<endl;
        cout<<"�����ױ��������ֿ��л�⣬ͬʱҲΪ����������֡��������أ��ڰ�Ĭ·˹ͨ�������ǡ����硱֮�⡣"<<endl<<endl;
        cout<<"���Ȳ�����������������С���ϱ�ǰ�У���Ϊ�ϱ��а�Ĭ·˹�����ƽԭ�����Ѿ��޷��ȴ�ȥ��֤���Ƿ���������һ��Ѹ�ݶ�ǿ����ֱ�����еظ��ܵ��������ҵ��ٶȣ���ȥ��������Ŀ�����һ����Ȼʧɫ����������һ���������ë֮�ϣ��ҷ·�Ҳһͬ������ƽԭ�ϵ����磬�ڷ�۵糸��������һ�У�ͽ����ǰ���ۡ�"<<endl<<endl;
        cout<<"���ƻ轥�����ȻƵ��չ�������ƽԭ�������������궥�壬����ʱ����ͣ�£�����һ���޼ʵ��ϱߡ�"<<endl<<endl;
        cout<<"ǡ�ڴ�ʱ���ҵ��Ժ�ӳ��һ�����յ�ӳ��"<<endl<<endl;
        getch(); system("cls");
        cout<<"����ʮ����ǰ�����Һ͵ܵ���ֻ��������ͯ���ҳ�����������ĸ�������ر��ܻ��С�һ���������ʵ����ӣ����Ǳ������뿪���ţ�������¶��԰��С�����ִ������ļ��У��ڲ�֪�����䣬��������������ϲ���Ե���������Щ������������Ⱥ�Ѳ����ܼ����������������߹��ĸ������̷���Ҳ��������ǽ�����������С���ӡ�Ψһ�ܼ����ģ��������������ϵİ�Ĭ·˹�ӣ���������ض����͵��±ڣ��Լ�һλ�����������²ݵ��е����ߡ�"<<endl<<endl;
        cout<<"�ǻ�������ܵܵ�һ�������������İ���ĵؽ磬�����Щ������ķ�Χ֮�У����������Ļ������궯��ʧ�˲��٣�ȡ����֮���������е��Ƕ�������ؾ�����ɻ󡣲������������������ʱ����������ĺ��Ӷ��ԣ�����������̽�����ľ���ʱ�̡�����ܵ�ֻ����һ�ۣ����ղ�����һͬ����������ͨ���������֮��Ψһ��������"<<endl<<endl;
        cout<<"�������ǣ�����Ҫ������ȥ����"<<endl<<endl;
        cout<<"����������ͷ�����Ų������˽�ס�����ǡ�����������������ߣ������ǵ���˼����������"<<endl<<endl;
        cout<<"�������ǣ�����������������ˣ���ֶ���Ϊ����ֻ�ǣ�ǧ��Ҫ����������䡪���ǿ�Խ���������������Զ���Ϸ�����"<<endl<<endl;
        cout<<"��ʱ�����ǵĺ��汻����ؼ���æ��Ϊʲô������Ц�˼��������˷���΢�紵���ĺ��롣"<<endl<<endl;
        cout<<"���Ͼ������ﳣ������֮�·����������˿־�������������������š�ȥ����������ǣ���û��һλ���Թ黹����"<<endl<<endl;
        cout<<"��ʹ���۵����Ƕ���Щ��ֻ���ƶ��Ƕ����������ѳɹ�ʹ��������ȴ�����Ҽǵ���һ�죬��������������������Ϸ��ĵ�ƽ�ߣ����������﾿�������������Ĺ��¡�"<<endl<<endl;
        getch(); system("cls");
        cout<<"��֪�����䣬Ϧ����ȫȻ����Զ����ɽ�����ǳ���ʼ��ĺ����˸���ҵ�ת��ͷ�����и�ȥ��"<<endl<<endl;
        cout<<"��ʱ�ļ�����Ȼģ����������λ�������ĳ���ȴ�������������������ͷ������֮����Ҳ�Ŵ��ڲ�����������ϵ���̸���Ͼ������ܽ�������ϡ�����䣬�����Ƕ��Ͼ���������У����η�壬��򲻽⣬�ֻ�������Щ����������һ�����Ҳ�׽�����ʹ����ף��������������ڱտڲ��ԣ���ʹ��Ψ�е�����ʱ����Ҳ����ֹ�ڸ����Һ͵ܵ������ǲ���֮�أ��ƺ�������δ֪��Σ�ա�"<<endl<<endl;
        cout<<"ƽԭ��㣬������ȴӿ���˼�����ꡣ����Դ����������һֱǱ�ص�һ���Σ�һ���嶯��һ������������������������������̽������ð�����������죬����������ҳ���֮ʱ���ڴﵽ�˶��壬���ָо�����Ҫ���ҵ������������"<<endl<<endl;
        getch();
        cout<<"�Ҿ���̤��ȥ���Ͼ���̽��֮�á�"<<endl<<endl<<endl<<endl<<endl;
        getch(); system("pause"); system("cls");
        system("cls");
        cout<<"��1��"<<endl<<endl<<endl;
        getch();
        system("cls");
        PlaySound("ǿ������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"������������ù������ҾͿ��Է����ȥ����"<<endl<<endl;//���� ǿ������
        getch();
        cout<<"�����뵽���ǣ�·;��һ������������������û�뵽�����ڿ�Խ��Ĭ·˹�ӵĽ�����Сʱ�󣬾���һ���ֳ�ذ�׵��������ӵ�������խ��ɽ·�ϡ�"<<endl<<endl;
        getch();
        cout<<"��˹�ɣ�����ƣ���Ҫʲô���Զ���˵��������ܰ�������һ���ᾡ����æ���㲻����������"<<endl<<endl;
        Sleep(1000);
        cout<<"ǿ���������ڸ�Ц����������˵������Ҫ������ң���Ͽ�������Ұɣ���Ȼ�ͱ��������·��ȥ����"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ������Ҷ��Һ���Ҫ����"<<endl<<endl;
        Sleep(1000);
        cout<<"ǿ����������Ҳ����Ҫ���ϻ���˵�����ù�������Ȼ���������⵶�ӷ治��������"<<endl<<endl<<endl;
        getch();
        Enemy robber={90,90,4,1};
        cout<<"F��          ��ʼս��"<<endl;
        cout<<"R��          �����ֿ�"<<endl;
        gettwo(ch,'f','r');
        if(ch=='f')
        {
            robfight=1;
            system("cls");
            fight(kasmon,robber,1);
        }
        else if(ch=='r')
        {
            bp.coins-=ROB;
            do{
            system("cls");
            PlaySound("�հ�.wav",NULL,SND_FILENAME | SND_ASYNC);
            cout<<"����ǿ�����е�������������˵ֿ�������������"<<ROB<<"ö��ҡ�"<<endl<<endl;
            getch();
            cout<<"ǿ����С�ӣ�������ô�Եķ��Ͼ�������㣬������������ˣ�"<<endl<<endl<<endl;
            getch();
            cout<<"B��           �鿴����"<<endl;
            cout<<"����          ����"<<endl;
            ch=getch();
            if(ch=='b')
            {
                    system("cls");
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch,27);
            }
            }while(ch=='b');
        }
        daycost();
        cout<<"��2��"<<endl<<endl<<endl;
        getch();
        system("cls");
        cout<<"��˹�ɣ�Ҳ��ǰһ��ľ���ֻ��һ����ʼ��ȥ�ϱߵ�·����һ����˳��"<<endl<<endl;
        getch();
        cout<<"���˵��ǣ�����һ���·�̣����Ѿ���������˼�ǽ�������һ���̵���ڲ�Զ����"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("����˼�ǽ������˼��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"����˼�ǽ� �����̵�"<<endl<<endl<<endl;//���� ����˼�ǽ������˼��
        getch();
        cout<<"��������ࡣ��п������ˣ���ӭ�����ҵ��̵ꡣ������ȥ���������ߣ�û��ɣ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ����ǵģ��Ҵӱ����İ�Ĭ·˹���������ġ���"<<endl<<endl;
        Sleep(1000);
        if(kasmon.health<100)
        {
            cout<<"��������������������ȥ����ոպͱ��˴���ܣ��������𣿡�"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�������û�£�ˤ��һ�Ӷ��ѡ���"<<endl<<endl;
            Sleep(1000);
        }
        cout<<"��������������ô˵����Ȼ�����������е����壬�����ﻹ���е����õĶ����ġ����˵Ļ��б�����Ҫ�Ǿ����䣬���Ҿƿ���ů������������һЩ���⡭���������ɣ���"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"����˼�ǽ� �����̵�"<<endl<<endl<<endl;
            cout<<"��پ�"<<endl;
            cout<<"�۸�"<<MARTON_C<<"���   M������"<<endl;
            cout<<"�������ׯ԰���Ҿƣ����������������е�������ʿ�ᰮ�ľ�Ʒ�����ú󹥻�������"
            <<MARTON_A<<"���������˿ɻָ�"<<MARTON_H<<"����ֵ��"<<endl<<endl;
            cout<<"����"<<endl;
            cout<<"�۸�"<<BANDAGE_C<<"���   D������"<<endl;
            cout<<"������������Ʒ��ʹ�ú�ɻָ�"<<BANDAGE_H<<"����ֵ��"<<endl<<endl;
            cout<<"������"<<endl;
            cout<<"�۸�"<<SANDWICH_C<<"���   S������"<<endl;
            cout<<"��Ȼ�����㳣�Ե�ʳ���Ҳ����б����;�����İ�װֽʹ������Я����"<<endl<<endl;
            cout<<"���ϱ�ʯ����"<<endl;
            cout<<"�۸�"<<FAKEPURPLEGEMNECKLACE_C<<"���   F������"<<endl;
            cout<<"�����׿����ǲ����������ϱ�ʯ�����Ⲣ���������е��˶�����û��Ȥ��"<<endl<<endl<<endl;
            cout<<"�鿴����          B  "<<endl;
            cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 's':
                {
                    if(!cck(SANDWICH_C)) break;
                    bp.sandwich+=1;
                    bp.coins-=SANDWICH_C;
                    cout<<"�ѹ���  ������x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'm':
                {
                    if(!cck(MARTON_C)) break;
                    bp.marton+=1;
                    bp.coins-=MARTON_C;
                    cout<<"�ѹ���  ��پ�x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"�ѹ���  ����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'f':
                {
                    if(!cck(FAKEPURPLEGEMNECKLACE_C)) break;
                    bp.fakepurplenecklace+=1;
                    bp.coins-=FAKEPURPLEGEMNECKLACE_C;
                    cout<<"�ѹ���  ���ϱ�ʯ����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='s' || ch2=='m' || ch2=='d' || ch2=='f' || ch2=='b');
        system("cls");
        cout<<"����˼�ǽ� �����õ�"<<endl<<endl<<endl;
        getch();
        cout<<"��������һ��λ�ڳǽ����õꡣ��Ȼ����ķ��俴��ȥ������ô�ɾ�����ȴ�ܱ�û��Ҫ�á���Ժ����˩��������ص��˷��䡣"<<endl<<endl;
        getch();
        cout<<"��˹�ɣ���������������ҹ�ɣ���"<<endl<<endl;
        getch();
        PlaySound("ҹ��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        do{
            system("cls");
            cout<<"����˼�ǽ� �����õ�"<<endl<<endl<<endl;//���� ҹ��
            cout<<"�˴�������֮�ء������������ʹ������̵����������Ʒ��"
            <<endl<<endl<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','q','s');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        system("cls");
        cout<<"��һҹ��˯�úܰ��ȣ�����ҹ��ĳ������⣬ֻ���¹�͸�������������顣"<<endl<<endl;
        system("pause");
        daycost();
        cout<<"��3��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("����˼�ǽ������˼��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"����˼�� С�ƹ�"<<endl<<endl<<endl;//���� ����˼�ǽ������˼��
        getch();
        cout<<"һ��װ��ȽϾ��µ�С�ƹݣ�̤�������������ĵõ�һ���ķ��ɡ�"<<endl<<endl;
        getch();
        cout<<"�ƹ��ϰ壺�ˣ��ܱ�Ǹ����ʣ�ľ�û�����ˣ������м������ǵ��������ʹ��һ�٣��¾ƻ�û���ü��ϼܡ���Ҫ����ʲô��"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"����˼�� С�ƹ�"<<endl<<endl<<endl;
            cout<<"��پ�"<<endl;
            cout<<"�۸�"<<MARTON_C<<"���   M������"<<endl;
            cout<<"�������ׯ԰���Ҿƣ����������������е�������ʿ�ᰮ�ľ�Ʒ�����ú󹥻�������"
            <<MARTON_A<<"���������˿ɻָ�"<<MARTON_H<<"����ֵ��"<<endl<<endl;
            cout<<"���ʾ�"<<endl;
            cout<<"�۸�"<<LEMONA_C<<"���   L������"<<endl;
            cout<<"��֪����ʿ�ķ����������Ʊ�����ˮ��ƾ������һ����ƶ��ɵĶ������ơ����ú󹥻�������"
            <<LEMONA_A<<"���������˿ɻָ�"<<LEMONA_H<<"����ֵ��"<<endl<<endl;
            cout<<"��³Ү����"<<endl;
            cout<<"�۸�"<<BRUJE_C<<"���   R������"<<endl;
            cout<<"�����ϡ�еĲ�³Ү�����Ǹ߹�����ص����������ĵ��Ʒ���ֻ����������֪�������ú󹥻�������"
            <<BRUJE_A<<"���������˿ɻָ�"<<BRUJE_H<<"����ֵ��"<<endl<<endl<<endl;
            cout<<"�鿴����          B  "<<endl;
            cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'm':
                {
                    if(!cck(MARTON_C)) break;
                    bp.marton+=1;
                    bp.coins-=MARTON_C;
                    cout<<"�ѹ���  ��پ�x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"�ѹ���  ���ʾ�x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'r':
                {
                    if(!cck(BRUJE_C)) break;
                    bp.bruje+=1;
                    bp.coins-=BRUJE_C;
                    cout<<"�ѹ���  ��³Ү����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='m' || ch2=='l' || ch2=='r' || ch2=='b');
        cout<<"�ƹ��ϰ壺����Ӧ�ò���������˰ɣ������Ҳµ�û���ѵ��������й�͡�Ҫ֪��������ƫƧƶ��ĳ���ɲ���Ĭ·˹����������ʤ��һ���������ˡ��ͽ����µ�˹�ɣ�����˼�������Ǽ���û��һ������ʶ�ң������ÿ������ʲô����Ҳ������������ˣ����������һ��Ǻ�İ���ġ������ˣ��ɷ�֪������е�����Ŀ�ĵ��أ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�����Ҫ���Ͼ�ȥ����"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹��������س�Ĭ��"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�����Ϊʲô��ô���ȣ���"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹��������ֻ�ǡ�����ȷ�е㲻�����š�Ҫ֪����������һ����ͬѰ���ĵط���ȥ���������û��һ������������"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ��������Ͼ����˽⣿��"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹����Ҳ�㲻��̫���˽⣬����֪���Ķ��ǴӾƹݵĳ��������������ģ������ǽ����������һ��������˵�ĵط�����������ź�ɱ����Ҳ��֪����������ȥ������Ϊ��ʲô�£���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�������֪�����﾿����������һ���ط��������ﶼ������ʲô�¡���"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹��������������������һ��Ҫ������ġ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ����һ�ģ�лл������"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹���������������ˣ��ҿ�������Ҳû��ʲô���ֵ��������������ɲ��У����֪����ȥ�ϱߵ�·���Ǻ����յġ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ���������˵�öԣ�������������Ӧ���и��һ��Ӧ��ǿ��֮��ġ���"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹������Ȼ��������ʮ���Ƽ��㵽���в��������꣬�ϰ����п��أ�����Ҳ�����ˣ�����Ķ�����ȫ���˹��ϵĸ����������������������з���Ļ��ף�Ҫ��Ҳ���������"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�������������������͹�ȥ��������Ҫ��л����ָ������"<<endl<<endl;
        Sleep(1000);
        cout<<"�µ�˹����û�£����濲�������ͣ����´ε�������ȾƵö�����Ǯ����������"<<endl<<endl;
        system("pause");
        daycost();
        cout<<"��4��"<<endl<<endl;
        getch();
        system("cls");
        cout<<"����˼�� ������"<<endl<<endl<<endl;
        getch();
        cout<<"���أ�����ð���С���ӣ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�����ã���������˳�ֵ��������Ǿƹ��ϰ��µ�˹�Ƽ���������ġ���"<<endl<<endl;
        Sleep(1000);
        cout<<"���أ����������µ�˹���ϼһ��������ͦ����˼�ģ�������ô˵���������Եط��ˣ����������ͻ��׾�ȫ�����ұ�֤��������ʹ������ʱͻȻ�ϵ������������ϲ���ļ�����"<<endl<<endl;
        getch();
        int coinback=0;
        do{
            system("cls");
            cout<<"����˼�� ������"<<endl<<endl<<endl;
            cout<<"��������"<<endl<<endl;
            cout<<"�̽�"<<endl;
            cout<<"�۸�"<<DAGGER_C<<"���   D������"<<endl;
            cout<<"�����ͨ�Ķ̽�����˵�Ǵ̿͵�ϲ��֮�װ���󹥻�������"<<DAGGER_A<<"��"<<endl<<endl;
            cout<<"�������"<<endl;
            cout<<"�۸�"<<STEELSTICK_C<<"���   S������"<<endl;
            cout<<"���о�ݵ�����������ȥ������С��װ���󹥻�������"<<STEELSTICK_A<<"��"<<endl<<endl<<endl;
            cout<<"�����ס�"<<endl<<endl;
            cout<<"ͨ�ÿ���"<<endl;
            cout<<"�۸�"<<GENERAARMOR_C<<"���   G������"<<endl;
            cout<<"����Զ�����ų��沽����ͨ�ÿ��ף��ܹ���ս����Ϊ�����ṩ��Ч�ķ�����װ�������������"
            <<GENERAARMOR_A<<"��"<<endl<<endl;
            cout<<"�����"<<endl;
            cout<<"�۸�"<<OCEANARMOR_C<<"���   O������"<<endl;
            cout<<"��Ϊһ�ֲ�������������ף����׵ĵ�����Դ�������һ�����������ߺ�ʵ���߳��������ڹ���˹���帽����װ�������������"
            <<OCEANARMOR_A<<"��"<<endl<<endl<<endl;
            cout<<"�鿴����          B  "<<endl;
            cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'd':
                {
                    if(!cck(DAGGER_C)) break;
                    if(bp.weapon=="�̽�")
                    {
                        cout<<"����ӵ�д�����"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.attack+=DAGGER_A;
                    bp.weapon="�̽�";
                    bp.weapon_add=DAGGER_A;
                    bp.coins-=DAGGER_C;
                    coinback+=DAGGER_C;
                    cout<<"�ѹ���װ��   �̽�"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 's':
                {
                    if(!cck(STEELSTICK_C)) break;
                    if(bp.weapon=="�������")
                    {
                        cout<<"����ӵ�д�����"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.attack+=STEELSTICK_A;
                    bp.weapon="�������";
                    bp.weapon_add=STEELSTICK_A;
                    bp.coins-=STEELSTICK_C;
                    coinback+=STEELSTICK_C;
                    cout<<"�ѹ���װ��   �������"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'g':
                {
                    if(!cck(GENERAARMOR_C)) break;
                    if(bp.armor=="ͨ�ÿ���")
                    {
                        cout<<"����ӵ�д˷���"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=GENERAARMOR_A;
                    bp.armor="ͨ�ÿ���";
                    bp.armor_add=GENERAARMOR_A;
                    bp.coins-=GENERAARMOR_C;
                    coinback+=GENERAARMOR_C;
                    cout<<"�ѹ���װ��   ͨ�ÿ���"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'o':
                {
                    if(!cck(OCEANARMOR_C)) break;
                    if(bp.armor=="�����")
                    {
                        cout<<"����ӵ�д˷���"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=OCEANARMOR_A;
                    bp.armor="�����";
                    bp.armor_add=OCEANARMOR_A;
                    bp.coins-=OCEANARMOR_C;
                    coinback+=OCEANARMOR_C;
                    cout<<"�ѹ���װ��   �����"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
          }while(ch2=='d' || ch2=='s' || ch2=='g' || ch2=='o' || ch2=='b');
        system("cls");
        if(bp.weapon!="ͽ��")
        {
            cout<<"[��ʾ] ���������¼��ܣ���������"<<endl<<endl;
            cout<<"���ܽ��ܣ�ʹ�ú󹥻�������20%��ʹ�ô���3�Ρ�"<<endl<<endl;
            kasmon.skill_1=1;
            getch();
            system("cls");
            cout<<"����˼�� ������"<<endl<<endl<<endl;
            cout<<"���أ���С���Ӳ����ż��뿪��������и����£���֪�����ܲ��ܰ������æ�����������ң��Ҿͷ�����һ����ι��ﻨ���Ľ�ҡ���ô������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�������ȥ���������������£���ʲô���£���"<<endl<<endl;
            Sleep(1000);
            cout<<"���أ����������ġ���������Ҷ��Ӹպó��˳�ȥ�μ�����Զ�����Ź�������ѡ�Σ����ѡ����Ҳ����ʵ��������һ����Ը���������ڵ��⼸�����û�������ҵ���ɭ��������ˡ������ҵ��ǲ���Ҫ������ȥ���ԣ�ֻ������أ�������Ұ��Ģ�����ųԣ�����Ϊ���ﻹҪ�к����˵Ĺ�ϵ�벻����"
            <<"���Է����㵽�Ǳ��ߵ�ɭ�������Ҳ�һ���������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�����򵥣������Ͼ�ȥ����"<<endl<<endl;
            Sleep(1000);
            cout<<"���أ����������һ��Ҫע�⣬ɭ���ﲻֻ��Ģ������������ӣ�����Щ��Σ�յĶ���������ܣ��ؼ�ʱ������ܻ���Ҫ�����ǲ���һ�����㻹Ը��������æ�𣿡�"<<endl<<endl<<endl;
            Sleep(1000);
            cout<<"Y��          ����"<<endl;
            cout<<"N��          �ܾ�"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                cout<<"����˼�� ������"<<endl<<endl<<endl;
                cout<<"��˹�ɣ���֪���ˣ��һ�ע��ġ���"<<endl<<endl;
                Sleep(1000);
                cout<<"���أ��������Ǹ������С���ӣ�����һ��Ҫע�ⰲȫ����"<<endl<<endl;
                getch();
                system("cls");
                cout<<"��ɭ��"<<endl<<endl<<endl;
                getch();
                cout<<"��ܿ������˱�ɭ�֡��������������¶�ʪ��Ŀ���������Χ����������΢�������⴩͸�������ڲݵ��ϣ�������������ˬ�ие�Щ��ѹ�֡�"<<endl<<endl;
                getch();
                cout<<"����һЩ�д�׳���ɵ����·����˺ܶ�Ģ�����������Ƕ�װ���˱����С�"<<endl<<endl;
                getch();
                PlaySound("��ɭ�� ����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"Ȼ����������׼�������뿪ʱ����Զ��ȴ�����˵ͳ��Ľ�����"<<endl<<endl;//���� ��ɭ�� ����
                getch();
                cout<<"�����ٴ�̧ͷ��һֻ������������·�ϡ�"<<endl<<endl<<endl;
                getch();
                cout<<"�����������ս��..."<<endl<<endl;
                getch();
                system("cls");
                Enemy bear={110,110,18,3};
                fight(kasmon,bear);
                PlaySound("����˼�ǽ������˼��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                system("cls");
                cout<<"����˼�� ������"<<endl<<endl<<endl;
                getch();
                cout<<"���أ����������ơ�����Ȼ�ǹ����ʵ�Ģ����̫���ˣ�С���ӣ���Щ��Ҿͷ�������ɣ���"<<endl<<endl;
                getch();
                cout<<endl<<"[��ʾ] ������"<<(coinback/2)<<"��ң�����"<<bp.coins<<"���"<<endl<<endl;
                bp.coins+=(coinback/2);
            }
            else
            {
                cout<<"��˹�ɣ�����Ǹ�������һ�û���㹻������Ӧ����Щ�����ǣ��ҿ��ܰﲻ�������æ����"<<endl<<endl;
                Sleep(1000);
                cout<<"���أ���Ҳ��Ҳ�ã���ɭ��ȷʵ��Σ�գ���ôС���ӣ���ͼ����ó̰ɣ���"<<endl<<endl;
            }
        }
        getch();
        system("pause");
        daycost();
        PlaySound("�հ�.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"��5��"<<endl<<endl;//�˴�������
        getch();
        system("cls");
        cout<<"�뿪����˼��·��"<<endl<<endl<<endl;
        getch();
        cout<<"·�߿�ǽ�����ŵ�һ����ؤ���������ע�⣬ͬʱ����Ҳע�⵽���㣬���㻺��������"<<endl<<endl;
        getch();
        cout<<"��ؤ���������ˣ������ϻ��гԵ��������һЩ�ɣ��Һܶ�����"<<endl<<endl;
        if(bp.sandwich==0)
        {
            Sleep(1000);
            cout<<"��˹�ɣ�����������Ҳû��ʲô�Եġ�����"<<endl<<endl;
            Sleep(1000);
            cout<<"��ؤ���������ðɣ�ף�����ˡ���"<<endl<<endl;
            getch();
            cout<<"��ؤת���뿪�ˡ�"<<endl<<endl;
        }
        else
        {
            getch();
            cout<<"���������Լ����ϻ�����һ�������Ρ�"<<endl<<endl<<endl;
            Sleep(1000);
            cout<<endl<<"Y��          �������θ���ؤ"<<endl;
            cout<<"N��          �ܾ�"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                beggar=1;
                bp.sandwich-=1;
                cout<<"��ؤ��������̫лл���ˣ���"<<endl<<endl;
                getch();
                cout<<"��ؤ�ӹ������Σ���������������������κܿ�Ͳ�������Ӱ��"<<endl<<endl;
                getch();
                cout<<"��ؤ���������ˣ���л��������ʱͦ���˼�������"<<endl<<endl;
                Sleep(1000);
                cout<<"��˹�ɣ��������ﻹ�е��ң�Ҫ�����١�����"<<endl<<endl;
                Sleep(1000);
                cout<<"��ؤ���������ˣ��������鷳���ˣ���֪������ÿ���˶����Լ����Ѵ������Ľ��Ҳ����������;����Ӧ�����������аɣ����������������ǰɡ���"<<endl<<endl;
                Sleep(1000);
                cout<<"��˹�ɣ����ԣ���Ҫ���Ͼ�ȥ����"<<endl<<endl;
                Sleep(1000);
                cout<<"��ؤ�������ݵس�Ĭ��"<<endl<<endl;
                Sleep(1000);
                cout<<"��ؤ���������ˣ���ô��ʱ��Ҳû����ʩ���ң������Ҳ��������ǡ����Ǽ�Ȼ��˵��Ҫ���Ͼ�ȥ���������һ�㱨���Ȿ����װ�ڲ�������һ��ʱ���ˣ�������������ܰ�������������Ҫ�������ˣ����������ɡ���"<<endl<<endl;
                Sleep(1000);
                cout<<"��ؤת���뿪�ˡ�"<<endl<<endl<<endl;
                getch();
                cout<<"[��ʾ] ������1���鼮"<<endl<<endl;
                bp.book+=1;
            }
            else
            {
                cout<<"��˹�ɣ�����������Ҳû��ʲô�Եġ�����"<<endl<<endl;
                Sleep(1000);
                cout<<"��ؤ���������ðɣ�ף�����ˡ���"<<endl<<endl;
                getch();
                cout<<"��ؤת���뿪�ˡ�"<<endl<<endl;
            }
        }
        getch();
        system("cls");
        PlaySound("ҹ��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"�ű��õ�"<<endl<<endl<<endl;//���� ҹ��
        getch();
        cout<<"��ĺʱ�֣���������һ�������������ڿ�Խ�������ű�ǡ����һ���õ꣬�����������ҹ�ޡ�"<<endl<<endl;
        getch();
        cout<<"���õ���Ŀ���˵�����������ţ��Ϳ��Ե���һ���ȽϷ��ٵ�С��"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"�ű��õ�"<<endl<<endl<<endl;
            cout<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','s','q');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        daycost();
        cout<<"�������ļ�����㲻�ϸ�·����û��ʲô�ر���·�����"<<endl<<endl;
        getch();
        srand((unsigned int)time(NULL));
        int cost3;
        cost3=3*( rand()%11+10 );
        if((bp.coins-=cost3)>=0)
           {
               cout<<"���⼸����㻨����"<<cost3<<"��ҵ��ӷѣ���ʣ"<<bp.coins<<"��ҡ�"<<endl<<endl;
               system("pause");
               system("cls");
           }
        else
            {
                cout<<"���ź�����Ľ�Ҳ�����Ӧ�Խ��������г�����Ŀ������Ͼ�֮�õ��˽�����"<<endl<<endl;
                getch();
                exit(0);
            }
        system("cls");
        cout<<"��9��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"������"<<endl<<endl<<endl;//���� ������
        getch();
        cout<<"������ǰ�У�����һ����һ˿���ɵ���ͥ������������С���С�С���������������ȿ���˼�ǵ��˿���ȥҪ��һЩ�������ж���ʯ�̳ɵ�·�棬��ʽ�����ĵ��̺�̯����"<<endl<<endl;
        getch();
        cout<<"�ڻ��εĵ�·�Ϲ���һ���䣬������һ������סլ����������Щ¥װ�ޱ��һ�񣬺���֮ǰ������סլ��һ����"<<endl<<endl;
        getch();
        cout<<"���ڹ���֮ʱ������Ů�˵Ĳҽ�ȴ������Ķ��С�"<<endl<<endl;
        getch();
        cout<<"�����У�������������ʲôʱ�򣡡�"<<endl<<endl;
        Sleep(1000);
        cout<<"�����ǹ��ˣ���������"<<endl<<endl;
        Sleep(1000);
        cout<<"������������"<<endl<<endl;
        getch();
        cout<<"һ��ŮӶ���ŵ�Ů�����ڱ�����������װ�������Χ���м䣬����ȥ���ڱ�����Դ����㿪ʼ����Ҫ��Ҫ���ְ�æ��"<<endl<<endl<<endl;
        getch();
        cout<<"Y��          ����"<<endl;
        cout<<"N��          �뿪"<<endl<<endl;
        gettwo(ch,'y','n');
        system("cls");
        if(ch=='y')
        {
            maid=1;
            cout<<"��˹�ɣ���ͣ�£���"<<endl<<endl;
            getch();
            PlaySound("������ ����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"����ת��ͷ�������㡣"<<endl<<endl;
            getch();
            cout<<"���ɳ�Ա1����С�ӣ���**�������ģ��������Ĺ���ȥ����"<<endl<<endl;
            Sleep(1000);
            cout<<"���ɳ�Ա2������˵����֪��֪��������˭���㲻֪�����ǻ�����ģ���"<<endl<<endl;
            Sleep(1000);
            cout<<"���ɳ�Ա3����ʶ���Ͻ������뱻ͱ�Ļ��Ұ��㣡��"<<endl<<endl;
            Sleep(1000);
            cout<<"���ɳ�Ա1����������ô����������ѵ��ǵ��Ұ���ͱ������֪����ô���𣿡�"<<endl<<endl<<endl;
            getch();
            cout<<"�����������ս��..."<<endl<<endl;
            getch();
            Enemy gangster1={100,100,12,0};
            system("cls");
            fight(kasmon,gangster1,8);
            system("cls");
            cout<<"���ɳ�Ա2����û�뵽��**���е㱾�£�����**��ôŪ�㡭����"<<endl<<endl<<endl;//�˴����� ������ ����
            getch();
            cout<<"�����������ս��..."<<endl<<endl;
            getch();
            Enemy gangster2={100,100,15,0};
            system("cls");
            fight(kasmon,gangster2,8);
            system("cls");
             PlaySound("������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"����İ��ɳ�Ա��״�׷���ɢ��ֻ��ŮӶ��վ��ԭ�ء�"<<endl<<endl;
            getch();
            cout<<"ŮӶ�������ǡ���̫��л���ˣ����治֪����˵Щʲô������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���û���˾ͺã������Ǹ�ʲô�ģ���"<<endl<<endl;
            Sleep(1000);
            cout<<"ŮӶ���������ǵ��صİ��ɣ�����˵�޶���������ͨ�˼�������Ҳ������ʲô���Ͼ����ǵ������Ѿ����ᵽ����Ĺ����ˡ��Ҹոմ�һ�������ͥ��Լ����Ҽ���ȥ�����ǾͰ��Ҷ�����·�ϣ�Ȼ�󡭡���"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���������ô˵�������Ѿ���ȫ�ˣ��Ͳ�Ҫ�ٻ����ˡ�֮���ǵ�ע�Ⱑ����"<<endl<<endl;
            Sleep(1000);
            cout<<"ŮӶ���������ҵñ������ʲô����������һƿ�ƣ����Ҹմ�ԭ���ɻ�ĵط�͵�ģ�����Ҳ���Ⱦƣ�͵�ƾ����뱨��һ��֮ǰ�����۸��ҵ��Ǽ��ˡ�����ƻ��Ǹ���ɣ�����һЩǮ��Ҳ����͵�ģ�Ҳ����һ���ְɣ���"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ��������ǣ�лл��ĺ��⡣��"<<endl<<endl;
            Sleep(1000);
            cout<<"ŮӶ�����˵ز��˾�������϶��Ѿ������Ƕ����ˣ��Ժ������������С��Щ����Ҳ�øϿ�����ˣ��ټ��ˣ���"<<endl<<endl;
            bp.lemona+=1;
            bp.coins+=MAIDFEEDBACK;
            getch();
            cout<<endl<<"[��ʾ] ������1ƿ���ʾƺ�"<<MAIDFEEDBACK<<"�����"<<endl<<endl;
        }
        else
        {
            cout<<"Ϊ�˲������鷳�����ת��ͷ�������ȥ��"<<endl<<endl;
        }
        getch();
        system("cls");
        PlaySound("������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"��֪Ϊʲô����Щ���ɵĺ���סլ��Ҳ���ܴ������Ӿ����������ܡ�"<<endl<<endl;//���� ������
        getch();
        cout<<"���������Ź���һȦ��������������ҵ��˽�����ŵĵط���"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"������ �����õ�"<<endl<<endl;
            cout<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','q','s');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        daycost();
        cout<<"��10��"<<endl<<endl;
        getch();
        system("cls");
        cout<<"��һ�죬�����ȥ������̵꿴����"<<endl<<endl;
        getch();
        cout<<"��̤��һ���̵꣬���ϰ岢û�������˼�ǽ��Ǽҵ�һ��������к��㡣����Լ��ڻ�������ѡ��"<<endl<<endl;
        getch();
        system("cls");
        do{
            system("cls");
            cout<<"������ �̵�"<<endl<<endl<<endl;
            cout<<"���ʾ�"<<endl;
            cout<<"�۸�"<<LEMONA_C<<"���   L������"<<endl;
            cout<<"��֪����ʿ�ķ����������Ʊ�����ˮ��ƾ������һ����ƶ��ɵĶ������ơ����ú󹥻�������"
            <<LEMONA_A<<"���������˿ɻָ�"<<LEMONA_H<<"����ֵ��"<<endl<<endl;
            cout<<"����"<<endl;
            cout<<"�۸�"<<BANDAGE_C<<"���   D������"<<endl;
            cout<<"������������Ʒ��ʹ�ú�ɻָ�"<<BANDAGE_H<<"����ֵ��"<<endl<<endl;
            cout<<"ҩ��"<<endl;
            cout<<"�۸�"<<HERB_C<<"���   H������"<<endl;
            cout<<"����ҩ�ݲ���ƫƧ��Σ�յ�ɽ�أ��Ը�����������������������ã��������˴���Ч�����ٵػָ���ʹ�ú�ɻָ�"<<HERB_H<<"����ֵ��"<<endl<<endl<<endl;
            cout<<"�鿴����          B  "<<endl;
            cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"�ѹ���  ���ʾ�x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"�ѹ���  ����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'h':
                {
                    if(!cck(HERB_C)) break;
                    bp.herb+=1;
                    bp.coins-=HERB_C;
                    cout<<"�ѹ���  ҩ��x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='l' || ch2=='d' || ch2=='h' || ch2=='b');
        system("cls");
        cout<<"ҹĻ�ֿ�Ҫ�����ˡ���һ����û������ʲô�ر�����飬Ҳû�к�˭˵�����仰��ֻ�Ǿ���������Ȼ���ӷ�����������һ��ѹ�ֵķ�Χ��"<<endl<<endl;
        getch();
        system("pause");
        daycost();
         PlaySound("�հ�.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"��11��"<<endl<<endl;//�˴�������
        getch();
        system("cls");
        cout<<"��������򣬼������ϱ��н���"<<endl<<endl;
        getch();
        cout<<"������һ���ɣ������Ȥ�Ķ��������Դ�����õ���Ҳ���԰������Ȥ�Ķ��������ң���"<<endl<<endl;
        getch();
        cout<<"ߺ����ʹ��ͣ���˽Ų�����תͷ��ȥ��һ������ģ��������վ��·�ߵ�ʯͷ�����š��������߽���"<<endl<<endl;
        getch();
        cout<<"����ó���ߣ����٣�����ʲô����Ļ����������𣿡�"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�����������������Ķ�������"<<endl<<endl;
        Sleep(1000);
        cout<<"����ó���ߣ������ʲô�������ó���̸̸������ư���ʳƷ��ʲô�ģ�����������Ҫ����Щ�����Ļ�������õ��ܸߵļ�Ǯ����֪���ģ�����Ҫ�ǰ�����Щ������Ǯ�����ǣ��⸽���кܶ��������ˡ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ��������������ǻ������˰ɡ���"<<endl<<endl;
        Sleep(1000);
        cout<<"����ó���ߣ�������Ҳ��ȫ������ۣ�����ϡΪ���������ϣ���õ�һ���������ҵ�СŮ�����ĵĶ��������������Ҿ�Ҳ�����ˣ�����������������Ʒ���ҵĻ��ҿ��ܻ����ܸߵļۡ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�������Ů�����ĵĶ�������"<<endl<<endl;
        if(bp.fakepurplenecklace>0)
        {
            getch();
            cout<<"���뵽�������������ϱ�ʯ������Ҳ�������СŮ�����ġ��Ƿ������������ó���ߣ�"<<endl<<endl<<endl;
            cout<<"Y��          ����"<<endl;
            cout<<"N��          ����"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                cout<<"����ó���ߣ����ۡ����ⶫ��������Ů����˵�����Ǻö���������Ư������ɫ��ʯ���������ұ�֤���ܴ��ڲ����Ϻþã���"<<endl<<endl;
                Sleep(1000);
                cout<<"����ó���ߣ����ܺã��һ��úܶ������㹺��������������"<<endl<<endl;
                bp.fakepurplenecklace-=1;
                bp.coins+=FAKEPURPLEGEMNECKLACE_S;
                getch();
                cout<<endl<<"[��ʾ] ��������1�����ϱ�ʯ�����������"<<FAKEPURPLEGEMNECKLACE_S<<"�����"<<endl<<endl;
            }
            else
            {
                Sleep(1000);
                cout<<"��˹�ɣ�������������û��ʲôֵ�����Ķ����ˡ���"<<endl<<endl;
                Sleep(1000);
                cout<<"����ó���ߣ����ðɣ�ף��������һ�죡��"<<endl<<endl;
            }
        }
        else
        {
            Sleep(1000);
            cout<<"��˹�ɣ�������������û��ʲôֵ�����Ķ����ˡ���"<<endl<<endl;
            Sleep(1000);
            cout<<"����ó���ߣ������ðɣ�ף��������һ�죡"<<endl<<endl;
        }
        getch();
        system("pause");
        daycost();
        cout<<"��12��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"���ȡ���������������"<<endl<<endl;//���� ������
        getch();
        cout<<"����������������խ����·��ʱ���������˴�ǰ��սǴ������ĺ�������������ٶȣ�ע���������ڹսǴ���"<<endl<<endl;
        getch();
        cout<<"һ�����������˴ӹս����������ұ�������Ѫ����һ�߷����ұ�һ��ʹ���ܶ��š����������¶���·�������ǵ���ɫ��"<<endl<<endl;
        getch();
        cout<<"�����������б���������ܽ�����������"<<endl<<endl;
        getch();
        if(bp.bandage>0)
        {
            cout<<endl<<"Y��          ��������"<<endl;
            cout<<"N��          �ܾ�"<<endl<<endl;
            gettwo(ch,'y','n');
            if(ch=='y')
            {
                banout=1;
                system("cls");
                cout<<"[��ʾ] �������1������"<<endl<<endl;
                bp.bandage-=1;
                getch();
                cout<<"��Э���Է�ֹѪ���ñ�������������"<<endl<<endl;
                getch();
                cout<<"��˹�ɣ�����ô���˳���������"<<endl<<endl;
                Sleep(1000);
                cout<<"�������ӣ���������ˣ���������Ū�ģ���"<<endl<<endl;
                Sleep(1000);
                cout<<"��˹�ɣ��������ż����˿��Ѿ�������ˣ�������˵����"<<endl<<endl;
                Sleep(1000);
                cout<<"�������ӣ���������������ƽʱ���������ǿ������ܱ��������ǡ�����������ʱ�����嵽����ȥ����������û�ܰ����½���ã��ⲻ�������������ˣ�һ��Ʊ��ֱ�ӳ嵽�Ҽң�һ���Ҽ�ûʲô�����ģ���������������֡���ƴ�����������Ǿ�����׷���ҿ��������������ܵ���ȫ�ĵط��ˣ����ڹ������ǲ�����׷���ˡ�����"<<endl<<endl;
                Sleep(1000);
                cout<<"��˹�ɣ������ǻ쵰����"<<endl<<endl;
                Sleep(1000);
                cout<<"�������ӣ����������������ɻ�ɣ�һ���һ��ûؼ�ȥ�������Ǹ��һ����Ķ�����ʰ�ɾ�����������ô����ϣ��������û�£���"<<endl<<endl;
            }
            else
            {
                cout<<"��˹�ɣ�����Ǹ��������û�С�����"<<endl<<endl;
                getch();
                cout<<"�������������˴��Ҵ��뿪�ˡ�"<<endl<<endl;
            }
        }
        else
        {
            cout<<"��˹�ɣ�����Ǹ��������û�С�����"<<endl<<endl;
            getch();
            cout<<"�������������˴��Ҵ��뿪�ˡ�"<<endl<<endl;
        }
        getch();
        system("cls");
        cout<<"ҹɫԽ��Խ�����������·��·���������Ǹ��������Ӹ��������˺����ӡ��"<<endl<<endl;
        getch();
        cout<<"���ҵ�һ�ҽ����õ꣬�����������������ҹ��"<<endl<<endl;
        getch();
        if(banout==1)
        {
            cout<<"��˹�ɣ��������򡭡�������ʲô����һ���ط��أ���"<<endl<<endl;
            getch();
        }
        system("pause");
        daycost();
        cout<<"��13��"<<endl<<endl;
        getch();
        system("cls");
        cout<<"������"<<endl<<endl<<endl;
        getch();
        cout<<"��ǰ��������������ͬ��ӳ�������ģ���һ����������ɪ��С��"<<endl<<endl;
        getch();
        cout<<"�����ӿ��ٶȣ��������һ����С���д��ж�����ֱ������һ�����У����̲Ŷ��������������ڼ�����Χ��һ��ȴ������Χ�ڼ��е�̯λǰ������Χ��ǽ�ԣ�ͬʱ�������۷׷ס������������ע�⣬������ǰȥ̽����"<<endl<<endl;
        getch();
        cout<<"�����������������Ѿ�����������ô��ʱ�䣬�������ܵ�������ȴʲôҲ�ܲ��ˣ��ѵ���Ҫһֱ������ȥ����ʱ�����������Լ���ѡ���ˣ���"<<endl<<endl;
        getch();
        cout<<"�㷢��һ��ǿ׳������������վ��һ�ߣ��õ���ʮ��ĺ������������ǡ�"<<endl<<endl;
        getch();
        cout<<"����������Ѳ�߶ӣ��ȿ�������ˮ�����֮�аɣ�ֻҪ�������˵����κ͵��������벻Ҫ���Ӳ��ܣ��޶����ԣ���"<<endl<<endl;
        getch();
        cout<<"���֪����������Χ��һ����ʾ����ʾ�Ϻ����������е������׳�����Ӽ�������Ѳ�߶ӣ��ֿ�ʱ������������������ˡ�"<<endl<<endl;
        getch();
        cout<<"��Ҫ����ģ��������վ�������ֵ������Աߣ���"<<endl<<endl;
        getch();
        cout<<"��������߿�ȥ��ȴ���ִ�ʱ�������ֱ�ֻ��ʮ������׳�����ӡ�"<<endl<<endl;
        getch();
        cout<<"��������֪��֪���������������������ˣ���Ȼ��ʼ������֮�£������ɾ�Ҫ�ҵ����ˣ���"<<endl<<endl;
        Sleep(1000);
        cout<<"���ҵ�Ȼ��˵�ˣ�������ʲô�취�����������ܳ�ͷ�ľ���ôʮ�����ˣ���"<<endl<<endl;
        getch();
        cout<<"������Ⱥ�д����ĶԻ����Ǹ��������ӵ��������������ǰ������"<<endl<<endl;
        getch();
        cout<<"�������������������Ļ��������޷��Ը����ǵģ�����û����Ҫ���룿��"<<endl<<endl;
        getch();
        cout<<"���ź����߽�����üͷ��һ��������������ʹ�㿪ʼ��������������Ŀ�úͶ��ŵ�һ�ж��������˼���Ѳ�߶ӵ���ͷ������Ͼ������ǿ�������ˡ�"<<endl<<endl;
        getch();
        cout<<endl<<"F��          ��������Ѳ�߶�"<<endl;
        cout<<"N��          ������"<<endl<<endl;
        gettwo(ch,'f','n');
        system("cls");
        if(ch=='f')
        {
            teamfight=1;
            cout<<"��˹�ɣ������Ҽ��룡��"<<endl<<endl;
            getch();
            cout<<"����Ŀ��֮�£�����������ߵ��Ҳ࣬�뿨�������׳�����Ӳ���վ����һ�����㾪ϲ���ǣ���ľٶ��ƺ������˸�����ʵ���ѡ����Ѳ�߶ӣ������أ�վ�������Ե���Խ��Խ�ࡣ"<<endl<<endl;
            getch();
            cout<<"�����ߣ����Ǻã��������Ǿ������������������������Щ��ʿ������ս������Щ���ϳ����ǵļ�԰����"<<endl<<endl;
            getch();
            cout<<"����������"<<endl<<endl;
            getch();
            system("cls");
            cout<<"������ սǰ������"<<endl<<endl<<endl;
            getch();
            cout<<"���磬�������һͬ�����������ߵ�һ���յأ���������Ϊսǰ��������ѵ��������ս�����ܲ����۶Ը����ʱ��ս����"<<endl<<endl;
            getch();
            cout<<"ֵ��һ����ǣ�Ѳ�߶ӵ�����Ϊ�����˶�����������������õ�����һ�������⼣�������������䵶��"<<endl<<endl;
            getch();
            cout<<endl<<"[��ʾ] ��õ���һ���䵶"<<endl<<endl;
            getch();
            if(bp.weapon=="ͽ��")
                kasmon.attack+=MACHETE_A;
            else if(bp.weapon=="�̽�")
                kasmon.attack=kasmon.attack-DAGGER_A+MACHETE_A;
            else
                kasmon.attack=kasmon.attack-STEELSTICK_A+MACHETE_A;
            bp.weapon_add=MACHETE_A;
            bp.weapon="�䵶";
            cout<<"Ϧ����������Զ����ɽ�У�����ֱ�����һ˿���Ӳ���������ʧʱ���������������Ϥ��������䵶���ڲ������������µ�ս�����ܣ����������ս���е�ʮ�ּ�����"<<endl<<endl;
            getch();
            system("cls");
            cout<<"[��ʾ] ��ѧ�����¼��ܣ����� �硿"<<endl<<endl;
            cout<<"���ܽ��ܣ���������40%�ļ��ʴ��3������ͨ�������˺�������60%�ļ��ʽ������ͨ����80%���˺���ʹ�ô���"<<SKILL3PP<<"�Ρ�"<<endl<<endl;
            kasmon.skill_3=1;
            getch();
            system("cls");
            cout<<"������ ���ķ����̵�"<<endl<<endl<<endl;
            getch();
            cout<<"����Ϊ������������õ�Ͷ��ս�������뼸��ͬ�ӵ��ֵ�һͬ�������������ĵķ����̵꣬������˵�������п���˼�ǵ���������û�еĶ�����"<<endl<<endl;
            getch();
            do{

                system("cls");
                cout<<"������ ���ķ����̵�"<<endl<<endl<<endl;
                cout<<"ͨ�ÿ���"<<endl;
                cout<<"�۸�"<<GENERAARMOR_C<<"���   G������"<<endl;
                cout<<"����Զ�����ų��沽����ͨ�ÿ��ף��ܹ���ս����Ϊ�����ṩ��Ч�ķ�����װ�������������"
                <<GENERAARMOR_A<<"��"<<endl<<endl;
                cout<<"��˹������"<<endl;
                cout<<"�۸�"<<LANSTONARMOR_C<<"���   L������"<<endl;
                cout<<"������Զ��Ľ�����˹����ƣ���һ������׸�����ء�װ�������������"
                <<LANSTONARMOR_A<<"��"<<endl<<endl;
                cout<<"ʮ�ּ�"<<endl;
                cout<<"�۸�"<<CROSSARMOR_C<<"���   C������"<<endl;
                cout<<"��������ͷ���ϵ�ʮ��ͼ��������װ�����ı��䣬�ʺ���ǿ��׳���˴��š�װ�������������"
                <<CROSSARMOR_A<<"��"<<endl<<endl<<endl;
                cout<<"�鿴����          B  "<<endl;
                cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
                ch2=getch();
                system("cls");
                switch(ch2)
                {
                case 'g':
                    {
                        if(!cck(GENERAARMOR_C)) break;
                        if(bp.armor=="ͨ�ÿ���")
                        {
                            cout<<"����ӵ�д˻���"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=GENERAARMOR_A;
                        bp.armor="ͨ�ÿ���";
                        bp.armor_add=GENERAARMOR_A;
                        bp.coins-=GENERAARMOR_C;
                        cout<<"�ѹ���װ��   ͨ�ÿ���"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'l':
                    {
                        if(!cck(LANSTONARMOR_C)) break;
                        if(bp.armor=="��˹������")
                        {
                            cout<<"����ӵ�д˻���"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=LANSTONARMOR_A;
                        bp.armor="��˹������";
                        bp.armor_add=LANSTONARMOR_A;
                        bp.coins-=LANSTONARMOR_C;
                        cout<<"�ѹ���װ��   ��˹������"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'c':
                    {
                        if(!cck(CROSSARMOR_C)) break;
                        if(bp.armor=="ʮ�ּ�")
                        {
                            cout<<"����ӵ�д˻���"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=CROSSARMOR_A;
                        bp.armor="ʮ�ּ�";
                        bp.armor_add=CROSSARMOR_A;
                        bp.coins-=CROSSARMOR_C;
                        cout<<"�ѹ���װ��   ʮ�ּ�"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'b':
                    {
                        bp.show();
                        cout<<"esc          ����"<<endl;
                        getone(ch3,27);
                        break;
                    }
                default:;
                }
            }while(ch2=='g' || ch2=='l' || ch2=='c' || ch2=='b');
        }
        else
        {
            teamfight=0;
            cout<<"������û���ߵ������ߵ������ԣ�û�м���Ѳ�߶ӵĶ��顣Ҳ�����ǶԵ�ѡ�������ף��Լ����յ�Ŀ����Ȼ���Ͼ���"<<endl<<endl;
            getch();
        }
        system("cls");
        PlaySound("ҹ��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"ҹĻʱ�֣����ҵ���һ���򱱵��ƾ��ùݣ����������Ҫ�������ҹ�ˡ�"<<endl<<endl;//���� ҹ��
        getch();
        system("cls");
        do{
            system("cls");
            cout<<"��������ƾ��ù�"<<endl<<endl;
            cout<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','q','s');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        daycost();
        cout<<"��14��"<<endl<<endl;
        getch();
        system("cls");
        if(teamfight==1)
        {
            PlaySound("�������������� ��ˣ������ţ�.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"��������"<<endl<<endl<<endl;//���� �������������� ���
            getch();
            cout<<"�����Ĳ��֮�£���������������֮�ϣ�����Ѳ�߶ӵ�ȫ���Ա��ɽ�����ϡ�"<<endl<<endl;
            getch();
            cout<<"Ѳ�߶����䣺���ֵ��ǣ����죬������Щ�����ǹ�����ʱ��׼���ú����Ǵ��һ�����𣿡�"<<endl<<endl;
            Sleep(1000);
            cout<<"���ߺ�����"<<endl<<endl;
            Sleep(1000);
            cout<<"�����죬��Щ�쵰��һ�������ð�Ѫ���ڿ��������������"<<endl<<endl;
            Sleep(1000);
            cout<<"������ɽ���£���"<<endl<<endl;
            getch();
            cout<<"��˳��ɽ���¿�ȥ��ֻ��һ�������������ǳ������������ࡣ"<<endl<<endl;
            getch();
            cout<<"Ѳ�߶����䣺����Щ������˵��ȷ��ˣ�����һ��֪������������ѡ���������ǵ��ˡ�������ʿ�ǣ���ס��������Ĳ���������Ž�����������Ӧ���Լ������ĵ��ˣ�սʤ������ȥ���������ˣ���"<<endl<<endl;
            getch();
            cout<<"�����۸ߺ������ܳ�����ս�⣬���Ѫ���˿��Ѿ����ţ�׼����Ҫ����˾�һ��ս����������һ�룬����ȷ����Ѿ������嵽����ǰ������һ�����ǳ��������������������ӭ����ȥ����Ҳ�������⡭��"<<endl<<endl;
            getch();
            cout<<endl<<"�����������ս��..."<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegangpioneer={110,22,3};
            fight(kasmon,horsegangpioneer,9);
            cout<<"����������"<<endl<<endl;
            getch();
            cout<<"����ȷ��Ѿ�������ȫ�����𣬴��ʿ�����ǣ�����������˷���Ȼ��û��ã���ѵ�������������ɽ���¡�"<<endl<<endl;
            getch();
            cout<<"Ѳ�߶����䣺����ʿ�ǣ����ǵ�ս���Ÿոտ�ʼ����Щ�쵰�������ǵ��������ս��������е������������ǲ�ս���ݰɣ���"<<endl<<endl;
            getch();
            cout<<"һ������ɫƤ�׵����������������͵س�������"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang1={130,130,26,3};
            fight(kasmon,horsegang1,9);
            cout<<"�������������䵶���Ѿ�Ⱦ������Ѫ����������Ҫ�����Ӷ�����Ϊ��������ǰ����һ��ͷ���ڽ����˸ո�ɱ����һ������ֵܣ������ֵ�ת��ͷ����Ϯ������"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang2={140,140,20,10};
            fight(kasmon,horsegang2,9);
            cout<<"�ڽ���˴�����ˤ����ȥ�����ر�������������һЩ��������ս����û�н��������������Ķ�����Ѹ�ٵ�������һ���������һ����������˵ļ���һ������"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang3={135,135,30,2};
            fight(kasmon,horsegang3,9);
            PlaySound("������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"���ӹ����꣬����ɽ���ĻĲݣ�����������䡣���������в����˵��£����鲼���ܵ����ʬ�壬�����òд�����Ƿ�����������ĸߺ���"<<endl<<endl;//���� ������
            getch();
            cout<<"��֪������һս������ʤ���ˡ�"<<endl<<endl;
            getch();
            cout<<"�ص�����ʱ�������ܵ������о���ļе���ӭ�����ǳ��������������µ�սʿ����վ����Ⱥ�е�һ��Ů����������һ�ۣ�����ӡ����̡�"<<endl<<endl;
            getch();
            cout<<"�����������ǵı������𺳣�Ϊ���п����������˽�����һЩ��ҡ�"<<endl<<endl;
            getch();
            cout<<endl<<"[��ʾ] ������"<<REWARD<<"���"<<endl<<endl;
            bp.coins+=REWARD;
        }
        else
        {
            cout<<"�����ƾɵ��ùݴ���һ�졣��֪������������Ѳ�߶ӳ��������ӣ������ĵ�ĬĬ���������ܹ����ʤ����"<<endl<<endl;
        }
        getch();
        system("pause");
        daycost();
        cout<<"��15��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("������ ����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"�������뿪�������ˡ�";//���� ������ ����
        if(teamfight==1)
            cout<<"����ǰ�����Ѿ���һͬԡѪ��ս�����ֵ�����һ�������Ƕ������������ֿ��ף����";
        cout<<endl<<endl;
        getch();
        cout<<"�������뿪�ùݣ���������ȥ��"<<endl<<endl;
        getch();
        if(teamfight==1)
        {
            cout<<"�ɾ�����û�߼���֮ʱ���㷢�֣��Ǹ��������������ӵ�Ů����ʱ��վ��·�ߣ����㻺��������"<<endl<<endl;
            getch();
            cout<<"�㷭����������������ǰ��"<<endl<<endl;
            getch();
            cout<<"��˹�ɣ�����ð��������"<<endl<<endl;
            Sleep(1000);
            cout<<"���ţ�����ã��ҽп��š���"<<endl<<endl;
            getch();
            cout<<"��������������������������֡�"<<endl<<endl;
            getch();
            cout<<"���ţ���������һֱ�����������ɧ�ţ�лл����Ϊ�������ս����"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�����Ҳֻ��ϣ��������������ø�����һЩ���������������"<<endl<<endl;
            Sleep(1000);
            if(banout==1)
            {
                cout<<"���ţ���Ҳлл�㣬�����Ҹ�硣��"<<endl<<endl;
                Sleep(1000);
                cout<<"��˹�ɣ������磿��"<<endl<<endl;
                Sleep(1000);
                cout<<"���ţ����԰���������˿��ˣ���������������������������������������ˣ�������Ĵ��ţ���һ�۾��ܿ����㲻���������ˡ���"<<endl<<endl;
                Sleep(1000);
            }
            else
            {
                cout<<"���ţ��������������������Ӧ�ò����������˰ɣ���"<<endl<<endl;
                Sleep(1000);
            }
            cout<<"��˹�ɣ����ǵģ����þӴ˵أ�ԭ�����԰�Ĭ·˹�����򡣡�"<<endl<<endl;
            Sleep(1000);
            cout<<"���ţ���һ��������������ˣ�ȴ��Ϊ���������İ���ͦ�����������ĺܸм��㡭����"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ����������������ȷ��ѡ��ɣ��������������ҵ���ҪĿ�ĵ�һֱ�Ǵ����������ϵĵط�����"<<endl<<endl;
            Sleep(1000);
            cout<<"���ţ�����֪������ʱ��Ҳ���뿪����Ŀ����򣬶���̤��ð�յ��ó̡������������ڿ���������ʱ�򣬼��˻�����Ҫ�ҡ���"<<endl<<endl;
            Sleep(1000);
            cout<<"�㿴������û��˵����"<<endl<<endl;
            getch();
            cout<<"���ţ�����֪����Ҫ�뿪�ˣ���������������������������ɡ���"<<endl<<endl;
            Sleep(1000);
            cout<<endl<<"[��ʾ] ����1������ɫ�β"<<endl<<endl;
            bp.iris+=1;
            getch();
            cout<<"���ţ�����������ϲ���Ļ���ÿ�����춼���������ϱߵĻ�԰���ҵ�����͵�������ɡ���"<<endl<<endl;
            getch();
            if(bp.fakepurplenecklace>0)
            {

                cout<<"��¶��΢Ц���ӱ������ͳ�һ���������ݸ�������"<<endl<<endl;
                getch();
                cout<<"��˹�ɣ����ǣ���Ҳ���������ɣ��͵������ҵĸ�����ˡ���"<<endl<<endl;
                bp.fakepurplenecklace-=1;
                cout<<endl<<"[��ʾ] �������1�����ϱ�ʯ����"<<endl<<endl;
            }
            else
            {
                cout<<"������¶��΢Ц�������л�⣬�������ĵ���"<<endl<<endl;
            }
        }
        getch();
        system("cls");
        cout<<"������������ӱ�������ɳۣ�ֱ����Զ���Ϸ�����"<<endl<<endl;
        getch();
        system("pause");
        daycost();
        cout<<"��16��"<<endl<<endl;
        getch();
        system("cls");
        cout<<"��һ�죬��һֱ��·������û����ʲô�ر���£���ֻ�ǲ�������ܵĵ�ò���Լ��ļ���Խ��Խ��ͬ�ˡ�"<<endl<<endl;
        getch();
        cout<<"ҹ����Ѱ���Ÿ��������֮����ֻ�ҵ�һ�Һ����õꡣ"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("ҹ��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"�����õ�"<<endl<<endl<<endl;//���� ҹ��
        getch();
        cout<<"����������õ꣬����õ��װ�ޱ�֮ǰ���������Ķ�Ҫ���Ӹߵ������������������濪�ƻᡣ"<<endl<<endl;
        getch();
        cout<<"���ǵĶԻ�����������������һ����������Ҫ·��ǰ���������Ĵ�ƽԭ������һ��������Ҫ�����Լ��ļ��˵�ǰ���������ĺ���կȥ��׼��������"<<endl<<endl;
        getch();
        cout<<"������Ĵ����������Եø���룬Ϊ�˱����⵽�������������ٻص����Լ�����ѡ�Ĵε�ס�䡣����е���ο�������ļ۸�û�ж�ô����"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"�����õ�"<<endl<<endl<<endl;
            cout<<"�˴�������֮�ء������������ʹ������̵����������Ʒ��"
            <<endl<<endl<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','q','s');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        daycost();
        cout<<"��17��"<<endl<<endl;
        getch();
        system("cls");
        cout<<"����������·��һ��ʱ�����ǰ������������·��·�Ե�ָʾ����д�ţ�һ��ͨ�����Ϸ��Ĵ�ƽԭ����һ����ͨ�����Ϸ��ĺ���կ��������Ҫ������·����������Ҫ��һ��ѡ��"<<endl<<endl;
        getch();
        cout<<endl<<"P��          ȥ����ƽԭ"<<endl;
        cout<<"S��          ȥ������կ"<<endl<<endl;
        gettwo(ch,'p','s');
        system("cls");
        if(ch=='p')
        {
            PlaySound("��ƽԭ.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"��ƽԭ"<<endl<<endl<<endl;//���� ��ƽԭ
            getch();
            cout<<"�Դ��ԭҰ��Ұ�����ţ��ƴ��Ͽջ���Ʈ����ʱ��ʱ��ס���⣬Ϊ�������һƬ��Ӱ��"<<endl<<endl;
            getch();
            cout<<"��ƽԭ�Ȱ�Ĭ·˹�������ϲ���ԭҰ���������������ӱ��ÿ��µĻ�������������������ܱ��۵Ŀ�С�"<<endl<<endl;
            getch();
            cout<<"��˹�ɣ����ܾ�û�������ɳ۹��ˡ�����"<<endl<<endl;
            getch();
            cout<<"���뵽���˹������̵ĳ��ԣ����ɵö�ǰ�������ڴ��������ڷ���֮��������غ���ţ���ǰ��������ӽӽ���"<<endl<<endl;
            getch();
            cout<<"����һ�ᣬ������һƬҰ��֮�������ս�����ͣ������������������ƾ�Լ����ڻ����У������������գ�����Ļ�������һ�Ե�ͷ������ݡ�"<<endl<<endl;
            getch();
            cout<<"�ɾ�����ʱ���������޵ĵͺ�ȴ�����ע�����Ӷ��ȥ��������������ֻ��ʨ��Ȼ��Զ���ƽ������ǵ��۾�͸��Ұ�ԣ��Ѿ��������Ļ���������"<<endl<<endl;
            getch();
            cout<<"Ϊ�˳��׳���Σ��Դ��������������ȣ������������һս�������䵶�����������������졣"<<endl<<endl;
            getch();
            cout<<endl<<"�����������ս��..."<<endl<<endl;
            getch();
            system("cls");
            cout<<"��ƽԭ"<<endl<<endl<<endl;
            cout<<"������׼���Գ������ĺ�ʨ�ӵ�����ʱ������Ѹ���ĺ�Ӱ����б������ǰ������������ֻ��ʨ���ڶ̶̵ļ������ڣ���ֻ��ʨӦ�����أ�����ȥ�Ѿ�������"<<endl<<endl;
            getch();
            cout<<"�㶨��һ����ԭ����������ʸ���ڼ���ͬһʱ�̣�������ֻ��ʨ���۾���"<<endl<<endl;
            getch();
            cout<<"�����ȥ������ת���ͬʱ��һ���ͳ�������������"<<endl<<endl;
            getch();
            cout<<"����ͷͿ�˶�����Ч�����ǿ졣��"<<endl<<endl;
            getch();
            cout<<"����һ������Ƥ�׵����ˣ��ֳ�һ�Ѵ󹭣���ʸ�������"<<endl<<endl;
            getch();
            cout<<"���ˣ��������ĺ�ʨ֮ë���ֿ��Ը��ҽ������ϼ�ƿ�þơ���"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���лл�������ҡ���"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ��������������ƽԭ�ϲ����ڡ�л������֣���Ϊ����һ�㲻���л�˵�������Ե����ֻ�б��ӡ�������ͻ���������ʱ������ϡ�еĺ�ʨ��˵˵�ɣ���Ϊʲô�ᵽ���������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�����Ҫȥ���������ϵĵط�����"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ������������ϣ���˵���������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���һ�������Ͼ��ĵط�����"<<endl<<endl;
            getch();
            cout<<"�������ˣ�¶��ǳЦ��ĬĬ�شӺ�ʨ�����аγ������ļ�ʸ��"<<endl<<endl;
            getch();
            cout<<"���ˣ����������ҵĹ����𣿡�"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ���������ʱΪ����Զ�����ŵ���ҫ��������ս������ʮ���꣬����һ������ֵ�û������Ժ��ľ���������ʮ��������ų��˻��˲�����ǰ�����ԵĿ�˹��ķ���������˵�����Ķ����ڰ�Ĭ·˹�ĻԻ͡���"<<endl<<endl;
            Sleep(1000);
            cout<<"�㾲��Ƭ�̣�������û˵�����ࡣ"<<endl<<endl;
            getch();
            cout<<"��˹�ɣ�������ǡ�����Ҫ����ȫ������"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ�����������˵��Щ�ˣ�������Σ������Ѿ���ȥ��ʱ���ˡ���"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ����ðɡ���"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ�����������Ȼ��˵���Ŀ�ĵ��Ǹ�Զ���Ϸ������и�����Ҫ���㡣��"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���ʲô����"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ�����ĵ��õ���ô������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���˵ʵ��������ô�ã���Ҳ��һЩ����"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ��������ӣ����ͷ������Ҫ��װһЩ�����͵ĵ�ս������Ҫ֪�����Ϸ�����һ����Σ�յĵ��򡣶�������ܰ���ʵ�֡���"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���������˼�ǣ����Ͻ��ң���"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ���û�������������޳��ģ������ն��ø��ҵ㱨�ꡣ�㿴���ҿ���ȥ��Ȼ�����Ǹ����һ���һ����ŻԻ͵����������������ڻ�����ҪΪ�˼�ƿ�þ��ڴ�ƽԭ��ת��תȥ�𣿹��������ԣ���ô������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ���ֻҪ���������ҵ���ս�����Ķ������Ҷ�һ��Ҫѧϰ���ǣ���Ҫʲô���ı��ꣿ��"<<endl<<endl;
            Sleep(1000);
            cout<<"���ˣ�����������ѡ��һ���Ǹ���"<<HUNTER<<"����ң������Ҿ������Ⱥü�����ϵȲ�³Ү�������ˣ���һ��ѡ���ǣ��Ҹ������ŵ�ͼ����˳�ŵ�ͼ�ı�ʶ�������������ߣ���ľ��Խ��Խ�ֱ࣬�����߽�һƬ�������������֣�������������ĵط���һ�þ�����������ǰ��һ������������ߵĵط�����������һ�ų�ɫ��ʯ����ֻҪȥ�������ʯ�ڳ������ҾͿ����ˣ�����ҪС�ģ��ǿž����Ĳ�Զ����һ��Ұ���˾ۼ��أ���Ը�㲻���������ǡ���������ѡ�ĸ���"<<endl<<endl;
            getch();
            cout<<endl<<"C��          �����˽��"<<endl;
            cout<<"F��          ȥ�ҳ�ɫ��ʯ"<<endl<<endl;
            gettwo(ch2,'c','f');
            system("cls");
            if(ch2=='f' || bp.coins<HUNTER)
            {
                if(ch2=='c')
                {
                    cout<<"[��ʾ] ��û���㹻�Ľ�ҿ��Ը�����"<<endl<<endl;
                    getch();
                }
                cout<<"�����ȥѰ�ҳ�ɫ��ʯ�����˳�ŵ���ڲ�Զ����ɽ���µ���ʱСľ���еȴ���Ĺ�����"<<endl<<endl;
                getch();
                system("cls");
                PlaySound("��������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"��������"<<endl<<endl<<endl;//���� ��������
                getch();
                cout<<"��������������˵�������У��������ľ����Ũ�ܣ��չⱻ�ڵ��˺ܶ࣬����һƬ�İ������ա�"<<endl<<endl;
                getch();
                cout<<"��ͻȻ�е�����һ���ʹ����ͷһ���ŷ��֣��Լ�����ľ���ϵľ��������ˡ�"<<endl<<endl;
                getch();
                cout<<"���˵�ͼ�İ����������������ң���һ������֮�������������˾���ǰ������䵶��һ��һ�µ�����������"<<endl<<endl;
                getch();
                cout<<"���ڣ�����䵶������һ��Ӳ����ٿ��������������ɫ�Ĺ�����¶�˳�������֤���Ǹ�Ӳ�ﲢ������ͨ��ʯͷ����������ҪѰ��Ķ������ɾ�����ʱ��������ȴ����һ����صĽŲ�����"<<endl<<endl;
                getch();
                cout<<"�㻹�������ڳ�������ʯ���Ǹ��Ų����������߾��Ѿ�����һ��ʯ��������˹�������"<<endl<<endl;
                getch();
                cout<<endl<<"�����������ս��..."<<endl<<endl;
                getch();
                Enemy barbarian={140,140,35,15};
                system("cls");
                fight(kasmon,barbarian,2);
                system("cls");
                PlaySound("��ƽԭ.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"��ƽԭ"<<endl<<endl<<endl;//���� ��ƽԭ
                cout<<"������ʱСľ�������¼��������ˣ����ǿų�ɫ��ʯ�ݸ�����������ϲ�ؽӹ����������������У��������֡�"<<endl<<endl;
                getch();
                cout<<"���ˣ���̫���ˣ������������ֱ�Ǻ���һ׮����ô�������ھͽ�����ʮ�����ս������������ɵľ�����һ��ʮ�����Ͷ�ʹ���˷���ʤ����ɱ��֮������"<<endl<<endl;
                getch();
                cout<<endl<<"[��ʾ] ��ѧ�����¼��ܣ���ԭҰ�̿�����"<<endl<<endl;
                cout<<"���ܽ��ܣ��������������3~5�ι�����ÿ�ι�����30%�ļ��ʴ������ͨ������ͬ���˺�����40%�ļ��ʴ����ͨ����70%���˺�����30%�ļ��ʴ����ͨ����40%���˺���ʹ�ô���"<<SKILL4PP<<"�Ρ�"<<endl<<endl;
                kasmon.skill_4=1;
            }
            else if(ch2=='c' && bp.coins>=HUNTER)
            {
                bp.coins-=HUNTER;
                cout<<"���ˣ�����������ϲ�����ֱ�ӣ���ô�������ھͽ�����ʮ�����ս������������ɵľ�����һ��ʮ�����Ͷ�ʹ���˷���ʤ����ɱ��֮������"<<endl<<endl;
                getch();
                cout<<endl<<"[��ʾ] ��ѧ�����¼��ܣ���ԭҰ�̿�����"<<endl<<endl;
                cout<<"���ܽ��ܣ��������������3~5�ι�����ÿ�ι�����30%�ļ��ʴ������ͨ������ͬ���˺�����40%�ļ��ʴ����ͨ����70%���˺�����30%�ļ��ʴ����ͨ����40%���˺���ʹ�ô���"<<SKILL4PP<<"�Ρ�"<<endl<<endl;
                kasmon.skill_4=1;
            }
            getch();
            system("cls");
            cout<<"�������˵������Զ���Ϸ���ȥ������Լ���ã��Լ��ܿ��Ҫ�������յ�Ŀ�ĵء�"<<endl<<endl;
        }
        else
        {
            PlaySound("����կ������.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"����կ"<<endl<<endl<<endl;//���� ����կ������
            getch();
            cout<<"������ó�ʪ������������Զ����˫Ŀ�ҳϵظ����㣬���Ѿ������˴󺣵����ԡ�"<<endl<<endl;
            getch();
            cout<<"��С�ڰ�Ĭ·˹�����򳤴���㣬�Ӵ�������Ǻ����л������ʵ���ˮ��Ҳ����û�����ۼ����󺣵Ĳ��Σ�ֻ��ӡ���������ľ�����֮���١�"<<endl<<endl;
            getch();
            cout<<"����һ�����ں����Ե�կ����ȥ��"<<endl<<endl;
            getch();
            cout<<"կ�У�������������͵����գ�����������Ϸ���֣�׼������������������ڴ����������������ס�"<<endl<<endl;
            getch();
            cout<<"�㽫��˩��ľ���ϣ����򺣱ߣ�һ�����ں�̲��������������ǰ�ľ�������������˰�Ĭ·˹�ĺ�����Ҳ���������������е����������ж�ʱ����λ���ߡ�"<<endl<<endl;
            getch();
            cout<<"����������ѿ��������Խ�����ɣ����ѿ�ʼ���������Լ����ó̡�"<<endl<<endl;
            getch();
            cout<<"�������ˣ�����ȥ���������°�����"<<endl<<endl;
            getch();
            cout<<"������Դ��ȥ��һ������������Ҳ�������������������������Ϲ��źͰ���΢Ц��"<<endl<<endl;
            getch();
            cout<<"���ǿ�ʼ����Ȼ�����ɵĽ�̸�����֪����Ҳ��һ�����ߣ�ֻ�ǲ���������"<<endl<<endl;
            getch();
            cout<<"�����ߣ��������˻��Ǻð����˵�ǿ��һ���Ͼ�һȥ�������ˡ�����"<<endl<<endl;
            getch();
            cout<<"����һͬ����Զ���ĺ��ˣ��ղ�������׼�����������Ѿ��ں��������˷緫�����Ƹո���á�"<<endl<<endl;
            getch();
            cout<<"�����ߣ����ɷ�����ң������ˣ��������Ҫ������ȥ����"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�����Ҫ���Ͼ�ȥ����"<<endl<<endl;
            getch();
            cout<<"����¶��ǳЦ����������ȥ����Щ���⡣"<<endl<<endl;
            getch();
            cout<<"�����ߣ�����ʮ��ǰ����������Զ�����ŵ�����ҽ�ߡ��ڱ��ŷ�����˹��ķ���ǶλԻ�ʱ����������������ʿ�������ǵ������»ص�ս������"<<endl<<endl;
            getch();
            cout<<"�㿪ʼ����վ�����ߵ��ӽ�������ξ������ġ�"<<endl<<endl;
            getch();
            cout<<"�����ߣ��������ˣ���Ȼ��Ҫ������ȥ��һ·�Ϻܿ��ܻ�����һЩΣ�ա������ɣ��ҽ̸���һЩ�ܹ�Ѹ���������˼��ȵķ�������Щ�����Ҵ�ս���ϻ�õı����飬������Ȥ�𣿡�"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ�����̫���ˣ������Ը����ң��һ�м���������"<<endl<<endl;
            Sleep(1000);
            cout<<"�����ߣ���ֻ�ǣ���Щ�취�����ǳ����ļ���������ˣ�Ҫ�������ǣ���Ҫ��߱��ض������ʣ��Լ��㹻�Ŀ�����������ڿ�ʼ����ǰ���ҵö�����һ�����ԣ�ֻ����ͨ�����ԣ���˵�����ʺ�ѧϰ������Ѹ�����˷�������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ����ã���ʲô���Ĳ��ԣ���"<<endl<<endl;
            Sleep(1000);
            cout<<"�����ߣ��������ɣ�կ������һ�����Ÿ����ĳ�ѧ�ߣ����������һ�����������սʤ��������ֻ�����ˣ���ô�Ҿͽ̸���������������ģ�������ȫ��װ��Լ������úܺõģ�ֻҪ��û��������������սʤ��������"<<endl<<endl;
            Sleep(1000);
            cout<<"��˹�ɣ������ɣ���"<<endl<<endl;
            getch();
            cout<<endl<<"[��ʾ] Ҫ�ﵽҪ��ս����ʼ�����ʱ�������ֵ���ܴ���40��"<<endl<<endl;
            cout<<"�����������ս��..."<<endl<<endl;
            Enemy younglearner={130,130,5,9};
            getch();
            system("cls");
            int hp0=kasmon.health;
            fight(kasmon,younglearner,9);
            int hp1=kasmon.health;
            if( (hp0-hp1)<40 )
            {
                cout<<"�����ߣ����ð���������߱�ѧϰ���׼��ȷ�������������ô�����ھͰ����ǽ̸��㡣��"<<endl<<endl;
                getch();
                cout<<endl<<"[��ʾ] ��ѧ�����¼��ܣ������⼱������"<<endl<<endl;
                cout<<"���ܽ��ܣ�ʹ�ú�ָ�20~30����ֵ��ʹ�ô���"<<SKILL5PP<<"�Ρ�"<<endl<<endl;
                kasmon.skill_5=1;
            }
            else
            {
                cout<<"�����ߣ������������㻹�ǲ��߱�ѧϰ���׼��ȷ�����������������"<<endl<<endl;
            }
            getch();
            system("cls");
            cout<<"ֱ��Ϧ����������ߣ����������ߵ����뿪�˺���կ�����Զ���Ϸ���ȥ������Լ���ã��ܿ��Ҫ�������յ�Ŀ�ĵء�"<<endl<<endl;
        }
        getch();
        system("pause");
        system("cls");
        daycost();
        PlaySound("�հ�.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"��18��"<<endl<<endl;//�˴�������
        getch();
        system("cls");
        cout<<"�㲢û������������������ˣ����㷢�����ܵĻ������ӻ��ߣ�ֲ������ϡ�衣"<<endl<<endl;
        getch();
        cout<<"��֪����ǰ�������û�����ĵط���Ҳ����һֱ����ͼ����ĵط���"<<endl<<endl;
        getch();
        system("pause");
        system("cls");
        cout<<"��19��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("����֮ԭ.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"����֮ԭ"<<endl<<endl<<endl;//���� ����֮ԭ
        getch();
        cout<<"������һƬ��ԭ�ϣ��������ɱ����ɪ�Ͳ�ã����ǰ��δ���ġ��������Ĵ�������ȴ��Ҳ�Ҳ���һ����Ӱ��"<<endl<<endl;
        getch();
        cout<<"���û���ͣ��һ���ߵأ���Զ����ȥ����������ã֮ʱ��һ�����ϵ��������������"<<endl<<endl;
        getch();
        cout<<"���������ɡ���"<<endl<<endl;
        getch();
        cout<<"��һ���������ϵģ����ź��µ����ߡ�"<<endl<<endl;
        getch();
        cout<<"���ߵ�ת��ͷ�������������������һ��Ӫ��ǰ��"<<endl<<endl;
        getch();
        cout<<"������������¸���ֻ��һ��Ŀ�ģ���ǰ��������յ���ս�����ǣ�����������ֵ�׼������"<<endl<<endl;
        getch();
        cout<<"˵�꣬���߽�����Ӫ�ʣ��˺�������˳�Ĭ������ָ��������һ�Ż��ܣ������������������������η��ʡ�"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"����֮ԭ �ۺ��̵�"<<endl<<endl<<endl;
            cout<<"����Ʒ��"<<endl<<endl;
            cout<<"���ʾ�"<<endl;
            cout<<"�۸�"<<LEMONA_C<<"���   L������"<<endl;
            cout<<"��֪����ʿ�ķ����������Ʊ�����ˮ��ƾ������һ����ƶ��ɵĶ������ơ����ú󹥻�������"
            <<LEMONA_A<<"���������˿ɻָ�"<<LEMONA_H<<"����ֵ��"<<endl<<endl;
            cout<<"��³Ү����"<<endl;
            cout<<"�۸�"<<BRUJE_C<<"���   R������"<<endl;
            cout<<"�����ϡ�еĲ�³Ү�����Ǹ߹�����ص����������ĵ��Ʒ���ֻ����������֪�������ú󹥻�������"
            <<BRUJE_A<<"���������˿ɻָ�"<<BRUJE_H<<"����ֵ��"<<endl<<endl;
            cout<<"������Ʒ��"<<endl<<endl;
            cout<<"����"<<endl;
            cout<<"�۸�"<<BANDAGE_C<<"���   A������"<<endl;
            cout<<"������������Ʒ��ʹ�ú�ɻָ�"<<BANDAGE_H<<"����ֵ��"<<endl<<endl;
            cout<<"ҩ��"<<endl;
            cout<<"�۸�"<<HERB_C<<"���   H������"<<endl;
            cout<<"����ҩ�ݲ���ƫƧ��Σ�յ�ɽ�أ��Ը�����������������������ã��������˴���Ч�����ٵػָ���ʹ�ú�ɻָ�"<<HERB_H<<"����ֵ��"<<endl<<endl;
            cout<<"���־���"<<endl;
            cout<<"�۸�"<<POTION_C<<"���   P������"<<endl;
            cout<<"��һ����Ϊ���ֵİ�������Ҷ����ȡ��֭Һ���ڷ������þ��������Ե��������ã�ֻ�ǲ������ˡ�ʹ�ú�ɻָ�"<<POTION_H<<"����ֵ��"<<endl<<endl;
            cout<<"��������"<<endl<<endl;
            cout<<"��׼�����"<<endl;
            cout<<"�۸�"<<SWORD_C<<"���   S������"<<endl;
            cout<<"���˾����е������������ڼ���ʷǷ�������Ҳϲ��������������Թ�����װ���󹥻�������"<<SWORD_A<<"��"<<endl<<endl;
            cout<<"��ì"<<endl;
            cout<<"�۸�"<<SPEAR_C<<"���   E������"<<endl;
            cout<<"������֮ǰ��Ҫ������ȫ��Ŀ��ǣ��������۸񲻷ƣ������к�ǿ��ʵս��������������װ���󹥻�������"<<SPEAR_A<<"��"<<endl<<endl;
            cout<<"�����ס�"<<endl<<endl;
            cout<<"��˹������"<<endl;
            cout<<"�۸�"<<LANSTONARMOR_C<<"���   N������"<<endl;
            cout<<"������Զ��Ľ�����˹����ƣ���һ������׸�����ء�װ�������������"
            <<LANSTONARMOR_A<<"��"<<endl<<endl;
            cout<<"ʮ�ּ�"<<endl;
            cout<<"�۸�"<<CROSSARMOR_C<<"���   C������"<<endl;
            cout<<"��������ͷ���ϵ�ʮ��ͼ��������װ�����ı��䣬�ʺ���ǿ��׳���˴��š�װ�������������"
            <<CROSSARMOR_A<<"��"<<endl<<endl;
            cout<<"���ʯս��"<<endl;
            cout<<"�۸�"<<DIAMONDARMOR_C<<"���   D������"<<endl;
            cout<<"�ؼ��ܻ���λ���ɽ��ʯ������ɣ�����Ч�����Զ�������������Щÿ����ׯ԰�гԸ߶���ϯ�Ĺ����ǣ������ж������ܸ����������ļ۸�ġ�װ�������������"
            <<DIAMONDARMOR_A<<"��"<<endl<<endl<<endl;
            cout<<"�鿴����          B  "<<endl;
            cout<<"�뿪              ����"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"�ѹ���  ���ʾ�x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'r':
                {
                    if(!cck(BRUJE_C)) break;
                    bp.bruje+=1;
                    bp.coins-=BRUJE_C;
                    cout<<"�ѹ���  ��³Ү����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'a':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"�ѹ���  ����x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'h':
                {
                    if(!cck(HERB_C)) break;
                    bp.herb+=1;
                    bp.coins-=HERB_C;
                    cout<<"�ѹ���  ҩ��x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'p':
                {
                    if(!cck(POTION_C)) break;
                    bp.potion+=1;
                    bp.coins-=POTION_C;
                    cout<<"�ѹ���  ���־���x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 's':
                {
                    if(!cck(SWORD_C)) break;
                    bp.weapon="��׼�����";
                    bp.weapon_add=SWORD_A;
                    kasmon.attack=KASMONATTACK+SWORD_A;
                    bp.coins-=SWORD_C;
                    cout<<"�ѹ���װ��  ��׼�����"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'e':
                {
                    if(!cck(SPEAR_C)) break;
                    bp.weapon="��ì";
                    bp.weapon_add=SPEAR_A;
                    kasmon.attack=KASMONATTACK+SPEAR_A;
                    bp.coins-=SPEAR_C;
                    cout<<"�ѹ���װ��  ��ì"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'n':
                {
                    if(!cck(LANSTONARMOR_C)) break;
                    if(bp.armor=="��˹������")
                    {
                        cout<<"����ӵ�д˻���"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=LANSTONARMOR_A;
                    bp.armor="��˹������";
                    bp.armor_add=LANSTONARMOR_A;
                    bp.coins-=LANSTONARMOR_C;
                    cout<<"�ѹ���װ��   ��˹������"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'c':
                {
                    if(!cck(CROSSARMOR_C)) break;
                    if(bp.armor=="ʮ�ּ�")
                    {
                        cout<<"����ӵ�д˻���"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=CROSSARMOR_A;
                    bp.armor="ʮ�ּ�";
                    bp.armor_add=CROSSARMOR_A;
                    bp.coins-=CROSSARMOR_C;
                    cout<<"�ѹ���װ��   ʮ�ּ�"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(DIAMONDARMOR_C)) break;
                    kasmon.defend=DIAMONDARMOR_A;
                    bp.armor="���ʯս��";
                    bp.armor_add=DIAMONDARMOR_A;
                    bp.coins-=DIAMONDARMOR_C;
                    cout<<"�ѹ���װ��   ���ʯս��"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          ����"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='l' || ch2=='r' || ch2=='a' || ch2=='h' || ch2=='p' || ch2=='s' || ch2=='e' || ch2=='n' || ch2=='c' || ch2=='d' || ch2=='b');
        system("cls");
        cout<<"����ñ�������̧��ͷ��ȴ�������ص�����������ͬ�����Ļ��ܶ��Ѳ�������Ӱ��"<<endl<<endl;
        getch();
        cout<<"�����߳�Ӫ��֮ʱ��Զ�������ս�������ԭ��Ⱦ���˳Ⱥ�ɫ�����Ӱ���ڵ���������б����"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("ҹ��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"�ǳ��͵���ɫ�ӹ�����Ļ��һ�־��´�Զɽ�������������ңԶ�ļ��磬�㲻֪�����˶��ٴ����˹��á�"<<endl<<endl;//���� ҹ��
        getch();
        cout<<"��������ѡ��һ���ǣ�������������Լ��˵Ĺ����������Ҳ֪��������Ҳһ������ҹ���е�һ������������Լ���ףԸ��"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"ҹ���µ�¶��"<<endl<<endl<<endl;
            cout<<"��B���򿪱�������S���鿴״̬����Q��������"<<endl<<endl;
            getthree(ch,'b','s','q');
            if(ch=='b')
            {
                bp.show();
                bp.use();
            }
            else if(ch=='s')
                kasmon.status();
        }while(ch!='q');
        system("cls");
        cout<<"��20��"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("���ìʿ��BOSS��.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"һ��ʯ����ӳ���������������ʯ���ŵı��󣬳�����һ������ɫ���ס��ֳֻ�ɫì��ܵ�ìʿ��"<<endl<<endl;//���� ���ìʿ
        getch();
        cout<<"���ìʿ������ӭ�����Ͼ�����ڣ�ȷ�е�˵�����Ͼ��ı�Ե����"<<endl<<endl;
        getch();
        cout<<"���ìʿ���������Ͼ�֮�ŵ������ߣ�ר�Ž��������̽�����������Ͼ�֮�⡣��֪�������һ���Ѿ��ܾ��ˣ��������սʤ�ң����ܵõ������Ͼ����ʸ񡣡�"<<endl<<endl;
        getch();
        cout<<"��˹�ɣ����ð�����������ɣ���"<<endl<<endl;
        getch();
        cout<<"���ìʿ�������Ǹ��¸��ߵ���Ϸ�������𣿡�"<<endl<<endl;
        getch();
        cout<<endl<<"��������������յ�ս��..."<<endl<<endl;
        getch();
        system("cls");
        Enemy guarder={200,200,40,20};
        fight(kasmon,guarder);
        system("cls");
        cout<<"���ìʿ�����㡭����Ӯ�ˡ���"<<endl<<endl;
        getch();
        cout<<"���ìʿ����һ��Ϊ���ó�·����ʯ���ŷ·��������������"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("��β����.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"���Ͼ���"<<endl<<endl<<endl;//���� ��β����
        getch();
        cout<<"����̤��ʯ���ţ������ۣ�����������ϣ����ܵľ���û������Ԥ����������ӻ�����Ҳû��ʲô�����˵Ĺ����������ε����е�ֻ��Խ��Խ������ݡ����ֺ�ɽ�ԡ�"<<endl<<endl;
        getch();
        cout<<"��Զ�������ڵȴ����㡣�㽫��˩��һ�����ԣ��������˹�ȥ��"<<endl<<endl;
        getch();
        cout<<"��֪���ߣ�����ӭ�����Ͼ�����"<<endl<<endl;
        getch();
        cout<<"������¶������׽����΢Ц������Щ����"<<endl<<endl;
        getch();
        cout<<"��˹�ɣ���������ľ��ǡ����Ͼ��𣿡������ǣ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��֪���ߣ������Ҹ���������һ���°ɡ���"<<endl<<endl;
        getch();
        cout<<"������������ߵ�ɽ�Զ���������̤����ݣ����ٴ��ӹ����ԡ�"<<endl<<endl;
        getch();
        cout<<"��֪���ߣ�������ǰ���ڰ�Ĭ·˹��������һλ�����˻���̽������һ���¸ҵ��ģ�̤����ȥ���Ϸ��Ĺ���֮�á��������û�ٻص����У��������Ǵ��ԣ����Ѿ����������Ͼ�������ʵ�ϣ���ͨ��������Զ�����ŵ��ȷ������ѡ�Ρ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ����ȷ�������������Ǵ����У���������֧�����صġ�����"<<endl<<endl;
        Sleep(1000);
        cout<<"��֪���ߣ����ǰ��������������У����������ͨ��ʿ����������ʱ�仹�ǿռ�Ƕȣ�����ս������ǰ�У�ʱ�����ν���о��󷽵�����ʹ���������ر�ķ�ʽ�������ս�����ͬʱ������Ҳ�����¸ҡ����������͵�ʿ������"<<endl<<endl;
        Sleep(1000);
        cout<<"��֪���ߣ�����������Ϊ�ȷ����Ҳ��ʾ��Ҫ����һ��ȫ�µ������Ϊ����Զ��������Ҫ��һ���֣���λ���Ϸ�������Ӫ�س���פ����ѵ�������Լ��ڼ�������˺����Ѳ����ж�����ϵ������Ϊ��ˣ����ǲŻὫ�ҵ����������������й��Ͼ��Ĵ��ԡ���"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�������˵�����������ȷ������һԱ����"<<endl<<endl;
        getch();
        cout<<"��ĬĬ�ؿ�����һ�ۣ�û��ֱ�ӻش�"<<endl<<endl;
        getch();
        cout<<"��֪���ߣ����й��Ͼ��Ĵ����Ǳ�Ҫ�ġ��ڰ�Ĭ·˹��û�����˲����Ϊ��ҫ������Զ�����ŵ�һԱ��������˵���ȷ������Ȼ���ȷ��������û�ж��ڹ�����ѡ�η�ʽ��������һ�������Ͼ�����Σ�յĴ��Ի��ڰ�Ĭ·˹��ÿ���ط����������������¸ҺͲ�����ս��������̤��ͨ���Ͼ����ó̡���������һ·�Ŀ�����ֱ������սʤ��ʯ����ǰվ���ŵ������ߣ���Ҳ�ͻ���˽����Ͼ�������˵�����ȷ�������ʸ�����Ǳ��Ŷ������˵Ŀ��飬��"<<endl<<endl;
        Sleep(1000);
        cout<<"��˹�ɣ�����ô�������˵������"<<endl<<endl;
        Sleep(1000);
        cout<<"��֪���ߣ����ǵģ������˵�������ڿ�ʼ�����Ϊ���ȷ������һ���ӡ�";
        if(robfight==1)
            cout<<"���ͻ��������Σ�գ����ܺ������ò����ڼ�ʱ�ط�����";
        if(beggar==1)
            cout<<"�㿶�����������ʵ��������ꤵ��ˡ�";
        if(maid==1)
            cout<<"�����߱���ѹ������ͦ���������ǿ������";
        if(banout==1)
            cout<<"�ڱ�������������Σ��ʱ���㻳�����ĺ�����ԥ�س���������";
        if(teamfight==1)
            cout<<"���ܽ��Լ��İ�ȫ��֮���⣬ƴ����������֮�˵İ�����";
        cout<<endl<<endl;
        getch();
        cout<<"��֪���ߣ�����ô��׼��ӭ��ȫ�µ���������ս�ɡ���"<<endl<<endl;
        getch();
        cout<<"������Ų�֪���ߵĽŲ������Ὣ�������Ӫ����̧��ͷ�����񻮹���գ���Զ�������������Ϊ�����Ͼ����û����˾�š�"<<endl<<endl;
        getch();
        system("cls");
        victory();   //ʤ������
        color(16);
        getch();
        system("pause");
        system("cls");
        color(16);
        maker();//����������
        system("pause");
    }//���ڽ�����Ϸ��else������Ļ�����
}//main���������Ļ�����
