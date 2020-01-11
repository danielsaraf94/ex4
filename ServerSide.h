//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__SERVERSIDE_H_
#define EX4_5__SERVERSIDE_H_
namespace server_side
{
class Server{
 public:
    virtual void open(int port)=0;
    virtual void close()=0;
};

}
#endif //EX4_5__SERVERSIDE_H_
