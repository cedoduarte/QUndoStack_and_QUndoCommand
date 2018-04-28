#include "mycheckboxundocommand.h"
#include "mycheckbox.h"

MyCheckBoxUndoCommand::MyCheckBoxUndoCommand(MyCheckBox *mycheckbox, bool old_checked, bool new_checked,
                                             QUndoCommand *parent)
    : QUndoCommand(parent)
{
    m_old_checked = old_checked;
    m_new_checked = new_checked;
    m_checkbox = mycheckbox;
}

void MyCheckBoxUndoCommand::undo()
{
    m_checkbox->setChecked(m_old_checked);
}

void MyCheckBoxUndoCommand::redo()
{
    m_checkbox->setChecked(m_new_checked);
}
