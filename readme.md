封装esp-button的功能

1、初始化环境
    ```bash
    . ~/esp/v5.4.2/esp-idf/export.sh
    ```
2、创建项目
    ```bash
    idf.py create-project esp-button
    ```
    进入项目目录
    ```bash
    cd esp-button
    ```
3、创建组件
    ```bash
    idf.py -C components create-component Button
    ```
4、添加第三方库
    ```bash
    idf.py add-dependency "espressif/esp-button"
    ```

5、wokwi Debug
    https://docs.wokwi.com/vscode/debugging