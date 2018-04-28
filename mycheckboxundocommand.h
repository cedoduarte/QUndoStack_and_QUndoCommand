#ifndef MYCHECKBOXUNDOCOMMAND_H
#define MYCHECKBOXUNDOCOMMAND_H

#include <QUndoCommand>

class MyCheckBox;

class MyCheckBoxUndoCommand : public QUndoCommand
{
public:
    MyCheckBoxUndoCommand(MyCheckBox *mycheckbox, bool old_checked, bool new_checked, QUndoCommand *parent = nullptr);
    void undo() override;
    void redo() override;
private:
    bool m_old_checked;
    bool m_new_checked;
    MyCheckBox *m_checkbox;
};

#endif // MYCHECKBOXUNDOCOMMAND_H
