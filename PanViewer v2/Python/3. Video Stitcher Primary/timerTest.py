import threading

def work (): 
  threading.Timer(30, work).start ()
  print "stackoverflow"

work ()
