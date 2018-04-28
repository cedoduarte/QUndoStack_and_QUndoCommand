#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>

class MyCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    MyCheckBox(QWidget *parent = nullptr);
signals:
    void mouse_pressed(bool checked);
    void mouse_released(bool checked);
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
};

#endif // MYCHECKBOX_H
