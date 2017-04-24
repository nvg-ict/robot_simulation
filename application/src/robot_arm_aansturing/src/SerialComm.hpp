/*
 * SerialComm.hpp
 *
 *  Created on: Mar 2, 2017
 *      Author: Agit
 */

#ifndef SERIALCOMM_HPP_
#define SERIALCOMM_HPP_

#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
//#include "robot_arm_aansturing/Test.h"
#include "ros/ros.h"

class SerialComm
{
public:
        SerialComm(boost::asio::io_service& io_service, unsigned int baud, const std::string& device);

        void write_message(std::string aMessage);

        void write(const char msg);

        void start();

        void close();

        bool active();

        void read_start();
//        bool sendCommand(robot_arm_aansturing::Test::Request  &req,
//        				 robot_arm_aansturing::Test::Response &res);

    	virtual ~SerialComm();

private:

        void read_complete(const boost::system::error_code& error, size_t bytes_transferred);

        void do_write(const char msg);

        void write_start();

        void write_complete(const boost::system::error_code& error);

        void do_close(const boost::system::error_code& error);

        bool active_; // remains true while this object is still operating
        static const int max_read_length = 512; // maximum amount of data to read in one operation
        boost::asio::io_service& io_service_; // the main IO service that runs this connection
        boost::asio::serial_port serialPort; // the serial port this instance is connected
        char read_msg_[max_read_length]; // data read from the socket
        std::deque<char> write_msgs_; // buffered write data
        boost::thread io_service_thread; //run the IO service as a separate thread, so the main thread can do others

};

#endif /* SERIALCOMM_HPP_ */
