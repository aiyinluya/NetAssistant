#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QKeyEvent>
#include <QList>
#include <QString>

class PlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit PlainTextEdit(QWidget *parent = nullptr);
    void addHistory(const QString& value);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QList<QString> history;
    int historyIndex;
};

#endif // PLAINTEXTEDIT_H
