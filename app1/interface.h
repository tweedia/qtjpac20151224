#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtPlugin>
#include <QString>
#include <QObject>
#include <QWidget>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual QString title() const = 0;
    virtual void setQAction(QObject *argQAction) = 0;
    virtual QObject* getQAction() = 0;
    virtual QWidget* newWidget() = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "jp.QtAdventCalender2015.Plugin.PluginInterface/1.0")

#endif // INTERFACE_H

