;; Auto-generated. Do not edit!


(when (boundp 'robot_arm_aansturing::position)
  (if (not (find-package "ROBOT_ARM_AANSTURING"))
    (make-package "ROBOT_ARM_AANSTURING"))
  (shadow 'position (find-package "ROBOT_ARM_AANSTURING")))
(unless (find-package "ROBOT_ARM_AANSTURING::POSITION")
  (make-package "ROBOT_ARM_AANSTURING::POSITION"))
(unless (find-package "ROBOT_ARM_AANSTURING::POSITIONREQUEST")
  (make-package "ROBOT_ARM_AANSTURING::POSITIONREQUEST"))
(unless (find-package "ROBOT_ARM_AANSTURING::POSITIONRESPONSE")
  (make-package "ROBOT_ARM_AANSTURING::POSITIONRESPONSE"))

(in-package "ROS")





(defclass robot_arm_aansturing::positionRequest
  :super ros::object
  :slots (_time _angles ))

(defmethod robot_arm_aansturing::positionRequest
  (:init
   (&key
    ((:time __time) 0)
    ((:angles __angles) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _time (round __time))
   (setq _angles __angles)
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:serialization-length
   ()
   (+
    ;; int32 _time
    4
    ;; int32[] _angles
    (* 4    (length _angles)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _time
       (write-long _time s)
     ;; int32[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (write-long (elt _angles i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _angles
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angles (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _angles i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass robot_arm_aansturing::positionResponse
  :super ros::object
  :slots (_accepted ))

(defmethod robot_arm_aansturing::positionResponse
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

(defclass robot_arm_aansturing::position
  :super ros::object
  :slots ())

(setf (get robot_arm_aansturing::position :md5sum-) "f2b13f7d6d2e580339acb0496be6fd7a")
(setf (get robot_arm_aansturing::position :datatype-) "robot_arm_aansturing/position")
(setf (get robot_arm_aansturing::position :request) robot_arm_aansturing::positionRequest)
(setf (get robot_arm_aansturing::position :response) robot_arm_aansturing::positionResponse)

(defmethod robot_arm_aansturing::positionRequest
  (:response () (instance robot_arm_aansturing::positionResponse :init)))

(setf (get robot_arm_aansturing::positionRequest :md5sum-) "f2b13f7d6d2e580339acb0496be6fd7a")
(setf (get robot_arm_aansturing::positionRequest :datatype-) "robot_arm_aansturing/positionRequest")
(setf (get robot_arm_aansturing::positionRequest :definition-)
      "int32 time
int32[] angles
---
bool accepted

")

(setf (get robot_arm_aansturing::positionResponse :md5sum-) "f2b13f7d6d2e580339acb0496be6fd7a")
(setf (get robot_arm_aansturing::positionResponse :datatype-) "robot_arm_aansturing/positionResponse")
(setf (get robot_arm_aansturing::positionResponse :definition-)
      "int32 time
int32[] angles
---
bool accepted

")



(provide :robot_arm_aansturing/position "f2b13f7d6d2e580339acb0496be6fd7a")


