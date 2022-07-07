#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QLocalSocket>
#include <QUuid>
#include <QMutex>
#include <QMutexLocker>

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = nullptr);
    void close();

public slots:
    void sendReload();

signals:
    void status(QUuid id,bool running);

private slots:
    void onSocketError(QLocalSocket::LocalSocketError error);
    void onReadyRead();

private:
    QLocalSocket *localsocket=nullptr;
    QMutex mutex;

};

Q_DECLARE_METATYPE(QLocalSocket::LocalSocketError)
Q_DECLARE_METATYPE(QLocalSocket::LocalSocketState)

#endif // SOCKET_H
