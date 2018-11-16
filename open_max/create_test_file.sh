#!/bin/sh
for f in `seq -w 01 4864`
do
    echo line1\\nline2\\nline3\\n > "test$f"
done
