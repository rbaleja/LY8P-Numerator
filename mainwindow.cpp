#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ly8pid.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_read_log_file_clicked()
{
    LY8PID ID;

    unsigned int id;
    ID.Open_log_file();
    id = ID.get_ID();
    QString s = QString::number(id);
    ui->lcdnumber_log_file->display(s);
}

void MainWindow::on_pushButton_read_elf_file_clicked()
{
    LY8PID ID;
    unsigned int id;
    ID.Open_elf_File();
    id = ID.get_ID_elf();
    QString s = QString::number(id);
    ui->lcdNumber_elf_file->display(s);

}



void MainWindow::on_pushButton_add_number_clicked()
{
    LY8PID ID;
    QMessageBox msgBox;
    ID.Save_log_File();
    unsigned int id;
    QString string_id;

    if (ui->Manual_Number_checkBox->isChecked())
       {
        string_id = ui->Manualk_Number_lineEdit->text();
        id = string_id.toUInt();
        if (id < 400000 || id > 499999)
            {
            msgBox.setWindowTitle("LY8PID");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Niedozwolony numer ( tylko 400000 do 499999");
            msgBox.exec();

            }

        QString s = QString::number(id);
        ui->lcdNumber_elf_file->display(s);
        ID.Set_Manual_Filename(id);
        qDebug() << string_id;
        qDebug() << id;

       }

    else
    ID.Open_log_file();
    id = ID.get_ID();

    QString s = QString::number(id);
    qDebug() << id;
    ui->lcdnumber_log_file->display(s);
    ui->statusbar->showMessage("Numer kolejny nadany!", 1000);
}

void MainWindow::on_actionOpen_Log_File_triggered()
{
    LY8PID ID;
    QString filename = QFileDialog::getOpenFileName(this, "Open log file","", "*.log");
    ID.Set_FileNameLog(filename);
    ui->lineEdit_log_file->setText(filename);
    ui->statusbar->showMessage("Plik log Wczytany", 3000);




}
void MainWindow::on_actionOpen_Elf_File_triggered()
{

    LY8PID ID;
    QString filename = QFileDialog::getOpenFileName(this, "Open elf file", "", "*.elf");
    ID.Set_FileNAme(filename);
    ui->lineEdit_elf_file->setText(filename);
    ui->statusbar->showMessage("Plik elf Wczytany", 3000);

}










