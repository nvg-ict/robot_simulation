/*
 * SerialComm.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: Agit
 */

#include "SerialComm.hpp"

SerialComm::SerialComm(boost::asio::io_service& io_service, unsigned int baud, const std::string& device)
        : active_(true),
          io_service_(io_service),
          serialPort(io_service, device)
{
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
        if (!serialPort.is_open())
        {
                std::cerr << "Failed to open serial port\n";
                return;
        }
        boost::asio::serial_port_base::baud_rate baud_option(115200);
        serialPort.set_option(baud_option); // set the baud rate after the port has been opened
}


SerialComm::~SerialComm() {
	// TODO Auto-generated destructor stub
}
void SerialComm::read_start()
{ // Start an asynchronous read and call read_complete when it completes or fails

    //zou misschien readuntil kunnen gebruiken om tot delimeter te lezen, maar zie nut er nu van niet in.
	boost::asio::async_read(serialPort,boost::asio::buffer(read_msg_, max_read_length),
			boost::bind(&SerialComm::read_complete,
					this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
}

//our completion handler
void SerialComm::read_complete(const boost::system::error_code& error, size_t bytes_transferred)
{ // the asynchronous read operation has now completed or failed and returned an error

	  //moet eigenlijk controleren of valide bericht is.
	  if(bytes_transferred == 0)  read_start();
	  else
	  {
		  //initialiseren met 0 is zelfde als '\0', als je een char array print/leest dan het print het tot '\0' karakter dit doen we omdat rest van informatie niet belangerijk is.
		  read_msg_[bytes_transferred]=0;
		  //std::cout << bytes_transferred << " bytes: " << read_msg_ << std::endl;
		  //ROS_INFO("bytes %s:",read_msg_);
	  }

}
void SerialComm::write_message(std::string aMessage)
{
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
	std::for_each(aMessage.begin(),aMessage.end(),[this](const char msg){this->write(msg);});
}

void SerialComm::write(const char msg) // pass the write data to the do_write function via the io service in the other thread
{
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
        io_service_.post(boost::bind(&SerialComm::do_write, this, msg));
}

void SerialComm::close() // call the do_close function via the io service in the other thread
{
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
        io_service_.post(boost::bind(&SerialComm::do_close, this, boost::system::error_code()));
}

bool SerialComm::active() // return true if the socket is still active
{
        return active_;
}


void SerialComm::do_write(const char msg)
{ // callback to handle write call from outside this class
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
	std::cout<<"do_write"<<std::endl;
        bool write_in_progress = !write_msgs_.empty(); // is there anything currently being written?
        write_msgs_.push_back(msg); // store in write buffer
        if (!write_in_progress) // if nothing is currently being written, then start
        {
            write_start();
        }

}

void SerialComm::write_start()
{ // Start an asynchronous write and call write_complete when it completes or fails
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
	std::cout<<"do_write_start"<<std::endl;
//        boost::asio::async_write(serialPort,
//                boost::asio::buffer(&write_msgs_.front(), 1),
//                boost::bind(&SerialComm::write_complete,
//                        this,
//                        boost::asio::placeholders::error));

        serialPort.write_some(boost::asio::buffer(&write_msgs_.front(), 1));
}

void SerialComm::write_complete(const boost::system::error_code& error)
{ // the asynchronous read operation has now completed or failed and returned an error
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
	std::cout<<"do_write_complete"<<std::endl;
        if (!error)
        { // write completed, so send next write data
                write_msgs_.pop_front(); // remove the completed data
                if (!write_msgs_.empty()) // if there is anthing left to be written
                {
                        write_start(); // then start sending the next item in the buffer
                }
        }
        else
        {
        	 do_close(error);
        }

}

void SerialComm::do_close(const boost::system::error_code& error)
{ // something has gone wrong, so close the socket & make this object inactive
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
        if (error == boost::asio::error::operation_aborted) // if this call is the result of a timer cancel()
                return; // ignore it because the connection cancelled the timer
        if (error)
                std::cerr << "Error: " << error.message() << std::endl; // show the error message
        else
                std::cout << "Error: Connection did not succeed.\n";
        std::cout << "Press Enter to exit\n";
        serialPort.close();
        active_ = false;
        io_service_thread.join();
}

void SerialComm::start()
{
	std::cout<<__PRETTY_FUNCTION__<<std::endl;
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service_));
	io_service_thread.swap(t);
}


//bool SerialComm::sendCommand(robot_arm_aansturing::Test::Request& req,
//		robot_arm_aansturing::Test::Response& res)
//{
//	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service_));
//	std::string message ="hello_world";
//	char return_carriage = '\n';
//
//	for(int i =0; i<message.size(); ++i)
//	{
//		write(message[i]);
//	}
//	write(return_carriage);
//
//	boost::this_thread::sleep( boost::posix_time::milliseconds(1) );
//
//	close();
//	t.join();
//	return true;
//}
