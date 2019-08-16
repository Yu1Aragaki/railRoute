/**
 * @brief   drawpad window of the program
 * @file    drawpad.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/2
 * @note    the core part of this program, could draw graphs and can save in / load from files
 * @todo    do the todos
 */

#include "drawpad.h"
#include "ui_drawpad.h"
#include "about.h"
#include "common.h"
#include "drawpadscene.h"
#include "drawpadview.h"

#include <QtWidgets>

/**
 * @brief constructor of DrawPad
 * @param parent
 */
DrawPad::DrawPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawPad)
{
    ui->setupUi(this);
    QIcon *ico = new QIcon(":/res/img/logo/logo.ico");
    this->setWindowIcon(*ico);

    switch (langType)
    {
        case 0:
        {
            QTranslator translator;
            translator.load(":/res/i18n/translate_EN.qm");
            qApp->installTranslator(&translator);
            this->ui->retranslateUi(this);
            translator.load(":/res/i18n/qt_en.qm");
            qApp->installTranslator(&translator);
            break;
        }

        case 1:
        {
            QTranslator translator;
            translator.load(":/res/i18n/translate_ZHS.qm");
            qApp->installTranslator(&translator);
            this->ui->retranslateUi(this);
            translator.load(":/res/i18n/qt_zh_CN.qm");
            qApp->installTranslator(&translator);
            break;
        }

        case 2:
        {
            QTranslator translator;
            translator.load(":/res/i18n/translate_JP.qm");
            qApp->installTranslator(&translator);
            this->ui->retranslateUi(this);
            translator.load(":/res/i18n/qt_ja.qm");
            qApp->installTranslator(&translator);
            break;
        }
    }

    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << "50%" << "75%" << "100%" << "125%" << "150%" << "100%";
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &DrawPad::sceneScaleChanged);
    ui->toolBar->addWidget(sceneScaleCombo);

    scene = new DrawPadScene();
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    ui->graphicsView->setScene(scene);
    ui->actionNodeColor->setIcon(createColorToolButtonIcon(":/res/img/opr/node.png", Qt::black));
    ui->actionLineColor->setIcon(createColorToolButtonIcon(":/res/img/opr/line.png", Qt::black));
    ui->actionTextColor->setIcon(createColorToolButtonIcon(":/res/img/opr/text.png", Qt::black));
}

/**
 * @brief DrawPad::~DrawPad
 */
DrawPad::~DrawPad()
{
    delete ui;
}

/**
 * @brief reset the selected scale
 * @param scale
 * @param index
 */
void DrawPad::ChangeComboBoxItem(qreal scale, int index)
{
    sceneScaleCombo->setCurrentIndex(index);
    QString tempString = QString(QString::number(qRound(scale * 100)) + QString('%'));
    qDebug() << tempString;
    sceneScaleCombo->setItemText(index, tempString);
}

/**
 * @brief change scale from the combo box
 * @param scale
 */
void DrawPad::sceneScaleChanged(const QString &scale)
{
    double newScale = scale.left(scale.indexOf("%")).toDouble() / 100.0;
    ui->graphicsView->Zoom(newScale);
}

/**
 * @brief create Color ToolButton Icon
 * @param imageFile
 * @param color
 * @return a icon
 */
QIcon DrawPad::createColorToolButtonIcon(const QString &imageFile, QColor color)
{
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPixmap image(imageFile);
    // Draw icon centred horizontally on button.
    QRect target(4, 0, 42, 43);
    QRect source(0, 0, 42, 43);
    painter.fillRect(QRect(0, 60, 50, 80), color);
    painter.drawPixmap(target, image, source);

    return QIcon(pixmap);
}

/**
 * @brief deal with the close event, to make sure that the user's project has been saved.
 * @param event
 */
void DrawPad::closeEvent(QCloseEvent *event)
{
    qDebug() << "triggered close event";
    event->accept();
}

/**
 * @brief slot function of "New" in menubar
 * @todo  save the present project and open a new drawPad
 */
void DrawPad::on_actionNew_triggered()
{

}

/**
 * @brief slot function of "Save" in menubar
 * @todo  save the present project into a project file
 */
void DrawPad::on_actionSave_triggered()
{

}

/**
 * @brief slot function of "Load" in menubar
 * @todo  open the file-select window and load the selected file into the program
 */
void DrawPad::on_actionLoad_triggered()
{

}

/**
 * @brief slot function of "Exit" in menubar
 */
void DrawPad::on_actionExit_triggered()
{
    this->close();
}

/**
 * @brief slot function of "Undo" in menubar
 * @todo  add the undo lib of Qt
 */
void DrawPad::on_actionUndo_triggered()
{

}

/**
 * @brief slot function of "Redo" in menubar
 * @todo  add the redo lib of Qt
 */
void DrawPad::on_actionRedo_triggered()
{

}

/**
 * @brief slot function of "Delete" in menubar
 * @todo  delete the selected item
 */
void DrawPad::on_actionDelete_triggered()
{

}

/**
 * @brief slot function of "About" in menubar, open a "about" window
 */
void DrawPad::on_actionAbout_triggered()
{
    about *aView = new about();
    aView->show();
}

/**
 * @brief slot function of "English" in menubar, switch language to English
 */
void DrawPad::on_actionEnglish_triggered()
{
    QTranslator translator;
    translator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    translator.load(":/res/i18n/qt_en.qm");
    qApp->installTranslator(&translator);
    langType = 0;
}

/**
 * @brief slot function of "jiantizhongwen" in menubar, switch language into Chinese(Simplified)
 */
void DrawPad::on_actionZHS_triggered()
{
    QTranslator translator;
    translator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    translator.load(":/res/i18n/qt_zh_CN.qm");
    qApp->installTranslator(&translator);
    langType = 1;
}

/**
 * @brief slot function of "nihongo" in menubar, switch language into Japanese
 */
void DrawPad::on_actionJP_triggered()
{
    QTranslator translator;
    translator.load(":/res/i18n/translate_JP.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    translator.load(":/res/i18n/qt_ja.qm");
    qApp->installTranslator(&translator);
    langType = 2;
}

/**
 * @brief slot function of "Node" tool button in toolbox
 * @todo  switch the type of operation to draw a node
 */
void DrawPad::on_nodeButton_clicked()
{
    if ((static_cast <QPushButton*> (sender()))->isChecked() == true)
    {
        if (ui->lineButton->isChecked() == true)
        {
            ui->lineButton->setChecked(false);
        }
    }
}

/**
 * @brief slot function of "line" tool button in toolbox
 * @todo  switch the type of operation to draw a line
 */
void DrawPad::on_lineButton_clicked()
{
    if ((static_cast <QPushButton*> (sender()))->isChecked() == true)
    {
        if (ui->nodeButton->isChecked() == true)
        {
            ui->nodeButton->setChecked(false);
        }
    }
}

/**
 * @brief a inline function used to translate dialogs(eg. QColorDialog)
 */
inline void DrawPad::dialogTranslate()
{
    QTranslator *translator = new QTranslator();
    switch (langType)
    {
        case 0:
        {
            translator->load(":/res/i18n/qt_en.qm");
            qApp->installTranslator(translator);
            break;
        }

        case 1:
        {
            translator->load(":/res/i18n/qt_zh_CN.qm");
            qApp->installTranslator(translator);
            break;
        }

        case 2:
        {
            translator->load(":/res/i18n/qt_ja.qm");
            qApp->installTranslator(translator);
            break;
        }
    }
}

/**
 * @brief select the color for node
 */
void DrawPad::on_actionNodeColor_triggered()
{
    dialogTranslate();
    QColor color = QColorDialog::getColor(nodeColor);
    nodeColor = color;
    ui->actionNodeColor->setIcon(createColorToolButtonIcon(":/res/img/opr/node.png", color));
}

/**
 * @brief select the color for line
 */
void DrawPad::on_actionLineColor_triggered()
{
    dialogTranslate();
    QColor color = QColorDialog::getColor(lineColor);
    lineColor = color;
    ui->actionLineColor->setIcon(createColorToolButtonIcon(":/res/img/opr/line.png", color));
}

/**
 * @brief select the color for text
 */
void DrawPad::on_actionTextColor_triggered()
{
    dialogTranslate();
    QColor color = QColorDialog::getColor(textColor);
    textColor = color;
    ui->actionTextColor->setIcon(createColorToolButtonIcon(":/res/img/opr/text.png", color));
}
