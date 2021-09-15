# java-kicker

javaをcppから起動する。CreateProcessを利用。

```cpp
        LPSTR command_line = "java -cp . hello";
        result = Execute(command_line);
```
