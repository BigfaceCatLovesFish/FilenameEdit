#include "filenameedit.h"
#include "./ui_filenameedit.h"

#include <QFileDialog>


QStringList strPathList;


FilenameEdit::FilenameEdit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FilenameEdit)
{
    ui->setupUi(this);
}

FilenameEdit::~FilenameEdit()
{
    delete ui;
}

void FilenameEdit::on_actionAdd_File_triggered()
{

    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    if (fileDialog.exec() == QDialog::Accepted)
    {
        strPathList = fileDialog.selectedFiles();
    }

    int i, j=strPathList.count();
    QStringList filename;

    for (i = 0; i<j; i++)
    {
        QString a1 = strPathList.at(i);
        QStringList a2 = a1.split("/");
        a1 = a2.last();
        filename.append(a1);
    }

    QString b2;
    QString b1;

    for (i = 0; i<j; i++)
    {
        b2 = filename.at(i);
        b1 = b1.append("->");
        b1 = b1.append(b2);
        b1 = b1.append("\n");
    }

    ui->textEdit->setText(b1);

}


void FilenameEdit::on_pushButton_clicked()
{
    QString strTodelete;
    QStringList strPathListNew = strPathList;

    strTodelete = ui->lineEdit->text();

    int i, j = strPathListNew.count();

    for(i = 0; i < j; i++)
    {
        QString a = strPathListNew.at(i);
        strPathListNew[i] = a.replace(strTodelete, QString(""));
        QFile::rename(strPathList.at(i), strPathListNew.at(i));
    }

    QStringList d1;

    for (i = 0; i<j; i++)
    {
        QString a1 = strPathListNew.at(i);
        QStringList a2 = a1.split("/");
        a1 = a2.last();
        d1.append(a1);
    }

    QString b2;
    QString b1;

    for (i = 0; i<j; i++)
    {
        b2 = d1.at(i);
        b1 = b1.append("->");
        b1 = b1.append(b2);
        b1 = b1.append("\n");
    }

    ui->textEdit_2->setText(b1);

}

