#ifndef DATAPROCWINDOW_H
#define DATAPROCWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "addtomasterdiag.h"
#include <QtCharts>
#include <QGraphicsItem>
#include <QChart>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QFile>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class dataProcWindow;
}

class dataProcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit dataProcWindow(QWidget *parent = 0);
    ~dataProcWindow();
    void incompleteDataError();

private:
    Ui::dataProcWindow *ui;
    QString fileName;
    QString pidType;
    void createMenus();
    void createActions();
    void chartSetup();
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);
    QString getFilename();
    QAction *openFileAct;
    QAction *addIDtoMasterListAct;
    QAction *saveDataToFileAct;
    QMenu *fileMenu;
    QMenu *tableMenu;
    QMessageBox *errorMsg;
    addToMasterDiag *add2Master;
    QGraphicsScene *scene;
    QChart *chart;
    QSplineSeries *series;
    QVector<int> xVector;
    QVector<int> yVector;

private slots:
    void updateVehicleList();
    void showData();
    void checkPID();
    void updateComboBoxes();
    void addIDtoMasterList();
    QString getPID();
    void saveDataToFile();
};

#endif // DATAPROCWINDOW_H
