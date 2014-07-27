
#include "chatwindow.h"
#include "ui_chatwindow.h"
chatwindow::chatwindow(QWidget *parent) :
 QWidget(parent)
{
 QVBoxLayout *lay = new QVBoxLayout(this);
 QSplitter *splitter = new QSplitter(Qt::Vertical, this);
 lay->addWidget(splitter);
 conversationView = new QTextBrowser;
 chatEdit = new QTextEdit;
 splitter->addWidget(conversationView);
 splitter->addWidget(chatEdit);
 chatEdit->installEventFilter(this);
 setWindowTitle(tr("Chat Window"));
 setTabOrder(chatEdit, conversationView);
}
bool chatwindow::eventFilter(QObject *watched, QEvent* e)
{
if (watched == chatEdit && e->type() == QEvent::KeyPress) {
QKeyEvent *ke = static_cast<QKeyEvent*>(e);
if (ke->key() == Qt::Key_Enter ||
ke->key() == Qt::Key_Return) {
submitChatText();
return true;
}
}
return QWidget::eventFilter(watched, e);
}
void chatwindow::submitChatText()
{
conversationView->append(chatEdit->toPlainText());
chatEdit->setPlainText("");
}
chatwindow::~chatwindow()
{
delete ui;
}
