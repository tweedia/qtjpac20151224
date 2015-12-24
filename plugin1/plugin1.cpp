#include "form.h"

#include "plugin1.h"

Plugin1::Plugin1()
{
}

Plugin1::~Plugin1()
{
}

QWidget* Plugin1::newWidget()
{
    Form *widget = new Form();
    return widget;
}

Q_EXPORT_PLUGIN2(plugin1, Plugin1)
