import os

f = open(os.environ['HOME'] + '.aa.pdf', 'wb')
f.seek(4095)
f.write(b'\0')
f.close()
