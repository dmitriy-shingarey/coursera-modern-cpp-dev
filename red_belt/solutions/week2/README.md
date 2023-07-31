# How to use ```profile.h```

- include src/profile.h
- for usage include it in the block scope 
    ```cpp
    {
        LOG_DURATION("Input");
        ...
    }
    ```
-  define in in the very beginning of the block scope for contruction
-  destructor will be called by leaving the scope