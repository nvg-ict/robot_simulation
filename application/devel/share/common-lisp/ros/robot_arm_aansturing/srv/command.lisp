; Auto-generated. Do not edit!


(cl:in-package robot_arm_aansturing-srv)


;//! \htmlinclude command-request.msg.html

(cl:defclass <command-request> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:integer
    :initform 0)
   (command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass command-request (<command-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <command-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'command-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<command-request> is deprecated: use robot_arm_aansturing-srv:command-request instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <command-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:time-val is deprecated.  Use robot_arm_aansturing-srv:time instead.")
  (time m))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <command-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:command-val is deprecated.  Use robot_arm_aansturing-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <command-request>) ostream)
  "Serializes a message object of type '<command-request>"
  (cl:let* ((signed (cl:slot-value msg 'time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <command-request>) istream)
  "Deserializes a message object of type '<command-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<command-request>)))
  "Returns string type for a service object of type '<command-request>"
  "robot_arm_aansturing/commandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'command-request)))
  "Returns string type for a service object of type 'command-request"
  "robot_arm_aansturing/commandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<command-request>)))
  "Returns md5sum for a message object of type '<command-request>"
  "ff0e3fb9acee100884c63efa5d599c72")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'command-request)))
  "Returns md5sum for a message object of type 'command-request"
  "ff0e3fb9acee100884c63efa5d599c72")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<command-request>)))
  "Returns full string definition for message of type '<command-request>"
  (cl:format cl:nil "int32 time~%string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'command-request)))
  "Returns full string definition for message of type 'command-request"
  (cl:format cl:nil "int32 time~%string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <command-request>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <command-request>))
  "Converts a ROS message object to a list"
  (cl:list 'command-request
    (cl:cons ':time (time msg))
    (cl:cons ':command (command msg))
))
;//! \htmlinclude command-response.msg.html

(cl:defclass <command-response> (roslisp-msg-protocol:ros-message)
  ((accepted
    :reader accepted
    :initarg :accepted
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass command-response (<command-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <command-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'command-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<command-response> is deprecated: use robot_arm_aansturing-srv:command-response instead.")))

(cl:ensure-generic-function 'accepted-val :lambda-list '(m))
(cl:defmethod accepted-val ((m <command-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:accepted-val is deprecated.  Use robot_arm_aansturing-srv:accepted instead.")
  (accepted m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <command-response>) ostream)
  "Serializes a message object of type '<command-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'accepted) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <command-response>) istream)
  "Deserializes a message object of type '<command-response>"
    (cl:setf (cl:slot-value msg 'accepted) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<command-response>)))
  "Returns string type for a service object of type '<command-response>"
  "robot_arm_aansturing/commandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'command-response)))
  "Returns string type for a service object of type 'command-response"
  "robot_arm_aansturing/commandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<command-response>)))
  "Returns md5sum for a message object of type '<command-response>"
  "ff0e3fb9acee100884c63efa5d599c72")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'command-response)))
  "Returns md5sum for a message object of type 'command-response"
  "ff0e3fb9acee100884c63efa5d599c72")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<command-response>)))
  "Returns full string definition for message of type '<command-response>"
  (cl:format cl:nil "bool accepted~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'command-response)))
  "Returns full string definition for message of type 'command-response"
  (cl:format cl:nil "bool accepted~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <command-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <command-response>))
  "Converts a ROS message object to a list"
  (cl:list 'command-response
    (cl:cons ':accepted (accepted msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'command)))
  'command-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'command)))
  'command-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'command)))
  "Returns string type for a service object of type '<command>"
  "robot_arm_aansturing/command")