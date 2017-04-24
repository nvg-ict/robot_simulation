; Auto-generated. Do not edit!


(cl:in-package robot_arm_aansturing-msg)


;//! \htmlinclude positionGoal.msg.html

(cl:defclass <positionGoal> (roslisp-msg-protocol:ros-message)
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

(cl:defclass positionGoal (<positionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <positionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'positionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-msg:<positionGoal> is deprecated: use robot_arm_aansturing-msg:positionGoal instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <positionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-msg:time-val is deprecated.  Use robot_arm_aansturing-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <positionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-msg:angles-val is deprecated.  Use robot_arm_aansturing-msg:angles instead.")
  (angles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <positionGoal>) ostream)
  "Serializes a message object of type '<positionGoal>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <positionGoal>) istream)
  "Deserializes a message object of type '<positionGoal>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<positionGoal>)))
  "Returns string type for a message object of type '<positionGoal>"
  "robot_arm_aansturing/positionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'positionGoal)))
  "Returns string type for a message object of type 'positionGoal"
  "robot_arm_aansturing/positionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<positionGoal>)))
  "Returns md5sum for a message object of type '<positionGoal>"
  "564bd91ce4bae241b82d4b8b931ce81e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'positionGoal)))
  "Returns md5sum for a message object of type 'positionGoal"
  "564bd91ce4bae241b82d4b8b931ce81e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<positionGoal>)))
  "Returns full string definition for message of type '<positionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%int32 time~%int32[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'positionGoal)))
  "Returns full string definition for message of type 'positionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%int32 time~%int32[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <positionGoal>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <positionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'positionGoal
    (cl:cons ':time (time msg))
    (cl:cons ':angles (angles msg))
))
