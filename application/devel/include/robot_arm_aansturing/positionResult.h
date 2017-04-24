// Generated by gencpp from file robot_arm_aansturing/positionResult.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_POSITIONRESULT_H
#define ROBOT_ARM_AANSTURING_MESSAGE_POSITIONRESULT_H


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
struct positionResult_
{
  typedef positionResult_<ContainerAllocator> Type;

  positionResult_()
    : arrived(false)  {
    }
  positionResult_(const ContainerAllocator& _alloc)
    : arrived(false)  {
  (void)_alloc;
    }



   typedef uint8_t _arrived_type;
  _arrived_type arrived;




  typedef boost::shared_ptr< ::robot_arm_aansturing::positionResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_arm_aansturing::positionResult_<ContainerAllocator> const> ConstPtr;

}; // struct positionResult_

typedef ::robot_arm_aansturing::positionResult_<std::allocator<void> > positionResult;

typedef boost::shared_ptr< ::robot_arm_aansturing::positionResult > positionResultPtr;
typedef boost::shared_ptr< ::robot_arm_aansturing::positionResult const> positionResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_arm_aansturing::positionResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robot_arm_aansturing

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robot_arm_aansturing': ['/home/nico/Documents/HAN/WoR World/Simulation/robot_simulation/application/devel/share/robot_arm_aansturing/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::positionResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::positionResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::positionResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ea115e3ceb83b7b5fbcc7f283be1718c";
  }

  static const char* value(const ::robot_arm_aansturing::positionResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xea115e3ceb83b7b5ULL;
  static const uint64_t static_value2 = 0xfbcc7f283be1718cULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_arm_aansturing/positionResult";
  }

  static const char* value(const ::robot_arm_aansturing::positionResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result definition\n\
bool arrived\n\
";
  }

  static const char* value(const ::robot_arm_aansturing::positionResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.arrived);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct positionResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_arm_aansturing::positionResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_arm_aansturing::positionResult_<ContainerAllocator>& v)
  {
    s << indent << "arrived: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.arrived);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_POSITIONRESULT_H