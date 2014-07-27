#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QVBoxLayout>
#include<QSplitter>
#include<QTextBrowser>
#include<QTextEdit>
#include<QKeyEvent>
class QTextBrowser;
class QTextEdit;
class QEvent;

namespace Ui {
class chatwindow;
}

class chatwindow : public QWidget
{
    Q_OBJECT

public:
    explicit chatwindow(QWidget *parent = 0);
    ~chatwindow();
    bool eventFilter(QObject *watched, QEvent *e);
    void submitChatText();


private:
    Ui::chatwindow *ui;
    QTextBrowser *conversationView;
    QTextEdit *chatEdit;
};

#endif // CHATWINDOW_H
