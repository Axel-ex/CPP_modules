# Usage
```
make
./transactions > my.log
 awk '{sub(/\[[0-9]+_[0-9]+\]/, "[TIMESTAMP]")}1' my.log > my_processed.log
 awk '{sub(/\[[0-9]+_[0-9]+\]/, "[TIMESTAMP]")}1' 19920104_091532.log > processed.log
 diff my_processed.log processed.log
 ```