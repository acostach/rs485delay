FROM balenalib/imx8mm-var-dart-debian

WORKDIR /usr/src/test/

COPY ./test_rs485_delay.c ./test_rs485_delay.c
COPY ./script.sh ./script.sh

RUN apt-get update && apt-get install -y build-essential && \
    gcc test_rs485_delay.c -o test_rs485_delay

ENV UDEV=on

CMD ["bash", "script.sh"]
