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
void color(short x)	//自定义函根据参数改变颜色
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
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
        cout<<"状态栏"<<endl<<endl<<endl;
        cout<<"生命值："<<health<<endl<<endl;
        cout<<"攻击力："<<attack<<endl<<endl;
        cout<<"防御力："<<defend<<endl<<endl<<endl;
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
    string weapon="徒手", armor="无", shield="无";
    int weapon_add=0, armor_add=0;
    int marton=0, lemona=0, bruje=0;
    int bandage=0, herb=0, potion=0;
    int sandwich=0, book=0, fakepurplenecklace=0, iris=0;
    void show()
    {
        system("cls");
        cout<<"背包"<<endl<<endl<<endl;
        cout<<"当前有"<<coins<<"枚金币"<<endl<<endl;
        cout<<"当前武器："<<weapon<<"，武器攻击力加成："<<weapon_add<<endl<<endl;
        if(armor!="无")
            cout<<"当前护甲："<<armor<<"，护甲防御力加成："<<armor_add<<endl<<endl;
        if(marton!=0)
            cout<<"当前有"<<marton<<"瓶玛顿酒"<<endl;
        if(lemona!=0)
            cout<<"当前有"<<lemona<<"瓶柠檬酒"<<endl;
        if(bruje!=0)
            cout<<"当前有"<<bruje<<"瓶布鲁耶蓝晶"<<endl;
        if(bandage!=0)
            cout<<"当前有"<<bandage<<"个绷带"<<endl;
        if(herb!=0)
            cout<<"当前有"<<herb<<"个药草"<<endl;
        if(potion!=0)
            cout<<"当前有"<<potion<<"个麦卡林精华"<<endl;
        if(sandwich!=0)
            cout<<"当前有"<<sandwich<<"个三明治"<<endl;
        if(book!=0)
            cout<<"当前有"<<book<<"本书籍"<<endl;
        if(fakepurplenecklace!=0)
            cout<<"当前有"<<fakepurplenecklace<<"个仿紫宝石项链"<<endl;
        if(iris!=0)
            cout<<"当前有1朵紫蓝色鸢尾"<<endl;
        cout<<endl<<endl<<endl<<endl;
    }
    void use()
    {
        char chh1,chh2;
        if(bandage>0)
            cout<<"按D使用绷带"<<endl<<endl;
        if(herb>0)
            cout<<"按H使用药草"<<endl<<endl;
        if(potion>0)
            cout<<"按P使用麦卡林精华"<<endl<<endl;
        if(marton>0|| lemona>0 || bruje>0)
            cout<<"按A使用酒"<<endl<<endl;
        if(book>0)
            cout<<"按O使用书籍"<<endl;
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
                    cout<<"绷带已经使用，生命值恢复"<<BANDAGE_H<<endl<<endl;
                    kasmon.health+=BANDAGE_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    bandage-=1;
                }
                else
                {
                    cout<<"你没有受伤，无需使用绷带"<<endl<<endl;
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
                    cout<<"药草已经使用，生命值恢复"<<HERB_H<<endl<<endl;
                    kasmon.health+=HERB_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    herb-=1;
                }
                else
                    cout<<"你没有受伤，无需使用药草"<<endl<<endl;
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
                    cout<<"麦卡林精华已经使用，生命值恢复"<<POTION_H<<endl<<endl;
                    kasmon.health+=POTION_H;
                    if(kasmon.health>100)
                        kasmon.health=100;
                    potion-=1;
                }
                else
                    cout<<"你没有受伤，无需使用麦卡林精华"<<endl<<endl;
                system("pause");
                system("cls");
                break;
            }
        case 'a':
            {
                if(marton==0 && lemona==0 && bruje==0)
                    break;
                cout<<"当前有"<<marton<<"瓶玛顿酒"<<endl;
                cout<<"当前有"<<lemona<<"瓶柠檬酒"<<endl;
                cout<<"当前有"<<bruje<<"瓶布鲁耶蓝晶"<<endl<<endl;
                char choice;
                int own=0;
                cout<<"M          使用玛顿酒"<<endl;
                cout<<"L          使用柠檬酒"<<endl;
                cout<<"B          使用布鲁耶蓝晶"<<endl<<endl;
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
                cout<<"你要如何使用这瓶酒？"<<endl<<endl;
                cout<<"I          饮用"<<endl;
                cout<<"C          处理伤口（效率较低）"<<endl<<endl<<endl;
                cout<<"esc        返回"<<endl;
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
                            cout<<"你的攻击力有了小幅增加（仅限下一场战斗）"
                            <<endl<<endl;
                            break;
                        case 'l':
                            lemona-=1;
                            kasmon.add_L=1;
                            kasmon.attack+=LEMONA_A;
                            cout<<"你的攻击力有了一定的增加（仅限下一场战斗）"
                            <<endl<<endl;
                            break;
                        case 'b':
                            bruje-=1;
                            kasmon.add_B=1;
                            kasmon.attack+=BRUJE_A;
                            cout<<"你的攻击力有了可观的增加（仅限下一场战斗）"
                            <<endl<<endl;
                            break;
                        }
                    }
                    else
                        cout<<"你已经喝过酒了，再喝就要喝多了"<<endl<<endl;
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
                            cout<<"玛顿酒已经用来处理伤口，生命值恢复"<<MARTON_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                         case 'l':
                            lemona-=1;
                            kasmon.health+=LEMONA_H;
                            cout<<"柠檬酒已经用来处理伤口，生命值恢复"<<LEMONA_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                        case 'b':
                            bruje-=1;
                            kasmon.health+=BRUJE_H;
                            cout<<"布鲁耶蓝晶已经用来处理伤口，生命值恢复"<<BRUJE_H<<endl<<endl;
                            if(kasmon.health>100)
                                kasmon.health=100;
                            break;
                        }
                    }
                    else
                        cout<<"你没有受伤，无需使用酒来疗伤"<<endl<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            }//case'a'尾部
        case 'o':
            {
                system("cls");
                kasmon.skill_2=1;
                cout<<"[提示] 你学会了技能【格挡法则】"<<endl<<endl;
                cout<<"技能介绍：第一次使用后防御力提升6点，第二次使用后防御力提升3点。"<<endl<<endl;
                book=0;
                getch();
                break;
            }
        default:;
        }
    }
};
Backpack bp;

bool cck(int c)//购买物品前检验金币是否足够
{
    if(bp.coins-c<0)
    {
        cout<<"金币不足！"<<endl<<endl;
        system("pause");
        return 0;
    }
    else
        return 1;
}

void blood(int a,int b)//当前血量|总血量
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
//战斗系统函数生成点
void fight(Kasmon& a, Enemy& b,int num=0)
{
    switch(num)
    {
        case 1: PlaySound("强盗战斗.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP); break;
        case 2: PlaySound("荆棘暗林 野蛮人.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP); break;
        case 3: PlaySound("启动界面及帮助界面.wav",NULL,SND_FILENAME | SND_ASYNC); break;
        case 4: PlaySound("启动界面及帮助界面.wav",NULL,SND_FILENAME | SND_ASYNC); break;
        case 5: PlaySound("启动界面及帮助界面.wav",NULL,SND_FILENAME | SND_ASYNC); break;
    }
    int a0=a.attack, d0=a.defend;
    int time_1=SKILL1PP; int time_2=SKILL2PP; int time_3=SKILL3PP; int time_4=SKILL4PP; int time_5=SKILL5PP;
    char c;
    int Gailv, randp, aatk, batk, ad, bd;
    srand((unsigned int)time(NULL));
    while(b.health>0 && a.health>0)
    {
        system("cls");
        cout<<"正在进行战斗..."<<endl<<endl;
        cout<<"选择你打算使用的技能："<<endl<<endl;
        cout<<"A       普通攻击"<<endl;
        if(a.skill_1==0)
            cout<<"1       [未学习技能]"<<endl;
        else
            cout<<"1       蓄  力"<<"         剩余使用次数："<<time_1<<"/"<<SKILL1PP<<endl;
        if(a.skill_2==0)
            cout<<"2       [未学习技能]"<<endl;
        else
            cout<<"2       格挡法则"<<"       剩余使用次数："<<time_2<<"/"<<SKILL2PP<<endl;
        if(a.skill_3==0)
            cout<<"3       [未学习技能]"<<endl;
        else
            cout<<"3       尘  风"<<"         剩余使用次数："<<time_3<<"/"<<SKILL3PP<<endl;
        if(a.skill_4==0)
            cout<<"4       [未学习技能]"<<endl;
        else
            cout<<"4       原野刺砍术"<<"     剩余使用次数："<<time_4<<"/"<<SKILL4PP<<endl;
        if(a.skill_5==0)
            cout<<"5       [未学习技能]"<<endl;
        else
            cout<<"5       特殊急救术"<<"     剩余使用次数："<<time_5<<"/"<<SKILL5PP<<endl;
        if( (bp.bandage!=0 || bp.herb!=0 || bp.potion!=0) && kasmon.health<100 && kasmon.use_heal==0)
            cout<<endl<<endl<<"H       使用疗伤物品"<<endl;
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
            if(bp.weapon=="徒手")
            {
                randp=rand()%2+1;
                if(randp==1)
                    cout<<"你狠狠挥拳向对方砸去……"<<endl;
                else
                    cout<<"你快速起腿，向对方袭去……"<<endl;
            }
            else
            {
                randp=rand()%2+1;
                if(randp==1)
                    cout<<"你向对方狠狠挥动手中的武器……"<<endl<<endl;
                else
                    cout<<"你鼓足力量，向对方发动全力一击……"<<endl<<endl;
            }
            cout<<"同时，对方也对你进行了攻击……"<<endl<<endl;
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
            cout<<"对方生命值 -"<<bd<<endl;
            cout<<"你的生命值 -"<<ad<<endl<<endl;
            if(b.health>0)
            {

                cout<<"对方的生命值:"<<b.health<<endl;
                blood(b.health,b.all_health);
            }
            else
                cout<<"对方的生命值:0"<<endl;
            if(a.health>0)
            {

                cout<<"你的生命值:"<<a.health<<endl;
                blood(a.health,a.all_health);
            }
            else
                cout<<"你的生命值:0"<<endl;
        }
        if(c=='1')
        {
            if(a.skill_1==0)
                cout<<"技能暂未解锁...."<<endl;
            else
            {
                if(time_1<=0)
                    continue;
                time_1--;
                a.attack=(a.attack*120)/100;
                cout<<"你退后一步，静蓄力量……"<<endl;
                cout<<"你的攻击力已增加20%"<<endl;
                batk=( b.attack*(rand()%4+8) )/10;
                ad=batk-a.defend;
                if(ad<=0)
                    ad=rand()%3+1;
                a.health-=ad;
                cout<<"但与此同时，对方向你发动了攻击……"<<endl<<endl;
                Sleep(1000);
                cout<<"你的生命值 -"<<ad<<endl<<endl;
                if(b.health>0)
                {

                    cout<<"对方的生命值:"<<b.health<<endl;
                    blood(b.health,b.all_health);
                }
                else
                    cout<<"对方的生命值:0"<<endl;
                if(a.health>0)
                {

                    cout<<"你的生命值:"<<a.health<<endl;
                    blood(a.health,a.all_health);
                }
                else
                    cout<<"你的生命值:0"<<endl;
            }
        }
        if(c=='2')
        {
            if(a.skill_2==0)
                cout<<"技能暂未解锁...."<<endl;
            else
            {
                if(time_2<=0)
                    continue;
                time_2--;
                cout<<"你做出防守架，开始更加注意格挡对方的攻击……"<<endl;
                if(time_2==SKILL2PP-1)
                {
                    kasmon.defend+=6;
                    cout<<"你的防御力已提升6点"<<endl<<endl;
                }
                else
                {
                    kasmon.defend+=3;
                    cout<<"你的防御力已提升3点"<<endl<<endl;
                }
            batk=( b.attack*(rand()%4+8) )/10;
            ad=batk-a.defend;
            if(ad<=0)
                ad=rand()%3+1;
            a.health-=ad;
            cout<<"但与此同时，对方向你发动了攻击……"<<endl<<endl;
            Sleep(1000);
            cout<<"你的生命值 -"<<ad<<endl<<endl;

            if(b.health>0)
            {
                cout<<"对方的生命值:"<<b.health<<endl;
                blood(b.health,b.all_health);
            }
            else
                cout<<"对方的生命值:0"<<endl;
            if(a.health>0)
            {

                cout<<"你的生命值:"<<a.health<<endl;
                blood(a.health,a.all_health);
            }
            else
                cout<<"你的生命值:0"<<endl;
            }
        }
        if(c=='3')
        {
            if(a.skill_3==0)
                cout<<"技能暂未解锁...."<<endl;
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
                cout<<"你的武器扫过四周，扬起尘土和疾风，紧接着直冲对方要害……"<<endl;
                cout<<"同时，对方也向你发动了攻击……"<<endl<<endl;
                Sleep(1000);
                Gailv=rand()%100+1;
                if(Gailv<=40)
                {
                    bd=aatk*3-b.defend;
                    cout<<"这一击造成了严重伤害!你此次攻击的伤害已经大幅提升"<<endl<<endl;
                }
                else
                {
                    bd=(aatk*8)/10-b.defend;
                    cout<<"看来这一下没能发挥最大威力……"<<endl<<endl;
                }
                if(bd<=0)
                    bd=rand()%3+1;
                a.health-=ad;
                b.health-=bd;
                cout<<"对方生命值 -"<<bd<<endl;
                cout<<"你的生命值 -"<<ad<<endl<<endl;
                if(b.health>0)
                {
                    cout<<"对方的生命值:"<<b.health<<endl;
                 blood(b.health,b.all_health);
                }
                else
                    cout<<"对方的生命值:0"<<endl;
                if(a.health>0)
                {
                     cout<<"你的生命值:"<<a.health<<endl;
                     blood(a.health,a.all_health);
                }
                else
                    cout<<"你的生命值:0"<<endl;
            }
        }
        if(c=='4')
        {
            if(a.skill_4==0)
                cout<<"技能暂未解锁...."<<endl;
            else
            {
                if(time_4<=0)
                    continue;
                time_4--;
                aatk=rand()%12+a.attack-6;
                batk=( b.attack*(rand()%4+8) )/10;
                cout<<"你使出了习自原野的凶猛刺砍术，向对方发起了连续的攻击……"<<endl<<endl<<endl;
                Sleep(1000);
                int i,j,t,aa; i=rand()%3+3;
                for(j=1;j<=i;++j)
                {
                    cout<<"第"<<j<<"次攻击,";
                    t=rand()%10+1;
                    if(t>=8)
                    {
                        cout<<"势大力足，杀伤性十分强悍"<<endl<<endl;
                        aa=aatk;
                    }
                    else if(t>=4 && t<=7)
                    {
                        cout<<"威力可观，杀伤性不容小觑"<<endl<<endl;
                        aa=(aatk*7)/10;
                    }
                    else
                    {
                        cout<<"攻势稍逊，杀伤性稍有欠缺"<<endl<<endl;
                        aa=(aatk*4)/10;
                    }
                    bd=aa-b.defend;
                    if(bd<=0)
                        bd=rand()%3+1;
                    b.health-=bd;
                    cout<<"对方生命值 -"<<bd<<endl<<endl;
                    if(b.health>0)
                    {
                        cout<<"对方的生命值:"<<b.health<<endl;
                        blood(b.health,b.all_health);
                    }
                    else
                        cout<<"对方的生命值:0"<<endl;
                    getch();
                    cout<<endl<<endl<<endl;
                }
                if(b.health>0)
                {
                    cout<<"同时，对方也发动了反击……"<<endl<<endl;
                    ad=b.attack-a.defend;
                    if(ad<=0)
                        ad=rand()%3+1;
                    a.health-=ad;
                    Sleep(1000);
                    cout<<"你的生命值 -"<<ad<<endl<<endl;
                    if(a.health>0)
                    {

                        cout<<"你的生命值:"<<a.health<<endl;
                        blood(a.health,a.all_health);
                    }
                    else
                        cout<<"你的生命值:0"<<endl;
                }
            }
        }
        if(c=='5')
        {
            if(a.skill_5==0)
              cout<<"技能暂未解锁...."<<endl;
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
                cout<<"你使用了习自海滨的特殊急救方法，生命值恢复了"<<hpadd<<endl<<endl;
                cout<<"与此同时，对方此次的攻击被你化解……"<<endl<<endl;
                Sleep(1000);
                batk=( b.attack*(rand()%4+8) )/10;
                ad=batk-a.defend;
                if(ad<=0)
                    ad=rand()%3+1;

                if(b.health>0)
                {

                    cout<<endl<<"对方的生命值:"<<b.health<<endl;
                    blood(b.health,b.all_health);
                }
                else
                    cout<<"对方的生命值:0"<<endl;
                if(a.health>0)
                {
                    cout<<"你的生命值:"<<a.health<<endl;
                    blood(a.health,a.all_health);
                }
                else
                    cout<<"你的生命值:0"<<endl;
            }
        }
        if((c=='H' || c=='h') && kasmon.use_heal==0)
        {
            system("cls");
            if(bp.bandage!=0)
                cout<<"按B使用绷带"<<endl<<endl;
            if(bp.herb!=0)
                cout<<"按H使用药草"<<endl<<endl;
            if(bp.potion!=0)
                cout<<"按P使用麦卡林精华"<<endl<<endl;
            char cc;
            getthree(cc,'b','h','p');
            if(cc=='b')
            {
                kasmon.health+=BANDAGE_H;
                cout<<"生命值恢复"<<BANDAGE_H<<endl;
                bp.bandage-=1;
            }
            else if(cc=='h')
            {
                kasmon.health+=HERB_H;
                cout<<"生命值恢复"<<HERB_H<<endl;
                bp.herb-=1;
            }
            else
            {
                kasmon.health+=POTION_H;
                cout<<"生命值恢复"<<POTION_H<<endl;
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

        cout<<endl<<"最终，你赢得了战斗！"<<endl<<endl;
        if(num!=9&&num!=8)
        PlaySound("空白.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
    }
    else if(a.health<=0)
    {
        cout<<endl<<"你在战斗中死掉了。"<<endl<<endl;
        getch();
        system("pause");
        system("cls");
        cout<<"正如人们所说的一样，去往南境的一路上充满着危险。"<<endl<<endl;
        getch();
        cout<<"真正勇敢的冒险者不会永远保持跌倒的状态。"<<endl<<endl;
        getch();
        cout<<"也许，还有机会？"<<endl<<endl;
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
           cout<<"这一天结束了，你花掉了"<<cost<<"金币的杂费，还剩"<<bp.coins<<"金币。"<<endl<<endl;
           system("pause");
           system("cls");
       }
    else
        {
            cout<<"很遗憾，你的金币不足以应对接下来的行程所需的开销，南境之旅到此结束。"<<endl<<endl;
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
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"南 境 孤 旅";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 108);cout<<" "<<endl;color(16);
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
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"南 境 孤 旅";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 109 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |  102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                   ";color(2);cout<<"'space'    开始征程";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 103 | 32);cout<<" ";color(16);cout<<"                   ";color(4);cout<<"'h'         帮  助 ";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                   ";color(3);cout<<"'esc'      退出游戏";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
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
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |102 | 32);cout<<" ";color(16);cout<<"                       ";color(6);cout<<"南 境 孤 旅";color(16);cout<<"                       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 109 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 |  102 | 64);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"      ";color(2);cout<<"  制 作 者 名 单              ";color(16);cout<<"                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102| 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);;
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       Nic";color(16);cout<<"                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 103 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       红莲的箭矢 ";color(16);cout<<"             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                          ";color(4);cout<<"       i-kun";color(16);cout<<"                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                 感  谢  您  的  游  玩                  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<" ";color(16);cout<<"                                                         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102  | 32);cout<<" "<<endl;color(16);
    cout<<"                            ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 102 | 32);cout<<"                                                           "<<endl;color(16);
}
void help()
{
color(16);
cout<<" 你即将步入另一个迥异的时空，一个年轻冒险者的生命和意志会暂时交到你手中，由你来导演这一切。"<<endl;
cout<<" 故事中，你需要扮演好这名冒险者，直到达到这趟旅程的终点。但有一些需要注意的事情："<<endl<<endl;
color(6);cout<<" 1. 金币"<<endl<<endl;color(11);
cout<<" 人们用金币来进行交易。你起初有一些金币，但故事中你的金币会因为种种事情而发生或增加或减少的变化，很大程度上取决于你的行动。要注意，通常情况下旅程中的每一天结束时都要支付10~20个金币作为旅程中吃住行一类的杂费，如果有一天你没有足够的金币可以支付，这趟旅程也将不得不终止。"<<endl;
cout<<" "<<endl;
color(6);cout<<" 2. 疗伤品"<<endl;color(11);
cout<<" 疗伤品包括绷带、药草与麦卡林精华，是一类十分重要的物品。建议玩家在背包中常备，并且在住宿时及时用它们来恢复生命值。"<<endl;
cout<<" "<<endl;
color(6);cout<<" 3. 技能"<<endl;color(11);
cout<<" 在战斗中，除了普通攻击以外，玩家还可以选择使用多个技能，但这些技能都需要一定事件的触发。错过特定的事件会导致无法学习这项技能。"<<endl;
cout<<" "<<endl;
color(6);cout<<" 4. 游戏中商店里一些看似无用的东西可能有十分重要的用处。"<<endl;color(16);
color(6);cout<<" 5. 游戏中剧情停顿时按任意键可继续，但当有连续的人物对话时不需要按键，对话会自动进行。"<<endl;color(16);
cout<<" "<<endl;
cout<<" 祝你游戏愉快！  (按空格返回主页面)  "<<endl;
}
int main()
{
    menu();
    PlaySound("启动界面及帮助界面.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
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
        PlaySound("初始剧情.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"-----------------------------------------------"<<endl<<endl;//插入 初始剧情
        cout<<"当海风跨越岛屿边缘为埃默路斯的大陆送来咸湿的气氛，当蝶与蜂欢快地萦绕在埃默路斯的每一株花丛中，当暖阳在埃默路斯这镶嵌着白色云丝的淡蓝天空默不作声时，每个在这里居住的人们都在欢笑中明白了——"<<endl<<endl;
        cout<<"这将是埃默路斯的又一春。"<<endl<<endl;
        cout<<"我踏过羊肠小径，从镇中央的高塔向我的家走去。在从木梯中下段一跃而下，跳到最近才重焕生机的草地上之前，我一直藏身于高塔顶端的小棚中。这个小棚颇有树屋之感，我常来此处度过消遣的时光，每当置身于此，不知是否也是身处小镇最高处的缘故，我时常会觉得自己化作了一只鸟，只身在此处栖息。"<<endl<<endl;
        cout<<"走入酒馆之间的小巷后，我与酒馆老板的儿子利托打过招呼。利托曾是埃默路斯大陆的保卫者——西南远征兵团的一员，兵团在过去的十几年内成功抵御了来犯的科斯塔姆并反攻征服了敌人，除此之外还有更多事迹，这一切都让兵团显得如此神圣与伟大。加入兵团在我眼中是一件充满荣光的事情，虽一直是心之所向，可父亲总说时候未到。"<<endl<<endl;
        cout<<"当我到达了家门，母亲得知了我已经归家，叫我在餐桌旁坐下，等待热腾腾的鸭汤和烤肉卷饼上桌，当然，还有很多其他的食物。"<<endl<<endl;
        cout<<"父亲和弟弟已经在餐桌坐好，看上去，他们已经等候我多时。我露出一个自然的微笑，坐在了向窗的位置，那是我的常座。"<<endl<<endl;
        cout<<"这是一年当中最丰盛的一餐，我的家人和我都知道原因——"<<endl<<endl;
        cout<<"在今天，我终于成年。"<<endl<<endl;
        cout<<"我们在欢声笑语间酒足饭饱，这时，父亲想要让我跟随他到院落中去，我虽然同意，但还是不禁好奇地发问。父亲说，他要赠予我成年之礼。"<<endl<<endl;
        cout<<endl; system("pause");
        system("cls");
        cout<<"一匹银灰高头大马在院落中央安静地伫立，当我看到它时，心中的兴奋之情难以克制。它的鬃毛虽是灰色，却在暖阳映照下散发出闪亮的光泽，就像华贵的科斯塔姆地毯，仅为王室和贵族们所用。父亲告诉我，它来自西方的拉普洛草原，是最健壮、最迅捷，也是最难以驯服的品种。而昨天，父亲花重金买下这匹马，在今天，将它赠给了我。"<<endl<<endl;
        cout<<"“卡斯蒙，我知道你喜欢在平原上策马奔驰，所以，它从现在起是属于你的。”"<<endl<<endl;
        cout<<"我向父亲表达了最深挚的谢意，同时也为它起好了名字——舒莱特，在埃默路斯通用语中是“闪电”之意。"<<endl<<endl;
        cout<<"我迫不及待地骑上它，向小镇南边前行，因为南边有埃默路斯最开阔的平原，我已经无法等待去验证它是否真如闪电一般迅捷而强力。直到真切地感受到它带给我的速度，过去我所骑过的骏马无一不黯然失色：在如闪电一般的银灰鬃毛之上，我仿佛也一同化作了平原上的闪电，在风驰电掣中忘记了一切，徒有向前奔驰。"<<endl<<endl;
        cout<<"当黄昏渐近，橙黄的日光在整个平原上倾洒。在丘陵顶峰，我暂时策马停下，望向一望无际的南边。"<<endl<<endl;
        cout<<"恰在此时，我的脑海映出一番昔日的映像。"<<endl<<endl;
        getch(); system("cls");
        cout<<"那是十几年前，当我和弟弟仍只是稚嫩顽童，我常带他在镇里的各处随意地奔跑欢叫。一个并不晴朗的日子，我们奔跑着离开家门，穿过卡露花园的小径，又穿过中心集市，在不知不觉间，我们来到了镇的南部边缘。在这里，那些熙熙攘攘的人群已不再能见到，看不到买卖蔬果的妇人与商贩，也看不到在墙边聊天的年轻小伙子。唯一能见到的，是蜿蜒流经镇南的埃默路斯河，河两侧厚重而陡峭的崖壁，以及一位独自坐在悬崖草地中的老者。"<<endl<<endl;
        cout<<"那还是我与弟弟第一次来到镇里相对陌生的地界，在这般些许冷清的氛围之中，我们往常的活泼与躁动消失了不少，取而代之并填在心中的是对这里独特景象的疑惑。不过，对于两个天真而时常充满好奇的孩子而言，这又是萌生探索欲的绝佳时刻。我与弟弟只相视一眼，心照不宣地一同走向那座连通镇南与更南之处唯一的桥梁。"<<endl<<endl;
        cout<<"“孩子们，你们要到哪里去？”"<<endl<<endl;
        cout<<"当我们向桥头迈出脚步，老人叫住了我们。我们来到了他的身边，把我们的心思告诉了他。"<<endl<<endl;
        cout<<"“孩子们，无论怎样在镇中玩耍嬉闹都不为过，只是，千万不要随意出镇，尤其——是跨越这座桥梁，到达更远的南方。”"<<endl<<endl;
        cout<<"霎时，我们的好奇被更大地激起，忙问为什么。老人笑了几声，扶了扶被微风吹动的胡须。"<<endl<<endl;
        cout<<"“南境，那里常有奇异之事发生，有令人恐惧的生物，有令人困惑的谜团。去往那里的人们，还没有一位得以归还。”"<<endl<<endl;
        cout<<"纵使稚嫩的我们对这些话只能似懂非懂，但老人已成功使我们主动却步。我记得那一天，我们用天真的眼神望着南方的地平线，想象着那里究竟会有着怎样的故事。"<<endl<<endl;
        getch(); system("cls");
        cout<<"不知不觉间，夕阳已全然沉入远方的山脉，星辰开始在暮空闪烁。我调转马头向镇中赶去。"<<endl<<endl;
        cout<<"儿时的记忆已然模糊，但与那位老者相逢的场景却如此清晰。回忆漫上心头，在那之后，我也屡次在不经意间听镇上的人谈起南境，尽管仅能听闻稀疏的语句，但人们对南境的种种情感，亦或畏惧，亦或不解，又或甚至是些许向往，无一不被我捕捉。我问过父亲，但他总是倾向于闭口不言，即使是唯有的少许时候，他也仅仅止于告诉我和弟弟那里是不安之地，似乎充满了未知与危险。"<<endl<<endl;
        cout<<"平原虽广，我心中却涌入了几分惆怅。那是源于在我心中一直潜藏的一个梦，一个冲动，一个向往，它来自于年轻男子天生的探索欲和冒险欲。到今天，这个向往在我成年之时终于达到了顶峰，这种感觉几乎要从我的心中溢出——"<<endl<<endl;
        getch();
        cout<<"我决心踏上去往南境的探索之旅。"<<endl<<endl<<endl<<endl<<endl;
        getch(); system("pause"); system("cls");
        system("cls");
        cout<<"第1天"<<endl<<endl<<endl;
        getch();
        system("cls");
        PlaySound("强盗出场.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"“把你的行囊拿过来，我就可以放你过去！”"<<endl<<endl;//插入 强盗出场
        getch();
        cout<<"你能想到的是，路途上一定会历经艰辛；但你没想到，就在跨越埃默路斯河的仅仅几小时后，就有一名手持匕首的棕衣男子挡在了狭窄的山路上。"<<endl<<endl;
        getch();
        cout<<"卡斯蒙：“伙计，需要什么可以对我说，如果我能帮助你我一定会尽力帮忙，你不必这样。”"<<endl<<endl;
        Sleep(1000);
        cout<<"强盗：“你在搞笑吗？那我现在说，我需要你的行囊，你赶快把它给我吧？不然就别想从这条路过去！”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“行囊对我很重要。”"<<endl<<endl;
        Sleep(1000);
        cout<<"强盗：“对我也很重要！废话少说！快拿过来，不然，看看我这刀子锋不锋利！”"<<endl<<endl<<endl;
        getch();
        Enemy robber={90,90,4,1};
        cout<<"F键          开始战斗"<<endl;
        cout<<"R键          放弃抵抗"<<endl;
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
            PlaySound("空白.wav",NULL,SND_FILENAME | SND_ASYNC);
            cout<<"看着强盗手中的武器，你放弃了抵抗，被他劫走了"<<ROB<<"枚金币。"<<endl<<endl;
            getch();
            cout<<"强盗：小子，看你这么乖的份上就少抢你点，现在你可以走了！"<<endl<<endl<<endl;
            getch();
            cout<<"B键           查看背包"<<endl;
            cout<<"其他          继续"<<endl;
            ch=getch();
            if(ch=='b')
            {
                    system("cls");
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch,27);
            }
            }while(ch=='b');
        }
        daycost();
        cout<<"第2天"<<endl<<endl<<endl;
        getch();
        system("cls");
        cout<<"卡斯蒙：也许前一天的经历只是一个开始，去南边的路不会一帆风顺。"<<endl<<endl;
        getch();
        cout<<"幸运的是，经过一天的路程，你已经来到克劳思城郊附近。一家商店就在不远处。"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("克劳思城郊与克劳思城.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"克劳思城郊 简易商店"<<endl<<endl<<endl;//插入 克劳思城郊与克劳思城
        getch();
        cout<<"店主：“唷，有客人来了！欢迎光临我的商店。您看上去像是旅行者，没错吧？”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“是的，我从北部的埃默路斯中心镇来的。”"<<endl<<endl;
        Sleep(1000);
        if(kasmon.health<100)
        {
            cout<<"店主：“呃……您看上去好像刚刚和别人打过架？您还好吗？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“……没事，摔了一跤而已。”"<<endl<<endl;
            Sleep(1000);
        }
        cout<<"店主：“不管怎么说，虽然这阵子生意有点冷清，但店里还是有点有用的东西的。受伤的话有绷带，要是觉得冷，有烈酒可以暖身，还有其他的一些玩意……随您挑吧！”"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"克劳思城郊 简易商店"<<endl<<endl<<endl;
            cout<<"玛顿酒"<<endl;
            cout<<"价格："<<MARTON_C<<"金币   M键购买"<<endl;
            cout<<"产自玛顿庄园的烈酒，曾经是上流家族中的年轻男士酷爱的酒品。饮用后攻击力增加"
            <<MARTON_A<<"；用其疗伤可恢复"<<MARTON_H<<"生命值。"<<endl<<endl;
            cout<<"绷带"<<endl;
            cout<<"价格："<<BANDAGE_C<<"金币   D键购买"<<endl;
            cout<<"常见的疗伤物品。使用后可恢复"<<BANDAGE_H<<"生命值。"<<endl<<endl;
            cout<<"三明治"<<endl;
            cout<<"价格："<<SANDWICH_C<<"金币   S键购买"<<endl;
            cout<<"虽然不是你常吃的食物，但也许会有别的用途。它的包装纸使它便于携带。"<<endl<<endl;
            cout<<"仿紫宝石项链"<<endl;
            cout<<"价格："<<FAKEPURPLEGEMNECKLACE_C<<"金币   F键购买"<<endl;
            cout<<"很容易看出那不是真正的紫宝石，但这并不代表所有的人都对它没兴趣。"<<endl<<endl<<endl;
            cout<<"查看背包          B  "<<endl;
            cout<<"离开              其他"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 's':
                {
                    if(!cck(SANDWICH_C)) break;
                    bp.sandwich+=1;
                    bp.coins-=SANDWICH_C;
                    cout<<"已购买  三明治x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'm':
                {
                    if(!cck(MARTON_C)) break;
                    bp.marton+=1;
                    bp.coins-=MARTON_C;
                    cout<<"已购买  玛顿酒x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"已购买  绷带x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'f':
                {
                    if(!cck(FAKEPURPLEGEMNECKLACE_C)) break;
                    bp.fakepurplenecklace+=1;
                    bp.coins-=FAKEPURPLEGEMNECKLACE_C;
                    cout<<"已购买  仿紫宝石项链x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='s' || ch2=='m' || ch2=='d' || ch2=='f' || ch2=='b');
        system("cls");
        cout<<"克劳思城郊 郊区旅店"<<endl<<endl<<endl;
        getch();
        cout<<"你来到了一家位于城郊的旅店。虽然这里的房间看上去并不怎么干净宽敞，却总比没有要好。在院落中拴好马后，你便回到了房间。"<<endl<<endl;
        getch();
        cout<<"卡斯蒙：“今晚就在这里过夜吧，”"<<endl<<endl;
        getch();
        PlaySound("夜宿.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        do{
            system("cls");
            cout<<"克劳思城郊 郊区旅店"<<endl<<endl<<endl;//插入 夜宿
            cout<<"此处是栖身之地。在这里你可以使用你从商店带回来的物品。"
            <<endl<<endl<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"这一夜你睡得很安稳，除了夜晚的虫鸣声外，只有月光透过窗户与你作伴。"<<endl<<endl;
        system("pause");
        daycost();
        cout<<"第3天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("克劳思城郊与克劳思城.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"克劳思城 小酒馆"<<endl<<endl<<endl;//插入 克劳思城郊与克劳思城
        getch();
        cout<<"一家装潢比较精致的小酒馆，踏入这里能让身心得到一定的放松。"<<endl<<endl;
        getch();
        cout<<"酒馆老板：嗨！很抱歉今天剩的酒没几种了，昨天有几个哥们到我这儿来痛喝一顿，新酒还没来得及上架。你要来点什么？"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"克劳思城 小酒馆"<<endl<<endl<<endl;
            cout<<"玛顿酒"<<endl;
            cout<<"价格："<<MARTON_C<<"金币   M键购买"<<endl;
            cout<<"产自玛顿庄园的烈酒，曾经是上流家族中的年轻男士酷爱的酒品。饮用后攻击力增加"
            <<MARTON_A<<"；用其疗伤可恢复"<<MARTON_H<<"生命值。"<<endl<<endl;
            cout<<"柠檬酒"<<endl;
            cout<<"价格："<<LEMONA_C<<"金币   L键购买"<<endl;
            cout<<"不知名人士的发明，将特制冰柠檬水与酒精混合在一起调制而成的独特美酒。饮用后攻击力增加"
            <<LEMONA_A<<"；用其疗伤可恢复"<<LEMONA_H<<"生命值。"<<endl<<endl;
            cout<<"布鲁耶蓝晶"<<endl;
            cout<<"价格："<<BRUJE_C<<"金币   R键购买"<<endl;
            cout<<"昂贵而稀有的布鲁耶蓝晶是高贵和神秘的象征，它的调制方法只被极少数人知道。饮用后攻击力增加"
            <<BRUJE_A<<"；用其疗伤可恢复"<<BRUJE_H<<"生命值。"<<endl<<endl<<endl;
            cout<<"查看背包          B  "<<endl;
            cout<<"离开              其他"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'm':
                {
                    if(!cck(MARTON_C)) break;
                    bp.marton+=1;
                    bp.coins-=MARTON_C;
                    cout<<"已购买  玛顿酒x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"已购买  柠檬酒x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'r':
                {
                    if(!cck(BRUJE_C)) break;
                    bp.bruje+=1;
                    bp.coins-=BRUJE_C;
                    cout<<"已购买  布鲁耶蓝晶x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='m' || ch2=='l' || ch2=='r' || ch2=='b');
        cout<<"酒馆老板：“你应该不是这里的人吧？看来我猜得没错。难得这里能有贵客。要知道，这样偏僻贫穷的城镇可不像埃默路斯北部那样的胜地一样吸引游人。就叫我温德斯吧！克劳思的男人们几乎没有一个不认识我，这里的每个人是什么样我也都再清楚不过了，不过对你我还是很陌生的。年轻人，可否知道你此行的最终目的地呢？”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“我要到南境去。”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：（讶异地沉默）"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“您为什么这么惊讶？”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“呃，只是……的确有点不敢相信。要知道，那里是一个非同寻常的地方，去过那里的人没有一个回来过。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“您对南境有了解？”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“也算不上太过了解，我所知道的都是从酒馆的常客们嘴里听来的，据他们讲，那里可是一个不可言说的地方，充斥着谜团和杀机。也不知道年轻人你去那里是为了什么事？”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“我想知道那里究竟是怎样的一个地方，在那里都发生过什么事。”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“是这样啊……那你一定要多加留心。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“我会的，谢谢您。”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“不过，年轻人，我看你身上也没带什么称手的武器啊，这样可不行，你得知道，去南边的路可是很凶险的。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“……您说得对，我想我手上是应该有个家伙，能应对强盗之类的。”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“既然这样，我十分推荐你到城中部的铁器店，老板名叫坎特，和我也是熟人，那里的东西是全城人公认的高质量，不仅有武器，还有防身的护甲，要价也还算合理。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“这样啊，那我明天就过去看看。还要感谢您的指引！”"<<endl<<endl;
        Sleep(1000);
        cout<<"温德斯：“没事！我替坎特揽个客，他下次到我这儿喝酒得多出点价钱，哈哈。”"<<endl<<endl;
        system("pause");
        daycost();
        cout<<"第4天"<<endl<<endl;
        getch();
        system("cls");
        cout<<"克劳思城 铁器店"<<endl<<endl<<endl;
        getch();
        cout<<"坎特：“你好啊，小伙子！”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“你好，我来看件顺手的武器，是酒馆老板温德斯推荐我来这儿的。”"<<endl<<endl;
        Sleep(1000);
        cout<<"坎特：“哈，是温德斯这老家伙，看来他还挺够意思的！不管怎么说，你是来对地方了，这里武器和护甲俱全，而且保证不会在你使用它们时突然断掉或碎掉！看你喜欢哪件？”"<<endl<<endl;
        getch();
        int coinback=0;
        do{
            system("cls");
            cout<<"克劳思城 铁器店"<<endl<<endl<<endl;
            cout<<"【武器】"<<endl<<endl;
            cout<<"短剑"<<endl;
            cout<<"价格："<<DAGGER_C<<"金币   D键购买"<<endl;
            cout<<"外观普通的短剑，据说是刺客的喜好之物。装备后攻击力增加"<<DAGGER_A<<"。"<<endl<<endl;
            cout<<"锯齿铁棍"<<endl;
            cout<<"价格："<<STEELSTICK_C<<"金币   S键购买"<<endl;
            cout<<"带有锯齿的铁棍，看上去威力不小。装备后攻击力增加"<<STEELSTICK_A<<"。"<<endl<<endl<<endl;
            cout<<"【护甲】"<<endl<<endl;
            cout<<"通用盔甲"<<endl;
            cout<<"价格："<<GENERAARMOR_C<<"金币   G键购买"<<endl;
            cout<<"西南远征兵团常规步兵的通用盔甲，能够在战斗中为身体提供有效的防护。装备后防御力增加"
            <<GENERAARMOR_A<<"。"<<endl<<endl;
            cout<<"海洋甲"<<endl;
            cout<<"价格："<<OCEANARMOR_C<<"金币   O键购买"<<endl;
            cout<<"作为一种并不常见的身体甲，海甲的得名是源于最初的一批护甲制造者和实践者常常集中于顾内斯海湾附近。装备后防御力增加"
            <<OCEANARMOR_A<<"。"<<endl<<endl<<endl;
            cout<<"查看背包          B  "<<endl;
            cout<<"离开              其他"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'd':
                {
                    if(!cck(DAGGER_C)) break;
                    if(bp.weapon=="短剑")
                    {
                        cout<<"你已拥有此武器"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.attack+=DAGGER_A;
                    bp.weapon="短剑";
                    bp.weapon_add=DAGGER_A;
                    bp.coins-=DAGGER_C;
                    coinback+=DAGGER_C;
                    cout<<"已购买并装备   短剑"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 's':
                {
                    if(!cck(STEELSTICK_C)) break;
                    if(bp.weapon=="锯齿铁棍")
                    {
                        cout<<"你已拥有此武器"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.attack+=STEELSTICK_A;
                    bp.weapon="锯齿铁棍";
                    bp.weapon_add=STEELSTICK_A;
                    bp.coins-=STEELSTICK_C;
                    coinback+=STEELSTICK_C;
                    cout<<"已购买并装备   锯齿铁棍"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'g':
                {
                    if(!cck(GENERAARMOR_C)) break;
                    if(bp.armor=="通用盔甲")
                    {
                        cout<<"你已拥有此防具"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=GENERAARMOR_A;
                    bp.armor="通用盔甲";
                    bp.armor_add=GENERAARMOR_A;
                    bp.coins-=GENERAARMOR_C;
                    coinback+=GENERAARMOR_C;
                    cout<<"已购买并装备   通用盔甲"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'o':
                {
                    if(!cck(OCEANARMOR_C)) break;
                    if(bp.armor=="海洋甲")
                    {
                        cout<<"你已拥有此防具"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=OCEANARMOR_A;
                    bp.armor="海洋甲";
                    bp.armor_add=OCEANARMOR_A;
                    bp.coins-=OCEANARMOR_C;
                    coinback+=OCEANARMOR_C;
                    cout<<"已购买并装备   海洋甲"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
          }while(ch2=='d' || ch2=='s' || ch2=='g' || ch2=='o' || ch2=='b');
        system("cls");
        if(bp.weapon!="徒手")
        {
            cout<<"[提示] 你领悟到了新技能：【蓄力】"<<endl<<endl;
            cout<<"技能介绍：使用后攻击力提升20%，使用次数3次。"<<endl<<endl;
            kasmon.skill_1=1;
            getch();
            system("cls");
            cout<<"克劳思城 铁器店"<<endl<<endl<<endl;
            cout<<"坎特：“小伙子不用着急离开，我这儿有个差事，不知道你能不能帮我这个忙，如果你帮了我，我就返还你一半这次购物花掉的金币。怎么样？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“听上去不错，不过……差事，是什么差事？”"<<endl<<endl;
            Sleep(1000);
            cout<<"坎特：“是这样的。最近几天我儿子刚好出了城去参加西南远征兵团弓箭兵的选拔，如果选上了也算是实现了他的一个夙愿，但他不在的这几天里就没人能替我到北森林里打猎了。不过我倒是不需要你替我去打猎，只是最近呢，我想搞点野生蘑菇烤着吃，但因为店里还要招呼客人的关系离不开身，"
            <<"所以烦请你到城北边的森林里替我采一点过来。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“这简单，我马上就去。”"<<endl<<endl;
            Sleep(1000);
            cout<<"坎特：“不过你可一定要注意，森林里不只有蘑菇、松鼠和兔子，还有些很危险的动物，比如棕熊！关键时刻你可能还需要和它们搏斗一番，你还愿意帮我这个忙吗？”"<<endl<<endl<<endl;
            Sleep(1000);
            cout<<"Y键          接受"<<endl;
            cout<<"N键          拒绝"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                cout<<"克劳思城 铁器店"<<endl<<endl<<endl;
                cout<<"卡斯蒙：“知道了，我会注意的。”"<<endl<<endl;
                Sleep(1000);
                cout<<"坎特：“你真是个不错的小伙子！那你一定要注意安全！”"<<endl<<endl;
                getch();
                system("cls");
                cout<<"北森林"<<endl<<endl<<endl;
                getch();
                cout<<"你很快来到了北森林。这里弥漫着清新而湿润的空气，但氛围略显黯淡，微弱的阳光穿透树冠照在草地上，令人在神清气爽中感到些许压抑。"<<endl<<endl;
                getch();
                cout<<"你在一些有粗壮树干的树下发现了很多蘑菇，并把它们都装进了背包中。"<<endl<<endl;
                getch();
                PlaySound("北森林 棕熊.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"然而，正当你准备起身离开时，不远处却传来了低沉的叫声。"<<endl<<endl;//插入 北森林 棕熊
                getch();
                cout<<"当你再次抬头，一只棕熊阻拦在了路上。"<<endl<<endl<<endl;
                getch();
                cout<<"按任意键进入战斗..."<<endl<<endl;
                getch();
                system("cls");
                Enemy bear={110,110,18,3};
                fight(kasmon,bear);
                PlaySound("克劳思城郊与克劳思城.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                system("cls");
                cout<<"克劳思城 铁器店"<<endl<<endl<<endl;
                getch();
                cout<<"坎特：“让我瞧瞧……果然是够新鲜的蘑菇！太好了，小伙子，这些金币就返还给你吧！”"<<endl<<endl;
                getch();
                cout<<endl<<"[提示] 你获得了"<<(coinback/2)<<"金币，现有"<<bp.coins<<"金币"<<endl<<endl;
                bp.coins+=(coinback/2);
            }
            else
            {
                cout<<"卡斯蒙：“抱歉，我想我还没有足够的能力应对那些猛兽们，我可能帮不了您这个忙。”"<<endl<<endl;
                Sleep(1000);
                cout<<"坎特：“也好也好，北森林确实很危险，那么小伙子，你就继续旅程吧！”"<<endl<<endl;
            }
        }
        getch();
        system("pause");
        daycost();
        PlaySound("空白.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"第5天"<<endl<<endl;//此处无音乐
        getch();
        system("cls");
        cout<<"离开克劳思的路上"<<endl<<endl<<endl;
        getch();
        cout<<"路边靠墙蹲坐着的一个乞丐吸引了你的注意，同时，他也注意到了你，向你缓缓走来。"<<endl<<endl;
        getch();
        cout<<"乞丐：“年轻人，您身上还有吃的吗？请给我一些吧，我很饿。”"<<endl<<endl;
        if(bp.sandwich==0)
        {
            Sleep(1000);
            cout<<"卡斯蒙：“可我身上也没有什么吃的……”"<<endl<<endl;
            Sleep(1000);
            cout<<"乞丐：“……好吧，祝您好运。”"<<endl<<endl;
            getch();
            cout<<"乞丐转身离开了。"<<endl<<endl;
        }
        else
        {
            getch();
            cout<<"你想起来自己身上还带着一块三明治。"<<endl<<endl<<endl;
            Sleep(1000);
            cout<<endl<<"Y键          将三明治给乞丐"<<endl;
            cout<<"N键          拒绝"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                beggar=1;
                bp.sandwich-=1;
                cout<<"乞丐：“真是太谢谢你了！”"<<endl<<endl;
                getch();
                cout<<"乞丐接过三明治，大口享用了起来，三明治很快就不见了踪影。"<<endl<<endl;
                getch();
                cout<<"乞丐：“年轻人，感谢你让我暂时挺过了饥饿。”"<<endl<<endl;
                Sleep(1000);
                cout<<"卡斯蒙：“我这里还有点金币，要不我再……”"<<endl<<endl;
                Sleep(1000);
                cout<<"乞丐：“不用了，不用再麻烦您了，我知道现在每个人都有自己的难处，您的金币也自有您的用途，您应该是正在旅行吧？那您还是留下它们吧。”"<<endl<<endl;
                Sleep(1000);
                cout<<"卡斯蒙：“对，我要到南境去。”"<<endl<<endl;
                Sleep(1000);
                cout<<"乞丐：（短暂地沉默）"<<endl<<endl;
                Sleep(1000);
                cout<<"乞丐：“年轻人，这么长时间也没有人施舍我，尽管我并不怪他们。但是既然您说您要到南境去，我想给您一点报答。这本书我装在布包里有一段时间了，我想今天终于能把它交给真正需要它的人了，请收下它吧。”"<<endl<<endl;
                Sleep(1000);
                cout<<"乞丐转身离开了。"<<endl<<endl<<endl;
                getch();
                cout<<"[提示] 你获得了1本书籍"<<endl<<endl;
                bp.book+=1;
            }
            else
            {
                cout<<"卡斯蒙：“可我身上也没有什么吃的……”"<<endl<<endl;
                Sleep(1000);
                cout<<"乞丐：“……好吧，祝您好运。”"<<endl<<endl;
                getch();
                cout<<"乞丐转身离开了。"<<endl<<endl;
            }
        }
        getch();
        system("cls");
        PlaySound("夜宿.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"桥边旅店"<<endl<<endl<<endl;//插入 夜宿
        getch();
        cout<<"日暮时分，你来到了一处河流附近，在跨越河流的桥边恰好有一个旅店，你决定在这里夜宿。"<<endl<<endl;
        getch();
        cout<<"听旅店里的客人说，过了这座桥，就可以到达一个比较繁荣的小镇。"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"桥边旅店"<<endl<<endl<<endl;
            cout<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"接下来的几天里，你不断赶路，并没有什么特别的事发生。"<<endl<<endl;
        getch();
        srand((unsigned int)time(NULL));
        int cost3;
        cost3=3*( rand()%11+10 );
        if((bp.coins-=cost3)>=0)
           {
               cout<<"在这几天里，你花掉了"<<cost3<<"金币的杂费，还剩"<<bp.coins<<"金币。"<<endl<<endl;
               system("pause");
               system("cls");
           }
        else
            {
                cout<<"很遗憾，你的金币不足以应对接下来的行程所需的开销，南境之旅到此结束。"<<endl<<endl;
                getch();
                exit(0);
            }
        system("cls");
        cout<<"第9天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("门温镇.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"门温镇"<<endl<<endl<<endl;//插入 门温镇
        getch();
        cout<<"你纵马前行，穿过一个有一丝气派的门庭，来到了这座小镇中。小镇中人来人往，比克劳思城的人看上去要多一些。这里有鹅卵石铺成的路面，各式各样的店铺和摊贩。"<<endl<<endl;
        getch();
        cout<<"在弧形的道路上拐了一个弯，你来到一个豪华住宅区附近。这些楼装修别具一格，和你之前看到的住宅大不一样。"<<endl<<endl;
        getch();
        cout<<"正在观赏之时，几声女人的惨叫却传入你的耳中。"<<endl<<endl;
        getch();
        cout<<"“还叫？看你能挣扎到什么时候！”"<<endl<<endl;
        Sleep(1000);
        cout<<"“真是够了，哈哈！”"<<endl<<endl;
        Sleep(1000);
        cout<<"“啊！……”"<<endl<<endl;
        getch();
        cout<<"一个女佣穿着的女人正在被几个穿着奇装异服的人围在中间，看上去正在被无礼对待。你开始考虑要不要出手帮忙。"<<endl<<endl<<endl;
        getch();
        cout<<"Y键          出手"<<endl;
        cout<<"N键          离开"<<endl<<endl;
        gettwo(ch,'y','n');
        system("cls");
        if(ch=='y')
        {
            maid=1;
            cout<<"卡斯蒙：“停下！”"<<endl<<endl;
            getch();
            PlaySound("门温镇 帮派.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"他们转过头来盯着你。"<<endl<<endl;
            getch();
            cout<<"帮派成员1：“小子，你**从哪来的？从哪来的滚哪去！”"<<endl<<endl;
            Sleep(1000);
            cout<<"帮派成员2：“我说，你知不知道我们是谁？你不知道我们混这儿的？”"<<endl<<endl;
            Sleep(1000);
            cout<<"帮派成员3：“识相点赶紧滚，想被捅的话我帮你！”"<<endl<<endl;
            Sleep(1000);
            cout<<"帮派成员1：“哎，怎么还不快滚？难道非得我把你捅几刀才知道怎么做吗？”"<<endl<<endl<<endl;
            getch();
            cout<<"按任意键进入战斗..."<<endl<<endl;
            getch();
            Enemy gangster1={100,100,12,0};
            system("cls");
            fight(kasmon,gangster1,8);
            system("cls");
            cout<<"帮派成员2：“没想到你**还有点本事？看我**怎么弄你……”"<<endl<<endl<<endl;//此处继续 门温镇 帮派
            getch();
            cout<<"按任意键进入战斗..."<<endl<<endl;
            getch();
            Enemy gangster2={100,100,15,0};
            system("cls");
            fight(kasmon,gangster2,8);
            system("cls");
             PlaySound("门温镇.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"其余的帮派成员见状纷纷逃散，只有女佣还站在原地。"<<endl<<endl;
            getch();
            cout<<"女佣：“真是……太感谢你了！我真不知道该说些什么……”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“没事了就好，他们是干什么的？”"<<endl<<endl;
            Sleep(1000);
            cout<<"女佣：“他们是当地的帮派，可以说无恶不作，但普通人见了他们也不敢做什么，毕竟他们的势力已经连结到这里的贵族了。我刚刚从一个贵族家庭解约想回我家乡去，他们就把我堵在了路上，然后……”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“不管怎么说，现在已经安全了，就不要再回想了。之后还是得注意啊。”"<<endl<<endl;
            Sleep(1000);
            cout<<"女佣：“我想我得报答你点什么……这里有一瓶酒，是我刚从原来干活的地方偷的，但我也不喝酒，偷酒就是想报复一下之前经常欺负我的那家人……这酒还是给你吧！还有一些钱，也是我偷的，也送你一部分吧！”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“……那，谢谢你的好意。”"<<endl<<endl;
            Sleep(1000);
            cout<<"女佣：“此地不宜久留，你肯定已经被他们盯上了，以后在门温镇你得小心些。我也得赶快出镇了，再见了！”"<<endl<<endl;
            bp.lemona+=1;
            bp.coins+=MAIDFEEDBACK;
            getch();
            cout<<endl<<"[提示] 你获得了1瓶柠檬酒和"<<MAIDFEEDBACK<<"个金币"<<endl<<endl;
        }
        else
        {
            cout<<"为了不卷入麻烦，你调转马头，向别处走去。"<<endl<<endl;
        }
        getch();
        system("cls");
        PlaySound("门温镇.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"不知为什么，那些气派的豪华住宅再也不能带给你视觉上美的享受。"<<endl<<endl;//插入 门温镇
        getch();
        cout<<"你在镇里大概逛了一圈，最后在镇中心找到了今晚落脚的地方。"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"门温镇 中心旅店"<<endl<<endl;
            cout<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"第10天"<<endl<<endl;
        getch();
        system("cls");
        cout<<"这一天，你打算去这里的商店看看。"<<endl<<endl;
        getch();
        cout<<"你踏入一家商店，但老板并没有像克劳思城郊那家店一样热情地招呼你。你便自己在货架上挑选。"<<endl<<endl;
        getch();
        system("cls");
        do{
            system("cls");
            cout<<"门温镇 商店"<<endl<<endl<<endl;
            cout<<"柠檬酒"<<endl;
            cout<<"价格："<<LEMONA_C<<"金币   L键购买"<<endl;
            cout<<"不知名人士的发明，将特制冰柠檬水与酒精混合在一起调制而成的独特美酒。饮用后攻击力增加"
            <<LEMONA_A<<"；用其疗伤可恢复"<<LEMONA_H<<"生命值。"<<endl<<endl;
            cout<<"绷带"<<endl;
            cout<<"价格："<<BANDAGE_C<<"金币   D键购买"<<endl;
            cout<<"常见的疗伤物品。使用后可恢复"<<BANDAGE_H<<"生命值。"<<endl<<endl;
            cout<<"药草"<<endl;
            cout<<"价格："<<HERB_C<<"金币   H键购买"<<endl;
            cout<<"这类药草采自偏僻而危险的山地，对各类外伤有着神奇的治疗作用，可以让伤处有效而快速地恢复。使用后可恢复"<<HERB_H<<"生命值。"<<endl<<endl<<endl;
            cout<<"查看背包          B  "<<endl;
            cout<<"离开              其他"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"已购买  柠檬酒x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"已购买  绷带x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'h':
                {
                    if(!cck(HERB_C)) break;
                    bp.herb+=1;
                    bp.coins-=HERB_C;
                    cout<<"已购买  药草x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='l' || ch2=='d' || ch2=='h' || ch2=='b');
        system("cls");
        cout<<"夜幕又快要降临了。这一天你没有碰到什么特别的事情，也没有和谁说过几句话，只是觉得这里虽然更加繁华，但总有一种压抑的氛围。"<<endl<<endl;
        getch();
        system("pause");
        daycost();
         PlaySound("空白.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"第11天"<<endl<<endl;//此处无音乐
        getch();
        system("cls");
        cout<<"你上马出镇，继续向南边行进。"<<endl<<endl;
        getch();
        cout<<"“来看一看吧！你感兴趣的东西都可以从这里得到！也可以把你感兴趣的东西卖给我！”"<<endl<<endl;
        getch();
        cout<<"吆喝声使你停下了脚步。你转头看去，一个商人模样的人正站在路边的石头上坐着。你向他走近。"<<endl<<endl;
        getch();
        cout<<"流浪贸易者：“嘿，你有什么想买的或者想卖的吗？”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“我这里……可以卖的东西？”"<<endl<<endl;
        Sleep(1000);
        cout<<"流浪贸易者：“随便什么都可以拿出来谈谈！比如酒啊、食品啊什么的，不过在我这要卖这些东西的话并不会得到很高的价钱，你知道的，我主要是帮助那些急需用钱的人们，这附近有很多这样的人。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“这样啊……那还是算了吧。”"<<endl<<endl;
        Sleep(1000);
        cout<<"流浪贸易者：“不过也不全是这个价！物以稀为贵，我最近很希望得到一个可以让我的小女儿开心的东西，看她开心我就也开心了！所以如果你出这种物品给我的话我可能会给你很高的价。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“让您女儿开心的东西？”"<<endl<<endl;
        if(bp.fakepurplenecklace>0)
        {
            getch();
            cout<<"你想到你身上有条仿紫宝石项链，也许可以让小女孩开心。是否把它卖给流浪贸易者？"<<endl<<endl<<endl;
            cout<<"Y键          卖出"<<endl;
            cout<<"N键          不卖"<<endl<<endl;
            gettwo(ch,'y','n');
            system("cls");
            if(ch=='y')
            {
                cout<<"流浪贸易者：“哇……这东西，对我女儿来说可真是好东西！镶着漂亮的紫色宝石的项链，我保证她能戴在脖子上好久！”"<<endl<<endl;
                Sleep(1000);
                cout<<"流浪贸易者：“很好，我会用很多金币向你购买这条项链。”"<<endl<<endl;
                bp.fakepurplenecklace-=1;
                bp.coins+=FAKEPURPLEGEMNECKLACE_S;
                getch();
                cout<<endl<<"[提示] 你卖出了1条仿紫宝石项链，获得了"<<FAKEPURPLEGEMNECKLACE_S<<"个金币"<<endl<<endl;
            }
            else
            {
                Sleep(1000);
                cout<<"卡斯蒙：“我想我身上没有什么值得卖的东西了。”"<<endl<<endl;
                Sleep(1000);
                cout<<"流浪贸易者：“好吧，祝你有愉快的一天！”"<<endl<<endl;
            }
        }
        else
        {
            Sleep(1000);
            cout<<"卡斯蒙：“我想我身上没有什么值得卖的东西了。”"<<endl<<endl;
            Sleep(1000);
            cout<<"流浪贸易者：“”好吧，祝你有愉快的一天！"<<endl<<endl;
        }
        getch();
        system("pause");
        daycost();
        cout<<"第12天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("卡朋镇.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"“救……救命！……”"<<endl<<endl;//插入 卡朋镇
        getch();
        cout<<"正当你骑马行在狭窄的土路上时，你听到了从前面拐角处传来的呼救声。你放慢速度，注意力集中在拐角处。"<<endl<<endl;
        getch();
        cout<<"一个矮个子男人从拐角现身，他的右臂正在流血，正一边扶着右臂一边使劲跑动着。见到你后，他露出仿佛见到救星的神色。"<<endl<<endl;
        getch();
        cout<<"“先生……有绷带吗？情况很紧急！……”"<<endl<<endl;
        getch();
        if(bp.bandage>0)
        {
            cout<<endl<<"Y键          给他绷带"<<endl;
            cout<<"N键          拒绝"<<endl<<endl;
            gettwo(ch,'y','n');
            if(ch=='y')
            {
                banout=1;
                system("cls");
                cout<<"[提示] 你给出了1个绷带"<<endl<<endl;
                bp.bandage-=1;
                getch();
                cout<<"你协助对方止血并用绷带替他包扎。"<<endl<<endl;
                getch();
                cout<<"卡斯蒙：“怎么会伤成这样？”"<<endl<<endl;
                Sleep(1000);
                cout<<"受伤男子：“马……马匪，都是他们弄的！”"<<endl<<endl;
                Sleep(1000);
                cout<<"卡斯蒙：“您别着急，伤口已经处理好了，您慢慢说。”"<<endl<<endl;
                Sleep(1000);
                cout<<"受伤男子：“西部丘陵的马匪平时总是在我们卡朋镇周边惹是生非、劫掠作恶，有时甚至冲到镇里去，镇政府都没能把这事解决好！这不今天他们又来了，一大票人直接冲到我家，一看我家没什么好抢的，就想冲我妹妹下手。我拼命阻拦，他们就用马刀追着我砍，还好我妹妹跑到安全的地方了！现在估计他们不会再追来了……”"<<endl<<endl;
                Sleep(1000);
                cout<<"卡斯蒙：“真是混蛋！”"<<endl<<endl;
                Sleep(1000);
                cout<<"受伤男子：“唉！让我在这躺会吧，一会我还得回家去，把他们搞得一团糟的东西收拾干净……不管怎么样，希望我妹妹没事！”"<<endl<<endl;
            }
            else
            {
                cout<<"卡斯蒙：“抱歉，我这里没有……”"<<endl<<endl;
                getch();
                cout<<"受伤男子捂着伤处匆匆离开了。"<<endl<<endl;
            }
        }
        else
        {
            cout<<"卡斯蒙：“抱歉，我这里没有……”"<<endl<<endl;
            getch();
            cout<<"受伤男子捂着伤处匆匆离开了。"<<endl<<endl;
        }
        getch();
        system("cls");
        cout<<"夜色越来越近，你继续行路，路上遇见的那个受伤男子给你留下了很深的印象。"<<endl<<endl;
        getch();
        cout<<"你找到一家郊区旅店，并打算今晚就在这里过夜。"<<endl<<endl;
        getch();
        if(banout==1)
        {
            cout<<"卡斯蒙：“卡朋镇……到底是什么样的一个地方呢？”"<<endl<<endl;
            getch();
        }
        system("pause");
        daycost();
        cout<<"第13天"<<endl<<endl;
        getch();
        system("cls");
        cout<<"卡朋镇"<<endl<<endl<<endl;
        getch();
        cout<<"和前面你所见都不相同，映入眼帘的，是一个苍凉而萧瑟的小镇。"<<endl<<endl;
        getch();
        cout<<"你策马加快速度，在两侧的一座座小屋中穿行而过，直到来到一处集市，人烟才多了起来。人们在集市中围在一起，却并不是围在集市的摊位前，而是围在墙旁，同时还在议论纷纷。这吸引了你的注意，你下马前去探看。"<<endl<<endl;
        getch();
        cout<<"“西部丘陵的马匪们已经祸害我们这么长时间，我们无能的镇政府却什么也管不了，难道就要一直这样下去吗？是时候做出我们自己的选择了！”"<<endl<<endl;
        getch();
        cout<<"你发现一个强壮的中年男人正站在一边，用底气十足的喊声号召着人们。"<<endl<<endl;
        getch();
        cout<<"“加入丘陵巡逻队，救卡朋镇于水深火热之中吧！只要你有男人的责任和担当，就请不要坐视不管，无动于衷！”"<<endl<<endl;
        getch();
        cout<<"你得知，人们是在围观一个告示，告示上呼吁卡朋镇中的青年和壮年男子加入丘陵巡逻队，抵抗时常来犯的西部丘陵马匪。"<<endl<<endl;
        getch();
        cout<<"“要加入的，就请过来站在我右手的铁剑旁边！”"<<endl<<endl;
        getch();
        cout<<"你向号召者看去，却发现此时他的右手边只有十几个青壮年男子。"<<endl<<endl;
        getch();
        cout<<"“哎，你知不知道，马匪们最近更加嚣张了！竟然开始做奸淫之事，做不成就要乱刀砍人！”"<<endl<<endl;
        Sleep(1000);
        cout<<"“我当然听说了，但又有什么办法？咱们镇里能出头的就这么十几个了！”"<<endl<<endl;
        getch();
        cout<<"听着人群中传出的对话，那个受伤男子的样子又在你的眼前闪过。"<<endl<<endl;
        getch();
        cout<<"“人数还不够，这样的话我们是无法对付他们的！还有没有人要加入？”"<<endl<<endl;
        getch();
        cout<<"看着号召者紧缩的眉头，一种无名的力量驱使你开始了心理斗争，你所目睹和耳闻的一切都让你有了加入巡逻队的念头，但你毕竟本不是卡朋镇的人。"<<endl<<endl;
        getch();
        cout<<endl<<"F键          加入丘陵巡逻队"<<endl;
        cout<<"N键          不加入"<<endl<<endl;
        gettwo(ch,'f','n');
        system("cls");
        if(ch=='f')
        {
            teamfight=1;
            cout<<"卡斯蒙：“让我加入！”"<<endl<<endl;
            getch();
            cout<<"在众目睽睽之下，你走向号召者的右侧，与卡朋镇的青壮年男子并肩站在了一起。让你惊喜的是，你的举动似乎带动了更多合适的人选加入巡逻队，渐渐地，站在你身旁的人越来越多。"<<endl<<endl;
            getch();
            cout<<"号召者：“那好！明天我们就向西部丘陵进发，让我们这些勇士并肩作战，把那些蟑螂赶出我们的家园！”"<<endl<<endl;
            getch();
            cout<<"（欢呼声）"<<endl<<endl;
            getch();
            system("cls");
            cout<<"卡朋镇 战前操练场"<<endl<<endl<<endl;
            getch();
            cout<<"下午，你和众人一同来到镇西北边的一处空地，将这里作为战前操练场，训练基本的战斗技能并讨论对付马匪时的战术。"<<endl<<endl;
            getch();
            cout<<"值得一提的是，巡逻队的领袖为所有人都发配了武器，而你得到的是一柄虽有锈迹但锋利不减的弯刀。"<<endl<<endl;
            getch();
            cout<<endl<<"[提示] 你得到了一把弯刀"<<endl<<endl;
            getch();
            if(bp.weapon=="徒手")
                kasmon.attack+=MACHETE_A;
            else if(bp.weapon=="短剑")
                kasmon.attack=kasmon.attack-DAGGER_A+MACHETE_A;
            else
                kasmon.attack=kasmon.attack-STEELSTICK_A+MACHETE_A;
            bp.weapon_add=MACHETE_A;
            bp.weapon="弯刀";
            cout<<"夕阳渐渐沉入远方的山中，操练直到最后一丝余光从操练场上消失时才算结束。你逐渐熟悉了手里的弯刀，在操练中掌握了新的战斗技能，并对明天的战斗感到十分激动。"<<endl<<endl;
            getch();
            system("cls");
            cout<<"[提示] 你学会了新技能：【尘 风】"<<endl<<endl;
            cout<<"技能介绍：出击后，有40%的几率打出3倍于普通攻击的伤害，但有60%的几率仅打出普通攻击80%的伤害。使用次数"<<SKILL3PP<<"次。"<<endl<<endl;
            kasmon.skill_3=1;
            getch();
            system("cls");
            cout<<"卡朋镇 中心防具商店"<<endl<<endl<<endl;
            getch();
            cout<<"傍晚，为了能在明天更好地投入战斗，你与几个同队的兄弟一同来到卡朋镇中心的防具商店，听他们说，这里有克劳思城的铁器店所没有的东西。"<<endl<<endl;
            getch();
            do{

                system("cls");
                cout<<"卡朋镇 中心防具商店"<<endl<<endl<<endl;
                cout<<"通用盔甲"<<endl;
                cout<<"价格："<<GENERAARMOR_C<<"金币   G键购买"<<endl;
                cout<<"西南远征兵团常规步兵的通用盔甲，能够在战斗中为身体提供有效的防护。装备后防御力增加"
                <<GENERAARMOR_A<<"。"<<endl<<endl;
                cout<<"兰斯顿链甲"<<endl;
                cout<<"价格："<<LANSTONARMOR_C<<"金币   L键购买"<<endl;
                cout<<"由声名远扬的将领兰斯顿设计，比一般的链甲更厚更重。装备后防御力增加"
                <<LANSTONARMOR_A<<"。"<<endl<<endl;
                cout<<"十字甲"<<endl;
                cout<<"价格："<<CROSSARMOR_C<<"金币   C键购买"<<endl;
                cout<<"得名于其头盔上的十字图案，是重装步兵的标配，适合身强体壮的人穿着。装备后防御力增加"
                <<CROSSARMOR_A<<"。"<<endl<<endl<<endl;
                cout<<"查看背包          B  "<<endl;
                cout<<"离开              其他"<<endl<<endl<<endl<<endl;
                ch2=getch();
                system("cls");
                switch(ch2)
                {
                case 'g':
                    {
                        if(!cck(GENERAARMOR_C)) break;
                        if(bp.armor=="通用盔甲")
                        {
                            cout<<"你已拥有此护甲"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=GENERAARMOR_A;
                        bp.armor="通用盔甲";
                        bp.armor_add=GENERAARMOR_A;
                        bp.coins-=GENERAARMOR_C;
                        cout<<"已购买并装备   通用盔甲"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'l':
                    {
                        if(!cck(LANSTONARMOR_C)) break;
                        if(bp.armor=="兰斯顿链甲")
                        {
                            cout<<"你已拥有此护甲"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=LANSTONARMOR_A;
                        bp.armor="兰斯顿链甲";
                        bp.armor_add=LANSTONARMOR_A;
                        bp.coins-=LANSTONARMOR_C;
                        cout<<"已购买并装备   兰斯顿链甲"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'c':
                    {
                        if(!cck(CROSSARMOR_C)) break;
                        if(bp.armor=="十字甲")
                        {
                            cout<<"你已拥有此护甲"<<endl<<endl;
                            system("pause");
                            break;
                        }
                        kasmon.defend=CROSSARMOR_A;
                        bp.armor="十字甲";
                        bp.armor_add=CROSSARMOR_A;
                        bp.coins-=CROSSARMOR_C;
                        cout<<"已购买并装备   十字甲"<<endl<<endl;
                        system("pause");
                        break;
                    }
                case 'b':
                    {
                        bp.show();
                        cout<<"esc          返回"<<endl;
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
            cout<<"你最终没有走到号召者的铁剑旁，没有加入巡逻队的队伍。也许这是对的选择？你明白，自己最终的目标依然是南境。"<<endl<<endl;
            getch();
        }
        system("cls");
        PlaySound("夜宿.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"夜幕时分，你找到了一家镇北的破旧旅馆，看来今晚就要在这里过夜了。"<<endl<<endl;//插入 夜宿
        getch();
        system("cls");
        do{
            system("cls");
            cout<<"卡朋镇的破旧旅馆"<<endl<<endl;
            cout<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"第14天"<<endl<<endl;
        getch();
        system("cls");
        if(teamfight==1)
        {
            PlaySound("卡朋镇西部丘陵 马匪（连续放）.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"西部丘陵"<<endl<<endl<<endl;//插入 卡朋镇西部丘陵 马匪
            getch();
            cout<<"淡蓝的苍穹之下，辽阔的西部丘陵之上，丘陵巡逻队的全体成员在山顶集合。"<<endl<<endl;
            getch();
            cout<<"巡逻队领袖：“兄弟们！今天，就是那些马贼们滚蛋的时候！准备好和他们大干一场了吗？”"<<endl<<endl;
            Sleep(1000);
            cout<<"（高呼声）"<<endl<<endl;
            Sleep(1000);
            cout<<"“今天，这些混蛋们一个个都得把血溅在卡朋镇的西部！”"<<endl<<endl;
            Sleep(1000);
            cout<<"“看！山脚下！”"<<endl<<endl;
            getch();
            cout<<"你顺着山脚下看去，只见一伙人纵马向你们冲来，人数不多。"<<endl<<endl;
            getch();
            cout<<"巡逻队领袖：“这些就是马匪的先锋了！他们一定知道我们是镇里选出来干他们的人。好了勇士们！记住我们昨天的操练，大家团结起来，首先应对自己遇到的敌人，战胜他后再去帮助其他人！”"<<endl<<endl;
            getch();
            cout<<"大家振臂高呼，四周充满了战意，你的血脉此刻已经偾张，准备好要和马匪决一死战。而就在下一秒，马匪先锋们已经近乎冲到了面前，其中一个正是冲你而来，所有人咆哮着迎了上去，你也不在例外……"<<endl<<endl;
            getch();
            cout<<endl<<"按任意键进入战斗..."<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegangpioneer={110,22,3};
            fight(kasmon,horsegangpioneer,9);
            cout<<"（欢呼声）"<<endl<<endl;
            getch();
            cout<<"马匪先锋已经被你们全数歼灭，大家士气高涨，欢呼声此起彼伏。然而没多久，大堆的人马便出现在了山脚下。"<<endl<<endl;
            getch();
            cout<<"巡逻队领袖：“勇士们！我们的战斗才刚刚开始！这些混蛋才是他们的主力！握紧你们手中的武器，让我们不战不休吧！”"<<endl<<endl;
            getch();
            cout<<"一个身穿绿色皮甲的马匪向你的正面凶猛地冲来……"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang1={130,130,26,3};
            fight(kasmon,horsegang1,9);
            cout<<"解决掉他后，你的弯刀上已经染尽了鲜血，但它还需要继续挥动，因为就在你右前方，一个头裹黑巾的马匪刚刚杀掉了一个你的兄弟，现在又调转马头向你袭来……"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang2={140,140,20,10};
            fight(kasmon,horsegang2,9);
            cout<<"黑巾马匪从马上摔了下去，倒地毙命，你消耗了一些体力，但战斗还没有结束，你察觉到身后的动静，迅速地闪开了一击，躲过了一个骑灰马的马匪的疾速一刀……"<<endl<<endl;
            getch();
            system("cls");
            Enemy horsegang3={135,135,30,2};
            fight(kasmon,horsegang3,9);
            PlaySound("卡朋镇.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"风掠过丘陵，吹动山顶的荒草，撩起你的衣袖。尽管镇中有不少人倒下，但遍布四周的马匪尸体，足以让残存的人们发出震耳欲聋的高呼。"<<endl<<endl;//插入 卡朋镇
            getch();
            cout<<"你知道，这一战，你们胜利了。"<<endl<<endl;
            getch();
            cout<<"回到镇中时，你们受到了镇中居民的夹道欢迎，他们称赞你们是最神勇的战士。而站在人群中的一个女孩与你相视一眼，令你印象深刻。"<<endl<<endl;
            getch();
            cout<<"镇政府被你们的表现所震撼，为所有凯旋归来的人奖励了一些金币。"<<endl<<endl;
            getch();
            cout<<endl<<"[提示] 你获得了"<<REWARD<<"金币"<<endl<<endl;
            bp.coins+=REWARD;
        }
        else
        {
            cout<<"你在破旧的旅馆待了一天。你知道今天是丘陵巡逻队出征的日子，你在心底默默祈望他们能够获得胜利。"<<endl<<endl;
        }
        getch();
        system("pause");
        daycost();
        cout<<"第15天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("卡朋镇 库雅.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"今天是离开的日子了。";//插入 卡朋镇 库雅
        if(teamfight==1)
            cout<<"在先前，你已经与一同浴血奋战过的兄弟们逐一道别，他们对你寄予了最真挚的祝福。";
        cout<<endl<<endl;
        getch();
        cout<<"你上马，离开旅馆，向镇外行去。"<<endl<<endl;
        getch();
        if(teamfight==1)
        {
            cout<<"可就在你没走几步之时，你发现，那个昨日曾与你相视的女孩此时正站在路边，向你缓缓走来。"<<endl<<endl;
            getch();
            cout<<"你翻身下马，来到她的面前。"<<endl<<endl;
            getch();
            cout<<"卡斯蒙：“你好啊，姑娘。”"<<endl<<endl;
            Sleep(1000);
            cout<<"库雅：“你好，我叫库雅。”"<<endl<<endl;
            getch();
            cout<<"她向你伸出手来，你与她握了手。"<<endl<<endl;
            getch();
            cout<<"库雅：“卡朋镇一直以来都被马匪骚扰，谢谢你们为卡朋镇而战。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“我也只是希望，人们能生活得更安宁一些，不管是在哪里。”"<<endl<<endl;
            Sleep(1000);
            if(banout==1)
            {
                cout<<"库雅：“也谢谢你，帮了我哥哥。”"<<endl<<endl;
                Sleep(1000);
                cout<<"卡斯蒙：“你哥哥？”"<<endl<<endl;
                Sleep(1000);
                cout<<"库雅：“对啊，他被马匪砍伤，是你给了他绷带，并帮他包扎。他都告诉我了，包括你的穿着，我一眼就能看出你不是这个镇的人。”"<<endl<<endl;
                Sleep(1000);
            }
            else
            {
                cout<<"库雅：“从你的衣着来看，你应该不是这个镇的人吧？”"<<endl<<endl;
                Sleep(1000);
            }
            cout<<"卡斯蒙：“是的，我旅居此地，原本来自埃默路斯中心镇。”"<<endl<<endl;
            Sleep(1000);
            cout<<"库雅：“一个不属于这里的人，却能为了这里居民的安宁挺身而出，我真的很感激你……”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“可能这才是我正确的选择吧？哈哈。不过，我的主要目的地一直是从这里再往南的地方。”"<<endl<<endl;
            Sleep(1000);
            cout<<"库雅：“你知道吗？有时我也想离开破落的卡朋镇，独自踏上冒险的旅程……不过，现在看来还不是时候，家人还很需要我。”"<<endl<<endl;
            Sleep(1000);
            cout<<"你看着她，没有说话。"<<endl<<endl;
            getch();
            cout<<"库雅：“我知道你要离开了，我想送你件东西，请你收下它吧。”"<<endl<<endl;
            Sleep(1000);
            cout<<endl<<"[提示] 你获得1朵紫蓝色鸢尾"<<endl<<endl;
            bp.iris+=1;
            getch();
            cout<<"库雅：“这是我最喜欢的花，每到春天都可以在镇南边的花园里找到。你就当作纪念吧。”"<<endl<<endl;
            getch();
            if(bp.fakepurplenecklace>0)
            {

                cout<<"你露出微笑，从背包中掏出一串项链，递给了她。"<<endl<<endl;
                getch();
                cout<<"卡斯蒙：“那，我也把这个给你吧，就当作是我的告别礼了。”"<<endl<<endl;
                bp.fakepurplenecklace-=1;
                cout<<endl<<"[提示] 你给出了1个仿紫宝石项链"<<endl<<endl;
            }
            else
            {
                cout<<"你向她露出微笑，表达了谢意，作了最后的道别。"<<endl<<endl;
            }
        }
        getch();
        system("cls");
        cout<<"你上了马，策马加鞭向镇外飞驰，直朝更远的南方……"<<endl<<endl;
        getch();
        system("pause");
        daycost();
        cout<<"第16天"<<endl<<endl;
        getch();
        system("cls");
        cout<<"这一天，你一直赶路，白天没发生什么特别的事，你只是察觉到四周的地貌与自己的家乡越来越不同了。"<<endl<<endl;
        getch();
        cout<<"夜晚，你寻找着附近的落脚之处，只找到一家豪华旅店。"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("夜宿.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"豪华旅店"<<endl<<endl<<endl;//插入 夜宿
        getch();
        cout<<"你走入豪华旅店，这家旅店的装修比之前你所见到的都要更加高档。三两贵族正在里面开酒会。"<<endl<<endl;
        getch();
        cout<<"他们的对话被你所听见，其中一个贵族明天要路过前方靠西部的大平原，而另一个贵族则要带领自己的家人到前方靠东部的海滨寨去，准备出海。"<<endl<<endl;
        getch();
        cout<<"由于你的穿着与他们显得格格不入，为了避免遭到多余的眼神，你快速回到了自己所挑选的次等住间。令你感到欣慰的是它的价格并没有多么昂贵。"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"豪华旅店"<<endl<<endl<<endl;
            cout<<"此处是栖身之地。在这里你可以使用你从商店带回来的物品。"
            <<endl<<endl<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"第17天"<<endl<<endl;
        getch();
        system("cls");
        cout<<"你策马继续行路，一段时间后，眼前出现了两条岔路。路旁的指示牌上写着，一条通往西南方的大平原，另一条则通往东南方的海滨寨。接下来要走哪条路？看来你需要做一个选择。"<<endl<<endl;
        getch();
        cout<<endl<<"P键          去往大平原"<<endl;
        cout<<"S键          去往海滨寨"<<endl<<endl;
        gettwo(ch,'p','s');
        system("cls");
        if(ch=='p')
        {
            PlaySound("大平原.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"大平原"<<endl<<endl<<endl;//插入 大平原
            getch();
            cout<<"苍翠的原野上野花绽放，云从上空缓缓飘过，时不时挡住阳光，为大地留下一片阴影。"<<endl<<endl;
            getch();
            cout<<"大平原比埃默路斯中心镇南部的原野更加辽阔，你快马加鞭让胯下的灰马疾驰起来，尽情地享受奔驰的快感。"<<endl<<endl;
            getch();
            cout<<"卡斯蒙：“很久没有这样飞驰过了……”"<<endl<<endl;
            getch();
            cout<<"你想到这趟孤旅启程的初衷，不由得对前方更加期待。你立于飞马之背，尽情地吼叫着，让前方与你更加接近。"<<endl<<endl;
            getch();
            cout<<"过了一会，你来到一片野花之海。你勒紧马绳停了下来，翻身下马，任凭自己躺在花海中，出神地望着天空，而你的灰马则在一旁低头吃着青草。"<<endl<<endl;
            getch();
            cout<<"可就在这时，几声猛兽的低吼却将你的注意力掠夺而去。你起身，发觉两只黑狮已然从远处逼近，它们的眼睛透着野性，已经将你和你的灰马锁定。"<<endl<<endl;
            getch();
            cout<<"为了彻底除掉危险源，与上马逃脱相比，你决定与它们一战。你抽出弯刀，它发出锋利的锐响。"<<endl<<endl;
            getch();
            cout<<endl<<"按任意键进入战斗..."<<endl<<endl;
            getch();
            system("cls");
            cout<<"大平原"<<endl<<endl<<endl;
            cout<<"正当你准备对冲上来的黑狮挥刀劈砍时，两道迅疾的黑影从你斜后方闪向前方，击中了两只黑狮。在短短的几秒钟内，两只黑狮应声倒地，看上去已经毙命。"<<endl<<endl;
            getch();
            cout<<"你定睛一看，原来是两根箭矢，在几乎同一时刻，正中两只黑狮的眼睛。"<<endl<<endl;
            getch();
            cout<<"你向后看去。在你转身的同时，一个低沉浑厚的声音响起："<<endl<<endl;
            getch();
            cout<<"“箭头涂了毒，见效还真是快。”"<<endl<<endl;
            getch();
            cout<<"那是一个穿着皮甲的男人，手持一把大弓，箭矢背在身后。"<<endl<<endl;
            getch();
            cout<<"猎人：“不凡的黑狮之毛，又可以给我今晚添上几瓶好酒。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“谢谢您救了我。”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“在这样广袤的平原上不存在‘谢’这个字，因为这里一般不会有会说人类语言的生物，只有豹子、羚羊和猛虎，运气好时能碰到稀有的黑狮。说说吧，你为什么会到这儿来？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“我要去这里再往南的地方。”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“这里再往南？你说的是哪里？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“一个叫作南境的地方。”"<<endl<<endl;
            getch();
            cout<<"猎人听了，露出浅笑，默默地从黑狮的眼中拔出锋利的箭矢。"<<endl<<endl;
            getch();
            cout<<"猎人：“想听听我的故事吗？”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“我年轻时为西南远征兵团的荣耀与威严所战斗的那十五年，是我一生中最值得回忆与自豪的经历。在这十五年里，兵团除了击退并征服前来侵略的科斯塔姆，还有许多说不尽的独属于埃默路斯的辉煌。”"<<endl<<endl;
            Sleep(1000);
            cout<<"你静等片刻，可他并没说出更多。"<<endl<<endl;
            getch();
            cout<<"卡斯蒙：“这就是……您要讲的全部？”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“哈哈，不说这些了，不论如何，都是已经过去的时光了。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“好吧。”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“不过，既然你说你的目的地是更远的南方，我有个问题要问你。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“什么？”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“你的刀用得怎么样？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“说实话，不怎么好，但也会一些。”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“看样子，你的头脑中需要再装一些更凶猛的刀战技术，要知道，南方可是一个很危险的地域。而这个我能帮你实现。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“您的意思是，您肯教我？”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“没错。不过，不是无偿的，你最终都得给我点报酬。你看，我看上去虽然并不是个坏家伙，而且还有着辉煌的人生经历，但现在还不是要为了几瓶好酒在大平原上转来转去吗？哈哈。所以，怎么样？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“只要是能提升我的作战技术的东西，我都一定要学习。那，您要什么样的报酬？”"<<endl<<endl;
            Sleep(1000);
            cout<<"猎人：“你有两个选择。一种是给我"<<HUNTER<<"个金币，这样我就能连喝好几天的上等布鲁耶蓝晶酒了；另一种选择是，我给你这张地图，你顺着地图的标识从这里再往西走，树木会越来越多，直到你走进一片充满荆棘的树林，大概在这个画叉的地方有一棵巨树，那是先前的一个盗贼家族藏赃的地方。树下埋着一颗橙色钻石，你只要去把这颗钻石挖出来给我就可以了，不过要小心，那颗巨树的不远处有一个野蛮人聚集地，但愿你不会碰上他们。怎样？你选哪个？"<<endl<<endl;
            getch();
            cout<<endl<<"C键          给猎人金币"<<endl;
            cout<<"F键          去找橙色钻石"<<endl<<endl;
            gettwo(ch2,'c','f');
            system("cls");
            if(ch2=='f' || bp.coins<HUNTER)
            {
                if(ch2=='c')
                {
                    cout<<"[提示] 你没有足够的金币可以给猎人"<<endl<<endl;
                    getch();
                }
                cout<<"你决定去寻找橙色钻石。猎人承诺会在不远处矮山脚下的临时小木屋中等待你的归来。"<<endl<<endl;
                getch();
                system("cls");
                PlaySound("荆棘暗林.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"荆棘暗林"<<endl<<endl<<endl;//插入 荆棘暗林
                getch();
                cout<<"你来到了猎人所说的树林中，这里的树木树冠浓密，日光被遮挡了很多，四下一片幽暗的气氛。"<<endl<<endl;
                getch();
                cout<<"你突然感到右腿一阵刺痛，低头一看才发现，自己被灌木丛上的荆棘划到了。"<<endl<<endl;
                getch();
                cout<<"有了地图的帮助，巨树并不难找，在一番行走之后你最终来到了巨树前，抽出弯刀，一下一下地挖着泥土。"<<endl<<endl;
                getch();
                cout<<"终于，你的弯刀碰到了一个硬物。你刨开更多的泥土，橙色的光泽显露了出来，这证明那个硬物并不是普通的石头，正是你想要寻获的东西。可就在这时，你的身后却传来一阵粗重的脚步声。"<<endl<<endl;
                getch();
                cout<<"你还来不及挖出整颗钻石，那个脚步声的制造者就已经拿着一根石棒向你冲了过来……"<<endl<<endl;
                getch();
                cout<<endl<<"按任意键进入战斗..."<<endl<<endl;
                getch();
                Enemy barbarian={140,140,35,15};
                system("cls");
                fight(kasmon,barbarian,2);
                system("cls");
                PlaySound("大平原.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
                cout<<"大平原"<<endl<<endl<<endl;//插入 大平原
                cout<<"你在临时小木屋中重新见到了猎人，将那颗橙色钻石递给了他，他欣喜地接过它，把它捧在手中，爱不释手。"<<endl<<endl;
                getch();
                cout<<"猎人：“太棒了！今天遇到你简直是好事一桩！那么，我现在就教你我十五年的战斗经历凝结而成的精华，一种十分凶猛而使敌人防不胜防的杀敌之术！”"<<endl<<endl;
                getch();
                cout<<endl<<"[提示] 你学会了新技能：【原野刺砍术】"<<endl<<endl;
                cout<<"技能介绍：向敌人连续发动3~5次攻击，每次攻击有30%的几率打出与普通攻击相同的伤害，有40%的几率打出普通攻击70%的伤害，有30%的几率打出普通攻击40%的伤害。使用次数"<<SKILL4PP<<"次。"<<endl<<endl;
                kasmon.skill_4=1;
            }
            else if(ch2=='c' && bp.coins>=HUNTER)
            {
                bp.coins-=HUNTER;
                cout<<"猎人：“啊哈，我喜欢你的直接！那么，我现在就教你我十五年的战斗经历凝结而成的精华，一种十分凶猛而使敌人防不胜防的杀敌之术！”"<<endl<<endl;
                getch();
                cout<<endl<<"[提示] 你学会了新技能：【原野刺砍术】"<<endl<<endl;
                cout<<"技能介绍：向敌人连续发动3~5次攻击，每次攻击有30%的几率打出与普通攻击相同的伤害，有40%的几率打出普通攻击70%的伤害，有30%的几率打出普通攻击40%的伤害。使用次数"<<SKILL4PP<<"次。"<<endl<<endl;
                kasmon.skill_4=1;
            }
            getch();
            system("cls");
            cout<<"你与猎人道别，向更远的南方走去。你隐约觉得，自己很快就要到达最终的目的地。"<<endl<<endl;
        }
        else
        {
            PlaySound("海滨寨与试炼.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
            cout<<"海滨寨"<<endl<<endl<<endl;//插入 海滨寨与试炼
            getch();
            cout<<"空气变得潮湿了起来，眺望远方的双目忠诚地告诉你，你已经来到了大海的身旁。"<<endl<<endl;
            getch();
            cout<<"自小在埃默路斯中心镇长大的你，接触更多的是河流中缓缓流淌的清水，也不是没有亲眼见过大海的波涛，只是印象中这样的经历少之又少。"<<endl<<endl;
            getch();
            cout<<"你向一个建在海滨旁的寨子行去。"<<endl<<endl;
            getch();
            cout<<"寨中，弥漫着清新祥和的气氛，孩子们在嬉戏玩闹，准备出海打渔的男人正在船边整理渔网和绳套。"<<endl<<endl;
            getch();
            cout<<"你将马拴在木柱上，走向海边，一个人在海滩上坐了下来。面前的景象让你回想起了埃默路斯的河流，也想起了那座记忆中的桥梁，还有儿时的那位老者。"<<endl<<endl;
            getch();
            cout<<"而如今，你早已跨过河流，越过禁忌，早已开始了属于你自己的旅程。"<<endl<<endl;
            getch();
            cout<<"“年轻人，看上去，你有心事啊？”"<<endl<<endl;
            getch();
            cout<<"你向声源看去，一个年迈的老人也在你身旁坐了下来。他的脸上挂着和蔼的微笑。"<<endl<<endl;
            getch();
            cout<<"你们开始了自然而放松的交谈。你得知，他也是一个渔者，只是不常出海。"<<endl<<endl;
            getch();
            cout<<"老渔者：“年轻人还是好啊，人的强健一到老就一去不复返了……”"<<endl<<endl;
            getch();
            cout<<"你们一同望着远方的海浪，刚才作出海准备的男人们已经在海中扬起了风帆，风势刚刚向好。"<<endl<<endl;
            getch();
            cout<<"老渔者：“可否告诉我，年轻人，你此行是要到哪里去？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“我要到南境去。”"<<endl<<endl;
            getch();
            cout<<"渔者露出浅笑。你向他看去，有些不解。"<<endl<<endl;
            getch();
            cout<<"老渔者：“几十年前，我是西南远征兵团的随行医者。在兵团反攻科斯塔姆的那段辉煌时光里，我挽救了无数兵士，让他们得以重新回到战场。”"<<endl<<endl;
            getch();
            cout<<"你开始试着站在渔者的视角想象这段军旅生涯。"<<endl<<endl;
            getch();
            cout<<"老渔者：“年轻人，既然你要到那里去，一路上很可能会遇到一些危险。这样吧，我教给你一些能够迅速自行疗伤急救的方法，这些都是我从战场上获得的宝贵经验，你有兴趣吗？”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“那太好了！如果您愿意教我，我会感激不尽！”"<<endl<<endl;
            Sleep(1000);
            cout<<"老渔者：“只是，这些办法并不是常见的急救术，因此，要掌握它们，需要你具备特定的体质，以及足够的抗打击能力。在开始教你前，我得对你做一个测试，只有你通过测试，才说明你适合学习这样的迅速疗伤方法。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“好，是什么样的测试？”"<<endl<<endl;
            Sleep(1000);
            cout<<"老渔者：“这样吧，寨子里有一个兵团格斗术的初学者，你和他比试一番，如果你能战胜他，并且只受轻伤，那么我就教给你这个方法。放心，他会用全身甲把自己保护得很好的，只要他没了体力，就算你战胜了他。”"<<endl<<endl;
            Sleep(1000);
            cout<<"卡斯蒙：“来吧！”"<<endl<<endl;
            getch();
            cout<<endl<<"[提示] 要达到要求，战斗开始与结束时你的生命值相差不能大于40。"<<endl<<endl;
            cout<<"按任意键进入战斗..."<<endl<<endl;
            Enemy younglearner={130,130,5,9};
            getch();
            system("cls");
            int hp0=kasmon.health;
            fight(kasmon,younglearner,9);
            int hp1=kasmon.health;
            if( (hp0-hp1)<40 )
            {
                cout<<"老渔者：“好啊，看来你具备学习这套急救方法的条件，那么我现在就把它们教给你。”"<<endl<<endl;
                getch();
                cout<<endl<<"[提示] 你学会了新技能：【特殊急救术】"<<endl<<endl;
                cout<<"技能介绍：使用后恢复20~30生命值。使用次数"<<SKILL5PP<<"次。"<<endl<<endl;
                kasmon.skill_5=1;
            }
            else
            {
                cout<<"老渔者：“唉，看来你还是不具备学习这套急救方法的条件啊……”"<<endl<<endl;
            }
            getch();
            system("cls");
            cout<<"直到夕阳出现在天边，你与老渔者道别，离开了海滨寨，向更远的南方走去。你隐约觉得，很快就要到达最终的目的地。"<<endl<<endl;
        }
        getch();
        system("pause");
        system("cls");
        daycost();
        PlaySound("空白.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"第18天"<<endl<<endl;//此处无音乐
        getch();
        system("cls");
        cout<<"你并没有在这天遇到特殊的人，但你发现四周的环境愈加荒芜，植被愈加稀疏。"<<endl<<endl;
        getch();
        cout<<"你知道，前方是你从没见过的地方，也是你一直所试图到达的地方。"<<endl<<endl;
        getch();
        system("pause");
        system("cls");
        cout<<"第19天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("落日之原.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"落日之原"<<endl<<endl<<endl;//插入 落日之原
        getch();
        cout<<"你来到一片荒原上，这里的肃杀、萧瑟和苍茫是你前所未见的。尽管你四处观望，却总也找不到一个人影。"<<endl<<endl;
        getch();
        cout<<"你让灰马停在一处高地，向远方望去。正当你迷茫之时，一个苍老的声音在身后响起："<<endl<<endl;
        getch();
        cout<<"“跟我来吧。”"<<endl<<endl;
        getch();
        cout<<"是一个坐在马背上的，穿着黑衣的老者。"<<endl<<endl;
        getch();
        cout<<"老者调转马头，你跟随着他，来到了一个营帐前。"<<endl<<endl;
        getch();
        cout<<"“来到这里的勇敢者只有一个目的，而前面就是最终的挑战。谨记，务必做好最充分的准备！”"<<endl<<endl;
        getch();
        cout<<"说完，老者进入了营帐，此后便陷入了沉默，除了指向身后的那一排货架，再无其他动作或话语，无论你如何发问。"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"落日之原 综合商店"<<endl<<endl<<endl;
            cout<<"【酒品】"<<endl<<endl;
            cout<<"柠檬酒"<<endl;
            cout<<"价格："<<LEMONA_C<<"金币   L键购买"<<endl;
            cout<<"不知名人士的发明，将特制冰柠檬水与酒精混合在一起调制而成的独特美酒。饮用后攻击力增加"
            <<LEMONA_A<<"；用其疗伤可恢复"<<LEMONA_H<<"生命值。"<<endl<<endl;
            cout<<"布鲁耶蓝晶"<<endl;
            cout<<"价格："<<BRUJE_C<<"金币   R键购买"<<endl;
            cout<<"昂贵而稀有的布鲁耶蓝晶是高贵和神秘的象征，它的调制方法只被极少数人知道。饮用后攻击力增加"
            <<BRUJE_A<<"；用其疗伤可恢复"<<BRUJE_H<<"生命值。"<<endl<<endl;
            cout<<"【疗伤品】"<<endl<<endl;
            cout<<"绷带"<<endl;
            cout<<"价格："<<BANDAGE_C<<"金币   A键购买"<<endl;
            cout<<"常见的疗伤物品。使用后可恢复"<<BANDAGE_H<<"生命值。"<<endl<<endl;
            cout<<"药草"<<endl;
            cout<<"价格："<<HERB_C<<"金币   H键购买"<<endl;
            cout<<"这类药草采自偏僻而危险的山地，对各类外伤有着神奇的治疗作用，可以让伤处有效而快速地恢复。使用后可恢复"<<HERB_H<<"生命值。"<<endl<<endl;
            cout<<"麦卡林精华"<<endl;
            cout<<"价格："<<POTION_C<<"金币   P键购买"<<endl;
            cout<<"从一种名为麦卡林的矮树的树叶中提取的汁液，口服或外用均可起到明显的愈伤作用，只是并不便宜。使用后可恢复"<<POTION_H<<"生命值。"<<endl<<endl;
            cout<<"【武器】"<<endl<<endl;
            cout<<"标准骑兵剑"<<endl;
            cout<<"价格："<<SWORD_C<<"金币   S键购买"<<endl;
            cout<<"除了军团中的骑兵，不少自诩气质非凡的猎手也喜爱用它来完成狩猎工作。装备后攻击力增加"<<SWORD_A<<"。"<<endl<<endl;
            cout<<"长矛"<<endl;
            cout<<"价格："<<SPEAR_C<<"金币   E键购买"<<endl;
            cout<<"购买它之前需要作妥善全面的考虑，尽管它价格不菲，但具有很强的实战威力与震慑力。装备后攻击力增加"<<SPEAR_A<<"。"<<endl<<endl;
            cout<<"【护甲】"<<endl<<endl;
            cout<<"兰斯顿链甲"<<endl;
            cout<<"价格："<<LANSTONARMOR_C<<"金币   N键购买"<<endl;
            cout<<"由声名远扬的将领兰斯顿设计，比一般的链甲更厚更重。装备后防御力增加"
            <<LANSTONARMOR_A<<"。"<<endl<<endl;
            cout<<"十字甲"<<endl;
            cout<<"价格："<<CROSSARMOR_C<<"金币   C键购买"<<endl;
            cout<<"得名于其头盔上的十字图案，是重装步兵的标配，适合身强体壮的人穿着。装备后防御力增加"
            <<CROSSARMOR_A<<"。"<<endl<<endl;
            cout<<"金刚石战甲"<<endl;
            cout<<"价格："<<DIAMONDARMOR_C<<"金币   D键购买"<<endl;
            cout<<"关键受击部位均由金刚石打造而成，防御效果不言而喻，但除了那些每日在庄园中吃高端宴席的贵族们，不会有多少人能负担得起它的价格的。装备后防御力增加"
            <<DIAMONDARMOR_A<<"。"<<endl<<endl<<endl;
            cout<<"查看背包          B  "<<endl;
            cout<<"离开              其他"<<endl<<endl<<endl<<endl;
            ch2=getch();
            system("cls");
            switch(ch2)
            {
            case 'l':
                {
                    if(!cck(LEMONA_C)) break;
                    bp.lemona+=1;
                    bp.coins-=LEMONA_C;
                    cout<<"已购买  柠檬酒x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'r':
                {
                    if(!cck(BRUJE_C)) break;
                    bp.bruje+=1;
                    bp.coins-=BRUJE_C;
                    cout<<"已购买  布鲁耶蓝晶x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'a':
                {
                    if(!cck(BANDAGE_C)) break;
                    bp.bandage+=1;
                    bp.coins-=BANDAGE_C;
                    cout<<"已购买  绷带x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'h':
                {
                    if(!cck(HERB_C)) break;
                    bp.herb+=1;
                    bp.coins-=HERB_C;
                    cout<<"已购买  药草x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'p':
                {
                    if(!cck(POTION_C)) break;
                    bp.potion+=1;
                    bp.coins-=POTION_C;
                    cout<<"已购买  麦卡林精华x1"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 's':
                {
                    if(!cck(SWORD_C)) break;
                    bp.weapon="标准骑兵剑";
                    bp.weapon_add=SWORD_A;
                    kasmon.attack=KASMONATTACK+SWORD_A;
                    bp.coins-=SWORD_C;
                    cout<<"已购买并装备  标准骑兵剑"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'e':
                {
                    if(!cck(SPEAR_C)) break;
                    bp.weapon="长矛";
                    bp.weapon_add=SPEAR_A;
                    kasmon.attack=KASMONATTACK+SPEAR_A;
                    bp.coins-=SPEAR_C;
                    cout<<"已购买并装备  长矛"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'n':
                {
                    if(!cck(LANSTONARMOR_C)) break;
                    if(bp.armor=="兰斯顿链甲")
                    {
                        cout<<"你已拥有此护甲"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=LANSTONARMOR_A;
                    bp.armor="兰斯顿链甲";
                    bp.armor_add=LANSTONARMOR_A;
                    bp.coins-=LANSTONARMOR_C;
                    cout<<"已购买并装备   兰斯顿链甲"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'c':
                {
                    if(!cck(CROSSARMOR_C)) break;
                    if(bp.armor=="十字甲")
                    {
                        cout<<"你已拥有此护甲"<<endl<<endl;
                        system("pause");
                        break;
                    }
                    kasmon.defend=CROSSARMOR_A;
                    bp.armor="十字甲";
                    bp.armor_add=CROSSARMOR_A;
                    bp.coins-=CROSSARMOR_C;
                    cout<<"已购买并装备   十字甲"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'd':
                {
                    if(!cck(DIAMONDARMOR_C)) break;
                    kasmon.defend=DIAMONDARMOR_A;
                    bp.armor="金刚石战甲";
                    bp.armor_add=DIAMONDARMOR_A;
                    bp.coins-=DIAMONDARMOR_C;
                    cout<<"已购买并装备   金刚石战甲"<<endl<<endl;
                    system("pause");
                    break;
                }
            case 'b':
                {
                    bp.show();
                    cout<<"esc          返回"<<endl;
                    getone(ch3,27);
                    break;
                }
            default:;
            }
        }while(ch2=='l' || ch2=='r' || ch2=='a' || ch2=='h' || ch2=='p' || ch2=='s' || ch2=='e' || ch2=='n' || ch2=='c' || ch2=='d' || ch2=='b');
        system("cls");
        cout<<"整理好背包，你抬起头，却发现神秘的老者甚至连同他身后的货架都已不见了踪影。"<<endl<<endl;
        getch();
        cout<<"当你走出营帐之时，远方的落日将整个荒原都染成了橙红色。你的影子在地面上拉得斜长。"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("夜宿.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"星辰和靛蓝色接管了天幕，一轮巨月从远山身后现身。曾经在遥远的家乡，你不知畅想了多少次这趟孤旅。"<<endl<<endl;//插入 夜宿
        getch();
        cout<<"你从天边挑选了一颗星，用它来寄托你对家人的挂念和祈福，你也知道，家人也一定会用夜空中的一颗星来传达对自己的祝愿。"<<endl<<endl;
        getch();
        do{
            system("cls");
            cout<<"夜空下的露宿"<<endl<<endl<<endl;
            cout<<"按B键打开背包，按S键查看状态栏，Q键继续。"<<endl<<endl;
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
        cout<<"第20天"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("赤灰矛士（BOSS）.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"一座石拱门映入了你的眼帘。从石拱门的背后，出现了一个身穿赤色盔甲、手持灰色矛与盾的矛士。"<<endl<<endl;//插入 赤灰矛士
        getch();
        cout<<"赤灰矛士：“欢迎来到南境的入口，确切地说，是南境的边缘。”"<<endl<<endl;
        getch();
        cout<<"赤灰矛士：“我是南境之门的守卫者，专门将不够格的探索者拦截在南境之外。我知道你等这一刻已经很久了，但你必须战胜我，才能得到走入南境的资格。”"<<endl<<endl;
        getch();
        cout<<"卡斯蒙：“好啊，放马过来吧！”"<<endl<<endl;
        getch();
        cout<<"赤灰矛士：“这是个勇敢者的游戏，不是吗？”"<<endl<<endl;
        getch();
        cout<<endl<<"按任意键进入最终的战斗..."<<endl<<endl;
        getch();
        system("cls");
        Enemy guarder={200,200,40,20};
        fight(kasmon,guarder);
        system("cls");
        cout<<"赤灰矛士：“你……你赢了。”"<<endl<<endl;
        getch();
        cout<<"赤灰矛士靠向一边为你让出路来，石拱门仿佛在向你呼唤……"<<endl<<endl;
        getch();
        system("cls");
        PlaySound("结尾剧情.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
        cout<<"“南境”"<<endl<<endl<<endl;//插入 结尾剧情
        getch();
        cout<<"当你踏入石拱门，纵马奔驰，出乎你的意料，四周的景象并没有像你预想地那样更加荒凉，也没有什么会伤人的怪物在这里游荡，有的只是越来越近的青草、树林和山冈。"<<endl<<endl;
        getch();
        cout<<"不远处有人在等待着你。你将马拴在一棵树旁，向他走了过去。"<<endl<<endl;
        getch();
        cout<<"不知名者：“欢迎来到南境。”"<<endl<<endl;
        getch();
        cout<<"他向你露出难以捉摸的微笑，你有些困惑。"<<endl<<endl;
        getch();
        cout<<"卡斯蒙：“这里真的就是……南境吗？……您是？”"<<endl<<endl;
        Sleep(1000);
        cout<<"不知名者：“让我告诉你这样一件事吧。”"<<endl<<endl;
        getch();
        cout<<"他将你引向更高的山冈顶部，你们踏过青草，风再次掠过身旁。"<<endl<<endl;
        getch();
        cout<<"不知名者：“多年前，在埃默路斯的中心镇，一位年轻人怀着探索欲和一颗勇敢的心，踏上了去往南方的孤身之旅。最后，他并没再回到镇中，于是人们传言，他已经葬身在了南境。但事实上，他通过了西南远征兵团的先锋骑兵的选拔。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“先锋骑兵？就是人们传言中，兵团中那支最神秘的……”"<<endl<<endl;
        Sleep(1000);
        cout<<"不知名者：“是啊。在整个兵团中，他们是最不普通的士兵，不论在时间还是空间角度，总是战斗在最前列，时而担任进入敌军后方的特殊使命，用最特别的方式与敌人作战。与此同时，他们也是最勇敢、最精明、最坚韧的士兵。”"<<endl<<endl;
        Sleep(1000);
        cout<<"不知名者：“不过，成为先锋骑兵也表示着要接受一段全新的生活。成为西南远征兵团重要的一部分，在位于南方的特殊营地长期驻扎与训练，与自己在家乡的亲人和朋友不再有多少联系。正因为如此，人们才会将我淡忘，并将我锁进有关南境的传言。”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“您是说……您就是先锋骑兵的一员？”"<<endl<<endl;
        getch();
        cout<<"他默默地看了你一眼，没有直接回答。"<<endl<<endl;
        getch();
        cout<<"不知名者：“有关南境的传言是必要的。在埃默路斯，没有男人不想成为荣耀的西南远征兵团的一员，更不用说是先锋骑兵，然而先锋骑兵从来没有对众公开的选拔方式。不过，一段描述南境充满危险的传言会在埃默路斯的每个地方流传，吸引真正勇敢和不惧挑战的年轻人踏上通往南境的旅程。当你历经一路的坎坷，直到最终战胜在石拱门前站立着的守卫者，你也就获得了进入南境，或者说加入先锋骑兵的资格。这就是兵团对年轻人的考验，”"<<endl<<endl;
        Sleep(1000);
        cout<<"卡斯蒙：“那么，这就是说……”"<<endl<<endl;
        Sleep(1000);
        cout<<"不知名者：“是的，这就是说，从现在开始，你成为了先锋骑兵的一份子。";
        if(robfight==1)
            cout<<"面对突如其来的危险，你能毫不退让并勇于及时地反击。";
        if(beggar==1)
            cout<<"你慷慨帮助穷困潦倒并饥肠辘辘的人。";
        if(maid==1)
            cout<<"当弱者被欺压，你能挺身而出，锄强扶弱。";
        if(banout==1)
            cout<<"在别人遭受生命的危险时，你怀着仁心毫不犹豫地出手相助。";
        if(teamfight==1)
            cout<<"你能将自己的安全置之度外，拼死捍卫他乡之人的安定。";
        cout<<endl<<endl;
        getch();
        cout<<"不知名者：“那么，准备迎接全新的生命与挑战吧。”"<<endl<<endl;
        getch();
        cout<<"你跟随着不知名者的脚步，他会将你引向军营。你抬起头，飞鸟划过晴空，在远方的天边盘旋，为这趟南境孤旅画上了句号。"<<endl<<endl;
        getch();
        system("cls");
        victory();   //胜利界面
        color(16);
        getch();
        system("pause");
        system("cls");
        color(16);
        maker();//制作者名单
        system("pause");
    }//用于进入游戏的else域结束的花括号
}//main函数结束的花括号
