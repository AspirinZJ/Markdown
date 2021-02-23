The problem is you haven't added it the `.bashrc`. file so it can be seen:

1.  From the terminal:

    ```
     nano /home/username/.bashrc
    
     # or
    
     nano /home/$USER/.bashrc
    ```

2.  Inside there add the following:

    ```
     export PATH="/usr/local/cuda-8.0/bin:$PATH"
     export LD_LIBRARY_PATH="/usr/local/cuda-8.0/lib64:$LD_LIBRARY_PATH"
    ```

3.  Then do the following to **save** and **close** the **editor**:

    ```
     On you keyboard press the following: 
    
     ctrl + o             --> save 
     enter or return key  --> accept changes
     ctrl + x             --> close editor
    ```

4.  Now either do `source .bashrc` or `close and open another terminal`

5.  Now run `nvcc --version`

Information:

-   `.bashrc`: is the file read by the `terminal` before opening and its found in the `/home/$USER` diretory of the user in question.
-   the `.` before the file means its **hidden from view** unless you instruct you file manager to show `hidden` files