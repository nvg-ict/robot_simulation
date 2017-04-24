;; Auto-generated. Do not edit!


(when (boundp 'robot_arm_aansturing::command)
  (if (not (find-package "ROBOT_ARM_AANSTURING"))
    (make-package "ROBOT_ARM_AANSTURING"))
  (shadow 'command (find-package "ROBOT_ARM_AANSTURING")))
(unless (find-package "ROBOT_ARM_AANSTURING::COMMAND")
  (make-package "ROBOT_ARM_AANSTURING::COMMAND"))
(unless (find-package "ROBOT_ARM_AANSTURING::COMMANDREQUEST")
  (make-package "ROBOT_ARM_AANSTURING::COMMANDREQUEST"))
(unless (find-package "ROBOT_ARM_AANSTURING::COMMANDRESPONSE")
  (make-package "ROBOT_ARM_AANSTURING::COMMANDRESPONSE"))

(in-package "ROS")





(defclass robot_arm_aansturing::commandRequest
  :super ros::object
  :slots (_time _command ))

(defmethod robot_arm_aansturing::commandRequest
  (:init
   (&key
    ((:time __time) 0)
    ((:command __command) "")
    )
   (send-super :init)
   (setq _time (round __time))
   (setq _command (string __command))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; int32 _time
    4
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _time
       (write-long _time s)
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass robot_arm_aansturing::commandResponse
  :super ros::object
  :slots (_accepted ))

(defmethod robot_arm_aansturing::commandResponse
  (:init
   (&key
    ((:accepted __accepted) nil)
    )
   (send-super :init)
   (setq _accepted __accepted)
   self)
  (:accepted
   (&optional __accepted)
   (if __accepted (setq _accepted __accepted)) _accepted)
  (:serialization-length
   ()
   (+
    ;; bool _accepted
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _accepted
       (if _accepted (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _accepted
     (setq _accepted (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass robot_arm_aansturing::command
  :super ros::object
  :slots ())

(setf (get robot_arm_aansturing::command :md5sum-) "ff0e3fb9acee100884c63efa5d599c72")
(setf (get robot_arm_aansturing::command :datatype-) "robot_arm_aansturing/command")
(setf (get robot_arm_aansturing::command :request) robot_arm_aansturing::commandRequest)
(setf (get robot_arm_aansturing::command :response) robot_arm_aansturing::commandResponse)

(defmethod robot_arm_aansturing::commandRequest
  (:response () (instance robot_arm_aansturing::commandResponse :init)))

(setf (get robot_arm_aansturing::commandRequest :md5sum-) "ff0e3fb9acee100884c63efa5d599c72")
(setf (get robot_arm_aansturing::commandRequest :datatype-) "robot_arm_aansturing/commandRequest")
(setf (get robot_arm_aansturing::commandRequest :definition-)
      "int32 time
string command
---
bool accepted

")

(setf (get robot_arm_aansturing::commandResponse :md5sum-) "ff0e3fb9acee100884c63efa5d599c72")
(setf (get robot_arm_aansturing::commandResponse :datatype-) "robot_arm_aansturing/commandResponse")
(setf (get robot_arm_aansturing::commandResponse :definition-)
      "int32 time
string command
---
bool accepted

")



(provide :robot_arm_aansturing/command "ff0e3fb9acee100884c63efa5d599c72")


