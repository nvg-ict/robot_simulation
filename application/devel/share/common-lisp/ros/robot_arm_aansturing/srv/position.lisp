; Auto-generated. Do not edit!


(cl:in-package robot_arm_aansturing-srv)


;//! \htmlinclude position-request.msg.html

(cl:defclass <position-request> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:integer
    :initform 0)
   (angles
    :reader angles
    :initarg :angles
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass position-request (<position-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <position-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'position-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<position-request> is deprecated: use robot_arm_aansturing-srv:position-request instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:time-val is deprecated.  Use robot_arm_aansturing-srv:time instead.")
  (time m))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:angles-val is deprecated.  Use robot_arm_aansturing-srv:angles instead.")
  (angles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <position-request>) ostream)
  "Serializes a message object of type '<position-request>"
  (cl:let* ((signed (cl:slot-value msg 'time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'angles))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'angles))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <position-request>) istream)
  "Deserializes a message object of type '<position-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'angles) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'angles)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<position-request>)))
  "Returns string type for a service object of type '<position-request>"
  "robot_arm_aansturing/positionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position-request)))
  "Returns string type for a service object of type 'position-request"
  "robot_arm_aansturing/positionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<position-request>)))
  "Returns md5sum for a message object of type '<position-request>"
  "f2b13f7d6d2e580339acb0496be6fd7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'position-request)))
  "Returns md5sum for a message object of type 'position-request"
  "f2b13f7d6d2e580339acb0496be6fd7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<position-request>)))
  "Returns full string definition for message of type '<position-request>"
  (cl:format cl:nil "int32 time~%int32[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'position-request)))
  "Returns full string definition for message of type 'position-request"
  (cl:format cl:nil "int32 time~%int32[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <position-request>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <position-request>))
  "Converts a ROS message object to a list"
  (cl:list 'position-request
    (cl:cons ':time (time msg))
    (cl:cons ':angles (angles msg))
))
;//! \htmlinclude position-response.msg.html

(cl:defclass <position-response> (roslisp-msg-protocol:ros-message)
  ((accepted
    :reader accepted
    :initarg :accepted
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass position-response (<position-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <position-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'position-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<position-response> is deprecated: use robot_arm_aansturing-srv:position-response instead.")))

(cl:ensure-generic-function 'accepted-val :lambda-list '(m))
(cl:defmethod accepted-val ((m <position-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:accepted-val is deprecated.  Use robot_arm_aansturing-srv:accepted instead.")
  (accepted m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <position-response>) ostream)
  "Serializes a message object of type '<position-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'accepted) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <position-response>) istream)
  "Deserializes a message object of type '<position-response>"
    (cl:setf (cl:slot-value msg 'accepted) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<position-response>)))
  "Returns string type for a service object of type '<position-response>"
  "robot_arm_aansturing/positionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position-response)))
  "Returns string type for a service object of type 'position-response"
  "robot_arm_aansturing/positionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<position-response>)))
  "Returns md5sum for a message object of type '<position-response>"
  "f2b13f7d6d2e580339acb0496be6fd7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'position-response)))
  "Returns md5sum for a message object of type 'position-response"
  "f2b13f7d6d2e580339acb0496be6fd7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<position-response>)))
  "Returns full string definition for message of type '<position-response>"
  (cl:format cl:nil "bool accepted~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'position-response)))
  "Returns full string definition for message of type 'position-response"
  (cl:format cl:nil "bool accepted~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <position-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <position-response>))
  "Converts a ROS message object to a list"
  (cl:list 'position-response
    (cl:cons ':accepted (accepted msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'position)))
  'position-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'position)))
  'position-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position)))
  "Returns string type for a service object of type '<position>"
  "robot_arm_aansturing/position")