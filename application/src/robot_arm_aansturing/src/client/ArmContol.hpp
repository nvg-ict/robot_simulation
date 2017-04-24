/*
 * ArmContol.hpp
 *
 *  Created on: Mar 7, 2017
 *      Author: nico
 */

#ifndef ARMCONTOL_HPP_
#define ARMCONTOL_HPP_

#include "RobotArmContext.hpp"
#include <initializer_list>
#include <utility>

#include <ros/ros.h>
#include <boost/thread.hpp>


class ArmContol
{
public:
	/**
	 * @brief Getter of the singleton instance
	 * @return Instance of the class
	 */
	static ArmContol& getArmContol();
	virtual ~ArmContol();
	/**
	 * @brief Function that checks whether a task is available
	 * @return true when a task is in the list, false if empty
	 */
	bool taskAvailable();
	/**
	 * @brief Function that will return the first task in the task list
	 * @return The first task of the list
	 */
	Task getNextTask();
	/**
	 * @brief Function adds a task to the task list
	 * @param aTask A reference to the task
	 */
	void addTask(const Task& aTask);
	void emptyTaskList();
private:
	/**
	 * Private constructor
	 */
	ArmContol();

	std::queue<Task> taskList;
};

/**
 * Task struct containing basic info of a Task
 */
struct Task
{
	Task(std::initializer_list<short> al, unsigned long aTime):
	angles(al), time(aTime)
	{

	}

	Task(const std::vector<short>& al, unsigned long aTime):
	angles(al), time(aTime)
	{

	}
	virtual ~Task(){}

	/**
	 * @brief Function can validate the task
	 * @return false if a task is not valid
	 */
	bool validateTask() {
		for(unsigned short i = 0; i<angles.size();++i)
		{
			if(!checkPosition(angles.at(i),i))
			{
				std::cout<<"Position: "<<i<<std::endl;
				return false;
			}
		}
		return true;
	}

	/**
	 * Function that can check whether a position is valid.
	 * @param pos The angle that needs to be checked
	 * @param index Index of servo (0 is shoulder, see spreadsheet for more info or check init of RobotArmContext class)
	 * @return false when the position is not within range
	 */
	bool checkPosition(short pos, unsigned short index)
	{
		std::cout<<angles_bounds.at(index).first<<":"<<pos<<":"<<angles_bounds.at(index).second<<std::endl;
		if(angles_bounds.at(index).first == angles_bounds.at(index).second) return true;
		return (pos >= angles_bounds.at(index).first  && pos <= angles_bounds.at(index).second);
	}

	std::vector<short> angles;
	std::vector<std::pair<short,short>> angles_bounds = {
			std::make_pair(-90,90),std::make_pair(-30,90),std::make_pair(0,135),
			std::make_pair(-90,90),std::make_pair(0,0),std::make_pair(-90,90)
	};
	unsigned long time;
};





#endif /* ARMCONTOL_HPP_ */
