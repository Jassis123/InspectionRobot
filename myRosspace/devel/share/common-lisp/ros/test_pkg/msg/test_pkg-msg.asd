
(cl:in-package :asdf)

(defsystem "test_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MsgTest" :depends-on ("_package_MsgTest"))
    (:file "_package_MsgTest" :depends-on ("_package"))
  ))