#include "plainTextEdit.h"

PlainTextEdit::PlainTextEdit(QWidget *parent)
    : QPlainTextEdit(parent), historyIndex(-1)
{
    history << "历史记录1" << "历史记录2" << "历史记录3"; // 示例历史记录
}

void PlainTextEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if (historyIndex > 0) {
            --historyIndex;
            setPlainText(history.at(historyIndex));
        } else if (historyIndex == -1 && !history.isEmpty()) {
            historyIndex = history.size() - 1;
            setPlainText(history.at(historyIndex));
        }
    } else if (event->key() == Qt::Key_Down) {
        if (historyIndex < history.size() - 1) {
            ++historyIndex;
            setPlainText(history.at(historyIndex));
        } else if (historyIndex == history.size() - 1) {
            ++historyIndex;
            clear();
        }
    } else {
        QPlainTextEdit::keyPressEvent(event);
    }
}
