#!/bin/bash

if ./test_rs485_delay; then
    echo "Test passed"
else
    echo "Test failed"
fi

# Don't exit the process
while true; do
    sleep 1
done
