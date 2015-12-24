#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QList>
#include <QWidget>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QPluginLoader>
#include "interface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_Plugin_triggered();
    void callPlugin();

private:
    Ui::MainWindow *ui;
    QList<PluginInterface*> plugins;
};

#endif // MAINWINDOW_H
