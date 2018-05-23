#include "dialog.h"
#include "dialog1.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
#include<colordlg.h>
#include<qfile.h>
#include<qtextstream.h>
#include<qdir.h>
#include<qfiledialog.h>
#include<QtUiTools/quiloader.h>

using namespace std;

#define NULL 0
FILE *fp;
QStringList st;
int j=0;
char ech[100][10];
char echattr[100][10];
char Fplace[10],Eplace[10],Tplace[10],TTplace[10],EEplace[10],E1place[10],E2place[10],idplace[10],Splace[10],Snext[10],Ctrue[10],Cfalse[10],Sbegin[10];
char S1next[10],S2next[10],S1begin[10];
char Fcode[50],Ecode[50],Tcode[50],TTcode[50],EEcode[50],E1code[50],E2code[50],idcode[50],Scode[50],Ccode[50];
int temp=1;
int label=0;
int now;
char ch;
char attr[10];
char *keyword[8]={"do","else","if","then","for","while","int","char"};
char *operatornum[4]={"+","-","*","/"};
char *comparison[7]={"<","<=","=",">",">=","!=","=="};
char *interpunction[3]={",",";","."};
char *bracket[4]={"(",")","{","}"};
int S();
int SS();
int E();
int C();
int CC();
int T();
int TT();
int EE();
int F();
char letterprocess(char ch);
char numberprocess(char ch);
char otherprocess(char ch);
QString str2qstr(const string str);
string qstr2str(const QString qstr);
QString change(char *number);

QString str2qstr(string str){
    return QString::fromLocal8Bit(str.c_str());
}

string qstr2str(QString qstr){
    QByteArray cdata = qstr.toLocal8Bit();    return string(cdata);
}

dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::on_pushButton_2_clicked()
{
    st.clear();
    QFile txt("3address.txt");
    txt.open(QFile::WriteOnly|QFile::Truncate);
    txt.close();
    QFile tet("error.txt");
    tet.open(QFile::WriteOnly|QFile::Truncate);
    tet.close();
    if( ui->textEdit->document()->isEmpty())
            {
                QMessageBox::warning(this, tr("警告信息"), tr("输入为空！    请重新输入"));
                return;
            }
    QString qs = ui->textEdit->toPlainText();
    QFile fil("code.txt");
    if(!fil.open(QIODevice::ReadWrite | QIODevice::Text))
    {
         QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);

    }
    QTextStream in(&fil);
    in<<qs<<"\n";
    fil.close();
    char str;
    if ((fp=fopen("code.txt","r"))==NULL)				//读入文件
            QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
        else{
            str =fgetc(fp);
            while (str!=EOF){
                if (isalpha(str)!=0)
                str=letterprocess(str);
                else{
                    if (isdigit(str)!=0)
                        str=numberprocess(str);
                    else
                        str=otherprocess(str);
                }
            };
            for(int m=0;m<j;m++){
             printf("%s",ech[m]);
         }
        ofstream outfile("signtable.txt");
        for (int f = 0; f<sizeof(ech); f++) {
            outfile << "type: "<<ech[f] << std::right << setw(20) << '\t'<<" character: " << std::left << setw(20) << echattr[f] << std::left <<endl;
        }
         printf("\n");
              for(int jj=0;jj<j;jj++){
                  printf("%s",echattr[jj]);
              }
              printf("\n");
             }
        now=0;
        ofstream outfile("grammertable.txt", ios::trunc);
        j=S();
        QFile file1("signtable.txt");
        if(!file1.open(QFile::ReadOnly|QFile::Text)){
            QMessageBox::warning(this,tr("Error"),tr("read file error:%1").arg(file1.errorString()));
        }
        QTextStream in5(&file1);
        ui->textEdit_3->setPlainText(in5.readAll());
        file1.flush();
        file1.close();
        if(j==1)
        {
            QFile *file2=new QFile("grammertable.txt");
            file2->open(QIODevice::ReadOnly|QIODevice::Text);
            QString data1 = QString(file2->readAll());
            ui->textEdit_4->setText(data1);
            QFile *file3=new QFile("3address.txt");
            file3->open(QIODevice::ReadOnly|QIODevice::Text);
            QString data2= QString(file3->readAll());
            ui->textEdit_2->setText(data2);
            QMessageBox::warning(this,"         判断信息         ","true",QMessageBox::Yes);
        }
        else
        {
            ui->textEdit_2->clear();
            ui->textEdit_4->clear();
            for (QStringList::iterator it = st.begin();it != st.end(); ++it) {
            QString search_text = *it;
            QTextDocument *document = ui->textEdit->document();
            bool found = false;
            QTextCursor highlight_cursor(document);
            QTextCursor cursor(document);
            cursor.beginEditBlock();
            QTextCharFormat color_format(highlight_cursor.charFormat());
            color_format.setForeground(Qt::red);
            while (!highlight_cursor.isNull() && !highlight_cursor.atEnd()) {
                highlight_cursor = document->find(search_text, highlight_cursor, QTextDocument::FindWholeWords);
                        if (!highlight_cursor.isNull()) {
                            if(!found)
                                found = true;
                            highlight_cursor.mergeCharFormat(color_format);
                        }
                    }
            cursor.endEditBlock();
            }
            QFile *ioi=new QFile("error.txt");
            ioi->open(QIODevice::ReadOnly|QIODevice::Text);
            QString da= QString(ioi->readAll());
            dialog1=new Dialog1(this);
            QObject::connect(this,SIGNAL(sendData(QString)),dialog1,SLOT(receiveData(QString)));
            emit sendData(da);
            dialog1->setModal(false);
            dialog1->show();
        }
        j=0;
        getch();
}

void dialog::on_pushButton_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("Text Files(*.txt)"));
        if(!path.isEmpty()){
            QFile file(path);
            if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) {
                QMessageBox::warning(this,tr("Read File"),tr("Cannot open file:\n%1").arg(path));
                return;
            }
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
            file.close();
        }
}

void dialog::on_pushButton_3_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("Text Files(*.txt)"));
}


void newtemp(char *ch)                               //t
{
    sprintf(attr,"%d",temp);
    strcpy(ch,"t");					//复制t
    strcat(ch,attr);				//连接attr，第几个register
    temp++;
}

void newlabel(char *ch)                                 //L
{
    sprintf(attr,"%d",label);
    strcpy(ch,"L");
    strcat(ch,attr);
    label++;
}
bool search(char searchstr[],int wordtype){		//匹配特殊字符
    int i;
    switch (wordtype){
    case 1:for(i=0;i<=7;i++){					//case1: keyword
        if(strcmp(keyword[i],searchstr)==0){	//keyword[i]==searchstr，循环检查字符是否匹配
            strcpy(ech[j],keyword[i]);			//后 复制到 前
            strcpy(echattr[j],keyword[i]);
            j++;
            return(true);
        }
           }
    case 2:{for(i=0;i<=3;i++){					//case2: operatornum
        if(strcmp(operatornum[i],searchstr)==0){
            strcpy(ech[j],operatornum[i]);
            strcpy(echattr[j],operatornum[i]);
            j++;
            return(true);
        }
           }
        break;
           }
 case 3: for(i=0;i<=6;i++){						//case3: comparison
        if(strcmp(comparison[i],searchstr)==0){
            strcpy(ech[j],comparison[i]);
            strcpy(echattr[j],comparison[i]);
            j++;
            return(true);
        }
         }
 case 4:for(i=0;i<=2;i++){						//case4: interpuction
        if(strcmp(interpunction[i],searchstr)==0){
            strcpy(ech[j],interpunction[i]);
            strcpy(echattr[j],interpunction[i]);
            j++;
            return(true);
        }
        }
 case 5:for(i=0;i<=3;i++){						//case5: bracket
     if(strcmp(bracket[i],searchstr)==0){
            strcpy(ech[j],bracket[i]);
            strcpy(echattr[j],bracket[i]);
            j++;
            return(true);
        }
        }
    }
         return(false);
}

char letterprocess(char ch){					//字母处理函数
    int i=-1;
    char letter[20];
    while (isalnum(ch)!=0){						//检测字符串是否由字母和数字组成。是=1
    letter[++i]=ch;
    ch=fgetc(fp);								//读字符串
    }
    letter[i+1]='\0';
    if (search(letter,1)){						//如果是keyword
        printf("%s,_\n",letter);
    }
    else{
        printf("IDN,%s\n",letter);
        strcpy(ech[j],"id");
        strcpy(echattr[j],letter);
        j++;
    }
    return(ch);
}


char numberprocess(char ch){               //数字处理程序
    //int len;
    int i=-1;
    char num[20];
    if(ch!='0'){							//10进制
        while (isdigit(ch)!=0||ch=='.' ){				//是否为十进制字符，是=1
            num[++i]=ch;
            ch=fgetc(fp);
            }
        if(isalpha(ch)!=0){					//字符串是否只由字母组成，是=1
            while (isspace(ch) == 0 && ch != ';') {			//字符是否只有为空格、换行，不是=0
                num[++i]=ch;
                ch=fgetc(fp);
                }
            num[i+1]='\0';					//既不是数字，也不是空格、换行符，报错
            printf("illegal identifier：%s\n",num);
            st.append(num);
            ofstream outfile("error.txt", ios::app);
            outfile << "illegal identifier："<<num<< endl;
            goto u;
        }
        int len = strlen(num);
        num[i + 1] = '\0';
        for (int k = 0; k < len; k++) {
            if (num[k] == '.') {
                printf("REAL10,%s\n", num);
                goto INT10;
            }
        }
        printf("INT10,%s\n", num);
        INT10:strcpy(ech[j],"int10");
        strcpy(echattr[j],num);
        j++;
    }
    if(ch=='0'){
        num[++i]=ch;
        ch=fgetc(fp);
        if (ch=='.') {
            num[++i] = ch;
            ch = fgetc(fp);
            while (isdigit(ch) != 0) {
                num[++i] = ch;
                ch = fgetc(fp);
            }
            if (isspace(ch) == 0 ) {
                while (isspace(ch) == 0 && ch != ';') {
                    num[++i] = ch;
                    ch = fgetc(fp);
                }
                num[i + 1] = '\0';
                printf(" 错误的十进制格式：%s\n", num);
                st.append(num);
                ofstream outfile("error.txt", ios::app);
                outfile << "错误的十进制格式："<<num<< endl;
                goto u;
            }
            num[i + 1] = '\0';
            printf("REAL10,%s\n", num);
            strcpy(ech[j], "int10");
            strcpy(echattr[j], num);
            j++;
            ch = fgetc(fp);
            goto u;
        }
        if (isalnum(ch) == 0 && ch != ';') {
            while (isspace(ch) == 0 && ch != ';') {
                num[++i] = ch;
                ch = fgetc(fp);
            }
            num[i + 1] = '\0';
            printf("错误的变量名称：%s\n", num);
            st.append(num);
            ofstream outfile("error.txt", ios::app);
            outfile << "错误的变量名称："<<num<< endl;
            goto u;
        }

        if(ch=='x' || ch=='X'){            //16进制，0x,!!!加0X
            num[++i]=ch;
            ch=fgetc(fp);
            while (isxdigit(ch) != 0 || ch == '.') {		//0x后跟的是是16进制数字
                num[++i] = ch;
                ch = fgetc(fp);
                }
            if (isspace(ch) == 0 && ch != ';') {
                while (isspace(ch) == 0) {
                    num[++i] = ch;
                    ch = fgetc(fp);
                }
                num[i + 1] = '\0';
                printf(" 错误的十六进制格式：%s\n", num);
                st.append(num);
                ofstream outfile("error.txt", ios::app);
                outfile << "错误的十六进制格式："<<num<< endl;
                goto u;
            }
            int Value16 = 0;
            num[i + 1] = '\0';
            sscanf(num, "%x", &Value16);
            for (int k = 0; k < sizeof(num); k++) {
                if (num[k] == '.') {
                    float x = Value16;
                    for (int kk = k + 1; kk < sizeof(num); kk++) {
                        if (num[kk] == '\0')
                            break;
                        else
                            x = x + ((num[kk]-'0') / pow(16, (kk - k)));
                    }
                    printf("REAL16,%f\n", x);
                    goto INT16;
                }
            }
            printf("INT16,%d\n",Value16);	//!!!16进制改成直接输出十进制
            INT16:strcpy(ech[j],"int16");
            strcpy(echattr[j],num);
            j++;
            //len=strlen(num);
            //printf("   Transform to INT10 is:%d\n",HtoD(num,len));

            }
        else{                                             //8进制
            while ((ch>='0'&&ch<='7') || ch == '.'){
                num[++i]=ch;
                ch=fgetc(fp);
                }
            if ((isalpha(ch) != 0 || ch > '7') && ch != ';') {
                while(isspace(ch)==0 && ch != ';'){
                    num[++i]=ch;
                    ch=fgetc(fp);
                    }
                num[i+1]='\0';
                printf("错误的八进制格式 ：%s\n",num);
                st.append(num);
                ofstream outfile("error.txt", ios::app);
                outfile << "错误的八进制格式："<<num<< endl;
                goto u;
                }
            num[i+1]='\0';
            int Value8=0;
            /*for (int k = 1; k < strlen(num); k++) {
                Value8 = Value8 + (num[k]-'0') * pow(8 ,(k-1)); /////
            }*/
            sscanf(num, "%x", &Value8);
            for (int k = 0; k < sizeof(num); k++) {
                if (num[k] == '.') {
                    float x = Value8;
                    for (int kk = k + 1; kk < sizeof(num); kk++) {
                        if (num[kk] == '\0')
                            break;
                        else
                            x = x + ((num[kk] - '0') / pow(8, (kk - k)));
                    }
                    printf("REAL8,%f\n", x);
                    goto INT8;
                }
            }
            printf("INT8,%d\n",Value8);
            INT8:strcpy(ech[j],"int8");
            strcpy(echattr[j],num);
            j++;
            }
        }
    u: return(ch);
}


char otherprocess(char ch){							//除了keyword的其他特殊字符
    int i=-1;
    char other[20];
    if (isspace(ch)!=0){
        ch=fgetc(fp);
        goto u;
    }
    other[++i]=ch;
    ch=fgetc(fp);
    if(other[i]=='<'||other[i]=='='||other[i]=='>'){		//两个字符的 特殊的字符 的处理程序
        while ((isspace(ch)==0)&&(isalnum(ch)==0)){
            other[++i]=ch;
            ch=fgetc(fp);
        }

    }

 other[i+1]='\0';								//特殊字符不作为保留字符
   if (search(other,2))
       printf("%s，_\n",other);
   else
       if (search(other,3))
           printf("%s，_\n",other);
       else
           if (search(other,4))
               printf("%s，_\n",other);
           else
               if(search(other,5))
                   printf("%s，_",other);
               else{
                   printf("不能识别的字符：%s\n",other);
                   st.append(other);
                   ofstream outfile("error.txt", ios::app);
                   outfile << "不能识别的字符："<<other<< endl;
               }
u: return (ch);
}

int S()									//语义分析
{
    int c,s1,ss,e;
    if(strcmp(ech[now],"if")==0)		//now=0，字符是if
    {
        if(label==0)
        {
            newlabel(Snext);
            newlabel(Sbegin);
            strcpy(Cfalse, Snext);
            printf("\n%s:\n",Sbegin);
            ofstream outfile("3address.txt",ios::app);
            outfile<<Sbegin<<":"<<endl;
        }
        else
        {

            strcpy(Cfalse, S1next);
        }

        newlabel(Ctrue);
        strcpy(S1begin, Ctrue);
        now++;
        c=C();
        if(c==0)
        {
            return 0;
        }
        if(strcmp(ech[now],"then")==0)
        {
            now++;
            if(strcmp(ech[now],"id")==0||strcmp(ech[now],"if")==0)
            {
                printf("\n%s:\n",Ctrue);
                ofstream outfile("3address.txt",ios::app);
                outfile<<Ctrue<<":"<<endl;
            }
            s1=S();
            if(s1==0)
            {
                return 0;
            }
            else
            {
                ofstream outfile("grammertable.txt", ios::app);
                outfile << "  S->if C then S"<< endl;
                return 1;
            }
        }
    }

    if(strcmp(ech[now],"id")==0)
    {
        strcpy(idplace,echattr[now]);
        now++;
        if(strcmp(ech[now],"=")==0)
        {
            now++;
            e=E();
            strcpy(Scode,Ecode);                                 //aaaaaaaaaaaaaaa
            printf("   %s=%s\n",idplace,Eplace);
            ofstream outfile("3address.txt",ios::app);
            outfile<<"   "<<idplace<<"="<<Eplace<<endl;
            /*if (label == 0)
            {
                goto LIN1;
            }*/
            /*LIN1:*/
            if(e==0)
            {
                return 0;
            }
            /*ss = SS();
            if (ss == 0)
            {
                return 0;
            }*/
            else
            {
                if (int(S1begin[1]) == (int(Ctrue[1]-1))) {
                    printf("   goto %s", S1begin);
                    ofstream outfile1("3address.txt",ios::app);
                    outfile1<<"   goto "<<S1begin<<endl;
                    printf("\n   goto %s", Cfalse);
                    outfile1<<"   goto "<<Cfalse<<endl;
                    ofstream outfile("grammertable.txt", ios::app);
                    outfile << "  S->id=E " << endl;
                    ss = SS();
                }
                else {
                    printf("\n%s:\n",Snext);
                    ofstream outfile("3address.txt",ios::app);
                    outfile<<Snext<<":"<<endl;
                    ss = SS();
                }

            }

            return 1;
        }
        return 0;
    }

    if(strcmp(ech[now],"while")==0)		//等=0
    {
        now++;
        if(label==0)
        {
            newlabel(Snext);
            newlabel(Sbegin);
            strcpy(Cfalse, Snext);
            printf("\n%s:\n", Sbegin);
            ofstream outfile("3address.txt",ios::app);
            outfile<<Sbegin<<":"<<endl;
        }
        else
        {

            strcpy(Cfalse, S1next);
            printf("\n%s:\n", S1begin);
            ofstream outfile("3address.txt",ios::app);
            outfile<<S1begin<<":"<<endl;
        }
        newlabel(Ctrue);
        strcpy(S1next,Sbegin);
        c=C();
        if(c==0)
        {
            return 0;
        }
        if(strcmp(ech[now],"do")==0)
        {
            now++;

            if(strcmp(ech[now],"while")!=0)
            {
                printf("\n%s:\n",Ctrue);
                ofstream outfile("3address.txt",ios::app);
                outfile<<Ctrue<<":"<<endl;
            }
            s1=S();
            if(s1==0)
            {
                return 0;
            }
            else
            {
                ofstream outfile("grammertable.txt", ios::app);
                outfile << "  S->while C do SS" << endl;
                return 1;
            }
        }
    }
    return 0;
}


int SS()                                  //SS
{
    int s;
    if(strcmp(ech[now],"else")==0)
    {
        now++;
        s=S();
        if(s==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (strcmp(ech[now], ";") == 0) {		//？
        int sss;
        label = 0;
        now++;
        strcpy(Sbegin, Cfalse);
        strcpy(Ctrue, Snext);

        if (strcmp(ech[now + 1], "") != 0){
            //printf("\n%s:\n", Snext);
            sss= S();
            if(sss==1)
            {
                ofstream outfile("grammertable.txt", ios::app);
                outfile << "  S->SS " << endl;
                return 1;
            }
            return 0;
        }
        return 0;
    }
}


int C()                                   //C
{
    int cc,e;
    e=E();                                //e
    strcpy(E1place,Eplace);           //aaaaaaaaaaaaaa
    strcpy(E1code,Ecode);
    if(e==0)
    {
        return 0;
    }
    cc=CC();                          //
    if(cc==0)
    {
        return 0;
    }
    else
    {
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  C->EC1 " << endl;
        return 1;
    }
}


int CC()                                       //CC
{
    int e;
    if(strcmp(ech[now],">")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s>%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<">"<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1-> >E " << endl;
            return 1;
        }
    }
    if(strcmp(ech[now],">=")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s>=%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<">="<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1-> >=E " << endl;
            return 1;
        }
    }
    if(strcmp(ech[now],"<=")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s<=%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<"<="<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1-><=E " << endl;
            return 1;
        }
    }
    if(strcmp(ech[now],"<")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s<%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<"<"<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1-><E " << endl;
            return 1;
        }
    }
    if(strcmp(ech[now],"=")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s=%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<"="<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1->=E " << endl;
            return 1;
        }
    }

    if(strcmp(ech[now],"==")==0)
    {
        now++;
        e=E();
        strcpy(E2place,Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code,Ecode);
        printf("   if %s==%s goto %s \n   goto %s",E1place,E2place,Ctrue,Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<"=="<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if(e==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1->==E " << endl;
            return 1;
        }
    }
    if (strcmp(ech[now], "!=") == 0)
    {
        now++;
        e = E();
        strcpy(E2place, Eplace);           //aaaaaaaaaaaaaa
        strcpy(E2code, Ecode);
        printf("   if %s!=%s goto %s \n   goto %s", E1place, E2place, Ctrue, Cfalse);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   if "<<E1place<<"!="<<E2place<<" goto "<<Ctrue<<" \n   goto "<<Cfalse<<endl;
        if (e == 0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  C1->!=E " << endl;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}


int E()                                     //E
{
    int t,ee;
    t=T();
    strcpy(Eplace,Tplace);                //aaaaaaaaaaaa
    strcpy(Ecode,Tcode);
    if(t==0)
    {
        return 0;
    }
    ee=EE();
    if(ee==0)
    {
        return 0;
    }
    else
    {
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  E->TE1 " << endl;
        return 1;
    }
}


int T()                                  //T
{
    int f,tt;
    f=F();
    strcpy(Tplace,Fplace);                //aaaaaaaaaaaa
    strcpy(Tcode,Fcode);
    if(f==0)
    {
        return 0;
    }
    tt=TT();
    if(tt==0)
    {
        return 0;
    }
    else
    {
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  T->FT1 " << endl;
        return 1;
    }

}


int TT()                                              //TT处理“*/”
{
    int f,tt;
    if(strcmp(ech[now],"*")==0)
    {
        strcpy(TTplace,Tplace);
        strcpy(TTcode,Tcode);
        newtemp(Tplace);                            //aaaaaaaaaaaa
        now++;
        f=F();
        strcpy(Tcode,TTcode);                       //aaaaaaaaaaaa
        strcat(Tcode,Fcode);
        printf("   %s=%s*%s\n",Tplace,TTplace,Fplace);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   "<<Tplace<<"="<<TTplace<<"*"<<Fplace<<endl;
        if(f==0)
        {
            return 0;
        }
        tt=TT();
        if(tt==0)
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  T1->*F \n" << endl;
            return 0;
        }
        else
        {
            return 1;
        }

    }
    if(strcmp(ech[now],"/")==0)
    {
        strcpy(TTplace,Tplace);
        strcpy(TTcode,Tcode);
        newtemp(Tplace);                            //aaaaaaaaaaaa
        now++;
        f=F();
        strcpy(Tcode,TTcode);                       //aaaaaaaaaaaa
        strcat(Tcode,Fcode);
        printf("   %s=%s/%s\n",Tplace,TTplace,Fplace);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   "<<Tplace<<"="<<TTplace<<"/"<<Fplace<<endl;
        if(f==0)
        {
            return 0;
        }
        tt=TT();
        if(tt==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  T1->/F " << endl;
            return 1;
        }
    }
    else
    {
        /*ofstream outfile("grammertable.txt", ios::app);
        outfile << "  T1->NULL \n" << endl;*/
        return 1;
    }
}


int EE()                                             //EE处理“+-”
{
    int t,ee;
    if(strcmp(ech[now],"+")==0)
    {
        strcpy(EEplace,Eplace);
        strcpy(EEcode,Ecode);
        newtemp(Eplace);                            //aaaaaaaaaaaa
        now++;
        t=T();
        strcpy(Ecode,EEcode);                       //aaaaaaaaaaaa
        strcat(Ecode,Tcode);
        printf("   %s=%s+%s\n",Eplace,EEplace,Tplace);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   "<<Eplace<<"="<<EEplace<<"+"<<Tplace<<endl;
        if(t==0)
        {
            return 0;
        }
        ee=EE();
        if(ee==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  E1->+T " << endl;
            return 1;
        }
    }
    if(strcmp(ech[now],"-")==0)
    {
        strcpy(EEplace,Eplace);
        strcpy(EEcode,Ecode);
        newtemp(Eplace);                            //aaaaaaaaaaaa
        now++;
        t=T();
        strcpy(Ecode,EEcode);                       //aaaaaaaaaaaa
        strcat(Ecode,Tcode);
        printf("   %s=%s-%s\n",Eplace,EEplace,Tplace);
        ofstream outfile("3address.txt",ios::app);
        outfile<<"   "<<Eplace<<"="<<EEplace<<"-"<<Tplace<<endl;
        if(t==0)
        {
            return 0;
        }
        ee=EE();
        if(ee==0)
        {
            return 0;
        }
        else
        {
            ofstream outfile("grammertable.txt", ios::app);
            outfile << " E1->-T" << endl;
            return 1;
        }
    }
    else
    {
        return 1;
    }
}


int F()                                        //F
{
    int e=0;
    if(strcmp(ech[now],"(")==0)
    {
        now++;
        e=E();
        strcpy(Fplace,Eplace);                 //aaaaaaaaaaaa
        strcpy(Fcode,Ecode);
        if(e==0)
        {
            return 0;
        }
        if(strcmp(ech[now],")")==0)
        {
            now++;
            ofstream outfile("grammertable.txt", ios::app);
            outfile << "  F->(E)" << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(strcmp(ech[now],"id")==0)
    {
        strcpy(Fplace,echattr[now]);             //aaaaaaaaaaaa
        strcpy(Fcode,"");
        now++;
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  F->id" << endl;
        return 1;
    }
    if(strcmp(ech[now],"int8")==0)
    {
        strcpy(Fplace,echattr[now]);            //aaaaaaaaaaaa
        strcpy(Fcode,"");
        now++;
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  F->int8" << endl;
        return 1;
    }
    if(strcmp(ech[now],"int10")==0)
    {
        strcpy(Fplace,echattr[now]);            //aaaaaaaaaaaa
        strcpy(Fcode,"");
        now++;
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  F->int10" << endl;
        return 1;
    }
    if(strcmp(ech[now],"int16")==0)
    {
        strcpy(Fplace,echattr[now]);            //aaaaaaaaaaaa
        strcpy(Fcode,"");
        now++;
        ofstream outfile("grammertable.txt", ios::app);
        outfile << "  F->int16" << endl;
        return 1;
    }

    else
    {
        return 0;
    }
}

QString change(char *number){
    string sd=number;
    QString st=str2qstr(sd);
    return st;
}



