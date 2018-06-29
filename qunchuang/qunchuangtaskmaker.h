﻿#ifndef QUNCHUANGTASKMAKER_H
#define QUNCHUANGTASKMAKER_H

#include "../taskmaker.h"
#include "qunchuangtcsconnection.h"

class QunChuangTaskMaker : public TaskMaker
{
public:
    QunChuangTaskMaker();
    ~QunChuangTaskMaker();
    virtual void init();
    virtual void makeTask(qyhnetwork::TcpSessionPtr conn, const Json::Value &request);
    virtual void makeTask(std::string from ,std::string to,std::string dispatch_id,int ceid,std::string line_id, int agv_id);

private:
    QunChuangTcsConnection *tcsConnection;
};

#endif // QUNCHUANGTASKMAKER_H