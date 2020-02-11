/**
 * @file BoostServer.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief C'est un scandale ce code
 * @version 1.0
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include <boost/bind.hpp>
#include "BoostServer.hpp"

using namespace rt::network;

BoostServer::BoostServer(const std::string &myIp, uint16_t myPort, RcvFptr rcvHandler) :
_me(boost::asio::ip::udp::v4(), myPort), _service(), _socket(_service), _onRcv(rcvHandler)
{
    auto bytes = boost::asio::ip::make_address_v4(myIp).to_bytes();
    uint8_t *raw = (uint8_t*)&_myIp;
    for (uint8_t i = 0; i < sizeof(uint32_t); i++)
        *(raw + i) = bytes[sizeof(uint32_t) - i - 1];
    _socket.open(boost::asio::ip::udp::v4());
    _socket.bind(_me);
}

BoostServer::BoostServer(uint32_t myIp, uint16_t myPort, RcvFptr rcvHandler) :
_me(boost::asio::ip::udp::v4(), myPort), _service(), _socket(_service), _onRcv(rcvHandler)
{
    _myIp = myIp;
    _socket.open(boost::asio::ip::udp::v4());
    _socket.bind(_me);
}

BoostServer::~BoostServer(void)
{

}

void BoostServer::run(void)
{
    prepareRead();
    _service.run();
}

void BoostServer::stop(void)
{
    _service.stop();
}

void BoostServer::threadLaunch(void *server)
{
    BoostServer *instance = (BoostServer *)server;
    instance->run();
}

void BoostServer::prepareRead(void)
{
    auto binding = boost::bind(&BoostServer::recvPacket, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred);
    _socket.async_receive(boost::asio::buffer(_buffer), binding);
}

void BoostServer::recvPacket(const boost::system::error_code &error, std::size_t size)
{
    rt::Byte packet;
    for (size_t i = 0; i < size; i++)
        packet << _buffer[i];

    uint64_t id   = (uint64_t)packet;
    uint64_t ip   = id & 0x00000000FFFFFFFF;
    uint64_t port = id >> 32;

    auto it = _clients.find(id);
    if (it == _clients.end()) {
        _clients.emplace(id, std::make_unique<BoostUdpEndpoint>(ip, port, _myIp, _me.port()));
        it = _clients.find(id);
    }
    // Do something
    _onRcv(*(it->second), packet, data);
    // Don't do something
    prepareRead();
}

std::vector<std::reference_wrapper<BoostUdpEndpoint>> BoostServer::getAllClients(void) const
{
    std::vector<std::reference_wrapper<BoostUdpEndpoint>> res;
    for (auto &i : _clients)
        res.push_back(*(i.second));
    return res;
}

void BoostServer::broadcast(rt::Byte packet)
{
    for (auto &i : _clients)
        (i.second)->send(packet);
}
