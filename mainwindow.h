#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QUndoStack;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_undo_pushbutton_clicked();

    void on_redo_pushbutton_clicked();

private:
    Ui::MainWindow *ui;
    QUndoStack *m_undo_stack;
    bool m_old_checked;
    bool m_new_checked;
};

#endif // MAINWINDOW_H
