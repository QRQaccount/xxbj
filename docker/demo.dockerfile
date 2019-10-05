#volume test

FROM centos
VOLUME [ "/media/qrq/QRQ_HOME/QRQ-INF/workspace","/qrqdoc"]
CMD echo "success"
CMD echo /bin/bash