#include "widget.h"
#include "ui_widget.h"

#include "aes128cifradofromphp.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->plainTextEdit->bo

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{

    QByteArray arr = QByteArray::fromHex(arg1.simplified().trimmed().remove(" ").toLocal8Bit());

    ui->lineEdit->setStyleSheet( (arr.length() == 16 && arr.toHex().toLower() == arg1.simplified().trimmed().remove(" ").toLocal8Bit().toLower()) ? "" : "background-color: qlineargradient(spread:pad, x1:0.53, y1:1, x2:0.53, y2:0.00568182, stop:0 rgba(170, 0, 0, 255), stop:0.0994475 rgba(255, 255, 255, 0));" );
    ui->label_2->setText(QString("Key len %1 byte").arg(arr.length()));
}

void Widget::on_plainTextEdit_textChanged()
{
    if(ui->plainTextEdit->toPlainText().isEmpty()){
        ui->plainTextEdit->setStyleSheet("");
        ui->label->setText("Input len 0 byte");
        return;


    }

    QByteArray arr = QByteArray::fromHex(ui->plainTextEdit->toPlainText().simplified().trimmed().remove(" ").toLocal8Bit());
    ui->plainTextEdit->setStyleSheet( (arr.length()%16 == 0 && arr.toHex().toLower() == ui->plainTextEdit->toPlainText().simplified().trimmed().remove(" ").toLocal8Bit().toLower()) ? "" : "background-color: qlineargradient(spread:pad, x1:0.53, y1:1, x2:0.53, y2:0.00568182, stop:0 rgba(170, 0, 0, 255), stop:0.0994475 rgba(255, 255, 255, 0));" );

    ui->label->setText(QString("Input len %1 byte").arg(arr.length()));


}

void Widget::on_pushButton_clicked()
{
    ui->plainTextEdit_2->clear();
    AES128CifradoFromPhp cifr;
    QByteArray arr = cifr.aes128_ecb_encrtypt(QByteArray::fromHex(ui->plainTextEdit->toPlainText().simplified().trimmed().remove(" ").toLocal8Bit()),
                                              QByteArray::fromHex(ui->lineEdit->text().simplified().trimmed().remove(" ").toLocal8Bit())).toHex();
                                              //QByteArray::fromHex("000102030405060708090A0B0C0D0E0F")).toHex();

    if(arr.isEmpty()){
        ui->plainTextEdit_2->appendPlainText("Unknown error.");
        return;
    }


    QString str("");
    for(int i = 0, iMax = arr.length(), j = 0; i < iMax; i += 2, j++){
        if(j > 15){
            j = 0;
            str.append("\n");
        }
        str.append(arr.mid(i, 2) + " ");
    }
    ui->plainTextEdit_2->appendPlainText(str);

}

void Widget::on_pushButton_2_clicked()
{
    ui->plainTextEdit_2->clear();
    AES128CifradoFromPhp cifr;
    QByteArray arr = cifr.aes128_ecb_decrtypt(QByteArray::fromHex(ui->plainTextEdit->toPlainText().simplified().trimmed().remove(" ").toLocal8Bit()),
                                              QByteArray::fromHex(ui->lineEdit->text().simplified().trimmed().remove(" ").toLocal8Bit())).toHex();
                                              //QByteArray::fromHex("000102030405060708090A0B0C0D0E0F")).toHex();

    if(arr.isEmpty()){
        ui->plainTextEdit_2->appendPlainText("Unknown error.");
        return;
    }


    QString str("");
    for(int i = 0, iMax = arr.length(), j = 0; i < iMax; i += 2, j++){
        if(j > 15){
            j = 0;
            str.append("\n");
        }
        str.append(arr.mid(i, 2) + " ");
    }
    ui->plainTextEdit_2->appendPlainText(str);
}
