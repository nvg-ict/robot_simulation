
(cl:in-package :asdf)

(defsystem "robot_arm_aansturing-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Test" :depends-on ("_package_Test"))
    (:file "_package_Test" :depends-on ("_package"))
    (:file "command" :depends-on ("_package_command"))
    (:file "_package_command" :depends-on ("_package"))
    (:file "position" :depends-on ("_package_position"))
    (:file "_package_position" :depends-on ("_package"))
  ))