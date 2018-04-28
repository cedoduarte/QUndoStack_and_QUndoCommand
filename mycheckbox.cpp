#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QWidget *parent)
    : QCheckBox(parent)
{

}

void MyCheckBox::mousePressEvent(QMouseEvent *e)
{
    QCheckBox::mousePressEvent(e);
    emit mouse_pressed(isChecked());
}

void MyCheckBox::mouseReleaseEvent(QMouseEvent *e)
{
    QCheckBox::mouseReleaseEvent(e);
    emit mouse_released(isChecked());
}
