#ifndef NEWSPAPER
#define NEWSPAPER

#endif // NEWSPAPER

#include <QObject>

class Newspaper : public QObject
{
Q_OBJECT//这个宏的展开将为我们的类提供信号槽机制、国际化机制以及 Qt 提
   // 供的不基于 C++ RTTI 的反射能力
public:
Newspaper(const QString & name) :
m_name(name)
{ }
void send()
{
emit newPaper(m_name);
}
signals:
void newPaper(const QString &name);//该类需要让外界知道的数据
private:
QString m_name;
};
