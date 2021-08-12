#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_read_log_file_clicked();

    void on_pushButton_read_elf_file_clicked();

    void on_pushButton_add_number_clicked();

    void on_actionOpen_Log_File_triggered();

    void on_actionOpen_Elf_File_triggered();










private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
