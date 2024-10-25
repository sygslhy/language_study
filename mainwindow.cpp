#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model/VerbConjModel.h"
#include "io/VerbMetadata.h"
#include <QLabel>
#include <QTextEdit>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("日语学习");

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSave_clicked()
{
    // parse the verb name from name text edit and set the name to model builder.
    std::string verbName = ui->textEditVerbName->toPlainText().toStdString();

    VerbConjModel verbModel;
    verbModel.name = verbName;

    // parse the form data from every H layout and set to the model builder
    verbModel.naiForm.name = ui->groupBoxNai->title().toStdString();
    verbModel.naiForm.formData = ui->textEditNaiForm->toPlainText().toStdString();
    verbModel.naiForm.exampleJap = ui->plainTextEditNaiExample->toPlainText().toStdString();
    verbModel.naiForm.translation = ui->plainTextEditNaiTranslate->toPlainText().toStdString();


    verbModel.masuForm.name = ui->groupBoxMasu->title().toStdString();
    verbModel.masuForm.formData = ui->textEditMasuForm->toPlainText().toStdString();
    verbModel.masuForm.exampleJap = ui->plainTextEditMasuExample->toPlainText().toStdString();
    verbModel.masuForm.translation = ui->plainTextEditMasuTranslate->toPlainText().toStdString();

    // verbModel.dictForm.formData = ui->textEditDictForm->toPlainText().toStdString();
    // verbModel.dictForm.exampleJap = ui->plainTextEditDictEsample->toPlainText().toStdString();
    // verbModel.dictForm.translation = ui->plainTextEditDictTranslate->toPlainText().toStdString();

    // verbModel.subForm.formData = ui->textEditSubForm->toPlainText().toStdString();
    // verbModel.subForm.exampleJap = ui->plainTextEditSubExample->toPlainText().toStdString();
    // verbModel.subForm.translation = ui->plainTextEditSubTranslate->toPlainText().toStdString();

    // verbModel.condForm.formData = ui->textEditCondForm->toPlainText().toStdString();
    // verbModel.condForm.exampleJap = ui->plainTextEditCondExample->toPlainText().toStdString();
    // verbModel.condForm.translation = ui->plainTextEditCondTranslate->toPlainText().toStdString();

    // verbModel.orderForm.formData = ui->textEditOrderForm->toPlainText().toStdString();
    // verbModel.orderForm.exampleJap = ui->plainTextEditOrderExample->toPlainText().toStdString();
    // verbModel.orderForm.translation = ui->plainTextEditOrderTranslate->toPlainText().toStdString();

    // verbModel.desireForm.formData = ui->textEditDesireForm->toPlainText().toStdString();
    // verbModel.desireForm.exampleJap = ui->plainTextEditDesireExample->toPlainText().toStdString();
    // verbModel.desireForm.translation = ui->plainTextEditDesireTranslate->toPlainText().toStdString();

    // verbModel.teForm.formData = ui->textEditTeForm->toPlainText().toStdString();
    // verbModel.teForm.exampleJap = ui->plainTextEditTeExample->toPlainText().toStdString();
    // verbModel.teForm.translation = ui->plainTextEditTeTranslate->toPlainText().toStdString();

    // verbModel.taForm.formData = ui->textEditTaForm->toPlainText().toStdString();
    // verbModel.taForm.exampleJap = ui->plainTextEditTaExample->toPlainText().toStdString();
    // verbModel.taForm.translation = ui->plainTextEditTaTranslate->toPlainText().toStdString();

     //save the model to json file.
    writeMetadata(verbModel, "/home/ysun/verbs.json");
}


void MainWindow::on_pushButtonCleanup_clicked()
{
    QList<QTextEdit*> listTextEdit = ui->centralwidget->findChildren<QTextEdit*>();
    foreach(QTextEdit* textEdit, listTextEdit){
        if(textEdit!=nullptr){
            textEdit->clear();
        }
    }

    QList<QPlainTextEdit*> listPlainTextEdit = ui->centralwidget->findChildren<QPlainTextEdit*>();
    foreach(QPlainTextEdit* plainTextEdit, listPlainTextEdit){
        if(plainTextEdit!=nullptr){
            plainTextEdit->clear();
        }
    }
}

