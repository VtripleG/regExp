#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 300);
    setMaximumSize(300, 300);

    this->emailEdit->setPlaceholderText("Enter email");
    this->telNumberEdit->setPlaceholderText("Enter telephone number");
    QRegularExpression telNumExp("8\\(\\d{3}\\)\\d{3}\\-\\d{2}\\-\\d{2}");
    QRegularExpression nameExp("[A-Z]{1}[a-z]{11}");
    QRegularExpression surnameExp("[A-Z]{1}[a-z]{11}");
    this->telNumberEdit->setValidator(new QRegularExpressionValidator(telNumExp, this));
    this->telNumberEdit->setInputMask("8(999)999-99-99");
    this->nameEdit->setPlaceholderText("Enter name");
    this->nameEdit->setValidator(new QRegularExpressionValidator(nameExp, this));
    this->surnameEdit->setPlaceholderText("Enter Surname");
    this->surnameEdit->setValidator(new QRegularExpressionValidator(surnameExp, this));
    QPushButton* regButton = new QPushButton;
    regButton->setText("Registration");

    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addWidget(nameEdit);
    mainLayout->addWidget(surnameEdit);
    mainLayout->addWidget(telNumberEdit);
    mainLayout->addWidget(emailEdit);
    mainLayout->addWidget(regButton);

    setLayout(mainLayout);

    connect(regButton, &QPushButton::clicked, this, &MainWindow::RegButtonClicked);

}

MainWindow::~MainWindow()
{
}

void MainWindow::RegButtonClicked()
{
    QRegularExpression emailExp("\\b[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b");
    if (!emailExp.match(this->emailEdit->text()).hasMatch())
    {
        this->emailEdit->clear();
        QMessageBox::warning(this, "Error", "Invalid email");
    }

//    if (!telNumExp.match(this->telNumberEdit->text()).hasMatch())
//    {
//        qDebug() << this->telNumberEdit->text();
//        this->telNumberEdit->clear();
//        QMessageBox::warning(this, "Error", "Invalid telephone number");
//    }

}

