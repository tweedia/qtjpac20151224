#ifndef PLUGIN1_H
#define PLUGIN1_H

#include "interface.h"

class Plugin1 : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)

public:
    Plugin1();
    ~Plugin1();
    QString title() const {return QString("Text Edit");}
    void setQAction(QObject *argQAction) {mQAction = argQAction;}
    QObject* getQAction() {return mQAction;}
    QWidget* newWidget();

private:
    QObject *mQAction;
};

#endif // PLUGIN1_H
