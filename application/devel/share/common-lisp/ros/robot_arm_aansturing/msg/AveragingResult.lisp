; Auto-generated. Do not edit!


(cl:in-package robot_arm_aansturing-msg)


;//! \htmlinclude AveragingResult.msg.html

(cl:defclass <AveragingResult> (roslisp-msg-protocol:ros-message)
  ((mean
    :reader mean
    :initarg :mean
    :type cl:float
    :initform 0.0)
   (std_dev
    :reader std_dev
    :initarg :std_dev
    :type cl:float
    :initform 0.0))
)

(cl:defclass AveragingResult (<AveragingResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AveragingResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AveragingResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-msg:<AveragingResult> is deprecated: use robot_arm_aansturing-msg:AveragingResult instead.")))

(cl:ensure-generic-function 'mean-val :lambda-list '(m))
(cl:defmethod mean-val ((m <AveragingResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-msg:mean-val is deprecated.  Use robot_arm_aansturing-msg:mean instead.")
  (mean m))

(cl:ensure-generic-function 'std_dev-val :lambda-list '(m))
(cl:defmethod std_dev-val ((m <AveragingResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-msg:std_dev-val is deprecated.  Use robot_arm_aansturing-msg:std_dev instead.")
  (std_dev m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AveragingResult>) ostream)
  "Serializes a message object of type '<AveragingResult>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'mean))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'std_dev))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AveragingResult>) istream)
  "Deserializes a message object of type '<AveragingResult>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'mean) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'std_dev) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AveragingResult>)))
  "Returns string type for a message object of type '<AveragingResult>"
  "robot_arm_aansturing/AveragingResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AveragingResult)))
  "Returns string type for a message object of type 'AveragingResult"
  "robot_arm_aansturing/AveragingResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AveragingResult>)))
  "Returns md5sum for a message object of type '<AveragingResult>"
  "d5c7decf6df75ffb4367a05c1bcc7612")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AveragingResult)))
  "Returns md5sum for a message object of type 'AveragingResult"
  "d5c7decf6df75ffb4367a05c1bcc7612")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AveragingResult>)))
  "Returns full string definition for message of type '<AveragingResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%float32 mean~%float32 std_dev~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AveragingResult)))
  "Returns full string definition for message of type 'AveragingResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%float32 mean~%float32 std_dev~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AveragingResult>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AveragingResult>))
  "Converts a ROS message object to a list"
  (cl:list 'AveragingResult
    (cl:cons ':mean (mean msg))
    (cl:cons ':std_dev (std_dev msg))
))
