/**
 * @file BoostUdp.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Implementation of BoostUdp
 * @version 1.0
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include "BoostUdp.hpp"

using namespace rt::network;

BoostUdpEndpoint::BoostUdpEndpoint(const std::string &targetIp, uint16_t targetPort, const std::string &myIp, uint16_t myPort) :
 _target(boost::asio::ip::make_address_v4(targetIp), targetPort), _me(boost::asio::ip::udp::v4(), 0), _service(), _socket(_service)
{
    _myPort = myPort;
    auto bytes = boost::asio::ip::make_address_v4(myIp).to_bytes();
    uint8_t *raw = (uint8_t*)&_myIp;
    for (uint8_t i = 0; i < sizeof(uint32_t); i++)
        *(raw + i) = bytes[sizeof(uint32_t) - i - 1];
    _socket.open(boost::asio::ip::udp::v4());
    _socket.bind(_me);
}

BoostUdpEndpoint::BoostUdpEndpoint(uint32_t targetIp, uint16_t targetPort, uint32_t myIp, uint16_t myPort) :
 _target(boost::asio::ip::make_address_v4(targetIp), targetPort), _me(boost::asio::ip::udp::v4(), 0), _service(), _socket(_service)
{
    _myPort = myPort;
    _myIp = myIp;
    _socket.open(boost::asio::ip::udp::v4());
    _socket.bind(_me);
}

BoostUdpEndpoint::~BoostUdpEndpoint(void)
{

}

uint16_t BoostUdpEndpoint::targetPort(void) const
{
    return _target.port();
}

uint32_t BoostUdpEndpoint::targetIp(void) const
{
    uint32_t res = 0;
    uint8_t *raw = (uint8_t*)&res;
    auto addr = _target.address();
    auto bytes = addr.to_v4().to_bytes();
    for (uint8_t i = 0; i < sizeof(res); i++)
        *(raw + i) = bytes[sizeof(res) - i - 1];
    return res;
}

uint16_t BoostUdpEndpoint::myPort(void) const
{
    return _myPort;
}

uint32_t BoostUdpEndpoint::myIp(void) const
{
    return _myIp;
}

static void write_handler(const boost::system::error_code& ec, std::size_t bytes_transferred)
{

}

void BoostUdpEndpoint::send(rt::Byte packet)
{
    try {
        Byte newPacket;
        newPacket << myIp() << myPort() << (uint16_t)0;
        newPacket += packet;
        _socket.async_send_to(boost::asio::buffer(newPacket.getData()), _target, write_handler);
    }
    catch (std::exception &err)
    {

    }
}
