#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Plugin_triggered()
{
    QString pathname = QFileDialog::getOpenFileName(this, "Open Plugin File");

    if (!pathname.isEmpty()) {
        QPluginLoader loader(pathname);
        if (PluginInterface *plugin = qobject_cast<PluginInterface*>(loader.instance())) {

            QAction *action = new QAction("Call " + plugin->title(), this);
            connect(action, SIGNAL(triggered()), this, SLOT(callPlugin()));
            ui->menuFile->addAction(action);

            plugin->setQAction(action);
            plugins.append(plugin);
        }
    }
}

void MainWindow::callPlugin()
{
    QObject* pSender = QObject::sender();
    PluginInterface *plugin;
    QWidget *widget;

    for (int i = 0; i < plugins.size(); ++i) {
        plugin = plugins.at(i);
        if (plugin->getQAction() == pSender) {
            widget = plugin->newWidget();
            if (widget) {
                QString title = QString("Form - " + QString("%1").arg(ui->mdiArea->subWindowList().count() + 1));
                QAction *action = new QAction(title, this);
                ui->menuWindow->addAction(action);

                QMdiSubWindow *window = ui->mdiArea->addSubWindow(widget);
                window->setWindowTitle(title);

                connect(action, SIGNAL(triggered()), widget, SLOT(setFocus()));

                widget->show();
                widget->setFocus();
            }
        }
    }
}
