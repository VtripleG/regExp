#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit* emailEdit = new QLineEdit;
    QLineEdit* telNumberEdit = new QLineEdit;
    QLineEdit* nameEdit = new QLineEdit;
    QLineEdit* surnameEdit = new QLineEdit;




public slots:
    void RegButtonClicked();
};
#endif // MAINWINDOW_H
