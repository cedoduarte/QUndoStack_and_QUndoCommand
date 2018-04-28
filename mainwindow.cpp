#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycheckboxundocommand.h"
#include <QUndoStack>

#define PREPARE_CHECKBOX(checkbox_number) \
    connect(ui->checkbox##checkbox_number, &MyCheckBox::mouse_pressed, this, [&](bool checked) \
    { \
        m_old_checked = checked; \
    }); \
    \
    connect(ui->checkbox##checkbox_number, &MyCheckBox::mouse_released, this, [&](bool checked) \
    { \
        m_new_checked = checked; \
        MyCheckBoxUndoCommand *command = new MyCheckBoxUndoCommand(ui->checkbox##checkbox_number, m_old_checked, m_new_checked); \
        m_undo_stack->push(command); \
    });

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_undo_stack = new QUndoStack(this);

    PREPARE_CHECKBOX(1)
    PREPARE_CHECKBOX(2)
    PREPARE_CHECKBOX(3)
    PREPARE_CHECKBOX(4)
    PREPARE_CHECKBOX(5)
    PREPARE_CHECKBOX(6)
    PREPARE_CHECKBOX(7)
    PREPARE_CHECKBOX(8)
    PREPARE_CHECKBOX(9)
    PREPARE_CHECKBOX(10)
    PREPARE_CHECKBOX(11)
    PREPARE_CHECKBOX(12)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_undo_pushbutton_clicked()
{
    m_undo_stack->undo();
}

void MainWindow::on_redo_pushbutton_clicked()
{
    m_undo_stack->redo();
}
