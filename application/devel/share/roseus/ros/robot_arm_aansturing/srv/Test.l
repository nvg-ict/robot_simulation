;; Auto-generated. Do not edit!


(when (boundp 'robot_arm_aansturing::Test)
  (if (not (find-package "ROBOT_ARM_AANSTURING"))
    (make-package "ROBOT_ARM_AANSTURING"))
  (shadow 'Test (find-package "ROBOT_ARM_AANSTURING")))
(unless (find-package "ROBOT_ARM_AANSTURING::TEST")
  (make-package "ROBOT_ARM_AANSTURING::TEST"))
(unless (find-package "ROBOT_ARM_AANSTURING::TESTREQUEST")
  (make-package "ROBOT_ARM_AANSTURING::TESTREQUEST"))
(unless (find-package "ROBOT_ARM_AANSTURING::TESTRESPONSE")
  (make-package "ROBOT_ARM_AANSTURING::TESTRESPONSE"))

(in-package "ROS")





(defclass robot_arm_aansturing::TestRequest
  :super ros::object
  :slots ())

(defmethod robot_arm_aansturing::TestRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass robot_arm_aansturing::TestResponse
  :super ros::object
  :slots ())

(defmethod robot_arm_aansturing::TestResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass robot_arm_aansturing::Test
  :super ros::object
  :slots ())

(setf (get robot_arm_aansturing::Test :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get robot_arm_aansturing::Test :datatype-) "robot_arm_aansturing/Test")
(setf (get robot_arm_aansturing::Test :request) robot_arm_aansturing::TestRequest)
(setf (get robot_arm_aansturing::Test :response) robot_arm_aansturing::TestResponse)

(defmethod robot_arm_aansturing::TestRequest
  (:response () (instance robot_arm_aansturing::TestResponse :init)))

(setf (get robot_arm_aansturing::TestRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get robot_arm_aansturing::TestRequest :datatype-) "robot_arm_aansturing/TestRequest")
(setf (get robot_arm_aansturing::TestRequest :definition-)
      "
---
")

(setf (get robot_arm_aansturing::TestResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get robot_arm_aansturing::TestResponse :datatype-) "robot_arm_aansturing/TestResponse")
(setf (get robot_arm_aansturing::TestResponse :definition-)
      "
---
")



(provide :robot_arm_aansturing/Test "d41d8cd98f00b204e9800998ecf8427e")


