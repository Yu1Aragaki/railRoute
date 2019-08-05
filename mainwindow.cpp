/**
 * @brief   start window of the program
 * @file    mainwindow.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/7/16
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "drawpad.h"
#include "common.h"

#include <QAction>
#include <QWidget>
#include <QApplication>
#include <QTranslator>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

/**
 * @brief constructor of MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << this->frameGeometry().width() << this->frameGeometry().height();
    if (langType == 1)
    {
        QTranslator zhsTranslator;
        zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
        qApp->installTranslator(&zhsTranslator);
        this->ui->retranslateUi(this);
    }
    else if (langType == 0)
    {
        QTranslator enTranslator;
        enTranslator.load(":/res/i18n/translate_EN.qm");
        qApp->installTranslator(&enTranslator);
        this->ui->retranslateUi(this);
    }
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief a mid function of several "New" actions, open a drawpad
 */
void MainWindow::OpenNewProject()
{
    DrawPad *dp = new DrawPad(nullptr);
    dp->show();
    this->close();
}

/**
 * @brief a mid function of several "Load" actions
 * @todo  open the file-select window and load the selected file into the program
 */
void MainWindow::LoadProject()
{

}

/**
 * @brief slot function of "About" in menubar, open a "about" window
 */
void MainWindow::on_actionAbout_triggered()
{
    about *aView = new about();
    aView->show();
}

/**
 * @brief slot function of "English" in menubar, switch the language into English
 */
void MainWindow::on_actionEnglish_triggered()
{
    QTranslator enTranslator;
    enTranslator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&enTranslator);
    this->ui->retranslateUi(this);
    langType = 0;
}

/**
 * @brief slot function of "jiantizhongwen" in menubar, switch language into Chinese(Simplified)
 */
void MainWindow::on_actionZHS_triggered()
{
    QTranslator zhsTranslator;
    zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&zhsTranslator);
    this->ui->retranslateUi(this);
    langType = 1;
}

/**
 * @brief slot function of "New" in menubar, jump to the OpenNewProject function
 */
void MainWindow::on_actionNew_triggered()
{
    OpenNewProject();
}

/**
 * @brief slot function of "Load" in menubar, jump to the LoadProject function
 */
void MainWindow::on_actionLoad_triggered()
{
    LoadProject();
}

/**
 * @brief slot function of "Exit" in menubar, trigger a closeEvent
 */
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

/**
 * @brief slot function of "New Project", jump to the OpenNewProject function
 */
void MainWindow::on_newProject_clicked()
{
    OpenNewProject();
}

/**
 * @brief slot function of "Load Project", jump to the LoadProject function
 */
void MainWindow::on_loadProject_clicked()
{
    LoadProject();
}

/**
 * @brief slot function of "Exit", trigger a closeEvent
 */
void MainWindow::on_exitLabel_clicked()
{
    this->close();
}
