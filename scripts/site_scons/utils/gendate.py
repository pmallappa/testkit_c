
import SCons
import datetime

def getdate(target, source, env):

    now = datetime.date.today()

    return str(now)
    
