#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <enet/enet.h>
#include <QObject>
#include <QString>
#include <QWidget>

class NetworkManager : public QObject
{
    Q_OBJECT

private:
    ENetHost *client;
    ENetAddress address;
    ENetEvent event;
    ENetPeer *peer;
    QString ip_addr;
    int port;
    int next_time;
    int keep_running;
    int myClientId;
    QString login;
    int startTime;
    int requestedTeam;

public:
    NetworkManager();
    ~NetworkManager();
    void set_key(int key);
    void network_loop();
    void process_packet(ENetEvent * event);
    void update_state();
    void testFunction();
    void sendMessage(int msgType,int clientId,int data = 0);


public slots:
    void start();
    void process_key(QKeyEvent * event, int key_status);
    int network_init();
    void set_rand_key();
    void setLogin(QString newLogin);
    void disconnectClient();
    void setIP(QString ip_addr = "127.0.0.1", int port=1234);
    void setRequestedTeam(int team);

signals:
    void writeText(QString text);
    void newPlayerScore(int score);
    void newHealthPoints(int value);
    void newPlayerId(int value);
    void newTeamId(int value);
    void newIdInTeam(int value);
    //void newStartTime(int value);
    void disconnected();

};

#endif // NETWORKMANAGER_H
