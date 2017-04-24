;; Auto-generated. Do not edit!


(when (boundp 'robot_arm_aansturing::positionGoal)
  (if (not (find-package "ROBOT_ARM_AANSTURING"))
    (make-package "ROBOT_ARM_AANSTURING"))
  (shadow 'positionGoal (find-package "ROBOT_ARM_AANSTURING")))
(unless (find-package "ROBOT_ARM_AANSTURING::POSITIONGOAL")
  (make-package "ROBOT_ARM_AANSTURING::POSITIONGOAL"))

(in-package "ROS")
;;//! \htmlinclude positionGoal.msg.html


(defclass robot_arm_aansturing::positionGoal
  :super ros::object
  :slots (_time _angles ))

(defmethod robot_arm_aansturing::positionGoal
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

(setf (get robot_arm_aansturing::positionGoal :md5sum-) "564bd91ce4bae241b82d4b8b931ce81e")
(setf (get robot_arm_aansturing::positionGoal :datatype-) "robot_arm_aansturing/positionGoal")
(setf (get robot_arm_aansturing::positionGoal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#goal definition
int32 time
int32[] angles

")



(provide :robot_arm_aansturing/positionGoal "564bd91ce4bae241b82d4b8b931ce81e")

