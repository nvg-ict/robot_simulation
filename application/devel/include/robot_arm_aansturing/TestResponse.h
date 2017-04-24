// Generated by gencpp from file robot_arm_aansturing/TestResponse.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_TESTRESPONSE_H
#define ROBOT_ARM_AANSTURING_MESSAGE_TESTRESPONSE_H


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
struct TestResponse_
{
  typedef TestResponse_<ContainerAllocator> Type;

  TestResponse_()
    {
    }
  TestResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }






  typedef boost::shared_ptr< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> const> ConstPtr;

}; // struct TestResponse_

typedef ::robot_arm_aansturing::TestResponse_<std::allocator<void> > TestResponse;

typedef boost::shared_ptr< ::robot_arm_aansturing::TestResponse > TestResponsePtr;
typedef boost::shared_ptr< ::robot_arm_aansturing::TestResponse const> TestResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_arm_aansturing::TestResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::robot_arm_aansturing::TestResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_arm_aansturing/TestResponse";
  }

  static const char* value(const ::robot_arm_aansturing::TestResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::robot_arm_aansturing::TestResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TestResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_arm_aansturing::TestResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::robot_arm_aansturing::TestResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_TESTRESPONSE_H