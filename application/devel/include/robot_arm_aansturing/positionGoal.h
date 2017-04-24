// Generated by gencpp from file robot_arm_aansturing/positionGoal.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_POSITIONGOAL_H
#define ROBOT_ARM_AANSTURING_MESSAGE_POSITIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robot_arm_aansturing
{
template <class ContainerAllocator>
struct positionGoal_
{
  typedef positionGoal_<ContainerAllocator> Type;

  positionGoal_()
    : time(0)
    , angles()  {
    }
  positionGoal_(const ContainerAllocator& _alloc)
    : time(0)
    , angles(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _time_type;
  _time_type time;

   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _angles_type;
  _angles_type angles;




  typedef boost::shared_ptr< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct positionGoal_

typedef ::robot_arm_aansturing::positionGoal_<std::allocator<void> > positionGoal;

typedef boost::shared_ptr< ::robot_arm_aansturing::positionGoal > positionGoalPtr;
typedef boost::shared_ptr< ::robot_arm_aansturing::positionGoal const> positionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_arm_aansturing::positionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robot_arm_aansturing

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robot_arm_aansturing': ['/home/nico/Documents/HAN/WoR World/Simulation/robot_simulation/application/devel/share/robot_arm_aansturing/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "564bd91ce4bae241b82d4b8b931ce81e";
  }

  static const char* value(const ::robot_arm_aansturing::positionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x564bd91ce4bae241ULL;
  static const uint64_t static_value2 = 0xb82d4b8b931ce81eULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_arm_aansturing/positionGoal";
  }

  static const char* value(const ::robot_arm_aansturing::positionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definition\n\
int32 time\n\
int32[] angles\n\
";
  }

  static const char* value(const ::robot_arm_aansturing::positionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.angles);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct positionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_arm_aansturing::positionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_arm_aansturing::positionGoal_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    Printer<int32_t>::stream(s, indent + "  ", v.time);
    s << indent << "angles[]" << std::endl;
    for (size_t i = 0; i < v.angles.size(); ++i)
    {
      s << indent << "  angles[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.angles[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_POSITIONGOAL_H