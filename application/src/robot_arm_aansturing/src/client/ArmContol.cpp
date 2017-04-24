/*
 * ArmContol.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: nico
 */

#include "ArmContol.hpp"

#include <thread>
#include <chrono>

/*static*/ArmContol& ArmContol::getArmContol()
{
	static ArmContol aC;
	return aC;
}

ArmContol::ArmContol()
{
	std::cout << "In constructor" << std::endl;
}

ArmContol::~ArmContol()
{
	// TODO Auto-generated destructor stub
}

bool ArmContol::taskAvailable()
{
	return !taskList.empty();
}

Task ArmContol::getNextTask()
{
	std::cout << "Get a task" << std::endl;
	Task task = taskList.front();
	taskList.pop();
	std::cout << task.time << std::endl;
	return task;
}

void ArmContol::addTask(const Task& aTask)
{
	std::cout << "Task added" << std::endl;
	taskList.push(aTask);
}

void ArmContol::emptyTaskList()
{
	while (!taskList.empty())
	{
		taskList.pop();
	}

}

