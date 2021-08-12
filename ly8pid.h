#ifndef LY8PID_H
#define LY8IPD_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>


class LY8PID : public QMainWindow
{
    Q_OBJECT


public:
    explicit LY8PID(QWidget *parent = nullptr);

    void Open_log_file();
    void Open_elf_File();
    void Set_ID_man(unsigned int&);
    unsigned  int & get_ID();
    unsigned  int & get_ID_elf();
    void Save_log_File();
    void Save_elf_File();
    void Set_FileNameLog(QString);
    QString  Get_FileNameLog();
    void Set_FileNAme(QString);
    QString  Get_FileName();
    void Set_Manual_Filename(unsigned int);






private:
    static QString FileName; //= "LY8P_v001_ELF.elf";
    static QString FileNameLog; //= "LY8P_ID.log";
    unsigned int  ID_Lo_Location = 2566 ;
    unsigned int ID_elf;
    unsigned int ID_man;
    QByteArray pc_Dane;
    QByteArray log_Dane;
    int i_DlugoscPliku;
    int i_DlugoscPliku_log;
    unsigned char Lo, Mi, Hi;               // od 0 do 255
    unsigned short i, ID_Lo, Lp;            // od 0 do 65'535
    unsigned int ID;                       // od 0 do 4'294'967'295  zakres IP: 0 - 16 777 215 (3 bajty)
    char znak;

signals:

};

#endif // LY8IDP_H

