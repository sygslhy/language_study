#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model/VerbConjModel.h"
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

// void parseVerbFormDataFromHLayout(const QHBoxLayout* hLayout, std::string& name, std::string& form, std::string& example, std::string& translation){
//     QLabel* label = hLayout->findChild<QLabel*>();
//     name= label->text().toStdString();
//     QList<QTextEdit*> listTextEdit = hLayout->findChildren<QTextEdit*>();
//     form = listTextEdit[0]->toPlainText().toStdString();
//     example = listTextEdit[1]->toPlainText().toStdString();
//     translation = listTextEdit[2]->toPlainText().toStdString();

// }


void MainWindow::on_pushButtonSave_clicked()
{
//     // parse the verb name from name text edit and set the name to model builder.
//     std::string verbName = ui->textEditVerbName->toPlainText().toStdString();
//     VerbConjModel::Builder verbConjModelBuilder;
//     verbConjModelBuilder.setName(verbName);


//     // parse the form data from every H layout and set to the model builder
//     QList<QHBoxLayout*> listHLayout = ui->centralwidget->findChildren<QHBoxLayout*>();
//     foreach(QHBoxLayout* hLayout, listHLayout){
//         if(hLayout!=nullptr){
//             std::string name, form, example, translation;
//             parseVerbFormDataFromHLayout(hLayout, name, form, example, translation);
//             verbConjModelBuilder.setForm(name, form, example, translation);
//         }
//     }

//     // build the model
//     VerbConjModel model = verbConjModelBuilder.build();

//     //save the model to json file.
}


void MainWindow::on_pushButtonCleanup_clicked()
{
    // QList<QTextEdit*> listTextEdit = ui->centralwidget->findChildren<QTextEdit*>();
    // foreach(QTextEdit* textEdit, listTextEdit){
    //     if(textEdit!=nullptr){
    //         textEdit->clear();
    //     }
    // }
}

